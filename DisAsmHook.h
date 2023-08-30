// DisAsmHook.h
// Copyright 2003 ManuSoft
// http://www.manusoft.com
//
// Use of this software is governed by the terms of:
// GNU General Public License v2.0
// See LICENSE for details

#ifndef _DISASMHOOK_H_
#define _DISASMHOOK_H_

#include "AsmHook.h"
#include "CreateInstruction.h"
#include "InstructionSequence.h"


#ifndef DLLEXPORT
#define DLLEXPORT
#endif


template< typename _TTargetInstruction >
_TTargetInstruction* DaSafeInstructionCast( const PVOID pvTarget )
{
	if( !CompareOpCodeBytes<_TTargetInstruction>( (BYTE*)pvTarget ) )
		return NULL;
	return (_TTargetInstruction*)pvTarget;
}

template< typename _TTargetInstruction >
_TTargetInstruction* DaInstructionCast( const PVOID pvTarget )
{
	if( !CompareOpCodeBytes<_TTargetInstruction>( (BYTE*)pvTarget ) )
		throw;
	return (_TTargetInstruction*)pvTarget;
}

struct CheckAsmNoCheck
{
	bool operator()( DaInstructionSequence& ISeq ) { return true; }
};

struct CheckAsmNoBranching
{
	bool operator()( DaInstructionSequence& ISeq )
		{
			DaInstructionSequence::const_iterator iter = ISeq.begin();
			while( iter != ISeq.end() )
			{
				if( !(*iter) || (*iter)->GetStatus().Branch.Branch )
					return false;
				++iter;
			}
			return true;
		}
};

struct CheckAsmNoConditionalBranching
{
	bool operator()( DaInstructionSequence& ISeq )
		{
			DaInstructionSequence::const_iterator iter = ISeq.begin();
			while( iter != ISeq.end() )
			{
				if( !(*iter) ||
						((*iter)->GetStatus().Branch.Branch && (*iter)->GetStatus().Branch.Conditional) )
					return false;
				++iter;
			}
			return true;
		}
};

struct CheckAsmNoRelativeBranching
{
	bool operator()( DaInstructionSequence& ISeq )
		{
			DaInstructionSequence::const_iterator iter = ISeq.begin();
			while( iter != ISeq.end() )
			{
				if( !(*iter) ||
						((*iter)->GetStatus().Branch.Branch && !(*iter)->GetStatus().Branch.Absolute) )
					return false;
				++iter;
			}
			return true;
		}
};

struct CheckAsmRelocatable
{
	bool operator()( DaInstructionSequence& ISeq )
		{
			DaInstructionSequence::const_iterator iter = ISeq.begin();
			while( iter != ISeq.end() )
			{
				if( !(*iter) ||
						((*iter)->GetStatus().Branch.Branch && !(*iter)->GetStatus().Branch.Absolute) ||
						(*iter)->GetStatus().Offset )
					return false;
				++iter;
			}
			return true;
		}
};

template< typename _TInsertType, class _TCheckAsm >
ULONG DaAlignHook( const PVOID pvTarget )
{
	DaByteStream Source( (BYTE*)pvTarget );
	DaInstructionSequence ISeq( Source, CreateInstruction );
	if( !ISeq.Process( sizeof(_TInsertType) ) )
		throw eBadFormat;
	if( !_TCheckAsm()( ISeq ) )
		throw eBadFormat;
	return ISeq.GetStreamHighWater();
}

template< typename _TCheckInstruction, typename _TInsertType, class _TCheckAsm >
ULONG DaCheckInstructionOrAlign( const PVOID pvTarget )
{
	if( CompareOpCodeBytes<_TCheckInstruction>( (BYTE*)pvTarget ) )
		return sizeof(_TCheckInstruction);
	if( CompareOpCodeBytes<_TInsertType>( (BYTE*)pvTarget ) )
		return sizeof(_TInsertType);
	return DaAlignHook<_TInsertType, _TCheckAsm>( pvTarget );
}


inline bool FixupRelocatedCode( BYTE* pvOriginal, BYTE* pvRelocated, ULONG cbCode = sizeof(AsmFarJmp) )
{
	if( CompareOpCodeBytes< AsmFarJmp >( pvOriginal ) )
		return true; //the original code is a far jump; the relocated code is not used, so no need to fix it up
	DaByteStream Source( pvOriginal );
	DaInstructionSequence ISeq( Source, CreateInstruction );
	if( !ISeq.Process( cbCode ) )
		return false;
	for( DaInstructionSequence::const_iterator iter = ISeq.begin(); iter != ISeq.end(); ++iter )
	{
		if( !(*iter) )
			continue;
		DaInstruction& In( *(*iter) );
		if( In.GetStatus().Offset )
		{
			if( In.StartPoint() + In.Size() == ISeq.GetStreamHighWater() )
			{ //if the last instruction is a far jmp, it should already be fixed up
				if( memcmp( pvOriginal + In.StartPoint(), pvRelocated + In.StartPoint(), In.Size() ) != 0 )
					return true; //relocated code doesn't match, so it is already fixed up
			}
			if( In.GetStatus().Offset.cbSize != sizeof(LONG) )
				return false;
			BYTE* pvOldOffsetAddr = pvOriginal + In.StartPoint() + In.Size() - sizeof(LONG);
			BYTE* pvOldDestination = pvOldOffsetAddr + sizeof(LONG) + *(LONG*)pvOldOffsetAddr;
			BYTE* pvNewOffsetBase = pvRelocated + In.StartPoint() + In.Size();
			BYTE* pvNewOffsetAddr = pvNewOffsetBase - sizeof(LONG);
			LONG_PTR lOffset = pvOldDestination - pvNewOffsetBase;
		#ifdef _WIN64
			if( lOffset != (LONG)lOffset )
			{
				AsmPtrJmp* pJmpThunk = CreateJmpThunk( pvRelocated, (PROC)pvOldDestination );
				assert( pJmpThunk != NULL );
				lOffset = (BYTE*)pJmpThunk - pvNewOffsetBase;
			}
		#endif
			assert( lOffset == (LONG)lOffset );
			if( lOffset != (LONG)lOffset )
				return false;
			*(LONG*)pvNewOffsetAddr = (LONG)lOffset;
		}
	}
	return true;
}


template< class _TCheckAsm = CheckAsmNoConditionalBranching >
class DaHookStaticCode : public HookStaticCode
{
public:
	DaHookStaticCode( const PVOID pvTarget,
										const FARPROC pfPre = NULL,
										const FARPROC pfPost = NULL,
										F_Callback pfPreHookCallback = PreHookCallback )
		: HookStaticCode( pvTarget,
											pvTarget? DaCheckInstructionOrAlign<AsmFarCall,AsmFarJmp,_TCheckAsm>( pvTarget ) : 0,
											pfPre,
											pfPost,
											pfPreHookCallback )
		{}
protected:
	static bool PreHookCallback( HookStaticCode* pThis )
		{
			return FixupRelocatedCode( (BYTE*)pThis->GetTarget(), (BYTE*)pThis->GetSavedCode() );
		}
};


template< class TPtr = HookStaticCode, class _TCheckAsm = CheckAsmNoConditionalBranching >
class DaHookStaticCodePtr : public HookStaticCodePtr<TPtr>
{
public:
	DaHookStaticCodePtr<TPtr,_TCheckAsm>( const TPtr* pArg,
																				const PVOID pvTarget,
																				const FunctionInfo info,
																				const FARPROC pfPre = NULL,
																				const FARPROC pfPost = NULL,
																				F_Callback pfPreHookCallback = PreHookCallback )
		: HookStaticCodePtr<TPtr>( pArg,
															 pvTarget,
															 pvTarget? DaCheckInstructionOrAlign<AsmFarCall,AsmFarJmp,_TCheckAsm>( pvTarget ) : 0,
															 info,
															 pfPre,
															 pfPost,
															 pfPreHookCallback )
		{}
protected:
	static bool PreHookCallback( HookFunctionEntry* pThis )
		{
			return FixupRelocatedCode( (BYTE*)pThis->GetTarget(), (BYTE*)pThis->GetSavedCode() );
		}
};


template< class _TCheckAsm = CheckAsmNoConditionalBranching >
class DaHookFunctionEntry : public HookFunctionEntry
{
public:
	DaHookFunctionEntry<_TCheckAsm>( const FARPROC pfTarget,
																	 const FARPROC pfWrapperFunction,
																	 const FunctionInfo info,
																	 F_Callback pfPreHookCallback = PreHookCallback )
		: HookFunctionEntry( pfTarget,
												 DaCheckInstructionOrAlign<AsmFarCall,AsmFarJmp,_TCheckAsm>( pfTarget ),
												 pfWrapperFunction,
												 info,
												 pfPreHookCallback )
		{}
protected:
	static bool PreHookCallback( HookFunctionEntry* pThis )
		{
			return FixupRelocatedCode( (BYTE*)pThis->GetTarget(), (BYTE*)pThis->GetOriginalCode() );
		}
};


template< class TPtr = HookFunctionEntry, class _TCheckAsm = CheckAsmNoConditionalBranching >
class DaHookFunctionEntryPtr : public HookFunctionEntryPtr<TPtr>
{
public:
	DaHookFunctionEntryPtr<TPtr,_TCheckAsm>( const TPtr* pArg,
																					 const FARPROC pfTarget,
																					 const FARPROC pfWrapperFunction,
																					 const FunctionInfo info,
																					 F_Callback pfPreHookCallback = PreHookCallback )
		: HookFunctionEntryPtr<TPtr>( pArg,
																	pfTarget,
																	DaCheckInstructionOrAlign<AsmFarCall,AsmFarJmp,_TCheckAsm>( pfTarget ),
																	pfWrapperFunction,
																	info,
																	pfPreHookCallback )
		{}
	DaHookFunctionEntryPtr<TPtr,_TCheckAsm>( const FARPROC pfTarget,
																					 const FARPROC pfWrapperFunction,
																					 const FunctionInfo info,
																					 F_Callback pfPreHookCallback = PreHookCallback )
		: HookFunctionEntryPtr<TPtr>( pfTarget,
																	DaCheckInstructionOrAlign<AsmFarCall,AsmFarJmp,_TCheckAsm>( pfTarget ),
																	pfWrapperFunction,
																	info,
																	pfPreHookCallback )
		{}
protected:
	static bool PreHookCallback( HookFunctionEntry* pThis )
		{
			return FixupRelocatedCode( (BYTE*)pThis->GetTarget(), (BYTE*)pThis->GetOriginalCode() );
		}
};


template< typename _CWrapper = NullFunctionWrapper, class _TCheckAsm = CheckAsmNoConditionalBranching >
class DLLEXPORT DaWrapFunctionEntry : public WrapFunctionEntry<_CWrapper>
{
public:
	DaWrapFunctionEntry( const FARPROC pfTargetFunction, F_Callback pfPreHookCallback = PreHookCallback  )
		: WrapFunctionEntry<_CWrapper>
				(	pfTargetFunction,
					DaCheckInstructionOrAlign<AsmFarCall,AsmFarJmp,_TCheckAsm>( pfTargetFunction ),
					pfPreHookCallback )
		{}
protected:
	static bool PreHookCallback( WrapFunctionEntryBase* pThis )
		{
			return FixupRelocatedCode( (BYTE*)pThis->GetTarget(), (BYTE*)pThis->GetOriginalCode() );
		}
};


template< typename _CWrapper = NullFunctionWrapper >
class DLLEXPORT DaWrapCall : public WrapCall<_CWrapper>
{
public:
	DaWrapCall( const PVOID pAsmCall )
		: WrapCall<_CWrapper>( DaInstructionCast<AsmFarCall>(pAsmCall) )
		{}
};



#endif //_DISASMHOOK_H_

// CreateInstruction.cpp
// Copyright 2003 ManuSoft
// http://www.manusoft.com
//
// Use of this software is governed by the terms of:
// GNU General Public License v2.0
// See LICENSE for details

#include "StdAfx.h"
#include "CreateInstruction.h"

namespace DaCI //forward declarations
{
	#include "OpCodeTables.h"
	template< CITable OpCode > bool DaSpOpcodeLookup( DaInstruction& In );
};

//Starting point for deriving new instruction
DaInstruction* CreateInstruction( DaByteStream& Source, const DaStatus* pStatus )
{
	DaInstruction* pNewInstruction = new DaInstruction( Source, pStatus );
	if( !pNewInstruction )
		return NULL;
	DaCI::DaSpOpcodeLookup<DaCI::MainOpCode>( *pNewInstruction );
	return pNewInstruction;
}


//Hide implementation details inside private namespace
namespace DaCI
{

//Lookup instruction from table and call processors
bool DaCallProcessors( DaInstruction& In, DaStreamProcessor* rSpArray, ULONG cElements )
{
	for( ULONG idxProcessor = 0; idxProcessor < cElements; idxProcessor++ )
	{
		DaStreamProcessor pfSp = rSpArray[idxProcessor];
		if( pfSp )
		{
			if( !pfSp( In ) )
				return false;
		}
	}
	return true;
}

template< CITable OpCode >
bool DaSpOpcodeLookup( DaInstruction& In )
{
	return DaCallProcessors( In, OpCode[In.Get()], (sizeof(OpCode[0]) / sizeof(OpCode[0][0])) );
}


//Stream Processors used to set status flags
bool DaSpUndefinedInstruction( DaInstruction& In )
{
	In.GetStatus().State.Undef = true;
	return false;
}

bool DaSpIllegalInstruction( DaInstruction& In )
{
	DaStatus& Status = In.GetStatus();
	Status.State.Undef = true;
	Status.State.Illegal = true;
	return false;
}

bool DaSpBranch( DaInstruction& In )
{
	In.GetStatus().Branch.Branch = true;
	return true;
}

bool DaSpConditionalBranch( DaInstruction& In )
{
	In.GetStatus().Branch.Conditional = true;
	return DaSpBranch( In );
}

bool DaSpAbsoluteBranch( DaInstruction& In )
{
	In.GetStatus().Branch.Absolute = true;
	return DaSpBranch( In );
}

bool DaSpCallBranch( DaInstruction& In )
{
	In.GetStatus().Branch.Call = true;
	return DaSpBranch( In );
}

bool DaSpAbsoluteCallBranch( DaInstruction& In )
{
	In.GetStatus().Branch.Absolute = true;
	return DaSpCallBranch( In );
}

bool DaSpMemoryOperand( DaInstruction& In )
{
	In.GetStatus().XRef.bMemOperand = true;
	return true;
}

bool DaSpMemoryWrite( DaInstruction& In )
{
	In.GetStatus().XRef.bWrite = true;
	return true;
}

bool DaSpToggleAddressSize( DaInstruction& In )
{
	In.GetStatus().State.Addr32 ^= 1;
	return true;
}

bool DaSpToggleOperandSize( DaInstruction& In )
{
	In.GetStatus().State.Op32 ^= 1;
	return true;
}

#ifdef _AMD64_
bool DaSpSetAmd64OperandEx( DaInstruction& In, bool bSet = true )
{
	DaPrefixState& Prefix = In.GetStatus().Prefix;
	if( Prefix.RexW == bSet )
		return DaSpUndefinedInstruction( In );
	Prefix.RexW = bSet;
	return true;
}

bool DaSpSetAmd64RegisterEx( DaInstruction& In, bool bSet = true )
{
	DaPrefixState& Prefix = In.GetStatus().Prefix;
	if( Prefix.RexR == bSet )
		return DaSpUndefinedInstruction( In );
	Prefix.RexR = bSet;
	return true;
}

bool DaSpSetAmd64IndexEx( DaInstruction& In, bool bSet = true )
{
	DaPrefixState& Prefix = In.GetStatus().Prefix;
	if( Prefix.RexX == bSet )
		return DaSpUndefinedInstruction( In );
	Prefix.RexX = bSet;
	return true;
}

bool DaSpSetAmd64BaseEx( DaInstruction& In, bool bSet = true )
{
	DaPrefixState& Prefix = In.GetStatus().Prefix;
	if( Prefix.RexB == bSet )
		return DaSpUndefinedInstruction( In );
	Prefix.RexB = bSet;
	return true;
}
#endif //_AMD64_

bool DaSpLockPrefixAllowed( DaInstruction& In )
{
	In.GetStatus().Prefix.LockAllowed = true;
	return true;
}

bool DaSpRepPrefixAllowed( DaInstruction& In )
{
	In.GetStatus().Prefix.RepAllowed = true;
	return true;
}

bool DaSpRepNEPrefixAllowed( DaInstruction& In )
{
	In.GetStatus().Prefix.RepNEAllowed = true;
	return true;
}

bool DaSpGroup1Prefix( DaInstruction& In )
{
	DaPrefixState& Prefix = In.GetStatus().Prefix;
	if( Prefix.Group1 )
		return DaSpUndefinedInstruction( In );
	Prefix.Group1 = true;
	return true;
}

bool DaSpGroup2Prefix( DaInstruction& In )
{
	DaPrefixState& Prefix = In.GetStatus().Prefix;
	if( Prefix.Group2 )
		return DaSpUndefinedInstruction( In );
	Prefix.Group2 = true;
	return true;
}

bool DaSpGroup3Prefix( DaInstruction& In )
{
	DaPrefixState& Prefix = In.GetStatus().Prefix;
	if( Prefix.Group3 )
		return DaSpUndefinedInstruction( In );
	Prefix.Group3 = true;
	return true;
}

bool DaSpGroup4Prefix( DaInstruction& In )
{
	DaPrefixState& Prefix = In.GetStatus().Prefix;
	if( Prefix.Group4 )
		return DaSpUndefinedInstruction( In );
	Prefix.Group4 = true;
	return true;
}


//Stream Processors used to process specific parts of instructions
template< typename T >
bool DaSpImmediateOp( DaInstruction& In )
{
	In.Extend( sizeof(T) );
	DaSpMemoryOperand( In );
	return true;
}

template<>
bool DaSpImmediateOp<SpModeDependent>( DaInstruction& In )
{
	ULONG cbOp = In.GetStatus().State.Op32? 4 : 2;
	In.Extend( cbOp );
	DaSpMemoryOperand( In );
	return true;
}

template<>
bool DaSpImmediateOp<SpModeDependentRexW>( DaInstruction& In )
{
	ULONG cbOp = In.GetStatus().State.Op32? 4 : 2;
#ifdef _AMD64_
	if( In.GetStatus().Prefix.RexW )
		cbOp = 8;
#endif
	In.Extend( cbOp );
	DaSpMemoryOperand( In );
	return true;
}

template< bool bMemoryWrite >
bool DaSpOffsetOp( DaInstruction& In )
{
	In.Extend( In.GetStatus().State.Addr32? 4 : 2 );
	DaSpMemoryOperand( In );
	if( bMemoryWrite == SpMemoryWrite )
		DaSpMemoryWrite( In );
	return true;
}

template< typename T >
bool DaSpRelativeOffset( DaInstruction& In )
{
	ULONG cbBefore = In.Size();
	DaSpImmediateOp<T>( In );
	In.GetStatus().Offset = (DaByte)(In.Size() - cbBefore);
	return true;
}

template< bool bMemoryWrite >
bool DaSpModRM16( DaInstruction& In )
{
	DaModRM ModRM( In.Get() );
	switch( ModRM.Mode() )
	{
		case 0:
		{
			if( ModRM.RM() == 6 )
				In.Extend( 2 ); //16 bit displacement
			DaSpMemoryOperand( In );
			if( bMemoryWrite == SpMemoryWrite )
				DaSpMemoryWrite( In );
			break;
		}
		case 1:
		{
			In.Extend( 1 ); //8 bit displacement
			DaSpMemoryOperand( In );
			if( bMemoryWrite == SpMemoryWrite )
				DaSpMemoryWrite( In );
			break;
		}
		case 2:
		{
			In.Extend( 2 ); //16 bit displacement
			DaSpMemoryOperand( In );
			if( bMemoryWrite == SpMemoryWrite )
				DaSpMemoryWrite( In );
			break;
		}
		case 3:
		{
			break;
		}
	}
	return true;
}

template< bool bMemoryWrite >
bool DaSpModRM32( DaInstruction& In )
{
	DaModRM ModRM( In.Get() );
	switch( ModRM.Mode() )
	{
		case 0:
		{
			if( ModRM.RM() == 4 )
				In.Extend( 1 ); //SIB byte
			else if( ModRM.RM() == 5 )
				In.Extend( 4 ); //32 bit displacement
			DaSpMemoryOperand( In );
			if( bMemoryWrite == SpMemoryWrite )
				DaSpMemoryWrite( In );
			break;
		}
		case 1:
		{
			if( ModRM.RM() == 4 )
				In.Extend( 1 ); //SIB byte
			In.Extend( 1 ); //8 bit displacement
			DaSpMemoryOperand( In );
			if( bMemoryWrite == SpMemoryWrite )
				DaSpMemoryWrite( In );
			break;
		}
		case 2:
		{
			if( ModRM.RM() == 4 )
				In.Extend( 1 ); //SIB byte
			In.Extend( 4 ); //32 bit displacement
			DaSpMemoryOperand( In );
			if( bMemoryWrite == SpMemoryWrite )
				DaSpMemoryWrite( In );
			break;
		}
		case 3:
		{
			break;
		}
	}
	return true;
}

#ifdef _AMD64_
template< bool bMemoryWrite >
bool DaSpModRM64( DaInstruction& In )
{
	DaModRM ModRM( In.Get() );
	switch( ModRM.Mode() )
	{
		case 0:
		{
			DaByte RM = ModRM.RM();
			if( RM == 4 )
				In.Extend( 1 ); //SIB byte
			else if( RM == 5 )
			{
				In.Extend( 4 ); //32 bit displacement
				In.GetStatus().Offset = 4;
			}
			DaSpMemoryOperand( In );
			if( bMemoryWrite == SpMemoryWrite )
				DaSpMemoryWrite( In );
			break;
		}
		case 1:
		{
			if( ModRM.RM() == 4 )
				In.Extend( 1 ); //SIB byte
			In.Extend( 1 ); //8 bit displacement
			DaSpMemoryOperand( In );
			if( bMemoryWrite == SpMemoryWrite )
				DaSpMemoryWrite( In );
			break;
		}
		case 2:
		{
			if( ModRM.RM() == 4 )
				In.Extend( 1 ); //SIB byte
			In.Extend( 4 ); //32 bit displacement
			DaSpMemoryOperand( In );
			if( bMemoryWrite == SpMemoryWrite )
				DaSpMemoryWrite( In );
			break;
		}
		case 3:
		{
			break;
		}
	}
	return true;
}
#endif //_AMD64_

template< bool bMemoryWrite >
bool DaSpModRM( DaInstruction& In )
{
	if( !In.GetStatus().State.Addr32 )
		return DaSpModRM16<bMemoryWrite>( In );
#ifdef _AMD64_
	return DaSpModRM64<bMemoryWrite>( In );
#else //_AMD64_
	return DaSpModRM32<bMemoryWrite>( In );
#endif //_AMD64_
}

template< bool bMemoryWrite >
bool DaSpModRMMemOnly( DaInstruction& In )
{
	if( !DaSpModRM<bMemoryWrite>( In ) )
		return false;
	if( !In.GetStatus().XRef.bMemOperand ) //valid instruction must have memory operand
		return DaSpUndefinedInstruction( In );
	return true;
}

bool DaSpModRMRegOnly( DaInstruction& In )
{
	if( !DaSpModRM<SpNoMemoryWrite>( In ) )
		return false;
	if( In.GetStatus().XRef.bMemOperand ) //valid instruction cannot have memory operand
		return DaSpUndefinedInstruction( In );
	return true;
}

template< ExOpTable rGroupEx >
bool DaSpModRMExtended( DaInstruction& In )
{
	return DaCallProcessors( In,
													 rGroupEx[DaModRM( In.PeekAt( 1 ) ).Op()],
													 (sizeof(rGroupEx[0]) / sizeof(rGroupEx[0][0])) );
}

template< FPModRMTable* pFBTable >
bool DaSpFPExtended( DaInstruction& In )
{
	DaModRM ModRM( In.PeekAt( 1 ) );
	if( ModRM.Mode() != 3 )
		return DaCallProcessors( In,
														 pFBTable->ExOp[ModRM.Op()],
														 (sizeof(pFBTable->ExOp[0]) / sizeof(pFBTable->ExOp[0][0])) );
	In.Pop();
	return DaCallProcessors( In,
													 pFBTable->FPOpTable[ModRM.ExOp()],
													 (sizeof(pFBTable->FPOpTable[0]) / sizeof(pFBTable->FPOpTable[0][0])) );
}

static bool DaSpPrefixedInstruction( DaInstruction& In )
{
	if( !DaSpOpcodeLookup<MainOpCode>( In ) )
		return DaSpUndefinedInstruction( In );
	return true;
}

#ifdef _AMD64_
static bool DaSpAmd64OperandEx( DaInstruction& In )
{
	return DaSpSetAmd64OperandEx( In );
}

static bool DaSpAmd64RegisterEx( DaInstruction& In )
{
	return DaSpSetAmd64RegisterEx( In );
}

static bool DaSpAmd64IndexEx( DaInstruction& In )
{
	return DaSpSetAmd64IndexEx( In );
}

static bool DaSpAmd64BaseEx( DaInstruction& In )
{
	return DaSpSetAmd64BaseEx( In );
}
#endif //_AMD64_

static bool DaSpOperandSizeOverridePrefixedInstruction( DaInstruction& In )
{
	DaSpToggleOperandSize( In );
	if( !DaSpPrefixedInstruction( In ) )
		return DaSpUndefinedInstruction( In );
	if( !DaSpGroup3Prefix( In ) )
		return false;
/*
	if( MMX, SSE, SSE2 )
		return DaSpUndefinedInstruction( In );
*/
	return true;
}

static bool DaSpAddressSizeOverridePrefixedInstruction( DaInstruction& In )
{
	DaSpToggleAddressSize( In );
	if( !DaSpPrefixedInstruction( In ) )
		return DaSpUndefinedInstruction( In );
	if( !DaSpGroup3Prefix( In ) )
		return false;
	if( !In.GetStatus().XRef.bMemOperand ) //valid instruction must have memory operand
		return DaSpUndefinedInstruction( In );
	return true;
}

static bool DaSpGroup1PrefixedInstruction( DaInstruction& In )
{
	if( !DaSpPrefixedInstruction( In ) )
		return false;
	if( !DaSpGroup1Prefix( In ) )
		return false;
	return true;
}

static bool DaSpLockPrefixedInstruction( DaInstruction& In )
{
	if( !DaSpGroup1PrefixedInstruction( In ) )
		return false;
	if( !In.GetStatus().Prefix.LockAllowed )
		return DaSpUndefinedInstruction( In );
	return true;
}

static bool DaSpRepPrefixedInstruction( DaInstruction& In )
{
	if( !DaSpGroup1PrefixedInstruction( In ) )
		return false;
	if( !In.GetStatus().Prefix.RepAllowed )
		return DaSpUndefinedInstruction( In );
	return true;
}

static bool DaSpRepNEPrefixedInstruction( DaInstruction& In )
{
	if( !DaSpGroup1PrefixedInstruction( In ) )
		return false;
	if( !In.GetStatus().Prefix.RepNEAllowed )
		return DaSpUndefinedInstruction( In );
	return true;
}

static bool DaSpSegmentOverridePrefixedInstruction( DaInstruction& In )
{
	if( !DaSpPrefixedInstruction( In ) )
		return DaSpIllegalInstruction( In );
	if( !DaSpGroup2Prefix( In ) )
		return false;
	if( In.GetStatus().Branch.Branch ) //undefined when used with a branch instruction
		return DaSpUndefinedInstruction( In );
	return true;
}

static bool DaSpBranchHintOrSegmentOverridePrefixedInstruction( DaInstruction& In )
{
	DaStatus& Status = In.GetStatus();
	if( !Status.State.Addr32 ) //segment override in 16 bit addressing mode
		return DaSpSegmentOverridePrefixedInstruction( In );
	//else it's branch hint
	if( !DaSpPrefixedInstruction( In ) )
	{
		DaSpIllegalInstruction( In );
		return false;
	}
	if( !DaSpGroup2Prefix( In ) )
		return false;
	//must be used with a conditional branch instruction
	if( !(Status.Branch.Branch && Status.Branch.Conditional) )
		return DaSpUndefinedInstruction( In );
	return true;
}

#include "OpCodeTables.cpp"

}; //namespace DaCI

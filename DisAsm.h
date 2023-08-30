// DisAsm.h
// Copyright 2003 ManuSoft
// http://www.manusoft.com
//
// Use of this software is governed by the terms of:
// GNU General Public License v2.0
// See LICENSE for details

#ifndef _DISASM_H_
#define _DISASM_H_


#include "Stream.h"
#ifndef _NO_TRACING_SUPPORT
#include <ostream> //need ostream for dumping object state
#include <iomanip>
typedef std::ostream ostream;
#endif //_NO_TRACING_SUPPORT

// Basic types
typedef BYTE DaByte;
typedef WORD DaWord;
typedef DWORD DaDWord;
typedef ULONG64 DaQWord;
struct DaStatus;
template< typename _TSource > class DaInstructionBase;
typedef DaStream<const DaByte> DaByteStream;
typedef DaInstructionBase<DaByteStream> DaInstruction;


struct DaCpuState
{
	bool Undef : 1;     //undefined state
	bool Illegal : 1;   //illegal instruction
	bool Addr32 : 1;    //32 bit addressing mode
	bool Op32 : 1;      //32 bit operand mode
	DaCpuState() : Undef( false ), Illegal( false ), Addr32( true ), Op32( true ) {}
	DaCpuState( const DaCpuState* pState ) { *this = (pState? *pState : DaCpuState()); }
	operator bool() const { return (!Undef && !Illegal); }
#ifndef _NO_TRACING_SUPPORT
	ostream& Dump( ostream& os ) const;
#endif //_NO_TRACING_SUPPORT
};

struct DaBranchState
{
	bool Branch : 1;       //true if branching is possible
	bool Conditional : 1;  //true if branching is conditional
	bool Absolute : 1;     //true if branching is absolute (i.e. not relative to EIP)
	bool Call : 1;         //true if branching is CALL instruction
	DaBranchState() : Branch( false ), Conditional( false ), Call( false ), Absolute( false ) {}
#ifndef _NO_TRACING_SUPPORT
	ostream& Dump( ostream& os ) const;
#endif //_NO_TRACING_SUPPORT
};

struct DaPrefixState
{
	bool Group1 : 1;       //true if prefix from Group1 is present
	bool Group2 : 1;       //true if prefix from Group2 is present
	bool Group3 : 1;       //true if prefix from Group3 is present
	bool Group4 : 1;       //true if prefix from Group4 is present
	bool LockAllowed : 1;  //true if LOCK prefix allowed
	bool RepAllowed : 1;   //true if REP/REPE prefix allowed
	bool RepNEAllowed : 1; //true if REPNE prefix allowed
#ifdef _AMD64_
	bool RexB : 1;         //ModRM r/m, base, operand reg extension
	bool RexX : 1;         //SIB index extension
	bool RexR : 1;         //ModRM reg extension
	bool RexW : 1;         //64 bit operand mode
#endif //_AMD64_
	DaPrefixState()
		: Group1( false ), Group2( false ), Group3( false ), Group4( false ),
			LockAllowed( false ), RepAllowed( false ), RepNEAllowed( false )
		#ifdef _AMD64_
			, RexW( false ), RexR( false ), RexX( false ), RexB( false )
		#endif //_AMD64_
		{}
#ifndef _NO_TRACING_SUPPORT
	ostream& Dump( ostream& os ) const;
#endif //_NO_TRACING_SUPPORT
};

typedef enum{ eNone, eDisp8, eRel8, eDisp16, eRel16, eDisp32, eRel32, eDisp64, eRel64 } DaAddressingMode;

//Container to hold any type of memory reference
union DaMemRefU
{
	DaByte mem8;
	DaWord mem16;
	DaDWord mem32;
	DaQWord mem64;
	DaMemRefU() : mem64( 0 ) {}
	DaMemRefU( DaByte Op ) : mem8( Op ) {}
	DaMemRefU( DaWord Op ) : mem16( Op ) {}
	DaMemRefU( DaDWord Op ) : mem32( Op ) {}
	DaMemRefU( DaQWord Op ) : mem64( Op ) {}
};

struct DaOffset
{
	DaByte cbSize;
	DaOffset() : cbSize( 0 ) {}
	DaOffset& operator=( ULONG cbNewSize ) { cbSize = (DaByte)cbNewSize; return *this; }
	operator bool() const { return (cbSize != 0); }
#ifndef _NO_TRACING_SUPPORT
	ostream& Dump( ostream& os ) const;
#endif //_NO_TRACING_SUPPORT
};

struct DaXRef
{
	bool bMemOperand : 1;
	bool bWrite : 1;
	DaXRef() : bMemOperand( false ), bWrite( false ) {}
#ifndef _NO_TRACING_SUPPORT
	ostream& Dump( ostream& os ) const;
#endif //_NO_TRACING_SUPPORT
};

struct DaStatus
{
	DaCpuState State;     //CPU state
	DaXRef XRef;          //external ref
	DaOffset Offset;      //relative offset
	DaBranchState Branch; //branching
	DaPrefixState Prefix; //opcode prefixes
	DaStatus() {}
	DaStatus( const DaStatus* pStatus ) { if( pStatus ) State = pStatus->State; }
#ifndef _NO_TRACING_SUPPORT
	ostream& Dump( ostream& os ) const;
#endif //_NO_TRACING_SUPPORT
};


template< typename _TSource >
class DaInstructionBase
{
	_TSource& m_Source;
	ULONG m_idxInstructionStart;
	ULONG m_cbSize;
	DaStatus m_Status;
private:
	DaInstructionBase& operator=( DaInstructionBase& );
public:
	typedef typename _TSource::_TData _TData;
	DaInstructionBase( _TSource& Source, const DaStatus* pStatus = NULL, ULONG cbSize = 0 )
		: m_Source( Source ),
			m_idxInstructionStart( Source.Tell() ),
			m_cbSize( cbSize ),
			m_Status( pStatus )
		{}
	virtual ~DaInstructionBase() {}
	const ULONG Size() const { return m_cbSize; }
	const ULONG StartPoint() const { return m_idxInstructionStart; }
	const _TData* Peer() const { return PeerAt( 0 ); }
	const _TData* PeerAt( LONG idxOffset ) const
		{
			if( m_idxInstructionStart + idxOffset < 0 )
				return NULL;
			return m_Source.PeerAt( m_idxInstructionStart + idxOffset );
		}
	const _TData* Pop() { m_Source.Pop(); return m_Source.PeerAt( m_idxInstructionStart + m_cbSize++ ); }
	const _TData Get() { return *Pop(); }
	const _TData Peek() const { return PeekAt( 0 ); }
	const _TData PeekAt( LONG idxOffset ) const
		{
			const _TData* pData = PeerAt( idxOffset );
			if( !pData )
				throw;
			return *pData;
		}
	const DaStatus& GetStatus() const { return m_Status; }
	DaStatus& GetStatus() { return m_Status; }
	operator bool() const { return m_Status.State; }
	DaInstructionBase<_TSource>& Extend( ULONG cbSize = 1 )
		{ m_cbSize += cbSize; m_Source.Pop( cbSize ); return *this; }
#ifndef _NO_TRACING_SUPPORT
	ostream& Dump( ostream& os ) const
	{
		if( !m_Status.State ) //illegal or undefined
			os << "## ";
		os << "DaInstructionBase[ @" << std::setbase( 16 ) << m_idxInstructionStart << " < ";
		os << std::setfill( '0' );
		for( ULONG idx = 0; idx < m_cbSize; idx++ )
			os << std::setw( 2 ) << (UINT)PeekAt( idx ) << " ";
		os << std::setbase( 10 ) << ">]" << std::endl;
		return m_Status.Dump( os ) << std::endl;
	}
#endif //_NO_TRACING_SUPPORT
};

#endif //_DISASM_H_

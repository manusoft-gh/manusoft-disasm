// InstructionSequence.h
// Copyright 2003 ManuSoft
// http://www.manusoft.com

#ifndef _INSTRUCTIONSEQUENCE_H_
#define _INSTRUCTIONSEQUENCE_H_


#include "DisAsm.h"
#include <list>
#include <algorithm>


template< typename _TInstruction, typename _TSource >
class DaInstructionSequenceT
{
	typedef _TInstruction* (*_TInstructionCreator)( _TSource&, const DaStatus* );
	_TSource m_Stream; //private copy of stream
	_TInstructionCreator m_pfCreator;
	std::list< _TInstruction* > m_listSequence;
	const DaStatus m_InitialStatus;
public:
	DaInstructionSequenceT( const _TSource& Stream, _TInstructionCreator pfCreator, const DaStatus* pStatus = NULL )
		: m_Stream( Stream ), m_pfCreator( pfCreator ), m_InitialStatus( pStatus )
		{ m_Stream.Seek( 0 ); }
	DaInstructionSequenceT( const DaInstructionSequenceT& Source )
		: m_Stream( Source.m_Stream ),
			m_pfCreator( Source.m_pfCreator ),
			m_InitialStatus( Source.m_InitialStatus )
		{ m_Stream.Seek( 0 ); }
	virtual ~DaInstructionSequenceT()
		{ std::for_each( begin(), end(), DeleteListMember ); }
	const DaStatus& GetInitialStatus() const { return m_InitialStatus; }
	operator bool() const
		{
			const_iterator iter = begin();
			while( iter != end() )
			{
				if( !*iter )
					return false;
				++iter;
			}
			return true;
		}
	ULONG GetStreamHighWater() const
		{
			const_iterator iter = end();
			if( iter == begin() )
				return 0;
			const _TInstruction* pLast = *(--iter);
			return pLast->StartPoint() + pLast->Size();
		}
	_TInstruction* PushBack()
		{
			_TInstruction* pNew = m_pfCreator( m_Stream, &m_InitialStatus );
			if( !pNew )
				return NULL;
			m_listSequence.push_back( pNew );
			return *(--end());
		}
	bool Extend( ULONG cInstructionsToAdd = 1 )
		{
			while( cInstructionsToAdd-- > 0 )
				{ if( !PushBack() ) return false; }
			return true;
		}
	bool Process( ULONG cbBytesToProcess )
		{
			ULONG cbGoal = m_Stream.Tell() + cbBytesToProcess;
			while( m_Stream.Tell() < cbGoal )
				{ if( !PushBack() ) return false; }
			return true;
		}

	//std::list interface
	typedef typename std::list< _TInstruction* >::size_type size_type;
	typedef typename std::list< _TInstruction* >::iterator iterator;
	typedef typename std::list< _TInstruction* >::const_iterator const_iterator;
	size_type size() const { return m_listSequence.size(); }
	bool empty() const { return m_listSequence.empty(); }
	iterator begin() { return m_listSequence.begin(); }
	const_iterator begin() const { return m_listSequence.begin(); }
	iterator end() { return m_listSequence.end(); }
	const_iterator end() const { return m_listSequence.end(); }

private:
	static void DeleteListMember( _TInstruction* pI ) { delete pI; }

#ifdef _DEBUG
public:
	ostream& Dump( ostream& os ) const
	{
		os << "DaInstructionSequenceT [" << (ULONG)size() << "]" << std::endl;
		ULONG idx = 0;
		const_iterator iter = begin();
		while( iter != end() )
		{
			os << '(' << idx++ << ") ";
			(*iter++)->Dump( os );
		}
		return os;
	}
#endif //_DEBUG
};

typedef DaInstructionSequenceT< DaInstruction, DaByteStream > DaInstructionSequence;

#endif //_INSTRUCTIONSEQUENCE_H_
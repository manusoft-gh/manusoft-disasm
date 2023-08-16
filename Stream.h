// Stream.h
// Copyright 2003 ManuSoft
// http://www.manusoft.com

#ifndef _STREAM_H_
#define _STREAM_H_


#include "DisAsm.h"


template<typename T = DaByte>
class DaStream
{
	T* m_pStream;
	ULONG m_idxCursor;
public:
	typedef T _TData;
	DaStream( T* pStream ) : m_pStream( pStream ), m_idxCursor( 0 ) {}
	virtual ~DaStream() {}

	DaStream& operator+( ULONG cbOperand ) { Advance( cbOperand ); return *this; }
	DaStream& operator-( ULONG cbOperand ) { Retreat( cbOperand ); return *this; }
	DaStream& operator++() { Advance( 1 ); return *this; }
	DaStream& operator--() { Retreat( 1 ); return *this; }
	ULONG Tell() const { return m_idxCursor; }
	DaStream& Seek( ULONG idxPosition )
		{ if( (ULONG)-1 == idxPosition ) throw; m_idxCursor = idxPosition; return *this; }
	T* Peer() const { return m_pStream + m_idxCursor; }
	T* PeerAt( ULONG idxPosition ) const { return m_pStream + idxPosition; }
	T Peek() const { return *Peer(); }
	T PeekAt( ULONG idxPosition ) const { return *PeerAt( idxPosition ); }
	T Get() { return *Pop(); }
	T GetAt( ULONG idxPosition ) { Seek( idxPosition ); return *Pop(); }
	const T* Pop() { const T* pRet = Peer(); Advance(); return pRet; }
	const T* Pop( ULONG cbForward ) { const T* pRet = Peer(); Advance( cbForward ); return pRet; }
protected:
	void Advance() { m_idxCursor++; }
	void Advance( ULONG cbForward ) { m_idxCursor += cbForward; }
	void Retreat() { Seek( m_idxCursor - 1 ); }
	void Retreat( ULONG cbBackward )
		{ if( cbBackward > m_idxCursor ) throw; Seek( m_idxCursor - cbBackward ); }
};


#endif //_STREAM_H_
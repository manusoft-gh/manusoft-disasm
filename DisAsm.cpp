// DisAsm.cpp
// Copyright 2003 ManuSoft
// http://www.manusoft.com
//
// Use of this software is governed by the terms of:
// GNU General Public License v2.0
// See LICENSE for details

#include "StdAfx.h"
#include "DisAsm.h"


//Define dump helpers that are only declared in a debug build
#ifndef _NO_TRACING_SUPPORT
ostream& DaCpuState::Dump( ostream& os ) const
{
	return os <<
					"DaCpuState{ " <<
					(Undef? "##Undefined##, " : "") <<
					(Illegal? "##Illegal##, " : "") <<
					(Addr32? "32" : "16") <<
					" bit addressing, " <<
					(Op32? "32" : "16") <<
					" bit operands" <<
					" }";
}

ostream& DaBranchState::Dump( ostream& os ) const
{
	return os <<
					"DaBranchState{ " <<
					(Branch? "Branch" : "No Branch") <<
					(Conditional? " (Conditional)" : "") <<
					" }";
}

ostream& DaPrefixState::Dump( ostream& os ) const
{
	os << "DaPrefixState{ ";
	if( Group1 || Group2 || Group3 || Group4 )
	{
		os << "Prefix[";
		if( Group1 )
			os << "1,";
		if( Group2 )
			os << "2,";
		if( Group3 )
			os << "3,";
		if( Group4 )
			os << "4,";
		os.seekp(-1, std::ios::cur) << "], ";
	}
	else
		os << "No Prefix, ";
	os << "Allowed[";
	if( LockAllowed || RepAllowed || RepNEAllowed )
	{
		if( LockAllowed )
			os << "LOCK,";
		if( RepAllowed )
			os << "REP,";
		if( RepNEAllowed )
			os << "REPNE,";
		os.seekp(-1, std::ios::cur);
	}
	else
		os << "None";
	os << "]";
	os << " }";
	return os;
}

ostream& DaOffset::Dump( ostream& os ) const
{
	os << "DaOffset{ ";
	if( cbSize == 0 )
		os << "No relative offset";
	else
		os << "Relative Offset (" << (ULONG)cbSize << " bytes)";
	return os << " }";
}

ostream& DaXRef::Dump( ostream& os ) const
{
	os << "DaXRef{ ";
	if( bMemOperand )
		os << "Memory Operand";
	else
		os << "No Memory Operand";
	if( bWrite )
		os << " (Write)";
	else if( bMemOperand )
		os << " (Read)";
	return os << " }";
}

ostream& DaStatus::Dump( ostream& os ) const
{
	os << "{+ DaStatus" << std::endl;
	State.Dump( os << "  " ) << std::endl;
	XRef.Dump( os << "  " ) << std::endl;
	Offset.Dump( os << "  " ) << std::endl;
	Branch.Dump( os << "  " ) << std::endl;
	Prefix.Dump( os << "  " ) << std::endl;
	os << "}" << std::endl;
	return os;
}
#endif //_NO_TRACING_SUPPORT

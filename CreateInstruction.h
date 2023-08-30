// CreateInstruction.h
// Copyright 2003 ManuSoft
// http://www.manusoft.com
//
// Use of this software is governed by the terms of:
// GNU General Public License v2.0
// See LICENSE for details

#ifndef _CREATEINSTRUCTION_H_
#define _CREATEINSTRUCTION_H_


#include "DisAsm.h"

//#pragma comment(lib,"DisAsm.lib") //must link to DisAsm.lib for CreateInstruction()


typedef bool (*DaStreamProcessor)( DaInstruction& );
typedef DaByte DaByteArray[];

#pragma pack(push)
#pragma pack(1)
union DaModRM
{
	DaByte AsByte;
	DaModRM( const DaByte Source ) { AsByte = Source; }
	operator const DaByte() const { return AsByte; }
	const DaByte RM() const { return (AsByte & 7); }
	const DaByte Reg() const { return ((AsByte >> 3) & 7); }
	const DaByte Op() const { return ((AsByte >> 3) & 7); }
	const DaByte Mode() const { return ((AsByte >> 6) & 3); }
	const DaByte ExOp() const { return (AsByte & 0x3F); }
};

struct DaSIB
{
	unsigned Base : 3;
	unsigned Index : 3;
	unsigned Scale : 2;
	DaSIB( const DaByte Source ) { *(DaByte*)this = Source; }
};
#pragma pack(pop)

//Starting point for deriving new instruction
DaInstruction* CreateInstruction( DaByteStream& Source, const DaStatus* pStatus );

//Definitions used for stream processors
typedef enum{ eOmit = 0, eByte = 1, eWord = 2, eDWord = 4, eMode = -1 } eSize;
typedef enum{ eNoBranch, eBranch, eConditionalBranch } eBranching;
typedef enum{ eNoModRM, eModRMReadMem, eModRMWriteMem } eMem;


//typename used to specify addressing mode dependent on current state
typedef struct{} SpModeDependent;
typedef struct{} SpModeDependentRexW; //64-bit immediate operand if Rex.W set
#define SpMemoryWrite true
#define SpNoMemoryWrite false


#endif //_CREATEINSTRUCTION_H_

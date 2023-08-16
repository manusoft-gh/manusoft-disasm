// OpCodeTables.h
// Copyright 2003 ManuSoft
// http://www.manusoft.com

#ifndef _OPCODETABLES_H_
#define _OPCODETABLES_H_


#include "StdAfx.h"
#include "DisAsm.h"
#include "CreateInstruction.h"


typedef DaStreamProcessor DaStreamProcessorArray[5];
typedef DaStreamProcessorArray CITable[256];
typedef DaStreamProcessorArray FPExOpTable[64];
typedef DaStreamProcessorArray ExOpTable[8];
typedef struct{ ExOpTable ExOp; FPExOpTable FPOpTable; } FPModRMTable;

extern ExOpTable Group1;
extern ExOpTable Group2;
extern ExOpTable Group3Byte;
extern ExOpTable Group3ModeDependent;
extern ExOpTable Group4;
extern ExOpTable Group5;
extern ExOpTable Group11;
extern FPModRMTable FPExtD8;
extern FPModRMTable FPExtD9;
extern FPModRMTable FPExtDA;
extern FPModRMTable FPExtDB;
extern FPModRMTable FPExtDC;
extern FPModRMTable FPExtDD;
extern FPModRMTable FPExtDE;
extern FPModRMTable FPExtDF;

extern CITable MainOpCode;
extern CITable ExtOpCode;


#endif //_OPCODETABLES_H_

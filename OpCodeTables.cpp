// OpCodeTables.cpp
// Copyright 2003 ManuSoft
// http://www.manusoft.com

#include "StdAfx.h"
#include "OpCodeTables.h"


ExOpTable Group1 =
{
	/*0x000*/	{ DaSpModRM<SpMemoryWrite>, }, //ADD
	/*0x001*/	{ DaSpModRM<SpMemoryWrite>, }, //OR
	/*0x010*/	{ DaSpModRM<SpMemoryWrite>, }, //ADC
	/*0x011*/	{ DaSpModRM<SpMemoryWrite>, }, //SBB
	/*0x100*/	{ DaSpModRM<SpMemoryWrite>, }, //AND
	/*0x101*/	{ DaSpModRM<SpMemoryWrite>, }, //SUB
	/*0x110*/	{ DaSpModRM<SpMemoryWrite>, }, //XOR
	/*0x111*/	{ DaSpModRM<SpMemoryWrite>, }, //CMP
};

ExOpTable Group2 =
{
	/*0x000*/	{ DaSpModRM<SpMemoryWrite>, }, //ROL
	/*0x001*/	{ DaSpModRM<SpMemoryWrite>, }, //ROR
	/*0x010*/	{ DaSpModRM<SpMemoryWrite>, }, //RCL
	/*0x011*/	{ DaSpModRM<SpMemoryWrite>, }, //RCR
	/*0x100*/	{ DaSpModRM<SpMemoryWrite>, }, //SHL/SAL
	/*0x101*/	{ DaSpModRM<SpMemoryWrite>, }, //SHR
	/*0x110*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x111*/	{ DaSpModRM<SpMemoryWrite>, }, //SAR
};

ExOpTable Group3Byte =
{
	/*0x000*/	{ DaSpModRM<SpMemoryWrite>, DaSpImmediateOp<DaByte>, }, //TEST (Ib)
	/*0x001*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x010*/	{ DaSpModRM<SpMemoryWrite>, }, //NOT
	/*0x011*/	{ DaSpModRM<SpMemoryWrite>, }, //NEG
	/*0x100*/	{ DaSpModRM<SpMemoryWrite>, }, //MUL (AL/eAX)
	/*0x101*/	{ DaSpModRM<SpMemoryWrite>, }, //IMUL (AL/eAX)
	/*0x110*/	{ DaSpModRM<SpMemoryWrite>, }, //DIV (AL/eAX)
	/*0x111*/	{ DaSpModRM<SpMemoryWrite>, }, //IDIV (AL/eAX)
};

ExOpTable Group3ModeDependent =
{
	/*0x000*/	{ DaSpModRM<SpMemoryWrite>, DaSpImmediateOp<SpModeDependent> }, //TEST (Iv)
	/*0x001*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x010*/	{ DaSpModRM<SpMemoryWrite>, }, //NOT
	/*0x011*/	{ DaSpModRM<SpMemoryWrite>, }, //NEG
	/*0x100*/	{ DaSpModRM<SpMemoryWrite>, }, //MUL (AL/eAX)
	/*0x101*/	{ DaSpModRM<SpMemoryWrite>, }, //IMUL (AL/eAX)
	/*0x110*/	{ DaSpModRM<SpMemoryWrite>, }, //DIV (AL/eAX)
	/*0x111*/	{ DaSpModRM<SpMemoryWrite>, }, //IDIV (AL/eAX)
};

ExOpTable Group4 =
{
	/*0x000*/	{ DaSpModRM<SpMemoryWrite>, }, //INC (Eb)
	/*0x001*/	{ DaSpModRM<SpMemoryWrite>, }, //DEC (Eb)
	/*0x010*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x011*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x110*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x111*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
};

ExOpTable Group5 =
{
	/*0x000*/	{ DaSpModRM<SpMemoryWrite>, }, //INC (Ev)
	/*0x001*/	{ DaSpModRM<SpMemoryWrite>, }, //DEC (Ev)
	/*0x010*/	{ DaSpModRM<SpMemoryWrite>, DaSpCallBranch, }, //CALLN (Ev)
	/*0x011*/	{ DaSpModRM<SpMemoryWrite>, DaSpAbsoluteCallBranch, }, //CALLF (Ep)
	/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpBranch, }, //JMPN (Ev)
	/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpAbsoluteBranch, }, //JMPF (Ep)
	/*0x110*/	{ DaSpModRM<SpMemoryWrite>, }, //PUSH (Ev)
	/*0x111*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
};

ExOpTable Group6 =
{
	/*0x000*/	{ DaSpModRM<SpMemoryWrite>, }, //SLDT (Ew)
	/*0x001*/	{ DaSpModRM<SpMemoryWrite>, }, //STR (Ev)
	/*0x010*/	{ DaSpModRM<SpNoMemoryWrite>, }, //LLDT (Ew)
	/*0x011*/	{ DaSpModRM<SpNoMemoryWrite>, }, //LTR (Ew)
	/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, }, //VERR (Ew)
	/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, }, //VERW (Ew)
	/*0x110*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x111*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
};

ExOpTable Group7 =
{
	/*0x000*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //SGDT (Ms)
	/*0x001*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //SIDT (Ms)
	/*0x010*/	{ DaSpModRMMemOnly<SpNoMemoryWrite>, }, //LGDT (Ms)
	/*0x011*/	{ DaSpModRMMemOnly<SpNoMemoryWrite>, }, //LIDT (Ms)
	/*0x100*/	{ DaSpModRM<SpMemoryWrite>, }, //SMSW (Ew)
	/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x110*/	{ DaSpModRM<SpNoMemoryWrite>, }, //LMSW (Ew)
	/*0x111*/	{ DaSpModRMMemOnly<SpNoMemoryWrite>, }, //INVLPG (Mb)
};

ExOpTable Group11 =
{
	/*0x000*/	{ DaSpModRM<SpMemoryWrite>, }, //MOV (Ev/Eb,Iv/Ib)
	/*0x001*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x010*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x011*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x110*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x111*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
};

ExOpTable Group16 =
{
	/*0x000*/	{ DaSpModRM<SpNoMemoryWrite>, }, //PREFETCH-NTA
	/*0x001*/	{ DaSpModRM<SpNoMemoryWrite>, }, //PREFETCH-T0
	/*0x010*/	{ DaSpModRM<SpNoMemoryWrite>, }, //PREFETCH-T1
	/*0x011*/	{ DaSpModRM<SpNoMemoryWrite>, }, //PREFETCH-T2
	/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x110*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
	/*0x111*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
};

FPModRMTable FPExtD8 =
{
	{
		/*0x000*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FADD (single-real)
		/*0x001*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FMUL (single-real)
		/*0x010*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FCOM (single-real)
		/*0x011*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FCOMP (single-real)
		/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FSUB (single-real)
		/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FSUBR (single-real)
		/*0x110*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FDIV (single-real)
		/*0x111*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FDIVR (single-real)
	},
	{
		/*0xC0*/	{ NULL, }, //FADD ST(0),ST(0)
		/*0xC1*/	{ NULL, }, //FADD ST(0),ST(1)
		/*0xC2*/	{ NULL, }, //FADD ST(0),ST(2)
		/*0xC3*/	{ NULL, }, //FADD ST(0),ST(3)
		/*0xC4*/	{ NULL, }, //FADD ST(0),ST(4)
		/*0xC5*/	{ NULL, }, //FADD ST(0),ST(5)
		/*0xC6*/	{ NULL, }, //FADD ST(0),ST(6)
		/*0xC7*/	{ NULL, }, //FADD ST(0),ST(7)
		/*0xC8*/	{ NULL, }, //FMUL ST(0),ST(0)
		/*0xC9*/	{ NULL, }, //FMUL ST(0),ST(1)
		/*0xCA*/	{ NULL, }, //FMUL ST(0),ST(2)
		/*0xCB*/	{ NULL, }, //FMUL ST(0),ST(3)
		/*0xCC*/	{ NULL, }, //FMUL ST(0),ST(4)
		/*0xCD*/	{ NULL, }, //FMUL ST(0),ST(5)
		/*0xCE*/	{ NULL, }, //FMUL ST(0),ST(6)
		/*0xCF*/	{ NULL, }, //FMUL ST(0),ST(7)
		/*0xD0*/	{ NULL, }, //FCOM ST(0),ST(0)
		/*0xD1*/	{ NULL, }, //FCOM ST(0),ST(1)
		/*0xD2*/	{ NULL, }, //FCOM ST(0),ST(2)
		/*0xD3*/	{ NULL, }, //FCOM ST(0),ST(3)
		/*0xD4*/	{ NULL, }, //FCOM ST(0),ST(4)
		/*0xD5*/	{ NULL, }, //FCOM ST(0),ST(5)
		/*0xD6*/	{ NULL, }, //FCOM ST(0),ST(6)
		/*0xD7*/	{ NULL, }, //FCOM ST(0),ST(7)
		/*0xD8*/	{ NULL, }, //FCOMP ST(0),ST(0)
		/*0xD9*/	{ NULL, }, //FCOMP ST(0),ST(1)
		/*0xDA*/	{ NULL, }, //FCOMP ST(0),ST(2)
		/*0xDB*/	{ NULL, }, //FCOMP ST(0),ST(3)
		/*0xDC*/	{ NULL, }, //FCOMP ST(0),ST(4)
		/*0xDD*/	{ NULL, }, //FCOMP ST(0),ST(5)
		/*0xDE*/	{ NULL, }, //FCOMP ST(0),ST(6)
		/*0xDF*/	{ NULL, }, //FCOMP ST(0),ST(7)
		/*0xE0*/	{ NULL, }, //FSUB ST(0),ST(0)
		/*0xE1*/	{ NULL, }, //FSUB ST(0),ST(1)
		/*0xE2*/	{ NULL, }, //FSUB ST(0),ST(2)
		/*0xE3*/	{ NULL, }, //FSUB ST(0),ST(3)
		/*0xE4*/	{ NULL, }, //FSUB ST(0),ST(4)
		/*0xE5*/	{ NULL, }, //FSUB ST(0),ST(5)
		/*0xE6*/	{ NULL, }, //FSUB ST(0),ST(6)
		/*0xE7*/	{ NULL, }, //FSUB ST(0),ST(7)
		/*0xE8*/	{ NULL, }, //FSUBR ST(0),ST(0)
		/*0xE9*/	{ NULL, }, //FSUBR ST(0),ST(1)
		/*0xEA*/	{ NULL, }, //FSUBR ST(0),ST(2)
		/*0xEB*/	{ NULL, }, //FSUBR ST(0),ST(3)
		/*0xEC*/	{ NULL, }, //FSUBR ST(0),ST(4)
		/*0xED*/	{ NULL, }, //FSUBR ST(0),ST(5)
		/*0xEE*/	{ NULL, }, //FSUBR ST(0),ST(6)
		/*0xEF*/	{ NULL, }, //FSUBR ST(0),ST(7)
		/*0xF0*/	{ NULL, }, //FDIV ST(0),ST(0)
		/*0xF1*/	{ NULL, }, //FDIV ST(0),ST(1)
		/*0xF2*/	{ NULL, }, //FDIV ST(0),ST(2)
		/*0xF3*/	{ NULL, }, //FDIV ST(0),ST(3)
		/*0xF4*/	{ NULL, }, //FDIV ST(0),ST(4)
		/*0xF5*/	{ NULL, }, //FDIV ST(0),ST(5)
		/*0xF6*/	{ NULL, }, //FDIV ST(0),ST(6)
		/*0xF7*/	{ NULL, }, //FDIV ST(0),ST(7)
		/*0xF8*/	{ NULL, }, //FDIVR ST(0),ST(0)
		/*0xF9*/	{ NULL, }, //FDIVR ST(0),ST(1)
		/*0xFA*/	{ NULL, }, //FDIVR ST(0),ST(2)
		/*0xFB*/	{ NULL, }, //FDIVR ST(0),ST(3)
		/*0xFC*/	{ NULL, }, //FDIVR ST(0),ST(4)
		/*0xFD*/	{ NULL, }, //FDIVR ST(0),ST(5)
		/*0xFE*/	{ NULL, }, //FDIVR ST(0),ST(6)
		/*0xFF*/	{ NULL, }, //FDIVR ST(0),ST(7)
	},
};

FPModRMTable FPExtD9 =
{
	{
		/*0x000*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FLD (single-real)
		/*0x001*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
		/*0x010*/	{ DaSpModRM<SpMemoryWrite>, }, //FST (single-real)
		/*0x011*/	{ DaSpModRM<SpMemoryWrite>, }, //FSTP (single-real)
		/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FLDENV (14/28 bytes)
		/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FLDCW (2 bytes)
		/*0x110*/	{ DaSpModRM<SpMemoryWrite>, }, //FSTENV (14/28 bytes)
		/*0x111*/	{ DaSpModRM<SpMemoryWrite>, }, //FSTCW (2 bytes)
	},
	{
		/*0xC0*/	{ NULL, }, //FLD ST(0),ST(0)
		/*0xC1*/	{ NULL, }, //FLD ST(0),ST(1)
		/*0xC2*/	{ NULL, }, //FLD ST(0),ST(2)
		/*0xC3*/	{ NULL, }, //FLD ST(0),ST(3)
		/*0xC4*/	{ NULL, }, //FLD ST(0),ST(4)
		/*0xC5*/	{ NULL, }, //FLD ST(0),ST(5)
		/*0xC6*/	{ NULL, }, //FLD ST(0),ST(6)
		/*0xC7*/	{ NULL, }, //FLD ST(0),ST(7)
		/*0xC8*/	{ NULL, }, //FXCH ST(0),ST(0)
		/*0xC9*/	{ NULL, }, //FXCH ST(0),ST(1)
		/*0xCA*/	{ NULL, }, //FXCH ST(0),ST(2)
		/*0xCB*/	{ NULL, }, //FXCH ST(0),ST(3)
		/*0xCC*/	{ NULL, }, //FXCH ST(0),ST(4)
		/*0xCD*/	{ NULL, }, //FXCH ST(0),ST(5)
		/*0xCE*/	{ NULL, }, //FXCH ST(0),ST(6)
		/*0xCF*/	{ NULL, }, //FXCH ST(0),ST(7)
		/*0xD0*/	{ NULL, }, //FNOP
		/*0xD1*/	{ DaSpUndefinedInstruction, },
		/*0xD2*/	{ DaSpUndefinedInstruction, },
		/*0xD3*/	{ DaSpUndefinedInstruction, },
		/*0xD4*/	{ DaSpUndefinedInstruction, },
		/*0xD5*/	{ DaSpUndefinedInstruction, },
		/*0xD6*/	{ DaSpUndefinedInstruction, },
		/*0xD7*/	{ DaSpUndefinedInstruction, },
		/*0xD8*/	{ DaSpUndefinedInstruction, },
		/*0xD9*/	{ DaSpUndefinedInstruction, },
		/*0xDA*/	{ DaSpUndefinedInstruction, },
		/*0xDB*/	{ DaSpUndefinedInstruction, },
		/*0xDC*/	{ DaSpUndefinedInstruction, },
		/*0xDD*/	{ DaSpUndefinedInstruction, },
		/*0xDE*/	{ DaSpUndefinedInstruction, },
		/*0xDF*/	{ DaSpUndefinedInstruction, },
		/*0xE0*/	{ NULL, }, //FCHS
		/*0xE1*/	{ NULL, }, //FABS
		/*0xE2*/	{ DaSpUndefinedInstruction, },
		/*0xE3*/	{ DaSpUndefinedInstruction, },
		/*0xE4*/	{ NULL, }, //FTST
		/*0xE5*/	{ NULL, }, //FXAM
		/*0xE6*/	{ DaSpUndefinedInstruction, },
		/*0xE7*/	{ DaSpUndefinedInstruction, },
		/*0xE8*/	{ NULL, }, //FLD1
		/*0xE9*/	{ NULL, }, //FLDL2T
		/*0xEA*/	{ NULL, }, //FLDL2E
		/*0xEB*/	{ NULL, }, //FLDPI
		/*0xEC*/	{ NULL, }, //FLDLG2
		/*0xED*/	{ NULL, }, //FLDLN2
		/*0xEE*/	{ NULL, }, //FLDZ
		/*0xEF*/	{ DaSpUndefinedInstruction, },
		/*0xF0*/	{ NULL, }, //F2XM1
		/*0xF1*/	{ NULL, }, //FYL2X
		/*0xF2*/	{ NULL, }, //FPTAN
		/*0xF3*/	{ NULL, }, //FPATAN
		/*0xF4*/	{ NULL, }, //FXTRACT
		/*0xF5*/	{ NULL, }, //FPREM1
		/*0xF6*/	{ NULL, }, //FDECSTP
		/*0xF7*/	{ NULL, }, //FINCSTP
		/*0xF8*/	{ NULL, }, //FPREM
		/*0xF9*/	{ NULL, }, //FYL2XP1
		/*0xFA*/	{ NULL, }, //FSQRT
		/*0xFB*/	{ NULL, }, //FSINCOS
		/*0xFC*/	{ NULL, }, //FRNDINT
		/*0xFD*/	{ NULL, }, //FSCALE
		/*0xFE*/	{ NULL, }, //FSIN
		/*0xFF*/	{ NULL, }, //FCOS
	},
};

FPModRMTable FPExtDA =
{
	{
		/*0x000*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FIADD (dword-integer)
		/*0x001*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FIMUL (dword-integer)
		/*0x010*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FICOM (dword-integer)
		/*0x011*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FICOMP (dword-integer)
		/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FISUB (dword-integer)
		/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FISUBR (dword-integer)
		/*0x110*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FIDIV (dword-integer)
		/*0x111*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FIDIVR (dword-integer)
	},
	{
		/*0xC0*/	{ NULL, }, //FCMOVB ST(0),ST(0)
		/*0xC1*/	{ NULL, }, //FCMOVB ST(0),ST(1)
		/*0xC2*/	{ NULL, }, //FCMOVB ST(0),ST(2)
		/*0xC3*/	{ NULL, }, //FCMOVB ST(0),ST(3)
		/*0xC4*/	{ NULL, }, //FCMOVB ST(0),ST(4)
		/*0xC5*/	{ NULL, }, //FCMOVB ST(0),ST(5)
		/*0xC6*/	{ NULL, }, //FCMOVB ST(0),ST(6)
		/*0xC7*/	{ NULL, }, //FCMOVB ST(0),ST(7)
		/*0xC8*/	{ NULL, }, //FCMOVE ST(0),ST(0)
		/*0xC9*/	{ NULL, }, //FCMOVE ST(0),ST(1)
		/*0xCA*/	{ NULL, }, //FCMOVE ST(0),ST(2)
		/*0xCB*/	{ NULL, }, //FCMOVE ST(0),ST(3)
		/*0xCC*/	{ NULL, }, //FCMOVE ST(0),ST(4)
		/*0xCD*/	{ NULL, }, //FCMOVE ST(0),ST(5)
		/*0xCE*/	{ NULL, }, //FCMOVE ST(0),ST(6)
		/*0xCF*/	{ NULL, }, //FCMOVE ST(0),ST(7)
		/*0xD0*/	{ NULL, }, //FCMOVBE ST(0),ST(0)
		/*0xD1*/	{ NULL, }, //FCMOVBE ST(0),ST(1)
		/*0xD2*/	{ NULL, }, //FCMOVBE ST(0),ST(2)
		/*0xD3*/	{ NULL, }, //FCMOVBE ST(0),ST(3)
		/*0xD4*/	{ NULL, }, //FCMOVBE ST(0),ST(4)
		/*0xD5*/	{ NULL, }, //FCMOVBE ST(0),ST(5)
		/*0xD6*/	{ NULL, }, //FCMOVBE ST(0),ST(6)
		/*0xD7*/	{ NULL, }, //FCMOVBE ST(0),ST(7)
		/*0xD8*/	{ NULL, }, //FCMOVU ST(0),ST(0)
		/*0xD9*/	{ NULL, }, //FCMOVU ST(0),ST(1)
		/*0xDA*/	{ NULL, }, //FCMOVU ST(0),ST(2)
		/*0xDB*/	{ NULL, }, //FCMOVU ST(0),ST(3)
		/*0xDC*/	{ NULL, }, //FCMOVU ST(0),ST(4)
		/*0xDD*/	{ NULL, }, //FCMOVU ST(0),ST(5)
		/*0xDE*/	{ NULL, }, //FCMOVU ST(0),ST(6)
		/*0xDF*/	{ NULL, }, //FCMOVU ST(0),ST(7)
		/*0xE0*/	{ DaSpUndefinedInstruction, },
		/*0xE1*/	{ DaSpUndefinedInstruction, },
		/*0xE2*/	{ DaSpUndefinedInstruction, },
		/*0xE3*/	{ DaSpUndefinedInstruction, },
		/*0xE4*/	{ DaSpUndefinedInstruction, },
		/*0xE5*/	{ DaSpUndefinedInstruction, },
		/*0xE6*/	{ DaSpUndefinedInstruction, },
		/*0xE7*/	{ DaSpUndefinedInstruction, },
		/*0xE8*/	{ DaSpUndefinedInstruction, },
		/*0xE9*/	{ DaSpUndefinedInstruction, },
		/*0xEA*/	{ DaSpUndefinedInstruction, },
		/*0xEB*/	{ DaSpUndefinedInstruction, },
		/*0xEC*/	{ DaSpUndefinedInstruction, },
		/*0xED*/	{ DaSpUndefinedInstruction, },
		/*0xEE*/	{ DaSpUndefinedInstruction, },
		/*0xEF*/	{ DaSpUndefinedInstruction, },
		/*0xF0*/	{ DaSpUndefinedInstruction, },
		/*0xF1*/	{ DaSpUndefinedInstruction, },
		/*0xF2*/	{ DaSpUndefinedInstruction, },
		/*0xF3*/	{ DaSpUndefinedInstruction, },
		/*0xF4*/	{ DaSpUndefinedInstruction, },
		/*0xF5*/	{ DaSpUndefinedInstruction, },
		/*0xF6*/	{ DaSpUndefinedInstruction, },
		/*0xF7*/	{ DaSpUndefinedInstruction, },
		/*0xF8*/	{ DaSpUndefinedInstruction, },
		/*0xF9*/	{ DaSpUndefinedInstruction, },
		/*0xFA*/	{ DaSpUndefinedInstruction, },
		/*0xFB*/	{ DaSpUndefinedInstruction, },
		/*0xFC*/	{ DaSpUndefinedInstruction, },
		/*0xFD*/	{ DaSpUndefinedInstruction, },
		/*0xFE*/	{ DaSpUndefinedInstruction, },
		/*0xFF*/	{ DaSpUndefinedInstruction, },
	},
};

FPModRMTable FPExtDB =
{
	{
		/*0x000*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FILD (dword-integer)
		/*0x001*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
		/*0x010*/	{ DaSpModRM<SpMemoryWrite>, }, //FIST (dword-integer)
		/*0x011*/	{ DaSpModRM<SpMemoryWrite>, }, //FISTP (dword-integer)
		/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
		/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FLD (extended-real)
		/*0x110*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
		/*0x111*/	{ DaSpModRM<SpMemoryWrite>, }, //FSTP (extended-real)
	},
	{
		/*0xC0*/	{ NULL, }, //FCMOVNB ST(0),ST(0)
		/*0xC1*/	{ NULL, }, //FCMOVNB ST(0),ST(1)
		/*0xC2*/	{ NULL, }, //FCMOVNB ST(0),ST(2)
		/*0xC3*/	{ NULL, }, //FCMOVNB ST(0),ST(3)
		/*0xC4*/	{ NULL, }, //FCMOVNB ST(0),ST(4)
		/*0xC5*/	{ NULL, }, //FCMOVNB ST(0),ST(5)
		/*0xC6*/	{ NULL, }, //FCMOVNB ST(0),ST(6)
		/*0xC7*/	{ NULL, }, //FCMOVNB ST(0),ST(7)
		/*0xC8*/	{ NULL, }, //FCMOVNE ST(0),ST(0)
		/*0xC9*/	{ NULL, }, //FCMOVNE ST(0),ST(1)
		/*0xCA*/	{ NULL, }, //FCMOVNE ST(0),ST(2)
		/*0xCB*/	{ NULL, }, //FCMOVNE ST(0),ST(3)
		/*0xCC*/	{ NULL, }, //FCMOVNE ST(0),ST(4)
		/*0xCD*/	{ NULL, }, //FCMOVNE ST(0),ST(5)
		/*0xCE*/	{ NULL, }, //FCMOVNE ST(0),ST(6)
		/*0xCF*/	{ NULL, }, //FCMOVNE ST(0),ST(7)
		/*0xD0*/	{ NULL, }, //FCMOVNBE ST(0),ST(0)
		/*0xD1*/	{ NULL, }, //FCMOVNBE ST(0),ST(1)
		/*0xD2*/	{ NULL, }, //FCMOVNBE ST(0),ST(2)
		/*0xD3*/	{ NULL, }, //FCMOVNBE ST(0),ST(3)
		/*0xD4*/	{ NULL, }, //FCMOVNBE ST(0),ST(4)
		/*0xD5*/	{ NULL, }, //FCMOVNBE ST(0),ST(5)
		/*0xD6*/	{ NULL, }, //FCMOVNBE ST(0),ST(6)
		/*0xD7*/	{ NULL, }, //FCMOVNBE ST(0),ST(7)
		/*0xD8*/	{ NULL, }, //FCMOVNU ST(0),ST(0)
		/*0xD9*/	{ NULL, }, //FCMOVNU ST(0),ST(1)
		/*0xDA*/	{ NULL, }, //FCMOVNU ST(0),ST(2)
		/*0xDB*/	{ NULL, }, //FCMOVNU ST(0),ST(3)
		/*0xDC*/	{ NULL, }, //FCMOVNU ST(0),ST(4)
		/*0xDD*/	{ NULL, }, //FCMOVNU ST(0),ST(5)
		/*0xDE*/	{ NULL, }, //FCMOVNU ST(0),ST(6)
		/*0xDF*/	{ NULL, }, //FCMOVNU ST(0),ST(7)
		/*0xE0*/	{ DaSpUndefinedInstruction, },
		/*0xE1*/	{ DaSpUndefinedInstruction, },
		/*0xE2*/	{ NULL, }, //FCLEX
		/*0xE3*/	{ NULL, }, //FINIT
		/*0xE4*/	{ DaSpUndefinedInstruction, },
		/*0xE5*/	{ DaSpUndefinedInstruction, },
		/*0xE6*/	{ DaSpUndefinedInstruction, },
		/*0xE7*/	{ DaSpUndefinedInstruction, },
		/*0xE8*/	{ NULL, }, //FUCOMI ST(0),ST(0)
		/*0xE9*/	{ NULL, }, //FUCOMI ST(0),ST(1)
		/*0xEA*/	{ NULL, }, //FUCOMI ST(0),ST(2)
		/*0xEB*/	{ NULL, }, //FUCOMI ST(0),ST(3)
		/*0xEC*/	{ NULL, }, //FUCOMI ST(0),ST(4)
		/*0xED*/	{ NULL, }, //FUCOMI ST(0),ST(5)
		/*0xEE*/	{ NULL, }, //FUCOMI ST(0),ST(6)
		/*0xEF*/	{ NULL, }, //FUCOMI ST(0),ST(7)
		/*0xF0*/	{ NULL, }, //FCOMI ST(0),ST(0)
		/*0xF1*/	{ NULL, }, //FCOMI ST(0),ST(1)
		/*0xF2*/	{ NULL, }, //FCOMI ST(0),ST(2)
		/*0xF3*/	{ NULL, }, //FCOMI ST(0),ST(3)
		/*0xF4*/	{ NULL, }, //FCOMI ST(0),ST(4)
		/*0xF5*/	{ NULL, }, //FCOMI ST(0),ST(5)
		/*0xF6*/	{ NULL, }, //FCOMI ST(0),ST(6)
		/*0xF7*/	{ NULL, }, //FCOMI ST(0),ST(7)
		/*0xF8*/	{ DaSpUndefinedInstruction, },
		/*0xF9*/	{ DaSpUndefinedInstruction, },
		/*0xFA*/	{ DaSpUndefinedInstruction, },
		/*0xFB*/	{ DaSpUndefinedInstruction, },
		/*0xFC*/	{ DaSpUndefinedInstruction, },
		/*0xFD*/	{ DaSpUndefinedInstruction, },
		/*0xFE*/	{ DaSpUndefinedInstruction, },
		/*0xFF*/	{ DaSpUndefinedInstruction, },
	},
};

FPModRMTable FPExtDC =
{
	{
		/*0x000*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FADD (double-real)
		/*0x001*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FMUL (double-real)
		/*0x010*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FCOM (double-real)
		/*0x011*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FCOMP (double-real)
		/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FSUB (double-real)
		/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FSUBR (double-real)
		/*0x110*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FDIV (double-real)
		/*0x111*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FDIVR (double-real)
	},
	{
		/*0xC0*/	{ NULL, }, //FADD ST(0),ST(0)
		/*0xC1*/	{ NULL, }, //FADD ST(1),ST(0)
		/*0xC2*/	{ NULL, }, //FADD ST(2),ST(0)
		/*0xC3*/	{ NULL, }, //FADD ST(3),ST(0)
		/*0xC4*/	{ NULL, }, //FADD ST(4),ST(0)
		/*0xC5*/	{ NULL, }, //FADD ST(5),ST(0)
		/*0xC6*/	{ NULL, }, //FADD ST(6),ST(0)
		/*0xC7*/	{ NULL, }, //FADD ST(7),ST(0)
		/*0xC8*/	{ NULL, }, //FMUL ST(0),ST(0)
		/*0xC9*/	{ NULL, }, //FMUL ST(1),ST(0)
		/*0xCA*/	{ NULL, }, //FMUL ST(2),ST(0)
		/*0xCB*/	{ NULL, }, //FMUL ST(3),ST(0)
		/*0xCC*/	{ NULL, }, //FMUL ST(4),ST(0)
		/*0xCD*/	{ NULL, }, //FMUL ST(5),ST(0)
		/*0xCE*/	{ NULL, }, //FMUL ST(6),ST(0)
		/*0xCF*/	{ NULL, }, //FMUL ST(7),ST(0)
		/*0xD0*/	{ DaSpUndefinedInstruction, },
		/*0xD1*/	{ DaSpUndefinedInstruction, },
		/*0xD2*/	{ DaSpUndefinedInstruction, },
		/*0xD3*/	{ DaSpUndefinedInstruction, },
		/*0xD4*/	{ DaSpUndefinedInstruction, },
		/*0xD5*/	{ DaSpUndefinedInstruction, },
		/*0xD6*/	{ DaSpUndefinedInstruction, },
		/*0xD7*/	{ DaSpUndefinedInstruction, },
		/*0xD8*/	{ DaSpUndefinedInstruction, },
		/*0xD9*/	{ DaSpUndefinedInstruction, },
		/*0xDA*/	{ DaSpUndefinedInstruction, },
		/*0xDB*/	{ DaSpUndefinedInstruction, },
		/*0xDC*/	{ DaSpUndefinedInstruction, },
		/*0xDD*/	{ DaSpUndefinedInstruction, },
		/*0xDE*/	{ DaSpUndefinedInstruction, },
		/*0xDF*/	{ DaSpUndefinedInstruction, },
		/*0xE0*/	{ NULL, }, //FSUBR ST(0),ST(0)
		/*0xE1*/	{ NULL, }, //FSUBR ST(1),ST(0)
		/*0xE2*/	{ NULL, }, //FSUBR ST(2),ST(0)
		/*0xE3*/	{ NULL, }, //FSUBR ST(3),ST(0)
		/*0xE4*/	{ NULL, }, //FSUBR ST(4),ST(0)
		/*0xE5*/	{ NULL, }, //FSUBR ST(5),ST(0)
		/*0xE6*/	{ NULL, }, //FSUBR ST(6),ST(0)
		/*0xE7*/	{ NULL, }, //FSUBR ST(7),ST(0)
		/*0xE8*/	{ NULL, }, //FSUB ST(0),ST(0)
		/*0xE9*/	{ NULL, }, //FSUB ST(1),ST(0)
		/*0xEA*/	{ NULL, }, //FSUB ST(2),ST(0)
		/*0xEB*/	{ NULL, }, //FSUB ST(3),ST(0)
		/*0xEC*/	{ NULL, }, //FSUB ST(4),ST(0)
		/*0xED*/	{ NULL, }, //FSUB ST(5),ST(0)
		/*0xEE*/	{ NULL, }, //FSUB ST(6),ST(0)
		/*0xEF*/	{ NULL, }, //FSUB ST(7),ST(0)
		/*0xF0*/	{ NULL, }, //FDIVR ST(0),ST(0)
		/*0xF1*/	{ NULL, }, //FDIVR ST(1),ST(0)
		/*0xF2*/	{ NULL, }, //FDIVR ST(2),ST(0)
		/*0xF3*/	{ NULL, }, //FDIVR ST(3),ST(0)
		/*0xF4*/	{ NULL, }, //FDIVR ST(4),ST(0)
		/*0xF5*/	{ NULL, }, //FDIVR ST(5),ST(0)
		/*0xF6*/	{ NULL, }, //FDIVR ST(6),ST(0)
		/*0xF7*/	{ NULL, }, //FDIVR ST(7),ST(0)
		/*0xF8*/	{ NULL, }, //FDIV ST(0),ST(0)
		/*0xF9*/	{ NULL, }, //FDIV ST(1),ST(0)
		/*0xFA*/	{ NULL, }, //FDIV ST(2),ST(0)
		/*0xFB*/	{ NULL, }, //FDIV ST(3),ST(0)
		/*0xFC*/	{ NULL, }, //FDIV ST(4),ST(0)
		/*0xFD*/	{ NULL, }, //FDIV ST(5),ST(0)
		/*0xFE*/	{ NULL, }, //FDIV ST(6),ST(0)
		/*0xFF*/	{ NULL, }, //FDIV ST(7),ST(0)
	},
};

FPModRMTable FPExtDD =
{
	{
		/*0x000*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FLD (double-real)
		/*0x001*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
		/*0x010*/	{ DaSpModRM<SpMemoryWrite>, }, //FST (double-real)
		/*0x011*/	{ DaSpModRM<SpMemoryWrite>, }, //FSTP (double-real)
		/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FRSTOR (98/108 bytes)
		/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
		/*0x110*/	{ DaSpModRM<SpMemoryWrite>, }, //FSAVE (98/108 bytes)
		/*0x111*/	{ DaSpModRM<SpMemoryWrite>, }, //FSTSW (2 bytes)
	},
	{
		/*0xC0*/	{ NULL, }, //FFREE ST(0)
		/*0xC1*/	{ NULL, }, //FFREE ST(1)
		/*0xC2*/	{ NULL, }, //FFREE ST(2)
		/*0xC3*/	{ NULL, }, //FFREE ST(3)
		/*0xC4*/	{ NULL, }, //FFREE ST(4)
		/*0xC5*/	{ NULL, }, //FFREE ST(5)
		/*0xC6*/	{ NULL, }, //FFREE ST(6)
		/*0xC7*/	{ NULL, }, //FFREE ST(7)
		/*0xC8*/	{ DaSpUndefinedInstruction, },
		/*0xC9*/	{ DaSpUndefinedInstruction, },
		/*0xCA*/	{ DaSpUndefinedInstruction, },
		/*0xCB*/	{ DaSpUndefinedInstruction, },
		/*0xCC*/	{ DaSpUndefinedInstruction, },
		/*0xCD*/	{ DaSpUndefinedInstruction, },
		/*0xCE*/	{ DaSpUndefinedInstruction, },
		/*0xCF*/	{ DaSpUndefinedInstruction, },
		/*0xD0*/	{ NULL, }, //FST ST(0)
		/*0xD1*/	{ NULL, }, //FST ST(1)
		/*0xD2*/	{ NULL, }, //FST ST(2)
		/*0xD3*/	{ NULL, }, //FST ST(3)
		/*0xD4*/	{ NULL, }, //FST ST(4)
		/*0xD5*/	{ NULL, }, //FST ST(5)
		/*0xD6*/	{ NULL, }, //FST ST(6)
		/*0xD7*/	{ NULL, }, //FST ST(7)
		/*0xD8*/	{ NULL, }, //FSTP ST(0)
		/*0xD9*/	{ NULL, }, //FSTP ST(1)
		/*0xDA*/	{ NULL, }, //FSTP ST(2)
		/*0xDB*/	{ NULL, }, //FSTP ST(3)
		/*0xDC*/	{ NULL, }, //FSTP ST(4)
		/*0xDD*/	{ NULL, }, //FSTP ST(5)
		/*0xDE*/	{ NULL, }, //FSTP ST(6)
		/*0xDF*/	{ NULL, }, //FSTP ST(7)
		/*0xE0*/	{ NULL, }, //FUCOM ST(0),ST(0)
		/*0xE1*/	{ NULL, }, //FUCOM ST(1),ST(0)
		/*0xE2*/	{ NULL, }, //FUCOM ST(2),ST(0)
		/*0xE3*/	{ NULL, }, //FUCOM ST(3),ST(0)
		/*0xE4*/	{ NULL, }, //FUCOM ST(4),ST(0)
		/*0xE5*/	{ NULL, }, //FUCOM ST(5),ST(0)
		/*0xE6*/	{ NULL, }, //FUCOM ST(6),ST(0)
		/*0xE7*/	{ NULL, }, //FUCOM ST(7),ST(0)
		/*0xE8*/	{ NULL, }, //FUCOMP ST(0)
		/*0xE9*/	{ NULL, }, //FUCOMP ST(1)
		/*0xEA*/	{ NULL, }, //FUCOMP ST(2)
		/*0xEB*/	{ NULL, }, //FUCOMP ST(3)
		/*0xEC*/	{ NULL, }, //FUCOMP ST(4)
		/*0xED*/	{ NULL, }, //FUCOMP ST(5)
		/*0xEE*/	{ NULL, }, //FUCOMP ST(6)
		/*0xEF*/	{ NULL, }, //FUCOMP ST(7)
		/*0xF0*/	{ DaSpUndefinedInstruction, },
		/*0xF1*/	{ DaSpUndefinedInstruction, },
		/*0xF2*/	{ DaSpUndefinedInstruction, },
		/*0xF3*/	{ DaSpUndefinedInstruction, },
		/*0xF4*/	{ DaSpUndefinedInstruction, },
		/*0xF5*/	{ DaSpUndefinedInstruction, },
		/*0xF6*/	{ DaSpUndefinedInstruction, },
		/*0xF7*/	{ DaSpUndefinedInstruction, },
		/*0xF8*/	{ DaSpUndefinedInstruction, },
		/*0xF9*/	{ DaSpUndefinedInstruction, },
		/*0xFA*/	{ DaSpUndefinedInstruction, },
		/*0xFB*/	{ DaSpUndefinedInstruction, },
		/*0xFC*/	{ DaSpUndefinedInstruction, },
		/*0xFD*/	{ DaSpUndefinedInstruction, },
		/*0xFE*/	{ DaSpUndefinedInstruction, },
		/*0xFF*/	{ DaSpUndefinedInstruction, },
	},
};

FPModRMTable FPExtDE =
{
	{
		/*0x000*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FIADD (word-integer)
		/*0x001*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FIMUL (word-integer)
		/*0x010*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FICOM (word-integer)
		/*0x011*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FICOMP (word-integer)
		/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FISUB (word-integer)
		/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FISUBR (word-integer)
		/*0x110*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FIDIV (word-integer)
		/*0x111*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FIDIVR (word-integer)
	},
	{
		/*0xC0*/	{ NULL, }, //FADDP ST(0),ST(0)
		/*0xC1*/	{ NULL, }, //FADDP ST(1),ST(0)
		/*0xC2*/	{ NULL, }, //FADDP ST(2),ST(0)
		/*0xC3*/	{ NULL, }, //FADDP ST(3),ST(0)
		/*0xC4*/	{ NULL, }, //FADDP ST(4),ST(0)
		/*0xC5*/	{ NULL, }, //FADDP ST(5),ST(0)
		/*0xC6*/	{ NULL, }, //FADDP ST(6),ST(0)
		/*0xC7*/	{ NULL, }, //FADDP ST(7),ST(0)
		/*0xC8*/	{ NULL, }, //FMULP ST(0),ST(0)
		/*0xC9*/	{ NULL, }, //FMULP ST(1),ST(0)
		/*0xCA*/	{ NULL, }, //FMULP ST(2),ST(0)
		/*0xCB*/	{ NULL, }, //FMULP ST(3),ST(0)
		/*0xCC*/	{ NULL, }, //FMULP ST(4),ST(0)
		/*0xCD*/	{ NULL, }, //FMULP ST(5),ST(0)
		/*0xCE*/	{ NULL, }, //FMULP ST(6),ST(0)
		/*0xCF*/	{ NULL, }, //FMULP ST(7),ST(0)
		/*0xD0*/	{ DaSpUndefinedInstruction, },
		/*0xD1*/	{ DaSpUndefinedInstruction, },
		/*0xD2*/	{ DaSpUndefinedInstruction, },
		/*0xD3*/	{ DaSpUndefinedInstruction, },
		/*0xD4*/	{ DaSpUndefinedInstruction, },
		/*0xD5*/	{ DaSpUndefinedInstruction, },
		/*0xD6*/	{ DaSpUndefinedInstruction, },
		/*0xD7*/	{ DaSpUndefinedInstruction, },
		/*0xD8*/	{ DaSpUndefinedInstruction, },
		/*0xD9*/	{ NULL, }, //FCOMPP
		/*0xDA*/	{ DaSpUndefinedInstruction, },
		/*0xDB*/	{ DaSpUndefinedInstruction, },
		/*0xDC*/	{ DaSpUndefinedInstruction, },
		/*0xDD*/	{ DaSpUndefinedInstruction, },
		/*0xDE*/	{ DaSpUndefinedInstruction, },
		/*0xDF*/	{ DaSpUndefinedInstruction, },
		/*0xE0*/	{ NULL, }, //FSUBRP ST(0),ST(0)
		/*0xE1*/	{ NULL, }, //FSUBRP ST(1),ST(0)
		/*0xE2*/	{ NULL, }, //FSUBRP ST(2),ST(0)
		/*0xE3*/	{ NULL, }, //FSUBRP ST(3),ST(0)
		/*0xE4*/	{ NULL, }, //FSUBRP ST(4),ST(0)
		/*0xE5*/	{ NULL, }, //FSUBRP ST(5),ST(0)
		/*0xE6*/	{ NULL, }, //FSUBRP ST(6),ST(0)
		/*0xE7*/	{ NULL, }, //FSUBRP ST(7),ST(0)
		/*0xE8*/	{ NULL, }, //FSUBP ST(0),ST(0)
		/*0xE9*/	{ NULL, }, //FSUBP ST(1),ST(0)
		/*0xEA*/	{ NULL, }, //FSUBP ST(2),ST(0)
		/*0xEB*/	{ NULL, }, //FSUBP ST(3),ST(0)
		/*0xEC*/	{ NULL, }, //FSUBP ST(4),ST(0)
		/*0xED*/	{ NULL, }, //FSUBP ST(5),ST(0)
		/*0xEE*/	{ NULL, }, //FSUBP ST(6),ST(0)
		/*0xEF*/	{ NULL, }, //FSUBP ST(7),ST(0)
		/*0xF0*/	{ NULL, }, //FDIVRP ST(0),ST(0)
		/*0xF1*/	{ NULL, }, //FDIVRP ST(1),ST(0)
		/*0xF2*/	{ NULL, }, //FDIVRP ST(2),ST(0)
		/*0xF3*/	{ NULL, }, //FDIVRP ST(3),ST(0)
		/*0xF4*/	{ NULL, }, //FDIVRP ST(4),ST(0)
		/*0xF5*/	{ NULL, }, //FDIVRP ST(5),ST(0)
		/*0xF6*/	{ NULL, }, //FDIVRP ST(6),ST(0)
		/*0xF7*/	{ NULL, }, //FDIVRP ST(7),ST(0)
		/*0xF8*/	{ NULL, }, //FDIVP ST(0),ST(0)
		/*0xF9*/	{ NULL, }, //FDIVP ST(1),ST(0)
		/*0xFA*/	{ NULL, }, //FDIVP ST(2),ST(0)
		/*0xFB*/	{ NULL, }, //FDIVP ST(3),ST(0)
		/*0xFC*/	{ NULL, }, //FDIVP ST(4),ST(0)
		/*0xFD*/	{ NULL, }, //FDIVP ST(5),ST(0)
		/*0xFE*/	{ NULL, }, //FDIVP ST(6),ST(0)
		/*0xFF*/	{ NULL, }, //FDIVP ST(7),ST(0)
	},
};

FPModRMTable FPExtDF =
{
	{
		/*0x000*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FILD (word-integer)
		/*0x001*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpUndefinedInstruction, },
		/*0x010*/	{ DaSpModRM<SpMemoryWrite>, }, //FIST (word-integer)
		/*0x011*/	{ DaSpModRM<SpMemoryWrite>, }, //FISTP (word-integer)
		/*0x100*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FBLD (packed-BCD)
		/*0x101*/	{ DaSpModRM<SpNoMemoryWrite>, }, //FILD (qword-integer)
		/*0x110*/	{ DaSpModRM<SpMemoryWrite>, }, //FBSTP (packed-BCD)
		/*0x111*/	{ DaSpModRM<SpMemoryWrite>, }, //FISTP (qword-integer)
	},
	{
		/*0xC0*/	{ DaSpUndefinedInstruction, },
		/*0xC1*/	{ DaSpUndefinedInstruction, },
		/*0xC2*/	{ DaSpUndefinedInstruction, },
		/*0xC3*/	{ DaSpUndefinedInstruction, },
		/*0xC4*/	{ DaSpUndefinedInstruction, },
		/*0xC5*/	{ DaSpUndefinedInstruction, },
		/*0xC6*/	{ DaSpUndefinedInstruction, },
		/*0xC7*/	{ DaSpUndefinedInstruction, },
		/*0xC8*/	{ DaSpUndefinedInstruction, },
		/*0xC9*/	{ DaSpUndefinedInstruction, },
		/*0xCA*/	{ DaSpUndefinedInstruction, },
		/*0xCB*/	{ DaSpUndefinedInstruction, },
		/*0xCC*/	{ DaSpUndefinedInstruction, },
		/*0xCD*/	{ DaSpUndefinedInstruction, },
		/*0xCE*/	{ DaSpUndefinedInstruction, },
		/*0xCF*/	{ DaSpUndefinedInstruction, },
		/*0xD0*/	{ DaSpUndefinedInstruction, },
		/*0xD1*/	{ DaSpUndefinedInstruction, },
		/*0xD2*/	{ DaSpUndefinedInstruction, },
		/*0xD3*/	{ DaSpUndefinedInstruction, },
		/*0xD4*/	{ DaSpUndefinedInstruction, },
		/*0xD5*/	{ DaSpUndefinedInstruction, },
		/*0xD6*/	{ DaSpUndefinedInstruction, },
		/*0xD7*/	{ DaSpUndefinedInstruction, },
		/*0xD8*/	{ DaSpUndefinedInstruction, },
		/*0xD9*/	{ DaSpUndefinedInstruction, },
		/*0xDA*/	{ DaSpUndefinedInstruction, },
		/*0xDB*/	{ DaSpUndefinedInstruction, },
		/*0xDC*/	{ DaSpUndefinedInstruction, },
		/*0xDD*/	{ DaSpUndefinedInstruction, },
		/*0xDE*/	{ DaSpUndefinedInstruction, },
		/*0xDF*/	{ DaSpUndefinedInstruction, },
		/*0xE0*/	{ NULL, }, //FSTSW AX
		/*0xE1*/	{ DaSpUndefinedInstruction, },
		/*0xE2*/	{ DaSpUndefinedInstruction, },
		/*0xE3*/	{ DaSpUndefinedInstruction, },
		/*0xE4*/	{ DaSpUndefinedInstruction, },
		/*0xE5*/	{ DaSpUndefinedInstruction, },
		/*0xE6*/	{ DaSpUndefinedInstruction, },
		/*0xE7*/	{ DaSpUndefinedInstruction, },
		/*0xE8*/	{ DaSpUndefinedInstruction, },
		/*0xE9*/	{ DaSpUndefinedInstruction, },
		/*0xEA*/	{ DaSpUndefinedInstruction, },
		/*0xEB*/	{ DaSpUndefinedInstruction, },
		/*0xEC*/	{ DaSpUndefinedInstruction, },
		/*0xED*/	{ DaSpUndefinedInstruction, },
		/*0xEE*/	{ DaSpUndefinedInstruction, },
		/*0xEF*/	{ DaSpUndefinedInstruction, },
		/*0xF0*/	{ NULL, }, //FCOMIP ST(0),ST(0)
		/*0xF1*/	{ NULL, }, //FCOMIP ST(0),ST(1)
		/*0xF2*/	{ NULL, }, //FCOMIP ST(0),ST(2)
		/*0xF3*/	{ NULL, }, //FCOMIP ST(0),ST(3)
		/*0xF4*/	{ NULL, }, //FCOMIP ST(0),ST(4)
		/*0xF5*/	{ NULL, }, //FCOMIP ST(0),ST(5)
		/*0xF6*/	{ NULL, }, //FCOMIP ST(0),ST(6)
		/*0xF7*/	{ NULL, }, //FCOMIP ST(0),ST(7)
		/*0xF8*/	{ NULL, }, //FUCOMIP ST(0),ST(0)
		/*0xF9*/	{ NULL, }, //FUCOMIP ST(0),ST(1)
		/*0xFA*/	{ NULL, }, //FUCOMIP ST(0),ST(2)
		/*0xFB*/	{ NULL, }, //FUCOMIP ST(0),ST(3)
		/*0xFC*/	{ NULL, }, //FUCOMIP ST(0),ST(4)
		/*0xFD*/	{ NULL, }, //FUCOMIP ST(0),ST(5)
		/*0xFE*/	{ NULL, }, //FUCOMIP ST(0),ST(6)
		/*0xFF*/	{ NULL, }, //FUCOMIP ST(0),ST(7)
	},
};


static CITable MainOpCode =
{
	/*0x00*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //ADD (Eb,Gb)
	/*0x01*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //ADD (Ev,Gv)
	/*0x02*/	{ DaSpModRM<SpNoMemoryWrite>, }, //ADD (Gb,Eb)
	/*0x03*/	{ DaSpModRM<SpNoMemoryWrite>, }, //ADD (Gv,Ev)
	/*0x04*/	{ DaSpImmediateOp<DaByte>, }, //ADD (AL,Ib)
	/*0x05*/	{ DaSpImmediateOp<SpModeDependent>, }, //ADD (eAX,Iv)
	/*0x06*/	{ NULL, }, //PUSH ES
	/*0x07*/	{ NULL, }, //POP ES
	/*0x08*/	{ DaSpModRM<SpMemoryWrite>, }, //OR (Eb,Gb)
	/*0x09*/	{ DaSpModRM<SpMemoryWrite>, }, //OR (Ev,Gv)
	/*0x0A*/	{ DaSpModRM<SpNoMemoryWrite>, }, //OR (Gb,Eb)
	/*0x0B*/	{ DaSpModRM<SpNoMemoryWrite>, }, //OR (Gv,Ev)
	/*0x0C*/	{ DaSpImmediateOp<DaByte>, }, //OR (AL,Ib)
	/*0x0D*/	{ DaSpImmediateOp<SpModeDependent>, }, //OR (eAX,Iv)
	/*0x0E*/	{ NULL, }, //PUSH CS
	/*0x0F*/	{ DaSpOpcodeLookup<ExtOpCode>, }, //2 byte escape
	/*0x10*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //ADC (Eb,Gb)
	/*0x11*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //ADC (Ev,Gv)
	/*0x12*/	{ DaSpModRM<SpNoMemoryWrite>, }, //ADC (Gb,Eb)
	/*0x13*/	{ DaSpModRM<SpNoMemoryWrite>, }, //ADC (Gv,Ev)
	/*0x14*/	{ DaSpImmediateOp<DaByte>, }, //ADC (AL,Ib)
	/*0x15*/	{ DaSpImmediateOp<SpModeDependent>, }, //ADC (eAX,Iv)
	/*0x16*/	{ NULL, }, //PUSH SS
	/*0x17*/	{ NULL, }, //POP SS
	/*0x18*/	{ DaSpModRM<SpMemoryWrite>, }, //SBB (Eb,Gb)
	/*0x19*/	{ DaSpModRM<SpMemoryWrite>, }, //SBB (Ev,Gv)
	/*0x1A*/	{ DaSpModRM<SpNoMemoryWrite>, }, //SBB (Gb,Eb)
	/*0x1B*/	{ DaSpModRM<SpNoMemoryWrite>, }, //SBB (Gv,Ev)
	/*0x1C*/	{ DaSpImmediateOp<DaByte>, }, //SBB (AL,Ib)
	/*0x1D*/	{ DaSpImmediateOp<SpModeDependent>, }, //SBB (eAX,Iv)
	/*0x1E*/	{ NULL, }, //PUSH DS
	/*0x1F*/	{ NULL, }, //POP DS
	/*0x20*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //AND (Eb,Gb)
	/*0x21*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //AND (Ev,Gv)
	/*0x22*/	{ DaSpModRM<SpNoMemoryWrite>, }, //AND (Gb,Eb)
	/*0x23*/	{ DaSpModRM<SpNoMemoryWrite>, }, //AND (Gv,Ev)
	/*0x24*/	{ DaSpImmediateOp<DaByte>, }, //AND (AL,Ib)
	/*0x25*/	{ DaSpImmediateOp<SpModeDependent>, }, //AND (eAX,Iv)
	/*0x26*/	{ DaSpSegmentOverridePrefixedInstruction, }, //SEG=ES
	/*0x27*/	{ NULL, }, //DAA
	/*0x28*/	{ DaSpModRM<SpMemoryWrite>, }, //SUB (Eb,Gb)
	/*0x29*/	{ DaSpModRM<SpMemoryWrite>, }, //SUB (Ev,Gv)
	/*0x2A*/	{ DaSpModRM<SpNoMemoryWrite>, }, //SUB (Gb,Eb)
	/*0x2B*/	{ DaSpModRM<SpNoMemoryWrite>, }, //SUB (Gv,Ev)
	/*0x2C*/	{ DaSpImmediateOp<DaByte>, }, //SUB (AL,Ib)
	/*0x2D*/	{ DaSpImmediateOp<SpModeDependent>, }, //SUB (eAX,Iv)
	/*0x2E*/	{ DaSpBranchHintOrSegmentOverridePrefixedInstruction, }, //SEG=CS
	/*0x2F*/	{ NULL, }, //DAS
	/*0x30*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //XOR (Eb,Gb)
	/*0x31*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //XOR (Ev,Gv)
	/*0x32*/	{ DaSpModRM<SpNoMemoryWrite>, }, //XOR (Gb,Eb)
	/*0x33*/	{ DaSpModRM<SpNoMemoryWrite>, }, //XOR (Gv,Ev)
	/*0x34*/	{ DaSpImmediateOp<DaByte>, }, //XOR (AL, Ib)
	/*0x35*/	{ DaSpImmediateOp<SpModeDependent>, }, //XOR (eAX, Iv)
	/*0x36*/	{ DaSpSegmentOverridePrefixedInstruction, }, //SEG=SS
	/*0x37*/	{ NULL, }, //AAA
	/*0x38*/	{ DaSpModRM<SpMemoryWrite>, }, //CMP (Eb,Gb)
	/*0x39*/	{ DaSpModRM<SpMemoryWrite>, }, //CMP (Ev,Gv)
	/*0x3A*/	{ DaSpModRM<SpNoMemoryWrite>, }, //CMP (Gb,Eb)
	/*0x3B*/	{ DaSpModRM<SpNoMemoryWrite>, }, //CMP (Gv,Ev)
	/*0x3C*/	{ DaSpImmediateOp<DaByte>, }, //CMP (AL,Ib)
	/*0x3D*/	{ DaSpImmediateOp<SpModeDependent>, }, //CMP (eAX,Iv)
	/*0x3E*/	{ DaSpBranchHintOrSegmentOverridePrefixedInstruction, }, //SEG=DS
	/*0x3F*/	{ NULL, }, //AAS
#ifdef _AMD64_
	/*0x40*/	{ DaSpPrefixedInstruction, }, //default operand size
	/*0x41*/	{ DaSpAmd64BaseEx, DaSpPrefixedInstruction, }, //default operand size, r/m-base-reg extension
	/*0x42*/	{ DaSpAmd64IndexEx, DaSpPrefixedInstruction, }, //default operand size, SIB index extension
	/*0x43*/	{ DaSpAmd64IndexEx, DaSpAmd64BaseEx, DaSpPrefixedInstruction, }, //default operand size, SIB index extension, r/m-base-reg extension
	/*0x44*/	{ DaSpAmd64RegisterEx, DaSpPrefixedInstruction, }, //default operand size, ModRM reg extension
	/*0x45*/	{ DaSpAmd64RegisterEx, DaSpAmd64BaseEx, DaSpPrefixedInstruction, }, //default operand size, ModRM reg extension, r/m-base-reg extension
	/*0x46*/	{ DaSpAmd64RegisterEx, DaSpAmd64IndexEx, DaSpPrefixedInstruction, }, //default operand size, ModRM reg extension, SIB index extension
	/*0x47*/	{ DaSpAmd64RegisterEx, DaSpAmd64IndexEx, DaSpAmd64BaseEx, DaSpPrefixedInstruction, }, //default operand size, ModRM reg extension, SIB index extension, r/m-base-reg extension
	/*0x48*/	{ DaSpAmd64OperandEx, DaSpPrefixedInstruction, }, //64-bit operand
	/*0x49*/	{ DaSpAmd64OperandEx, DaSpAmd64BaseEx, DaSpPrefixedInstruction, }, //64-bit operand, r/m-base-reg extension
	/*0x4A*/	{ DaSpAmd64OperandEx, DaSpAmd64IndexEx, DaSpPrefixedInstruction, }, //64-bit operand, SIB index extension
	/*0x4B*/	{ DaSpAmd64OperandEx, DaSpAmd64IndexEx, DaSpAmd64BaseEx, DaSpPrefixedInstruction, }, //64-bit operand, SIB index extension, r/m-base-reg extension
	/*0x4C*/	{ DaSpAmd64OperandEx, DaSpAmd64RegisterEx, DaSpPrefixedInstruction, }, //64-bit operand, ModRM reg extension
	/*0x4D*/	{ DaSpAmd64OperandEx, DaSpAmd64RegisterEx, DaSpAmd64BaseEx, DaSpPrefixedInstruction, }, //64-bit operand, ModRM reg extension, r/m-base-reg extension
	/*0x4E*/	{ DaSpAmd64OperandEx, DaSpAmd64RegisterEx, DaSpAmd64IndexEx, DaSpPrefixedInstruction, }, //64-bit operand, ModRM reg extension, SIB index extension
	/*0x4F*/	{ DaSpAmd64OperandEx, DaSpAmd64RegisterEx, DaSpAmd64IndexEx, DaSpAmd64BaseEx, DaSpPrefixedInstruction, }, //64-bit operand, ModRM reg extension, SIB index extension, r/m-base-reg extension
#elif defined(WIN32)
	/*0x40*/	{ NULL, }, //INC (eAX)
	/*0x41*/	{ NULL, }, //INC (eCX)
	/*0x42*/	{ NULL, }, //INC (eDX)
	/*0x43*/	{ NULL, }, //INC (eBX)
	/*0x44*/	{ NULL, }, //INC (eSP)
	/*0x45*/	{ NULL, }, //INC (eBP)
	/*0x46*/	{ NULL, }, //INC (eSI)
	/*0x47*/	{ NULL, }, //INC (eDI)
	/*0x48*/	{ NULL, }, //DEC (eAX)
	/*0x49*/	{ NULL, }, //DEC (eCX)
	/*0x4A*/	{ NULL, }, //DEC (eDX)
	/*0x4B*/	{ NULL, }, //DEC (eBX)
	/*0x4C*/	{ NULL, }, //DEC (eSP)
	/*0x4D*/	{ NULL, }, //DEC (eBP)
	/*0x4E*/	{ NULL, }, //DEC (eSI)
	/*0x4F*/	{ NULL, }, //DEC (eDI)
#else
#error OpCode range 40h - 4Fh not defined for this CPU!
#endif
	/*0x50*/	{ DaSpMemoryWrite, }, //PUSH (eAX)
	/*0x51*/	{ DaSpMemoryWrite, }, //PUSH (eCX)
	/*0x52*/	{ DaSpMemoryWrite, }, //PUSH (eDX)
	/*0x53*/	{ DaSpMemoryWrite, }, //PUSH (eBX)
	/*0x54*/	{ DaSpMemoryWrite, }, //PUSH (eSP)
	/*0x55*/	{ DaSpMemoryWrite, }, //PUSH (eBP)
	/*0x56*/	{ DaSpMemoryWrite, }, //PUSH (eSI)
	/*0x57*/	{ DaSpMemoryWrite, }, //PUSH (eDI)
	/*0x58*/	{ NULL, }, //POP (eAX)
	/*0x59*/	{ NULL, }, //POP (eCX)
	/*0x5A*/	{ NULL, }, //POP (eDX)
	/*0x5B*/	{ NULL, }, //POP (eBX)
	/*0x5C*/	{ NULL, }, //POP (eSP)
	/*0x5D*/	{ NULL, }, //POP (eBP)
	/*0x5E*/	{ NULL, }, //POP (eSI)
	/*0x5F*/	{ NULL, }, //POP (eDI)
	/*0x60*/	{ DaSpMemoryWrite, }, //PUSHA/PUSHAD
	/*0x61*/	{ NULL, }, //POPA/POPAD
	/*0x62*/	{ DaSpModRMMemOnly<SpNoMemoryWrite>, }, //BOUND (Gv,Ma)
	/*0x63*/	{ DaSpModRM<SpMemoryWrite>, }, //ARPL (Ew,Gw)
	/*0x64*/	{ DaSpSegmentOverridePrefixedInstruction, }, //SEG=FS
	/*0x65*/	{ DaSpSegmentOverridePrefixedInstruction, }, //SEG=GS
	/*0x66*/	{ DaSpOperandSizeOverridePrefixedInstruction, }, //Opd Size
	/*0x67*/	{ DaSpAddressSizeOverridePrefixedInstruction, }, //Addr Size
	/*0x68*/	{ DaSpMemoryWrite, DaSpImmediateOp<SpModeDependent>, }, //PUSH (Iv)
	/*0x69*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpImmediateOp<SpModeDependent>, }, //IMUL (Gv,Ev,Iv)
	/*0x6A*/	{ DaSpMemoryWrite, DaSpImmediateOp<DaByte>, }, //PUSH (Ib)
	/*0x6B*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpImmediateOp<DaByte>, }, //IMUL (Gv,Ev,Ib)
	/*0x6C*/	{ DaSpRepPrefixAllowed, }, //INS/INSB (Yb,DX)
	/*0x6D*/	{ DaSpRepPrefixAllowed, }, //INS/INSW/INSD (Yv,DX)
	/*0x6E*/	{ DaSpRepPrefixAllowed, }, //OUTS/OUTSB (DX,Xb)
	/*0x6F*/	{ DaSpRepPrefixAllowed, }, //OUTS/OUTSW/OUTSD (DX,Xv)
	/*0x70*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JO (Jb)
	/*0x71*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JNO (Jb)
	/*0x72*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JC (Jb)
	/*0x73*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JNC (Jb)
	/*0x74*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JZ (Jb)
	/*0x75*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JNZ (Jb)
	/*0x76*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JNA (Jb)
	/*0x77*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JA (Jb)
	/*0x78*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JS (Jb)
	/*0x79*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JNS (Jb)
	/*0x7A*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JP (Jb)
	/*0x7B*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JNP (Jb)
	/*0x7C*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JL (Jb)
	/*0x7D*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JNL (Jb)
	/*0x7E*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JNG (Jb)
	/*0x7F*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JG (Jb)
	/*0x80*/	{ DaSpModRMExtended<Group1>, DaSpImmediateOp<DaByte>, DaSpLockPrefixAllowed, }, //Group 1 (Eb,Ib)
	/*0x81*/	{ DaSpModRMExtended<Group1>, DaSpImmediateOp<SpModeDependent>, DaSpLockPrefixAllowed, }, //Group 1 (Ev,Iv)
	/*0x82*/	{ DaSpModRMExtended<Group1>, DaSpImmediateOp<DaByte>, DaSpLockPrefixAllowed, }, //Group 1 (Eb,Ib)
	/*0x83*/	{ DaSpModRMExtended<Group1>, DaSpImmediateOp<DaByte>, DaSpLockPrefixAllowed, }, //Group 1 (Ev,Ib)
	/*0x84*/	{ DaSpModRM<SpMemoryWrite>, }, //TEST (Eb,Gb)
	/*0x85*/	{ DaSpModRM<SpMemoryWrite>, }, //TEST (Ev,Gv)
	/*0x86*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //XCHG (Eb,Gb)
	/*0x87*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //XCHG (Ev,Gv)
	/*0x88*/	{ DaSpModRM<SpMemoryWrite>, }, //MOV (Eb,Gb)
	/*0x89*/	{ DaSpModRM<SpMemoryWrite>, }, //MOV (Ev,Gv)
	/*0x8A*/	{ DaSpModRM<SpNoMemoryWrite>, }, //MOV (Gb,Eb)
	/*0x8B*/	{ DaSpModRM<SpNoMemoryWrite>, }, //MOV (Gv,Ev)
	/*0x8C*/	{ DaSpModRM<SpMemoryWrite>, }, //MOV (Ew,Sw)
	/*0x8D*/	{ DaSpModRM<SpNoMemoryWrite>, }, //LEA (Gv,M)
	/*0x8E*/	{ DaSpModRM<SpNoMemoryWrite>, }, //MOV (Sw,Ew)
	/*0x8F*/	{ DaSpModRM<SpMemoryWrite>, }, //POP (Ev)
	/*0x90*/	{ NULL, }, //NOP
	/*0x91*/	{ NULL, }, //XCHG (eCX)
	/*0x92*/	{ NULL, }, //XCHG (eDX)
	/*0x93*/	{ NULL, }, //XCHG (eBX)
	/*0x94*/	{ NULL, }, //XCHG (eSP)
	/*0x95*/	{ NULL, }, //XCHG (eBP)
	/*0x96*/	{ NULL, }, //XCHG (eSI)
	/*0x97*/	{ NULL, }, //XCHG (eDI)
	/*0x98*/	{ NULL, }, //CBW/CBWE
	/*0x99*/	{ NULL, }, //CWD/CDQ
	/*0x9A*/	{ DaSpOffsetOp<SpNoMemoryWrite>, DaSpImmediateOp<DaWord>, DaSpAbsoluteCallBranch, }, //CALLF (Ap)
	/*0x9B*/	{ NULL, }, //FWAIT/WAIT
	/*0x9C*/	{ NULL, DaSpMemoryWrite, }, //PUSHF/PUSHFD (Fv)
	/*0x9D*/	{ NULL, }, //POPF/POPFD
	/*0x9E*/	{ NULL, }, //SAHF
	/*0x9F*/	{ NULL, }, //LAHF
	/*0xA0*/	{ DaSpOffsetOp<SpNoMemoryWrite>, }, //MOV (AL,Ob)
	/*0xA1*/	{ DaSpOffsetOp<SpNoMemoryWrite>, }, //MOV (eAX,Ov)
	/*0xA2*/	{ DaSpOffsetOp<SpMemoryWrite>, }, //MOV (Ob,AL)
	/*0xA3*/	{ DaSpOffsetOp<SpMemoryWrite>, }, //MOV (Ov,eAX)
	/*0xA4*/	{ DaSpMemoryWrite, DaSpRepPrefixAllowed, }, //MOVS/MOVSB (Yb,Xb)
	/*0xA5*/	{ DaSpMemoryWrite, DaSpRepPrefixAllowed, }, //MOVS/MOVSW/MOVSD (Yv,Xv)
	/*0xA6*/	{ DaSpRepPrefixAllowed, DaSpRepNEPrefixAllowed, }, //CMPS/CMPSB (Yb,Xb)
	/*0xA7*/	{ DaSpRepPrefixAllowed, DaSpRepNEPrefixAllowed, }, //CMPS/CMPSW/CMPSD (Xv,Yv)
	/*0xA8*/	{ DaSpImmediateOp<DaByte>, }, //TEST (AL,Ib)
	/*0xA9*/	{ DaSpImmediateOp<SpModeDependent>, }, //TEST (eAX,Iv)
	/*0xAA*/	{ DaSpMemoryWrite, DaSpRepPrefixAllowed, }, //STOS/STOSB (Yb,AL)
	/*0xAB*/	{ DaSpMemoryWrite, DaSpRepPrefixAllowed, }, //STOS/STOSW/STOSD (Yv,eAX)
	/*0xAC*/	{ DaSpRepPrefixAllowed, }, //LODS/LODSB (AL,Xb)
	/*0xAD*/	{ DaSpRepPrefixAllowed, }, //LODS/LODSW/LODSD (eAX,Xv)
	/*0xAE*/	{ DaSpRepPrefixAllowed, DaSpRepNEPrefixAllowed, }, //SCAS/SCASB (AL,Yb)
	/*0xAF*/	{ DaSpRepPrefixAllowed, DaSpRepNEPrefixAllowed, }, //SCAS/SCASW/SCASD (eAX,Yv)
	/*0xB0*/	{ DaSpImmediateOp<DaByte>, }, //MOV (AL,Ib)
	/*0xB1*/	{ DaSpImmediateOp<DaByte>, }, //MOV (CL,Ib)
	/*0xB2*/	{ DaSpImmediateOp<DaByte>, }, //MOV (DL,Ib)
	/*0xB3*/	{ DaSpImmediateOp<DaByte>, }, //MOV (BL,Ib)
	/*0xB4*/	{ DaSpImmediateOp<DaByte>, }, //MOV (AH,Ib)
	/*0xB5*/	{ DaSpImmediateOp<DaByte>, }, //MOV (CH,Ib)
	/*0xB6*/	{ DaSpImmediateOp<DaByte>, }, //MOV (DH,Ib)
	/*0xB7*/	{ DaSpImmediateOp<DaByte>, }, //MOV (BH,Ib)
	/*0xB8*/	{ DaSpImmediateOp<SpModeDependentRexW>, }, //MOV (eAX,Iv)
	/*0xB9*/	{ DaSpImmediateOp<SpModeDependentRexW>, }, //MOV (eCX,Iv)
	/*0xBA*/	{ DaSpImmediateOp<SpModeDependentRexW>, }, //MOV (eDX,Iv)
	/*0xBB*/	{ DaSpImmediateOp<SpModeDependentRexW>, }, //MOV (eBX,Iv)
	/*0xBC*/	{ DaSpImmediateOp<SpModeDependentRexW>, }, //MOV (eSP,Iv)
	/*0xBD*/	{ DaSpImmediateOp<SpModeDependentRexW>, }, //MOV (eBP,Iv)
	/*0xBE*/	{ DaSpImmediateOp<SpModeDependentRexW>, }, //MOV (eSI,Iv)
	/*0xBF*/	{ DaSpImmediateOp<SpModeDependentRexW>, }, //MOV (eDI,Iv)
	/*0xC0*/	{ DaSpModRMExtended<Group1>, DaSpImmediateOp<DaByte>, }, //Group 2 (Eb,Ib)
	/*0xC1*/	{ DaSpModRMExtended<Group1>, DaSpImmediateOp<DaByte>, }, //Group 2 (Ev,Ib)
	/*0xC2*/	{ DaSpImmediateOp<DaWord>, DaSpAbsoluteBranch, }, //RET Iw
	/*0xC3*/	{ DaSpAbsoluteBranch, }, //RET
	/*0xC4*/	{ DaSpModRMMemOnly<SpNoMemoryWrite>, }, //LES (Gv,Mp)
	/*0xC5*/	{ DaSpModRMMemOnly<SpNoMemoryWrite>, }, //LDS (Gv,Mp)
	/*0xC6*/	{ DaSpModRMExtended<Group11>, DaSpImmediateOp<DaByte>, }, //MOV (Eb,Ib)
	/*0xC7*/	{ DaSpModRMExtended<Group11>, DaSpImmediateOp<SpModeDependent>, }, //MOV (Ev,Iv)
	/*0xC8*/	{ DaSpImmediateOp<DaWord>, DaSpImmediateOp<DaByte>, }, //ENTER (Iw,Ib)
	/*0xC9*/	{ NULL, }, //LEAVE
	/*0xCA*/	{ DaSpImmediateOp<DaWord>, DaSpAbsoluteBranch, }, //RETF (Iw)
	/*0xCB*/	{ DaSpAbsoluteBranch, }, //RETF
	/*0xCC*/	{ DaSpAbsoluteBranch, }, //INT 3
	/*0xCD*/	{ DaSpImmediateOp<DaByte>, DaSpAbsoluteBranch, }, //INT (Ib)
	/*0xCE*/	{ DaSpAbsoluteBranch, }, //INTO
	/*0xCF*/	{ DaSpAbsoluteBranch, }, //IRET
	/*0xD0*/	{ DaSpModRMExtended<Group1>, }, //Group 2 (Eb,1)
	/*0xD1*/	{ DaSpModRMExtended<Group1>, }, //Group 2 (Ev,1)
	/*0xD2*/	{ DaSpModRMExtended<Group1>, }, //Group 2 (Eb,CL)
	/*0xD3*/	{ DaSpModRMExtended<Group1>, }, //Group 2 (Ev,CL)
	/*0xD4*/	{ DaSpImmediateOp<DaByte>, }, //AAM (Ib)
	/*0xD5*/	{ DaSpImmediateOp<DaByte>, }, //AAD (Ib)
	/*0xD6*/	{ DaSpUndefinedInstruction, },
	/*0xD7*/	{ NULL, }, //XLAT/XLATB
	/*0xD8*/	{ DaSpFPExtended<&FPExtD8>, }, //FP escape
	/*0xD9*/	{ DaSpFPExtended<&FPExtD9>, }, //FP escape
	/*0xDA*/	{ DaSpFPExtended<&FPExtDA>, }, //FP escape
	/*0xDB*/	{ DaSpFPExtended<&FPExtDB>, }, //FP escape
	/*0xDC*/	{ DaSpFPExtended<&FPExtDC>, }, //FP escape
	/*0xDD*/	{ DaSpFPExtended<&FPExtDD>, }, //FP escape
	/*0xDE*/	{ DaSpFPExtended<&FPExtDE>, }, //FP escape
	/*0xDF*/	{ DaSpFPExtended<&FPExtDF>, }, //FP escape
	/*0xE0*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //LOOPNZ (Jb)
	/*0xE1*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //LOOPZ (Jb)
	/*0xE2*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //LOOP (Jb)
	/*0xE3*/	{ DaSpConditionalBranch, DaSpRelativeOffset<DaByte>, }, //JCXZ/JECXZ (Jb)
	/*0xE4*/	{ DaSpImmediateOp<DaByte>, }, //IN (AL,Ib)
	/*0xE5*/	{ DaSpImmediateOp<DaByte>, }, //IN (eAX,Ib)
	/*0xE6*/	{ DaSpImmediateOp<DaByte>, }, //OUT (Ib,AL)
	/*0xE7*/	{ DaSpImmediateOp<DaByte>, }, //OUT (Ib,eAX)
	/*0xE8*/	{ DaSpCallBranch, DaSpRelativeOffset<SpModeDependent>, }, //CALL (Jv)
	/*0xE9*/	{ DaSpBranch, DaSpRelativeOffset<SpModeDependent>, }, //JMP (near Jv)
	/*0xEA*/	{ DaSpAbsoluteBranch, DaSpImmediateOp<SpModeDependent>, }, //JMP (far Ap)
	/*0xEB*/	{ DaSpBranch, DaSpRelativeOffset<DaByte>, }, //JMP (short Jb)
	/*0xEC*/	{ NULL, }, //IN (AL,DX)
	/*0xED*/	{ NULL, }, //IN (eAX,DX)
	/*0xEE*/	{ NULL, }, //OUT (DX,AL)
	/*0xEF*/	{ NULL, }, //OUT (DX,eAX)
	/*0xF0*/	{ DaSpLockPrefixedInstruction, }, //LOCK
	/*0xF1*/	{ DaSpUndefinedInstruction, },
	/*0xF2*/	{ DaSpRepNEPrefixedInstruction, }, //REPNE
	/*0xF3*/	{ DaSpRepPrefixedInstruction, }, //REP/REPE
	/*0xF4*/	{ NULL, }, //HLT
	/*0xF5*/	{ NULL, }, //CMC
	/*0xF6*/	{ DaSpModRMExtended<Group3Byte>, }, //Group 3 (Eb)
	/*0xF7*/	{ DaSpModRMExtended<Group3ModeDependent>, }, //Group 3 (Ev)
	/*0xF8*/	{ NULL, }, //CLC
	/*0xF9*/	{ NULL, }, //STC
	/*0xFA*/	{ NULL, }, //CLI
	/*0xFB*/	{ NULL, }, //STI
	/*0xFC*/	{ NULL, }, //CLD
	/*0xFD*/	{ NULL, }, //STD
	/*0xFE*/	{ DaSpModRMExtended<Group4>, }, //Group 4
	/*0xFF*/	{ DaSpModRMExtended<Group5>, }, //Group 5
};


CITable ExtOpCode =
{
	/*0x00*/	{ DaSpModRMExtended<Group6>, }, //Group 6
	/*0x01*/	{ DaSpModRMExtended<Group7>, }, //Group 7
	/*0x02*/	{ DaSpModRM<SpNoMemoryWrite>, }, //LAR (Gv,Ew)
	/*0x03*/	{ DaSpModRM<SpNoMemoryWrite>, }, //LSL (Gv,Ew)
	/*0x04*/	{ DaSpUndefinedInstruction, },
	/*0x05*/	{ DaSpUndefinedInstruction, },
	/*0x06*/	{ NULL, }, //CLTS
	/*0x07*/	{ DaSpUndefinedInstruction, },
	/*0x08*/	{ NULL, }, //INVD
	/*0x09*/	{ NULL, }, //WBINVD
	/*0x0A*/	{ DaSpUndefinedInstruction, },
	/*0x0B*/	{ NULL, }, //UD2 (trigger undefined opcode excpetion)
	/*0x0C*/	{ DaSpUndefinedInstruction, },
	/*0x0D*/	{ DaSpUndefinedInstruction, },
	/*0x0E*/	{ DaSpUndefinedInstruction, },
	/*0x0F*/	{ DaSpUndefinedInstruction, },
	/*0x10*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpRepPrefixAllowed, DaSpRepNEPrefixAllowed, }, //MOVUPS (Vps,Wps); (F3)MOVFSS (Vss,Wss); (66)MOVUPD (Vpd,Wpd); (F2)MOVSD (Vsd,Wsd)
	/*0x11*/	{ DaSpModRM<SpMemoryWrite>, DaSpRepPrefixAllowed, DaSpRepNEPrefixAllowed, }, //MOVUPS (Wps,Vps); (F3)MOVFSS (Wss,Vss); (66)MOVUPD (Wpd,Vpd); (F2)MOVSD (Wsd,Vsd)
	/*0x12*/	{ DaSpModRM<SpMemoryWrite>, }, //MOVLPS (Wq,Vq); (66)MOVLPD (Ws,Vs); MOVHLPS (Vq,Vq)
	/*0x13*/	{ DaSpModRM<SpNoMemoryWrite>, }, //MOVLPS (Vq,Wq); (66)MOVLPD (Vs,Ws)
	/*0x14*/	{ DaSpModRM<SpNoMemoryWrite>, }, //UNPCKLPS (Vps,Wq); (66)UNPCKLPD (Vpd,Wq)
	/*0x15*/	{ DaSpModRM<SpNoMemoryWrite>, }, //UNPCKHPS (Vps,Wq); (66)UNPCKHPD (Vpd,Wq)
	/*0x16*/	{ DaSpModRM<SpNoMemoryWrite>, }, //MOVHPS (Vq,Wq); (66)MOVHPD (Vs,Ws); MOVLHPS (Vq,Vq)
	/*0x17*/	{ DaSpModRM<SpMemoryWrite>, }, //MOVHPS (Wq,Vq); (66)MOVHPD (Ws,Vs)
	/*0x18*/	{ DaSpModRMExtended<Group16>, }, //PREFETCH (Group 16)
	/*0x19*/	{ DaSpUndefinedInstruction, },
	/*0x1A*/	{ DaSpUndefinedInstruction, },
	/*0x1B*/	{ DaSpUndefinedInstruction, },
	/*0x1C*/	{ DaSpUndefinedInstruction, },
	/*0x1D*/	{ DaSpUndefinedInstruction, },
	/*0x1E*/	{ DaSpUndefinedInstruction, },
	/*0x1F*/	{ DaSpUndefinedInstruction, },
	/*0x20*/	{ DaSpModRMRegOnly, }, //MOV (Rd,Cd)
	/*0x21*/	{ DaSpModRMRegOnly, }, //MOV (Rd,Dd)
	/*0x22*/	{ DaSpModRMRegOnly, }, //MOV (Cd,Rd)
	/*0x23*/	{ DaSpModRMRegOnly, }, //MOV (Dd,Rd)
	/*0x24*/	{ DaSpModRMRegOnly, }, //MOV (Rd,Td)
	/*0x25*/	{ DaSpUndefinedInstruction, },
	/*0x26*/	{ DaSpModRMRegOnly, }, //MOV (Td,Rd)
	/*0x27*/	{ DaSpUndefinedInstruction, },
	/*0x28*/	{ DaSpModRM<SpNoMemoryWrite>, }, //MOVAPS (Vps,Wps); (66)MOVAPD (Vpd,Wpd)
	/*0x29*/	{ DaSpModRM<SpMemoryWrite>, }, //MOVAPS (Wps,Vps); (66)MOVAPD (Wpd,Vpd)
	/*0x2A*/	{ DaSpModRM<SpNoMemoryWrite>, DaSpRepPrefixAllowed, DaSpRepNEPrefixAllowed, }, //CVTPI2PS (Vps,Qq); (F3)CVTSI2SS (Vss,Ed); (66)CVTPI2PD (Vpd,Qdq); (F2)CVTSI2SD (Vsd,Ed)
	/*0x2B*/	{ DaSpModRM<SpMemoryWrite>, }, //MOVNTPS (Wps,Vps); (66)MOVNTPD (Wpd,Vpd)
	/*0x2C*/	{ DaSpModRM<SpMemoryWrite>, DaSpRepPrefixAllowed, DaSpRepNEPrefixAllowed, }, //CVTTPS2PI (Qq,Wps); (F3)CVTTSS2SI (Gd,Wss); (66)CVTTPD2PI (Qdq,Wpd); (F2)CVTTSD2SI (Gd,Wsd)
	/*0x2D*/	{ DaSpModRM<SpMemoryWrite>, DaSpRepPrefixAllowed, DaSpRepNEPrefixAllowed, }, //CVTPS2PI (Qq,Wps); (F3)CVTSS2SI (Gd,Wss); (66)CVTPD2PI (Qdq,Wpd); (F2)CVTSD2SI (Gd,Wsd)
	/*0x2E*/	{ DaSpModRM<SpNoMemoryWrite>, }, //UCOMISS (Vss,Wss); (66)UCOMISD (Vsd,Wsd)
	/*0x2F*/	{ DaSpModRM<SpNoMemoryWrite>, }, //COMISS (Vss,Wss); (66)COMISD (Vsd,Wsd)
	/*0x30*/	{ NULL, }, //WRMSR
	/*0x31*/	{ NULL, }, //RDTSC
	/*0x32*/	{ NULL, }, //RDMSR
	/*0x33*/	{ NULL, }, //RDPMC
	/*0x34*/	{ DaSpAbsoluteBranch, }, //SYSENTER
	/*0x35*/	{ DaSpAbsoluteBranch, }, //SYSEXIT
	/*0x36*/	{ DaSpUndefinedInstruction, },
	/*0x37*/	{ DaSpUndefinedInstruction, },
	/*0x38*/	{ DaSpUndefinedInstruction, },
	/*0x39*/	{ DaSpUndefinedInstruction, },
	/*0x3A*/	{ DaSpUndefinedInstruction, },
	/*0x3B*/	{ DaSpUndefinedInstruction, },
	/*0x3C*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //MOVNTI (Mv,Gv)
	/*0x3D*/	{ DaSpUndefinedInstruction, },
	/*0x3E*/	{ DaSpUndefinedInstruction, },
	/*0x3F*/	{ DaSpUndefinedInstruction, },
	/*0x40*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVO (Gv,Ev)
	/*0x41*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVNO (Gv,Ev)
	/*0x42*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVC (Gv,Ev)
	/*0x43*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVNC (Gv,Ev)
	/*0x44*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVZ (Gv,Ev)
	/*0x45*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVNZ (Gv,Ev)
	/*0x46*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVBE (Gv,Ev)
	/*0x47*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVA (Gv,Ev)
	/*0x48*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVS (Gv,Ev)
	/*0x49*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVNS (Gv,Ev)
	/*0x4A*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVP (Gv,Ev)
	/*0x4B*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVNP (Gv,Ev)
	/*0x4C*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVL (Gv,Ev)
	/*0x4D*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVGE (Gv,Ev)
	/*0x4E*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVLE (Gv,Ev)
	/*0x4F*/	{ DaSpModRMMemOnly<SpMemoryWrite>, }, //CMOVG (Gv,Ev)
	/*0x50*/	{NULL },
	/*0x51*/	{NULL },
	/*0x52*/	{NULL },
	/*0x53*/	{NULL },
	/*0x54*/	{NULL },
	/*0x55*/	{NULL },
	/*0x56*/	{NULL },
	/*0x57*/	{NULL },
	/*0x58*/	{NULL },
	/*0x59*/	{NULL },
	/*0x5A*/	{NULL },
	/*0x5B*/	{NULL },
	/*0x5C*/	{NULL },
	/*0x5D*/	{NULL },
	/*0x5E*/	{NULL },
	/*0x5F*/	{NULL },
	/*0x60*/	{NULL },
	/*0x61*/	{NULL },
	/*0x62*/	{NULL },
	/*0x63*/	{NULL },
	/*0x64*/	{NULL },
	/*0x65*/	{NULL },
	/*0x66*/	{NULL },
	/*0x67*/	{NULL },
	/*0x68*/	{NULL },
	/*0x69*/	{NULL },
	/*0x6A*/	{NULL },
	/*0x6B*/	{NULL },
	/*0x6C*/	{NULL },
	/*0x6D*/	{NULL },
	/*0x6E*/	{NULL },
	/*0x6F*/	{NULL },
	/*0x70*/	{NULL },
	/*0x71*/	{NULL },
	/*0x72*/	{NULL },
	/*0x73*/	{NULL },
	/*0x74*/	{NULL },
	/*0x75*/	{NULL },
	/*0x76*/	{NULL },
	/*0x77*/	{NULL },
	/*0x78*/	{NULL },
	/*0x79*/	{NULL },
	/*0x7A*/	{NULL },
	/*0x7B*/	{NULL },
	/*0x7C*/	{NULL },
	/*0x7D*/	{NULL },
	/*0x7E*/	{NULL },
	/*0x7F*/	{NULL },
	/*0x80*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JO (Jz)
	/*0x81*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JNO (Jz)
	/*0x82*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JC (Jz)
	/*0x83*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JNC (Jz)
	/*0x84*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JZ (Jz)
	/*0x85*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JNZ (Jz)
	/*0x86*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JNA (Jz)
	/*0x87*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JA (Jzb)
	/*0x88*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JS (Jz)
	/*0x89*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JNS (Jz)
	/*0x8A*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JP (Jz)
	/*0x8B*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JNP (Jz)
	/*0x8C*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JL (Jz)
	/*0x8D*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JNL (Jz)
	/*0x8E*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JNG (Jz)
	/*0x8F*/	{ DaSpConditionalBranch, DaSpRelativeOffset<SpModeDependent>, }, //JG (Jz)
	/*0x90*/	{NULL },
	/*0x91*/	{NULL },
	/*0x92*/	{NULL },
	/*0x93*/	{NULL },
	/*0x94*/	{NULL },
	/*0x95*/	{NULL },
	/*0x96*/	{NULL },
	/*0x97*/	{NULL },
	/*0x98*/	{NULL },
	/*0x99*/	{NULL },
	/*0x9A*/	{NULL },
	/*0x9B*/	{NULL },
	/*0x9C*/	{NULL },
	/*0x9D*/	{NULL },
	/*0x9E*/	{NULL },
	/*0x9F*/	{NULL },
	/*0xA0*/	{NULL },
	/*0xA1*/	{NULL },
	/*0xA2*/	{NULL },
	/*0xA3*/	{NULL },
	/*0xA4*/	{NULL },
	/*0xA5*/	{NULL },
	/*0xA6*/	{NULL },
	/*0xA7*/	{NULL },
	/*0xA8*/	{NULL },
	/*0xA9*/	{NULL },
	/*0xAA*/	{NULL },
	/*0xAB*/	{NULL },
	/*0xAC*/	{NULL },
	/*0xAD*/	{NULL },
	/*0xAE*/	{NULL },
	/*0xAF*/	{NULL },
	/*0xB0*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //CMPXCHG (Eb,Gb)
	/*0xB1*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //CMPXCHG (Ev,Gv)
	/*0xB2*/	{NULL },
	/*0xB3*/	{NULL },
	/*0xB4*/	{NULL },
	/*0xB5*/	{NULL },
	/*0xB6*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //MOVZX (Gv,Eb)
	/*0xB7*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //MOVZX (Gv,Ew)
	/*0xB8*/	{NULL },
	/*0xB9*/	{NULL },
	/*0xBA*/	{NULL },
	/*0xBB*/	{NULL },
	/*0xBC*/	{NULL },
	/*0xBD*/	{NULL },
	/*0xBE*/	{NULL },
	/*0xBF*/	{NULL },
	/*0xC0*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //XADD (Eb,Gb)
	/*0xC1*/	{ DaSpModRM<SpMemoryWrite>, DaSpLockPrefixAllowed, }, //XADD (Ev,Gv)
	/*0xC2*/	{NULL },
	/*0xC3*/	{NULL },
	/*0xC4*/	{NULL },
	/*0xC5*/	{NULL },
	/*0xC6*/	{NULL },
	/*0xC7*/	{NULL },
	/*0xC8*/	{NULL },
	/*0xC9*/	{NULL },
	/*0xCA*/	{NULL },
	/*0xCB*/	{NULL },
	/*0xCC*/	{NULL },
	/*0xCD*/	{NULL },
	/*0xCE*/	{NULL },
	/*0xCF*/	{NULL },
	/*0xD0*/	{NULL },
	/*0xD1*/	{NULL },
	/*0xD2*/	{NULL },
	/*0xD3*/	{NULL },
	/*0xD4*/	{NULL },
	/*0xD5*/	{NULL },
	/*0xD6*/	{NULL },
	/*0xD7*/	{NULL },
	/*0xD8*/	{NULL },
	/*0xD9*/	{NULL },
	/*0xDA*/	{NULL },
	/*0xDB*/	{NULL },
	/*0xDC*/	{NULL },
	/*0xDD*/	{NULL },
	/*0xDE*/	{NULL },
	/*0xDF*/	{NULL },
	/*0xE0*/	{NULL },
	/*0xE1*/	{NULL },
	/*0xE2*/	{NULL },
	/*0xE3*/	{NULL },
	/*0xE4*/	{NULL },
	/*0xE5*/	{NULL },
	/*0xE6*/	{NULL },
	/*0xE7*/	{NULL },
	/*0xE8*/	{NULL },
	/*0xE9*/	{NULL },
	/*0xEA*/	{NULL },
	/*0xEB*/	{NULL },
	/*0xEC*/	{NULL },
	/*0xED*/	{NULL },
	/*0xEE*/	{NULL },
	/*0xEF*/	{NULL },
	/*0xF0*/	{NULL },
	/*0xF1*/	{NULL },
	/*0xF2*/	{NULL },
	/*0xF3*/	{NULL },
	/*0xF4*/	{NULL },
	/*0xF5*/	{NULL },
	/*0xF6*/	{NULL },
	/*0xF7*/	{NULL },
	/*0xF8*/	{NULL },
	/*0xF9*/	{NULL },
	/*0xFA*/	{NULL },
	/*0xFB*/	{NULL },
	/*0xFC*/	{NULL },
	/*0xFD*/	{NULL },
	/*0xFE*/	{NULL },
	/*0xFF*/	{NULL },
};

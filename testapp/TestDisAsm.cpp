// TestDisAsm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "StdAfx.h"

#include <strstream>

#include "CreateInstruction.h"
#include "InstructionSequence.h"
#include "DisAsmHook.h"


void Pre()
{
	return;
}

void Post()
{
	return;
}

HMODULE TestFunc(LPCTSTR pszName)
{
	OutputDebugString("TestFunc(");
	OutputDebugString(pszName);
	OutputDebugString(")\r\n");
	return GetModuleHandle(pszName);
}

struct Wrapper
{
	Wrapper() : m_pszModule(NULL)
	{
		MessageBox(NULL, "In function entry hook!", "Test", MB_OK);
	}
	Wrapper(LPCTSTR pszName) : m_pszModule(pszName)
	{
		MessageBox(NULL, "In function entry hook!", pszName, MB_OK);
	}
	~Wrapper()
	{
	}
	const LPCTSTR m_pszModule;
	static bool IsMemberFunction() { return false; }
	static Wrapper* OnEntry(LPCTSTR pszName) { return new Wrapper(pszName); }
	static DWORD OnExit(Wrapper* pThis, const DWORD dwResult)
	{
		char buf[60];
		sprintf(buf, "In exit hook!\nReturning: %x", dwResult);
		MessageBox(NULL, buf, pThis->m_pszModule ? pThis->m_pszModule : "Test", MB_OK);
		delete pThis;
		return dwResult;
	}
};

int main()
{
	DaByte* pbSource = (DaByte*)&TestFunc;
	if (CompareOpCodeBytes<AsmFarJmp>(pbSource))
		pbSource = (DaByte*)(((AsmFarJmp*)&TestFunc)->GetDestination());
	DaByteStream S(pbSource);
	DaInstructionSequence Test(S, CreateInstruction);
	Test.Extend(10);
	/*
		std::ostrstream s;
		Test.Dump( s );
		s << std::ends;
		OutputDebugString( s.str() );
	//	static DaHookStaticCode HTest1( pbSource, (PROC)Pre, (PROC)Post );
	//	TestFunc(); //pre-hook test
	*/
	//	static WrapFunctionEntry<Wrapper> HTest2( (PROC)pbSource, 9 );

	new DaWrapFunctionEntry<Wrapper>((PROC)pbSource);
	HMODULE hmodTest = TestFunc("KERNEL32.DLL"); //post-hook test
	return 0;
}

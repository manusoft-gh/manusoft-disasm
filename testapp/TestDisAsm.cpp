// TestDisAsm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Copyright 2003 ManuSoft
// http://www.manusoft.com
//
// Use of this software is governed by the terms of:
// GNU General Public License v2.0
// See LICENSE for details

#include "StdAfx.h"

#include <strstream>

#include "CreateInstruction.h"
#include "InstructionSequence.h"
#include "DisAsmHook.h"

#pragma optimize("", off) //optimizing compiler elides all the hook code!

void Pre()
{
	Beep(600, 500);
}

void Post()
{
	Beep(400, 500);
}

HMODULE TestFunc(LPCTSTR pszName)
{
	OutputDebugString(_T("TestFunc(\""));
	OutputDebugString(pszName);
	OutputDebugString(_T("\")\r\n"));
	return GetModuleHandle(pszName);
}

struct TestHook
{
	TestHook() : m_pszModule(NULL)
	{
		MessageBox(NULL, _T("In function entry hook!"), _T("Test"), MB_OK);
	}
	TestHook(LPCTSTR pszName) : m_pszModule(pszName)
	{
		MessageBox(NULL, _T("In function entry hook!"), pszName, MB_OK);
	}
	~TestHook()
	{
	}
	const LPCTSTR m_pszModule;
	static bool IsMemberFunction() { return false; }
	static TestHook* OnEntry(LPCTSTR pszName) { return new TestHook(pszName); }
	static DWORD_PTR OnExit(TestHook* pThis, const DWORD_PTR Result)
	{
		TCHAR buf[60];
		_stprintf(buf, _T("In exit hook!\nReturning: %p"), (void*)Result);
		MessageBox(NULL, buf, pThis->m_pszModule ? pThis->m_pszModule : _T("Test"), MB_OK);
		delete pThis;
		return Result;
	}
};

#pragma optimize("", on)


int main()
{
	// All the examples use the entrypoint address of TestFunc() as the target location
	DaByte* pbSource = (DaByte*)&TestFunc;

	// First, a normal call of TestFunc() to confirm debug output is emitted
	{
		HMODULE hmodTest = TestFunc(_T("KERNEL32.DLL"));
	}

	// Example 1: disassemble a stream of instructions at runtime
	if (CompareOpCodeBytes<AsmFarJmp>(pbSource)) //is first instruction a far jmp?
		pbSource = (DaByte*)(((AsmFarJmp*)&TestFunc)->GetDestination()); //yes, follow the jmp
	DaByteStream S(pbSource); //initialize the raw byte stream
	DaInstructionSequence Test(S, CreateInstruction); //initialize the instruction stream
	Test.Extend(10); //disassemble the first ten instructions

	// Dump the disassembled instructions to debugger output
	std::ostrstream s;
	Test.Dump( s );
	s << std::ends;
	OutputDebugStringA( s.str() );

	// IMPORTANT NOTE
	//
	// All classes derived from CodeHeap must be allocated only on the heap via
	// operator new(). This is necessary because they may contain inline assembly
	// instructions as data members, and these must reside in a memory region
	// marked as executable. CodeHeap defines custom allocators to ensure this.
	// If the following hook classes are allocated on the stack, inline code will
	// trigger an access violation because the stack memory is not marked as
	// executable.

	// Example 2: implant a pre/post hook around an arbitrary instruction sequence
	{
		auto hook = std::make_unique < DaHookStaticCode<> >( pbSource, (FARPROC)Pre, (FARPROC)Post);
		// test the hook: Pre() and Post() should be called
		HMODULE hmodTest = TestFunc(_T("KERNEL32.DLL"));
	}

	// Example 3: hook well-known function entry/exit using a TestHook instance
	{
		// Note: size argument must be >= 5 and represent a known instruction boundary!
#ifdef _WIN64
		//mov qword ptr [rsp+8],rcx
		static const ULONG cbInstructions = 5;
#else
#ifdef _DEBUG
		//push ebp
		//mov ebp, esp
		//sub esp, 0C0h
		static const ULONG cbInstructions = 9;
#else
		//push ebp
		//mov ebp, esp
		//push offset string
		static const ULONG cbInstructions = 8;
#endif
#endif
		auto hook = std::make_unique < WrapFunctionEntry< TestHook > >( (FARPROC)pbSource, cbInstructions );
		// test the hook: TestHook ctor/dtor should be called
		HMODULE hmodTest = TestFunc(_T("KERNEL32.DLL"));
	}

	// Example 4: hook arbitrary function entry/exit using a TestHook instance
	{
		auto hook = std::make_unique < DaWrapFunctionEntry< TestHook > >( (FARPROC)pbSource );
		// test the hook: TestHook ctor/dtor should be called
		HMODULE hmodTest = TestFunc(_T("KERNEL32.DLL"));
	}
	return 0;
}

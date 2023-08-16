# manusoft-disasm
This collection of classes and functions contains some basic runtime
disassembler functionality for Intel x86 and x64 executable code on
Windows. The library is far from complete. It is designed for tools
that perform dynamic code patching of foreign or opaque executable
code at runtime by examining assembly instructions. This sort of
requirement is typically encountered when patching hooks at the
beginning or end of exported functions, e.g. for an API hooking
utility. The DisAsm library depends on the WinPatch library:
https://github.com/manusoft-gh/manusoft-winpatch

A test app is inluded in the testapp folder. This very briefly
demonstrates some DisAsm functionality in TestDisAsm.cpp. Sorry,
there is no documentation.

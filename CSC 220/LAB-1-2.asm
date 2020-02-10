;lab 1 (#2)
;purpose: manipulating values (with and without registers)

.386
INCLUDE Irvine32.inc
;Assume I have the following data segment written:

.data
val1 BYTE 10h
val2 WORD 8000h
val3 DWORD 0FFFFh
val4 WORD 7FFFh
	
;1. Write an instruction that increments val2.
;2. Write an instruction that subtracts val3 from EAX.
;3. Write instructions that subtract val4 from val2.

.code
;Write your instructions here
main PROC
inc val2 
sub eax, val3
movzx ebx, val2
movzx ecx, val4
sub ebx,ecx

call DumpRegs 

invoke ExitProcess, 0
main ENDP
END
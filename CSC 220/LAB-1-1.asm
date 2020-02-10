;lab 1 (#1)
;purpose: to add registers together
.386
INCLUDE Irvine32.inc

.data ;declaring variables for adding
	val BYTE 1h
	val1 WORD 33h
	val2 DWORD 0000AB4Ah
	Result DWORD ?

.code


main PROC
mov eax, 0 ;clearing general purpose registers
mov ebx, 0
mov ecx, 0
mov edx, 0
mov esi, 0
mov edi, 0 ;end of clearing

L1: ;moving variables into their registers
 MOVZX eax, val
 MOVZX ebx, val1
 MOV ecx, val2

L2: ;adding variables into ecx
	ADD ecx, eax
	ADD ecx, ebx

call DumpRegs ;Check registers via output

MOV Result, ecx ;move ecx to result

invoke ExitProcess,0
main ENDP
END
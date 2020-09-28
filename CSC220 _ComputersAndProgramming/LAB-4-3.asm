; dec 12 2019
; lab 4 #3

.386
.model flat,stdcall
.stack 4096
INCLUDE Irvine32.inc


.data
Array DWORD 1,2,3,4,5,6,7,8,9,10 


.code
main PROC

mov ecx, lengthof array
mov esi, offset array
mov edi, offset array
add edi, 36
mov ecx, lengthof array
shr ecx, 1

L1: 
	mov eax, [esi]
	xchg [edi], eax
	mov [esi], eax
	add esi, type array
	sub edi, type array
	loop L1

call DumpRegs        ; Check registers via output
invoke ExitProcess,0

main ENDP
end main
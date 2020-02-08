; dec 12 2019
; lab 4 #5
; translate cpp to asm

.386
.model flat,stdcall
.stack 4096
INCLUDE Irvine32.inc


.data

.code
main PROC

; translating first part of if statement
L1:
	cmp eax, ebx
	jge L2
	jmp secondOR
L2:
	cmp ebx, ecx
	je ExecuteIF
	jmp secondOR

ExecuteIF:
	add eax, ebx
	add eax, ecx
	jmp exit1

; if first part is false, then check if the second part of the OR statement is true
secondOR:
	cmp eax, ecx
	je ExecuteIF
	jmp else1

; if none are true, execute else statement
else1:
	add ebx, eax
	add ebx, ecx

exit1:
	mov eax, 1
call DumpRegs        ; Check registers via output
invoke ExitProcess,0

main ENDP
end main
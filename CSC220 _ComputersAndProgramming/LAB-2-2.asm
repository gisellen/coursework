.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

INCLUDE Irvine32.inc

.data
array1 DWORD 11111h, 22222h, 33333h, 44444h
array2 WORD 0AEFFh, 23CAh, 1156h
.code
main PROC
;clear registers
mov eax, 0
mov ebx, 0
mov ecx, 0
mov edx, 0
mov esi, 0
mov edi, 0

; PART A
;adding arrays via brute force
mov eax, array1
add eax, DWORD PTR [array2]
add eax, DWORD PTR [array2+2]
add eax, DWORD PTR [array2+4]
add eax, [array1+4]
add eax, [array1+8]
add eax, [array1+12]
					; note to self: they add up to B8EC9
call DumpRegs		;Check registers via output

;clear registers
mov eax, 0
mov ebx, 0
mov ecx, 0
mov edx, 0
mov esi, 0
mov edi, 0

;PART B
;adding array via loops
mov eax, array1
mov ebx, 0			; ebx will be used to add the direct offset operands
mov ecx, 3
loop1:
	add eax, DWORD PTR[array2+ebx]
	add ebx,2
	loop loop1
mov ebx,4			; ebx will be used to add the direct offset operands
mov ecx, 3
loop2:
	add eax, [array1+ebx]
	add ebx, 4
	loop loop2
	


call DumpRegs		; Check registers via output
invoke ExitProcess,0

main ENDP
end main
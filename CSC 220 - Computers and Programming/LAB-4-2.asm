; dec 12 2019
; lab 4 #2

.386
.model flat,stdcall
.stack 4096
INCLUDE Irvine32.inc

.data
array DWORD 40
result DWORD lengthof array DUP(?)

.code
main PROC
mov eax, 40h
mov ecx, lengthof array
mov esi, offset array
mov edi, offset result

find:
	cmp [esi], eax
	add  esi, type array
	je set ;if 40 is found then go to "set" to put 40 in result
	loop find ;the label will loop until the end if it did not find 40 yet 
	jmp nfound ;if 40 is not found in array, then jump to nfound to set result to 0

set:
	mov ecx, lengthof array
set1:			;set1 will be looped to set all of result to 40
	mov [edi], eax
	add edi, type result
	loop set1	;set1 loops until it fills result
	jmp exit1 ;after setting result, then exit

nfound:
	mov ecx, lengthof array
nfound2:
	mov eax, 0
	mov [edi], eax
	add edi, type result
	loop nfound2	;nfound loops until it fills result to zero then exit

exit1:
	mov ecx,[edi]

call DumpRegs        ; Check registers via output
invoke ExitProcess,0

main ENDP
end main
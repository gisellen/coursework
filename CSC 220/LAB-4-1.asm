; dec 12 2019
; lab 4 #1

.386
.model flat,stdcall
.stack 4096
INCLUDE Irvine32.inc


.data
	array DWORD 10,20,30,40
.code
main PROC
	mov esi, offset array		;set indirect addressing
	mov ecx, lengthof array		;set loop counter
	mov edx, 40h
	
	L0:					  	;start of loop
		cmp [esi], edx				;compare
		je L1				  	;if 40 is found in [esi], then put 12345678h into eax in L1
		add esi, type array
		loop L0					;loops until 40 is found
		jne L2					;if 40 is not found, then put 87654321h into eax in L2


	L1:
		mov EAX, 12345678h
		jmp ex					;exit loop when finished

	L2:
		mov EBX, 87654321h

	ex:
		mov edx, 1
call DumpRegs        ; Check registers via output
invoke ExitProcess,0

main ENDP
end main
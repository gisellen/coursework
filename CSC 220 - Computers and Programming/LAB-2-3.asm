.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

INCLUDE Irvine32.inc

.data
array1 BYTE 10h, 20h, 30h, 40h
.code
main PROC
;clear registers
mov eax, 0
mov ebx, 0
mov ecx, 0
mov edx, 0
mov esi, 0
mov edi, 0

;move eax to array 20, 40, 10, 30	

mov esi, OFFSET array1
mov al, [esi+1]
mov al, [esi+3]
mov al, [esi]
mov al, [esi+2]
movzx eax, al



call DumpRegs		; Check registers via output
invoke ExitProcess,0

main ENDP
end main
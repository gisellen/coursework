; nov 1 2019
; lab 3 #3
; purpose: to add swap value using loops

.386
.model flat,stdcall
.stack 4096
INCLUDE Irvine32.inc

.data
array DWORD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
.code
main PROC
    mov ecx, 5 ; loop counter
    mov eax, 0 ; used to address the first element that will be exchanged
    mov ebx, 4 ; used to address the second element that will be exchanged
    ; both eax and ebx will be used in direct addressing
    L1: 
    mov edx, [array+eax]  ; edx will hold the array that was in the first element 
    xchg [array+(eax+4)], edx ; second element and edx will exchange
	mov [array+eax], edx

    ; the eax and ebx register will be increased by 8.  So when it is going to be directly addressed, 
	; eax and ebx will have the value of the next set of elements that will be exchanged
    add eax, 8 
    add ebx, 8
    Loop L1

call DumpRegs        ; Check registers via output
invoke ExitProcess,0

main ENDP
end main
; dec 12 2019
; lab 4 #4
; translate cpp to asm

.386
.model flat,stdcall
.stack 4096
INCLUDE Irvine32.inc


.data
x dword 10
y dword 20
z dword 20

.code
main PROC

mov eax, x
L1:				;first if
	cmp eax, y
	jl L2
	jmp else1	;go to else if, if false
L2:				;first if (if L1 is true)
	mov eax, y
	cmp eax, z
	je first
	jmp else1	;go to else-if if false

first:
	inc y
	jmp ex		;go to exist

else1:
	mov eax, x
	add eax, y
	cmp eax, z
	jl second	;if first OR statement is true then execute else-if statement
	jmp else1_1	;go to the second part of the else if statement if first part is false

else1_1:
	mov eax, z
	add eax, y
	cmp eax, x
	jl second	;if true then execute else if statement
	jmp third	;if not true then execute else statement

second:
	inc z
	inc x
	jmp ex

third: 
	inc z
	inc x
	inc y

ex:
	mov eax, 1

call DumpRegs        ; Check registers via output
invoke ExitProcess,0

main ENDP
end main
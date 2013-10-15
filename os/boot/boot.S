[BITS 16]
[ORG 0x7c00]

MOV SI, hello_string
CALL print_string
JMP $

print_character: 
	MOV AH, 0x0e
	MOV BH, 0x00
	MOV BL, 0x07

	INT 0x10
	RET

print_string:
next_char: 
	MOV AL, [SI]
	INC SI
	OR AL, AL
	JZ exit_fun
	CALL print_character
	JMP	next_char
exit_fun:
	RET

hello_string db 'Hello World', 0

TIMES 510 - ($ - $$) db 0
DW	0xAA55

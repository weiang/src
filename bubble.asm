assume cs:code, ds:data, ss:stack

;####################################
;#                                  #  
;#            Data Segment          #
;#                                  #	
;####################################

data segment

  	sort_size  	dw 5
 	sort_array	dw 200 dup(0)
	i_prompt	db "Please enter array's size:$"
	o_prompt	db "Sorted result:$"
	str		db 20 dup(?) 				; input buffer
	base		db 10	
data ends

stack segment

 	db 200 dup(0)
	stack_top:

stack ends

code segment
	_start:
	main PROC
		mov ax, data
		mov ds, ax
		mov ax, stack
		mov ss, ax
		mov sp, stack_top
		mov bp, sp
		call get_input
		mov bx, offset sort_size
		mov cx, ds:[bx]			; Get the size of the array to be sorted
		mov bx, offset sort_array	; Get the array's address 	
		push cx
		push bx
		call bubble
		call print_result	
		mov  ax, 40cch
		int  21h		

	main ENDP

		
	; bubble(int *arr, int n)
	
	bubble PROC
		push bp
		mov bp, sp
		push bx
		push cx
		push dx
		push di
		push si				; Save registers
	 
		mov bx, ss:[bp + 4]	; Get arr
		mov ax, ss:[bp + 6]	; Get n
		sub ax, 1 	
		mov cx, 2
		mul word ptr cx
		mov si, 0			; si = 0	
	
	out_loop:
		cmp si, ax
		jz  bubble_exit
		mov cx, [bx + si]	; cx = arr[i]
		mov di, si
		add di,	2			; di = si + 2	

	inner_loop:
	 	cmp di, ax
		ja  out_inc	
		mov dx, [bx + di] 
		cmp cx, dx
		jna in_inc
	swap:	mov [bx + di], cx	; 
		mov cx, dx
	in_inc:	add di, 2
		jmp inner_loop
	out_inc:mov [bx + si], cx
		add si, 2
		jmp out_loop
	
	bubble_exit:	
		mov sp, bp
		mov bx, [bp - 2]
		mov cx, [bp - 4]
		mov dx, [bp - 6]
		mov di, [bp - 8]
		mov si, [bp - 10]
		
		ret

	bubble ENDP
	
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;
	;	 void get_input(void) 
	; 
	; Get input array to be sorted, store it in sort_array
	; Count the size of the input array, store it in sort_size
	;
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	get_input PROC
		push bp
		mov bp, sp
		push dx
		push bx
		push cx

		mov ah, 9
		mov dx, offset i_prompt
		int 21h			; output prompt on the screen
		
		; Get array's size, store it in sort_size
		call get_num
		mov bx, offset sort_size
		mov [bx], ax		; Store the array's size in sort_size
		
		mov cx, ax
		mov si, offset sort_array
	s:	call get_num
		mov ds:[si], ax
		add si, 2
		loop s	
		
		mov sp, bp
		mov dx, [bp - 2]
		mov bx, [bp - 4]
		mov cx, [bp - 6]
		ret
	
	get_input ENDP 

	;
	; int get_num(void)
	; return value stored in ax
	;
	
	get_num PROC
		push bp
		mov bp, sp
		push bx
	
		mov bx, offset str	; Input buffer
	get_char:
		mov ah, 1
		int 21h			; get input char	
		cmp al, ' '		; if [al] == ' '
		jz str2n		
		cmp al, 0dh 		; if [al] == '\n'
		jz str2n
		cmp al, '0'
		jb  get_char		; if [al] < 0
		cmp al, '9'
		ja  get_char		; if [al] > 9
		mov [bx], al
		inc bx
		jmp get_char
		

	str2n:	mov ax, offset str
		sub bx, ax
		push bx			; string's size
		push ax			; string's address
		call atoi
		
		mov sp, bp
		mov bx, [bp - 2]		
		pop bp
		ret
	
	get_num ENDP


	atoi PROC
		push bp
		mov bp, sp
		push di
		push cx
		push bx
		
		mov di, [bp + 4]
		mov bx, [bp + 6]
		add bx, di

		mov ax, 0
	_lp:	cmp di, bx
		jnb result 
		mov cx, 10
		mul cx
		mov cl, [di]
		sub cl, '0'
		mov ch, 0
		add ax, cx
		inc di
		jmp _lp
	
	result: 		
		mov sp, bp
		mov di, [bp - 2]
		mov cx, [bp - 4]
		mov bx, [bp - 6]
		pop bp

		ret
	atoi ENDP		





	;
	;	void print_result(void)
	;
	print_result PROC
		push bp
		mov bp, sp
		push bx
		push cx
		push dx
	
		mov ah, 9
		mov dx, offset o_prompt
		int 21h

		mov bx, offset sort_array
		mov cx, sort_size
	pr_loop:mov dx, [bx]
		push dx
		call itoa
		add bx, 2
		mov ah, 6
		mov dl, ' '
		int 21h
		loop pr_loop	

		mov ah, 6
		mov dl, 0dh
		int 21h
	
		mov sp, bp
		mov bx, [bp - 2]
		mov cx, [bp - 4]
		mov dx, [bp - 6]
		pop bp
		ret
				
	print_result ENDP
		
 	;
	;	void itoa(int n)
	;
	itoa PROC
		push bp
		mov bp, sp
		push bx
		push dx
		
		mov ax, [bp + 4]	; Get n
		mov bx, offset str
		
	back:	div base
		add ah, '0'
		mov [bx], ah
		mov ah, 0
		cmp al, 0
		je next
		inc bx
		jmp back
	next:	mov ax, offset str
		cmp bx, ax
		jb finish
		mov ah, 6
		mov dl, [bx]
		int 21h	
		dec bx
		jmp next
	finish:
		mov sp, bp
		mov bx, [bp - 2]
		mov dx, [bp - 4]		
		pop bp
		ret			
		
	itoa ENDP
code ends		

end _start

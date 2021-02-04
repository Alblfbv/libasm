section .text
	global ft_strcpy

ft_strcpy:
	
	; prologue
	push rbp
	mov rbp, rsp
	
	; clear reg tmp and set return value
	xor bl, bl
	xor rax, rax
	mov rax, rdi

_loop:
	mov bl, [rsi]
	mov [rdi], bl
	inc rsi
	inc rdi
	cmp byte [rsi], 0x0
	jne _loop

	; copy null char
	mov bl, [rsi]
	mov [rdi], bl

	; epilogue
	leave
	ret

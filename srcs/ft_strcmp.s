section .text
	global ft_strcmp

ft_strcmp:
	
	;prologue
	push rbp
	mov rbp, rsp

_loop:
	xor al, al
	mov al, [rdi]
	cmp al, [rsi]
	jne _check_type
	cmp byte [rdi], 0x0
	je _check_type
	inc rsi
	inc rdi
	jmp _loop


_check_type:
	sub al, [rsi]
	test al, al
	js _negative
	jmp _positive

_positive:
	xor rax, rax
	mov al, [rdi]
	sub al, [rsi]
	jmp _end

_negative:
	xor rax, rax
	not eax
	mov al, [rdi]
	sub al, [rsi]

_end:
	;epilogue
	leave
	ret

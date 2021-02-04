section .text
	global ft_read
	extern __errno_location

ft_read:

	;prologue
	push rbp
	mov rbp, rsp

	mov rax, 0x0
	syscall

	test rax, rax
	js _set_error
	jmp _end

_set_error:
	neg rax							; 2's complement to get positive error code
	mov rdi, rax
	call __errno_location WRT ..plt
	xor rax, rax
	not rax

_end:
	;epilogue
	leave
	ret

section .text
	global ft_write
	extern __errno_location

ft_write:
	
	;prologue
	push rbp
	mov rbp, rsp

	mov rax, 0x1					; write syscall code
	syscall							; system interrupt (msg length already in rdx)

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

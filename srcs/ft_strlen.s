section .text
    global ft_strlen

ft_strlen:

	; prologue
    push rbp		; copies rbp value on stack AND decreases rsp by 4
    mov rbp, rsp	; rsp is at top of stack (RIP and RBP values) which is new RBP value for this function
   
	; actual code
	xor rax, rax

_loop:
	cmp byte [rdi + rax], 0x0
	je _epilogue
	inc rax
	jne _loop

_epilogue:
	; epilogue
	leave			; mov rsp, rbp AND pop rbp (pop which increases RSP by 4 again)
	ret				; pop eip + jmp eip

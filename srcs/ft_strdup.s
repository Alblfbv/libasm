section .text
	global ft_strdup

ft_strdup:
	
	;prologue
	push rbp
	mov rbp, rsp

	extern malloc
	xor rcx, rcx
	xor rbx, rbx
	cmp byte [rdi + rcx], 0x0
	je _malloc
	
_loop:
	inc rcx
	cmp byte [rdi + rcx], 0x0
	jne _loop

_malloc:
	push rdi
	xor rdi, rdi
	inc rcx
	mov rdi, rcx
	push rcx
	call malloc WRT ..plt
	pop rcx
	pop rdi

_dup:
	xor rdx, rdx
	mov dl, [rdi + rbx]
	mov [rax + rbx], dl
	inc rbx
	cmp rbx, rcx
	jne _dup

	;epilogue
	leave
	ret

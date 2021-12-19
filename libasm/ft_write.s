section .text
	global _ft_write
	extern ___error
_ft_write:
	cmp rdi, 0
	jl .error
	cmp rdx, 0
	jl .error
	mov rax, 0x2000004
	syscall
	jc .error
	ret
.error:
	push	rax
	call	___error
	pop		r9
	mov		[rax], r9
	mov		rax, -1
	ret

section .text
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc

global _ft_strdup
_ft_strdup:
	mov rax, 0
	push rdi;
	call _ft_strlen
	add rax, 1
	mov rdi, rax
	call _malloc
	cmp rax, 0
	jz .fin
	mov rdi, rax
	pop rsi
	call _ft_strcpy
	ret
.fin:
	pop rdi
	ret

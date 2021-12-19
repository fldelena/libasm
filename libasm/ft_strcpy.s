section .text
global _ft_strcpy
_ft_strcpy:
	mov rax, 0
.loop:
	mov dl, byte[rsi + rax]
	mov byte[rdi + rax], dl
	cmp byte[rdi + rax], 0
	jz .fin
	inc rax
	jmp .loop
.fin:
	mov rax, 0
	mov rax, rdi
	ret

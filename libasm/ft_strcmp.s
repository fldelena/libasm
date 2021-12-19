section .text

global _ft_strcmp
_ft_strcmp:
	mov rax, 0
	mov rdx, 0
	mov rcx, 0
.loop:
	mov dl, byte[rdi + rax]
	mov cl, byte[rsi + rax]
	cmp dl, 0
	jz .end
	cmp cl, 0
	jz .end
	cmp dl, cl
	jne .end
	inc rax
	jmp .loop
.end:
	mov rax, rdx
	sub rax, rcx
	ret

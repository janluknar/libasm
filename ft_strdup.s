			section	.text
			extern	_malloc
			global	_ft_strdup
			extern	_ft_strlen
			extern  _ft_strcpy

_ft_strdup:
			push rdi			;str saved in stack
			call _ft_strlen		;get length
			mov rdi, rax		;save str length for malloc
			inc rdi				;+1 for null terminated string
			call _malloc		;malloc(rdi)
			cmp rax, 0			;return NULL if failed to allocate
			jz error
			mov rdi, rax		;save allocated string in rdi
			pop rsi				;get string from stack saved in rsi for use in strcpy
			call _ft_strcpy
			mov rax, rdi		;save return from strcpy in rax
			ret
error:
			xor rax, rax
			ret

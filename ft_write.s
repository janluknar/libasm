			section	.text
			global	_ft_write
			extern	___error

_ft_write:
			mov	rax, 0x2000004		;store write syscall
			syscall
			jc error
			ret
error:
			mov rdx, rax			;move errno in negative to rdx
			push rdx				;push rdx because stack pointer changes
			call ___error			;call for error
			pop	rdx					;retrieve rdx
			mov [rax], rdx			;store error in pointer to errno
			mov rax, -1				;store -1 return value from write locally
			ret
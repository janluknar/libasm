			section	.text
			global	_ft_read
			extern	___error

_ft_read:
			mov	rax, 0x2000003		;store read syscall
			syscall
			jc error
			ret
error:
			mov rdx, rax			;move errno in negative to rdx
			push rdx				;push rdx because stack pointer changes
			call ___error			;call for error
			pop rdx					;retrieve rdx
			mov [rax], rdx			;store error in pointer to errno
			mov rax, -1				;store -1 return value from write locally
			ret
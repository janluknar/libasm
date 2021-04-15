			section	.text
			global	_ft_strcpy

_ft_strcpy:
			xor		rbx, rbx			; i = 0
			xor		rsi, 0
			jz		done
			jmp		copy
increment:
			inc		rbx					; i++
copy:
			mov		dl, BYTE [rsi + rbx]
			mov		BYTE [rdi + rbx], dl
			cmp		dl, 0				; src[i] == 0
			jne		increment
done:
			mov		rax, rdi
			ret							; return i
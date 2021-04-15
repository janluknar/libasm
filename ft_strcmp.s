			section .text
			global	_ft_strcmp

_ft_strcmp:
			xor		rax, rax	; main register set to 0
			xor		rbx, rbx	; i = 0;
			jmp		compare
compare:
			mov		al, BYTE [rdi]
			mov		bl, BYTE [rsi]
			cmp		al, 0	
			je		done		; checking if we are at the end of dest
			cmp		bl, 0
			je		done		; checking if we are at the end of src
			cmp		al, bl		; comparing characters that are being pointed at
			jne		done
			inc		rdi			; increment pointer
			inc		rsi			; increment pointer
			jmp		compare
done:
			mov		al, BYTE [rdi]
			movzx	rax, al
			movzx	rbx, bl
			sub		rax, rbx
			ret

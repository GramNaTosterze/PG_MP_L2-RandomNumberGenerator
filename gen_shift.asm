global _gen_reg_shift

section .text

_gen_reg_shift:
	push 	rsi
	push	rdx
	push	rbx
	mov		eax, [b]
	
	; tworzenie zmiennej zwracanej
	mov		esi, q
	mov		ecx,  32
	foreach_bit:
	
	
	
	inc		esi
	loop foreach_bit
	
	
	
	; zmiana b
	mov		ecx, [b]
	shl		ecx, 32 - 7
	mov		[b], ecx
	pop		rbx
	pop 	rdx
	pop		rsi
	ret
	
section .data
	b:		dd	1001011b
	p:		db	7
	q:		db	3

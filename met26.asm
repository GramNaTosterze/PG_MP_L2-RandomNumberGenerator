global _rol

section .data

section .bss

section .text

_rol:
	push rbp
	mov rbp, rsp
	mov eax, [rbp + 8]
	mov ecx, [rbp + 12]
	
	rol eax, 2
	
	pop rbp

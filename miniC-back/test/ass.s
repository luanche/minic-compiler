	.file	"hello.c"
	.intel_syntax noprefix
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	push	ebp
	mov	ebp, esp
	sub	esp, 32
	mov	DWORD PTR [ebp-4], 0
	jmp	.L2
.L3:
	mov	eax, DWORD PTR [ebp-4]
	mov	edx, DWORD PTR [ebp-4]
	mov	DWORD PTR [ebp-24+eax*4], edx
	add	DWORD PTR [ebp-4], 1
.L2:
	cmp	DWORD PTR [ebp-4], 4
	jle	.L3
	mov	eax, 0
	leave
	ret

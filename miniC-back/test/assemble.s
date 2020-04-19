	.file	"hello.c"
	.intel_syntax noprefix
	.text
	.globl main
	.type	main, @function
main:
	push ebp
	mov ebp,esp
	and esp, -16
	sub esp,48
	mov eax,0
	mov DWORD PTR[ebp-24],eax
L2:
	mov eax,DWORD PTR [ebp-24]
	mov ebx,5
	mov ecx,0
	cmp eax,ebx
	setl cl
	mov DWORD PTR[ebp-28],ecx
	mov eax,DWORD PTR [ebp-28]
	cmp eax,0
	je L3
	mov eax,DWORD PTR [ebp-24]
	mov DWORD PTR[ebp-20],eax
	mov eax,0
	mov DWORD PTR[ebp-32],eax
	mov eax,DWORD PTR [ebp-24]
	mov DWORD PTR[ebp-32],eax
	mov eax,DWORD PTR [ebp-24]
	mov ebx,1
	add eax,ebx
	mov DWORD PTR[ebp-24],eax
	jmp L2
L3:
	mov eax,0
	jmp L1
L1:
	mov esp,ebp
	pop ebp
	ret

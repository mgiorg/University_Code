.globl f
f:
	pushl %edi
	pushl %esi
	pushl %ebx
	pushl %ebp
	subl $4, %esp

	movl 24(%esp), %edi
	movl 28(%esp), %esi
	xorl %ebx, %ebx
	xorl %ebp, %ebp

L:
	cmpl %esi, %ebx
	jae E
	movl (%edi, %ebx, 4), %ecx
	movl %ecx, (%esp)
	call is_negative
	addl %eax, %ebp
	incl %ebx
	jmp L
E:
	movl %ebp, %eax
	addl $4, %esp
	popl %ebp
	popl %ebx
	popl %esi
	popl %edi
	ret


.globl g
g:	
	pushl %ebx
	pushl %edi
	pushl %esi
	subl $8, %esp

	movl 24(%esp), %edi
	movl 28(%esp), %esi
	movl $1, %ebx

L:  
	cmpl %esi, %ebx
	jae E2
	movl -4(%edi, %ebx, 4), %edx
	movl (%edi, %ebx, 4), %edx
	movl %ecx, (%esp)
	movl %edx, 4(%esp)
	call ordinati
	testl %eax, %eax
	je E1
	incl %ebx
	jmp L
E1:
	xorl %eax, %eax
	jmp E
E2:
	movl $1, %eax
E:
	addl $8, %esp
	popl %esi
	popl %edi
	popl %ebx
	ret
	
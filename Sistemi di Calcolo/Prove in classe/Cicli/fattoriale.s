.globl fact

fact:
	movl $1, %eax
	movl $2, %ecx

L:
	cmpl 4(%esp), %ecx
	ja E

	imull %ecx, %eax
	incl %ecx
	jmp L
E:
	ret

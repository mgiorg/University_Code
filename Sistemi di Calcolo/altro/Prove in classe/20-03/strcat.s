.globl my_strcat

my_strcat:
	movl 4(%esp), %edx
	movl 8(%esp), %ecx
L1:
	cmpb $0, (%edx)
	je E1
	incl %edx
	jmp L1
E1:
L2:
	movb (%ecx), %al
	movb %al, (%edx)
	testb %al, %al
	je E2
	incl %edx
	incl %ecx
	jmp L2
E2:
	movl 4(%esp), %eax
	ret

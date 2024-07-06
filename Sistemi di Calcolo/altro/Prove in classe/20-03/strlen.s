.globl my_strlen

my_strlen:
	movl 4(%esp), %ecx
	movl $0, %eax
L:
	movb (%ecx), %dl
	incl %ecx
	cmpb $0, %dl
	je E
	incl %eax
	jmp L
E:
	ret
	
# scrivere la soluzione qui...
.globl my_strcmp 

my_strcmp:
	movl 4(%esp), %ecx
	movl 8(%esp), %edx
L:
	movb (%ecx), %al
	cmpb $0, %al
	je E
	cmpb %al, (%edx)
	jne E
	incl %ecx
	incl %edx
	jmp L
E:
	movb (%ecx), %al
	subb (%edx), %al
	ret

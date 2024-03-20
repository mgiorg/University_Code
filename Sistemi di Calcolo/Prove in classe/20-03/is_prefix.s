.globl is_prefix

is_prefix:
	movl 4(%esp), %ecx
	movl 8(%esp), %edx
L:
	movb (%ecx), %al
	cmpb $0, %al
	je E
	cmpb $0, (%edx)
	je E
	cmpb %al, (%edx)
	jne E
	
	incl %ecx
	incl %edx
	jmp L
E:
	testb %al, %al
	jne E2
	movl $1, %eax
	jmp F

E2:
	movl $0, %eax
F:
	ret


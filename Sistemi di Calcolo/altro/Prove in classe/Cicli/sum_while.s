.globl sumwhile

sumwhile:
	xorl %eax, %eax
	movl 4(%esp), %ecx
	movl 8(%esp), %edx

L:
	cmpl $0, %ecx
	jle E
	cmpl $0, %edx 
	jle F

	addl %ecx, %eax 
	subl $1, %edx 

F:
	subl $1, %ecx 
	jmp L 

E:
	ret


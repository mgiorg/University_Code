.globl times2

times2:
	movl 4(%esp), %eax
	movw (%eax), %cx
	imulw $2, %cx
	movw %cx, (%eax)
	ret
	
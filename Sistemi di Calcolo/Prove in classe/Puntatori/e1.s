.globl times2_int

times2_int:
	movl 4(%esp), %eax
	movw (%eax), %cx
	imulw $2, %cx
	movw %cx, (%eax)
	ret
	
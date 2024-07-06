.globl swap

swap:
	movl 4(%esp), %eax
	movl 8(%esp), %ecx

	movb (%eax), %dl
	movb (%ecx), %dh

	movb %dh, (%eax)
	movb %dl, (%ecx)

	ret
	
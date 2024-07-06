.globl swap_short

swap_short:
	movl 4(%esp), %eax
	movw (%eax), %ax

	movl 8(%esp), %ecx
	movw (%ecx), %cx

	movl 4(%esp), %edx
	movw %cx, (%edx)

	movl 8(%esp), %edx
	movw %ax, (%edx)

	ret

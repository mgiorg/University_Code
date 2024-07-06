# ciclo while
.globl sum

sum:
	xorl %eax, %eax		# azzera eax
	movl 4(%esp), %ecx

L:
	testl %ecx, %ecx 	# == cmpl $0, %ecx
	jle E 	# jump less or equal

	addl %ecx, %eax
	decl %ecx
	jmp L

E:
	ret

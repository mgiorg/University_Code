# scrivere la soluzione qui...
.globl find

find:
	movl 4(%esp), %ecx 		# puntatore al primo elemento dell'array 
	movl 8(%esp), %edx 		# dimensione array
	movl 12(%esp), %eax 	# elemento da trovare (x)
	decl %edx # n--
L:
	testl %edx, %edx
	jl R0
	cmp %eax, (%ecx, %edx, 4)  #if (a == c[d])
	je R1
	decl %edx	# n--
	jmp L

R0:
	movl $0, %eax
	jmp E
R1:
	movl $1, %eax
	jmp E
E:
	ret

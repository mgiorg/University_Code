# scrivere la soluzione qui...
.globl fib
fib:

	pushl %edi				#prologo
	pushl %ebx
	subl $4, %esp

	movl 16(%esp), %edi
	movl $1, %eax
	cmpl $2, %edi
	jl E
	decl %edi
	movl %edi, (%esp)
	call fib
	movl %eax, %ebx
	decl %edi
	movl %edi, (%esp)
	call fib
	addl %ebx, %eax

E:	
	addl $4, %esp           # epilogo
    popl %ebx
    popl %edi
	ret

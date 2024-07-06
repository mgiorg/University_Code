# scrivere la soluzione qui...
.globl counteq
counteq:

    pushl %edi
    pushl %esi
    pushl %ebx

    movl 16(%esp), %edi
    movl 20(%esp), %esi
    movl 24(%esp), %edx
    xorl %eax, %eax
    decl %edx    

L:  testl %edx, %edx 
    jl E 
    movw (%edi, %edx, 2), %cx
    movw (%esi, %edx, 2), %bx
    cmpw %cx, %bx
    sete %cl     
    movsbl %cl, %ecx      
    addl %ecx, %eax
    decl %edx
    jmp L
E:
    popl %ebx
	popl %esi
    popl %edi

    ret 

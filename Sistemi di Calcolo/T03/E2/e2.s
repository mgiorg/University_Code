# Inserire qui la soluzione
.globl fib

fib:
    xorl %edx, %edx
    movl $1, %eax
    movl 4(%esp), %ecx
    testl %ecx, %ecx
    jne F1
    movl %edx, %eax
    jmp E
F1:
    cmpl $1, %ecx
    jne F2

    jmp E
F2:
L:
    cmpl $1, %ecx
    jbe E
    decl %ecx
    addl %eax, %edx
    addl %eax, %edx
    negl %eax
    addl %edx, %eax
    subl %eax, %edx
    jmp L
E:
    ret
    
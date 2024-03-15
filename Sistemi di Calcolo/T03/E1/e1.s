# Inserire qui la soluzione
.globl min

min:
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
    movl 12(%esp), %edx

    cmp %ecx, %eax
    jge CD
    cmp %edx, %eax
    jge D
    jmp E

CD:
    cmp %edx, %ecx
    jge D
    movl %ecx, %eax 
    jmp E

D:
    movl %edx, %eax
    jmp E

E:
    ret

# scrivere la soluzione qui...
.global clone

clone: 

    pushl %esi                         # prologo
    pushl %edi
    pushl %ebx
    subl $12, %esp

    movl 28(%esp),%esi                 # const void* si = src;
    movl 32(%esp),%ebx                 # int b = n;
    movl %ebx, (%esp)                  #                  b;
    call malloc                        # void* a = malloc(|)
    movl %eax, %edi                    # void* di = a
    xorl %eax, %eax                    # a = 0;
    testl %edi, %edi                   # if (di==0)
    je E                               #    goto E;
    movl %edi, (%esp)                  #         di
    movl %esi, 4(%esp)                 #         |   si
    movl %ebx, 8(%esp)                 #         |   |   b
    call memcpy                        # memcpy( | , |  ,| );
    movl %edi, %eax                    # a = di;
E:
    addl $12, %esp                     # epilogo
    popl %ebx
    popl %edi
    popl %esi
    ret 
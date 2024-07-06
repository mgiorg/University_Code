.section .data

.section .bss

.section .text
.global deleetify

deleetify:
    pushl %ebp                # Salva il valore di ebp corrente
    movl %esp, %ebp           # Imposta il nuovo valore di ebp
    pushl %ebx                # Salva il valore di ebx
    pushl %esi                # Salva il valore di esi
    pushl %edi                # Salva il valore di edi

    movl 8(%ebp), %edi        # %edi = v (primo parametro)
    movl 12(%ebp), %ecx       # %ecx = len (secondo parametro)

    movl %ecx, %eax           # %eax = len
    imull $1, %eax            # Moltiplica per sizeof(unsigned char) (che è 1)
    pushl %eax                # Passa len a malloc
    call malloc               # Chiama malloc
    addl $4, %esp             # Pulisce lo stack
    movl %eax, %ebx           # %ebx = res

    xorl %edx, %edx           # %edx = i = 0

.L1:
    cmpl %ecx, %edx           # Confronta i con len
    jge .L2                   # Se i >= len, esce dal ciclo

    movzbl (%edi, %edx, 1), %eax  # %eax = v[i]
    cmpl $57, %eax            # Confronta v[i] con 57
    jle .L3                   # Se v[i] <= 57, chiama deleetify_helper

    movb %al, (%ebx, %edx, 1) # res[i] = v[i]
    jmp .L4                   # Salta alla fine del ciclo

.L3:
    pushl %eax                # Passa v[i] a deleetify_helper
    call deleetify_helper     # Chiama deleetify_helper
    addl $4, %esp             # Pulisce lo stack
    movb %al, (%ebx, %edx, 1) # res[i] = valore ritornato da deleetify_helper

.L4:
    incl %edx                 # i++
    jmp .L1                   # Ripeti il ciclo

.L2:
    movl %ebx, %eax           # Imposta il valore di ritorno (res)
    
    popl %edi                 # Ripristina il valore di edi
    popl %esi                 # Ripristina il valore di esi
    popl %ebx                 # Ripristina il valore di ebx
    movl %ebp, %esp           # Ripristina il valore di esp
    popl %ebp                 # Ripristina il valore di ebp
    ret                       # Ritorna dalla funzione

    
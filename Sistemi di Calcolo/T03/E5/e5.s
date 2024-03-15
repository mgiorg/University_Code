.globl f

f:									# int f(int x, int y){
	movl 4(%esp), %eax
	movl 8(%esp), %ecx
	movl %eax, %edx					# int z = x;
	addl %edx, %eax					# z += y;
	cmpl $15, %edx					# if (z > 15) goto E;
	ja E
	movl $0, %eax					# return 0;
	ret
	
E: 	movl $1, %eax					# return 1;
	ret

	.globl f

f:                                   # int f(int x, int y){
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
    movl %eax, %edx                  # int z = x;
    addl %ecx, %edx  # errore 1      # z += y;
    cmpl $15, %edx                   # if (z > 15) goto E;
    jg E             # errore 2            
    movl $0, %eax                    # return 0;
    ret
    
E:  movl $1, %eax                    # return 1;
    ret

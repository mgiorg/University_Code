.globl _f
_f: 
movl $2, %eax
addl $3, %eax
movl $4, %ecx
subl $2, %ecx
imull %ecx, %eax
movl $2, %edx
addl $3, %edx
subl %edx, %eax
imull $3, %eax
incl %eax
ret 


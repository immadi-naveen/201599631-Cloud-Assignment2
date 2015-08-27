.file "sum.c"
.section .rodata
.LC0:
.string "%d"
.text
.globl main
.type main, @function
main:
.LFB0:
.cfi_startproc
pushq %rbp
.cfi_def_cfa_offset 16
.cfi_offset 6, -16
movl %rsp, %rbp
.cfi_def_cfa_register 6
andl $-16, %rsp
subq $32, %rsp
movl $1, 20(%esp)
movl $2, 24(%esp)
movl 24(%esp), %eax
movl 20(%esp), %edx
addl %edx, %eax
movl %eax, 28(%esp)
movl 28(%esp), %eax
movl %eax, 4(%esp)
movl $.LC0, (%esp)
call printf
leave
.cfi_restore 6
.cfi_def_cfa 7 5
ret
.cfi_endproc
.LFE0:
.size main, .-main
.ident "GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
.section .note.GNU-stack,"",@progbits

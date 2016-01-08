	.file	"spawnshell_asm.c"
	.section	.rodata
.LC0:
	.string	"/bin/sh"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	$.LC0, -16(%rbp)
	movq	$0, -8(%rbp)
#APP
# 18 "spawnshell_asm.c" 1
	mov $0x3b,%eax;mov -0x10(%rbp), %rdi;lea -0x10(%rbp), %rsi;mov $0x0, %rdx;syscall; 	## Assembly code written in corresponding c file.
# 0 "" 2
#NO_APP
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits

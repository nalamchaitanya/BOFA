	.file	"spawnshell.c"
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
	subq	$16, %rsp			## Allocating space for name array of char ptrs.
	movq	$.LC0, -16(%rbp)	## moving exectable name to first value of array
	movq	$0, -8(%rbp)		## Then arguments (NULL) ptr as no arguments.
	movq	-16(%rbp), %rax
	leaq	-16(%rbp), %rcx
	movl	$0, %edx			## No environment variables so NULL, last argmnt
	movq	%rcx, %rsi			## Address of the array of strings(char** name)
	movq	%rax, %rdi			## Address of the string i.e $.LC0("/bin/sh")
	call	execve				## calling the function.
	movl	$0, %edi
	call	exit
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits

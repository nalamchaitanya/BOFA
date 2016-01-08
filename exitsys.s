	.file	"exitsys.c"
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
	movl	$0, %edi		## Two points to note put the error code or rather
	call	exit			## say the one and only argument to %rdi (here it is
							## %edi because it is optimized as we know that upper
							## half of rdi is already zero) and then call exit
							## which eventually calls system call with correspon
							## -ding system call number to %rax.
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits

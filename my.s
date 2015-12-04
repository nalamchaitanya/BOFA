	.file	"1.c"
	.text
	.globl	function
	.type	function, @function
function:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -52(%rbp)
	movl	%esi, -56(%rbp)
	movl	%edx, -60(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movb	$5, -32(%rbp)
	leaq	-32(%rbp), %rax
	addq	$36, %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movzbl	(%rax), %eax
	addl	$7, %eax
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movb	%dl, (%rax)
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L2
	call	__stack_chk_fail
.L2:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	function, .-function
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$3, %edx
	movl	$2, %esi
	movl	$1, %edi
	call	function
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits

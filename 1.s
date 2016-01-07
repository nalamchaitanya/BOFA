	.file	"1.c"
	.section	.rodata
.LC0:
	.string	"%x\n"
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
	subq	$80, %rsp					## Allocating space on the stack for the local variables in the function.
	movl	%edi, -68(%rbp)
	movl	%esi, -72(%rbp)
	movl	%edx, -76(%rbp)
	movq	%fs:40, %rax				## Filling the canary.
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movb	$5, -48(%rbp)				## From this instructions we can infer that the bufffer1 is at 48bytes below
	movb	$6, -32(%rbp)				## rbp and buffer2 is 32 bytes below rbp. These buffers are rounded off to 16 bytes
	leaq	-48(%rbp), %rax				## while allocating space on the stack.
	addq	$56, %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi					## This is for printing the current return value of the function.
	movl	$0, %eax
	call	printf
	movq	-56(%rbp), %rax				## Getting the address of the 'current return address' on the stack to rax.
	movl	(%rax), %eax				## From the address getting the return address.
	leal	8(%rax), %edx				## Adding 8 to the return address.
	movq	-56(%rbp), %rax
	movl	%edx, (%rax)				## Storing new return address to the stack.
	movq	-8(%rbp), %rax				## This code is called canary to check whether any buffer overflow happend or not overwriting the
	xorq	%fs:40, %rax				## return address. The old value of canary is in %fs:40 which has to be checked.
	je	.L2								## if matches then leave the function
	call	__stack_chk_fail			## if not call the function for stack checking failed.
.L2:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	function, .-function
	.section	.rodata
.LC1:
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
	movl	$1, -4(%rbp)			## This is the instruction that is skipped from the function there by retaining the old value in
	movl	-4(%rbp), %eax			## the variable x which is in -4(%rbp).
	movl	%eax, %esi
	movl	$.LC1, %edi
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

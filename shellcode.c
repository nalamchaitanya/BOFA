#include <stdio.h>

void main()
{
__asm__ (
		"jmp .+0x29;"
		"pop %rbx;"
		"mov %rbx, 0x8(%rbx);"
		"xorq %rax, %rax;"
		"movb %ah, 0x7(%rbx);"
		"movq %rax, 0x10(%rbx);"
		"mov %eax, %edx;"
		"movb $0x3b, %al;"
		"mov 0x8(%rbx), %rdi;"
		"lea 0x8(%rbx), %rsi;"
		"syscall;"
		"xorq %rcx, %rcx;"
		"mov %rcx, %rdi;"
		"movb $0x3c, %al;"
		"syscall;"
		"call .-0x27;"
		".string \"/bin/sh                 \";"
);
}

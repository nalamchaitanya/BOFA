#include <stdio.h>

void main()
{
	char* name[2] = {"/bin/sh",NULL};
// __asm__ (
// 		"jmp .+0x21;"
// 		"pop %rsi;"
// 		"movb $0x0, 0x7(%rsi);"
// 		"movq %rsi, 0x8(%rsi);"
// 		"movl $0x0, 0x10(%rsi);"
// 		"mov $0x3b, %eax;"
// 		"mov 0x8(%rsi), %rdi;"
// 		"lea 0x8(%rsi), %rsi;"
// 		"syscall;"
// 		"call .-0x1f;"
// 		".string \"/bin/sh                 \";"
// );
	asm (
		"mov $0x3b,%eax;"
		"mov -0x10(%rbp), %rdi;"
		"lea -0x10(%rbp), %rsi;"
		"syscall;"
	);
}

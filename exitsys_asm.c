#include <stdio.h>

void main()
{
	asm (
		"mov $0x0, %rdi;"
		"mov $0x3c, %eax;"
		"syscall;"
	);
}

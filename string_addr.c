#include <stdio.h>

void* function()
{
__asm__ (
		"jmp .+0x5;"
		"pop %rax;"
		"leaveq;"
		"retq;"
		"call .-0x3;"
		".string \"/bin/sh\";"
);
}

void main()
{
	printf("%p\n",function());
}

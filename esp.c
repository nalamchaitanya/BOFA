#include <stdio.h>

unsigned long get_rsp()
{
	__asm__
	(
		"nop;"
		"mov %rsp,%rax;"
	);
}

void main()
{
	printf("0x%lx\n",get_rsp());
}

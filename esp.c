#include <stdio.h>

unsigned int get_rsp()
{
	__asm__ ("mov %esp,%eax");
}

void main()
{
	printf("0x%x\n",get_rsp());
}

/**
 * Author: Nalam V S S Krishna Chaitanya,
 * Details: CS13B021, IIT Madras.
 */

#include <stdio.h>

/**
 * This program prints the value of stack pointer (%rsp).
 */

unsigned long get_rsp()
{
	asm
	(
		"mov %rsp,%rax;"	// moves the value of stack pointer to register rax
							// which is what returned from the function.
	);
}

void main()
{
	printf("%#lx\n",get_rsp());	// prints the value returned from the function.
}

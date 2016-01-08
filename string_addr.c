/**
 * Author: Nalam V S S Krishna Chaitanya,
 * Details: CS13B021, IIT Madras.
 */

#include <stdio.h>

/**
 * This file shows how to find the address of the string kept in the code
 * segment and prints the address of the string. To find the address of the
 * string we put it along with the code itself, at the bottom and find 
 * its address by using a series of jump and call instructions by using relative
 * addressing with %rip (the instructions pointer).
 */

void* function()
{
asm (
	"jmp .+0x5;"	// 2 bytes	// 2+1+1+1 makes 5 bytes where we jump to call
	"pop %rax;"		// 1 byte	// instr which then calls(jumps to 2nd instr by
	"leaveq;"		// 1 byte	// pushing the address next to the call instr
	"retq;"			// 1 byte	// which is the address of the string, on to the
	"call .-0x3;"	// 5 bytes	// stack, we now pop it into %rax and return.
	".string \"/bin/sh\";" // The string whose address we want to find.
);
}

void main()
{
	printf("%p\n",function());	// This just prints the address of the string.
}

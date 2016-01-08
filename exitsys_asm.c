/**
 * Author: Nalam V S S Krishna Chaitanya,
 * Details: CS13B021, IIT Madras.
 */

#include <stdio.h>

/**
 * This file consists the assembly code written for exit system call.
 */

void main()
{
	asm (
		"mov $0x0, %rdi;"	// argument for exit function.
		"mov $0x3c, %rax;"	// syscall number for exit syscall.
		"syscall;"			// syscall instruction for faster system calls.
	);
}

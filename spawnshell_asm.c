/**
 * Author: Nalam V S S Krishna Chaitanya,
 * Details: CS13B021, IIT Madras.
 */

#include <stdio.h>

/**
 * In this file we write the assembly level code to call execve function with
 * the arguments kept in corresponding registers as per x86_64 syscall
 * convention.
 */

void main()
{
	char* name[2] = {"/bin/sh",NULL};	// Arguments filled in array.

	asm (
		"mov $0x3b,%eax;"				// syscall number in rax.
		"mov -0x10(%rbp), %rdi;"		// filename ptr in rdi.
		"lea -0x10(%rbp), %rsi;"		// arguments array(name) in rsi.
		"mov $0x0, %rdx;"				// No env variables so NULL in rdx.
		"syscall;"						// call system call.(llly to int 0x80)
	);
}

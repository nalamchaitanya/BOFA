/**
 * Author: Nalam V S S Krishna Chaitanya,
 * Details: CS13B021, IIT Madras.
 */

#include <stdio.h>

/**
 * In this program we alter the return address from the function 'function'
 *  so that the instruction x=1 in the main function is skipped and the old
 *  value i.e 0 is printed. The stack in the function look likes this.
 */

// |					|<-----Higher Address.
// |					|
// +--------------------+
// |  <retunr address>	|
// +--------------------+
// |<prev frame pointer>|
// +--------------------+<-----rbp
// |<canary for checking|
// +for any overflows	+
// |can be ignored now>	|
// +--------------------+<-----(-16)
// |<space for buffer2	|
// + along with padding	+
// | total of 16 bytes>	|
// +--------------------+<-----(-32)
// |<space for buffer1	|
// + along with padding	+
// | total of 16 bytes>	|
// +--------------------+<-----(-48)
// |<int *ret is here>	|
// +--------------------+<-----(-56)
// |					|
// |					|<-----Lower Address


void function(int a, int b, int c)
{
	char buffer1[5];			// These are the buffers allocated on the stack.
	char buffer2[10];
    buffer1[0]=5;				// These are just assigned values so that we can find the offsets of these buffers from the
    buffer2[0]=6;				// base of the function frame on the stack above which lies the return address. Refer 1.s for explanation.

	int *ret;					// Since from 1.s we can see that buffer1 is 48 bytes below rbp and another 8 bytes for the frame pointer
    ret = buffer1+48+8;			// so by adding a total of 56 bytes we arrive at the return address.

	printf("%x\n",*ret);		// This is for printing the current return value of the function.
    (*ret) += 8;				// Increment the return address by 8 bytes so as to skip the assignmet x=1 in the main function.
								// This value of 8, the value to be incremented is found from disassembling the main function using
								// gdb with flag /m i.e disas /m main (https://sourceware.org/gdb/onlinedocs/gdb/Machine-Code.html)
}

void main()
{
    int x;
    x=0;
	function(1,2,3);			// Calling the function(1,2,3) which manipulates the return address.
    x=1;						// Actually the function has to return here,
    printf("%d\n",x);			// but returns here due to increment of the return address there by printing its old value.
}

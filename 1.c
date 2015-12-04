#include <stdio.h>

 void function(int a, int b, int c)
 {
	char buffer1[5];
    buffer1[0]=5;
	char buffer2[10];
    int *ret;

    ret = buffer1+32+8;
    /**
     * 32 as the buffer1 started 32 bytes below %rbp
     * 8 as each address is rounded of by 8 bytes. pushq
     */
    printf("%x\n",*ret);
    (*ret) += 8;

 }

 void main()
 {
    int x;
    x=0;
	function(1,2,3);
    x=1;
    printf("%d\n",x);
 }

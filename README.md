Buffer OverFlow Attack
----------------------

Introduction:
------------

This project is based on the paper "Smashing The Stack For Fun And Profit" by Aleph One. src: http://insecure.org/stf/smashstack.html

What is Buffer Overflow Attack?

This is a way of altering the program's execution by overflowing an allocated memory for the program. This is mainly caused due to violation of memory safety. There are different types of attacks based on which memory of the process we are going to overflow. For example Stack overflow,Heap Overflow etc.

This project demonstrates how to attack the program by overflowing the stack by passing malicious code into it and overwriting the return address and there by altering the control of the program. All the code and executables are for the 64-bit machine unlike given in the paper. So there may be slight changes which are important to be noticed.

Requirements:
---------------

1. You have to be familiar with how a stack functions and some facts about how the function calls are organized using stack (About the frame pointer rbp and the stack pointer rsp). Stacks can be top-down or bottom-up based on the direction of growth of the stack after a push operation. If the rsp value is decreased it means stack is growing downward implies that it is a top-down stack and in the same way if the rsp value is increased then it is growing upward implies that it is a bottom-up stack.

2. In this project I used AT&T syntax for assembly code which you can get familiarised using Brennan's Guide to Inline Assembly. http://www.delorie.com/djgpp/doc/brennan/brennan_att_inline_djgpp.html Basic Inline Assembly is enough as far as this project is concerned.

3. We should be adding the gcc option -fno-stack-protector to prevent any canaries added to the functions and also -zexecstack whenever you want to give executing permissions to the stack which is generally disabled because of W xor X permissions i.e a memory should be marked either executable or writable but not both.

Explanation:
-----------

In this project we are mainly  using the fact that the local variables and arrays of a function are allocated in the stack. So by overflowing these buffers (arrays) we can overwrite the return address to which the function goes after completing the function there by taking control over the process.

1.c,1.s,1
---------

 In this program we alter the return address from the function 'function' so that the instruction x=1 in the main function is skipped and the old value of the variable x i.e 0 is printed. Refer 1.s file also for further clarification. To disassemble the function use gdb utility 'disas /m <function name>' which gives the length of each line in code in bytes. Refer this link regarding disassemble in gdb https://sourceware.org/gdb/onlinedocs/gdb/Machine-Code.html

#Buffer OverFlow Attack

##Introduction:

This project is based on the paper [Smashing The Stack For Fun And Profit](http://insecure.org/stf/smashstack.html) by Aleph One.

What is Buffer Overflow Attack?

This is a way of altering the program's execution by overflowing an allocated memory for the program. This is mainly caused due to violation of memory safety. There are different types of attacks based on which memory of the process we are going to overflow. For example Stack overflow,Heap Overflow etc.

This project demonstrates how to attack the program by overflowing the stack by passing malicious code into it and overwriting the return address and there by altering the control of the program. All the code and executables are for the 64-bit machine unlike given in the paper. So there may be slight changes which are important to be noticed.

##Requirements:

 You have to be familiar with how a stack functions and some facts about how the function calls are organized using stack (About the frame pointer rbp and the stack pointer rsp). Stacks can be top-down or bottom-up based on the direction of growth of the stack after a push operation. If the rsp value is decreased it means stack is growing downward implies that it is a top-down stack and in the same way if the rsp value is increased then it is growing upward implies that it is a bottom-up stack.

 In this project I used **AT&T** syntax for assembly code which you can get familiarised using [Brennan's Guide to Inline Assembly](http://www.delorie.com/djgpp/doc/brennan/brennan_att_inline_djgpp.html). Basic Inline Assembly is enough as far as this project is concerned.

 We should be adding the gcc option -fno-stack-protector to prevent any canaries added to the functions and also -zexecstack whenever you want to give executing permissions to the stack which is generally disabled because of **W xor X** permissions i.e a memory should be marked either executable or writable but not both.

##Explanation:

In this project we are mainly  using the fact that the local variables and arrays of a function are allocated in the stack. So by overflowing these buffers (arrays) we can overwrite the return address to which the function goes after completing the function there by taking control over the process.

###[1.c](./1.c),[1.s](./1.s)

 In this program we alter the return address from the function 'function' so that the instruction x=1 in the main function is skipped and the old value of the variable x i.e 0 is printed. Refer 1.s file also for further clarification. To disassemble the function use gdb utility [disas /m main](https://sourceware.org/gdb/onlinedocs/gdb/Machine-Code.html). which gives the length of each line in code in bytes.

Next part of the project concentrates basically on what should we overflow the buffer with so that we can get the control. Here we try to execute a bash shell so that we can do anything from that point. So we construct a *shellcode* which will be used to overflow the buffer and then execute so that a shell gets executed and we get a terminal. It is done step by step.

###[spawnshell.c](./spawnshell.c),[spawnshell.s](./spawnshell.s)

 This is just an example of how to execute a shell using execve function, a system call. This is written so that we can write our 'shellcode' similar to the assembly code of this file. Execute this and we get a shell.

###[spawnshell_asm.c](./spawnshell_asm.c),[spawnshell_asm.s](./spawnshell_asm.s)

 These files are extension of the previous files. In that they directly write the assembly required to perform the system call with the corresponding arguments in the registers as per the [x86_64 syscall instruction convention](https://en.wikibooks.org/wiki/X86_Assembly/Interfacing_with_Linux#int_0x80). **syscall** is an instruction introduced in x86_64 architecture to make system calls faster without accessing interrupt descriptor tables.

 You can find the system call number of the execve function either by disassembling execve function at a break point while running or you can also find it in [System call table for x86_64](https://filippo.io/linux-syscall-table/). In this case it is 59(0x3b) for execve function.

###[exitsys.c](./exitsys.c),[exitsys.s](./exitsys.s)

The execve function never returns however it does when it fails, then it keeps on fetching instructions which is not intended and may crash and core dump. To avoid this and to exit cleanly we also have to write the assembly code for the exit system call as we wrote for the execve system call. So let us start with [exitsys.c](./exitsys.c). This just exits cleanly without any error code.

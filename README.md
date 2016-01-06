Buffer OverFlow Attack
----------------------

Introduction:
------------

This project is based on the paper "Smashing The Stack For Fun And Profit" by
Aleph One. Link : http://insecure.org/stf/smashstack.html

What is Buffer Overflow Attack?

This is a way of altering the program's execution by overflowing an allocated
memory for the program. This is mainly caused due to violation of memory safety.
There are different types of attacks based on which memory of the process we are
going to overflow. For example Stack overflow,Heap Overflow etc.

This project demonstrates how to attack the program by overflowing the stack by
passing malicious code into it and overwriting the return address and there by
altering the control of the program. All the code and executables are for the
64-bit machine unlike given in the paper. So there may be slight changes which
are important to be noticed.


/*
======================================================================================== 
Name: 19c.c
Author: Gitika Pinjani
Description: Create a FIFO file by
c. use strace command to find out, which command (mknod or mkfifo) is better.
Date: 21st Sept, 2024
=========================================================================================
*/

/*
command: strace mknod myfifo p
output: mknodat(AT_FDCWD, "myfifo", S_IFIFO|0666)

command: strace mkfifo myfifo
outputL: mknodat(AT_FDCWD, "myfifo", S_IFIFO|0666)

both mknod mkfifo ultimatelt rely on mknod() system call to create FIFO.

mkfifo is better because it is specifically designed for creating FIFO's and abstract system call detail from the user.

*/

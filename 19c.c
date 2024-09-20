
/*
command: strace mknod myfifo p
output: mknodat(AT_FDCWD, "myfifo", S_IFIFO|0666)

command: strace mkfifo myfifo
outputL: mknodat(AT_FDCWD, "myfifo", S_IFIFO|0666)

both mknod mkfifo ultimatelt rely on mknod() system call to create FIFO.

mkfifo is better because it is specifically designed for creating FIFO's and abstract system call detail from the user.

*/

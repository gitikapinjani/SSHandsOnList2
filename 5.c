#include<unistd.h>
#include<stdio.h>

int main(){

long systemConfig = sysconf(_SC_ARG_MAX);
printf("maximum length of arguments %ll",systemConfig);

}

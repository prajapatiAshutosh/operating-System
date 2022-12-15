// program 2
// Write a program to report behaviour of Linux kernel including kernel version, CPU type and
// model. (CPU information)
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    system("cat /proc/sys/kernel/osrelease");
    system("cat /proc/cpuinfo");
    system("cat /proc/meminfo");
    return 0;
}
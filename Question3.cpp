// program 3
//  Write a program to report behaviour of Linux kernel including information on 19 configured
// memory, amount of free and used memory. (memory information)
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    cout << "kernel version is:/n";
    system("cat /proc/kernel/osrelease");
    cout << "Cpu Usage: /n";
    system("cat /proc/cpuinfo | awk 'NR==3,NR==4{print}'/n");
    cout << "/n amount of cpu time usage:";
    system("cat /proc/uptime /n");
    system("cat /proc/meminfo | awk 'NR==1,NR==4{print $2}'/n");
    cout << "amount of free memory: /n";
    system("cat /proc/meminfo | awk 'NR==2{print $2}'/n");
    cout << "amount of used memory: /n";
    system("cat /proc/meminfo | awk'{ if(NR==1) a=$2;if(NR==2) b=$2}END{print a-b}'/n");
    cout << endl;
    return (0);
}
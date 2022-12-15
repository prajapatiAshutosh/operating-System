// program 4
//  Write a program to print file details including owner access permissions, file access time,
// where file name is given as argument.
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
    int i;
    struct stat s;
    if (argc < 2)
    {
        cout << "enter filename:/n";
        // exit();
    }
    for (i = 1; i < argc; i++)
    {
        cout << "file:" << argv[i] << "/n";
        if (stat(argv[i], &s) < 0)
            cout << "error in obtaining stats.";
        else
        {
            cout << "OWNER UID:";
            cout << s.st_uid;
            cout << "/n";
            cout << "GROUPID:";
            cout << s.st_gid;
            cout << "/n";
            cout << "ACCESS PERMISSIONS:";
            cout << s.st_mode;
            cout << "/n";
            cout << "ACCESS";
            cout << s.st_atime;
            cout << "/n";
        }
    }
    return 0;
}
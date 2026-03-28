#include <stdio.h>
#include <sys/sysinfo.h>

#ifdef linux 
#ifndef OS
#define OS "linux"
#endif

#ifndef NOTOS
#define NOTOS "windows, unix or apple"
#endif 
#endif

#ifdef _WIN32
#ifndef OS
#define OS "windows"
#endif

#ifndef NOTOS 
#define NOTOS "linux, unix or apple"
#endif
#endif

#ifdef __unix

#ifndef OS
#define OS "unix"
#endif

#ifndef NOTOS
#define NOTOS "linux, windows or apple"
#endif
#endif

#ifdef __APPLE

#ifndef OS
#define OS "unix"
#endif

#ifndef NOTOS
#define NOTOS "linux, windows or unix"
#endif
#endif

int main(void) 
{
    struct sysinfo s;

unsigned long long free_kb = (unsigned long long)s.freeram * s.mem_unit / 1024;    
unsigned long long total_kb = (unsigned long long)s.totalram * s.mem_unit / 1024;

    printf("Total %llu kb\n", total_kb/1024.0);    
    printf("Free %llu kb\n", free_kb/1024.0);
    printf("system is %s and is not %s. \n", OS, NOTOS );
return 0;
};

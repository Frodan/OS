#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <zconf.h>

int main() {
    int fd = open("ex1.txt", O_RDWR);
    char outstring[] = "This is a nice day.";
    int length = sizeof(outstring) - 1;
    char* src;

    ftruncate(fd, length);
    src = mmap(NULL, length, PROT_WRITE, MAP_SHARED, fd, 0);
    strcpy(src, outstring);

    return 0;
}
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <zconf.h>
#include <sys/mman.h>


int main(void) {
    int in = open("ex1.txt", O_RDONLY);
    int out = open("ex1.memcpy.txt", O_RDWR | O_CREAT);

    struct stat filestat;
    fstat(in, &filestat);

    long size = filestat.st_size;
    ftruncate(out, size);

    void* in_src = mmap(NULL, size, PROT_READ, MAP_SHARED, in, 0);
    void* out_src = mmap(NULL, size, PROT_WRITE, MAP_SHARED, out, 0);
    memcpy(out_src, in_src, size);

    return 0;
}
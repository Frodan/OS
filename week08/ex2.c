/*
 * after executing 'vmstat 1' and this program we can see in the output,
 * that our free space is decreasing, si and so equal 0. When free space will be not enough,
 * system will use swap and si,so will not be equal to 0 anymore.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int size = 1024*1024*10;
    for(int i = 0; i < 10; i++){
        void *pointer = malloc(size);
        memset(pointer, 0, size);
        sleep(1);
    }
    return 0;
}
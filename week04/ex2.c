#include <stdio.h>
#include <unistd.h>

int main() {
    for(int i = 0; i < 5; i++){
        fork();
        sleep(5);
    }
    return 0;
}
/*
 * ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
    │     │     │     └─ex2
    │     │     ├─ex2───ex2
    │     │     └─ex2
    │     ├─ex2─┬─ex2───ex2
    │     │     └─ex2
    │     ├─ex2───ex2
    │     └─ex2
    ├─ex2─┬─ex2─┬─ex2───ex2
    │     │     └─ex2
    │     ├─ex2───ex2
    │     └─ex2
    ├─ex2─┬─ex2───ex2
    │     └─ex2
    ├─ex2───ex2
    └─ex2

This is the output of pstree. every time, when fork() is executing, the number of threads doubles. We did fork()
in loop 5 times, so number of threads is 2**5.
 */
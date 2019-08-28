#include <stdio.h>
#include <string.h>

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int a, b;
    char line[100];
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d %d", &a, &b);
    printf("a is %d, b is %d\n", a, b);
    swap(&a, &b);
    printf("a is %d, b is %d after swap.\n", a, b);
}
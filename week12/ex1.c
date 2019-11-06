#include <stdio.h>

int main() {
    FILE* random;
    char str[20];
    random = fopen("/dev/random", "r");
    fgets(str, 20, random);
    printf("%s", str);
    return 0;
}
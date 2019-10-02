#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int *array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        array[i] = i;
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}


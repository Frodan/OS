#include <stdio.h>


void print_array(int array[], int len){

    for(int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubble_sort(int array[], int len){
    int i = len;
    while (i > 0){
        int check = 0;
        for (int j = 1; j < i; j++){
            if (array[j-1] > array[j]){
                int tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
                check = 1;
            }
        }
        if (!check){
            break;
        }
        i--;
    }
}

int main(){
    int test_array[10] = {1000, 4, 3, 2, 1, 6, 3, 3 , 123, 0};
    print_array(test_array, 10);
    bubble_sort(test_array, 10);
    print_array(test_array, 10);
    return 0;
}
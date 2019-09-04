#include <stdio.h>


void print_array(int array[], int len){

    for(int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int partition(int array[], int low, int high){
    int pivot = array[high];
    int i = low;
    for (int j = low; j < high; j++){
        if (array[j] <= pivot){
            int tmp =  array[i];
            array[i] = array[j];
            array[j] = tmp;
            i += 1;
        }
    }
    int tmp =  array[i];
    array[i] = array[high];
    array[high] = tmp;
    return i;
}

void quick_sort(int array[], int low, int high){
    if (low < high){
        int p = partition(array, low, high);
        quick_sort(array, low, p - 1);
        quick_sort(array, p + 1, high);
    }
}


int main(){
    int test_array[10] = {1000, 4, 3, 2, 1, 6, 3, 3 , 123, 0};
    print_array(test_array, 10);
    quick_sort(test_array, 0, 9);
    print_array(test_array, 10);
    return 0;
}

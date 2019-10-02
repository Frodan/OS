#include <stdlib.h>
#include <stdio.h>

void* my_realloc(void *ptr, size_t size, size_t new_size){
    if (ptr == NULL){
        return malloc(new_size);
    }
    if (size == 0){
        free(ptr);
        return NULL;
    }
    else{
        char *tmp = ptr;
        char *ptr_new = malloc(new_size);
        for(size_t i = 0; i < size; i++){
            ptr_new[i] = tmp[i];
        }
        free(ptr);
        void *result = ptr_new;
        return result;
    }
}

int main(){
    printf("Enter original array size:");
    int n1=0;
    scanf("%d",&n1);

    //Create a new array of n1 ints
    int* a1 = malloc(n1 * sizeof(int));
    for(int i=0; i<n1; i++){
        //Set each value in a1 to 100
        a1[i]=100;

        //Print each element out (to make sure things look right)
        printf("%d ", a1[i] );
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2=0;
    scanf("%d",&n2);

    //Dynamically change the array to size n2
    a1 = my_realloc(a1, n2 * sizeof(int), n1);

    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

    if (n2 > n1){
        for (int i = n1; i < n2; i++){
            a1[i] = 0;
        }
    }


    for(int i=0; i<n2;i++){
        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }
    printf("\n");

    //Done with array now, done with program :D

    return 0;
}


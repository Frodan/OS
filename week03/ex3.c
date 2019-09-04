#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

void print_list(struct Node* list){
    printf("List: ");
    if (list->next == NULL){
        printf("\n");
        return;
    }
    else{
        struct Node* pointer = list->next;
        while (1){
            int value = pointer->value;
            printf("%d ", value);
            pointer = pointer->next;
            if (pointer == NULL){
                break;
            }
        }
    }
    printf("\n");
}

void insert_node(struct Node* list, int value){
    struct Node* pointer;
    pointer = malloc(sizeof(struct Node));
    pointer->value = value;
    pointer->next = NULL;
    struct Node* curr = list;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = pointer;
}

void delete_node(struct Node* list, int value){
    struct Node* curr = list;
    struct Node* pred = list;
    int check = 0;
    while (curr->next != NULL){
        pred = curr;
        curr = curr->next;
        if (curr->value == value){
            check = 1;
            pred->next = curr->next;
            free(curr);
            curr = pred;
        }
    }
}

int main(){
    struct Node list;
    list.next = NULL;
    print_list(&list);//

    insert_node(&list, 1);
    insert_node(&list, 1);
    print_list(&list);// 1 1

    insert_node(&list, 2);
    print_list(&list);// 1 1 2

    delete_node(&list, 1);
    print_list(&list);// 2

    delete_node(&list, 2);
    print_list(&list);//
    return 0;
}
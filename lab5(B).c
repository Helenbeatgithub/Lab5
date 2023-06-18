#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertionSort(int array[], int size){
    int i, key, j;
    
    for(i = 1; i < size; i++){
        key = array[i];
        j = i - 1;
        
        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j = j - 1;
        }
        
        array[j + 1] = key;

        // printing each step of the sort
        printf("After step %d: ", i);
        for(int k = 0; k < size; k++) {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}

struct Node* arrayToLinkedList(int* array, int size) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for(int i = 0; i < size; i++) {
        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->data = array[i];
        new_node->next = NULL;

        if(head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void reverseLinkedList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int main() {
    int size;
    
    printf("Insertion Sort\n");
    printf("Input array size: ");
    scanf("%d", &size);
    
    int *array = malloc(size * sizeof(int));
    
    if(array == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    
    printf("Input elements of array:\n");
    for(int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    
    insertionSort(array, size);

    struct Node* head = arrayToLinkedList(array, size);

    printf("Linked list from sorted array:\n");
    printLinkedList(head);

    reverseLinkedList(&head);

    printf("Reversed linked list:\n");
    printLinkedList(head);

    free(array);

    //free the linked list
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

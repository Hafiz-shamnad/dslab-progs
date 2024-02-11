#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

void insertAtEnd(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    struct Node* lastNode = list->head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void insertAnyPosition(struct LinkedList* list, int data , int keyValue){
    struct Node * new = createNode(data);
    if(list -> head == NULL){
        list -> head = new;
        return;
    }
    struct Node* ptr = list->head;
    while(ptr != NULL && (ptr -> data != keyValue)){
        ptr = ptr -> next;
    }
    if(ptr == NULL){
        printf("Key value not found");
    }else{
        new -> next = ptr -> next;
        ptr -> next = new;
    }
}

void deleteNode(struct LinkedList* list, int key) {
    struct Node *temp = list->head, *prev;

    if (temp != NULL && temp->data == key) {
        list->head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void display(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct LinkedList linkedList;
    linkedList.head = NULL;

    insertAtBeginning(&linkedList, 1);
    insertAtBeginning(&linkedList, 2);
    insertAnyPosition(&linkedList,5,2);
    insertAtEnd(&linkedList, 3);
    insertAtEnd(&linkedList, 4);

    printf("Linked List: ");
    display(&linkedList);

    deleteNode(&linkedList, 3);

    printf("After deletion: ");
    display(&linkedList);

    return 0;
}

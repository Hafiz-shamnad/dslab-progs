#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = value;
    new->link = head;
    head = new;
}

void display() {
    struct Node* ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

void reverse() {
    struct Node* prev = NULL;
    struct Node* curr = head;
    while (curr != NULL) {
        head = curr;
        curr = curr->link;
        head->link = prev;
        prev = head;
    }
}

int main() {
    int choice, value;

    printf("SLL operations\n");
    printf(" [1] Insert\n");
    printf(" [2] Display\n");
    printf(" [3] Reverse\n");
    printf(" [4] Exit\n");
    while (1) {
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
        } else if (choice == 2) {
            display();
        } else if (choice == 3) {
            reverse();
            printf("List reversed\n");
        } else if (choice == 4) {
            break;
        } else {
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}

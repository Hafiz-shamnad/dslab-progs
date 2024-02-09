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

void sum_of_even() {
    struct Node* ptr;
    int sum = 0;

    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->link == NULL) {
        printf("No even nodes\n");
    } else {
        ptr = head->link;
        while (ptr != NULL) {
            sum += ptr->data;
            if (ptr->link == NULL)
                break;
            ptr = ptr->link->link;
        }
        printf("Sum of even nodes = %d\n", sum);
    }
}

int main() {
    int choice, value;

    printf("SLL operations\n");
    printf(" [1] Insert\n");
    printf(" [2] Display\n");
    printf(" [3] Sum of even nodes\n");
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
            sum_of_even();
        } else if (choice == 4) {
            break;
        } else {
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr;
    new->data = value;
    if (head == NULL) {
        head = new;
        head->link = head;
    } else {
        ptr = head;
        while (ptr->link != head)
            ptr = ptr->link;
        new->link = head;
        ptr->link = new;
        head = new;
    }
}

void display() {
    struct Node* ptr;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        ptr = head;
        while (ptr->link != head) {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
        printf("%d\n", ptr->data);
    }
}

void get_distance(int key1, int key2) {
    struct Node* ptr;
    int dist = 0;

    if (head == NULL) {
        printf("List is empty\n");
    } else {
        ptr = head;
        while (ptr->data != key1) {
            ptr = ptr->link;
            if (ptr == head)
                break;
        }
        if (ptr->data != key1) {
            printf("First key not found\n");
        } else {
            while (ptr->data != key2) {
                ptr = ptr->link;
                dist++;
                if (ptr->data == key1)
                    break;
            }
            if (ptr->data != key2) {
                printf("Second key not found\n");
            } else {
                printf("Distance between nodes = %d\n", dist);
            }
        }
    } 
}

int main() {
    int choice, value, key1, key2;

    printf("CLL operations\n");
    printf(" [1] Insert\n");
    printf(" [2] Display\n");
    printf(" [3] Get distance\n");
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
            printf("Enter two keys: ");
            scanf("%d %d", &key1, &key2);
            get_distance(key1, key2);
        } else if (choice == 4) {
            break;
        } else {
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}

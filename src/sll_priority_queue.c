#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item;
    int prio;
    struct Node* link;
};

struct Node* head = NULL;

void display() {
    struct Node* ptr;

    if (head == NULL) {
        printf("Priority queue is empty\n");
    } else if (head->link == NULL) {
        printf("Item = %d\tPriority = %d\n", head->item, head->prio);
    } else {
        ptr = head;
        while (ptr != NULL) {
            printf("Item = %d\tPriority = %d\n", ptr->item, ptr->prio);
            ptr = ptr->link;
        }
    }
}

void enqueue(int item, int prio) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr;
    new->item = item;
    new->prio = prio;

    if (head == NULL) {
        head = new;
    } else if (head->prio > prio) {
        new->link = head;
        head = new;
    } else {
        ptr = head;
        while (ptr->link != NULL) {
            if (ptr->link->prio > prio) {
                new->link = ptr->link;
                ptr->link = new;
                return;
            }
            ptr = ptr->link;
        }
        ptr->link = new;
        new->link = NULL;
    }
}

void dequeue() {
    struct Node* prev;
    struct Node* curr;

    if (head == NULL) {
        printf("Priority queue is empty. Cannot dequeue.\n");
    } else {
        if (head->link == NULL) {
            curr = head;
            head = NULL;
        } else {
            prev = head;
            curr = head->link;
            while (curr->link != NULL) {
                prev = curr;
                curr = curr->link;
            }
            prev->link = NULL;
        }
        printf("Deleted item %d with priority %d\n", curr->item, curr->prio);
        free(curr);
    }
}

int main() {
    int choice, item, priority;

    printf("\nPriority Queue operations\n");
    printf(" [1] Display\n");
    printf(" [2] Enqueue\n");
    printf(" [3] Dequeue\n");
    printf(" [4] Exit\n");
    while (1) {
        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            display();
        } else if (choice == 2) {
            printf("\nEnter value and priority of item: ");
            scanf("%d %d", &item, &priority);
            enqueue(item, priority);
            printf("%d with priority %d added to queue\n", item, priority);
        } else if (choice == 3) {
            dequeue();
        } else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}

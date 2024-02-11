#include <stdio.h>
#define MAX_SIZE 50

int front, rear = -1;
int queue[MAX_SIZE];

void insert_front(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[front] = item;
    } else {
        if (front > 0) {
            queue[--front] = item;
        } else {
            printf("Cannot insert at front, queue full\n");
        }
    }
}

void insert_rear(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear++] = item;
    } else {
        queue[rear++] = item;
    }
}

int dlt_front() {
    int item;
    if (front == -1 && rear == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        item = queue[front++];
        if (front > rear) {
            front = rear = -1;
        }
        return item;
    }
}

int dlt_end() {
    int item;
    if (front == -1 && rear == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        item = queue[rear--];
        if (front > rear) {
            front = rear = -1;
        }
        return item;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    do {
        printf("\n------ Queue Menu ------\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &item);
                insert_front(item);
                break;
            case 2:
                printf("Enter element to insert at rear: ");
                scanf("%d", &item);
                insert_rear(item);
                break;
            case 3:
                printf("Deleted element from front: %d\n", dlt_front());
                break;
            case 4:
                printf("Deleted element from rear: %d\n", dlt_end());
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

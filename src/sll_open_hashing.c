#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* link;
};

void insert(struct Node** head, int item) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp;
    new->data = item;
    new->link = NULL;
    if (*head == NULL) {
        *head = new;
    } else {
        temp = *head;
        while (temp->link != NULL) temp = temp->link;
        temp->link = new;
    }
}

void display_list(struct Node** head) {
    struct Node* temp;
    temp = *head;
    while (temp->link != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("%d\n", temp->data);
}

int main() {
    struct Node* hash_table[MAX_SIZE];
    int table_size, key, hash, choice, i;

    printf("Enter hash table size: ");
    scanf("%d", &table_size);

    printf("\nOpen Hashing operations\n");
    printf(" [1] Hash a key\n");
    printf(" [2] Display\n");
    printf(" [3] Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nEnter the key value: ");
            scanf("%d", &key);
            hash = key % table_size;
            insert(&hash_table[hash], key);
            printf("Key %d is hashed to %d\n", key, hash);
        } else if (choice == 2) {
            printf("\nDisplaying hashes and keys\n");
            for (i = 0; i < table_size; i++) {
                if (hash_table[i] != NULL) {
                    printf("%d: ", i);
                    display_list(&hash_table[i]);
                }
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}

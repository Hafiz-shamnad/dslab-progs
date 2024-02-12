#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc

struct Node
{
    int data;
    struct Node* lchild;
    struct Node* rchild;
};

struct Node* addTree(struct Node* node, int value) {
    if (node == NULL) {
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->data = value;
        new->lchild = NULL;
        new->rchild = NULL;
        return new;
    }
    if (value > node->data) {
        node->rchild = addTree(node->rchild, value);
    }
    else if (value < node->data) {
        node->lchild = addTree(node->lchild, value);
    }
    else {
        printf("Duplicate Value exists\n");
    }
    return node;
}

void preorder(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->lchild);
        preorder(node->rchild);
    }
}

void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->lchild);
        printf("%d ", node->data);
        inorder(node->rchild);
    }
}

void postorder(struct Node* node) {
    if (node != NULL) {
        postorder(node->lchild);
        postorder(node->rchild);
        printf("%d ", node->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Tree Menu\n");
        printf("1. Add a value\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                root = addTree(root, value);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}

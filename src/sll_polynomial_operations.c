#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int expo;
    struct Node* link;
};

struct Node* read_poly() {
    struct Node* poly_head = NULL;
    struct Node* temp = NULL;
    struct Node* new;
    int count, i;

    printf("Enter the number of non zero terms: ");
    scanf("%d", &count);
    printf("Enter the coefficients and exponents in order");
    for (i = 0; i < count; i++) {
        new = (struct Node*)malloc(sizeof(struct Node));
        printf("\nEnter cofficient: ");
        scanf("%d", &new->coef);
        printf("Enter exponent: ");
        scanf("%d", &new->expo);
        new->link = NULL;
        if (temp == NULL) {
            poly_head = temp = new;
        } else {
            temp->link = new;
            temp = new;
        }
    }
    temp->link = NULL;
    return poly_head;
}

void display_poly(struct Node* poly_head) {
    struct Node* ptr = poly_head;
    while (ptr->link != NULL) {
        printf("%dx^%d", ptr->coef, ptr->expo);
        ptr = ptr->link;
        if (ptr->link != NULL) printf(" + ");
    }
    printf(" + %dx^%d", ptr->coef, ptr->expo);
    printf("\n");
}

struct Node* add_or_sub(struct Node* poly1, struct Node* poly2, char op) {
    struct Node* res_head;
    struct Node* ptr = NULL;
    struct Node* new;

    while (poly1 != NULL && poly2 != NULL) {
        new = (struct Node*)malloc(sizeof(struct Node));
        new->link = NULL;
        if (poly1->expo > poly2->expo) {
            new->coef = poly1->coef;
            new->expo = poly1->expo;
            poly1 = poly1->link;
        } else if (poly2->expo > poly1->expo) {
            new->coef = poly2->coef;
            new->expo = poly2->expo;
            poly2 = poly2->link;
        } else {
            if (op == '+')
                new->coef = poly1->coef + poly2->coef;
            else if (op == '-')
                new->coef = poly1->coef - poly2->coef;
            new->expo = poly1->expo;
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
        if (ptr == NULL) {
            res_head = new;
            ptr = new;
            ptr->link = NULL;
        } else {
            ptr->link = new;
            ptr = new;
            ptr->link = NULL;
        }
    }
    while (poly1 != NULL) {
        new = (struct Node*)malloc(sizeof(struct Node));
        new->link = NULL;
        new->coef = poly1->coef;
        new->expo = poly1->expo;
        poly1 = poly1->link;
        if (ptr == NULL) {
            res_head = new;
            ptr = new;
            ptr->link = NULL;

        } else {
            ptr->link = new;
            ptr = new;
            ptr->link = NULL;
        }
    }
    while (poly2 != NULL) {
        new = (struct Node*)malloc(sizeof(struct Node));
        new->link = NULL;
        new->coef = poly2->coef;
        new->expo = poly2->expo;
        poly2 = poly2->link;
        if (ptr == NULL) {
            res_head = new;
            ptr = ptr->link;
            ptr->link = NULL;

        } else {
            ptr->link = new;
            ptr = new;
            ptr->link = NULL;
        }
    }
    return res_head;
}

struct Node* multiply(struct Node* poly1, struct Node* poly2) {
    struct Node* res_poly = NULL;
    struct Node* rptr;
    struct Node* temp;
    struct Node* new;
    struct Node* ptr1 = poly1;
    struct Node* ptr2 = poly2;
    int new_coef, new_expo;

    // Use distributive property to multiply poly1 with poly2
    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            new = (struct Node*)malloc(sizeof(struct Node));
            new->coef = ptr1->coef * ptr2->coef;
            new->expo = ptr1->expo + ptr2->expo;

            if (res_poly == NULL) {
                res_poly = new;
            } else {
                rptr = res_poly;
                while (rptr->link != NULL)
                    rptr = rptr->link;
                rptr->link = new;
            }
            ptr2 = ptr2->link;
        }
        ptr2 = poly2;
        ptr1 = ptr1->link;
    }

    // Add nodes with same exponent and delete extra nodes
    ptr1 = res_poly;
    while (ptr1 != NULL && ptr1->link != NULL) {
        ptr2 = ptr1;
        while (ptr2->link != NULL) {
            if (ptr1->expo == ptr2->link->expo) {
                ptr1->coef = ptr1->coef + ptr2->link->coef;
                temp = ptr2->link;
                ptr2->link = ptr2->link->link;
                free(temp);
            } else {
                ptr2 = ptr2->link;
            }
        }
        ptr1 = ptr1->link;
    }

    return res_poly;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* res_poly = NULL;
    int choice;

    printf("\nEnter the two polynomials\n");
    printf("\nPolynomial 1\n");
    poly1 = read_poly();
    printf("Entered polynomial 1 = ");
    display_poly(poly1);

    printf("\n\nPolynomial 2\n");
    poly2 = read_poly();
    printf("Entered polynomial 2 = ");
    display_poly(poly2);

    printf("\nPolynomial operations\n");
    printf(" [1] Display\n");
    printf(" [2] Add\n");
    printf(" [3] Subtract\n");
    printf(" [4] Multiply\n");
    printf(" [5] Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Polynomial 1 = ");
            display_poly(poly1);
            printf("Polynomial 2 = ");
            display_poly(poly2);

        } else if (choice == 2) {
            res_poly = add_or_sub(poly1, poly2, '+');
            printf("\nSum polynomial = ");
            display_poly(res_poly);

        } else if (choice == 3) {
            res_poly = add_or_sub(poly1, poly2, '-');
            printf("\nDifference polynomial = ");
            display_poly(res_poly);

        } else if (choice == 4) {
            res_poly = multiply(poly1, poly2);
            printf("\nProduct polynomial = ");
            display_poly(res_poly);

        } else if (choice == 5) {
            break;
        } else {
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}
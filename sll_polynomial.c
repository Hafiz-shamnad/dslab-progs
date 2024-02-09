#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *link;
};
struct Node *phead = NULL; // Initialize head to NULL
struct Node *new;

struct Node *read_poly()
{
    int count, i;
    struct Node *temp = NULL;
    printf("\nEnter the Number of Non-Zero terms\n");
    scanf("%d", &count);
    for (i = 0; i < count; i++)
    {
        printf("\nEnter the Coefficient\n");
        new = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &new->coeff);
        printf("\nEnter the Exponent of %d\n", new->coeff);
        scanf("%d", &new->exp);
        if (temp == NULL)
        {
            temp = phead = new;
        }
        else
        {
            temp->link = new;
            temp = new;
        }
    }
    temp->link = NULL;
    return phead;
}

void display_poly(struct Node *phead)
{
    struct Node *temp = phead;
    while (temp != NULL)
    {
        printf("%d x ^ %d", temp->coeff, temp->exp);
        temp = temp->link;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}


struct Node* addpoly(struct Node *pptr, struct Node *qptr)
{
    struct Node *rhead = NULL;
    struct Node *new;
    struct Node *rptr;

    while (pptr != NULL && qptr != NULL)
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        new->link = NULL;

        if (pptr->exp > qptr->exp)
        {
            new->exp = pptr->exp;
            new->coeff = pptr->coeff;
            pptr = pptr->link;
        }
        else if (qptr->exp > pptr->exp)
        {
            new->exp = qptr->exp;
            new->coeff = qptr->coeff;
            qptr = qptr->link;
        }
        else
        {
            new->exp = qptr->exp;
            new->coeff = qptr->coeff + pptr->coeff;
            qptr = qptr->link;
            pptr = pptr->link;
        }
        if (rptr == NULL)
        {
            rhead = new;
            rptr = new;
            rptr->link = NULL;
        }
        else
        {
            rptr->link = new;
            rptr = new;
            rptr->link = NULL;
        }
    }
    while (pptr != NULL)
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        new->link = NULL;
        new->exp = pptr->exp;
        new->coeff = pptr->coeff;
        pptr = pptr->link;
        if (rptr == NULL)
        {
            rhead = new;
            rptr = new;
            rptr->link = NULL;
        }
        else
        {
            rptr->link = new;
            rptr = new;
            rptr->link = NULL;
        }
    }
    while (qptr != NULL)
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        new->link = NULL;
        new->exp = qptr->exp;
        new->coeff = qptr->coeff;
        qptr = qptr->link;

        if (rptr == NULL)
        {
            rhead = new;
            rptr = new;
            rptr->link = NULL;
        }
        else
        {
            rptr->link = new;
            rptr = new;
            rptr->link = NULL;
        }
    }
    return rhead;
}

struct Node* subpoly(struct Node *pptr, struct Node *qptr)
{
    struct Node *rhead = NULL;
    struct Node *new;
    struct Node *rptr;

    while (pptr != NULL && qptr != NULL)
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        new->link = NULL;

        if (pptr->exp > qptr->exp)
        {
            new->exp = pptr->exp;
            new->coeff = pptr->coeff;
            pptr = pptr->link;
        }
        else if (qptr->exp > pptr->exp)
        {
            new->exp = qptr->exp;
            new->coeff = qptr->coeff;
            qptr = qptr->link;
        }
        else
        {
            new->exp = qptr->exp;
            new->coeff = qptr->coeff - pptr->coeff;
            qptr = qptr->link;
            pptr = pptr->link;
        }
        if (rptr == NULL)
        {
            rhead = new;
            rptr = new;
            rptr->link = NULL;
        }
        else
        {
            rptr->link = new;
            rptr = new;
            rptr->link = NULL;
        }
    }
    while (pptr != NULL)
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        new->link = NULL;
        new->exp = pptr->exp;
        new->coeff = pptr->coeff;
        pptr = pptr->link;
        if (rptr == NULL)
        {
            rhead = new;
            rptr = new;
            rptr->link = NULL;
        }
        else
        {
            rptr->link = new;
            rptr = new;
            rptr->link = NULL;
        }
    }
    while (qptr != NULL)
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        new->link = NULL;
        new->exp = qptr->exp;
        new->coeff = qptr->coeff;
        qptr = qptr->link;

        if (rptr == NULL)
        {
            rhead = new;
            rptr = new;
            rptr->link = NULL;
        }
        else
        {
            rptr->link = new;
            rptr = new;
            rptr->link = NULL;
        }
    }
    return rhead;
}

struct Node* multpoly(struct Node *pptr, struct Node *qptr)
{
    struct Node *rhead = NULL;
    struct Node *new;
    struct Node *rptr;

    while (pptr != NULL && qptr != NULL)
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        new->link = NULL;

        if (pptr->exp == qptr->exp)
        {
            new->exp = qptr->exp;
            new->coeff = qptr->coeff * pptr->coeff;
            qptr = qptr->link;
            pptr = pptr->link;
        }
        else
        {
            new->exp = qptr->exp;
            new->coeff = 0;
            qptr = qptr->link;
            pptr = pptr->link;
        }
        if (rptr == NULL)
        {
            rhead = new;
            rptr = new;
            rptr->link = NULL;
        }
        else
        {
            rptr->link = new;
            rptr = new;
            rptr->link = NULL;
        }
    }
    return rhead;
}

int main()
{
    int choice;
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *result = NULL;

    do
    {
        printf("\n--- Polynomial Operations Menu ---\n");
        printf("1. Read Polynomial\n");
        printf("2. Display Polynomial\n");
        printf("3. Add Polynomials\n");
        printf("4. Subtract Polynomials\n");
        printf("5. Multiply Polynomials\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Reading Polynomial 1\n");
            poly1 = read_poly();
            printf("Reading Polynomial 2\n");
            poly2 = read_poly();
            break;
        case 2:
            printf("Displaying Polynomial 1\n");
            display_poly(poly1);
            printf("\nDisplaying Polynomial 2\n");
            display_poly(poly2);
            break;
        case 3:
            printf("Adding Polynomials\n");
            result = addpoly(poly1, poly2);
            printf("Resultant Polynomial after addition:\n");
            display_poly(result);
            break;
        case 4:
            printf("Subtracting Polynomials\n");
            result = subpoly(poly1, poly2);
            printf("Resultant Polynomial after subtraction:\n");
            display_poly(result);
            break;
        case 5:
            printf("Multiplying Polynomials\n");
            result = multpoly(poly1, poly2);
            printf("Resultant Polynomial after multiplication:\n");
            display_poly(result);
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


#include <stdio.h>
#define MAX_SIZE 10
int front = -1;
int rear = -1;
int queue[MAX_SIZE], prio[MAX_SIZE];

void display(int limit)
{
    for (int i = 0; i < limit; i++)
    {
        printf("Process ID - %d\t", queue[i]);
        printf("Priority - %d\n", prio[i]);
    }
}

void enqueue()
{
    int item, prioVal;
    if (rear == MAX_SIZE - 1)
    {
        printf("\nProcess Queue is Full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        printf("\nEnter the Process ID to be Inserted into Core : ");
        scanf("%d", &item);
        printf("\nEnter the Priority : ");
        scanf("%d", &prioVal);
        queue[rear] = item;
        prio[rear] = prioVal;
    }
    else
    {
        printf("\nEnter the Process ID to be Inserted into Core : ");
        scanf("%d", &item);
        printf("\nEnter the Priority : ");
        scanf("%d", &prioVal);
        rear++;
        queue[rear] = item;
        prio[rear] = prioVal;
    }
}

int dequeue()
{
    int item, prioVal;
    if (front == -1)
    {
        printf("\nNo processes Exists. Cannot be Deleted.\n");
    }
    else if (front == 0 && rear == 0)
    {
        item = queue[rear];
        prioVal = prio[rear];
        front = rear = -1;
    }
    else
    {
        item = queue[rear];
        prioVal = prio[rear];
        rear--;
    }
    return item;
}

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int sort_by_prio(int limit)
{
    int i, j;
    for (i = 0; i < limit - 1; i++)
    {
        for (j = i; j < limit - i - 1; j++)
        {
            if (prio[i] > prio[j])
            {
                swap(prio[i], prio[j]);
                swap(queue[i], queue[j]);
            }
        }
    }
}

int main()
{
    int choice;
    do
    {
        printf("\n--- CPU Process Operations Menu ---");
        printf("\n----- (MAXIMUM PROCESS = 10) -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue an Priority\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            sort_by_prio(rear + 1);
            int item = dequeue();
            printf("\nDeleetd process ID is : %d", item);
            break;
        case 3:
            printf("Displaying Processes\n");
            display(rear + 1);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
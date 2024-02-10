#include <stdio.h>
#define MAX_SIZE 20

int main()
{
    int arr[MAX_SIZE], min, lim, i, j, temp = 0;
    printf("Enter the limit of array\n");
    scanf("%d", &lim);
    printf("Enter the Elements of array\n");
    for (i = 0; i < lim; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < lim - 1; i++)
    {
        min = i;
        for (j = i + 1; j < lim; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    printf("After Sorting\n");
    for ( i = 0; i < lim; i++)
    {
        printf("%d " , arr[i]);
    }
    printf("\n");
    return 0;
}
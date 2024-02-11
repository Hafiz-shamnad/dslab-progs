#include <stdio.h>

int partiton(int low, int high, int arr[])
{
    int pivot = arr[high];
    int i =low;
    for (int j = low; j < high; j++)
    {
        if(arr[j]<pivot){
            i++;
            if(i-1 != j)
            swap(&arr[i-1],&arr[j]);
        }
    }
    swap(&arr[i],&arr[high]);
    return i;
}

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void quicksort(int low, int high, int arr[])
{
    if (low < high)
    {
        int pivot_index = partiton(low, high, arr);
        quicksort(0, pivot_index - 1, arr);
        quicksort(pivot_index + 1, high, arr);
    }
}

int main()
{
int arr[10];

    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(0, 4, arr);

    printf("After Sorting: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
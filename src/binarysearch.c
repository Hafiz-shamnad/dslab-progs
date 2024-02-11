#include <stdio.h>

void binsearch(int arr[], int low, int high, int item) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item) {
            printf("Value %d exists at index %d\n", item, mid);
            return;
        } else if (arr[mid] < item) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Value %d does not exist in the array\n", item);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements in ascending order:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int item;
    printf("Enter the value to search: ");
    scanf("%d", &item);

    binsearch(arr, 0, size - 1, item);
    return 0;
}

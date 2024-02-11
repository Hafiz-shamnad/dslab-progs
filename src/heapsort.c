#include <stdio.h>

void heapify(int arr[], int size, int root) {
    int largest = root;
    int lchild = 2 * root + 1;
    int rchild = 2 * root + 2;
    int temp;

    if (lchild < size && arr[lchild] > arr[largest])
        largest = lchild;
    if (rchild < size && arr[rchild] > arr[largest])
        largest = rchild;
    if (largest != root) {
        temp = arr[largest];
        arr[largest] = arr[root];
        arr[root] = temp;
        heapify(arr, size, largest);
    }
}

void heapsort(int arr[], int size) {
    int i, temp;
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i); //first heapipy calling according to the array parent
    }
    for (i = size - 1; i >= 0; i--) {
        temp = arr[0]; //deletion of elements fropm maximum root value to the end of the array
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0); // after deletion heapifying the tree
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    displayArray(arr, size);

    heapsort(arr, size);

    printf("Sorted array: ");
    displayArray(arr, size);

    return 0;
}

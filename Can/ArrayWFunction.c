#include <stdio.h>

#define MAX 100

void printArray(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAt(int arr[], int *size, int index, int value) {

    if (*size >= MAX)
        return;

    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    (*size)++;
}

void deleteAt(int arr[], int *size, int index) {

    if (*size <= 0)
        return;

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}

int main() {

    int arr[MAX] = {10, 20, 30, 40, 50};
    int size = 5;

    printArray(arr, size);

    insertAt(arr, &size, 2, 25);
    printArray(arr, size);

    deleteAt(arr, &size, 3);
    printArray(arr, size);

    return 0;
}
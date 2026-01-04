#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index) {

    if (index == 0)
        return;

    int parent = (index - 1) / 2;

    if (heap[parent] > heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }
}

void insert(int value) {

    heap[size] = value;
    size++;

    heapifyUp(size - 1);
}

void heapifyDown(int index) {

    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

int deleteMin() {

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return min;
}

int main() {

    insert(10);
    insert(30);
    insert(20);
    insert(5);

    printf("Min: %d\n", deleteMin());
    printf("Min: %d\n", deleteMin());

    return 0;
}
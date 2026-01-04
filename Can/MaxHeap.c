#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

/* iki sayiyi yer degistirme */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* yukari dogru duzenleme */
void heapifyUp(int index) {

    if (index == 0)
        return;

    int parent = (index - 1) / 2;

    if (heap[parent] < heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }
}

/* heap'e eleman ekleme */
void insert(int value) {

    heap[size] = value;
    size++;

    heapifyUp(size - 1);
}

/* asagi dogru duzenleme */
void heapifyDown(int index) {

    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

/* max heap'ten silme */
int deleteMax() {

    int max = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return max;
}

int main() {

    insert(10);
    insert(30);
    insert(20);
    insert(5);

    printf("Max: %d\n", deleteMax());
    printf("Max: %d\n", deleteMax());

    return 0;
}
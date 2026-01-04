#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
}

void insert(int array[], int *size, int newNum) {
    if (*size == 0) {
        array[0] = newNum;
        (*size)++;
    } else {
        array[*size] = newNum;
        (*size)++;
        for (int i = *size / 2 - 1; i >= 0; i--) {
            heapify(array, *size, i);
        }
    }
}

void deleteRoot(int array[], int *size) {
    int i;
    int lastElement = array[*size - 1];
    array[0] = lastElement;
    (*size)--;
    heapify(array, *size, 0);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[10];
    int size = 0;

    insert(array, &size, 3);
    insert(array, &size, 4);
    insert(array, &size, 9);
    insert(array, &size, 5);
    insert(array, &size, 2);

    printf("Max Heap: ");
    printArray(array, size);

    deleteRoot(array, &size);

    printf("After deletion: ");
    printArray(array, size);

    return 0;
}
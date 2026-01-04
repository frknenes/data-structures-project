#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *n, int pos, int val, int capacity) {
    if (*n >= capacity || pos < 0 || pos > *n) {
        printf("Islem basarisiz.\n");
        return;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
}

void deleteElement(int arr[], int *n, int pos) {
    if (*n == 0 || pos < 0 || pos >= *n) {
        printf("Islem basarisiz.\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;
    int capacity = 100;

    printf("Baslangic: ");
    printArray(arr, n);

    insertElement(arr, &n, 2, 99, capacity);
    printf("Ekleme sonrasi (Index 2, Deger 99): ");
    printArray(arr, n);

    deleteElement(arr, &n, 3);
    printf("Silme sonrasi (Index 3): ");
    printArray(arr, n);

    return 0;
}
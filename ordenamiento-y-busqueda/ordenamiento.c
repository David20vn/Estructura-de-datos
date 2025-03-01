#include <stdio.h>

// Ordenamiento Burbuja menos optimizado (O(n^2))
void bubbleSort(int arr[], int n) {
	int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) { // Comparar siempre hasta el final
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Ordenamiento por Inserción
void insertionSort(int arr[], int n) {
	int i;
    for (i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Ordenamiento Rápido (Quicksort) con pivote en el primer elemento
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        while (i <= j) {
            while (i <= high && arr[i] <= pivot) i++;
            while (j >= low && arr[j] > pivot) j--;
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

// Función para imprimir un arreglo
void printArray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    
    printf("Array original: ");
    printArray(arr1, n);
    
    bubbleSort(arr1, n);
    printf("Ordenado con Burbuja: ");
    printArray(arr1, n);
    
    insertionSort(arr2, n);
    printf("Ordenado con Inserción: ");
    printArray(arr2, n);
    
    quickSort(arr3, 0, n - 1);
    printf("Ordenado con Quicksort: ");
    printArray(arr3, n);
    
    return 0;
}


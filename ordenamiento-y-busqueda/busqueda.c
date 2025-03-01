#include <stdio.h>

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

// Búsqueda Secuencial
int sequentialSearch(int arr[], int n, int x) {
	int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Retorna la posición donde se encontró el elemento
        }
    }
    return -1; // Retorna -1 si no se encontró
}

// Búsqueda Binaria (requiere un arreglo ordenado)
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n - 1);
    printf("Ordenado: ");
    printArray(arr, n);
    
    int x = 22;
    int resultSeq = sequentialSearch(arr, n, x);
    printf("Busqueda Secuencial de %d: %s\n", x, resultSeq != -1 ? "Encontrado" : "No encontrado");
    
    int resultBin = binarySearch(arr, 0, n - 1, x);
    printf("Busqueda Binaria de %d: %s\n", x, resultBin != -1 ? "Encontrado" : "No encontrado");
    
    return 0;
}


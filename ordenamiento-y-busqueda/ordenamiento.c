#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>  // Necesario para memcpy

// Ordenamiento Burbuja (O(n^2))
void bubbleSort(int arr[], int n) {
int i, j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - 1 - i; j++) { // Optimización menor
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Ordenamiento por Inserción (O(n^2))
void insertionSort(int arr[], int n) {
int i;
    for ( i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Quicksort con pivote en el primer elemento (O(n log n) en promedio)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low + 1, j = high;
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

// Generar un array con números aleatorios en el rango [0, 100]
void generarArray(int arr[], int size) {
int i;
  for ( i = 0; i < size; i++) {
      arr[i] = rand() % 101;
  }
}

int sequentialSearch(int arr[], int n, int x) {
int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Retorna la posición donde se encontró el elemento
        }
    }
    return -1; // Retorna -1 si no se encontró
}

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {

    srand(time(NULL)); // Inicializar semilla de aleatoriedad
    int size, posicion_buscar;
    clock_t inicio, fin;
    double tiempo;

    printf("Digite la longitud del array: ");
    scanf("%d", &size);

    // Reservar memoria para los tres arreglos
    int *arr_burbuja = (int *)malloc(size * sizeof(int));
    int *arr_insertion = (int *)malloc(size * sizeof(int));
    int *arr_quickSort = (int *)malloc(size * sizeof(int));

    if (arr_burbuja == NULL || arr_insertion == NULL || arr_quickSort == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Generar valores aleatorios y copiarlos a los otros arreglos
    generarArray(arr_burbuja, size);
    memcpy(arr_insertion, arr_burbuja, size * sizeof(int));
    memcpy(arr_quickSort, arr_burbuja, size * sizeof(int));

    // Medir el tiempo de Bubble Sort
    inicio = clock();
    bubbleSort(arr_burbuja, size);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("\nTiempo en ordenar con Bubble Sort: %f segundos\n", tiempo);

    // Medir el tiempo de Insertion Sort
    inicio = clock();
    insertionSort(arr_insertion, size);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo en ordenar con Insertion Sort: %f segundos\n", tiempo);

    // Medir el tiempo de Quick Sort
    inicio = clock();
    quickSort(arr_quickSort, 0, size - 1);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo en ordenar con Quick Sort: %f segundos\n", tiempo);
   
    posicion_buscar = (int) rand()%(size+1);

    // Liberar memoria
    free(arr_burbuja);
    free(arr_insertion);
    free(arr_quickSort);

    return 0;
}


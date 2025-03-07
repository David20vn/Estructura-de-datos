#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Quicksort
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

// Generar un array aleatorio con valores más variados
void generarArray(int arr[], long int size) {
	long int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % (size*10); // Mayor rango de valores
    }
}

// Búsqueda secuencial
int sequentialSearch(int arr[], long int n, int x) {
	long int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

// Búsqueda binaria
int binarySearch(int arr[], long int low, long int high, int x) {
    while (low <= high) {
        long int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    srand(time(NULL));
    long int size;
    clock_t inicio, fin;
    double tiempo;
    int i;

    printf("Digite la longitud del array: ");
    scanf("%ld", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    generarArray(arr, size);
    quickSort(arr, 0, size - 1);

    int objetivo = arr[size - 1]; // Buscar el último número para mayor dificultad

    // Búsqueda secuencial (promedio de 100 ejecuciones)
    inicio = clock();
    for (i = 0; i < 100; i++) {
        sequentialSearch(arr, size, objetivo);
    }
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC / 100;
    printf("Tiempo promedio para busqueda secuencial: %f segundos\n", tiempo);

    // Búsqueda binaria (promedio de 100 ejecuciones)
    inicio = clock();
    for (i = 0; i < 100; i++) {
        binarySearch(arr, 0, size - 1, objetivo);
    }
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC / 100;
    printf("Tiempo promedio para busqueda binaria: %f segundos\n", tiempo);

    free(arr);
    return 0;
}

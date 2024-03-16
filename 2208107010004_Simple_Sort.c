#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumbers(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void saveToFile(int arr[], int n, const char *filename);

void printTableHeader() {
    printf(" ---------------------------------------------------------\n");
    printf("| Jenis Algoritma | Jumlah Bilangan | Waktu Eksekusi (ms) |\n");
    printf(" ---------------------------------------------------------\n");
}

void printTableRow(const char* algorithm, int n, double timeTaken) {
    printf("| %-16s| %-16d| %-20.2f|\n", algorithm, n, timeTaken);
}

void generateRandomNumbers(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void saveToFile(int arr[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int previous = arr[0] - 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] != previous) {
            fprintf(file, "%d\n", arr[i]);
            previous = arr[i];
        }
    }

    fclose(file);
}


int main() {
    int maxNumbers = 1000000;
    int increment = 100000;

    printTableHeader();

    // Bubble Sort
    for (int n = increment; n <= maxNumbers; n += increment) {
        int *arr = (int *)malloc(n * sizeof(int));

        generateRandomNumbers(arr, n);

        char unsorted_filename[20];
        sprintf(unsorted_filename, "unsorted_%d.txt", n);
        saveToFile(arr, n, unsorted_filename);

        clock_t start = clock();
        bubbleSort(arr, n);
        clock_t end = clock();
        double timeTakenBubble = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        printTableRow("Bubble Sort", n, timeTakenBubble);

        char sorted_filename[20];
        sprintf(sorted_filename, "sorted_%d.txt", n);
        saveToFile(arr, n, sorted_filename);

        free(arr);
    }

    printf("| ---------------------------------------------------------|\n");

    // Selection Sort
    for (int n = increment; n <= maxNumbers; n += increment) {
        int *arr = (int *)malloc(n * sizeof(int));

        generateRandomNumbers(arr, n);

        char unsorted_filename[20];
        sprintf(unsorted_filename, "unsorted_%d.txt", n);
        saveToFile(arr, n, unsorted_filename);

        clock_t start = clock();
        selectionSort(arr, n);
        clock_t end = clock();
        double timeTakenSelection = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        printTableRow("Selection Sort", n, timeTakenSelection);

        char sorted_filename[20];
        sprintf(sorted_filename, "sorted_%d.txt", n);
        saveToFile(arr, n, sorted_filename);

        free(arr);
    }

    printf("| ---------------------------------------------------------|\n");


    // Insertion Sort
    for (int n = increment; n <= maxNumbers; n += increment) {
        int *arr = (int *)malloc(n * sizeof(int));

        generateRandomNumbers(arr, n);

        char unsorted_filename[20];
        sprintf(unsorted_filename, "unsorted_%d.txt", n);
        saveToFile(arr, n, unsorted_filename);

        clock_t start = clock();
        insertionSort(arr, n);
        clock_t end = clock();
        double timeTakenInsertion = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

        printTableRow("Insertion Sort", n, timeTakenInsertion);

        char sorted_filename[20];
        sprintf(sorted_filename, "sorted_%d.txt", n);
        saveToFile(arr, n, sorted_filename);

        free(arr);
    }

    return 0;
}
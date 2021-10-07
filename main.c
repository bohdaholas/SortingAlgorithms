#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sorting_algorithms.h"

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void fill_up_array(int array[], int n, int experiment) {
    if (experiment == 1) {
        for (int i = 0; i < n; ++i) {
            array[i] = rand() % n;
        }
    } else if (experiment == 2) {
        for (int i = 0; i < n; ++i) {
            array[i] = i;
        }
    } else if (experiment == 3) {
        for (int i = 0; i < n; ++i) {
            array[i] = n - i;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            array[i] = (rand() % 3) + 1;
        }
    }
}

int main() {
    for (int experiment = 1; experiment <= 4; ++experiment) {
        printf("Experiment: %d\n", experiment);
        for (size_t n = pow(2, 7); n <= pow(2, 15); n *= 2) {
            printf("Array size: %d\n\n", n);
            int array[n];
            clock_t start, end;
            double cpu_time_used;
            int comp;

            fill_up_array(array, n, experiment);
            start = clock();
            comp = insertionSort(array, n);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Insertion sort:\nTime:%f\nComparisons:%d\n\n", cpu_time_used, comp);

            fill_up_array(array, n, experiment);
            start = clock();
            comp = selectionSort(array, n);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Selection sort:\nTime:%f\nComparisons:%d\n\n", cpu_time_used, comp);

            fill_up_array(array, n, experiment);
            start = clock();
            comp = shellSort(array, n);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Shell sort:\nTime:%f\nComparisons:%d\n\n", cpu_time_used, comp);

            fill_up_array(array, n, experiment);
            start = clock();
            comp = mergeSort(array, 0, n - 1);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Merge sort:\nTime:%f\nComparisons:%d\n\n", cpu_time_used, comp);
        }
        printf("\n");
    }
    return 0;
}

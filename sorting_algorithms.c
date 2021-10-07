#include "sorting_algorithms.h"

int selectionSort(int arr[], int n) {
    int i, j, min_idx;
    int comp = 0;
    for (i = 0; i < n-1; i++) {
        comp++;
        min_idx = i;
        for (j = i+1; j < n; j++) {
            comp++;
            if (arr[j] < arr[min_idx]) {
                comp++;
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = arr[min_idx];
        arr[i] = temp;
    }
    return comp;
}

int insertionSort(int arr[], int n) {
    int i, key, j;
    int comp = 0;
    for (i = 1; i < n; i++) {
        comp++;
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comp += 2;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return comp;
}

int shellSort(int arr[], int n) {
    int comp = 0;
    for (int gap = n/2; gap > 0; gap /= 2) {
        comp++;
        for (int i = gap; i < n; i += 1) {
            comp++;
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comp += 2;
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return comp;
}

int merge(int arr[], int l, int m, int r) {
    static int comp = 0;
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        comp++;
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        comp++;
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        comp += 3;
        k++;
    }
    while (i < n1) {
        comp++;
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        comp++;
        arr[k] = R[j];
        j++;
        k++;
    }
    return comp;
}

int mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        int comp = merge(arr, l, m, r);
        return comp;
    }
    return -1;
}

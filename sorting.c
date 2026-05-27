#include "sorting.h"

// Utilitas umum

// Tukar nilai dua integer
void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Tukar nilai dua string
void swapString(char a[], char b[]) {
    char temp[MAX_WORD_LEN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// Utilitas data dasar

// Generate data integer random
void generateDataDasar(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

// Mengacak data integer
void shuffleDataDasar(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swapInt(&arr[i], &arr[j]);
    }
}

// Menampilkan data integer
void printDataDasar(int arr[], int n, int limit) {
    int tampil = (n < limit) ? n : limit;

    for (int i = 0; i < tampil; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Utilitas data advance

// Mengacak data string
void shuffleDataAdvance(char words[][MAX_WORD_LEN], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swapString(words[i], words[j]);
    }
}

// Menampilkan data string
void printDataAdvance(char words[][MAX_WORD_LEN], int n, int limit) {
    int tampil = (n < limit) ? n : limit;

    for (int i = 0; i < tampil; i++) {
        printf("%s\n", words[i]);
    }

    printf("\n");
}

// Membaca dataset dari file txt
int readWordsFromFile(const char *filename, char words[][MAX_WORD_LEN]) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File tidak ditemukan!\n");
        return 0;
    }

    int count = 0;

    while (count < MAX_WORDS && fscanf(fp, "%99s", words[count]) == 1) {
        count++;
    }

    fclose(fp);

    return count;
}

// Bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapInt(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swapInt(&arr[i], &arr[minIndex]);
    }
}

// Merge process
void merge(char words[][MAX_WORD_LEN], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    char L[n1][MAX_WORD_LEN];
    char R[n2][MAX_WORD_LEN];

    for (int i = 0; i < n1; i++) {
        strcpy(L[i], words[left + i]);
    }

    for (int j = 0; j < n2; j++) {
        strcpy(R[j], words[mid + 1 + j]);
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(words[k], L[i]);
            i++;
        } 
        else {
            strcpy(words[k], R[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(words[k], L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(words[k], R[j]);
        j++;
        k++;
    }
}

// Merge sort
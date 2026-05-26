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
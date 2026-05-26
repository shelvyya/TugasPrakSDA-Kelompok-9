#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Konstanta
#define MAX_DATA_DASAR 1000
#define MAX_WORDS 50000
#define MAX_WORD_LEN 100

// Jumlah data yang ditampilkan
#define DISPLAY_LIMIT_DASAR 10
#define DISPLAY_LIMIT_ADVANCE 30

// Fungsi utilitas umum
void swapInt(int *a, int *b);
void swapString(char a[], char b[]);

// Fungsi data sorting dasar
void generateDataDasar(int arr[], int n);
void shuffleDataDasar(int arr[], int n);
void printDataDasar(int arr[], int n, int limit);

// Fungsi data advance sorting
int readWordsFromFile(const char *filename, char words[][MAX_WORD_LEN]);
void shuffleDataAdvance(char words[][MAX_WORD_LEN], int n);
void printDataAdvance(char words[][MAX_WORD_LEN], int n, int limit);

// Algoritma sorting dasar
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);

// Algoritma advance sorting
void mergeSort(char words[][MAX_WORD_LEN], int left, int right);
void quickSort(char words[][MAX_WORD_LEN], int low, int high);
void shellSort(char words[][MAX_WORD_LEN], int n);

#endif
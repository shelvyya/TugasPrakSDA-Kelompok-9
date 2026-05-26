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
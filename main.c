#include "sorting.h"

// Array global dataset string
char words[MAX_WORDS][MAX_WORD_LEN];

int main() {

    int menuUtama, menuDasar, menuAdvance;
    int dataDasar[MAX_DATA_DASAR];
    int jumlahWords = 0;
    clock_t start, end;
    double waktu;

    srand(time(NULL));

    do {
        printf("\n===== MENU UTAMA =====\n");
        printf("1. Sorting Dasar\n");
        printf("2. Advance Sorting\n");
        printf("3. Keluar\n");
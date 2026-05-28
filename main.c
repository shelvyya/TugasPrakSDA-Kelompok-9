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
        printf("Pilih menu : ");
        scanf("%d", &menuUtama);

        switch(menuUtama) {
            case 1:
                do {
                    printf("\n===== SORTING DASAR =====\n");
                    printf("1. Bubble Sort\n");
                    printf("2. Insertion Sort\n");
                    printf("3. Selection Sort\n");
                    printf("4. Kembali\n");
                    printf("Pilih metode : ");
                    scanf("%d", &menuDasar);

                    if(menuDasar >= 1 && menuDasar <= 3) {
                        generateDataDasar(dataDasar, MAX_DATA_DASAR);
                        shuffleDataDasar(dataDasar, MAX_DATA_DASAR);
                        printf("\nData sebelum sorting:\n");
                        printDataDasar(dataDasar, MAX_DATA_DASAR, DISPLAY_LIMIT_DASAR);

                        start = clock();

                        switch(menuDasar) {
                            case 1:
                                bubbleSort(dataDasar, MAX_DATA_DASAR);
                                printf("\nMetode: Bubble Sort\n");
                                break;
                            case 2:
                                insertionSort(dataDasar, MAX_DATA_DASAR);
                                printf("\nMetode: Insertion Sort\n");
                                break;
                            case 3:
                                selectionSort(dataDasar, MAX_DATA_DASAR);
                                printf("\nMetode: Selection Sort\n");
                                break;
                        }
                        end = clock();

                        waktu = ((double)(end - start)) / CLOCKS_PER_SEC;

                        printf("\nData setelah sorting:\n");
                        printDataDasar(dataDasar, MAX_DATA_DASAR, DISPLAY_LIMIT_DASAR);
                        printf("\nWaktu eksekusi: %.5f detik\n", waktu);
                    }
                } 
                while(menuDasar != 4);
                
                break;

            case 2:
                do {
                    printf("\n===== ADVANCE SORTING =====\n");
                    printf("1. Merge Sort\n");
                    printf("2. Quick Sort\n");
                    printf("3. Shell Sort\n");
                    printf("4. Kembali\n");
                    printf("Pilih metode : ");
                    scanf("%d", &menuAdvance);

                    if(menuAdvance >= 1 && menuAdvance <= 3) {
                        jumlahWords = readWordsFromFile("words.txt", words);
                        if(jumlahWords == 0) {
                            printf("\nDataset gagal dibaca!\n");
                            break;
                        }

                        shuffleDataAdvance(words, jumlahWords);

                        printf("\nData sebelum sorting:\n");
                        printDataAdvance(words, jumlahWords, DISPLAY_LIMIT_ADVANCE);
                        start = clock();

                        switch(menuAdvance) {
                            case 1:
                                mergeSort(words, 0, jumlahWords - 1);
                                printf("\nMetode: Merge Sort\n");
                                break;
                            case 2:
                                quickSort(words, 0, jumlahWords - 1);
                                printf("\nMetode: Quick Sort\n");
                                break;
                            case 3:
                                shellSort(words, jumlahWords);
                                printf("\nMetode: Shell Sort\n");
                                break;
                        }
                        end = clock();

                        waktu = ((double)(end - start)) / CLOCKS_PER_SEC;

                        printf("\nData setelah sorting:\n");
                        printDataAdvance(words, jumlahWords, DISPLAY_LIMIT_ADVANCE);
                        printf("\nJumlah data: %d kata\n", jumlahWords);
                        printf("Waktu eksekusi: %.5f detik\n", waktu);
                    }
                } while(menuAdvance != 4);
                break;
            case 3:
                printf("\nProgram selesai.\n");
                break;
            default:
                printf("\nPilihan tidak valid!\n");
        }
    } 
    while(menuUtama != 3);

    return 0;
}
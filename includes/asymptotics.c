//
// Created by xed22 on 12.03.2022.
//

#include "sorts.h"
#include <time.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof (a[0]);

#define TIME_TEST(testCode, time) { \
    clock_t start_time = clock();       \
    testCode                           \
    clock_t end_time = clock();         \
    clock_t sort_time = end_time - start_time; \
    time = (double) sort_time / CLOCKS_PER_SEC ; \
}

typedef struct SortFunc {
    void (*sort)(int *const a, const size_t n);

    char name[64];
} SortFunc;

typedef struct GeneratingFunc {
    void (*generate)(int *const a, const size_t n);

    char name[64];
} GeneratingFunc;

double getTime() {
    clock_t start_time = clock();
    // фрагмент кода
    // время которого измеряется
    clock_t end_time = clock();
    clock_t sort_time = end_time - start_time;
    return (double) sort_time / CLOCKS_PER_SEC;
}

void checkTime(void (*sortFunc )(int *, size_t),
               void (*generateFunc )(int *, size_t),
               size_t size, char *experimentName) {

    static size_t runCounter = 1;
// генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf(" Run #% zu| ", runCounter++);
    printf(" Name : %s\n", experimentName);

    double time;
    TIME_TEST({
                  sortFunc(innerBuffer, size);
              }, time);
}

void timeExperiment() {
    // описание функций сортировки
    SortFunc sorts[] = {
            {selectionSort, " selectionSort "},
            {insertionSort, " insertionSort "},
            {bubbleSort,    " bubbleSort "},
            {shellSort,     " shellSort "},
            {combSort,      " combSort "},
            {countSort,     " countSort "},
            {qSort,         " qSort "},
            {mergeSort,     " mergeSort "},
            // вы добавите свои сортировки
    };
    const unsigned FUNCS_N = ARRAY_SIZE (sorts);

    // описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            // генерируется случайный массив
            {generateRandomArray,      " random "},
            // генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray,     " ordered "},
            // генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwards, " orderedBackwards "}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    // запись статистики в файл
    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf(" ------------------------------\n");
        printf(" Size : %d\n", size);
        for (register size_t i = 0; i < FUNCS_N; i++) {
            for (register size_t j = 0; j < CASES_N; j++) {
                // генерация имени файла
                static char filename[128] = "statTime";
                sprintf(filename, "%s_% s_time ",
                        sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].sort,
                          generatingFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }
}
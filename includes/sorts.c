//
// Created by xed22 on 12.03.2022.
//

#include "sorts.h"

#define GET_INDEX_LEFT_CHILD(i) i * 2 + 1
#define GET_INDEX_RIGHT_CHILD(i) i * 2 + 2

void swap(int *a, int *b) {
    const int t = *a;
    *a = *b;
    *b = t;
}

void inputArray(int *const a, const size_t n) {
    for (register size_t i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}

void outputArray(const int *const a, const size_t n) {
    for (register size_t i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

bool isOrdered(const int *a, const size_t n) {
    for (register size_t i = 1; i < n; ++i)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

void append(int *const a, size_t *n, const int x) {
    a[*n] = x;
    (*n)++;
}

// Сортировка Выбором >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void selectionSort(int *a, const size_t n) {
    for (register size_t i = 0; i < n; ++i) {
        size_t indexMin = i;
        for (register size_t j = i + 1; j < n; ++j)
            if (a[j] < a[indexMin])
                indexMin = j;
        if (indexMin != i)
            swap(&a[i], &a[indexMin]);
    }
}

unsigned long long selectionSortNComp(int *a, const size_t n) {
    unsigned long long nComp = 0;
    for (register size_t i = 0; ++nComp && i < n; ++i) {
        size_t indexMin = i;
        for (register size_t j = i + 1; ++nComp && j < n; ++j)
            if (++nComp && a[j] < a[indexMin])
                indexMin = j;
        if (++nComp && indexMin != i)
            swap(&a[i], &a[indexMin]);
    }

    return nComp;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Вставками >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void insertionSort(int *a, const size_t n) {
    for (register size_t i = 1; i < n; ++i) {
        int t = a[i];
        register size_t j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

unsigned long long insertionSortNComp(int *a, const size_t n) {
    unsigned long long nComp = 0;
    for (register size_t i = 1; ++nComp && i < n; ++i) {
        int t = a[i];
        register size_t j = i;
        while (++nComp && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }

    return nComp;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Соритровка Пузырьком >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void bubbleSort(int *a, const size_t n) {
    for (register size_t i = 0; i < n - 1; ++i)
        for (register size_t j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
                swap(&a[j - 1], &a[j]);
}

unsigned long long bubbleSortNComp(int *a, const size_t n) {
    unsigned long long nComp = 0;
    for (register size_t i = 0; ++nComp && i < n - 1; ++i)
        for (register size_t j = n - 1; ++nComp && j > i; j--)
            if (++nComp && a[j] < a[j - 1])
                swap(&a[j - 1], &a[j]);
    return nComp;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Соритровка Расческой >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void combSort(int *a, const size_t n) {
    size_t step = n;
    bool swapped = true;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = false;
        for (register size_t i = 0, j = i + step; j < n; ++i, ++j) {
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = true;
            }
        }
    }
}

unsigned long long combSortNComp(int *a, const size_t n) {
    size_t step = n;
    bool swapped = true;
    unsigned long long nComp = 0;
    while ((step > 1 || swapped) && ++nComp) {
        if (++nComp && step > 1)
            step /= 1.24733;
        swapped = false;
        for (register size_t i = 0, j = i + step; ++nComp && j < n; ++i, ++j) {
            if (++nComp && a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = true;
            }
        }
    }

    return nComp;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Быстрая сортировка >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void qSort(int *a, const size_t n) {
    assert(n > 0);

    register int leftBorder = 0;
    register int rightBorder = n - 1;
    int middle = leftBorder + (rightBorder - leftBorder) / 2;
    int t = a[middle];

    do {
        // часть , где числа меньше t
        while (a[leftBorder] < t)
            leftBorder++;
        // часть , где числа больше t
        while (a[rightBorder] > t)
            rightBorder--;
        if (leftBorder <= rightBorder) {
            swap(&a[rightBorder], &a[leftBorder]);
            leftBorder++;
            rightBorder--;
        }
    } while (leftBorder <= rightBorder);

    if (leftBorder < n)
        qSort(a + leftBorder, n - leftBorder);
    if (rightBorder > 0)
        qSort(a, rightBorder + 1);
}

unsigned long long qSortNComp(int *a, const size_t n) {
    assert(n > 0);

    static unsigned long long nComp;
    register int leftBorder = 0;
    register int rightBorder = n - 1;
    int middle = leftBorder + (rightBorder - leftBorder) / 2;
    int t = a[middle];

    do {
        // часть , где числа меньше t
        while (++nComp && a[leftBorder] < t)
            leftBorder++;
        // часть , где числа больше t
        while (++nComp && a[rightBorder] > t)
            rightBorder--;
        if (++nComp && leftBorder <= rightBorder) {
            swap(&a[rightBorder], &a[leftBorder]);
            leftBorder++;
            rightBorder--;
        }
    } while (++nComp && leftBorder <= rightBorder);

    if (++nComp && leftBorder < n)
        qSort(a + leftBorder, n - leftBorder);
    if (++nComp && rightBorder > 0)
        qSort(a, rightBorder + 1);

    return nComp;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Подсчетом >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int getMinElemArray(const int *a, const size_t n) {
    int elemMin = a[0];
    for (register size_t i = 1; i < n; ++i)
        if (a[i] < elemMin)
            elemMin = a[i];

    return elemMin;
}

int getMaxElemArray(const int *a, const size_t n) {
    int elemMax = a[0];
    for (register size_t i = 1; i < n; ++i)
        if (a[i] > elemMax)
            elemMax = a[i];

    return elemMax;
}

void countSort(int *a, const size_t n) {
    assert(n > 0);

    int elemMin = getMinElemArray(a, n);
    int elemMax = getMaxElemArray(a, n);
    size_t sizeArrayCountNumbers = elemMax - elemMin + 1;
    int *arrayCountNumbers = (int *) calloc(sizeArrayCountNumbers, sizeof(int));
    for (register size_t i = 0; i < n; ++i)
        arrayCountNumbers[a[i] - elemMin]++;

    size_t k = 0;
    for (register int i = 0; i < sizeArrayCountNumbers; ++i) {
        int x = arrayCountNumbers[i];
        for (register size_t j = 0; j < x; ++j)
            a[k++] = elemMin + i;
    }

    free(arrayCountNumbers);
}

unsigned long long countSortNComp(int *a, const size_t n) {
    assert(n > 0);

    unsigned long long nComp = 0;
    int elemMin = getMinElemArray(a, n);
    int elemMax = getMaxElemArray(a, n);
    size_t sizeArrayCountNumbers = elemMax - elemMin + 1;
    int *arrayCountNumbers = (int *) calloc(sizeArrayCountNumbers, sizeof(int));
    for (register size_t i = 0; ++nComp && i < n; ++i)
        arrayCountNumbers[a[i] - elemMin]++;

    size_t k = 0;
    for (register int i = 0; ++nComp && i < sizeArrayCountNumbers; ++i) {
        int x = arrayCountNumbers[i];
        for (register size_t j = 0; ++nComp && j < x; ++j)
            a[k++] = elemMin + i;
    }

    free(arrayCountNumbers);

    return nComp;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Слиянием >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void merge(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c) {
    register size_t iReadA = 0;
    register size_t iReadB = 0;
    while (iReadA < sizeA || iReadB < sizeB) {
        if (iReadB == sizeB || iReadA < sizeA && a[iReadA] < b[iReadB]) {
            c[iReadA + iReadB] = a[iReadA];
            iReadA++;
        } else {
            c[iReadA + iReadB] = b[iReadB];
            iReadB++;
        }
    }
}

static void
mergeSort_(int *source, const size_t leftBorder, const size_t rightBorder, int *buffer) {
    int sizeSource = (int) rightBorder - leftBorder;
    if (sizeSource <= 1)
        return;

    size_t middle = (leftBorder + rightBorder) / 2;
    mergeSort_(source, leftBorder, middle, buffer);
    mergeSort_(source, middle, rightBorder, buffer);

    merge(source + leftBorder, middle - leftBorder, source + middle, rightBorder - middle, buffer);

    if (memcmp(source + leftBorder, buffer, sizeSource * sizeof(int)) != 0)
        memcpy(source + leftBorder, buffer, sizeSource * sizeof(int));
}

void mergeSort(int *a, const size_t n) {
    int *buffer = (int *) malloc(n * sizeof(int));
    mergeSort_(a, 0, n, buffer);

    free(buffer);
}

unsigned long long mergeNComp(const int *a, const size_t sizeA, const int *b, const size_t sizeB, int *c) {
    unsigned long long nComp = 0;
    register size_t iReadA = 0;
    register size_t iReadB = 0;
    while (++nComp && (iReadA < sizeA || iReadB < sizeB)) {
        if (++nComp && (iReadB == sizeB || iReadA < sizeA && a[iReadA] < b[iReadB])) {
            c[iReadA + iReadB] = a[iReadA];
            iReadA++;
        } else {
            c[iReadA + iReadB] = b[iReadB];
            iReadB++;
        }
    }

    return nComp;
}

static unsigned long long
mergeSortNComp_(int *source, const size_t leftBorder, const size_t rightBorder, int *buffer) {
    static unsigned long long nComp;
    int sizeSource = (int) rightBorder - leftBorder;
    if (++nComp && sizeSource <= 1)
        return 0;

    size_t middle = (leftBorder + rightBorder) / 2;
    nComp += mergeSortNComp_(source, leftBorder, middle, buffer);
    nComp += mergeSortNComp_(source, middle, rightBorder, buffer);

    nComp += mergeNComp(source + leftBorder, middle - leftBorder, source + middle, rightBorder - middle, buffer);

    if (++nComp && memcmp(source + leftBorder, buffer, sizeSource * sizeof(int)) != 0)
        memcpy(source + leftBorder, buffer, sizeSource * sizeof(int));

    return nComp;
}

unsigned long long mergeSortNComp(int *a, const size_t n) {
    int *buffer = (int *) malloc(n * sizeof(int));
    int nComp = mergeSortNComp_(a, 0, n, buffer);
    free(buffer);

    return nComp;

}

// Сортировка Шелла >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void shellSort(int *const a, const size_t n) {
    for (register size_t s = n / 2; s > 0; s /= 2) {
        for (register int i = s; i < n; ++i) {
            for (register int j = i - s; j >= 0 && a[j] > a[j + s]; j -= s)
                swap(&a[j], &a[j + s]);
        }
    }
}

unsigned long long shellSortNComp(int *const a, const size_t n) {
    unsigned long long nComp = 0;
    for (register size_t s = n / 2; ++nComp && s > 0; s /= 2) {
        for (register int i = s; ++nComp && i < n; ++i) {
            for (register int j = i - s; ++nComp && j >= 0 && a[j] > a[j + s]; j -= s)
                swap(&a[j], &a[j + s]);
        }
    }

    return nComp;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Гномья >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void gnomeSort(int *const a, const size_t n) {
    register size_t i = 1;
    while (i < n) {
        if (a[i - 1] <= a[i])
            i++;
        else {
            swap(&a[i - 1], &a[i]);
            i = i > 1 ? i - 1 : i;
        }
    }
}

unsigned long long gnomeSortNComp(int *const a, const size_t n) {
    register size_t i = 1;
    unsigned long long nComp = 0;
    while (++nComp && i < n) {
        if (++nComp && a[i - 1] <= a[i])
            i++;
        else {
            swap(&a[i - 1], &a[i]);
            i = ++nComp && i > 1 ? i - 1 : i;
        }
    }

    return nComp;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Гномья (оптимизация) >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void gnomeSortOptimaze(int *const a, const size_t n) {
    register size_t i = 1;
    register size_t j = 2;
    while (i < n) {
        if (a[i - 1] <= a[i]) {
            i = j;
            j++;
        } else {
            swap(&a[i - 1], &a[i]);
            i--;
            if (!i) {
                i = j;
                j++;
            }
        }
    }
}

unsigned long long gnomeSortOptimazeNComp(int *const a, const size_t n) {
    register size_t i = 1;
    register size_t j = 2;
    unsigned long long nComp = 0;
    while (++nComp && i < n) {
        if (++nComp && a[i - 1] <= a[i]) {
            i = j;
            j++;
        } else {
            swap(&a[i - 1], &a[i]);
            i--;
            if (++nComp && !i) {
                i = j;
                j++;
            }
        }
    }

    return nComp;
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int compareInts(const void *a, const void *b) {
    return *(const int *) a - *(const int *) b;
}

// Нестандартные сортировки <><><><><>
// **********************************************************************

// Цифровая сортировка **********************************************************************
void getPrefSumArray(int *const a, const size_t n) {
    for (register size_t i = 1; i < n; ++i)
        a[i] += a[i - 1];
}

void countSortByExp(int *const a, const size_t n, const unsigned int exp) {
    int *outputArray = (int *) malloc(n * sizeof(int));
    int counter[4] = {0};

    for (register size_t i = 0; i < n; i++)
        counter[(a[i] >> exp) & 3]++;
    getPrefSumArray(counter, 4);

    for (register int i = n - 1; i >= 0; i--) {
        outputArray[counter[(a[i] >> exp) & 3] - 1] = a[i];
        counter[(a[i] >> exp) & 3]--;
    }

    for (register size_t i = 0; i < n; i++)
        a[i] = outputArray[i];

    free(outputArray);
}

void radixSort(int *const a, const size_t n) {
    int max = getMaxElemArray(a, n);

    for (int exp = 0; max >> exp > 0; exp += 2)
        countSortByExp(a, n, exp);
}

unsigned long long countSortByExpNComp(int *const a, const size_t n, const unsigned int exp) {
    unsigned long long nComp = 0;
    int *outputArray = (int *) malloc(n * sizeof(int));
    int counter[4] = {0};

    for (register size_t i = 0; ++nComp && i < n; i++)
        counter[(a[i] >> exp) & 3]++;
    getPrefSumArray(counter, 4);

    for (register int i = n - 1; ++nComp && i >= 0; i--) {
        outputArray[counter[(a[i] >> exp) & 3] - 1] = a[i];
        counter[(a[i] >> exp) & 3]--;
    }

    for (register size_t i = 0; ++nComp && i < n; i++)
        a[i] = outputArray[i];

    free(outputArray);

    return nComp;
}

unsigned long long radixSortNComp(int *const a, const size_t n) {
    int max = getMaxElemArray(a, n);
    unsigned long long nComp = 0;

    for (int exp = 0; ++nComp && max >> exp > 0; exp += 2)
        nComp += countSortByExpNComp(a, n, exp);

    return nComp;
}
// ************************************************************************************

// Сортировка кучей **********************************************************************
typedef struct parent {
    size_t indexParent;
    size_t indexLeftChild;
    size_t indexRightChild;
} parent;

void heapify(int *const a, const size_t n, const size_t i) {
    parent p = {i, GET_INDEX_LEFT_CHILD(i), GET_INDEX_RIGHT_CHILD(i)};

    if (p.indexLeftChild < n && a[p.indexLeftChild] > a[p.indexParent])
        p.indexParent = p.indexLeftChild;

    if (p.indexRightChild < n && a[p.indexRightChild] > a[p.indexParent])
        p.indexParent = p.indexRightChild;

    if (p.indexParent != i) {
        swap(&a[i], &a[p.indexParent]);

        // Создание сортирующей кучи
        heapify(a, n, p.indexParent);
    }
}

void heapSort(int *const a, const size_t n) {
    for (register int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (register size_t i = n - 1; i > 0; i--) {
        // Добавление отсортированого элемента в конец кучи
        swap(&a[0], &a[i]);

        heapify(a, i, 0);
    }
}

unsigned long long heapifyNComp(int *const a, const size_t n, const size_t i, const unsigned long long counter) {
    parent p = {i, GET_INDEX_LEFT_CHILD(i), GET_INDEX_RIGHT_CHILD(i)};
    unsigned long long nComp = counter;

    if (++nComp && p.indexLeftChild < n && a[p.indexLeftChild] > a[p.indexParent])
        p.indexParent = p.indexLeftChild;

    if (++nComp && p.indexRightChild < n && a[p.indexRightChild] > a[p.indexParent])
        p.indexParent = p.indexRightChild;

    if (++nComp && p.indexParent != i) {
        swap(&a[i], &a[p.indexParent]);

        // Создание сортирующей кучи
        heapifyNComp(a, n, p.indexParent, nComp);
    }

    return nComp;
}

unsigned long long heapSortNComp(int *const a, const size_t n) {
    unsigned long long nComp = 0;
    for (register int i = n / 2 - 1; ++nComp && i >= 0; i--)
        nComp += heapifyNComp(a, n, i, 0);

    for (register size_t i = n - 1; ++nComp && i > 0; i--) {
        // Добавление отсортированого элемента в конец кучи
        swap(&a[0], &a[i]);

        nComp += heapifyNComp(a, i, 0, 0);
    }

    return nComp;
}
// ************************************************************************************

// Блинная сортировка *****************************************************************
void reverseArray(int *const a, const size_t n) {
    for (register int *i = a, *j = a + n; i < j; i++, j--)
        swap(j, i);
}

size_t getMaxIndex(const int *const a, const size_t n) {
    size_t maxIndex = 0;
    int maxElem = a[0];
    for (register size_t i = 1; i < n; ++i)
        if (a[i] > maxElem) {
            maxElem = a[i];
            maxIndex = i;
        }

    return maxIndex;
}

void pancakeSort(int *const a, const size_t n) {
    for (register size_t currentSize = n; currentSize > 0; currentSize--) {
        size_t maxIndex = getMaxIndex(a, currentSize);

        if (maxIndex != currentSize - 1) {
            reverseArray(a, maxIndex);
            reverseArray(a, currentSize - 1);
        }
    }
}

unsigned long long reverseArrayNComp(int *const a, const size_t n) {
    unsigned long long nComp = 0;
    for (register int *i = a, *j = a + n; ++nComp && i < j; i++, j--)
        swap(j, i);

    return nComp;
}

unsigned long long pancakeSortNComp(int *const a, const size_t n) {
    unsigned long long nComp = 0;
    for (register size_t currentSize = n; ++nComp && currentSize > 0; currentSize--) {
        size_t maxIndex = getMaxIndex(a, currentSize);

        if (++nComp && maxIndex != currentSize - 1) {
            nComp += reverseArrayNComp(a, maxIndex);
            nComp += reverseArrayNComp(a, currentSize - 1);
        }
    }

    return nComp;
}

// ************************************************************************************
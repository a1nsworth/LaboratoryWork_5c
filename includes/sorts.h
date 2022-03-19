//
// Created by xed22 on 12.03.2022.
//

#ifndef LABA5C_SORTS_H
#define LABA5C_SORTS_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>

void swap(int *a, int *b);

void inputArray(int *a, size_t n);

void outputArray(const int *a, size_t n);

bool isOrdered(const int *a, size_t n);

void append(int *a, size_t *n, int x);

void getPresSumArray(int *a, size_t n);

size_t getMaxPos(const int *a, size_t n);

// Сортировка Выбором >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void selectionSort(int *a, size_t n);

unsigned long long selectionSortNComp(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Вставками >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void insertionSort(int *a, size_t n);

unsigned long long insertionSortNComp(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Соритровка Пузырьком >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void bubbleSort(int *a, size_t n);

unsigned long long bubbleSortNComp(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void combSort(int *a, size_t n);

unsigned long long combSortNComp(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Быстрая сортировка >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void qSort(int *a, size_t n);

unsigned long long qSortNComp(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Подсчетом >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int getMinElemArray(const int *a, size_t n);

int getMaxElemArray(const int *a, size_t n);

size_t getMaxIndex(const int *a, size_t n);

void countSort(int *a, size_t n);

unsigned long long countSortNComp(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Слиянием >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void merge(const int *a, size_t sizeA, const int *b, size_t sizeB, int *c);

unsigned long long mergeNComp(const int *a, size_t sizeA, const int *b, size_t sizeB, int *c);

static void
mergeSort_(int *source, size_t leftBorder, size_t rightBorder, int *buffer);

static unsigned long long
mergeSortNComp_(int *source, size_t leftBorder, size_t rightBorder, int *buffer);

void mergeSort(int *a, size_t n);

unsigned long long mergeSortNComp(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Шелла >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void shellSort(int *a, size_t n);

unsigned long long shellSortNComp(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Гномья >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void gnomeSort(int *a, size_t n);

unsigned long long gnomeSortNComp(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Сортировка Гномья(оптимизация) >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void gnomeSortOptimaze(int *a, size_t n);

unsigned long long gnomeSortOptimazeNComp(int *a, size_t n);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int compareInts(const void *a, const void *b);

// Цифровая сортировка >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void countSortByExp(int *a, size_t n, unsigned int exp);

unsigned long long countSortByExpNComp(int *a, size_t n, unsigned int exp);

void radixSort(int *a, size_t n);

unsigned long long radixSortNComp(int *a, size_t n);

void heapify(int *a, size_t n, size_t i);

unsigned long long heapifyNComp(int *a, size_t n, size_t i, unsigned long long counter);

void heapSort(int *a, size_t n);

unsigned long long heapSortNComp(int *a, size_t n);

void reverseArray(int *a, size_t n);

unsigned long long reverseArrayNComp(int *a, size_t n);

void pancakeSort(int *a, size_t n);

unsigned long long pancakeSortNComp(int *a, size_t n);

#endif //LABA5C_SORTS_H

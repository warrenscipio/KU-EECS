// Sorts.h - declaration of template-based sort algorithms

#ifndef SORTS_H
#define SORTS_H

template <typename T>
void bubbleSort(T theArray[], long n);

template <typename T>
void insertionSort(T theArray[], long n);

template <typename T>
void mergesort(T theArray[], long size);

template <typename T>
void quicksort(T theArray[], long size);

template <typename T>
void selectionSort(T theArray[], long n);

#include "bubbleSort.c++"
#include "insertionSort.c++"
#include "mergesort.c++"
#include "quicksort.c++"
#include "selectionSort.c++"

#endif

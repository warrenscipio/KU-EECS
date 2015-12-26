// Sorts.h - declaration of template-based sort algorithms

#ifndef SORTS_H
#define SORTS_H

template <typename T>
void bubbleSort(T theArray[], long n);

template <typename T>
void insertionSort(T theArray[], long n);

template <typename T>
void mergesort(T theArray[], long size, long thresh, int n);

template <typename T>
void quicksort(T theArray[], long size, long thresh, int n);



#include "bubbleSort.c++"
#include "insertionSort.c++"
#include "mergesort.c++"
#include "quicksort.c++"


#endif
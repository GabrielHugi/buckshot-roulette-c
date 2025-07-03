#include "tools.h"

void quickSort(int* array, int min, int max) {
  if (min < max) {
    int pp = partition(array, min, max);
    quickSort(array, min, pp-1);
    quickSort(array, pp+1, max);
  }
}

int partition(int* array, int min, int max) {
  int posMinimum = min; int posMaximum = max;
  int pivot = array[min];
  while(posMinimum < posMaximum) {
    while (array[posMinimum] <= pivot && posMinimum < max) {
      posMinimum++;
    }
    while (array[posMaximum] > pivot && posMaximum > min) {
      posMaximum--;
    }
    if (posMinimum < posMaximum) swap(&array[posMinimum], &array[posMaximum]);    
  }
  if (min != posMaximum) swap(&array[min], &array[posMaximum]);
  return posMaximum;
}

void swap(int* a, int* b) {
  int t=*a; *a=*b; *b=t;
}
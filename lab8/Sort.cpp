#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <memory.h>
#include <cstdlib>
#include <sys/time.h>
#include "Sort.h"
#include <algorithm> 
using namespace std;

void merge(int *array, int *tmpArray, int start, int mid, int end){

    int i = start;
    int j = mid;
    int k = 0;
    while(i < mid && j < end){
        if (array[i] < array[j]){
            tmpArray[k] = array[i];
            ++i;
        }else{
            tmpArray[k] = array[j];
            ++j;
        }
        ++k;
    }
    while(i < mid){
        tmpArray[k] = array[i];
        ++i;
        ++k;
    }
    while(j < end){
        tmpArray[k] = array[j];
        ++j;
        ++k;
    }
    memcpy(array + start, tmpArray, sizeof(int) * (end - start));
}


void mergeSort_rec(int *array, int *tmpArray, int start, int end){

    if (end - start <= 1){
        return;
    }
    int mid = (end + start) / 2;
    mergeSort_rec(array, tmpArray, start, mid);
    mergeSort_rec(array, tmpArray, mid, end);
    merge(array, tmpArray, start, mid, end);
}



int* Sort::mergesort(int* array, int size){

	 int *tmpArray = new int [size];
    mergeSort_rec(array, tmpArray, 0, size);
    return array;
}






int* Sort::quicksort(int* arr,int left, int right)
{
       int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quicksort(arr, left, j);
      if (i < right)
            quicksort(arr, i, right);

	return arr;
}




void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

int* Sort::heapsort(int* a, int n){

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n , i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(a[0], a[i]);
 
        // call max heapify on the reduced heap
        heapify(a, i, 0);
    }
    return a;
}

int* Sort::sortA(int* a, int size){

    heapsort(a,size);
      return a;
}
int* Sort::sortB(int* b, int size){

        mergesort(b, size);
         return b;

}


int * Sort::sortOptimized(int * a, int size){
 
     
      int low = 0;
      quicksort(a,low,size-1);
      return a;
      //return b;
}




























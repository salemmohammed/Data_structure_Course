#ifndef SORT_H
#define SORT_H

#define ARRAY_SIZE(array) (sizeof(array)/sizeof((array)[0]))

class Sort
{

private:
	int* heapsort(int* a, int size);
	int* mergesort(int* a, int size);
	int* quicksort(int* array,int low, int high);
public:
	Sort(){};
	int* sortA(int* a, int size);
	int* sortB(int* b, int size);
	int * sortOptimized(int * a, int size);
	//int * sortOptimized(int * a, int size);

};		
#endif

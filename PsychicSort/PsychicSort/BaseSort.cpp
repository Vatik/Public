#ifndef QuickSortMain
#define QuickSortMain
#include "BaseSort.h"

using namespace OtherSorts;
	
	void BaseSorter::QuickSort(int* unsorted, unsigned int unsortedLength) { //inplace quicksort
		if (unsortedLength <= 1) return;

		unsigned int pivot = rand() % unsortedLength; //not completely random, but fast
		unsigned int x = 0, y = 0, z = 0;

		while (x + y + z < unsortedLength)  {
			if (unsorted[x + y + z] > unsorted[pivot]) {
				x++;
			}
			else if(unsorted[x + y + z] < unsorted[pivot]) {
				y++;
			}
			else {
				z++;
			}
		}

		int* greaterPart = (int*)malloc(x * sizeof(int));
		int* lessPart = (int*)malloc(y * sizeof(int));
		//we know what the equalPart would be, the pivot written z times
		unsigned int a=0, b=0;
		for (unsigned int i = 0; i < unsortedLength; i++) {
			if (unsorted[i] > unsorted[pivot])  {
				greaterPart[a++] = unsorted[i];
			}
			else if (unsorted[i] < unsorted[pivot])  {
				lessPart[b++] = unsorted[i];
			}
		}

		//recurse
		QuickSort(greaterPart,x);
		QuickSort(lessPart, y);

		//move partitions to main array memory
		//sorry about the naming, y = less than, z= equal, x=greater than
		for (unsigned int i = 0; i < y; i++)  {
			unsorted[i] = lessPart[i];
		}
		for (unsigned int i = 0; i < z; i++)  {
			unsorted[y+i] = unsorted[pivot];
		}
		for (unsigned int i = 0; i < x; i++)  {
			unsorted[y+z+i] = greaterPart[i];
		}

	}

		void BaseSorter::insert(int value)  {
			storage.push(value);
		}
		int* BaseSorter::Sort(int* unsorted, unsigned int unSortedLength)  {
			int* sorted = (int*)malloc(unSortedLength* sizeof(int));
			for (unsigned int i = 0; i < unSortedLength; i++) {
				sorted[i] = unsorted[i];
			}
			QuickSort(sorted, unSortedLength);
			return sorted;
		}

#endif
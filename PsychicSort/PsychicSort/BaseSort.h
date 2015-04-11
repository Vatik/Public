#ifndef QuickSort_h
#define QuickSort_h
#include <random>
#include <queue>
#include "OtherSort.h"

namespace OtherSorts {
	//Sort class, stores objects and sorts them. Quicksort by default, but overridable
	class BaseSorter {
	
		std::queue<int> storage;
		public:
			void insert(int value);
			virtual int*  Sort(int* unsorted, unsigned int unSortedLength);
			void QuickSort(int* unsorted, unsigned int unsortedLength);
	};
}

#endif
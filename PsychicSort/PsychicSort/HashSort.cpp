#ifndef HashSort_cpp
#define HashSort_cpp
#include "HashSort.h"

using namespace HashSort;
	//input: unsorted array
	//output: sorted array, unexpected array
	int * HashSort::Sort(int* input, int inLength, int HashSize, OtherSorts::BaseSorter otherSort)  {  //TODO: generalize with templates
		HashMap * Map = new HashMap(HashSize);
		try  {
			for (int i = 0; i < inLength; i++)  { if (-1 == Map->insert(input[i])) { otherSort.insert(input[i]); } } //try to put input into map use other sorting algo otherwise
			int* toReturn = Map->getSortedArray();
			delete Map;
			return toReturn;
		}
		catch (...) {
			delete Map;
		}
	}

#endif
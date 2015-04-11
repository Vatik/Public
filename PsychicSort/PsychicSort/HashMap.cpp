#include <queue>
#include "HashSort.h"

#ifndef HashSortMain
#define HashSortMain

using namespace HashSort;
	HashMap::HashMap(unsigned int _HashMapSize) {
		HashMapSize = _HashMapSize;
		numberOfValues = 0;
		values = (unsigned int*)malloc(HashMapSize * sizeof(int));
		for (unsigned int i = 0; i < HashMapSize; i++)  { //zero out HashMap, not needed on some OS. may add compile time skip; note: use calloc
			values[i] = 0;
		}
	}

	int HashMap::insert(int value) {
		unsigned int locationToInsert = HashMap::Hash(value);
		if (locationToInsert == -1)  { //not in hash
			return -1;
		}
		else {
			values[locationToInsert]++;
			//valueBitMap[value / sizeof(int)] = (valueBitMap[value / sizeof(int)] | 1 << (value % sizeof(int)));
			numberOfValues++;
			return value;
		}
	}

	//outputs location in hash array, -1 if not expected
	int HashMap::Hash(int input) {
		if ((input < 0) ||  ((unsigned int)abs(input) > HashMapSize)) return -1;
		return input;  //keeping it simple for now, need to make dynamic and account for negative numbers
	}

	//inverts Hash function, assuming reversable hash function
	int HashMap::ReverseHash(int input) {
		return input;  //keeping it simple for now
	}
	//takes hashmap and converts to sorted array
	int* HashMap::getSortedArray()  {
		int * sorted = (int*)malloc(numberOfValues * sizeof(int));
		int z = 0;
		//for (int i = getNextInHashMap(0, HashMapSize); i != -1; i = getNextInHashMap(i, HashMapSize))  {
		for (unsigned int i = 0; i < HashMapSize; i++)  { //replace with the above line later
			for (unsigned int j = 0; j < values[i]; j++)  {
				sorted[z++] = ReverseHash(i);
			}
		}
		return sorted;
	}

#endif


#ifndef HashSortMain_h
#define HashSortMain_h
#include <iostream>
#include "HashSort.h"
#include "BaseSort.h"

namespace HashSort  {
	class HashMap  {
	public:
		unsigned int * values;  //tracks number of instances of values
		unsigned int numberOfValues;
		unsigned int HashMapSize;
	
		//used to make traversing values faster, first int is least significant, least sig digit is first 
		//int* valueBitMap; = (int*)malloc(HashMapSize);

		HashMap(unsigned int _HashMapSize);
		int insert(int value);
		int Hash(int input);
		int ReverseHash(int input);
		int* getSortedArray();
	};

	int * Sort(int* input, int inLength, int HashSize, OtherSorts::BaseSorter otherSort);

}
#endif
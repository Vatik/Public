#include "HashSort.h"
#include "BaseSort.h"
#include "PsychicSort.h"

	int* PsychicSort::Sort(int* input, int inLength,int HashSize) {
		OtherSorts::BaseSorter sorter = OtherSorts::BaseSorter();
		return HashSort::Sort(input, inLength, HashSize, sorter);
	}

	int* PsychicSort::Merge(int* a, int aLength, int* b, int bLength)  {
		int i = 0, j = 0, z = 0;
		int* sorted = (int*)malloc((aLength + bLength) * sizeof(int));
		while (i < aLength && j < bLength) {
			if (a[i] < b[j])  {
				sorted[z] = a[i];
				i++;
				z++;
			}
			else {
				sorted[z] = b[j];
				j++;
				z++;
			}

		}
		while (i < aLength)  {
			sorted[z] = a[i];
			i++;
			z++;
		}
		while (j < bLength)  {
			sorted[z] = b[j];
			j++;
			z++;
		}
		return sorted;
	}
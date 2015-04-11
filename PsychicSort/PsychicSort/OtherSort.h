#ifndef IOtherSorts
#define IOtherSorts

namespace OtherSorts {
	class IOtherSort {
	public:
		virtual int* Sort(int* unsorted, int unSortedLength) = 0;
		virtual void insert(int a) = 0;
	};
}

#endif
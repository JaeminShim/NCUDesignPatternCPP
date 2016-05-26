// 3_단위전략3 - 84p
#include <iostream>
using namespace std;


// 메모리 할당기
template <typename T>
class allocator
{
public:
	T* allocate(int sz) { return new T[sz]; }
	void deallocate(T* p) { delete[] p; }
};


template <typename T, typename Allocator = allocator<T>>
class vector
{
	Allocator a;

public:
	void resize(int sz)
	{
		// 메모리 재할당이 필요합니다. 어떻게 할까요?
		// malloc(), new, calloc(), heapalloc(), brk()

		T* p = a.allocate(sz);	// 메모리 할당
		a.deallocate(p);		// 메모리 해제
	}
};



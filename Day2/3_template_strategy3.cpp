// 3_��������3 - 84p
#include <iostream>
using namespace std;


// �޸� �Ҵ��
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
		// �޸� ���Ҵ��� �ʿ��մϴ�. ��� �ұ��?
		// malloc(), new, calloc(), heapalloc(), brk()

		T* p = a.allocate(sz);	// �޸� �Ҵ�
		a.deallocate(p);		// �޸� ����
	}
};



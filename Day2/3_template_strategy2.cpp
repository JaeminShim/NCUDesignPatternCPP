// 3_��������2 - 84p
#include <iostream>
using namespace std;

// ���� ����: Policy based design
// ���ø� ���ڷ� ��å Ŭ������ ��ü�ϴ� ���

// ����: ���� �ð� ��ü �Ұ���
// ����: �����Լ��� �ƴ� �ζ��� ġȯ�� ������ ���.

// ��� ��å Ŭ������ ���Ѿ� �ϴ� ��Ģ�� ������ �ȴ�.
// (�����Լ��� ����ϸ� ���� ���� => no interface. ������ ������ �� �ۿ� ����)

template <typename T, typename ThreadModel = NoLock>
class List : public ThreadModel
{
public:
	void push_front(const T& a)
	{
		Lock();
		//......
		Unlock();
	}
};

// ������ ��å�� ���� Ŭ����
class NoLock
{
public:
	inline void Lock() {}
	inline void Unlock() {}
};

class Win32MutexLock
{
public:
	inline void Lock() { cout << "Lock" << endl; }
	inline void Unlock() { cout << "Unlock" << endl; }
};



List<int, NoLock> st;
List<int, Win32MutexLock> st2;

int main()
{
	st.push_front(0);
	st2.push_front(0);
}
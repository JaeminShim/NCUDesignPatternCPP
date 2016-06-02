// 5_container4 - 92p
#include <iostream>
using namespace std;

// 3. C ��Ÿ���� void* ��� �����̳�
struct Node
{
	void* data;
	Node* next;

	Node(void* d, Node* n)
		: data(d), next(n)
	{
	}
};

class slistImpl
{
	Node* head;
public:
	slistImpl() : head(0)
	{
	}

	void push_front(void* a)
	{
		head = new Node(a, head);
	}

	void* front()
	{
		return head->data;
	}
};

// void* ��� �����̳ʸ� ���� ����ϸ� �׻� ĳ������ �ؾ� �ϹǷ� �����ϴ�.
// ĳ������ å������ �ڽ� Ŭ������ ���ø����� ��������.

// thin template �̶�� ���
// google���� "C++ Idioms"��� �˻��� ������.
// (https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms)
template <typename T>
class slist : public slistImpl
{
public:
	inline void push_front(T a) { slistImpl::push_front((void*)a); }
	inline T front() { return static_cast<T>(slistImpl::front()); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	cout << s.front() << endl;
}
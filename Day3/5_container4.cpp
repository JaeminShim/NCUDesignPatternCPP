// 5_container4 - 92p
#include <iostream>
using namespace std;

// 3. C 스타일의 void* 기반 컨테이너
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

// void* 기반 컨테이너를 직접 사용하면 항상 캐스팅을 해야 하므로 불편하다.
// 캐스팅을 책임지는 자식 클래스를 템플릿으로 제공하자.

// thin template 이라는 기술
// google에서 "C++ Idioms"라고 검색해 보세요.
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
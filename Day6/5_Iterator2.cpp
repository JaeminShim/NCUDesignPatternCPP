// 5_Iterator2	// C++의 반복자

// (copied from "6_반복자.cpp")

#include <iostream>
using namespace std;


//---------------------------------------------------------
// 반복자의 인터페이스


// 모든 컨테이너에는 자신의 반복자를 만드는 함수가 있어야 한다고 약속.
// => 인터페이스 없음... 약속 강제 안 됨


///////////////////////////////////////////////////////////
// 싱글 링크드 리스트

// 싱글 링크드 리스트의 노드
template<typename T>
struct Node
{
	T   data;
	Node* next;
	Node(T a, Node* n) : data(a), next(n) {}
};

// 싱글 링크드 리스트의 반복자
template <typename T>
class slist_iterator
{
	Node<T>* current;

public:
	slist_iterator(Node<T>* p = 0) : current(p) {}

	// 이동과 값 꺼내기는 배열(즉, 진짜 포인터)의 규칙을 따른다.
	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	inline T& operator*()
	{
		return current->data;
	}

	inline Node<T>& operator->()
	{
		return *current;
	}

	inline bool operator == (slist_iterator& other)
	{
		return current == other.current;
	}

	inline bool operator != (slist_iterator& other)
	{
		return current != other.current;
	}
};

// 싱글 링크드 리스트
template<typename T>
class slist
{
	Node<T>* head;
public:
	slist() : head(0) {}
	void push_front(const T& a) { head = new Node<T>(a, head); }
	T&  front() { return head->data; }

	// 반복자를 리턴하는 함수를 만들기로 문서로만 약속
	// end() : 0으로 초기화 된 반복자 (마지막 다음을 의미)
	inline slist_iterator<T> begin() { return slist_iterator<T>(head); }
	inline slist_iterator<T> end()   { return slist_iterator<T>(0); }
};


///////////////////////////////////////////////////////////
// 벡터

template<typename T>
class Vector
{
	T* buff;
public:
	Vector(int sz) { buff = new T[sz]; }

	T& operator[](int index) { return buff[index]; }
};


///////////////////////////////////////////////////////////

// 인터페이스가 없으므로 slist_iterator<T> 전체를 T로 사용
template <typename T>
void Find(T first, T last)
{
	while (first != last)
	{
		cout << *first << endl;
		++first;
	};
}


///////////////////////////////////////////////////////////

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	Find(s.begin(), s.end());
}

// 5_Iterator2	// C++�� �ݺ���

// (copied from "6_�ݺ���.cpp")

#include <iostream>
using namespace std;


//---------------------------------------------------------
// �ݺ����� �������̽�


// ��� �����̳ʿ��� �ڽ��� �ݺ��ڸ� ����� �Լ��� �־�� �Ѵٰ� ���.
// => �������̽� ����... ��� ���� �� ��


///////////////////////////////////////////////////////////
// �̱� ��ũ�� ����Ʈ

// �̱� ��ũ�� ����Ʈ�� ���
template<typename T>
struct Node
{
	T   data;
	Node* next;
	Node(T a, Node* n) : data(a), next(n) {}
};

// �̱� ��ũ�� ����Ʈ�� �ݺ���
template <typename T>
class slist_iterator
{
	Node<T>* current;

public:
	slist_iterator(Node<T>* p = 0) : current(p) {}

	// �̵��� �� ������� �迭(��, ��¥ ������)�� ��Ģ�� ������.
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

// �̱� ��ũ�� ����Ʈ
template<typename T>
class slist
{
	Node<T>* head;
public:
	slist() : head(0) {}
	void push_front(const T& a) { head = new Node<T>(a, head); }
	T&  front() { return head->data; }

	// �ݺ��ڸ� �����ϴ� �Լ��� ������ �����θ� ���
	// end() : 0���� �ʱ�ȭ �� �ݺ��� (������ ������ �ǹ�)
	inline slist_iterator<T> begin() { return slist_iterator<T>(head); }
	inline slist_iterator<T> end()   { return slist_iterator<T>(0); }
};


///////////////////////////////////////////////////////////
// ����

template<typename T>
class Vector
{
	T* buff;
public:
	Vector(int sz) { buff = new T[sz]; }

	T& operator[](int index) { return buff[index]; }
};


///////////////////////////////////////////////////////////

// �������̽��� �����Ƿ� slist_iterator<T> ��ü�� T�� ���
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

// 반복자 - 104 page
// 컨테이너 3번 복사해오세요

// 5_컨테이너- 100 page
#include <iostream>
using namespace std;

template<typename T> struct Node
{
	T   data;
	Node* next;
	Node(T a, Node* n) : data(a), next(n) {}
};

template<typename T> class slist
{
	Node<T>* head; 
public:
	slist() : head(0) {}
	void push_front(const T& a) { head = new Node<T>(a, head); }
	T&  front() { return head->data; }
};
//----------------------------
template<typename T> class Vector
{
	T* buff;
public:
	Vector(int sz) { buff = new T[sz]; }

	T& operator[](int index) { return buff[index]; }
};


int main()
{
	Vector<int> v(10); // 10개 짜리 vector
	v[0] = 10;
}






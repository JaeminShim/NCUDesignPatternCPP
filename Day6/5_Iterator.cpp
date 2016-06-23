// 5_Iterator	// C#의 반복자

// (copied from "6_반복자.cpp")

#include <iostream>
using namespace std;


//---------------------------------------------------------
// 반복자의 인터페이스
/*
// C# 1.0의 모양 (공통 Object 기반, Generic 도입 이전)
struct IEnumerator
{
	virtual bool moveNext() = 0;		// 다음으로 이동
	virtual Object* getObject() = 0;	// 현재 위치에서 요소 꺼내오기

	virtual ~IEnumerator() {}
};
*/

// C# 2.0 부터는 템플릿이 도입 됩니다
template<typename T>
struct IEnumerator
{
	virtual bool moveNext() = 0;
	virtual T& getObject() = 0;

	virtual ~IEnumerator() {}
};

// 모든 컨테이너에는 자신의 반복자를 만드는 함수가 있어야 한다고 약속.
// => 인터페이스로 약속 강제
template <typename T>
struct IEnumerable
{
	virtual IEnumerator<T>* getEnumerator() = 0;
	virtual ~IEnumerable() {}
};


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

#include <exception>

// 싱글 링크드 리스트의 반복자
template <typename T>
class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current;

public:
	slist_enumerator(Node<T>* p = 0) : current(p) {}
	virtual bool moveNext() override
	{
		current = current->next;
		return current != nullptr;	// 더 이상 이동 불가능
	}

	virtual T& getObject() override
	{
		if (current == nullptr) throw new exception("으악");
		return current->data;
	}
};

// 싱글 링크드 리스트
template<typename T>
class slist : public IEnumerable<T>
{
	Node<T>* head;
public:
	slist() : head(0) {}
	void push_front(const T& a) { head = new Node<T>(a, head); }
	T&  front() { return head->data; }

	// 삼성의 Tizen에서는 이름 뒤에 N이 붙으면 new를 사용한 객체를 리턴함을 의미;
	// virtual IEnumerator<T>* getEnumeratorN() override
	virtual IEnumerator<T>* getEnumerator() override
	{
		return new slist_enumerator<T>(head);
	}
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

template <typename T>
void Find(IEnumerator<T>* p)
{
	do
	{
		cout << p->getObject() << endl;
	} while (p->moveNext());
}


///////////////////////////////////////////////////////////

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	Find(s.getEnumerator());
}

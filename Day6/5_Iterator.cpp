// 5_Iterator	// C#�� �ݺ���

// (copied from "6_�ݺ���.cpp")

#include <iostream>
using namespace std;


//---------------------------------------------------------
// �ݺ����� �������̽�
/*
// C# 1.0�� ��� (���� Object ���, Generic ���� ����)
struct IEnumerator
{
	virtual bool moveNext() = 0;		// �������� �̵�
	virtual Object* getObject() = 0;	// ���� ��ġ���� ��� ��������

	virtual ~IEnumerator() {}
};
*/

// C# 2.0 ���ʹ� ���ø��� ���� �˴ϴ�
template<typename T>
struct IEnumerator
{
	virtual bool moveNext() = 0;
	virtual T& getObject() = 0;

	virtual ~IEnumerator() {}
};

// ��� �����̳ʿ��� �ڽ��� �ݺ��ڸ� ����� �Լ��� �־�� �Ѵٰ� ���.
// => �������̽��� ��� ����
template <typename T>
struct IEnumerable
{
	virtual IEnumerator<T>* getEnumerator() = 0;
	virtual ~IEnumerable() {}
};


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

#include <exception>

// �̱� ��ũ�� ����Ʈ�� �ݺ���
template <typename T>
class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current;

public:
	slist_enumerator(Node<T>* p = 0) : current(p) {}
	virtual bool moveNext() override
	{
		current = current->next;
		return current != nullptr;	// �� �̻� �̵� �Ұ���
	}

	virtual T& getObject() override
	{
		if (current == nullptr) throw new exception("����");
		return current->data;
	}
};

// �̱� ��ũ�� ����Ʈ
template<typename T>
class slist : public IEnumerable<T>
{
	Node<T>* head;
public:
	slist() : head(0) {}
	void push_front(const T& a) { head = new Node<T>(a, head); }
	T&  front() { return head->data; }

	// �Ｚ�� Tizen������ �̸� �ڿ� N�� ������ new�� ����� ��ü�� �������� �ǹ�;
	// virtual IEnumerator<T>* getEnumeratorN() override
	virtual IEnumerator<T>* getEnumerator() override
	{
		return new slist_enumerator<T>(head);
	}
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

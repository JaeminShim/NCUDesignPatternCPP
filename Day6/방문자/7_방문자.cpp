// 7_�湮��(visitor)
// �����̳�3 �����ؿ�����...

#include <iostream>
using namespace std;

template<typename T> struct Node
{
	T   data;
	Node* next;
	Node(T a, Node* n) : data(a), next(n) {}
};

// �湮���� �������̽�
template<typename T> struct IVisitor
{
	virtual void visit(T& a) = 0;
	virtual ~IVisitor() {}
};


// ��� �����̳ʴ� �湮�ڸ� �޾� �鿩�� �Ѵ�. accept�� �־�� �Ѵ�.
// ���հ�ü(�����̳�)�� �������̽�
template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>* p) = 0;
	virtual ~IAcceptor() {}
};





template<typename T> class slist : public IAcceptor<T>
{
	Node<T>* head; 
public:

	// �Ʒ� �Լ��� �湮���� �ٽ��Դϴ�.  �߻����غ�����
	virtual void accept(IVisitor<T>* p)
	{
		Node<T>* current = head;
		while (current != 0 )
		{
			p->visit(current->data); // �湮�ڿ��� ��� ����
			current = current->next;
		}
	}




	slist() : head(0) {}
	void push_front(const T& a) { head = new Node<T>(a, head); }
	T&  front() { return head->data; }
};

// ���� �پ��� �湮�ڸ� ����� �˴ϴ�.
template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& a) { a = a * 2; }
};


template<typename T> class ShowVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& a) { cout << a << endl; }
};

template<typename T> class ZeroVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& a) { a = 0; }
};


int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	// s�� �ִ� ��� ��Ҹ� 2��� �ϰ� �ʹ�.
	// 1. ������ �����ϸ鼭 ����Ҹ������� 2�� ���� �ٽ� �־� �ش�.
	// 2. ���� �ϴ� ���̶�� s.twiceAll() ���� ��� �Լ��� ���� �ȴ�.
	// 3. vector�� �̷����� ���� �Ѵ�. v.twiceAll()�� �ʿ��ϴ�.
	
	// �׷��ٸ�.. �湮�������� ����ص� �ȴ�

	ShowVisitor<int> sv;

	TwiceVisitor<int> tv;
	s.accept(&tv); // ��� ��Ұ� 2�谡 �ȴ�
	s.accept(&sv); // ��� ��� ���

	ZeroVisitor<int> zv;
	s.accept(&zv); // ��� ��Ҹ� 0���� �ȴ�
	s.accept(&sv); // ��� ��� ���

	// ���� : �پ��� �湮�ڸ� �پ��� �����̳ʿ� Ȱ���Ҽ� �ִ�.
	// ���� : �����Լ� ����̴�. ������ ����ؾ� �Ѵ�.
}







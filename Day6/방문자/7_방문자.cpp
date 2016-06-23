// 7_방문자(visitor)
// 컨테이너3 복사해오세요...

#include <iostream>
using namespace std;

template<typename T> struct Node
{
	T   data;
	Node* next;
	Node(T a, Node* n) : data(a), next(n) {}
};

// 방문자의 인터페이스
template<typename T> struct IVisitor
{
	virtual void visit(T& a) = 0;
	virtual ~IVisitor() {}
};


// 모든 컨테이너는 방문자를 받아 들여야 한다. accept가 있어야 한다.
// 복합객체(컨테이너)의 인터페이스
template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>* p) = 0;
	virtual ~IAcceptor() {}
};





template<typename T> class slist : public IAcceptor<T>
{
	Node<T>* head; 
public:

	// 아래 함수가 방문자의 핵심입니다.  잘생각해보세요
	virtual void accept(IVisitor<T>* p)
	{
		Node<T>* current = head;
		while (current != 0 )
		{
			p->visit(current->data); // 방문자에게 요소 전달
			current = current->next;
		}
	}




	slist() : head(0) {}
	void push_front(const T& a) { head = new Node<T>(a, head); }
	T&  front() { return head->data; }
};

// 이제 다양한 방문자를 만들면 됩니다.
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

	// s에 있는 모든 요소를 2배로 하고 싶다.
	// 1. 루프를 수행하면서 모든요소를꺼내서 2배 한후 다시 넣어 준다.
	// 2. 자주 하는 일이라면 s.twiceAll() 등의 멤버 함수를 만들어도 된다.
	// 3. vector도 이런일을 자주 한다. v.twiceAll()이 필요하다.
	
	// 그렇다면.. 방문자패턴을 사용해도 된다

	ShowVisitor<int> sv;

	TwiceVisitor<int> tv;
	s.accept(&tv); // 모든 요소가 2배가 된다
	s.accept(&sv); // 모든 요소 출력

	ZeroVisitor<int> zv;
	s.accept(&zv); // 모든 요소를 0으로 된다
	s.accept(&sv); // 모든 요소 출력

	// 장점 : 다양한 방문자를 다양한 컨테이너에 활용할수 있다.
	// 단점 : 가상함수 기반이다. 성능을 고려해야 한다.
}







// 5_container - 92p

// 1. object 기반의 컨테이너
//   최상위 부모를 보관하면 모든 하위 클래스 보관 가능
// - 장점
//		1) template이 아니다.
//		2) 코드 메모리가 증가하지 않는다.
// - 단점:
//		1) 타입 안정성이 떨어진다.
//		2) 표준 타입을 사용할 수 없으므로 표준 타입의 wrapper 클래스가 필요하다.
//		3) 꺼낼 때 항상 캐스팅이 필요하다.

class object {};
class Point : public object {};
class Dialog : public object {};
class Integer : public object {};

struct Node
{
	object* data;
	Node* next;

	Node(object* d, Node* n)
		: data(d), next(n)
	{
	}
};

class slist
{
	Node* head;
public:
	slist() : head(0)
	{
	}

	void push_front(object* a)
	{
		head = new Node(a, head);
	}

	Node* front()
	{
		return head;
	}
};

int main()
{
	slist s;
	s.push_front(new Point());
	s.push_front(new Point());
	s.push_front(new Dialog());	// 단점 1)
	s.push_front(10);			// 단점 2)
	Dialog* p = s.front();		// 단점 3)
}
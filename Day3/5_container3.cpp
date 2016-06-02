// 5_container - 93p

// 2. template 기반의 컨테이너
// - 장점:
//		1) 타입 안정성이 뛰어나다
//		2) 객체 뿐 아니라 표준 타입 저장 가능
//		3) 데이터 가져올 때 캐스팅 필요 없음
// - 단점:
//		1) 템플릿이므로 코드 메모리 증가

template <typename T>
struct Node
{
	T data;
	Node* next;

	Node(T d, Node* n)
		: data(d), next(n)
	{
	}
};

template <typename T>
class slist
{
	Node<T>* head;
public:
	slist() : head(0)
	{
	}

	void push_front(T a)
	{
		head = new Node<T>(a, head);
	}

	Node<T>* front()
	{
		return head;
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
}
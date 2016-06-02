// 5_container - 93p

// 2. template ����� �����̳�
// - ����:
//		1) Ÿ�� �������� �پ��
//		2) ��ü �� �ƴ϶� ǥ�� Ÿ�� ���� ����
//		3) ������ ������ �� ĳ���� �ʿ� ����
// - ����:
//		1) ���ø��̹Ƿ� �ڵ� �޸� ����

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
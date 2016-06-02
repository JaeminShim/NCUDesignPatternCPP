// 5_container - 92p

// 1. object ����� �����̳�
//   �ֻ��� �θ� �����ϸ� ��� ���� Ŭ���� ���� ����
// - ����
//		1) template�� �ƴϴ�.
//		2) �ڵ� �޸𸮰� �������� �ʴ´�.
// - ����:
//		1) Ÿ�� �������� ��������.
//		2) ǥ�� Ÿ���� ����� �� �����Ƿ� ǥ�� Ÿ���� wrapper Ŭ������ �ʿ��ϴ�.
//		3) ���� �� �׻� ĳ������ �ʿ��ϴ�.

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
	s.push_front(new Dialog());	// ���� 1)
	s.push_front(10);			// ���� 2)
	Dialog* p = s.front();		// ���� 3)
}
// 5_container - 92p

struct Node
{
	int data;
	Node* next;

	Node(int d, Node* n)
		: data(d), next(n)
	{
	}
};

// �̱� ����Ʈ�� ����� ���ô�
class slist
{
	Node* head;
public:
	slist() : head(0)
	{
	}

	// ����� �����ڸ� �� Ȱ���ϸ� ����Ʈ�� �����ϰ� ���� �� �ֽ��ϴ�.
	void push_front(int a)
	{
		head = new Node(a, head);
	}
};

int main()
{
	slist s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);	// �� �� �޸� �׸��� ������ ������.
}
#include <iostream>
#include <vector>
using namespace std;

// 9_�޸��� : ��ü�� ���¸� �����ߴٰ� ���߿� ���� �Ҽ� �ְ��ϴ� ����

class Pen{};
class Brush{};

class Graphics
{
	Pen*   pen;
	Brush* brush;
	int data;

	// �����ؾ� �ϴ� ������� ���ο� ����ü�� �����Ѵ�.
	struct Memento
	{
		Pen*   pen;
		Brush* brush;
		Memento(Pen* p, Brush* b) :pen(p), brush(b) {}
	};
	vector<Memento*> history;
public:
	int saveState()
	{
		history.push_back(new Memento(pen, brush));
		return history.size(); 
	}
	void restoreState(int token)
	{
		Memento* p = history[token - 1];
		pen = p->pen;
		brush = p->brush;
	}
	void setPen(Pen* p) { pen = p; }
};



int main()
{
	Graphics g;
	int token = g.saveState(); // ���� ���¸� ������ ���´�.

//	{
		Pen p;
		g.setPen(&p);
//	}

	// g�� ����ؼ� �׸��� �׸���.
	//g.DrawLine(0, 0, 100, 100);  // g�� ���� ������ �׸���
	//g.DrawLine(0, 0, 100, 100, &p);  // ������ ���ڷ� ������ ������ �׸���

	g.restoreState(token); // token ���·� ���� �Ѵ�.
}

// C++ ��ü : ���ÿ� ����� �ְ� ���� ����� �ִ�. => ������ ��Ȳ�� �����

// java ��ü : ������ ����� �ִ�. -> ������ �ξ� ������ ����.

// �׷��� ���� ���¼ҽ��� 

// 1. �ݵ�� ���� ������
// 2. ��������� ���� ����.
// 3. ����Ʈ������ ��������

// �� ����� ������ �˴ϴ� - �ᱹ java style!!

// ���� : C++ ������� > java garbage collector









// 2_inheritance3

class Base
{
private:			// ���� ������
	int a;
protected:	int b;
public:		int c;
};

class Derived
//	: protected		// ���� ������
	: private		// ���� ������
	  Base
					// �θ��� ���� ������ ����� �� ���
					// ������ Ȯ���� ���� ����.
{
};

int main()
{
	Base b;		b.c = 10;	// OK
	Derived d;	d.c = 10;	// ERROR
}
// 1_thiscall2	// 33p

// 1. �Ϲ� �Լ� �����Ϳ� ��� �Լ��� �ּҸ� ���� �� ����.
// 2. �Ϲ� �Լ� �����Ϳ� static ��� �Լ��� �ּҸ� ���� �� �ִ�.
// 3. ��� �Լ� �����͸� ����� ����ϴ� ���: �Ʒ� main ����

class Dialog
{
public:
	void Close() {}
};

void foo() {}

int main()
{
	void(*f1)() = &foo;
	//void(*f2)() = &Dialog::Close;	// �ɱ��?
									// ERROR: this ���ڰ� �ִ�.

	// ��� �Լ��� �ּҸ� ��� ���
	void(Dialog::*f2)() = &Dialog::Close;

	Dialog dlg;
	(dlg.*f2)();		// dlg.Close();
}
// 2_inheritance2 // 45p

// protected ������:
//	�ڽ��� ���� �� ������ (�߻����� ����)
//	�Ļ� Ŭ������ ���� �� �ְ� �ϰڴ� (��ü���� ����)
//	�� ������ ��� - 46p

class Animal
{
//public:
protected:	// �߻����� Ŭ����
	Animal() {}
};

class Dog : public Animal
{
public:
	Dog() {}
};

int main()
{
	// ���� �� ������ ��� ���ÿ�
	Animal	a;	// 1. ERROR
	Dog		d;	// 2. OK
}

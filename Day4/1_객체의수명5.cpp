// 1_��ü�Ǽ���5
#include <iostream>
using namespace std;

// ��ü ������ ���� ����� �ڵ����� �����ϴ� ����Ʈ ������
template <typename T> class sp
{
	T* obj;
public:
	sp(T* p = 0)	: obj(p)		{ obj->AddRef(); }
	sp(const sp& s)	: obj(s.obj)	{ obj->AddRef(); }
	~sp()							{ obj->Release(); }

	// ����Ʈ ������ �⺻: ->�� *
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};

#include <memory>

int main()
{
	//sp<int> p1 = new int;	// �ɱ��?	=> ERROR! sp�� RefCount�� �Ļ�Ŭ������ ��� ����

	// C++ ǥ���� ����Ʈ ������: ��� Ÿ�Կ� ���� ��� ����
	//							��������� ��ü ���ΰ� �ƴ� �ܺο� �����.
	shared_ptr<int> p2(new int);
	shared_ptr<int> p3 = p2;

	struct Car {};
	// ���� �� ���� �ڵ��?	(sp�� RefCount�� ���!�޾Ҵٰ� ����)
	sp<Car> p4(new Car);			// �޸� �Ҵ��� 1ȸ
	shared_ptr<Car> p5(new Car);	// �޸� �Ҵ��� 2ȸ

	// �׷��� �������� shared_ptr<>�� �־ ������ ����Ʈ�����͸� ���̺귯���� ����

	// C++11 ���ʹ�
	shared_ptr<int> p6(new int);				// �޸� �Ҵ� 2ȸ
	shared_ptr<int> p7 = make_shared<int>();	// �޸� �Ҵ� 1ȸ sizeof(int) + sizeof(�������)
												// ũ���� �޸𸮸� �� ���� �Ҵ�
}

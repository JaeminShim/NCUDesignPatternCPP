// 3_abstract_class2	// 58p

#include <iostream>

using namespace std;

// ��� Ȯ�忡 �����ְ� (Open)
// �ڵ� ������ ���� �־�� (Close)
// �Ѵٴ� �̷� (Principle)
// => OCP

// �̷��� ���ο� Ŭ������ �߰� �Ǿ ������ �ڵ�� ���� �Ǹ� �ȵȴ�.

class Camera
{
public:
	void Take() { cout << "Take a picture with a camera." << endl; }
};

class Camera2
{
public:
	void Take() { cout << "Take a picture with a camera2." << endl; }
};

class People
{
public:
	void UseCamera(Camera* p) { p->Take(); }
	void UseCamera(Camera2* p) { p->Take(); }
};

int main()
{
	Camera c1;
	People p;
	p.UseCamera(&c1);

	Camera2 c2;
	p.UseCamera(&c2);
}
// 3_abstract_class	// 57p

// �߻� Ŭ����
// : ���� ���� �Լ��� �� �� �̻� �ִ� Ŭ����
class Shape
{
public:
	virtual void Draw() = 0;	// ���� �����Լ� (pure virtual function)
};

class Rect : public Shape		// Draw()�� �����θ� �������� ������
								// Rect ���� �߻� Ŭ�����̴�.
								// Rect�� ����ϰ� �ʹٸ�
								// �ݵ�� Draw()�� �����ض�.
{
public:
	//virtual void Draw() override {}
};

int main()
{
	Shape s;	// ERROR: �߻� Ŭ���� ��ü�� ���� �� ����.
}

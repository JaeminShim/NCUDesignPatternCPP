// 3_abstract_class	// 57p

// 추상 클래스
// : 순수 가상 함수가 한 개 이상 있는 클래스
class Shape
{
public:
	virtual void Draw() = 0;	// 순수 가상함수 (pure virtual function)
};

class Rect : public Shape		// Draw()의 구현부를 제공하지 않으면
								// Rect 역시 추상 클래스이다.
								// Rect를 사용하고 싶다면
								// 반드시 Draw()를 구현해라.
{
public:
	//virtual void Draw() override {}
};

int main()
{
	Shape s;	// ERROR: 추상 클래스 객체를 만들 수 없다.
}

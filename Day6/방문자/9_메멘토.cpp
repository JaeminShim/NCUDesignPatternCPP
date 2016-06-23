#include <iostream>
#include <vector>
using namespace std;

// 9_메멘토 : 객체의 상태를 저장했다가 나중에 복구 할수 있게하는 패턴

class Pen{};
class Brush{};

class Graphics
{
	Pen*   pen;
	Brush* brush;
	int data;

	// 저장해야 하는 멤버만을 새로운 구조체로 정의한다.
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
	int token = g.saveState(); // 현재 상태를 저장해 놓는다.

//	{
		Pen p;
		g.setPen(&p);
//	}

	// g를 사용해서 그림을 그린다.
	//g.DrawLine(0, 0, 100, 100);  // g가 가진 펜으로 그리기
	//g.DrawLine(0, 0, 100, 100, &p);  // 마지막 인자로 전달한 펜으로 그리기

	g.restoreState(token); // token 상태로 복구 한다.
}

// C++ 객체 : 스택에 만들수 있고 힙에 만들수 있다. => 복잡한 상황이 생긴다

// java 객체 : 힙에만 만들수 있다. -> 개념이 훨씬 간단해 진다.

// 그래서 많은 오픈소스가 

// 1. 반드시 힙에 만들자
// 2. 참조계수로 관리 하자.
// 3. 스마트포인터 도입하자

// 는 결론을 내리게 됩니다 - 결국 java style!!

// 성능 : C++ 참조계수 > java garbage collector









// 2_inheritance4

#include <iostream>

using namespace std;

// 링크드 리스트가 이미 있습니다.
#include <list>

// 그런데 사용자가 스택을 요구합니다.
// 1. stack을 새롭게 만들자
// 2. list를 한 쪽으로만 사용하면 stack이다. list를 재사용하자.

// Adapter 패턴
// : 기존 클래스의 인터페이스(함수 이름)만 변경해서
//   클라이언트가 요구하는 다른 클래스를 만드는 패턴
//   C++는 인라인 치환 등의 기술로 성능 저하 없는 어답터가 가능

// private 상속을 사용한 어답터 패턴 - 47p 3번
// : 부모로부터 구현은 물려 받지만 (자식이 내부적으로 부모 함수를 사용)
//   인터페이스는 물려 받지 않겠다. (부모 함수를 외부에 노출하지 않겠다)
/*
template <typename T>
class stack : private list<T>
{
public:
	void push(const T& a)	{ push_back(a); }
	void pop()				{ pop_back(); }
	T&   top()				{ return back(); }
};
// 문제: IDE의 assistant가 모든 멤버를 노출한다.
// 장점: 가상함수 재정의를 원할 때에는 필요함
*/


// SW의 재사용은 상속과 포함이 있습니다.
// 상속보다 포함이 좋은 경우가 더 많습니다.
// 가상함수 재정의가 필요한 경우 포함이 아닌 상속을 사용하자.
/*
template <typename T>
class stack
{
	list<T> st;
public:
	void push(const T& a)	{ st.push_back(a); }
	void pop()				{ st.pop_back(); }
	T&   top()				{ return st.back(); }
};
// 해결: 멤버 인터페이스를 완벽히 감출 수 있다.
*/


#include <vector>
#include <deque>	// list와 vector 중간 성능의 자료 구조

/*
template <typename T, typename C = deque<T>>
class stack
{
	C st;
public:
	void push(const T& a)	{ st.push_back(a); }
	void pop()				{ st.pop_back(); }
	T&   top()				{ return st.back(); }
};
*/

#include <stack>	// C++ 표준의 stack, 흔히 "stack adapter"라고 합니다.

int main()
{
	stack<int> s;
	s.push(10);
	cout << s.top() << endl;

	stack<int, list<int>> s_l;
	stack<int, vector<int>> s_v;
}

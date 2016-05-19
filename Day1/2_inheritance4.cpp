// 2_inheritance4

#include <iostream>

using namespace std;

// ��ũ�� ����Ʈ�� �̹� �ֽ��ϴ�.
#include <list>

// �׷��� ����ڰ� ������ �䱸�մϴ�.
// 1. stack�� ���Ӱ� ������
// 2. list�� �� �����θ� ����ϸ� stack�̴�. list�� ��������.

// Adapter ����
// : ���� Ŭ������ �������̽�(�Լ� �̸�)�� �����ؼ�
//   Ŭ���̾�Ʈ�� �䱸�ϴ� �ٸ� Ŭ������ ����� ����
//   C++�� �ζ��� ġȯ ���� ����� ���� ���� ���� ����Ͱ� ����

// private ����� ����� ����� ���� - 47p 3��
// : �θ�κ��� ������ ���� ������ (�ڽ��� ���������� �θ� �Լ��� ���)
//   �������̽��� ���� ���� �ʰڴ�. (�θ� �Լ��� �ܺο� �������� �ʰڴ�)
/*
template <typename T>
class stack : private list<T>
{
public:
	void push(const T& a)	{ push_back(a); }
	void pop()				{ pop_back(); }
	T&   top()				{ return back(); }
};
// ����: IDE�� assistant�� ��� ����� �����Ѵ�.
// ����: �����Լ� �����Ǹ� ���� ������ �ʿ���
*/


// SW�� ������ ��Ӱ� ������ �ֽ��ϴ�.
// ��Ӻ��� ������ ���� ��찡 �� �����ϴ�.
// �����Լ� �����ǰ� �ʿ��� ��� ������ �ƴ� ����� �������.
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
// �ذ�: ��� �������̽��� �Ϻ��� ���� �� �ִ�.
*/


#include <vector>
#include <deque>	// list�� vector �߰� ������ �ڷ� ����

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

#include <stack>	// C++ ǥ���� stack, ���� "stack adapter"��� �մϴ�.

int main()
{
	stack<int> s;
	s.push(10);
	cout << s.top() << endl;

	stack<int, list<int>> s_l;
	stack<int, vector<int>> s_v;
}

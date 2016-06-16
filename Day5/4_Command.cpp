// 4_Command

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Shape
{
public:
	virtual void Draw() = 0;
};

class Rect : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Rect" << endl; }
};

class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }
};


// ��� ����� �������̽�
struct ICommand
{
	virtual ~ICommand() {}
	virtual void Execute() = 0;
	virtual bool CanUndo() { return false; }
	virtual void Undo() {}
};

// �簢���� �߰��ϴ� ���
class AddRectCommand : public ICommand
{
	vector<Shape*>& v;
public:
	AddRectCommand(vector<Shape*>& a) : v(a) {}

	virtual void Execute() override { v.push_back(new Rect); }
	virtual bool CanUndo() override { return true; }
	virtual void Undo() override
	{
		Shape* p = v.back();	// �����͸� ���. ���� �� ��.
		delete p;
		v.pop_back();			// ����
	}
};

// ������ �߰��ϴ� ���
class AddCircleCommand : public ICommand
{
	vector<Shape*>& v;
public:
	AddCircleCommand(vector<Shape*>& a) : v(a) {}

	virtual void Execute() override { v.push_back(new Circle); }
	virtual bool CanUndo() override { return true; }
	virtual void Undo() override
	{
		Shape* p = v.back();	// �����͸� ���. ���� �� ��.
		delete p;
		v.pop_back();			// ����
	}
};

// ������ �߰��ϴ� ���
class DrawCommand : public ICommand
{
	vector<Shape*>& v;
public:
	DrawCommand(vector<Shape*>& a) : v(a) {}

	virtual void Execute() override
	{
		for (int i = 0; i < v.size(); i++)
			v[i]->Draw();
	}
	virtual bool CanUndo() override { return true; }
	virtual void Undo() override
	{
		system("cls");
	}
};

int main()
{
	stack<ICommand*> cmd_stack;
	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1)
		{
			ICommand* p = new AddRectCommand(v);
			p->Execute();
			cmd_stack.push(p);
		}
		else if (cmd == 2)
		{
			ICommand* p = new AddCircleCommand(v);
			p->Execute();
			cmd_stack.push(p);
		}
		else if (cmd == 9)
		{
			ICommand* p = new DrawCommand(v);
			p->Execute();
			cmd_stack.push(p);
		}
		else if (cmd == 0)
		{
			ICommand* p = cmd_stack.top();
			if (p->CanUndo())
				p->Undo();
			cmd_stack.pop();
			delete p;
		}
	}
}

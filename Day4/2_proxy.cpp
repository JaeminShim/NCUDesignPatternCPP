// 2_proxy
#include <iostream>
#include <conio.h>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

int main()
{
	int server = IoFindServer("Calc");
	cout << "serverId: " << server << endl;
	while (1)
	{
		_getch();	cout << IoSendServer(server, 1, 10, 20) << endl;
		_getch();	cout << IoSendServer(server, 2, 10, 20) << endl;
	}
}
#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"

using namespace std;

int justice(string coword)
{
	cout<<"�����뵥��"<<endl;
	string word;
	cin.sync();
	cin>>word;
	if (word =="Q") return 2;
	if (word == coword) 
	{
		cout<<"Correct!"<<endl;
		Sleep(normal);
		return 0;
	}
	else 
	{
		
		cout<<"��Ǹ��������ˣ�����һ����(Y/N)"<<endl;
		
		char c;
		cin.sync();
		cin>>c;
		while (c !='N' && c!='Y') 
		{
			cout<<"������Y/N"<<endl;
			cin.sync();
			cin>>c;
		}

		if (c=='N') 
		{ 
			cout<<"��ȷ���ǣ�"<<coword<<endl; 
			Sleep(normal);
			return 1;
		}
		else 
		{
			cout<<"�����뵥�ʣ�"<<endl;
			cin.sync();
			cin>>word;
			if (word=="Q") return 2;
			if (word == coword)  { cout<<"����ˣ�"<<endl;Sleep(1000); return 0;}
			else 
			{
				changeclass(4,coword);
				cout<<"��Ǹ��������ˡ�"<<endl;
				cout<<"��ȷ���ǣ�"<<coword<<endl;
				Sleep(normal);
				return 1;
			}
		}
	}
}
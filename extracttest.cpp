#include"decl.h"
#include"newdecl.h"
#include"newtest.h"
#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>

using namespace std;

int main()
{
	system("cls");
	cout<<"����..."<<endl;
	int b = extrinit();
	if (b==1)
	{
		cout<<"�����ļ���ɾ��������Ҹ�Ŀ¼���Ƿ���config.txt!"<<endl;
		Sleep(2000);
		return 1;
	}
	
	initial* p = new newinit();
	p->beginrecite();
	cout<<"��ʼ�����"<<endl;
	remark();
	cout<<"���ڽ���..."<<endl;
	tofile* ptofile = new newtofile();
	ptofile->endfile();
	return 0;
}
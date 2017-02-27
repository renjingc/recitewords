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
	cout<<"载入..."<<endl;
	int b = extrinit();
	if (b==1)
	{
		cout<<"配置文件被删除！请查找根目录下是否有config.txt!"<<endl;
		Sleep(2000);
		return 1;
	}
	
	initial* p = new newinit();
	p->beginrecite();
	cout<<"初始化完毕"<<endl;
	remark();
	cout<<"正在结束..."<<endl;
	tofile* ptofile = new newtofile();
	ptofile->endfile();
	return 0;
}
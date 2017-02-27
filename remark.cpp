#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"
#include<windows.h>
using namespace std;

//typedef initial* (*PFUNC)();
//typedef dic* (*FUNC)();

/*initial* CreateInstance1(char*szDll)
{
	HINSTANCE h = LoadLibrary(szDll);
	if (h == NULL) return NULL;
	PFUNC DllGetInit = (PFUNC)GetProcAddress(h,"DllGetInit");
	if (DllGetInit == NULL) return NULL;
	return DllGetInit();
}

dic* CreateInstance2(char*szDll)
{
	HINSTANCE h = LoadLibrary(szDll);
	if (h == NULL) return NULL;
	FUNC DllGetDic = (FUNC)GetProcAddress(h,"DllGetDic");
	if (DllGetDic == NULL) return NULL;
	return DllGetDic();
}*/

void remark()
{
	system("cls");
	cout<<"※※※※※※※※※※※※※※※※※※"<<endl
		<<"※  欢迎使用单词风暴（版本1.2）  ※"<<endl
		<<"※                               ※"<<endl
		<<"※※※※※※※※※※※※※※※※※※"<<endl;
	Sleep(normal);
	int i;
	initial* pif = new newinit();
	dic* pdic = new diction();
	testword* ptes = new newtestword();
	textp* ptex = new newtextp();
	reciteb* prec = new newreciteb();
	do
	{
		system("cls");
		cout<<"请选择你要做什么,只输出数字:"<<endl
			<<"1(初始化)，2(单词测试),3(查询单词)，4(历史记录），5(生词统计）,6(背单词),7（退出)"<<endl;
		
		cin.sync();
		cin>>i;
		while ( i!=1 && i!= 2 && i!= 3 && i!= 4 && i!=5 && i!=6 && i!=7)
		{
			cout<<"输出错误."<<endl;
			cin.sync();
			cin>>i;
		}
			
			switch(i)
			{
			case(1): pif->init(); break;
			case(2): ptes->testremark(ptes->testchoose()); break;
			case(3): pdic->dicpre();pdic->search();pdic->dicend(); break;
			case(4): pdic->history();break;
			case(5): ptex->textprocess();break;
			case(6): prec->recitebegin();break;
			default: break;
			}
			if (i ==7) break;
		
		}while ( i==1 || i ==2 || i==3 || i ==4 || i==5 || i==6 || i==7);
	delete pif;
	delete pdic;
	delete ptes;
	delete ptex;
	delete prec;
	
	return;
}
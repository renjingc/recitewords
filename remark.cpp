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
	cout<<"������������������������������������"<<endl
		<<"��  ��ӭʹ�õ��ʷ籩���汾1.2��  ��"<<endl
		<<"��                               ��"<<endl
		<<"������������������������������������"<<endl;
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
		cout<<"��ѡ����Ҫ��ʲô,ֻ�������:"<<endl
			<<"1(��ʼ��)��2(���ʲ���),3(��ѯ����)��4(��ʷ��¼����5(����ͳ�ƣ�,6(������),7���˳�)"<<endl;
		
		cin.sync();
		cin>>i;
		while ( i!=1 && i!= 2 && i!= 3 && i!= 4 && i!=5 && i!=6 && i!=7)
		{
			cout<<"�������."<<endl;
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
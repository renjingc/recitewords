#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"

using namespace std;

void newtestword::testprocess(int l,int choose)
{
	char c;
	int errorn = 0,spe = 0,total= 0;
	double result;
	const int level = l;
	do
	{
		for (int i = 0; i<10; i++)
		{
			system("cls");
			if (choose == 1)
			spe=testen(level);
			if (choose ==2)
				spe = testch(level);
			if (spe == 2) break;
			if (spe == -1) break;
			else errorn+=spe;
			total++;

		}
		if (spe == 2) break;
		if (spe == -1) break;
		cout<<"������(Y/N)"<<endl;
		cin.sync();
		cin>>c;
		while (c!='Y' && c!='N') 
		{
			cout<<"�������"<<endl;
			cin.sync();
			cin>>c;
		}
		if (c == 'N')
		{

			result = 1.00-double(double(errorn) / total);
			cout<<"������ȷ����:"<<result*100<<"%"<<endl;
			Sleep(review_time);
			break;
		}
		
	}while(c == 'Y');
	return;
}
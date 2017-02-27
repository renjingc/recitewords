#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"

using namespace std;

int justice(string coword)
{
	cout<<"请输入单词"<<endl;
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
		
		cout<<"抱歉！您答错了，再试一遍吗？(Y/N)"<<endl;
		
		char c;
		cin.sync();
		cin>>c;
		while (c !='N' && c!='Y') 
		{
			cout<<"请输入Y/N"<<endl;
			cin.sync();
			cin>>c;
		}

		if (c=='N') 
		{ 
			cout<<"正确答案是："<<coword<<endl; 
			Sleep(normal);
			return 1;
		}
		else 
		{
			cout<<"请输入单词："<<endl;
			cin.sync();
			cin>>word;
			if (word=="Q") return 2;
			if (word == coword)  { cout<<"答对了！"<<endl;Sleep(1000); return 0;}
			else 
			{
				changeclass(4,coword);
				cout<<"抱歉，您答错了。"<<endl;
				cout<<"正确答案是："<<coword<<endl;
				Sleep(normal);
				return 1;
			}
		}
	}
}
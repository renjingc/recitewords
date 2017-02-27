#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"
#include<cstdlib>
using namespace std;

string newreciteb::mark =initname;

void newreciteb::recitebegin()//提取背诵词表
{
	system("cls");
	recitein();
	char c;
	ifstream in("name.txt");
	string line;
	getline(in,name);
	in>>number;
	in.close();
	do
	{
		cout<<"请选择：1(单词初记);2(复习计划）3(退出)"<<endl;
		int ch;
		cin.sync();
		cin>>ch;
		while (ch!=1 && ch!=2 && ch!=3)
		{
			cout<<"输入错误."<<endl;
			cin.sync();
			cin>>ch;
		}
		if (ch ==1) recite();
		else if (ch ==2) review();
		else break;
		cout<<"退出吗？(Y/N)"<<endl;
		cin.sync();
		cin>>c;
		while (c!='Y' && c!='N')
		{
			cout<<"输入错误."<<endl;

			cin.sync();
			cin>>c;
		}
		
	}while (c == 'N');
	
	
	recitend();
	testwords.clear();
	testexp.clear();
	recitelist.clear();
	correct.clear();
	return;
}

void newreciteb::recite()//背诵单词,每次背诵MAX个
{
	system("cls");
	char c;
	int  b = 0;
	b= extractword(1);
	
		if (b == 1) 
		{
			cout<<"生词本为空"<<endl;
			return;
		}
		else {}
		string exp;
		if (mark=="") 
		{
			cout<<"已无单词可背诵"<<endl;
			return;
		}
		else 
		{
			if (mark == initname)
			{
				cout<<mark<<endl;
				cin.sync();
				cin>>name;
				number = 0;
				ofstream out("name.txt");
				out<<name<<endl
					<<number;
				out.close();
				mark = testwords[0];
				
			}
			else {
				
				}
			cout<<"欢迎"<<name<<endl;
			int begin = 0;
			while (testwords[begin]!=mark && begin!=testwords.size())
				begin++;
			
			if (begin==testwords.size())
			{
				cout<<"已无单词可背！"<<endl;
				return;
			}
			else
			do
			{
				cout<<"每个单词有3秒钟记忆时间！"<<endl;
				int i;
				for (i = begin; i < begin+MAX && i!=testwords.size(); i++)
				{
					
					exp = testexp[i];
					cout<<'('<<i-begin+1<<')'<<testwords[i]<<':'<<exp<<endl;
					int j = recitelist.size();
					recitelist.push_back( testwords[i]);
					
					correct.push_back(0);
					
					Sleep(recite_time);
				}
				begin = i;
				cout<<"继续吗?(Y/N)"<<endl;
				cin.sync();
				cin>>c;
				while (c!='Y' && c!='N') 
				{
					cout<<"请输入Y/N"<<endl;
					cin.sync();
					cin>>c;
				}
				number++;
				system("cls");
			}while(c=='Y');
			int end = begin;
			if (begin==testwords.size()) mark ="";
			else mark = testwords[begin];
			
			//recitend();
			
			
		}
		ofstream out("name.txt");
		out<<name<<endl
			<<number;
		out.close();
		return;
}

void newreciteb::review()//复习单词
{
	
	if (mark==initname)
	{
		cout<<"目前无单词可供复习！"<<endl;
		return;
	}
	char c;
	do
	{

		cout<<"您已经学习了"<<number<<"组:"<<endl
			<<"请选择您要复习的组项(仅用数字表示）"<<endl;
		int ch;
		cin.sync();
		cin>>ch;
		while (ch <1 || ch > number)
		{
			cout<<"输入错误。"<<endl;
			cin.sync();
			cin>>ch;
		}
		string exp;
		int j;
		cout<<"每个单词有2秒钟记忆时间！"<<endl;
		for (j = (ch-1)* MAX; j< ch*MAX && j!=newwords.size(); j++)
		{
			exp = (words.find(recitelist[j]))->second;
			cout<<recitelist[j]<<':'<<exp<<endl;
			Sleep(review_time);
		}
		system("cls");
		cout<<"需要测试吗？只有测试通过的单词才可以变为熟词.(Y/N)"<<endl;
		char chs;
		cin.sync();
		cin>>chs;
		while (chs!='Y' && chs!='N') 
		{
			cout<<"输入错误！"<<endl;
			cin.sync();
			cin>>chs;
		}
		if (chs == 'N') break;
		else 
		{
			string word;
			int errorn = 0,total =0,b;
			for (j = (ch-1)* MAX; j< ch*MAX && j!=recitelist.size(); j++)
			{
				system("cls");
				exp = (words.find(recitelist[j]))->second;
				string coword = recitelist[j];
				cout<<exp<<endl;
				 b= justice(coword);
				if (b ==2)
					break;
				else
				{
					errorn+=b;
					total++;
				}
				if (b==0) 
				{
					correct[j]++;
				}
			}
			if (b==2) break;
			else 
			{
				double result = 1.00-double(double(errorn) / double(total));
				cout<<"您的正确率是："<<result*100<<'%'<<endl;
				Sleep(review_time);
			}
		}
		cout<<"要继续吗"<<endl;
		cin.sync();
		cin>>c;
		while (c!='Y' && c!='N')
		{
			cout<<"请输入Y/N"<<endl;
			cin.sync();
			cin>>c;
		}
		system("cls");
	}while (c =='Y');
	int b = extractword(1);
	if (b==1) 
	{
		cout<<"生词本无单词!"<<endl;
		return;
	}
	b= extractword(2);
	for (int j = number* MAX; j< number*MAX && j!=recitelist.size(); j++)
	{
		if (correct[j] ==2)
		{
			changeclass(2,recitelist[j]);
			correct[j] =0;
		}
	}
	
	//recitend();
	//recitelist.clear();
	
	return;
}


void newreciteb::recitend()//将背诵输出到文件
{
	ofstream out;
	out.open("recitelist.txt");
	
	if (!out) 
	{
		cout<<"文件打开失败！"<<endl;
		return;
	}
	unsigned int i;
	out<<mark<<endl;

	for (i = 0; i< recitelist.size() && i<(number+1)* MAX; i++)
	{
		out<<recitelist[i]<<":"<<correct[i]<<endl;
		
	}
	
	out.close();
	return;
}

void newreciteb::recitein()//提取词表
{
	ifstream in("recitelist.txt");
	if (!in) 
	{
		cout<<"目前尚无背诵记录"<<endl;
		Sleep(normal);
		return;
	}
	string line,word;
	string::size_type i;
	int n;
	char f;
	getline(in,word);
	mark = word;
	while(getline(in,line))
	{
		i = line.find(":");
		word = line.substr(0,i);
		f = line[i+1];
		n = int(f)-(int('1')-1);
		recitelist.push_back(word);
		correct.push_back(n);
	}
	in.close();
}
	
	



	




		


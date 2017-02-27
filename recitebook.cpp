#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"
#include<cstdlib>
using namespace std;

string newreciteb::mark =initname;

void newreciteb::recitebegin()//��ȡ���дʱ�
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
		cout<<"��ѡ��1(���ʳ���);2(��ϰ�ƻ���3(�˳�)"<<endl;
		int ch;
		cin.sync();
		cin>>ch;
		while (ch!=1 && ch!=2 && ch!=3)
		{
			cout<<"�������."<<endl;
			cin.sync();
			cin>>ch;
		}
		if (ch ==1) recite();
		else if (ch ==2) review();
		else break;
		cout<<"�˳���(Y/N)"<<endl;
		cin.sync();
		cin>>c;
		while (c!='Y' && c!='N')
		{
			cout<<"�������."<<endl;

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

void newreciteb::recite()//���е���,ÿ�α���MAX��
{
	system("cls");
	char c;
	int  b = 0;
	b= extractword(1);
	
		if (b == 1) 
		{
			cout<<"���ʱ�Ϊ��"<<endl;
			return;
		}
		else {}
		string exp;
		if (mark=="") 
		{
			cout<<"���޵��ʿɱ���"<<endl;
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
			cout<<"��ӭ"<<name<<endl;
			int begin = 0;
			while (testwords[begin]!=mark && begin!=testwords.size())
				begin++;
			
			if (begin==testwords.size())
			{
				cout<<"���޵��ʿɱ���"<<endl;
				return;
			}
			else
			do
			{
				cout<<"ÿ��������3���Ӽ���ʱ�䣡"<<endl;
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
				cout<<"������?(Y/N)"<<endl;
				cin.sync();
				cin>>c;
				while (c!='Y' && c!='N') 
				{
					cout<<"������Y/N"<<endl;
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

void newreciteb::review()//��ϰ����
{
	
	if (mark==initname)
	{
		cout<<"Ŀǰ�޵��ʿɹ���ϰ��"<<endl;
		return;
	}
	char c;
	do
	{

		cout<<"���Ѿ�ѧϰ��"<<number<<"��:"<<endl
			<<"��ѡ����Ҫ��ϰ������(�������ֱ�ʾ��"<<endl;
		int ch;
		cin.sync();
		cin>>ch;
		while (ch <1 || ch > number)
		{
			cout<<"�������"<<endl;
			cin.sync();
			cin>>ch;
		}
		string exp;
		int j;
		cout<<"ÿ��������2���Ӽ���ʱ�䣡"<<endl;
		for (j = (ch-1)* MAX; j< ch*MAX && j!=newwords.size(); j++)
		{
			exp = (words.find(recitelist[j]))->second;
			cout<<recitelist[j]<<':'<<exp<<endl;
			Sleep(review_time);
		}
		system("cls");
		cout<<"��Ҫ������ֻ�в���ͨ���ĵ��ʲſ��Ա�Ϊ���.(Y/N)"<<endl;
		char chs;
		cin.sync();
		cin>>chs;
		while (chs!='Y' && chs!='N') 
		{
			cout<<"�������"<<endl;
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
				cout<<"������ȷ���ǣ�"<<result*100<<'%'<<endl;
				Sleep(review_time);
			}
		}
		cout<<"Ҫ������"<<endl;
		cin.sync();
		cin>>c;
		while (c!='Y' && c!='N')
		{
			cout<<"������Y/N"<<endl;
			cin.sync();
			cin>>c;
		}
		system("cls");
	}while (c =='Y');
	int b = extractword(1);
	if (b==1) 
	{
		cout<<"���ʱ��޵���!"<<endl;
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


void newreciteb::recitend()//������������ļ�
{
	ofstream out;
	out.open("recitelist.txt");
	
	if (!out) 
	{
		cout<<"�ļ���ʧ�ܣ�"<<endl;
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

void newreciteb::recitein()//��ȡ�ʱ�
{
	ifstream in("recitelist.txt");
	if (!in) 
	{
		cout<<"Ŀǰ���ޱ��м�¼"<<endl;
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
	
	



	




		


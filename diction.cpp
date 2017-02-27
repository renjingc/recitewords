#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"
#include<windows.h>
using namespace std;

deque<string> historylist;

void diction::lookup(const string& word)
{
	iterss i;
	
	i = words.find(word);
	if (i == words.end())
	{
		cout<<"���޴˴�!"<<endl;
		return;
	}
	cout<<i->second<<endl;
	map<string,string>::iterator j;
	j = examplelist.find(word);
	if (j != examplelist.end())
	{
		cout<<j->second;
		cout<<endl;
	}

	cout<<"�Ƿ�Ҫ�������(Y/N):"<<endl;
	char f;
	cin>>f;
	if (f !='N' && f !='Y') 
	{
		cout<<"������Y/N!"<<endl;
		return;
	}
	note(word);
	if (f=='N')
		return;
	if (f == 'Y') 
	{
		cout<<"���������䣺"<<endl;
		string line;
		cin.sync();
		if (getline(cin,line))
		{
			example(word,line);
			iterss k = examplelist.find(word);
		}
		
	}
	
	return;
}

void diction::note(string word)
{
	
	if (historylist.size() == maxnum) historylist.pop_back();
	historylist.push_front(word);
	return;
}

void diction::search()
{
	
	string word;
	char c;
	do
	{
		system("cls");
		cout<<"������Ҫ��ѯ�ĵ��ʣ�"<<endl;
		cin.sync();
		cin>>word;
		lookup(word);

		cout<<"��Ҫ����������Y����������N"<<endl;
		cin.sync();
		cin>>c;
		while (c !='Y' && c!='N') 
		{
			cout<<"������Y/N"<<endl;
			cin.sync();
			cin>>c;
		}
	}while (c == 'Y');
	return;
}

void diction::examplein()//���������
{
	ifstream in("example.txt");
	string line,word,ex;
	string::size_type i;
	while (getline(in,line))
	{
		i = line.find_first_of(":");
		word = line.substr(0,i);
		ex = line.substr(i+1,line.size()-i-1);
		examplelist.insert(make_pair(word,ex));
	}
	in.close();
	return;
}

int diction::historyin()//������ʷ��¼
{
	ifstream in;
	in.open("history.txt");
	if (!in)
	{
		return 1;
	}

	string line;
	while (getline(in,line))
		historylist.push_back(line);
	in.close();
	if (historylist.size() == 0)
	{
		cout<<"��ʷ��¼Ϊ��!"<<endl;
		Sleep(normal);
		return 1;
	}
	
	return 0;
}

void diction::history()
{
	int j = 1;
	cout<<"��ѡ����Ҫ���еĲ���"<<endl
		<<"1.�鿴��ʷ��¼��2.�����ʷ��¼"<<endl;
	int n;
	cin.sync();
	cin>>n;
	while(n<1 || n>2)
	{
		cout<<"������1��2"<<endl;
		cin.sync();
		cin>>n;
	}
	int b= historyin();
	if (b ==1) return;
	else 
	{
	if (n==1)
	{
		deque<string>::iterator i = historylist.begin();
		while (i != historylist.end())
		{
			cout<<"("<<j<<")"<<*i<<endl;
			j++;
			i++;
			Sleep(normal);
		}
		return;
	}
	else 
	{
		clehisty();
		historyprint();
	}
	return;
	}
}

void diction::historyprint()//������ʷ��¼���ļ�
{
	ofstream out("history.txt");
	if (!out) 
	{
		cout<<"history.txt ��ʧ�ܣ�"<<endl;
		return;
	}
	deque<string>::iterator i;
	for (i = historylist.begin(); i!=historylist.end(); i++)
	{
		
		out<<*i<<endl;
	}
	out.close();
	historylist.clear();
	return;
}

void diction::exampleprint()//�������䱾
{
	iterss i;
	ofstream out("example.txt");
	if (!out)
	{
		cout<<"example.txt��ʧ�ܣ�"<<endl;
		Sleep(normal);
		return;
	}
	for (i = examplelist.begin(); i!= examplelist.end(); i++)
	{
		out<<i->first<<":"<<i->second<<endl;
	}
	out.close();
	examplelist.clear();
	return;
}

void diction::clehisty()//���ȫ����ʷ��¼
{
	historylist.clear();
	return;
}

extern "C"__declspec(dllexport)
dic* DllGetDic() { return new diction;}


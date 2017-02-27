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
		cout<<"查无此词!"<<endl;
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

	cout<<"是否要添加例句(Y/N):"<<endl;
	char f;
	cin>>f;
	if (f !='N' && f !='Y') 
	{
		cout<<"请输入Y/N!"<<endl;
		return;
	}
	note(word);
	if (f=='N')
		return;
	if (f == 'Y') 
	{
		cout<<"请输入例句："<<endl;
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
		cout<<"请输入要查询的单词："<<endl;
		cin.sync();
		cin>>word;
		lookup(word);

		cout<<"需要继续请输入Y，否则输入N"<<endl;
		cin.sync();
		cin>>c;
		while (c !='Y' && c!='N') 
		{
			cout<<"请输入Y/N"<<endl;
			cin.sync();
			cin>>c;
		}
	}while (c == 'Y');
	return;
}

void diction::examplein()//加载例句库
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

int diction::historyin()//加载历史记录
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
		cout<<"历史记录为空!"<<endl;
		Sleep(normal);
		return 1;
	}
	
	return 0;
}

void diction::history()
{
	int j = 1;
	cout<<"请选择您要进行的操作"<<endl
		<<"1.查看历史记录；2.清空历史记录"<<endl;
	int n;
	cin.sync();
	cin>>n;
	while(n<1 || n>2)
	{
		cout<<"请输入1或2"<<endl;
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

void diction::historyprint()//输入历史记录到文件
{
	ofstream out("history.txt");
	if (!out) 
	{
		cout<<"history.txt 打开失败！"<<endl;
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

void diction::exampleprint()//更新例句本
{
	iterss i;
	ofstream out("example.txt");
	if (!out)
	{
		cout<<"example.txt打开失败！"<<endl;
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

void diction::clehisty()//清空全部历史记录
{
	historylist.clear();
	return;
}

extern "C"__declspec(dllexport)
dic* DllGetDic() { return new diction;}


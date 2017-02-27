//初始化难度
#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"
#include<iostream>
#include<string>
#include<map>
#include<fstream>

using namespace std;
map<string,string> words;
map<string,int> wordclass;

void newinit::init()//初始化难度
{
	//extract();
	iterss i= words.begin();
	wordclass.clear();
	
	for (; i!= words.end(); i++)
	{
		wordclass.insert(make_pair(i->first,1));//生词设为1
		newwords.insert(make_pair(i->first,i->second));
	}

	cout<<"是否需要重新设定单词难度？(Y/N)"<<endl;
	char c;
	cin>>c;
	while (c!='Y' && c!='N')
	{
		cout<<"请输入Y/N"<<endl;
		cin.sync();
		cin>>c;
	}
	if (c == 'N') {}
	else if (c == 'Y') 
	{
		
		extract2();//提取单词
		tofile* p = new newtofile();
		p->endfile();
		beginrecite();
	}
	
	
	return;
	
}

void newinit::extract2()//根据词表初始化难度
{
	cout<<"请选择更新文件类型(只填数字):"<<endl
		<<"1.生词；2.熟词；3. 罕见词；4. 易忘词"<<endl;
	int n;
	cin>>n;
	while (n<1 || n>5)
	{
		cout<<"请输入1-4中任意数字"<<endl;
		cin.sync();
		cin>>n;
	}

	
	cout<<"请输入文件名:"<<endl;
	string fname;
	cin>>fname;

	ifstream fin(fname.c_str());
	
	int b;
	for (int i = 1; i<4; i++)
	{
		b = extractword(i);
		testwords.clear();
	}

	if (!fin) 
	{
		cout<<"打开文件失败!"<<endl;
		Sleep(normal);
		return;
	}
	
	string word;
	map<string,int>::iterator j;

	while (fin>>word)
	{
		changeclass(n,word);
		
	}
	
	fin.close();
	cout<<"初始化成功"<<endl;
	Sleep(normal);
	
	//remark();

	return;
}

void newinit::extract()//提取单词库中单词和解释
{
	ifstream in(Diction.c_str());
	if (!in)
	{
		cout<<"diction unexisted!"<<endl;
		Sleep(normal);
		return;
	}
	string line;
	string word,exp;
	string::size_type i;
	while (getline(in,line))
	{
		i = line.find_first_of(":");
		word= line.substr(0,i);
		
		i = line.find_first_of("]");
		exp = line.substr(i+2,line.size()-i-2);
		words.insert(make_pair(word,exp));
	}
	
	in.close();
}

void newinit::wordclassin()//提取难度
{
	ifstream in("wordclass.txt");
	
	string line;
	string word;
	string::size_type i;
	int n;
	char c;
	int b =0 ;
	while (getline(in,line))
	{
		i = line.find_first_of(":");
		word= line.substr(0,i);
		c = line[i+1];
		n = int(c)- (int('1')-1);
		
		wordclass.insert(make_pair(word,n));
	}
	
	in.close();
}

		
//extern "C"__declspec(dllexport)
//initial* DllGetInit() { return new newinit;}









//从熟词文件中读取初始化信息
#include"decl.h"
#include<iostream>
#include<string>
#include<map>
#include<fstream>

using namespace std;

map<string,string> words;
map<string,int> wordclass;

void extract2()//根据熟词表初始化难度
{
	cout<<"请输入熟词文件名:"<<endl;
	string name;
	cin>>name;

	ifstream fin(name.c_str());

	if (!fin) 
	{
		cout<<"打开文件失败!"<<endl;
		exit(1);
	}

	string word;
	map<string,string>::iterator i;
	map<string,int>::iterator j;

	while (fin>>word)
	{
		i = words.find(word);
		if (i != words.end())
		{
			j = wordclass.find(word);
			j->second = 1;//熟词设为1
		}
	}
	fin.close();
	return;
}




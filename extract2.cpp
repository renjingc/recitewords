//������ļ��ж�ȡ��ʼ����Ϣ
#include"decl.h"
#include<iostream>
#include<string>
#include<map>
#include<fstream>

using namespace std;

map<string,string> words;
map<string,int> wordclass;

void extract2()//������ʱ��ʼ���Ѷ�
{
	cout<<"����������ļ���:"<<endl;
	string name;
	cin>>name;

	ifstream fin(name.c_str());

	if (!fin) 
	{
		cout<<"���ļ�ʧ��!"<<endl;
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
			j->second = 1;//�����Ϊ1
		}
	}
	fin.close();
	return;
}




#include"decl.h"
#include"newdecl.h"

#include<iostream>
#include<fstream>
#include<string>
#include<map>

using namespace std;

void newtofile::wordclassprint()//�������Ѷ�������ļ�
{
	ofstream out("wordclass.txt");
	
	if (!out) 
	{
		cout<<"�ļ���ʧ�ܣ�"<<endl;
		return;
	}
	map<string,int>::iterator j = wordclass.begin();
	for (; j!= wordclass.end(); j++)
	{
		out<<j->first<<":"<<j->second<<endl;
	
	}
	out.close();
	return;
}


void newtofile::wordsbook()//���¸���ʱ�
{
	ofstream out;
	map<string,string>::iterator i;
	i = newwords.begin();
	if (i!=newwords.end())
	{
		out.open("newwords.txt");//�������ʱ�
		if (!out) 
		{
			cout<<"newwords.txt ��ʧ�ܣ�"<<endl;
			return;
		}
		for( ; i!=newwords.end(); i++)
		{
			out<<i->first<<":"<<i->second<<endl;
		}
	
		out.close();
	}

	i = easywords.begin();
	if (i!=easywords.end())
	{
		out.open("easywords.txt");//������ʱ�
		if (!out)
		{
			cout<<"easywords.txt ��ʧ��! "<<endl;
			return;
		}
		for (i = easywords.begin(); i!=easywords.end(); i++)
		{
			out<<i->first<<":"<<i->second<<endl;
		}
		out.close();
	}
	
	i = uncommon.begin();
	if (i!=uncommon.end())
	{
		out.open("uncommon.txt");//���º����ʱ�
		if (!out)
		{
			cout<<"uncommon.txt ��ʧ�ܣ�"<<endl;
			return;
		}
		for (i = uncommon.begin(); i!=uncommon.end(); i++)
		{
			out<<i->first<<":"<<i->second<<endl;
		}
		out.close();
	}
	
	i = forgotten.begin();
	if (i!=forgotten.end())
	{
		out.open("forgotten.txt");//���������ʱ�
		if (!out)
		{
			cout<<"forgotten.txt ��ʧ�ܣ�"<<endl;
			return;
		
		}
		for (i = forgotten.begin(); i!=forgotten.end(); i++)
		{
			out<<i->first<<":"<<i->second<<endl;
		}
		out.close();
		
	}
	return;
}


extern "C"__declspec(dllexport)
tofile* DllGetToFile() { return new newtofile; }




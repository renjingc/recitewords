#include"decl.h"
#include"newdecl.h"

#include<iostream>
#include<fstream>
#include<string>
#include<map>

using namespace std;

void newtofile::wordclassprint()//将单词难度输出到文件
{
	ofstream out("wordclass.txt");
	
	if (!out) 
	{
		cout<<"文件打开失败！"<<endl;
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


void newtofile::wordsbook()//更新各类词本
{
	ofstream out;
	map<string,string>::iterator i;
	i = newwords.begin();
	if (i!=newwords.end())
	{
		out.open("newwords.txt");//更新生词本
		if (!out) 
		{
			cout<<"newwords.txt 打开失败！"<<endl;
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
		out.open("easywords.txt");//更新熟词本
		if (!out)
		{
			cout<<"easywords.txt 打开失败! "<<endl;
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
		out.open("uncommon.txt");//更新罕见词本
		if (!out)
		{
			cout<<"uncommon.txt 打开失败！"<<endl;
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
		out.open("forgotten.txt");//更新易忘词本
		if (!out)
		{
			cout<<"forgotten.txt 打开失败！"<<endl;
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




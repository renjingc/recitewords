//动态修改单词级别
#include"decl.h"
#include"test.h"
#include"newdecl.h"
#include"newtest.h"
#include<iostream>
#include<map>
#include<string>
#include<fstream>

using namespace std;

map<string,string> newwords;
map<string,string> easywords;
map<string,string> uncommon;
map<string,string> forgotten;

void changeclass(int n,string word)//改变单词级别到n
{
	ofstream out;
	int last;
	
	map<string,int>::iterator j;
	j = wordclass.find(word);
	last = j->second;
	j->second = n;//n为类型标号
	
	switch(last)
	{
	case(1): newwords.erase(word);break;
	case(2): easywords.erase(word);break;
	case(3): uncommon.erase(word);break;
	case(4): forgotten.erase(word);break;
	}
	
	iterss k;
	k = words.find(word);

	switch(n)
	{
	case(1): newwords.insert(make_pair(word,k->second));break;
	case(2): easywords.insert(make_pair(word,k->second));break;
	case(3): uncommon.insert(make_pair(word,k->second)); break;
	case(4): forgotten.insert(make_pair(word,k->second)); break;
	}
	
	return;
}

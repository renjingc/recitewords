#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"

using namespace std;

int extractword(int level)
{
	ifstream in;
	
	switch(level)
	{
	case(1):in.open("newwords.txt");break;
	case(2):in.open("easywords.txt");break;
	case(3):in.open("uncommon.txt");break;
	case(4):in.open("forgotten.txt");break;
	default:cout<<"输入错误"<<endl;return 2;
	}
	string word,exp,line;
	string::size_type i;
	if (!in)
	{
		switch(level)
		{
		case(1):cout<<"生词本还未建立！"<<endl;break;
		case(2):cout<<"熟词本还未建立!"<<endl;break;
		case(3):cout<<"易忘词本还未建立!"<<endl;break;
		case(4):cout<<"罕见词本还未建立！"<<endl;break;
		}
		Sleep(normal);
		return 1;
	}
	while(getline(in,line))
	{
		
		i = line.find(":");
		word = line.substr(0,i);
		exp = line.substr(i+1,line.size()-i-1);
	
		switch(level)
		{
		case(1):newwords.insert(make_pair(word,exp));break;
		case(2):easywords.insert(make_pair(word,exp));break;
		case(3):uncommon.insert(make_pair(word,exp));break;
		case(4):forgotten.insert(make_pair(word,exp));break;
		}
		testwords.push_back(word);
		testexp.push_back(exp);
		
	}
	in.close();
	
	
	return 0;
}


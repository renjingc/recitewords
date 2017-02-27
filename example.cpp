#include"decl.h"
#include"newdecl.h"
#include"newtest.h"
#include"test.h"

using namespace std;

map<string,string> examplelist;

void example(const string& word,const string& line)//Ìí¼ÓÀý¾ä
{
	iterss i = examplelist.find(word);
	if (i==examplelist.end())
	{
		examplelist.insert(make_pair(word,line));
		return;
	}
	string l= i->second;
	l = l + " " + line;
	i->second = l;
	return;
}
	


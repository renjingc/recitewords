//读取并设置参数
#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"

using namespace std;
string Diction;
int normal;
int recite_time;
int review_time;
int MAX;
int maxnum;

int extrinit()
{
	ifstream fin("config.txt");
	string::size_type i;
	string line;
	if (!fin)
	{
		return 1;
	}
	else 
	{
		string item,temp;
		while (fin>>item)
		{
			if (item=="DICTION")
				fin>>temp>>Diction;
			if (item=="NORMAL")
				fin>>temp>>normal;
			if (item=="RECITE_TIME")
				fin>>temp>>recite_time;
			if (item=="REVIEW_TIME")
				fin>>temp>>review_time;
			if (item=="MAX")
				fin>>temp>>MAX;
			if (item =="MAXNUM")
				fin>>temp>>maxnum;
		
		}
	return 0;
	}
}
		



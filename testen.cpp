#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"
#include<ctime>
#include<cstdlib>
using namespace std;

int newtestword::testen(int level)//∫∫”¢≤‚ ‘
{
	srand((unsigned int)time(NULL));
	int i = rand() % testwords.size();
	string coword = testwords[i];
	cout<<testexp[i]<<endl;
	return(justice(coword));
	
}
			


#ifndef NEWDECL_H
#define NEWDECL_H
#include"decl.h"
class newinit: public initial
{
	__declspec(dllexport)void extract();
	__declspec(dllexport)void wordclassin();
	
	
public:
	
	__declspec(dllexport)void extract2();
	__declspec(dllexport)void init();
	__declspec(dllexport)void beginrecite() 
	{
		extract();
		wordclassin();
	}
	~newinit(){}
};

class newtofile: public tofile
{
	
	//__declspec(dllexport)void wordsprint();
	__declspec(dllexport)void wordsbook();
	__declspec(dllexport) void wordclassprint();
	
public:
	void endfile()
	{
		wordclassprint();
		wordsbook();
		//wordsprint();
		return;
	}

	~newtofile(){}
};

#endif
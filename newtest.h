#ifndef NEWTEST_H
#define NEWTEST_H
#include"decl.h"
#include"test.h"
#include"newdecl.h"

class diction: public dic
{
	__declspec(dllexport)void lookup(const std::string&);//查一个单词
	__declspec(dllexport)void note(std::string);//记录查询历史
	
	__declspec(dllexport)void historyprint();//输入历史记录到文件
	__declspec(dllexport)void exampleprint();//打印例句
	__declspec(dllexport)void examplein();//导出例句
	__declspec(dllexport)void clehisty();//清空全部历史记录

public:
	__declspec(dllexport)int historyin();//加载历史记录
	__declspec(dllexport)void search();//查单词
	__declspec(dllexport)void history();//查询历史
	__declspec(dllexport)void dicpre()//准备查字典
	{
		examplein();
		historyin();
	}

	__declspec(dllexport)void dicend()//字典查询结束
	{
		exampleprint();
		historyprint();
	}

	
	~diction(){}
};

class newtestword: public testword
{
	
	__declspec(dllexport)void testprocess(int,int);//控制单词测试过程
	__declspec(dllexport)int testch(int);//英语单词测汉语解释
	__declspec(dllexport)int testen(int);//英汉测试
	
public:
	__declspec(dllexport) int testchoose();//选择测试方式
	__declspec(dllexport)void testremark(int);//测试
	
	
	~newtestword(){}
};

class newtextp:public textp
{
	__declspec(dllexport)void extracttext();//提取单词
	__declspec(dllexport)void newwordsfind(iset);//生词统计
public:
	__declspec(dllexport)void textprocess()//接口
	{
		extracttext();
	}
	~newtextp(){}
};

class newreciteb:public reciteb
{
	int number;
	std::string name;
	
	std::vector<std::string>recitelist;
	std::vector<int> correct;
	__declspec(dllexport)void recite();
	__declspec(dllexport)void review();
	__declspec(dllexport)void recitend();
	__declspec(dllexport)void recitein();
	__declspec(dllexport)void clehisty();
public:
	static std::string mark;
	__declspec(dllexport)void recitebegin();
	
	~newreciteb(){}
};


#endif

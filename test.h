#ifndef TEST_H
#define TEST_H

#include"decl.h"
#include"newdecl.h"

typedef std::set<std::string>::iterator iset;
extern int MAX;//每次背诵最多单词数
const std::string initname= "初次背诵,尊姓大名: ";

struct dic//查字典
{
	virtual void search() = 0;//查单词
	virtual void history()  = 0;//查询历史记录
	virtual int historyin()  = 0;//加载历史记录
	virtual void dicpre() = 0;//查字典准备
	virtual void dicend() = 0;//字典查询结束
	~dic(){}
private:
	virtual void note(std::string) = 0;//记录查询历史
	virtual void lookup(const std::string&)  = 0;//查询一个单词
	virtual void exampleprint() = 0;//更新例句库
	virtual void examplein() = 0;//加载例句库
	virtual void historyprint()  = 0;//输入历史记录到文件
	virtual void clehisty() = 0;//清空全部历史记录

};

struct testword//测试单词
{
	virtual void testremark(int) = 0;//测试
	
	virtual int testchoose() = 0;
	//virtual int justice(std::string) =0;//判断正误
	~testword(){}
private:
	virtual int testch(int) = 0;//给英文单词从中文解释中选出正确的解释
	virtual int testen(int) = 0;//英汉测试
	virtual void testprocess(int,int) = 0;//控制测试过程
};

struct textp//生词统计
{
	virtual void textprocess() = 0;//接口
	~textp(){}
private:
	virtual void extracttext() = 0;//提取单词
	virtual void newwordsfind(iset) = 0;//生词统计
};

struct reciteb//背单词
{
	virtual void recitebegin() = 0;//准备
	static std::string mark;//下次背诵的第一个单词
	~reciteb(){}
private:
	int number;//已背组数
	std::string name;
	
	std::vector<std::string> recitelist;//已背词表
	std::vector<int> correct;//对应正确次数
	virtual void recitein() = 0;//提取词表
	virtual void recite() = 0;//背诵
	virtual void review() = 0;//复习
	virtual void recitend() = 0;//输入记录到文件

};

__declspec(dllexport)int justice(std::string);//判断正误

#endif

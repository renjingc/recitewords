//初始化和结束时处理
#ifndef DECL_H
#define DECL_H
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>
#include<deque>
#include<windows.h>
#include<set>

extern std::map<std::string,std::string> words;//单词库
extern std::map<std::string,int> wordclass;//难度库
extern std::map<std::string,std::string> newwords;//生词库
extern std::map<std::string,std::string> easywords;//熟词库
extern std::map<std::string,std::string> uncommon;//罕见词库
extern std::map<std::string,std::string> forgotten;//易忘词库
extern std::deque<std::string> historylist;//历史记录
extern std::map<std::string,std::string> examplelist;//例句
extern std::vector<std::string> testwords;//测试时和背诵单词时使用存单词
extern std::vector<std::string> testexp;//测试时使用存解释
extern std::string Diction;
extern std::set<std::string> unknwnset;//生词统计时词库
extern int normal;
extern int recite_time;
extern int review_time;
extern int maxnum;//最多存放历史记录

struct initial//更新
{
	virtual void beginrecite() = 0;//每次更新
	virtual void init() = 0;//初始化难度
	virtual void extract2()= 0;//根据文件初始化难度
	~initial(){}
private:
	virtual void extract() = 0;//提取单词库中单词和解释
	virtual void wordclassin() = 0;//从文件提取难度信息
	
};



struct tofile
{
private:
	virtual void wordclassprint() = 0;//输出难度到文件
	//virtual void wordsprint() = 0;//输入单词到文件
	virtual void wordsbook() = 0;//输入各种类型的词到相应词本
		
public:
	virtual void endfile() = 0;//结束文件
	~tofile(){}
};


extern "C"__declspec(dllexport) void changeclass(int,std::string);//改变单词级别

extern "C"__declspec(dllexport) void remark();//提示选择项

typedef std::map<std::string,std::string>::iterator iterss;
extern "C"__declspec(dllexport) void example(const std::string&,const std::string&);//添加例句
extern "C"__declspec(dllexport)int extractword(int);//从单词本中提取单词
extern "C"__declspec(dllexport) int extrinit();//读取配置文件并设置参数

#endif
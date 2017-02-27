//��ʼ���ͽ���ʱ����
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

extern std::map<std::string,std::string> words;//���ʿ�
extern std::map<std::string,int> wordclass;//�Ѷȿ�
extern std::map<std::string,std::string> newwords;//���ʿ�
extern std::map<std::string,std::string> easywords;//��ʿ�
extern std::map<std::string,std::string> uncommon;//�����ʿ�
extern std::map<std::string,std::string> forgotten;//�����ʿ�
extern std::deque<std::string> historylist;//��ʷ��¼
extern std::map<std::string,std::string> examplelist;//����
extern std::vector<std::string> testwords;//����ʱ�ͱ��е���ʱʹ�ô浥��
extern std::vector<std::string> testexp;//����ʱʹ�ô����
extern std::string Diction;
extern std::set<std::string> unknwnset;//����ͳ��ʱ�ʿ�
extern int normal;
extern int recite_time;
extern int review_time;
extern int maxnum;//�������ʷ��¼

struct initial//����
{
	virtual void beginrecite() = 0;//ÿ�θ���
	virtual void init() = 0;//��ʼ���Ѷ�
	virtual void extract2()= 0;//�����ļ���ʼ���Ѷ�
	~initial(){}
private:
	virtual void extract() = 0;//��ȡ���ʿ��е��ʺͽ���
	virtual void wordclassin() = 0;//���ļ���ȡ�Ѷ���Ϣ
	
};



struct tofile
{
private:
	virtual void wordclassprint() = 0;//����Ѷȵ��ļ�
	//virtual void wordsprint() = 0;//���뵥�ʵ��ļ�
	virtual void wordsbook() = 0;//����������͵Ĵʵ���Ӧ�ʱ�
		
public:
	virtual void endfile() = 0;//�����ļ�
	~tofile(){}
};


extern "C"__declspec(dllexport) void changeclass(int,std::string);//�ı䵥�ʼ���

extern "C"__declspec(dllexport) void remark();//��ʾѡ����

typedef std::map<std::string,std::string>::iterator iterss;
extern "C"__declspec(dllexport) void example(const std::string&,const std::string&);//�������
extern "C"__declspec(dllexport)int extractword(int);//�ӵ��ʱ�����ȡ����
extern "C"__declspec(dllexport) int extrinit();//��ȡ�����ļ������ò���

#endif
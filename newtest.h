#ifndef NEWTEST_H
#define NEWTEST_H
#include"decl.h"
#include"test.h"
#include"newdecl.h"

class diction: public dic
{
	__declspec(dllexport)void lookup(const std::string&);//��һ������
	__declspec(dllexport)void note(std::string);//��¼��ѯ��ʷ
	
	__declspec(dllexport)void historyprint();//������ʷ��¼���ļ�
	__declspec(dllexport)void exampleprint();//��ӡ����
	__declspec(dllexport)void examplein();//��������
	__declspec(dllexport)void clehisty();//���ȫ����ʷ��¼

public:
	__declspec(dllexport)int historyin();//������ʷ��¼
	__declspec(dllexport)void search();//�鵥��
	__declspec(dllexport)void history();//��ѯ��ʷ
	__declspec(dllexport)void dicpre()//׼�����ֵ�
	{
		examplein();
		historyin();
	}

	__declspec(dllexport)void dicend()//�ֵ��ѯ����
	{
		exampleprint();
		historyprint();
	}

	
	~diction(){}
};

class newtestword: public testword
{
	
	__declspec(dllexport)void testprocess(int,int);//���Ƶ��ʲ��Թ���
	__declspec(dllexport)int testch(int);//Ӣ�ﵥ�ʲ⺺�����
	__declspec(dllexport)int testen(int);//Ӣ������
	
public:
	__declspec(dllexport) int testchoose();//ѡ����Է�ʽ
	__declspec(dllexport)void testremark(int);//����
	
	
	~newtestword(){}
};

class newtextp:public textp
{
	__declspec(dllexport)void extracttext();//��ȡ����
	__declspec(dllexport)void newwordsfind(iset);//����ͳ��
public:
	__declspec(dllexport)void textprocess()//�ӿ�
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

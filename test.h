#ifndef TEST_H
#define TEST_H

#include"decl.h"
#include"newdecl.h"

typedef std::set<std::string>::iterator iset;
extern int MAX;//ÿ�α�����൥����
const std::string initname= "���α���,���մ���: ";

struct dic//���ֵ�
{
	virtual void search() = 0;//�鵥��
	virtual void history()  = 0;//��ѯ��ʷ��¼
	virtual int historyin()  = 0;//������ʷ��¼
	virtual void dicpre() = 0;//���ֵ�׼��
	virtual void dicend() = 0;//�ֵ��ѯ����
	~dic(){}
private:
	virtual void note(std::string) = 0;//��¼��ѯ��ʷ
	virtual void lookup(const std::string&)  = 0;//��ѯһ������
	virtual void exampleprint() = 0;//���������
	virtual void examplein() = 0;//���������
	virtual void historyprint()  = 0;//������ʷ��¼���ļ�
	virtual void clehisty() = 0;//���ȫ����ʷ��¼

};

struct testword//���Ե���
{
	virtual void testremark(int) = 0;//����
	
	virtual int testchoose() = 0;
	//virtual int justice(std::string) =0;//�ж�����
	~testword(){}
private:
	virtual int testch(int) = 0;//��Ӣ�ĵ��ʴ����Ľ�����ѡ����ȷ�Ľ���
	virtual int testen(int) = 0;//Ӣ������
	virtual void testprocess(int,int) = 0;//���Ʋ��Թ���
};

struct textp//����ͳ��
{
	virtual void textprocess() = 0;//�ӿ�
	~textp(){}
private:
	virtual void extracttext() = 0;//��ȡ����
	virtual void newwordsfind(iset) = 0;//����ͳ��
};

struct reciteb//������
{
	virtual void recitebegin() = 0;//׼��
	static std::string mark;//�´α��еĵ�һ������
	~reciteb(){}
private:
	int number;//�ѱ�����
	std::string name;
	
	std::vector<std::string> recitelist;//�ѱ��ʱ�
	std::vector<int> correct;//��Ӧ��ȷ����
	virtual void recitein() = 0;//��ȡ�ʱ�
	virtual void recite() = 0;//����
	virtual void review() = 0;//��ϰ
	virtual void recitend() = 0;//�����¼���ļ�

};

__declspec(dllexport)int justice(std::string);//�ж�����

#endif

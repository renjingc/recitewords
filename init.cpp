//��ʼ���Ѷ�
#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"
#include<iostream>
#include<string>
#include<map>
#include<fstream>

using namespace std;
map<string,string> words;
map<string,int> wordclass;

void newinit::init()//��ʼ���Ѷ�
{
	//extract();
	iterss i= words.begin();
	wordclass.clear();
	
	for (; i!= words.end(); i++)
	{
		wordclass.insert(make_pair(i->first,1));//������Ϊ1
		newwords.insert(make_pair(i->first,i->second));
	}

	cout<<"�Ƿ���Ҫ�����趨�����Ѷȣ�(Y/N)"<<endl;
	char c;
	cin>>c;
	while (c!='Y' && c!='N')
	{
		cout<<"������Y/N"<<endl;
		cin.sync();
		cin>>c;
	}
	if (c == 'N') {}
	else if (c == 'Y') 
	{
		
		extract2();//��ȡ����
		tofile* p = new newtofile();
		p->endfile();
		beginrecite();
	}
	
	
	return;
	
}

void newinit::extract2()//���ݴʱ��ʼ���Ѷ�
{
	cout<<"��ѡ������ļ�����(ֻ������):"<<endl
		<<"1.���ʣ�2.��ʣ�3. �����ʣ�4. ������"<<endl;
	int n;
	cin>>n;
	while (n<1 || n>5)
	{
		cout<<"������1-4����������"<<endl;
		cin.sync();
		cin>>n;
	}

	
	cout<<"�������ļ���:"<<endl;
	string fname;
	cin>>fname;

	ifstream fin(fname.c_str());
	
	int b;
	for (int i = 1; i<4; i++)
	{
		b = extractword(i);
		testwords.clear();
	}

	if (!fin) 
	{
		cout<<"���ļ�ʧ��!"<<endl;
		Sleep(normal);
		return;
	}
	
	string word;
	map<string,int>::iterator j;

	while (fin>>word)
	{
		changeclass(n,word);
		
	}
	
	fin.close();
	cout<<"��ʼ���ɹ�"<<endl;
	Sleep(normal);
	
	//remark();

	return;
}

void newinit::extract()//��ȡ���ʿ��е��ʺͽ���
{
	ifstream in(Diction.c_str());
	if (!in)
	{
		cout<<"diction unexisted!"<<endl;
		Sleep(normal);
		return;
	}
	string line;
	string word,exp;
	string::size_type i;
	while (getline(in,line))
	{
		i = line.find_first_of(":");
		word= line.substr(0,i);
		
		i = line.find_first_of("]");
		exp = line.substr(i+2,line.size()-i-2);
		words.insert(make_pair(word,exp));
	}
	
	in.close();
}

void newinit::wordclassin()//��ȡ�Ѷ�
{
	ifstream in("wordclass.txt");
	
	string line;
	string word;
	string::size_type i;
	int n;
	char c;
	int b =0 ;
	while (getline(in,line))
	{
		i = line.find_first_of(":");
		word= line.substr(0,i);
		c = line[i+1];
		n = int(c)- (int('1')-1);
		
		wordclass.insert(make_pair(word,n));
	}
	
	in.close();
}

		
//extern "C"__declspec(dllexport)
//initial* DllGetInit() { return new newinit;}









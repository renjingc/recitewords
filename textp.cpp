#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"
#include<algorithm>
#include<cctype>

using namespace std;

set<string> unknwnset;

void newtextp::extracttext()//��ȡ����
{
	ifstream in;
	vector<string> unknwnword;
	cout<<"����������Ҫ������ļ�����"<<endl;
	string name,line;
	string::size_type pos,prev_pos;
	string word;
	cin.sync();
	cin>>name;
	in.open(name.c_str());
	if (!in)
	{
		cout<<"�ļ���ʧ�ܣ�"<<endl;
		Sleep(normal);
		return;
	}
	while (getline(in,line))
	{
		pos = 0;
		prev_pos = 0;
		while ((pos = line.find_first_of(' ',pos)) != string::npos)
		{
			unknwnword.push_back(line.substr(prev_pos,pos-prev_pos));
			prev_pos = ++pos;
		}
		unknwnword.push_back(line.substr(prev_pos,pos-prev_pos));
	}
	in.close();
	vector<string>::iterator i;
	string filt_elems("\",.;:!?)(\\/");
	i = unknwnword.begin();
	while (i!= unknwnword.end())
	{
		pos= 0;
		while ((pos = pos = (*i).find_first_of(filt_elems,pos))!=string::npos)
		{
			(*i).erase(pos,1);
		}
		unknwnset.insert(*i);
		i++;
	}
	
	extractword(1);
	
	iset j = unknwnset.begin();
	system("cls");
	for (; j!=unknwnset.end(); j++)
		newwordsfind(j);
	Sleep(normal);
	newwords.clear();
}

void newtextp::newwordsfind(iset j)//����ͳ��
{
	
	string l1;
	l1 = *j;
	iterss i = newwords.find(l1);
	if (i!= newwords.end())
	{
		cout<<i->first<<": "<<i->second<<endl;
		return;
	}
	//transform((*j).begin(),(*j).end(),(*j).begin(),::tolower);
	i = newwords.find(*j);
	if (i!= newwords.end())
	{
		cout<<i->first<<": "<<i->second<<endl;
		return;
	}
	return;
}





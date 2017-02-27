#include"decl.h"
#include"newdecl.h"
#include"test.h"
#include"newtest.h"
#include<ctime>
#include<cstdlib>

using namespace std;

vector<string> testwords;
vector<string> testexp;

void newtestword::testremark(int choose)
{
	int level;
	ofstream out;
	char ch;
	int b;
	vector<string>::iterator i;
	do
	{
		system("cls");
		cout<<"请选择测试范围："<<endl
			<<"0.全部单词；1. 生词本；2.熟词本；3.罕见词本；4.易忘词本; 5.退出"<<endl
			<<"测试开始后想退出只需在提示输入时输入Q"<<endl;
			cin.sync();
			cin>>level;
		while (level !=0 && level !=1 && level !=2 && level!=3 && level !=4 && level!=5)
		{
			cout<<"输入错误！"<<endl;
			cin.sync();
			cin>>level;
		}
		if (level ==5) { return;}
		
		iterss j;
		if (level==0)
		{
			for (j = words.begin(); j!=words.end(); j++)
				testwords.push_back(j->first);
			testprocess(0,choose);
		}
		if (level==1)
		{
			b = extractword(1);
			if (b!=0) return;
			j =newwords.begin();
			if (j!=newwords.end())
			{
				testprocess(1,choose);
			}
			else 
			{
				cout<<"对不起，该词库无单词！"<<endl;
				continue;
			}
		}
		if (level ==2)
		{
			b = extractword(2);
			if (b!=0) return;
			j ==easywords.begin();

			if (j!=easywords.end())
			{
				testprocess(2,choose);
			}
			else 
			{
				cout<<"对不起，该词库无单词！"<<endl;
				continue;
			}
		}
		if (level==3)
		{
			b = extractword(3);
			if (b!=0) return;
			j==uncommon.begin();
			if (j!=uncommon.end())
			{
				testprocess(3,choose);
			}
			else 
			{
				cout<<"对不起，该词库无单词！"<<endl;
				continue;
			}
		}

		if (level==4)
		{
			b = extractword(4);
			if (b!=0) return;
			j==forgotten.begin();
			if (j!=forgotten.end())
			{
				testprocess(4,choose);
			}
			else 
			{
				cout<<"对不起，该词库无单词！"<<endl;
				continue;
			}
		}
		testwords.clear();
		testexp.clear();
		system("cls");
		cout<<"选择其它词本？(Y/N)"<<endl;
		cin.sync();
		cin>>ch;
		while (ch!='Y' && ch!='N') 
		{
			cout<<"输入错误！"<<endl;
			cin.sync();
			cin>>ch;
		}
		
	}while(ch =='Y');
	
	return;
}

int newtestword::testchoose()//选择测试方式
{
	cout<<"请选择测试方式："<<endl
		<<"1（汉英测试）；2( 英汉测试)"<<endl;
	cin.sync();
	char c;
	cin>>c;
	while (c!='1' && c!='2') 
	{
		cout<<"输入错误！"<<endl;
		cin.sync();
		cin>>c;
	}
	if (c=='1') return 1;
	else return 2;
}


int newtestword::testch(int level)//英汉测试
{
	int n = 0,i;
	int itera[3];
	char coword;
	
	if (testwords.size()<10) 
	{
		cout<<"对不起，您的测试数据太少，无法测试！"<<endl;
		Sleep(normal);
		return -1;
	}

	srand((unsigned int)time(NULL));
	
	itera[0]= rand()% testwords.size();//正确选项
	
	while (n<2)
	{
		n++;
		itera[n]=rand() % testwords.size();
		for (i = 0; i<n; i++)
			if (itera[i] == itera[n])
				break;
		if (i<n) n--;
	}
	n = rand()% 2;
	
	int temp;
	temp = itera[n];
	itera[n] =itera[0];
	itera[0] = temp;
	coword = char(n+int('A'));
	cout<<testwords[itera[n]]<<endl;

	for (i = 0; i<3; i++)
	{
		cout<<char(i+int('A'))<<" "
			<<testexp[itera[i]]<<endl;
	}
	cout<<"请输入单词解释选项"<<endl;
	char word;
	cin.sync();
	cin>>word;
	if (word =='Q') return 2;
	while(word!='a' && word!='A' && word!='b' && word!='B'&& word!='c' && word!='C')
	{
		cout<<"请输入a-c 或 A-C"<<endl;
		cin.sync();
		cin>>word;
	}
	
	if (word == coword || word ==char(int(coword)+int('a')-int('A'))) 
	{
		cout<<"Correct!"<<endl;
		Sleep(1000);
		return 0;
	}
	else 
	{
		
		cout<<"抱歉！您答错了，再试一遍吗？(Y/N)"<<endl;
		
		char c;
		cin.sync();
		cin>>c;
		while (c !='N' && c!='Y') cout<<"输入错误！"<<endl;
		if (c=='N') 
		{ 
			cout<<"正确答案是："<<coword<<endl; 
			Sleep(review_time);
			return 1;
		}
		else 
		{
			cout<<"请输入单词解释选项："<<endl;
			cin.sync();
			cin>>word;
			if (word=='Q') return 2;
			if (word == coword || word ==char(int(coword)+int('a')-int('A')))  
			{ 
				cout<<"答对了！"<<endl;
				Sleep(normal); 
				return 0;
			}
			else 
			{
				changeclass(4,testwords[itera[n]]);
				cout<<"抱歉，您答错了。"<<endl;
				cout<<"正确答案是："<<coword<<endl;
				Sleep(review_time);
				return 1;
			}
		}
	}
}


	


		





				
				




	



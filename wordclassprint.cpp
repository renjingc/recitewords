#include"decl.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

map<string,string> words;
map<string,int> wordclass;

void wordclassprint()//将单词难度输出到文件

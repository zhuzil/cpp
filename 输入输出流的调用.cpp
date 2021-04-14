/*
作者：19c207 朱轩宇
目的：通过输入输出流读取txt文件的数据，然后进行输入，删除等功能
时间：2021.4.11
*/

#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<fstream>
#include<iomanip>

using namespace std;

int main() 
{
	multimap<string, string> zp;//作品信息数据
	ifstream in("作品信息.txt");//读文件数据
	ofstream out;
	string author, work;
	int n = 0;//保存作品数量
	if(!in)
	{
		cout << "读文件时打开失败。";
			return 0;
	}
	else {
		in >> n;
		for (int i = 0; i < n; i++) {
			in >> author >> work;
			zp.insert(make_pair(author, work));
		}
	}
	string name;
	cout << "请输入要删除的作者：";
	cin >> name;
	int m = zp.count(name);//记录找到的个数
	if (m == 0)
	{
		cout << "没有找到。";
	}
	else {
		auto it = zp.find(name);
		zp.erase(name);
		cout << "删除成功。"<<endl;
		//把zp输出到一个新的txt文件中
		out.open("新建文本文档.txt");
		if (!out)
		{
			cout << "写入时文件打开失败。" << endl;
			return 0;
		}
		else {
			out << n-m << endl;
			for (auto it = zp.begin(); it != zp.end(); it++)
			{
				
				out << left<<setw(20)<< it->first << "\t" <<  setw(20)<< it->second << endl;
			}
			cout << "写入成功" << endl;
		}
	}
	//可以用来遍历一遍zp中的数据
	for(auto it = zp.begin();it!=zp.end();it++)
	{
		cout << left << setw(20) << it->first << setw(20)<< it->second<<endl;
	}
	
	
	
	in.close();
	out.close();
	return 0;
}
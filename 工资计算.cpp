/*
作者：竹子
目的：我们部门计算工资有点麻烦，所以写了一个程序可以计算，并且输出结果，方便了部门工资的计算。
运用的文件流的输入和输出
*/
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;
int n = 0;
class person
{
public:
	double time=0;
	string name=" ";
	string xuehao = " ";
	double money=0;
	person() = default;
	~person() {}
//算时间
	void gettime(double a) { time = a; }
	//算绩效和罚款
	void getmoney(double a) { money = money + a; }
	//输入名字和学号
	void getname(string a, string b) { swap(a,name); swap(b, xuehao); n++; }
	//算总金额
	void count()
	{
		if (time < 16) { money = money + time * 16; }
		else if (time >= 16 && time < 20) { 
			money = money + 260 + (time - 16) * 10; }
		else if (time >= 20) {
			money = money + 300 + (time - 20) * 8;}
	}
};
int main()
{
	person a[25];
	ofstream out;
	ifstream in("工资.txt");//读文件数据
	double d;
	if (!in)
	{
		cout << "读文件时打开失败。";
		return 0;
	}
	else
	{
		string l,w,e;//把前三行弄掉
		getline(in, l);
		getline(in, w);
		getline(in, e);

		//输入数据
		for (int i = 0; !in.eof(); i++)
		{
			string l;//保存文件的一行
			getline(in, l);//读取一行文件
			string b, c;//保存名字和学号
			istringstream iss(l);//string流输入
			iss >> b >> c;//一行的前两个是人名和学号
			a[i].getname(b, c);//得到人名和学号
			vector<string> m;//保存后面的工作时间，以便后面转换为double
			string q;//得到后面的数字
			while (iss >> q) { m.push_back(q); }//将string流里的字符压入容器里面
			double p[20] = { 0 };//保存得到的数据
			for (int j = 0; j < m.size(); j++) {//将string转化为double
				p[j] = atof(m[j].c_str());
			}
			for (int k = 0; k < m.size(); k++) {//计算时间
				if (p[k] < 10) { a[i].time += p[k]; }
				else {
					a[i].getmoney(p[k]);
				}
			}

			//计算数据
			 a[i].count();
		}
		cout << "输入成功" << endl;
		//输出到文本
		out.open("结果.txt");
		if (!out)
		{
			cout << "写入时文件打开失败。" << endl;
			return 0;
		}
		else {
			out << left << setw(50) << "姓名" << setw(50) << "学号" << setw(50) << "总时间" << setw(50) << "总工资" << endl;
			for (int i = 0; i < n-2; i++)
			{
				out << left << setw(50) << a[i].name << setw(50) << a[i].xuehao << setw(50) << a[i].time << setw(50) << a[i].money << endl;
			}
			cout << "写入成功" << endl;
		}
		in.close();
		out.close();
		system("pause");
		return 0;
	}
}

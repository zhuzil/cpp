/*
      
	  作者：竹子
	  时间：2020年11月12日
	  目的：求sin（）
*/
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double t, x, y=0.0;
	double i=1;

	//输入x
	cout << "请输入x=";
	cin >> x;
	t = x;
	//计算sin（x）
	while (fabs(t) > 1.0e-5)//确定精度
	{//利用泰勒公式计算，循环
		y += t;
		i++;
		t *= -x * x / ((2 * i - 1) * (2 * i - 2));
	}
	//输出y
	cout << "sin(" << x << ")" << y << endl;
	cout << "真实值是：" << sin(x) << endl;
		return 0;
}
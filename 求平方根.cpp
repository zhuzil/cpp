/*
作者：竹子
时间：2020.12.21
目的：求一个数的平方根
*/
#include<iostream>
using namespace std;
int main() {
	double a, x1 = 1, x2 = 2,t=1;
	cout << "please input a figure";
	cin >> a;
	while (a < 0) {
		cout << "a应该大于0,请重新输入";
		cin >> a;
	}
	while (fabs(t) > 1e-5)//可以用来确定精度
	 {//循环
			x2 = (x1 + a / x1) / 2;
			t = x1 - x2;
			x1 = x2;
		}
	cout << x1;
	return 0;
}
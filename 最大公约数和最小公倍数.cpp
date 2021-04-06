/*


目的：完成作业，求两个数的最大公约数和最小公倍数
作者：竹子
时间：2020年11月12号


*/


#include<iostream>
#include<cmath>
using namespace std;
int main() {
	
	//输入两个数
	int m, n;
	cout << "请输入两个整数m，n" << endl;
	cin >> m >> n;
	//定义一个a，为m与n的乘积
	int a = m * n;
	//判断m,n的大小
	if (m < n) {
		int t;
		t = m;
		m = n;
		n = t;
	}
	//用辗转相除法计算最大公约数并且输出最大公约数
	//判断m是不是n的倍数
	int x=0;
	if(m % n != 0) {
		while (m % n != 0) {
			x = m % n;
			m = n;
			n = x;
		}
		cout << "最大公约数是：" << x << endl;
	}
	else {
		x = n;
		cout << "最大公约数是：" << x << endl;
	}
	//因为之前计算的时候m与n的值已经发生了变换
	//所以在前面定义一个a是m和n的乘积
	//计算最小公倍数
	double y=0;
	y = a / x;
	//输出最小公倍数
	cout << "最小公倍数是：" << y << endl;
		return 0;
}
/*
姓名：竹子
时间：2021.3.29
目的：利用动态数组，自己写一个vector
*/
#include<iostream>
using namespace std;

template<typename T>
class MyVec
{
protected:
	int m_size=0;
	T * m_p=nullptr;
public:
	~MyVec() { delete[]m_p; }//析构函数，delete动态数组
	MyVec(){}
	MyVec(int size):m_p(new T[size]){}
	//复制构造函数
	MyVec(const MyVec& p) : m_size(p.m_size)
	{
		m_p=new T[p.m_size] ;
		for (int i = 0; i < p.m_size; i++)
	    {m_p[i] = p.m_p[i];}
	}
	//移动复制构造函数
	MyVec(MyVec&& p) : m_size(p.m_size),m_p(p.m_p)
	{
		p.m_size = 0;
		p.m_p = nullptr;
	}
	//重载=运算符
	MyVec& operator=(const MyVec& a)
	{
		if(this != &a)
		{
			delete[]m_p;
			m_size = a.m_size;
			m_p = new T[a.m_size];
			for (int i = 0; i < a.m_size; i++)
			{
				m_p[i] = a.m_p[i];
			}
		}
		return *this;
	}
	//移动重载=运算符
	MyVec& operator=(const MyVec&& a)
	{
		if (this != &a)
		{
			delete[]m_p;
			m_size = a.m_size;
			m_p = a.m_p;
			a.m_p=nullptr;
			a.m_size = 0;
		}
		return *this;
	}
	int size() { return m_size; }
	//重载[]运算符
	T& operator[](int i) {
		return m_p[i];
	}
	//在后面压入
	void push_back(T val){
		T* p = new T[m_size + 1];
		for (int i = 0; i <m_size; i++)
		{
			p[i] = m_p[i];
		}
		p[m_size] = val;
		delete[]m_p;
		m_p = p;
		m_size++;
	}
	//删除最后那个
	void pop_back() {
		if (m_size == 0)return;
		T* p = new T[m_size - 1];
		for (int i = 0; i < m_size-1; i++)
		{
			p[i] = m_p[i];
		}
		delete[]m_p;
		m_p = p;
		m_size--;
	}
	void show()
	{
		for (int i = 0; i < m_size; i++)
		{
			cout << m_p[i] << " ";
		}
		cout << endl;
	}
	//指定位置插入
	void insert(int n,T m) 
	{
		if (n <= 0) return;
		T* p = new T[m_size + 1];
		for (int i = 0; i < n ; i++)
		{
			p[i] = m_p[i];
		}
		p[n] = m;
		for (int i = n+1; i < m_size + 1; i++)
		{
			p[i] = m_p[i-1];
		}
		delete[]m_p;
		m_p = p;
		m_size++;
	}
	//指定位置删除
	void erase(int n)
	{
		if (n <= 0) return;
		T* p = new T[m_size - 1];
		for (int i = 0; i < n; i++)
		{
			p[i] = m_p[i];
		}
		for (int i = n ; i < m_size - 1; i++)
		{
			p[i] = m_p[i + 1];
		}
		delete[]m_p;
		m_p = p;
		m_size--;
	}
};

int main() 
{
	MyVec<int>v1;
	//测试push_back
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i*i);
	}
	v1.show();
	//测试pop_back
	v1.pop_back();
	v1.show();
	//测试指定位置插入
	v1.insert(3, 0);
	v1.show();
	//测试指定位置删除
	v1.erase(3);
	v1.show();
	return 0;
}
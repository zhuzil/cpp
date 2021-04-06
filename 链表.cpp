/*
作者：竹子
时间：2021.4.3
目的：定义一个链表，可以逆序输出数据
*/
#include<iostream>
using namespace std;
//节点
template<typename T>
class Node
{
public:
	Node<T>* m_next = nullptr;
	T m_data;
	Node(T val):m_data(val){}
	~Node() {}
};
//链表
template<typename T>
class List
{
public:
	Node<T> *m_head = nullptr, * m_tail = nullptr;
	List() {}
	~List() { 
		Node<T>* p = nullptr;
		while(m_head!=nullptr)
		{
			p = m_head;
			m_head = m_head->m_next;
			delete p;
		}
	}
	//输入数据
	void push_back(const T &val)
	{
		Node<T>* node = new Node<T> (val);
		if(m_head==nullptr)
		{
			m_head = node;
			m_tail = node;
		} else
		{
			node->m_next = m_head;
			m_head = node;
		}
	}
	//逆向输出数据
	void show()
	{
		Node<T>* p = nullptr;
		//只能判断到最后一个，所以最后一个是没有输出的
		while (m_head != m_tail)
		{
			p = m_head;
			m_head = m_head->m_next;
			cout << p->m_data << " ";
		}
		//在这里另外输出一个最后的数据
		cout << m_tail->m_data;
	}
};

int main() 
{
	List<int> l;
	while(1)
	{
		int a = 0;
		cin >> a;
		if (a == -1) { break; }
		l.push_back(a);
	}
	l.show();
	return 0;
}
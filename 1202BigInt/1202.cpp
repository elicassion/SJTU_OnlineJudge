#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
class OutOfBound
{
public:
	OutOfBound() { cerr<<"Out of Bound"<<endl;}
	
};

class IllegalSize
{
public:
	IllegalSize() { cerr<<"Illegal Size"<<endl; }
};

template <class T>
class Node{
public:
	T _data;
	Node* _next;
	Node(const T &x, Node* next = NULL)
	{
		_data = x;
		_next = next;
	}
	Node():_next(NULL){}
	~Node(){}
};

template <class T>
class List
{
public:
	virtual void clear() = 0;
	virtual int length() const = 0;
	virtual void insert(int i, const T &x) = 0;
	virtual void remove(int i) = 0;
	virtual int search(const T &x) const = 0;
	virtual T visit(int i) const = 0;
	virtual void traverse() const =0;
	virtual ~List() {};
};

template <class T>
class LinkList:public List<T>
{
public:
	Node<T>* _head;
	LinkList();
	~LinkList();
	void clear();
	int length() const;
	void insert(int i, const T &x); //After insert the element will be at index i.
	void remove(int i);
	int search(const T &x) const;
	T visit(int i) const;//if failed return -1
	void traverse() const;
	void traverseToArray(T* array) const;
};

template <class T>
LinkList<T>::LinkList()
{
	_head = new Node<T>();
	if (!_head) throw IllegalSize();
}

template <class T>
LinkList<T>::~LinkList()
{
	clear();
	delete _head;
}

template <class T>
void LinkList<T>::clear()
{
	Node<T>* tmp = _head->_next;
	Node<T>* q;
	while (tmp)
	{
		q = tmp->_next;
		delete tmp;
		tmp = q;
	}
}

template <class T>
int LinkList<T>::length() const
{
	Node<T>* tmp = _head;
	int l = 0;
	while ((tmp = tmp->_next))
		++l;
	return l;
}

template <class T>
void LinkList<T>::insert(int i, const T &x)
{
	if (i < 0) throw OutOfBound();
	Node<T>* tmp = _head;
	int index = -1;
	while (tmp)
	{
		if (++index == i) break;
		else
		{
			tmp = tmp->_next;
		}
	}
	if (!tmp) throw OutOfBound();
	Node<T>* ins_node = new Node<T>(x);
	if (!ins_node) throw IllegalSize();
	Node<T>* q = tmp->_next;
	tmp->_next = ins_node;
	ins_node->_next = q;
}

template <class T>
void LinkList<T>::remove(int i)
{
	if (i < 0) throw OutOfBound();
	Node<T>* tmp = _head;
	int index = -1;
	while (tmp)
	{
		if (++index == i) break;
		else tmp = tmp->_next;
	}
	if (!tmp || !tmp->_next) throw OutOfBound();
	Node<T>* del_node = tmp->_next;
	tmp->_next = del_node->_next;
	delete del_node;
}

template <class T>
int LinkList<T>::search(const T &x) const
{
	Node<T>* tmp = _head;
	int l = 0;
	while ((tmp = tmp->_next))
	{
		if (tmp->_data == x)
			return l;
		else ++l;
	}
	return -1;
}

template <class T>
T LinkList<T>::visit(int i) const
{
	if (i < 0) throw OutOfBound();
	Node<T>* tmp = _head;
	int index = 0;
	while ((tmp = tmp->_next))
	{
		if (index == i)
			return tmp->_data;
		else ++index;
	}
	throw OutOfBound();
}

template <class T>
void LinkList<T>::traverse() const
{
	Node<T>* tmp = _head;
	while ((tmp = tmp->_next))
		cout<<tmp->_data;
}

template<class T>
void LinkList<T>::traverseToArray(T* array) const
{
	Node<T>* tmp = _head;
	int l = 0;
	while ((tmp = tmp->_next))
	{
		array[l++] = tmp->_data;
	}

}

char a_str[100010], b_str[100010];
int res[100010] = {0};
int main()
{
	LinkList<int> a, b, c;
	scanf("%s", a_str);
	getchar();
	scanf("%s", b_str);
	//cout<<a_str<<' '<<b_str<<endl;
	int a_l = strlen(a_str);
	int b_l = strlen(b_str);
	//cout<<a_l<<' '<<b_l<<endl;
	
	if (a_l < b_l)
	{
		for (int i = a_l; i < b_l; ++i)
			a.insert(0, 0);
	}
	else if (a_l > b_l)
	{
		for (int i = b_l; i < a_l; ++i)
			b.insert(0, 0);
	}

	// a.traverse();
	// cout<<endl;
	// b.traverse();

	for (int i = 0; i <= a_l - 1; ++i)
		a.insert(0, (int)(a_str[i] - '0'));
	//a.insert(a_l, 0);
	for (int i = 0; i <= b_l - 1; ++i)
		b.insert(0, (int)(b_str[i] - '0'));
	//b.insert(b_l, 0);
	//++a_l, ++b_l;
	
	

	// a.traverse();
	// cout<<endl;
	// b.traverse();
	// cout<<endl;

	int g = 0;
	Node<int> *ptra = a._head->_next, *ptrb = b._head->_next;
	for (int i = 0; i < max(a_l, b_l); ++i)
	{
		int tmpsum = ptra->_data + ptrb->_data + g;
		ptra = ptra->_next;
		ptrb = ptrb->_next;
		c.insert(0, tmpsum % 10);
		g = tmpsum / 10;
	}
	if (g > 0)
		c.insert(0, g);
	c.traverse();
	cout<<endl;
	return 0;
}
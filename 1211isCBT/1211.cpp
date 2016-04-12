#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
//#include "binarytree.cpp"
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

template <class elemType>
class Node{
public:
	elemType _data;
	Node* _next;
	Node(const elemType	&x, Node* next = NULL)
	{
		_data = x;
		_next = next;
	}
	Node():_next(NULL){}
	~Node(){}
};

template <class elemType>
class Queue
{
public:
	virtual bool isEmpty() const = 0;
	virtual void push(const elemType &x) = 0;
	virtual elemType pop() = 0;
	virtual elemType head() const = 0;
	virtual ~Queue(){};
};

template <class elemType>
class LinkQueue:public Queue<elemType>
{
private:
	Node<elemType> *_head, *_tail;
public:
	LinkQueue();
	~LinkQueue();
	bool isEmpty() const;
	void push(const elemType &x);
	elemType pop();
	elemType head() const;
};

template <class elemType>
LinkQueue<elemType>::LinkQueue()
{
	_head = _tail = NULL;
}

template <class elemType>
LinkQueue<elemType>::~LinkQueue()
{
	Node<elemType>* tmp;
	while (_head)
	{
		tmp = _head;
		_head = _head->_next;
		delete tmp;
	}
	
}

template <class elemType>
bool LinkQueue<elemType>::isEmpty() const
{
	return (_head == NULL);
}

template <class elemType>
void LinkQueue<elemType>::push(const elemType &x)
{
	try
	{
		if (_tail == NULL) _head = _tail = new Node<elemType>(x);
		else
		{
			_tail->_next = new Node<elemType>(x);
			_tail = _tail->_next;
		}
	}
	catch(...) 
	{
		
	}
	
}

template <class elemType>
elemType LinkQueue<elemType>::pop()
{
	if (isEmpty()) throw OutOfBound();
	Node<elemType>* tmp = _head;
	elemType v = _head->_data;
	_head = _head->_next;
	if (_head == NULL) _tail = NULL;
	delete tmp;
	return v;
}

template <class elemType>
elemType LinkQueue<elemType>::head() const
{
	if (isEmpty()) throw OutOfBound();
	return _head->_data;
}

template <class elemType>
class Stack
{
public:
	virtual bool isEmpty() const = 0;
	virtual void push(const elemType &x) = 0;
	virtual elemType pop() = 0;
	virtual elemType top() const = 0;
	virtual ~Stack(){}
};

template <class elemType>
class LinkStack:public Stack<elemType>
{
private:
	Node<elemType>* _top;
public:
	LinkStack();
	LinkStack(const LinkStack &s);
	~LinkStack();

	bool isEmpty() const;
	elemType pop();
	elemType top() const;
	void push(const elemType &x);
};

template <class elemType>
LinkStack<elemType>::LinkStack()
{
	_top = NULL;
}

template <class elemType>
LinkStack<elemType>::LinkStack(const LinkStack &s)
{
	_top = NULL;
	Node<elemType>* cur = s._top;
	while (cur)
	{
		Node<elemType>* p = new Node<elemType>;
		p->_data = cur->_data;
		p->_next = _top;
		_top = p;
		cur = cur._next;
	}
}

template <class elemType>
LinkStack<elemType>::~LinkStack()
{
	Node<elemType>* tmp;
	while (_top)
	{
		tmp = _top;
		_top = _top->_next;
		delete tmp;
	}
}

template <class elemType>
bool LinkStack<elemType>::isEmpty() const
{
	return (_top == NULL ? true : false);
}

template <class elemType>
elemType LinkStack<elemType>::pop()
{
	if (isEmpty()) throw OutOfBound();
	Node<elemType>* tmp = _top;
	elemType to_be_pop = _top->_data;
	_top = _top->_next;
	delete tmp;
	return to_be_pop;
}

template <class elemType>
elemType LinkStack<elemType>::top() const
{
	if (isEmpty()) throw OutOfBound();
	return _top->_data;
}

template <class elemType>
void LinkStack<elemType>::push(const elemType &x)
{
	Node<elemType>* p = new Node<elemType>;
	p->_data = x;
	p->_next = _top;
	_top = p;
}

template <class T>
class TreeNode
{
public:
	T _data;
	TreeNode *_left, *_right;
	TreeNode():_left(NULL), _right(NULL){}
	TreeNode(const T &x, TreeNode* L = NULL, TreeNode* R = NULL):
		_data(x), _left(L), _right(R){};
	~TreeNode(){}
};

template <class T>
class StNode
{
public:
	TreeNode<T>* _node;
	int _times_pop;
	StNode(TreeNode<T>* N = NULL):_node(N), _times_pop(0) {}
};

template <class T>
class BinaryTree
{
private:
	//TreeNode<T>* _root;
	void clear_(TreeNode<T>* rt);
	int height_(TreeNode<T>* rt) const;
	int size_(TreeNode<T>* rt) const;
	void preOrder_(TreeNode<T>* rt) const;
	void midOrder_(TreeNode<T>* rt) const;
	void postOrder_(TreeNode<T>* rt) const;
	void levelOrder_(TreeNode<T>* rt) const;
public:
	TreeNode<T>* _root;
	BinaryTree():_root(NULL){}
	BinaryTree(const T &x) {_root = new TreeNode<T>(x);}
	BinaryTree(const TreeNode<T>* p) {_root = p;}
	~BinaryTree() {clear();}
	T root() const;
	T left() const;
	T right() const;
	void makeTree(const T &x, BinaryTree &lt, BinaryTree &rt);
	void delLeft();
	void delRight();
	bool isEmpty() const;
	bool isCBT() const;
	void clear();
	int size() const;
	int height() const;
	void preOrder() const;
	void midOrder() const;
	void postOrder() const;
	void levelOrder() const;
	void createTree(T flag);
};

template <class T>
void BinaryTree<T>::clear_(TreeNode<T>* rt)
{

}

template <class T>
int BinaryTree<T>::height_(TreeNode<T>* rt) const
{
	if (rt == NULL) return 0;
	else
	{
		int lht = height_(rt->_left);
		int rht = height_(rt->_right);
		return 1 + ( (lht>rht) ? lht : rht);
	}
}

template <class T>
int BinaryTree<T>::size_(TreeNode<T>* rt) const
{
	if (rt == NULL) return 0;
	return 1 + size_(rt->_left) + size_(rt->_right);
}

template <class T>
void BinaryTree<T>::preOrder_(TreeNode<T>* rt) const
{
	LinkStack<TreeNode<T>*> s;
	TreeNode<T>* cur;
	s.push(rt);
	while (!s.isEmpty())
	{
		cur = s.pop();
		cout<<cur->_data<<' ';
		if (cur->_right) s.push(cur->_right);
		if (cur->_left) s.push(cur->_left);
	}
}

template <class T>
void BinaryTree<T>::midOrder_(TreeNode<T>* rt) const
{
	LinkStack<StNode<T> > s;
	StNode<T> cur(rt);
	s.push(cur);
	while (!s.isEmpty())
	{
		cur = s.pop();
		if (++cur._times_pop == 2)
		{
			cout<<cur._node->_data<<' ';
			if (cur._node->_right) s.push(StNode<T>(cur._node->_right));
		}
		else
		{
			s.push(cur);
			if (cur._node->_left) s.push(StNode<T>(cur._node->_left));
		}
	}
}

template <class T>
void BinaryTree<T>::postOrder_(TreeNode<T>* rt) const
{
	LinkStack<StNode<T> > s;
	StNode<T> cur(rt);
	s.push(cur);
	while (!s.isEmpty())
	{
		cur = s.pop();
		if (++cur._times_pop == 3) 
		{
			cout<<cur._node->_data<<' ';
			continue;
		}
		s.push(cur);
		if (cur._times_pop == 1)
		{
			if (cur._node->_left) 
				s.push(StNode<T>(cur._node->_left));
		}
		else
		{
			if (cur._node->_right)
				s.push(StNode<T>(cur._node->_right));
		}
	}
}

template <class T>
void BinaryTree<T>::levelOrder_(TreeNode<T>* rt) const
{
	LinkQueue<TreeNode<T>*> q;
	q.push(rt);
	while (!q.isEmpty())
	{
		TreeNode<T>* tmp = q.pop();
		if (tmp->_left) q.push(tmp->_left);
		if (tmp->_right) q.push(tmp->_right);
		cout<<tmp->_data<<' ';
	}
}

template <class T>
T BinaryTree<T>::root() const
{
	return _root->_data;
}

template <class T>
T BinaryTree<T>::left() const
{
	return _root->_left->_data;
}

template <class T>
T BinaryTree<T>::right() const
{
	return _root->_right->_data;
}

template <class T>
void BinaryTree<T>::makeTree(const T &x, BinaryTree &lt, BinaryTree &rt)
{
	_root = new TreeNode<T>(x, lt._root, rt._root);
	lt._root = rt._root = NULL;
}

template <class T>
void BinaryTree<T>::delLeft()
{
	BinaryTree<T> tmp = _root->_left;
	_root->_left = NULL;
	tmp.clear();
}

template <class T>
void BinaryTree<T>::delRight()
{
	BinaryTree<T> tmp = _root->_right;
	_root->_right = NULL;
	tmp.clear();
}

template <class T>
bool BinaryTree<T>::isEmpty() const
{
	return (_root == NULL);
}

template <class T>
bool BinaryTree<T>::isCBT() const
{
	LinkQueue<TreeNode<T>*> q;
	q.push(_root);
	TreeNode<T>* ptr;
	while ((ptr = q.pop()) != NULL)
	{
		q.push(ptr->_left);
		q.push(ptr->_right);
	}
	while (!q.isEmpty())
	{
		ptr = q.pop();
		if (ptr) return false;
	}
	return true;
}

template <class T>
void BinaryTree<T>::clear()
{
	if (!isEmpty()) clear_(_root);
	_root = NULL;
}

template <class T>
int BinaryTree<T>::size() const
{
	return size_(_root);
}

template <class T>
int BinaryTree<T>::height() const
{
	return height_(_root);
}

template <class T>
void BinaryTree<T>::preOrder() const
{
	preOrder_(_root);
}

template <class T>
void BinaryTree<T>::midOrder() const
{
	midOrder_(_root);
}

template <class T>
void BinaryTree<T>::postOrder() const
{
	postOrder_(_root);
}

template <class T>
void BinaryTree<T>::levelOrder() const
{
	levelOrder_(_root);
}

template <class T>
void BinaryTree<T>::createTree(T flag)
{
	LinkQueue<TreeNode<T>*> q;
	TreeNode<T>* tmp;
	T x, ldata, rdata;
	cin>>x;
	_root = new TreeNode<T>(x);
	q.push(_root);
	while(!q.isEmpty())
	{
		tmp = q.pop();
		cin>> ldata >> rdata;
		if (ldata != flag)
			q.push(tmp->_left = new TreeNode<T>(ldata));
		if (rdata != flag)
			q.push(tmp->_right = new TreeNode<T>(rdata));
	}
}

BinaryTree<int> p[100010];
int chd[100010][2] = {0};
bool vi[100010] = {0};
bool isin[100010] = {0};
int main()
{
	int N;
	cin>>N;
	for (int i = 1; i <= N; ++i)
	{
		cin>>chd[i][0]>>chd[i][1];
		vi[chd[i][0]] = vi[chd[i][1]] = true;
	}
	int root;
	for (int i = 1; i <= N; ++i)
		if (!vi[i])
		{
			root = i;
			break;
		}
	LinkStack<int> s;
	s.push(root);
	while (!s.isEmpty())
	{
		int tmp = s.top();
		if (chd[tmp][1] && !isin[chd[tmp][1]]) {s.push(chd[tmp][1]); isin[chd[tmp][1]] = true;}
		else if (chd[tmp][0] && !isin[chd[tmp][0]]) {s.push(chd[tmp][0]); isin[chd[tmp][0]] = true;}
		else
		{
			int tmmp = s.pop();
			p[tmmp].makeTree(tmmp, p[chd[tmmp][0]], p[chd[tmmp][1]]);
		}
	}

	cout<<(p[root].isCBT() ? 'Y' : 'N')<<endl;
	return 0;

}
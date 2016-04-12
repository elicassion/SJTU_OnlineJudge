#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
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
	void clear();
	int size() const;
	int height() const;
	void preOrder() const;
	void midOrder() const;
	void postOrder() const;
	void levelOrder() const;
	void createTree(T flag);
	template <class U>
	friend void buildTreeLRV(BinaryTree<U>* tree, int* lson, int* rson, U* value, const int N, const int rt);
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

template <class T>
void buildTreeLRV(BinaryTree<T>* tree, int* lson, int* rson, T* value, const int N, const int rt)
{
	//BinaryTree<T>* tree = new BinaryTree<T> [N];
	bool* isin = new bool [N];
	for (int i = 0; i <= N; ++i)
		isin[i]= false;
	isin[0] = true;
	LinkStack<int> s;
	s.push(rt);
	while (!s.isEmpty())
	{
		int tmp = s.top();
		if (rson[tmp] && !isin[rson[tmp]]) {s.push(rson[tmp]); isin[rson[tmp]] = true;}
		else if (lson[tmp] && !isin[lson[tmp]]) {s.push(lson[tmp]); isin[lson[tmp]] = true;}
		else
		{
			int tmmp = s.pop();
			tree[tmmp].makeTree(value[tmmp], tree[lson[tmmp]], tree[rson[tmmp]]);
		}
	}
}

BinaryTree<int> t1[100010];
BinaryTree<int> t2[100010];
bool vi[100010] = {0};
bool isin[10010] = {0};
int lson[100010] = {0};
int rson[100010] = {0};
int value[100010] = {0};
int main()
{
	int N, M;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d %d %d", &lson[i], &rson[i], &value[i]);
		vi[lson[i]] = vi[rson[i]] = true;
	}
	int root1;
	for (int i = 1; i <= N; ++i)
		if (!vi[i])
		{
			root1 = i;
			break;
		}
	LinkStack<int> s1s;
	s1s.push(root1);
	while (!s1s.isEmpty())
	{
		int tmp = s1s.top();
		if (rson[tmp] && !isin[rson[tmp]]) {s1s.push(rson[tmp]); isin[rson[tmp]] = true;}
		else if (lson[tmp] && !isin[lson[tmp]]) {s1s.push(lson[tmp]); isin[lson[tmp]] = true;}
		else
		{
			int tmmp = s1s.pop();
			t1[tmmp].makeTree(value[tmmp], t1[lson[tmmp]], t1[rson[tmmp]]);
		}
	}
	//buildTreeLRV(t1, lson, rson, value, N, root1);

	memset(vi, 0, sizeof(vi));
	memset(lson, 0, sizeof(lson));
	memset(rson, 0, sizeof(rson));
	memset(value, 0, sizeof(value));
	memset(isin, 0, sizeof(isin));

	scanf("%d", &M);
	for (int i = 1; i <= M; ++i)
	{
		scanf("%d %d %d", &lson[i], &rson[i], &value[i]);
		vi[lson[i]] = vi[rson[i]] = true;
	}
	int root2;
	for (int i = 1; i <= M; ++i)
		if (!vi[i])
		{
			root2 = i;
			break;
		}
	LinkStack<int> s2s;
	s2s.push(root2);
	while (!s2s.isEmpty())
	{
		int tmp = s2s.top();
		if (rson[tmp] && !isin[rson[tmp]]) {s2s.push(rson[tmp]); isin[rson[tmp]] = true;}
		else if (lson[tmp] && !isin[lson[tmp]]) {s2s.push(lson[tmp]); isin[lson[tmp]] = true;}
		else
		{
			int tmmp = s2s.pop();
			t2[tmmp].makeTree(value[tmmp], t2[lson[tmmp]], t2[rson[tmmp]]);
		}
	}
	//buildTreeLRV(t2, lson, rson, value, M, root2);

	//nodecheck
	if (N != M)
	{
		printf("N\n");
		return 0;
	}

	//preorder check
	LinkStack<TreeNode<int>*> s1, s2;
	TreeNode<int> *cur1 = t1[root1]._root, *cur2 = t2[root2]._root;
	s1.push(cur1);
	s2.push(cur2);
	if (cur1->_data != cur2->_data)
	{
		printf("N\n");
		return 0;
	}
	while (!s1.isEmpty() && !s2.isEmpty())
	{
		cur1 = s1.pop();
		cur2 = s2.pop();
		if (cur1->_data != cur2->_data)
		{
			printf("N\n");
			return 0;
		}
		bool r1, l1, r2, l2;
		r1 = l1 = r2 = l2 = true;
		if (cur1->_right) s1.push(cur1->_right);
		else r1 = false;
		if (cur1->_left) s1.push(cur1->_left);
		else l1 = false;
		if (cur2->_right) s2.push(cur2->_right);
		else r2 = false;
		if (cur2->_left) s2.push(cur2->_left);
		else l2 = false;
		if (r1 != r2 || l1 != l2)
		{
			printf("N\n");
			return 0;
		}
	}

	//midordercheck
	LinkStack<StNode<int> > st1, st2;
	StNode<int> curt1(t1[root1]._root);
	StNode<int> curt2(t2[root2]._root);
	st1.push(curt1);
	st2.push(curt2);
	if (curt1._node->_data != curt2._node->_data)
	{
		printf("N\n");
		return 0;
	}
	while (!st1.isEmpty() && !st2.isEmpty())
	{
		curt1 = st1.pop();
		curt2 = st2.pop();
		if (curt1._node->_data != curt2._node->_data)
		{
			printf("N\n");
			return 0;
		}
		bool r1, l1, r2, l2;
		r1 = l1 = r2 = l2 = true;
		if (++curt1._times_pop == 2)
		{
			//cout<<curt1._node->_data<<' ';
			if (curt1._node->_right) st1.push(StNode<int>(curt1._node->_right));
			else r1 = false;
		}
		else
		{
			st1.push(curt1);
			if (curt1._node->_left) st1.push(StNode<int>(curt1._node->_left));
			else l1 = false;
		}

		if (++curt2._times_pop == 2)
		{
			//cout<<curt2._node->_data<<' ';
			if (curt2._node->_right) st2.push(StNode<int>(curt2._node->_right));
			else r2 = false;
		}
		else
		{
			st2.push(curt2);
			if (curt2._node->_left) st2.push(StNode<int>(curt2._node->_left));
			else l2 = false;
		}
		if (r1 != r2 || l1 != l2)
		{
			printf("N\n");
			return 0;
		}
	}

	printf("Y\n");
	return 0;
}
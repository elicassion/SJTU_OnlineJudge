#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;
template <class elemType>
class List
{
public:
	virtual void clear() = 0;
	virtual int length() const = 0;
	virtual void insert(int i, const elemType &x) = 0;
	virtual void remove(int i) = 0;
	virtual int search(const elemType &x) const = 0;
	virtual elemType visit(int i) const = 0;
	virtual void traverse() const =0;
	virtual ~List() {};
};
class OutOfBound
{
public:
    OutOfBound()
    {
        cerr<<"Index Out of Bound"<<endl;
        //exit(1);
    }
};

class IllegalSize
{
public:
    IllegalSize()
    {
        cerr<<"Illegal Size"<<endl;
        //exit(1);
    }
};

template <class elemType>
class SeqList: public List<elemType>
{
private:
	elemType* data;
	int cur_length;
	int max_size;
	void doubleSpace();
public:
	SeqList(int init_size = 10);
	SeqList(const SeqList &l);
	~SeqList();
	void clear();
	int length() const;
	void insert(int i, const elemType &x);
	void remove(int i);
	int search(const elemType &x) const;
	elemType visit(int i) const;
	void traverse() const;

	template <class T>
	friend SeqList<T> operator+ (const SeqList<T> &sl1, const SeqList<T> &sl2);
};

template <class elemType>
void SeqList<elemType>::doubleSpace()
{
	elemType* tmp = new elemType [max_size * 2];
	if (!tmp)
		throw IllegalSize();
	for (int i = 0; i < cur_length; ++i)
		tmp[i] = data[i];
	max_size = max_size * 2;
	delete [] data;
	data = tmp;
}

template <class elemType>
SeqList<elemType>::SeqList(int init_size)
{
	if (init_size <= 0)
		throw IllegalSize();
	data = new elemType [init_size];
	if (!data)
		throw IllegalSize();
	max_size = init_size;
	cur_length = 0;
}

template <class elemType>
SeqList<elemType>::SeqList(const SeqList &l)
{
    elemType* tmp = new elemType [l.max_size];
    for (int i = 0; i < l.cur_length; ++i)
        tmp[i] = l.data[i];
    data = tmp;
    cur_length = l.cur_length;
    max_size = l.max_size;
}

template <class elemType>
SeqList<elemType>::~SeqList()
{
	delete [] data;
}

template <class elemType>
void SeqList<elemType>::clear()
{
	cur_length = 0;
}

template <class elemType>
int SeqList<elemType>::length() const
{
	return cur_length;
}

template <class elemType>
void SeqList<elemType>::insert(int i, const elemType &x)
{
	if (i > cur_length || i > max_size || i < 0)
		throw OutOfBound();
	if (cur_length == max_size)
		doubleSpace();
	for (int j = cur_length; j >= i + 1; --j)
		data[j] = data[j-1];
	data[i] = x;
	++cur_length;
}

template <class elemType>
void SeqList<elemType>::remove(int i)
{
	if (i >= cur_length || i < 0)
		throw OutOfBound();
	for (int j = i; j <= cur_length - 2; ++j)
		data[j] = data[j+1];
	--cur_length;
}

template <class elemType>
int SeqList<elemType>::search(const elemType &x) const
{
	for (int i = 0; i < cur_length; ++i)
		if (data[i] == x)
			return i;
	return -1;
}

template <class elemType>
elemType SeqList<elemType>::visit(int i) const
{
	if (i < 0 || i >= cur_length)
		throw OutOfBound();
	return data[i];
}

template <class elemType>
void SeqList<elemType>::traverse() const
{
	for (int i = 0; i < cur_length; ++i)
		cout<<data[i]<<' ';
	cout<<endl;
}

template <class elemType>
SeqList<elemType> operator+ (const SeqList<elemType> &sl1, const SeqList<elemType> &sl2)
{
    int length1 = sl1.length();
    int length2 = sl2.length();
    int res_length = length1 + length2;
    SeqList<elemType> res(res_length);
    for (int i = 0; i < length1; ++i)
        res.insert(i, sl1.visit(i));
    for (int i = 0; i < length2; ++i)
        res.insert(i + length1, sl2.visit(i));
    return res;
}



int main()
{
	string type;
	cin >> type;
    int l1, l2;
    cin>>l1>>l2;
    if (type == "int")
    {
        SeqList<int> a(l1);
        SeqList<int> b(l2);
        int x;
        for (int i = 0; i < l1; ++i)
        {
            cin>>x;
            a.insert(i, x);
            //cout<<"fuck"<<endl;
            //a.traverse();
        }
        for (int i = 0; i < l2; ++i)
        {
            cin>>x;
            b.insert(i, x);
            //cout<<"fuck"<<endl;
            //b.traverse();
        }
        SeqList<int> c = a + b;
        c.traverse();
    }
    else if (type == "char")
    {
        SeqList<char> a(l1);
        SeqList<char> b(l2);
        cin.get();
        for (int i = 0; i < l1; ++i)
        {
            char x;
            cin.get(x);
            a.insert(i, x);
            cin.get();
        }
        for (int i = 0; i < l2; ++i)
        {
            char x;
            cin.get(x);
            b.insert(i, x);
            cin.get();
        }
        SeqList<char> c = a + b;
        c.traverse();
    }
    else if (type == "double")
    {
        SeqList<double> a(l1);
        SeqList<double> b(l2);
        double x;
        for (int i = 0; i < l1; ++i)
        {
            cin>>x;
            a.insert(i, x);
        }
        for (int i = 0; i < l2; ++i)
        {
            cin>>x;
            b.insert(i, x);
        }
        SeqList<double> c = a + b;
        c.traverse();
    }

	return 0;
}

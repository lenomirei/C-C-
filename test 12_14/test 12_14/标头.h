#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
typedef int DataType;



class ListNode
{
public:
	ListNode(DataType x)
		:_data(x)
		, _next(NULL)
		, _prev(NULL)
	{
	}
public:
	DataType _data;
	ListNode *_next;
	ListNode *_prev;
};

class List
{
public:
	List()
		:_head(NULL)
		, _tail(NULL)
	{

	}
	~List()
	{
		ListNode *begin = _head;
		while (_head)
		{
			begin = _head;
			_head = _head->_next;
			delete	begin;
		}
		_head = _tail = NULL;
	}
	List(const List& l)
		:_head(new ListNode(l._head->_data))
		,_tail(_head)
	{
		ListNode *begin = l._head->_next;
		while (begin)
		{
			ListNode *tmp = new ListNode(begin->_data);
			tmp->_prev = _tail;
			_tail->_next = tmp;
			_tail = tmp;
			begin = begin->_next;
		}
	}
	List & operator=(const List& l)
	{
		if (this != &l)
		{
			Clear();
			_head = new ListNode(l._head->_data);
			_tail = _head;
			ListNode *begin = _head->_next;
			while (begin)
			{
				ListNode *tmp = new ListNode(begin->_data);
				tmp->_prev = _tail;
				_tail->_next = tmp;
				_tail = tmp;
				begin = begin->_next;
			}
		}
		return *this;
	}
	void Clear()
	{
		ListNode *begin = _head;
		while (_head)
		{
			begin = _head;
			_head = _head->_next;
			delete begin;
		}
		_head = _tail = NULL;
	}
	void PushBack(DataType x)
	{
		if (_head == NULL)
		{
			_head = new ListNode(x);
			_tail = _head;
		}
		else
		{
			ListNode *tmp = new ListNode(x);
			_tail->_next = tmp;
			tmp->_prev = _tail;
			_tail = tmp;
		}
	}
	void Print()
	{
		ListNode *begin = _head;
		while (begin)
		{
			cout << begin->_data << "->" << endl;
			begin = begin->_next;
		}
	}
	void PopBack()//1.û��ֵ2.ֻ��һ��ֵ3.��1�����ϵ�ֵ
	{
		if (_head == NULL)
		{
			return ;
		}
		else if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
		}
		else
		{
			_tail = _tail->_prev;
			delete _tail->_next;
			_tail->_next = NULL;
		}
	}
	void Insert(ListNode* pos, const DataType x)//ע����дInsert��ʱ����Ϊ����һ��˫���������Բ�������һ��ָ��
	{
		assert(pos);//���в����ж�
		assert(_head);//�Ҿ���Ӧ�ý��������пգ���Ϊ�շǷ�
		ListNode *next = pos->_next;
		ListNode *tmp = new ListNode(x);

		if (pos == _tail)
		{
			_tail->_next = tmp;
			tmp->_prev = _tail;
			_tail = tmp;

		}
		else
		{
			pos->_next = tmp;//һ��Ҫ���ָ��ĸ���
			next->_prev = tmp;//��4������
			tmp->_prev = pos;
			tmp->_prev = pos;
		}
	}
	void Erase(ListNode* pos)//��ֻ��һ��Ԫ�ص�ʱ�򣬻��������������Ҫ���ǵ�����ܶ�
	{
		assert(pos);
		ListNode *behind = pos->_next;
		ListNode *prev = pos->_prev;
		if (_head == _tail)
		{
			assert(_head == pos);//�������ȣ���ô��Ϊ��������ֵ������
			delete pos;
			_head = _tail = NULL;
			return;
		}
		if (pos->_prev == _head)
		{
			_head = behind;
			behind->_prev = NULL;
			delete pos;
		}
		else if (pos->_next == _tail)
		{
			_tail = prev;
			prev->_next = NULL;
			delete pos;
		}
		else
		{
			prev->_next = behind;
			behind->_prev = prev;
			delete pos;
		}
	}
	void PushFront(const DataType& x)
	{
		ListNode *tmp = new ListNode(x);
		tmp->_next = _head;
		_head->_prev = tmp;
		_head = tmp;

	}
	void PopFront()//1.û��ֵ2.��һ��ֵ3.��һ�����ϵ�ֵ
	{
		if (_head == NULL)
		{
			return;
		}
		else if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
		}
		else
		{
			_head = _head->_next;
			delete _head->_prev;
			_head->_prev = NULL;
		}
	}
	ListNode* Find(const DataType x)//����Ĳ�������Ҫ
	{
		ListNode *cur = _head;
		while (cur)
		{
			if (cur->_data == x)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return NULL;
	}
	//void Reverse()
	//{
	//	assert(_head);

	//}//ԭ��������ժ���;

	//void Reverse()
	//{
	//	//assert(_head);//���ﲻӦ��ʹ�ö��ԣ�������������Ǻ������ģ�ֻ�ǲ��������ǵ�������Ӧ��ʹ��if
	//	if (_head == NULL)
	//	{
	//		return;
	//	}
	//	else
	//	{
	//		ListNode *left = _head;
	//		ListNode *right = _tail;
	//		while (!(left == right || right->_next == left))
	//		{
	//			swap(left->_data, right->_data);
	//			left = left->_next;
	//			right = right->_next;
	//		}
	//	}
	//}

	void Reverse()
	{
		if (_head == NULL)
		{
			return;
		}
		else
		{
			ListNode *left = _head;
			ListNode *right = _tail;
			while (!(left == right || right->_next == left))
			{
				
			}
		}
	}
private:
	ListNode *_head;
	ListNode *_tail;
};
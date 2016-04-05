#pragma once
#include<iostream>
#include<cassert>
using namespace std;


enum type
{
	HEAD,
	SUB,
	VALUE,
};


struct GeneralListNode
{
	type _type;
	GeneralListNode *_next;
	union
	{
		char _value;
		GeneralListNode *_SubLink;
	};
	GeneralListNode(type type)
	{
		_type = type;
		_next = NULL;
	}
	GeneralListNode(type type, char ch)
	{
		_type = type;
		_value = ch;
		_next = NULL;
	}
};



class GeneralList
{
public:
	GeneralList(char *s)
	{
		_head = _CreateGeneralList(s);
	}
	~GeneralList()
	{
		_Destory(_head);
	}
	GeneralList(GeneralList& b)
	{
		_head=_Copy(b._head);
	}

	GeneralList &operator=(GeneralList b)
	{
		swap(b._head, _head);
		return *this;
	}
	void PrintList()
	{
		_PrintList(_head);
		cout << endl;
	}
	int Depth()
	{
		return _Depth(_head);
	}
protected:
	bool IsValue(char ch)
	{
		if ((ch > '0' && ch < '9') || (ch<'z' && ch>'a') || (ch<'Z' && ch>'A'))
		{
			return true;
		}
		return false;
	}
	GeneralListNode * _CreateGeneralList(char *&s)
	{
		assert(*s == '(');
		GeneralListNode *head = new GeneralListNode(HEAD);
		GeneralListNode *cur = head;
		*s++;
		while (*s)
		{

			if (*s == '(')
			{
				cur->_next = new GeneralListNode(SUB);
				cur = cur->_next;
				cur->_SubLink = _CreateGeneralList(s);

			}
			else if (*s == ')')
			{
				s++;
				break;
			}
			else if (IsValue(*s))
			{
				cur->_next = new GeneralListNode(VALUE, *s);
				s++;
				cur = cur->_next;
			}
			else if (*s == ',')
			{
				s++;
			}
			else if (*s = ' ')
			{
				s++;
			}
		}
		return head;
	}
	void _PrintList(GeneralListNode *head)
	{
		GeneralListNode *cur = head;
		while (cur)
		{
			if (cur->_type == HEAD)
			{
				cout << "(";
			}
			else if (cur->_type == VALUE)
			{
				cout << cur->_value;
				if (cur->_next != NULL)
				{
					cout << ",";
				}
			}
			else
			{
				_PrintList(cur->_SubLink);
				if (cur->_next)
				{
					cout << ",";
				}
			}
			cur = cur->_next;
		}
		cout << ")";
	}
	int _Depth(GeneralListNode* head)
	{
		int depth = 1;
		GeneralListNode* cur = head;
		while (cur)
		{
			if (cur->_type == SUB)
			{
				int subDepth = _Depth(cur->_SubLink);
				if (depth < subDepth + 1)
				{
					depth = subDepth + 1;
				}
			}
			cur = cur->_next;
		}
		return depth;
	}
	GeneralListNode* _Copy(GeneralListNode *head)
	{
		GeneralListNode *newHead = NULL;
		GeneralListNode *cur = head;
		GeneralListNode *newcur = NULL;
		while (cur)
		{
			if (cur->_type == HEAD)
			{
				newHead = new GeneralListNode(HEAD);
				newcur = newHead;
			}
			else if (cur->_type == SUB)
			{
				newcur->_next = new GeneralListNode(SUB);
				newcur = newcur->_next;
				newcur->_SubLink = _Copy(cur->_SubLink);
			}
			else if (cur->_type == VALUE)
			{
				newcur->_next = new GeneralListNode(VALUE, cur->_value);
				newcur = newcur->_next;
			}
			cur = cur->_next;
		}
		return newHead;
	}
	void _Destory(GeneralListNode* head)
	{
		GeneralListNode *cur = head;
		GeneralListNode *del = NULL;
		while (cur)
		{
			del = cur;
			cur = cur->_next;
			if (del->_type == HEAD)
			{
				delete del;
			}
			else if (del->_type == VALUE)
			{
				delete del;
			}
			else
			{
				_Destory(del->_SubLink);
			}
		}
	}

protected:
	GeneralListNode *_head;
};
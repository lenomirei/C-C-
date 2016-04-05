#pragma once

enum PointerTag {THREAD, LINK};

template <class T>
struct BinaryTreeNodeThd
{
	T _data ;                         // ����
	BinaryTreeNodeThd<T >* _left;	  // ����
	BinaryTreeNodeThd<T >* _right;    // �Һ���
	PointerTag   _leftTag ;          // ����������־
	PointerTag   _rightTag ;         // �Һ���������־

	BinaryTreeNodeThd(const T& data)
		:_data(data)
		,_left(NULL)
		,_right(NULL)
		,_leftTag(LINK)
		,_rightTag(LINK)
	{}
};


template<class T>
class BinaryTreeThd
{
public:
	BinaryTreeThd(const T* array, size_t size)
	{
		size_t index = 0;
		_root = _CreateTree(array, size, index);
	}

	~BinaryTreeThd()
	{}

	void InOrderThreading()
	{
		BinaryTreeNodeThd<T>* prev = NULL;
		_InOrderThreading(_root, prev);
	}

	void InOderThd()
	{
		BinaryTreeNodeThd<T>* cur = _root;
		while (cur)
		{
			// ������ڵ�
			while(cur && cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}

			cout<<cur->_data<<" ";
	
			// ���������ĺ�̽ڵ�
			while(cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout<<cur->_data<<" ";
			}

			// ��������������
			cur = cur->_right;
		}

		cout<<endl;
	}

	void PrevOrderThd()
	{
		BinaryTreeNodeThd<T>* cur = _root;
		while (cur)
		{
			while (cur && cur->_leftTag == LINK)
			{
				cout<<cur->_data<<" ";
				cur = cur->_left;
			}
			cout<<cur->_data<<" ";

			cur = cur->_right;

		/*	while(cur && cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout<<cur->_data<<" ";
			}

			if(cur->_leftTag == LINK)
				cur = cur->_left;
			else
				cur = cur->_right;*/
		}

		cout<<endl;
	}

	void PrevOrderThreading()
	{
		BinaryTreeNodeThd<T>* prev = NULL;
		_PrevOrderThreading(_root, prev);
	}

	void PostOrderThreading()
	{
		BinaryTreeNodeThd<T>* prev = NULL;
		_PostOrderThreading(_root, prev);
	}

protected:
	void _PrevOrderThreading(BinaryTreeNodeThd<T>* cur
		,BinaryTreeNodeThd<T>*& prev)
	{
		if (cur == NULL)
			return;

		if (cur->_left == NULL)
		{
			cur->_left = prev;
			cur->_leftTag = THREAD;
		}

		if (prev && prev->_right == NULL)
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}

		prev = cur;

		if (cur->_leftTag == LINK)
			_PrevOrderThreading(cur->_left, prev);
		
		if (cur->_rightTag == LINK)
			_PrevOrderThreading(cur->_right, prev);		
	}

	void _InOrderThreading(BinaryTreeNodeThd<T>* cur
		,BinaryTreeNodeThd<T>*& prev)
	{
		if (cur == NULL)
			return;

		_InOrderThreading(cur->_left, prev);

		// �����Ϊ�գ������������
		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}

		// �����Ϊ�գ������������
		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		
		prev = cur;

		_InOrderThreading(cur->_right, prev);
	}

	void _PostOrderThreading(BinaryTreeNodeThd<T>* cur,
		BinaryTreeNodeThd<T>* prev)
	{
		if (cur == NULL)
		{
			return;
		}

		_PostOrderThreading(cur->_left, prev);
		_PostOrderThreading(cur->_right, prev);

		if(cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}

		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}

		prev = cur;
	}

	BinaryTreeNodeThd<T>* _CreateTree(const T* array,
		size_t size, size_t& index)
	{
		BinaryTreeNodeThd<T>* root = NULL;
		if (index < size && array[index] != '#')
		{
			root = new BinaryTreeNodeThd<T>(array[index]);
			root->_left = _CreateTree(array, size, ++index);
			root->_right = _CreateTree(array, size, ++index);
		}

		return root;
	}

protected:
	BinaryTreeNodeThd<T>* _root;
};

void Test1()
{
	int a[10] = {1, 2, 3, '#', '#', 4, '#' , '#', 5, 6};
	BinaryTreeThd<int> t1(a, 10);
	t1.InOrderThreading();
	t1.InOderThd();

	BinaryTreeThd<int> t2(a, 10);
	t2.PrevOrderThreading();
	t2.PrevOrderThd();

	int a1[15] = {1,2,'#',3,'#','#',4,5,'#',6,'#',7,'#','#',8};
	BinaryTreeThd<int> t3(a1, 15);
	t3.PrevOrderThreading();
	t3.PrevOrderThd();

	//BinaryTreeThd<int> t3(a, 10);
	//t3.PostOrderThreading();
}
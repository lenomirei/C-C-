#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int _PrimeSize = 28;
static const unsigned long _GetPrime(size_t size)
{
	static const unsigned long _PrimeList[_PrimeSize] =
	{
		53ul,         97ul,         193ul,       389ul,       769ul,
		1543ul,       3079ul,       6151ul,      12289ul,     24593ul,
		49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
		1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
		50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};
	if (size == 0)
	{
		return _PrimeList[0];
	}
	for (int i = 0; i < _PrimeSize; ++i)
	{
		if (size == _PrimeList[i])
		{
			return _PrimeList[i + 1];
		}
	}
}

template<class K,class V>
struct KeyValueNode
{
	K _key;
	V _value;
	KeyValueNode<K,V> *_next;
	KeyValueNode(const K& key, const V& value)
		:_key(key)
		,_value(value)
		,_next(NULL)
	{

	}
};


template<class K>
struct HashFuncer
{
	size_t operator()(const K& key,size_t capacity)
	{
		return key%capacity;
	}
};

template<>
struct HashFuncer<string>
{
	static size_t BKDRHash(const char *s)
	{
		unsigned int seed = 131;
		unsigned hash = 0;
		while (*s)
		{
			hash = hash*seed + (*s++);

		}
		return (hash & 0x7FFFFFFF);//八成是想取个正数
	}
	size_t operator()(const string &key, size_t _capacity)
	{
		return BKDRHash(key.c_str())%_capacity;
	}
};





template<class K,class V,class HashFun=HashFuncer<K>>
class HashTable
{
	typedef KeyValueNode<K,V> KVNode;
public:
	HashTable()
		:_size(0)
	{

	}
	HashTable(size_t size)
		:_size(0)
	{
		_tables.resize(size);
		
	}
	HashTable(HashTable<K,V> &h)
		:_size(h._size)
	{
		size_t capacity = h._tables.size();
		_tables.resize(capacity);
		for (int i = 0; i < capacity; ++i)
		{
			KVNode *cur = h._tables[i];
			while (cur)
			{
				KVNode *tmp = new KVNode(cur->_key, cur->_value);
				tmp->_next = _tables[i];
				_tables[i] = tmp;//没必要在乎顺序，反正是查询哈希表
				cur = cur->_next;
			}
		}
	}
	HashTable &operator=(HashTable<K,V> h)
	{
		if (this != &h)
		{
			_Destory();
			size_t capacity = h._tables.size();
			_tables.resize(capacity);
			for (int i = 0; i < capacity; ++i)
			{
				KVNode *cur = h._tables[i];
				if (cur == NULL)
				{
					_tables[i] = NULL;
				}
				while (cur)
				{
					KVNode *tmp = new KVNode(cur->_key, cur->_value);
					tmp->_next = _tables[i];
					_tables[i] = tmp;//没必要在乎顺序，反正是查询哈希表
					cur = cur->_next;
				}
			}
		}
		return *this;
	}
	~HashTable()
	{
		_Destory();
	}


	bool Insert(const K& key,const V& value)
	{
		_CheckCapacity();
		size_t index = HashFuner(key, _tables.size());
		KVNode *cur = _tables[index];
		if (cur == NULL)
		{
			_tables[index] = new KVNode(key, value);
		}
		else 
		{
			KVNode *tmp = new KVNode(key, value);
			tmp->_next=cur;
			_tables[index] = tmp;
		}
		_size++;
		return true;
	}
	bool Remove(const K& key)
	{
		int index = HashFuner(key);
		KVNode *cur = _tables[index];
		if (cur == NULL)
		{
			return false;
		}
		if (cur->_key == key)
		{
			_tables[index] = cur->_next;
			delete cur;
			return true;
		}
		else
		{
			KVNode *del = cur;
			cur = cur->_next;
			while (cur)
			{
				if (cur->_key == key)
				{
					del->_next = cur->_next;
					delete cur;
					return true;
				}
				cur = cur->_next;
			}
		}
		return false;
	}

	KVNode* Find(const K& key)
	{
		size_t index = HashFun(key);
		KVNode *cur = _tables[index];
		while (cur)
		{
			if (cur->_key == key)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return NULL;

	}

	size_t HashFuner(const K& key,size_t capacity)
	{
		return HashFun()(key, capacity);
	}
	void Print()
	{
		for (int i = 0; i < _tables.size(); ++i)
		{
			cout << "table[" << i << "]->";
			KVNode *cur = _tables[i];
			while (cur)
			{
				cout << cur->_value << ":" << cur->_value << "->";
				cur = cur->_next;
			}
			cout << endl;
		}
	}

protected:
	void _CheckCapacity()
	{
		
		if (_size==_tables.size())
		{
			HashTable<K,V> newhashtable;
			newhashtable._tables.resize(_GetPrime(_tables.size()));
			for (int i = 0; i < _tables.size(); ++i)
			{
				KVNode *cur = _tables[i];

				while (cur)
				{
					KVNode *tmp = cur;
					cur = cur->_next;
					size_t newindex = HashFuner(tmp->_key,_tables.size());
					tmp->_next = newhashtable._tables[newindex];
					newhashtable._tables[newindex] = tmp;
				}
				_tables[i] = NULL;
			}
			swap(*this, newhashtable);
		}
	}
	void _Destory()
	{
		for (int i = 0; i < _tables.size(); ++i)
		{
			KVNode *cur = _tables[i];
			while (cur)
			{
				KVNode *del = cur;
				cur = cur->_next;
				delete del;

			}
		}
	}
protected:
	vector<KVNode *> _tables;
	size_t _size;
};
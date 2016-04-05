#pragma once
#include<iostream>
using namespace std;


enum Status
{
	EXISTS,
	DELETE,
	EMPTY,
};
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
template<class K>
size_t Hashfun0(const K &key, int _capacity)
{

	return BKDRHash(key.c_str()) % _capacity;
}
template<class K>
size_t Hashfun2(const K & preHashNum, int i)
{
	return preHashNum + 2 * i - 1;
}


template<class K>
struct HashFuner
{
	size_t operator()(const K &key)
	{
		return key;
	}
};
template<>
struct HashFuner<string>
{
	size_t operator()(const string &key, int _capacity)
	{
		return Hashfun0(key, _capacity);
	}
};



template<class K,class V>
class KeyValueNode 
{


public:
	KeyValueNode()
	{

	}
	KeyValueNode(const K& key,const V& value)
		:_key(key)
		,_value(value)
	{
	}

	K _key;
	V _value;
};

template<class K, class V, class HashFun = HashFuner<K>>
class HashTable
{
public:
	typedef KeyValueNode<K, V> KVNode;
	HashTable()
		:_tables(NULL)
		, _size(0)
		, _capacity(0)
		, _status(NULL)
	{

	}

	HashTable(size_t capacity)
		:_tables(new KVNode[capacity])
		, _size(0)
		, _capacity(capacity)
		, _status(new Status[capacity])
	{
		for (int i = 0; i < _capacity; ++i)
		{
			_status[i] = EMPTY;
		}
	}
	~HashTable()
	{
		delete[] _tables;
		delete[] _status;
		_capacity = 0;
		_size = 0;
	}
	bool Insert(K key, V value)
	{
		if (_size * 10 / _capacity > 8)
		{
			HashTable<K, V, HashFun> *newtables = new HashTable<K, V, HashFun>(2 * _capacity);
			for (int i = 0; i < _capacity; ++i)
			{
				newtables->Insert(_tables[i]._key, _tables[i]._value);
			}
			Swap(*newtables);
		}
		int i = 1;
		int index = HashFun()(key, _capacity);
		while (_status[index] == EXISTS)
		{
			index = Hashfun2(index, i++);
			if (index >= _capacity)
			{
				index = index%_capacity;
			}
		}
		_tables[index] = KVNode(key, value);
		_status[index] = EXISTS;
		_size++;
		return true;
	}
	bool Remove()
	{
		int index = HashFun()(key, _capacity);
		int i = 1;
		while (_status[index] != EMPTY)
		{
			if (_array[index] == key)
			{
				if (_status[index] == DELETE)
				{
					return false;
				}
				_status[index] = DELETE;
				return true;
			}
			index = Hashfun2(index, i++);
			if (index >= _capacity)
			{
				index = index%_capacity;
			}
		}
		return false;
	}
	KVNode* Find(const K&key)
	{
		int index = Hashfuncer()(key, _capacity);
		while (_status[index] != EMPTY)
		{
			if (_array[index] == key)
			{
				if (_status[index] == DELETE)
				{
					return false;
				}
				return true;
			}
			index = Hashfun2(index, i++);
			if (index >= _capacity)
			{
				index = index%_capacity;
			}
		}
		return false;
	}
	void Swap(HashTable<K, V, HashFun> h)
	{
		swap(_tables, h._tables);
		swap(_size, h._size);
		swap(_capacity, h._capacity);
		swap(_status, h._status);
	}
protected:
	KVNode *_tables;
	size_t _size;
	size_t _capacity;
	Status *_status;
};
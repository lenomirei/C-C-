#pragma once
#include<iostream>
#include<string>
using namespace std;

//insert remove find  

enum Status
{
	EMPTY,
	EXISTS,
	DELETE,
};




template<class K>
struct HashFuner
{
	size_t operator()(const K &key,int _capacity)
	{
		return key%_capacity;
	}
};

template <>
struct HashFuner<string>
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
	size_t operator()(const string &key,int _capacity)
	{
		return BKDRHash(key.c_str())%_capacity;
	}
};



template<class K ,class Hashfuncer=HashFuner<K>>
class HashTable
{
public:
	HashTable()
		:_array(NULL)
		,_size(0)
		,_capacity(0)
		,_status(NULL)
	{

	}
	HashTable(size_t capacity)
		:_array(new K[capacity])
		, _size(0)
		, _capacity(capacity)
		, _status(new Status[capacity])
	{
		for (int i = 0; i < capacity; ++i)
		{
			_status[i] = EMPTY;
		}
	}
	~HashTable()
	{
		delete[] _array;
		delete[] _status;
	}


	bool Insert(K key)
	{
		if (_size * 10 / _capacity > 8)
		{
			HashTable<K,Hashfuncer> *newHash = new HashTable<K, Hashfuncer>(_capacity * 2);
			int i = 0;

			for (int i = 0; i < _capacity; ++i)
			{
				if (_status[i] != EMPTY)
				{
					newHash->Insert(_array[i]);
				}
			}
			Swap(*newHash);
		}
		int index = Hashfuncer()(key,_capacity);
		while (_status[index]==EXISTS)
		{
			index++;
			if (index == _capacity)
			{
				index = 0;
			}
		}
		_array[index] = key;
		_status[index] = EXISTS;
		_size++;
		return true;
	}
	bool Remove(K key)
	{
		int index = Hashfuncer()(key,_capacity);
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
			index++;
			if (index == _capacity)
			{
				index = 0;
			}
		}
		return false;
	}
	bool Find(K key)//注意！kvnode的时候根据字典的要求，应该返回一个节点值
	{
		int index = Hashfuncer()(key,_capacity);
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
			index++;
			if (index == _capacity)
			{
				index = 0;
			}
		}
		return false;
	}


	void Swap(HashTable<K, Hashfuncer> h)
	{
		swap(_array, h._array);
		swap(_size, h._size);
		swap(_capacity, h._capacity);
		swap(_status, h._status);
	}
	

protected:
	K* _array;
	size_t _size;
	size_t _capacity;
	Status *_status;
};
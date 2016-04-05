#pragma once
#include<iostream>
using namespace std;

template<class T>

class SeqList
{
public:
	
	SeqList()
		:_data(new T(NULL))
		, _capacity(0)
		, _size(0)
	{

	}
	~SeqList()
	{
		delete _data;
		_capacity = 0;
		_size = 0;
	}
	SeqList(T* x, size_t s);


	SeqList(SeqList &s)
		:_data(new T[s._capacity])
		,_capacity(s._capacity)
		,_size(s._size)
	{
		memcpy(_data, s._data, _size*sizeof(T));
	}
	void PuchBack(T x)
	{
		CheckCapacity(_size+1);
		_data[_size] = x;
		_size++;
	}


	void PrintList()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << _data[i] << endl;

		}
	}
	SeqList& operator=(SeqList& s)
	{
		if (_data != s._data)
		{
			delete _data;
			_data = new T[s._size];
			memcpy(_data, s._data, s._size);
			_capacity = s._capacity;
			_size = s._size;
		}
		return *this;
	}


private:
	void CheckCapacity(size_t size)
	{
		if (size >= _capacity)
		{
			//T*  temp = new T(2 * _capacity + 3);
			//memcpy(temp, _data, sizeof(T)*_size);
			//_capacity = 2 * _capacity + 3;
			size_t newcapacity = size > 2 * _capacity + 3 ? size : 2 * _capacity + 3;
			_data = (int *)realloc(_data, newcapacity*sizeof(T));
			_capacity = newcapacity;
		}
	}

private:
	T* _data;
	size_t _capacity;
	size_t  _size;

};
template<class T>
SeqList<T>::SeqList(T* x,size_t s)
	: _data(new T[size])
	,_size(s)
	,_capacity(s)
{
	
}
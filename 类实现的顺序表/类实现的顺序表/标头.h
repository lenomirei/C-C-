#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

typedef int DataType;
class SeqList
{
public:

	SeqList()
		:_array(new DataType[1])
		, _size(0)
		, _capacity(1)
	{

	}
	SeqList(DataType *array, size_t size)
		:_array(new DataType[size])
		,_size(size)
		,_capacity(size)
	{
		memcpy(_array, array, size*sizeof(DataType));
	}
	SeqList(const SeqList &s)
		:_array(new DataType[s._size])
		,_size(s._size)
		,_capacity(s._capacity)
	{
		memcpy(_array, s._array, _size*sizeof(DataType));
	}
	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_size = 0;
			_capacity = 0;

		}
	}
	void clear()
	{
		_size = 0;
	}
	DataType operator [](size_t index)
	{
		assert(_array);//可能采用无参数的构造函数，这时候array可能是NULL，需要进行判断
		assert(index < 0);
		return _array[index];
	}
	void Swap(SeqList &s)
	{
		swap(_array, s._array);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	SeqList& operator =(const SeqList &s)
	{
		if (this->_array != s._array)
		{
			SeqList tmp(s);
			Swap(tmp);
		}
		return *this;
	}
	void Reserve(size_t size)
	{
		CheckCapacity(size);
	}
	//void Reserve(size_t size)
	//{
	//	DataType *tmp = new DataType[size];
	//	_capacity = size;
	//	swap(tmp, _array);
	//	memcpy(_array, tmp, _size);
	//}
private:
	//void CheckCapacity()
	//{
	//	if (_size >= _capacity)
	//	{
	//		_array = (DataType *)realloc(_array, 2 * _capacity);
	//		_capacity *= 2;
	//	}
	//}

	void CheckCapacity(size_t size)
	{
		if (_size >= _capacity)
		{
			size_t newcapacity = _size > 2 * _capacity ? _size : 2 * _capacity;
			_array = (DataType *)realloc(_array, sizeof(DataType)*newcapacity);//采用新开辟一段空间然后利用memcopy也是可以的
			_capacity = newcapacity;
		}
	}
private:
	DataType *_array;
	size_t _capacity;
	size_t _size;
};



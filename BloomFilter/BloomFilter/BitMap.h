#include<iostream>
#include<vector>
using namespace std;


class BitMap
{

public:
	BitMap()
		:_size(0)
	{


	}
	BitMap(size_t size)
	{
		_map.resize((size >> 5) + 1);
	}
	~BitMap()
	{

	}
	void Resize(size_t size)
	{
		_map.resize(size);
	}
	bool Set(int num)
	{
		
		size_t index = (num >> 5);
		size_t n = num % 32;
		if (!(_map[index] & (1 << (num % 32))))
		{
			_map[index] = _map[index] | (1 << n);
			_size++;
			return true;
		}
		return false;
	}

	bool ReSet(int num)
	{
		size_t index = (num >> 5);
		size_t n = num % 32;
		if (_map[index] & (1 << (num % 32)))
		{
			_map[index] = _map[index] & (~(1 << n));
			_size--;
			return true;
		}
		return false;
	}
	bool Test(int num)
	{
		size_t index = (num >> 5);
		return _map[index] & (1 << (num % 32));
	}

protected:
	vector<size_t> _map;
	size_t _size;

};




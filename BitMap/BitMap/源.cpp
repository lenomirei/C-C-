#include<iostream>
#include<vector>
using namespace std;


class BitMap
{

public:
	BitMap()
	{

	}
	~BitMap()
	{

	}
	bool Set(int num)
	{
		_map.resize((num >> 5) + 1);
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





int main()
{
	BitMap bt;
	bt.Set(1);
	bt.Set(4);
	bt.Set(33);
	bt.Set(4);
	return 0;
}
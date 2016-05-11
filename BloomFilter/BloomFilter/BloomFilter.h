#pragma once
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
	//if (size == 0)
	//{
	//	return _PrimeList[0];
	//}
	for (int i = 0; i < _PrimeSize; ++i)
	{
		if (size < _PrimeList[i])
		{
			return _PrimeList[i + 1];
		}
	}
}
size_t BKDRHash(const char *str)
{
	register size_t hash = 0;
	while (size_t ch = (size_t)*str++)
	{
		hash = hash * 131 + ch;   
	}
	return hash;
}

size_t SDBMHash(const char *str)
{
	register size_t hash = 0;
	while (size_t ch = (size_t)*str++)
	{
		hash = 65599 * hash + ch;
		//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
	}
	return hash;
}

size_t RSHash(const char *str)
{
	register size_t hash = 0;
	size_t magic = 63689;
	while (size_t ch = (size_t)*str++)
	{
		hash = hash * magic + ch;
		magic *= 378551;
	}
	return hash;
}

size_t APHash(const char *str)
{
	register size_t hash = 0;
	size_t ch;
	for (long i = 0; ch = (size_t)*str++; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
		}
	}
	return hash;
}

size_t JSHash(const char *str)
{
	if (!*str)        // 这是由本人添加，以保证空字符串返回哈希值0  
		return 0;
	register size_t hash = 1315423911;
	while (size_t ch = (size_t)*str++)
	{
		hash ^= ((hash << 5) + ch + (hash >> 2));
	}
	return hash;
}



struct __HashFunc1
{
	int operator()(const string& key)
	{
		return BKDRHash(key.c_str());
	}
};

struct __HashFunc2
{
	int operator()(const string& key)
	{
		return JSHash(key.c_str());
	}
};

struct __HashFunc3
{
	int operator()(const string& key)
	{
		return APHash(key.c_str());
	}
};

struct __HashFunc4
{
	int operator()(const string& key)
	{
		return RSHash(key.c_str());
	}
};

struct __HashFunc5
{
	int operator()(const string& key)
	{
		return SDBMHash(key.c_str());
	}
};

template<class K = string,
class HashFunc1 = __HashFunc1,
class HashFunc2 = __HashFunc2,
class HashFunc3 = __HashFunc3,
class HashFunc4 = __HashFunc4,
class HashFunc5 = __HashFunc5>
class BloomFilter
{
public:
	BloomFilter(size_t size)
	{
		_bt.Resize(_GetPrime(size));
		_capacity = size;
	}
	void Set(const K& key)
	{
		int index1 = __HashFunc1()(key)%_capacity;
		//_bt.Resize(index1);
		int index2 = __HashFunc2()(key)%_capacity;
		//_bt.Resize(index2);
		int index3 = __HashFunc3()(key)%_capacity;
		//_bt.Resize(index3);
		int index4 = __HashFunc4()(key)%_capacity;
		//_bt.Resize(index4);
		int index5 = __HashFunc5()(key)%_capacity;
		//_bt.Resize(index5);
		_bt.Set(index1);
		_bt.Set(index2);
		_bt.Set(index3);
		_bt.Set(index4);
		_bt.Set(index5);
	}
	bool IsIn(const K& key)
	{
		int index1 = __HashFunc1()(key)%_capacity;
		int index2 = __HashFunc2()(key)%_capacity;
		int index3 = __HashFunc3()(key)%_capacity;
		int index4 = __HashFunc4()(key)%_capacity;
		int index5 = __HashFunc5()(key)%_capacity;
		_bt.Test(index1);
		if (!_bt.Test(index1))
		{
			return false;
		}
		_bt.Test(index2);
		if (!_bt.Test(index2))
		{
			return false;
		}
		_bt.Test(index3);
		if (!_bt.Test(index3))
		{
			return false;
		}
		_bt.Test(index4);
		if (!_bt.Test(index4))
		{
			return false;
		}
		_bt.Test(index5);
		if (!_bt.Test(index5))
		{
			return false;
		}
		return true;
	}
protected:
	BitMap _bt;
	size_t _capacity;
};




void TestBloomFilter()
{
	BloomFilter<> bf(10000);
	bf.Set("土豪金");
	bf.Set("土豪银");
	bf.Set("土豪铜");
	bf.Set("老司机");
	cout << bf.IsIn("土豪金") << endl;
	cout << bf.IsIn("土豪银") << endl;
	cout << bf.IsIn("土豪铜") << endl;
	cout << bf.IsIn("老司机") << endl;
	cout << bf.IsIn("sdfjiafhaiu") << endl;
	cout << bf.IsIn("土豪铁") << endl;
	cout << bf.IsIn("小司机") << endl;
}
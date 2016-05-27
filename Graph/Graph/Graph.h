#pragma once
#include<iostream>
using namespace std;


template<class V ,class W>
class Graph
{
public:
	Graph(V *vArry,size_t size)
		:_varr(new V[size])
		,_vsize(size)
	{
		for (int i = 0; i < _vsize; ++i)
		{
			_varr[i] = vArry[i];
		}
		_edges = new W*[size];
		for (int i = 0; i < size; ++i)
		{
			_edges[i] = new W[size];
			for (int j = 0; j < size; ++j)
			{
				_edges[i][j] = W();
			}
		}
	}
	void AddEdges(const V& src,const V& dst,const W& w)
	{
		int indexsrc, indexdst;
		for (int i = 0; i < _vsize; ++i)
		{
			if (_varr[i] == src)
			{
				indexsrc = i;
			}
			if (_varr[i] == dst)
			{
				indexdst = i;
			}
		}
		_edges[indexsrc][indexdst] = w;
		_edges[indexdst][indexsrc] = w;
	}

	void Display()
	{
		for (int i = 0; i < _vsize; ++i)
		{
			for (int j = 0; j < _vsize; ++j)
			{
				cout << _edges[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}
protected:
	V *_varr;
	size_t _vsize;
	W **_edges;
};


void testGraph()
{
	int a[] = { 1,2,3,4,5 };
	Graph<int, int> g(a,5);
	g.AddEdges(3, 5, 10);
	g.AddEdges(1, 1, 50);
	g.Display();
}
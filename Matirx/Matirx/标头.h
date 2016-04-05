#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class T>
class SymmetryMatrix
{
public:
	SymmetryMatrix(int *a,size_t n)
		:_array(new T[n*(n+1)/2])
		,_n(n)
	{
		int index = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i >= j)
				{
					_array[index++] = a[i*n + j];
				}
			}
		}
	}

	void Display()
	{
		for (int i = 0; i < _n; ++i)
		{
			for (int j = 0; j < _n; ++j)
			{
				if (i < j)
				{
					cout << _array[j*(j + 1) / 2 + i];
				}
				else
				{
					cout << _array[i*(i + 1) / 2 + j];
				}
			}
			cout << endl;
		}
		cout << endl;
	}
protected:
	T *_array;
	size_t _n;
};

template<class T>
struct Trituple
{
	size_t _row;
	size_t _col;
	T _value;
	Trituple(int row,int col,T value)
		:_row(row)
		,_col(col)
		,_value(value)
	{

	}
	Trituple()
	{

	}
};


template<class T>
class SparseMatrix
{
public:
	SparseMatrix()
	{

	}
	SparseMatrix(int *a, size_t rowSize, size_t colSize, T invalid)
		:_rowSize(rowSize)
		, _colSize(colSize)
		, _invalid(invalid)
	{
		for (int i = 0; i < rowSize; ++i)
		{
			for (int j = 0; j < colSize; ++j)
			{
				if (a[i*colSize + j] != invalid)
				{
					_array.push_back(Trituple<T>(i, j, a[i*colSize + j]));
				}
			}
		}
	}
	void Display()
	{
		int index = 0;
		for (int i = 0; i < _rowSize; ++i)
		{
			for (int j = 0; j < _colSize; ++j)
			{
				if (index < _array.size() &&
					_array[index]._row == i && _array[index]._col == j)
				{
					cout << _array[index]._value;
					index++;
				}
				else
				{
					cout << _invalid;
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	SparseMatrix<T> Transpose()
	{
		SparseMatrix<T> sm;
		sm._rowSize = _colSize;
		sm._colSize = _rowSize;
		sm._invalid = _invalid;
		for (int i = 0; i < _array.size(); ++i)
		{
			Trituple<T> tmp = _array[i];
			swap(tmp._col, tmp._row);
			sm._array.push_back(tmp);
		}
		for (int i = 0; i < _array.size(); ++i)
		{
			for (int j = 0; j < _array.size(); ++j)
			{
				if (sm._array[i]._row < sm._array[j]._row)
				{
					swap(sm._array[i], sm._array[j]);
				}
			}
		}
		return sm;
	}
	

	SparseMatrix<T> FastTranspose()
	{
		SparseMatrix<T> sm;
		sm._rowSize = _colSize;
		sm._colSize = _rowSize;
		sm._invalid = _invalid;
		sm._array.resize(_array.size());
		int *rowStart=new int[_colSize];
		int *rowCount=new int[_colSize];
		memset(rowStart, 0, sizeof(int)*_colSize);
		memset(rowCount, 0, sizeof(int)*_colSize);
		for (int i = 0; i < _array.size(); ++i)
		{
			rowCount[_array[i]._col]++;
		}
		rowStart[0] = 0;
		for (int i = 1; i < _array.size(); ++i)ee
		{
			rowStart[i] = rowStart[i - 1] + rowCount[i - 1];
		}
		for (int i = 0; i < _array.size(); ++i)
		{
			Trituple<T> tmp = _array[i];
			swap(tmp._col, tmp._row);
			sm._array[rowStart[_array[i]._col]]=tmp;
			rowStart[_array[i]._col]++;
		}
		return sm;
	}
private:
	vector<Trituple<T>> _array;
	size_t _rowSize;
	size_t _colSize;
	T _invalid;
};
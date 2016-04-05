#include<iostream>
#include<stack>
using namespace std;

struct Pos
{
	int row;
	int col;
	//Pos(int x,int y)
	//	:row(x)
	//	,col(y)
	//{

	//}
};

int * CreateMaze(int rowSize,int colSize)
{
	FILE *fp;
	int *a = new int[rowSize*colSize];
	fopen_s(&fp,"maze.txt", "r");
	for (int i = 0; i < rowSize; ++i)
	{
		for (int j = 0; j < colSize; )
		{
			char tmp = fgetc(fp);
			if (tmp == '1' || tmp == '0')
			{
				a[i*colSize + j] = tmp - '0';
				++j;
			}
		}
	}
	return a;
}

void PrintMaze(int *a, int rowSize, int colSize)
{
	for (int i = 0; i < rowSize; ++i)
	{
		for (int j = 0; j < colSize; ++j)
		{
			cout << a[i*colSize + j];
		}
		cout << endl;
	}
}

bool IsMazeAccess(int *a, int rowSize, int colSize, Pos cur)
{
	if (cur.col < colSize&&cur.row < rowSize&&cur.col >= 0 && cur.row >= 0 && a[cur.row*colSize + cur.col] == 0)
	{
		return true;
	}
	return false;
}



stack<Pos> GetMazePath(int *a, int rowSize, int colSize, Pos entry)
{
	stack<Pos> s;
	Pos cur;
	Pos next;
	s.push(entry);
	while (!s.empty())
	{
		cur = s.top();
		next = cur;
		if (next.row == rowSize - 1)
		{
			return s;
		}
		//ио
		next = cur;
		next.row--;

		if (IsMazeAccess(a, rowSize, colSize, next))
		{
			a[cur.row*colSize + cur.col] = 2;
			s.push(next);
			continue;
		}
		

		


		
		//об
		next = cur;
		next.row++;
		if (IsMazeAccess(a, rowSize, colSize, next))
		{
			a[cur.row*colSize + cur.col] = 2;
			s.push(next);
			continue;
		}
		
		//вС

		next = cur;
		next.col--;
		if (IsMazeAccess(a, rowSize, colSize, next))
		{
			a[cur.row*colSize + cur.col] = 2;
			s.push(next);
			continue;
		}

		//ср
		next = cur;
		next.col++;
		if (IsMazeAccess(a, rowSize, colSize, next))
		{
			a[cur.row*colSize + cur.col] = 2;
			s.push(next);
			continue;
		}
		next.col--;
		

		Pos top = s.top();
		a[top.row*colSize + top.col] = 3;
		s.pop();
	}
}



void TestMaze()
{
	int *a = CreateMaze(10, 10);
	PrintMaze(a, 10, 10);
	Pos entry;
	entry.row = 2;
	entry.col = 0;
	cout << endl;
	GetMazePath(a, 10, 10, entry);
	cout << endl;
	PrintMaze(a,10,10);
}

int main()
{
	TestMaze();
	return 0;
}
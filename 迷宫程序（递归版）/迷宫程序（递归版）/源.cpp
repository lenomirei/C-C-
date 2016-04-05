#include<iostream>
#include<stack>

using namespace std;


struct Pos
{
	int row;
	int col;
};


int *CreateMazeMap(int rowSize, int colSize)
{
	FILE *fp;
	fopen_s(&fp, "maze.txt", "r");
	int *a = new int[rowSize*colSize];
	for (int i = 0; i < rowSize; ++i)
	{
		for (int j = 0; j < colSize; )
		{
			char tmp = fgetc(fp);
			if ('0' == tmp || tmp == '1')
			{
				a[i*colSize + j] = tmp - '0';
				++j;
			}
		}
	}
	return a;
}

void PrintMazeMap(int *a, int rowSize, int colSize)
{
	for (int i = 0; i < rowSize; ++i)
	{
		for (int j = 0; j < colSize; ++j)
		{
			cout << a[i*rowSize + j];
		}
		cout << endl;
	}
}

bool IsPosAccess(int *a, int rowSize, int colSize, Pos *cur)
{
	Pos tmp = *cur;
	cur->col++;
	if (cur->col < colSize && cur->row < rowSize && cur->col >= 0 && cur->row >= 0 && a[cur->row*colSize + cur->col] == 0)
	{
		return true;
	}
	*cur = tmp;
	cur->row++;
	if (a[cur->row*colSize + cur->col] == 0)
	{
		return true;
	}
	*cur = tmp;
	cur->col--;
	if (a[cur->row*colSize + cur->col] == 0)
	{
		return true;
	}
	*cur = tmp;
	cur->row--;
	if (a[cur->row*colSize + cur->col] == 0)
	{
		return true;
	}
	return false;
}

stack<Pos> resultpath;
stack<Pos> minpath;
stack<Pos> path;
int mincount = 0;
void GetMazePath(int *a, int rowSize, int colSize, Pos pos)
{
	Pos cur;
	Pos next;
	//path.push(pos);
	cur = pos;
	if (path.empty())
	{
	
		cout << "no way" << endl;
	}
	else if (pos.row == rowSize - 1 || pos.col == colSize - 1)//退出条件不明确，需要进行更改
	{
		resultpath = path;
		return;
	}

	//上
	next = cur;

	for (int i = 0; i < 4; ++i)
	{
		if (IsPosAccess(a, rowSize, colSize, &next))
		{
			a[next.row*colSize + next.col] = 2;
			path.push(next);
			GetMazePath(a, rowSize, colSize, next);
		}
	}


	path.pop();

}



void GetMinMazePath(int *a, int rowSize, int colSize, Pos pos,int count)
{
	Pos cur;
	Pos next;
	//path.push(pos);
	cur = pos;
	if (path.empty())
	{
		cout << "no way" << endl;
	}
	else if (pos.row == rowSize - 1 || pos.col == colSize)//退出条件不明确，需要进行更改
	{
		minpath = path;
		mincount = count;
	}

	//上
	next = cur;

	for (int i = 0; i < 4; ++i)
	{
		if (IsPosAccess(a, rowSize, colSize, &next))
		{
			a[next.row*colSize + next.col] = 2;
			path.push(next);
			count++;
			GetMinMazePath(a, rowSize, colSize, next,count);
			
		}
	}


	path.pop();
	count--;
}





void TestMaze()
{
	int count = 1;
	int *a = CreateMazeMap(10, 10);
	PrintMazeMap(a, 10, 10);
	cout << endl;
	Pos entry;
	entry.row = 2;
	entry.col = 0;
	path.push(entry);
	GetMinMazePath(a, 10, 10, entry,count);
	cout << endl;
	PrintMazeMap(a, 10, 10);
}

//为什么要采用递归版本来进行迷宫路径呢，因为如果采用普通的if进行判断，有可能会将已经判断过的点在进行一次
//判断，这样就会影响计算的速度
int main()
{
	TestMaze();
	return 0;
}
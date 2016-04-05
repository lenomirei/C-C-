//这个程序的主要目的是，给定入栈顺序判断出栈顺序是否合法


#include"标头.h"

//假设入栈的字母是‘R’出栈的字母是‘C’

string Judge(int n_values, int input[], int output[])
{
	assert(input && output && n_values > 0);
	Stack<int, 100> s1;
	string result;
	s1.Push(input[0]);//为了防止数组越界访问造成崩溃，先将第一个数压栈开辟好数组空间
	result.append(1, 'R');//因为有入栈操作
	int out = 0;
	int in = 1;//因为有入栈操作，所以入栈数组计数加1
	while (out < n_values)//循环结束条件是完美的匹配了出栈顺序，出栈计数到达出栈数组末尾
	{
		if (in > n_values)//如果入栈计数先到达入栈数组末尾，证明没有数可以再入栈，但此时出栈数组还没走完，说明这个出栈顺序根本不可能完成
		{
			result = "这不可能！";
			return result;
		}
		if (s1.Top() == output[out]) 
		{
			s1.Pop();//当前栈顶元素恰好和出栈顺序的一样，赶紧出栈
			result.append(1, 'C');
			out++;
		}
		else
		{
			s1.Push(input[in]);//栈顶元素和出栈数组的当前指向不一致，只能继续入栈
			result.append(1, 'R');
			in++;
		}
	}
	return result;
}





int main()
{
	int input[5] = {1,2,3,4,5};
	int output[5] = {4,5,3,2,1};
	
	cout << Judge(5, input, output) << endl;
	
	return 0;
}




//����������ҪĿ���ǣ�������ջ˳���жϳ�ջ˳���Ƿ�Ϸ�


#include"��ͷ.h"

//������ջ����ĸ�ǡ�R����ջ����ĸ�ǡ�C��

string Judge(int n_values, int input[], int output[])
{
	assert(input && output && n_values > 0);
	Stack<int, 100> s1;
	string result;
	s1.Push(input[0]);//Ϊ�˷�ֹ����Խ�������ɱ������Ƚ���һ����ѹջ���ٺ�����ռ�
	result.append(1, 'R');//��Ϊ����ջ����
	int out = 0;
	int in = 1;//��Ϊ����ջ������������ջ���������1
	while (out < n_values)//ѭ������������������ƥ���˳�ջ˳�򣬳�ջ���������ջ����ĩβ
	{
		if (in > n_values)//�����ջ�����ȵ�����ջ����ĩβ��֤��û������������ջ������ʱ��ջ���黹û���꣬˵�������ջ˳��������������
		{
			result = "�ⲻ���ܣ�";
			return result;
		}
		if (s1.Top() == output[out]) 
		{
			s1.Pop();//��ǰջ��Ԫ��ǡ�úͳ�ջ˳���һ�����Ͻ���ջ
			result.append(1, 'C');
			out++;
		}
		else
		{
			s1.Push(input[in]);//ջ��Ԫ�غͳ�ջ����ĵ�ǰָ��һ�£�ֻ�ܼ�����ջ
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




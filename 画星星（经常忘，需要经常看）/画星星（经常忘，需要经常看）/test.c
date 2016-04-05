#include<stdio.h>
#include<math.h>

int  main()
{
	int rows;
	scanf("%d",&rows);
	for(int i = 0 ; i<2*rows-1;i++)
	{
		for(int j=0;j<abs(i-rows+1);j++)
		{
			printf(" ");
		}

		for(int k=abs(rows-1-i);abs(k-rows)>0;k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
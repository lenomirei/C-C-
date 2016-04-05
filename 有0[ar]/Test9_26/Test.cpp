#include<stdio.h>

void main()
{
	int ar[4][4];
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			ar[i][j] = i*j;
		}
	}

	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			printf("%d ",ar[i][j]);
		}
		printf("\n");
	}
}

/*
void main()
{
	int ar[3][4];
	for(int i=0; i<3; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			ar[i][j] = i+j;
		}
	}

	for(i=0; i<3; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			printf("%d ",ar[i][j]);
		}
		printf("\n");
	}

	int (*p)[4] = ar;
	p++;

	int br[3][3][3] = {0};

	int (*q)[3][3] = br;
}


/*
void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Max1(int ar[], int n)
{
	int max = ar[0];
	for(int i=1; i<n; ++i)
	{
		if(max < ar[i])
			max = ar[i];
	}
	return max;
}

int Max2(int ar[], int n)
{
	int max1,max2;
	if(ar[0] > ar[1])
	{
		max1 = ar[0];
		max2 = ar[1];
	}
	else
	{
		max1 = ar[1];
		max2 = ar[0];
	}

	for(int i=2; i<n; ++i)
	{
		if(ar[i] > max2)  //ar[i] > max1
		{
			
			if(ar[i] > max1)
			{
				max2 = max1;
				max1 = ar[i];
			}
			else
			{
				max2 = ar[i];
			}
		}		
	}
	return max2;
}

void Sort(int ar[],int n)
{
	for(int i=0; i<n-1; ++i)
	{
		for(int j=0; j<n-i-1; ++j)
		{
			if(ar[j] > ar[j+1])
			{
				Swap(&ar[j],&ar[j+1]);
			}
		}
	}
}

  /////////////////////////////////////////////////////
void Resverse(int ar[], int n)
{}

int  Search(int ar[], int n, int key)
{}
///////////////////////////////////////////////////////

void main()
{
	int ar[] = {41,4,64,2,8,87,3,45,876,9,401};
	int max_value = Max1(ar,sizeof(ar)/sizeof(int));
	printf("first max value = %d\n",max_value);
	
	Sort(ar,sizeof(ar)/sizeof(int)); //-->
	
	int second_value = Max2(ar,sizeof(ar)/sizeof(int));
	printf("second max value = %d\n",second_value);


}

/*
void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};

	ar[0];
	0[ar];  //->哲学家

	for(int i=0; i<10; ++i)
	{
		printf("%d ",ar[i]);// *(ar+0) ==> *(0+ar) 0[ar]
	}
	printf("\n");

	for(i=0; i<10; ++i)
	{
		printf("%d ",*(ar+i));
	}
	printf("\n");

	int *p = ar;
	for(i=0; i<10; ++i)
	{
		printf("%d ",*(p+i));
	}
	printf("\n");
} 

/*
void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void main()
{
	int a = 10;
	int b = 20;
	Swap(&a,&b);
	printf("a = %d, b = %d\n",a,b);
}

/*
// 01
//0471
//5810
//0x


int Max(int a, int b)
{
	return a>b ? a:b;
}

void main()
{
	int a= 100;
	Max(100,200);

	int(*pfun)(int,int);
	pfun = &Max;
	(*pfun)(10,20);
}

/*
//argument count
//argument value
//不定长

void main(int argc, char *argv)
{
	
	printf("argc = %d\n",argc);
	for(int i=0; i<argc; ++i)
	{
		printf("%s\n",argv[i]);
	}
	
}
*/
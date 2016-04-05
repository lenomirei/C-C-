#include"head.h"
#include"menu.h"

void test1()
{
	Date t1(2015,11,28);
	Date t2(2015,11,28);
	Date ret=t1-28;
	ret.display();
}


void test2()
{
	Date t1(2015,11,30);
	Date t2(2015,10,5);
	int ret=t1-t2;
	cout<<ret<<endl;
}



void test3()
{
	
	int select=0;
	Date d1,d2;
	int t;
	while(select!=9)
	{
		system("pause");
		system("CLS");
		menu();
		cout<<"请输入选择"<<endl;
		cin>>select;

		switch(select)
		{
		case 1:


			cout<<"请输入一个日期"<<endl;
			cin>>d1;
			cout<<"请输入一个数"<<endl;
			cin>>t;
			cout<<"结果是"<<d1+t<<endl;
			break;
		case 2:


			cout<<"请输入一个日期"<<endl;
			cin>>d1;
			cout<<"请输入一个数"<<endl;
			cin>>t;
			d1+=t;
			cout<<"结果是"<<d1<<endl;
			break;
		case 3:

			cout<<"请输入一个日期"<<endl;
			cin>>d1;
			d1++;
			cout<<d1<<endl;
			break;
		case 4:


			cout<<"请输入一个日期"<<endl;
			cin>>d1;
			cout<<"请输入一个数"<<endl;
			cin>>t;
			cout<<"结果是"<<d1-t<<endl;
			break;
		case 5:


			cout<<"请输入一个日期"<<endl;
			cin>>d1;
			cout<<"请输入一个数"<<endl;
			cin>>t;
			d1+=t;
			cout<<"结果是"<<d1<<endl;
			break;
		case 6:

			cout<<"请输入第一个日期"<<endl;
			cin>>d1;
			cout<<"请输入第二个日期"<<endl;
			cin>>d2;
			cout<<"结果是"<<d1-d2<<endl;
			break;
		case 7:

			cout<<"请输入一个日期"<<endl;
			cin>>d1;
			d1--;
			cout<<d1<<endl;
			break;
		case 8:
			break;
		case 9:
			exit(0);
			break;
		default:
			break;
		}
	}
}

void main()
{
	//test1();
	test3();
}
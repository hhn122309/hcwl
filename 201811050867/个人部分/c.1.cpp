#include<iostream>
using namespace std;
int fun1(int a,int b) //通过返回值将新数c传给主函数
	{int d,e;
		int c=0;
		d=a%10;
		e=a/10%10;
		c=d*1000+e*10;
		e=b%10;
		d=b/10%10;
		c=c+d+e*100;
		return c;
	}
void fun2(int a,int b,int *c)//通过引用参数将新数传给主函数
	{int d,e;
		d=a%10;
		e=a/10%10;
		*c=d*1000+e*10;
		e=b%10;
		d=b/10%10;
		*c=*c+d+e*100;
	}
void fun3(int a,int b,int &c)//通过指针型参数将新数传给主函数
	{int d,e;
		d=a%10;
		e=a/10%10;
		c=d*1000+e*10;
		e=b%10;
		d=b/10%10;
		c=c+d+e*100;
	}
int main()
{
int c,a,b;
cout<<"请输入两个数a，b"<<endl;
cin>>a>>b;
cout<<"通过返回值将新数c传给主函数"<<endl;
c=fun1(a,b);
cout<<c<<endl;
cout<<"通过指针型参数将新数传给主函数"<<endl;
fun2(a,b,&c);
cout<<c<<endl;
cout<<"通过引用参数将新数传给主函数"<<endl;
fun3(a,b,c);
cout<<c<<endl;
}
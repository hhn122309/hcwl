#include<iostream>
using namespace std;
int fun1(int a,int b) //ͨ������ֵ������c����������
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
void fun2(int a,int b,int *c)//ͨ�����ò�������������������
	{int d,e;
		d=a%10;
		e=a/10%10;
		*c=d*1000+e*10;
		e=b%10;
		d=b/10%10;
		*c=*c+d+e*100;
	}
void fun3(int a,int b,int &c)//ͨ��ָ���Ͳ�������������������
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
cout<<"������������a��b"<<endl;
cin>>a>>b;
cout<<"ͨ������ֵ������c����������"<<endl;
c=fun1(a,b);
cout<<c<<endl;
cout<<"ͨ��ָ���Ͳ�������������������"<<endl;
fun2(a,b,&c);
cout<<c<<endl;
cout<<"ͨ�����ò�������������������"<<endl;
fun3(a,b,c);
cout<<c<<endl;
}
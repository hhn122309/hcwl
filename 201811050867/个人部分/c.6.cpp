#include<iostream>
#include <math.h>
using namespace std;


class vehicle	//创建vehicle类
{
public:
vehicle(int h, int e)	//构造函数
{
	wheels = h;
	weight = e;
}
void disp()		//显示函数
{
	cout << "wheels=" << wheels << ",weight=" << weight << endl;
}
protected:
int wheels;
int weight;
};

class car:private vehicle  //创建car类
{
public:
car(int h, int e, int p) :vehicle(h,e)	//构造函数
{
	pa1 = p;
}
void disp()
{	cout<<endl;
	vehicle::disp();
	cout << "pa1=" << pa1 << endl;
}
int pa1;
};

class truck :private vehicle	//创建truck类
{
public:
truck(int h, int e, int a,int pay) :vehicle(h, e)
{
pa2 = a;
payl = pay;
}
void disp()		//构造函数
{cout<<endl;
vehicle::disp();
cout << "pa2=" << pa2<<',' << "payl=" << payl << endl;
}
int pa2;
int payl;
};

void main()
{
vehicle a(80, 75);
car b(55, 42, 20);
truck c(30, 25, 15, 5);
a.disp();
b.disp();
c.disp();
}

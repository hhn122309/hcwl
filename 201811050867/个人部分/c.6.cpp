#include<iostream>
#include <math.h>
using namespace std;


class vehicle	//����vehicle��
{
public:
vehicle(int h, int e)	//���캯��
{
	wheels = h;
	weight = e;
}
void disp()		//��ʾ����
{
	cout << "wheels=" << wheels << ",weight=" << weight << endl;
}
protected:
int wheels;
int weight;
};

class car:private vehicle  //����car��
{
public:
car(int h, int e, int p) :vehicle(h,e)	//���캯��
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

class truck :private vehicle	//����truck��
{
public:
truck(int h, int e, int a,int pay) :vehicle(h, e)
{
pa2 = a;
payl = pay;
}
void disp()		//���캯��
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

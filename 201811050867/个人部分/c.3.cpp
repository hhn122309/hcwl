#include<iostream>
using namespace std;
#define Max 55
struct student
{int id;
double yu,shu,ying,sum;
};
int main()
{int i,j,a,b,c,k;
student students[Max],t;
cout<<"请输入学生个数和各个成绩"<<endl;
cin>>k;
for(i=0;i<k;i++) //构造k组学生数据
	{
	students[i].id=i+1;
	cin>>a>>b>>c;
	students[i].yu=a;
	students[i].shu=b;
	students[i].ying=c;
	students[i].sum=a+b+c;
	}
for(i=0;i<k-1;i++)//排序
{	
	for(j=i+1;j<k;j++)
	{
	if(students[i].sum<students[j].sum)//先按总分
		{t=students[i];
		students[i]=students[j];
		students[j]=t;
		}
	if(students[i].sum==students[j].sum)//如果总分相同
		{		
		if(students[i].yu<students[j].yu)
			{t=students[i];
			students[i]=students[j];
			students[j]=t;
			}
		if(students[i].yu==students[j].yu)//如果语文分数相同
			if(students[i].id>students[j].id)
				{t=students[i];
					students[i]=students[j];
					students[j]=t;
				}
		}
		
	}
}
cout<<"如下5位数据为规则排序后的"<<endl;
for(i=0;i<5;i++)
cout<<students[i].id<<' '<<students[i].sum<<endl;
return 0;
}

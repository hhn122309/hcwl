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
cout<<"������ѧ�������͸����ɼ�"<<endl;
cin>>k;
for(i=0;i<k;i++) //����k��ѧ������
	{
	students[i].id=i+1;
	cin>>a>>b>>c;
	students[i].yu=a;
	students[i].shu=b;
	students[i].ying=c;
	students[i].sum=a+b+c;
	}
for(i=0;i<k-1;i++)//����
{	
	for(j=i+1;j<k;j++)
	{
	if(students[i].sum<students[j].sum)//�Ȱ��ܷ�
		{t=students[i];
		students[i]=students[j];
		students[j]=t;
		}
	if(students[i].sum==students[j].sum)//����ܷ���ͬ
		{		
		if(students[i].yu<students[j].yu)
			{t=students[i];
			students[i]=students[j];
			students[j]=t;
			}
		if(students[i].yu==students[j].yu)//������ķ�����ͬ
			if(students[i].id>students[j].id)
				{t=students[i];
					students[i]=students[j];
					students[j]=t;
				}
		}
		
	}
}
cout<<"����5λ����Ϊ����������"<<endl;
for(i=0;i<5;i++)
cout<<students[i].id<<' '<<students[i].sum<<endl;
return 0;
}

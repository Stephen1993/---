#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include<iostream>
#include<string>
#include"struct.h"
using namespace std;
extern __int64 number;
extern student *head;
extern void put_member(student *h);
student *search()
{
    string name1;
	bool a=false;
	__int64 n=0,m,x1=0,number1=number;
	student *p1=head,*p2=head,*p3;
	cout<<"请输入名字或学号选择学生:";
	cin>>m;
	system("cls");
	if(cin.fail())
	{
		cin.clear();
		cin>>name1;
		cin.sync();
		while(number1>0)
		{
		    p2=p2->next2;
			number1--;
			if(p2->name==name1)
			{
			   n++;
			   p3=p2;
			   a=true;
			   cout<<n<<"."<<endl;
			   put_member(p2);
			}
			number1--;
			if(number1>=0)
         {
            p1=p1->next1;
			if(p1->name==name1)
			{
			   n++;
			   p3=p1;
			   a=true;
			   cout<<n<<"."<<endl;
			   put_member(p1);
			}
          }
		}
	}
	else
	{
		while(number1>0)
		{
			p2=p2->next2;
			number1--;
			if(p2->student_number==m)
			{
				p3=p2;
				a=true;
				cout<<"1."<<endl;
				put_member(p2);
			}
			number1--;
		    if(number1>=0)
        {
             p1=p1->next1;
			if(p1->student_number==m)
			{
				p3=p1;
				a=true;
				cout<<"1."<<endl;
				put_member(p1);
			}
		}
      }
	}
	if(a)//如果输入的姓名或学号有对应的学生则a为真
      {
            if(n>1){//n>1表示该姓名的学生有多个
			number1=number;
			cout<<"请输入编号选择学生:";
			int x;
			cin>>x;
			system("cls");
			p1=p2=head;
			while(number1>0)
		  {
			p2=p2->next2;
            number1--;
            if(p2->name==name1)
			{
			   x1++;
			   if(x1==x)
			   {
               p3=p2;
		   	   put_member(p2);
			   break;
			   }
            }
            p1=p1->next1;
			number1--;
			if(p1->name==name1&&number1>=0)
			{
			   x1++;
			   if(x1==x)
			   {
               p3=p1;
		   	   put_member(p1);
			   break;
			   }
            }
		}
	}
	return p3;
  }
  return NULL;
}
#endif // SEARCH_H_INCLUDED

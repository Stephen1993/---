#ifndef PAIXU_H_INCLUDED
#define PAIXU_H_INCLUDED
#include<iostream>
#include<queue>
#include"struct.h"
using namespace std;
//extern __int64 number;
//extern student *head;
extern void put_member(student *h);
//__int64 n1=0,number2=number;
student *p3,student4;
bool paixu_c(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool a=false;
    priority_queue<student,vector<student>,cmp1>paixu;
    cout<<"存在"<<number2<<"位学生"<<endl;
    if(number2>0)
    cout<<"********************************************************************************";
		 while(number2>0)
		  {
            p2=p2->next2;
			number2--;
			if(number2>=0)
	        {paixu.push(*p2);a=true;}
	        p1=p1->next1;
	        number2--;
            if(number2>=0)
			{paixu.push(*p1);a=true;}
		  }
		  while(!paixu.empty())
		  {
		  	student4=paixu.top();
		  	p3=&student4;
		  	cout<<++n1<<'.'<<endl;
  			put_member(p3);
  			paixu.pop();
  		  }
    return a;
}
bool paixu_chinese(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool a=false;
    priority_queue<student,vector<student>,cmp2>paixu;
    cout<<"存在"<<number2<<"位学生"<<endl;
    if(number2>0)
    cout<<"********************************************************************************";
		 while(number2>0)
		  {
            p2=p2->next2;
			number2--;
			if(number2>=0)
	        {paixu.push(*p2);a=true;}
	        p1=p1->next1;
	        number2--;
            if(number2>=0)
			{paixu.push(*p1);a=true;}
		  }
		  while(!paixu.empty())
		  {
		  	student4=paixu.top();
		  	p3=&student4;
		  	cout<<++n1<<'.'<<endl;
  			put_member(p3);
  			paixu.pop();
  		  }
   return a;
}
bool paixu_math(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool a=false;
    priority_queue<student,vector<student>,cmp3>paixu;
    cout<<"存在"<<number2<<"位学生"<<endl;
    if(number2>0)
    cout<<"********************************************************************************";
		 while(number2>0)
		  {
            p2=p2->next2;
			number2--;
			if(number2>=0)
	        {paixu.push(*p2);a=true;}
	        p1=p1->next1;
	        number2--;
            if(number2>=0)
			{paixu.push(*p1);a=true;}
		  }
		  while(!paixu.empty())
		  {
		  	student4=paixu.top();
		  	p3=&student4;
		  	cout<<++n1<<'.'<<endl;
  			put_member(p3);
  			paixu.pop();
  		  }
   return a;
}
bool paixu_english(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool a=false;
    priority_queue<student,vector<student>,cmp4>paixu;
    cout<<"存在"<<number2<<"位学生"<<endl;
    if(number2>0)
    cout<<"********************************************************************************";
		 while(number2>0)
		  {
            p2=p2->next2;
			number2--;
			if(number2>=0)
	        {paixu.push(*p2);a=true;}
	        p1=p1->next1;
	        number2--;
            if(number2>=0)
			{paixu.push(*p1);a=true;}
		  }
		  while(!paixu.empty())
		  {
		  	student4=paixu.top();
		  	p3=&student4;
		  	cout<<++n1<<'.'<<endl;
  			put_member(p3);
  			paixu.pop();
  		  }
   return a;
}
bool paixu_lisan(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool a=false;
    priority_queue<student,vector<student>,cmp5>paixu;
    cout<<"存在"<<number2<<"位学生"<<endl;
    if(number2>0)
    cout<<"********************************************************************************";
		 while(number2>0)
		  {
            p2=p2->next2;
			number2--;
			if(number2>=0)
	        {paixu.push(*p2);a=true;}
	        p1=p1->next1;
	        number2--;
            if(number2>=0)
			{paixu.push(*p1);a=true;}
		  }
		  while(!paixu.empty())
		  {
		  	student4=paixu.top();
		  	p3=&student4;
		  	cout<<++n1<<'.'<<endl;
  			put_member(p3);
  			paixu.pop();
  		  }
   return a;
}
bool paixu_szlj(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool a=false;
    priority_queue<student,vector<student>,cmp6>paixu;
    cout<<"存在"<<number2<<"位学生"<<endl;
    if(number2>0)
    cout<<"********************************************************************************";
		 while(number2>0)
		  {
            p2=p2->next2;
			number2--;
			if(number2>=0)
	        {paixu.push(*p2);a=true;}
	        p1=p1->next1;
	        number2--;
            if(number2>=0)
			{paixu.push(*p1);a=true;}
		  }
		  while(!paixu.empty())
		  {
		  	student4=paixu.top();
		  	p3=&student4;
		  	cout<<++n1<<'.'<<endl;
  			put_member(p3);
  			paixu.pop();
  		  }
   return a;
}
bool paixu_sport(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool a=false;
    priority_queue<student,vector<student>,cmp7>paixu;
    cout<<"存在"<<number2<<"位学生"<<endl;
    if(number2>0)
    cout<<"********************************************************************************";
		 while(number2>0)
		  {
            p2=p2->next2;
			number2--;
			if(number2>=0)
	        {paixu.push(*p2);a=true;}
	        p1=p1->next1;
	        number2--;
            if(number2>=0)
			{paixu.push(*p1);a=true;}
		  }
		  while(!paixu.empty())
		  {
		  	student4=paixu.top();
		  	p3=&student4;
		  	cout<<++n1<<'.'<<endl;
  			put_member(p3);
  			paixu.pop();
  		  }
   return a;
}
bool paixu_makesi(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool a=false;
    priority_queue<student,vector<student>,cmp8>paixu;
    cout<<"存在"<<number2<<"位学生"<<endl;
    if(number2>0)
    cout<<"********************************************************************************";
		 while(number2>0)
		  {
            p2=p2->next2;
			number2--;
			if(number2>=0)
	        {paixu.push(*p2);a=true;}
	        p1=p1->next1;
	        number2--;
            if(number2>=0)
			{paixu.push(*p1);a=true;}
		  }
		  while(!paixu.empty())
		  {
		  	student4=paixu.top();
		  	p3=&student4;
		  	cout<<++n1<<'.'<<endl;
  			put_member(p3);
  			paixu.pop();
  		  }
   return a;
}
bool paixu_all(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool a=false;
    priority_queue<student,vector<student>,cmp9>paixu;
    cout<<"存在"<<number2<<"位学生"<<endl;
    if(number2>0)
    cout<<"********************************************************************************";
		 while(number2>0)
		  {
            p2=p2->next2;
			number2--;
			if(number2>=0)
	        {paixu.push(*p2);a=true;}
	        p1=p1->next1;
	        number2--;
            if(number2>=0)
			{paixu.push(*p1);a=true;}
		  }
		  while(!paixu.empty())
		  {
		  	student4=paixu.top();
		  	p3=&student4;
		  	cout<<++n1<<'.'<<endl;
  			put_member(p3);
  			paixu.pop();
  		  }
   return a;
}
#endif // PAIXU_H_INCLUDED

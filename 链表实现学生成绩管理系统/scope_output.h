#ifndef SCOPE_OUTPUT_H_INCLUDED
#define SCOPE_OUTPUT_H_INCLUDED
#include<iostream>
#include"struct.h"
using namespace std;
//extern void put_member(student *h);
//extern student *head;
double grade1,grade2;
//__int64 n1=0,number2=number;
//student *p1=head,*p2=head;
bool scope_c(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool b=false;
    while(number2>0)
		{
  			p2=p2->next2;
			number2--;
			if(p2->c_grade>=grade1&&p2->c_grade<=grade2)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p2);
			}
			p1=p1->next1;
			number2--;
			if(p1->c_grade>=grade1&&p1->c_grade<=grade2&&number2>=0)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p1);
			}
  		  }
    return b;
}
bool scope_chinese(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool b=false;
    while(number2>0)
          {
  		  	p2=p2->next2;
			number2--;
			if(p2->chinese_grade>=grade1&&p2->chinese_grade<=grade2)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p2);
			}
			p1=p1->next1;
			number2--;
			if(p1->chinese_grade>=grade1&&p1->chinese_grade<=grade2&&number2>=0)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p1);
			}
  		  }
    return b;
}
bool scope_math(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool b=false;
    while(number2>0)
		   {
  		  	p2=p2->next2;
			number2--;
			if(p2->math_grade>=grade1&&p2->math_grade<=grade2)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p2);
			}
			p1=p1->next1;
			number2--;
			if(p1->math_grade>=grade1&&p1->math_grade<=grade2&&number2>=0)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p1);
			}
		  }
    return b;
}
bool scope_english(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool b=false;
    while(number2>0)
		   {
  		  	p2=p2->next2;
			number2--;
			if(p2->english_grade>=grade1&&p2->english_grade<=grade2)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p2);
			}
			p1=p1->next1;
			number2--;
			if(p1->english_grade>=grade1&&p1->english_grade<=grade2&&number2>=0)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p1);
			}
  		  }
    return b;
}
bool scope_lisan(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool b=false;
    while(number2>0)
		   {
  		  	p2=p2->next2;
			number2--;
			if(p2->lisan_grade>=grade1&&p2->lisan_grade<=grade2)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p2);
			}
			p1=p1->next1;
			number2--;
			if(p1->lisan_grade>=grade1&&p1->lisan_grade<=grade2&&number2>=0)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p1);
			}
  		  }
    return b;
}
bool scope_szlj(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool b=false;
    while(number2>0)
		   {
  		  	p2=p2->next2;
			number2--;
			if(p2->szlj_grade>=grade1&&p2->szlj_grade<=grade2)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p2);
			}
			p1=p1->next1;
			number2--;
			if(p1->szlj_grade>=grade1&&p1->szlj_grade<=grade2&&number2>=0)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p1);
			}
  		  }
    return b;
}
bool scope_sport(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool b=false;
    while(number2>0)
		   {
  		  	p2=p2->next2;
			number2--;
			if(p2->sport_grade>=grade1&&p2->sport_grade<=grade2)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p2);
			}
			p1=p1->next1;
			number2--;
			if(p1->sport_grade>=grade1&&p1->sport_grade<=grade2&&number2>=0)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p1);
			}
		   }
    return b;
}
bool scope_makesi(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool b=false;
    while(number2>0)
		   {
  		  	p2=p2->next2;
			number2--;
			if(p2->makesi_grade>=grade1&&p2->makesi_grade<=grade2)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p2);
			}
			p1=p1->next1;
			number2--;
			if(p1->makesi_grade>=grade1&&p1->makesi_grade<=grade2&&number2>=0)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p1);
			}
  		  }
    return b;
}
bool scope_all(student *p1,student *p2,__int64 n1,__int64 number2)
{
    bool b=false;
    while(number2>0)
		  {
			p2=p2->next2;
			number2--;
			if(p2->all_grade>=grade1&&p2->all_grade<=grade2)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p2);
			}
			p1=p1->next1;
			number2--;
			if(p1->all_grade>=grade1&&p1->all_grade<=grade2&&number2>=0)
			{
			   n1++;
			   b=true;
			   cout<<n1<<"."<<endl;
			   put_member(p1);
			}
		  }
    return b;
}
#endif // SCOPE_OUTPUT_H_INCLUDED

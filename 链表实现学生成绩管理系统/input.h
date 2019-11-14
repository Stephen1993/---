#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include<iostream>
#include<set>
#include"struct.h"
using namespace std;
set<__int64>panduan;
void input_student_number(student *p)
{
    loop:cin>>p->student_number;
	while(cin.fail())
	{
	cout<<"ÊäÈë´íÎó!ÇëÖØÊä:";
	cin.clear();
	cin.sync();
	cin>>p->student_number;
	}
	if(panduan.find(p->student_number)!=panduan.end())
	{
	    cout<<"´ËÑ§ºÅÒÑ´æÔÚ!ÇëÖØÊä:";
	    goto loop;
	}
	return;
}
void input_sex(student *p)
{
    cin>>p->sex;
	while(p->sex!="ÄÐ"&&p->sex!="Å®"&&p->sex!="man"&&p->sex!="woman")
	{cout<<"²»´æÔÚ´ËÐÔ±ð!ÇëÖØÊä:";
	 cin>>p->sex;
	}
	return;
}
void input_c(student *p)
{
    cin>>p->c_grade;
	while(cin.fail()||p->c_grade<0||p->c_grade>100)
	{
		cout<<"ÊäÈë´íÎó!ÇëÖØÊä:";
		cin.clear();
	    cin.sync();
	    cin>>p->c_grade;
	}
	return;
}
void input_chinese(student *p)
{
    cin>>p->chinese_grade;
    while(cin.fail()||p->chinese_grade<0||p->chinese_grade>100)
    {
    	cout<<"ÊäÈë´íÎó!ÇëÖØÊä:";
    	cin.clear();
	    cin.sync();
	    cin>>p->chinese_grade;
    }
    return;
}
void input_math(student *p)
{
    while(cin.fail()||p->math_grade<0||p->math_grade>100)
		{
		cout<<"ÊäÈë´íÎó!ÇëÖØÊä:";
		cin.clear();
        cin.sync();
        cin>>p->math_grade;
		}
		return;
}
void input_english(student *p)
{
    cin>>p->english_grade;
	while(cin.fail()||p->english_grade<0||p->english_grade>100)
		{
			cout<<"ÊäÈë´íÎó!ÇëÖØÊä:";
			cin.clear();
	        cin.sync();
	        cin>>p->english_grade;
		}
		return;
}
void input_lisan(student *p)
{
    cin>>p->lisan_grade;
	while(cin.fail()||p->lisan_grade<0||p->lisan_grade>100)
	{
		cout<<"ÊäÈë´íÎó!ÇëÖØÊä:";
		cin.clear();
		cin.sync();
		cin>>p->lisan_grade;
	}
	return;
}
void input_szlj(student *p)
{
    cin>>p->szlj_grade;
	while(cin.fail()||p->szlj_grade<0||p->szlj_grade>100)
	{
		cout<<"ÊäÈë´íÎó!ÇëÖØÊä:";
		cin.clear();
		cin.sync();
		cin>>p->szlj_grade;
	}
	return;
}
void input_sport(student *p)
{
    cin>>p->sport_grade;
	while(cin.fail()||p->sport_grade<0||p->sport_grade>100)
	{
		cout<<"ÊäÈë´íÎó!ÇëÖØÊä:";
		cin.clear();
		cin.sync();
		cin>>p->sport_grade;
	}
	return;
}
void input_makesi(student *p)
{
    cin>>p->makesi_grade;
	while(cin.fail()||p->makesi_grade<0||p->makesi_grade>100)
	{
		cout<<"ÊäÈë´íÎó!ÇëÖØÊä:";
		cin.clear();
		cin.sync();
		cin>>p->makesi_grade;
	}
	return;
}
#endif

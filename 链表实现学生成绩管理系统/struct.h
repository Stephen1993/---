#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include<string>
using namespace std;
struct student
{
	student *next1;
	__int64 student_number;//学号
	string name;//姓名
	string sex;//性别
	string faculty;//学院
	string major;//专业
	string class_;//班级
	double c_grade;//c++成绩
	double chinese_grade;//语文成绩
	double math_grade;//数学成绩
	double english_grade;//英语成绩
	double lisan_grade;// 离散成绩
	double szlj_grade;//数字逻辑成绩
	double all_grade; //总成绩
	double sport_grade;//体育成绩
	double makesi_grade;//马克思成绩
	student *next2;
};
struct cmp1
{
    bool operator()(student a,student b)
	{return a.c_grade<b.c_grade;}
};
struct cmp2
{
    bool operator()(student a,student b)
	{return a.chinese_grade<b.chinese_grade;}
};
struct cmp3
{
    bool operator()(student a,student b)
	{return a.math_grade<b.math_grade;}
};
struct cmp4
{
    bool operator()(student a,student b)
	{return a.english_grade<b.english_grade;}
};
struct cmp5
{
    bool operator()(student a,student b)
	{return a.lisan_grade<b.lisan_grade;}
};
struct cmp6
{
    bool operator()(student a,student b)
	{return a.szlj_grade<b.szlj_grade;}
};
struct cmp7
{
    bool operator()(student a,student b)
	{return a.sport_grade<b.sport_grade;}
};
struct cmp8
{
    bool operator()(student a,student b)
	{return a.makesi_grade<b.makesi_grade;}
};
struct cmp9
{
    bool operator()(student a,student b)
	{return a.all_grade<b.all_grade;}
};
#endif // STRUCT_H_INCLUDED

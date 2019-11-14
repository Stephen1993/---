#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include<string>
using namespace std;
struct student
{
	student *next1;
	__int64 student_number;//ѧ��
	string name;//����
	string sex;//�Ա�
	string faculty;//ѧԺ
	string major;//רҵ
	string class_;//�༶
	double c_grade;//c++�ɼ�
	double chinese_grade;//���ĳɼ�
	double math_grade;//��ѧ�ɼ�
	double english_grade;//Ӣ��ɼ�
	double lisan_grade;// ��ɢ�ɼ�
	double szlj_grade;//�����߼��ɼ�
	double all_grade; //�ܳɼ�
	double sport_grade;//�����ɼ�
	double makesi_grade;//���˼�ɼ�
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

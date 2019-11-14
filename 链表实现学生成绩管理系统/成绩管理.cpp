#include<iostream>
#include<stdlib.h>
#include<string>
#include<conio.h>
#include<fstream>
#include"input.h"
#include"search.h"
#include"struct.h"
#include"paixu.h"
#include"scope_output.h"
using namespace std;
__int64 number=0;
struct student *head,*s;
void new_student();
void amend_student();
void search_student();
void delete_student();
void save_student_date();
void save_student_number(__int64 num);
void begin1()
{
    system("COLOR 4C");
	cout<<"********************************************************************************"<<endl;
	cout<<"                     欢迎使用学生成绩管理系统   "<<endl<<endl;
    cout<<"********************************************************************************"<<endl;
}
void end11()
{
    system("COLOR 4C");
	cout<<"********************************************************************************"<<endl;
	cout<<"                     谢谢使用学生成绩管理系统   "<<endl<<endl;
    cout<<"********************************************************************************"<<endl;
}
void put_member(student *h)
{
	cout<<"学号:"<<h->student_number;
	cout<<'\t'<<"姓名:"<<h->name;
	cout<<'\t'<<"性别:"<<h->sex;
	cout<<'\t'<<'\t'<<"学院:"<<h->faculty;
	cout<<endl<<endl<<"专业:"<<h->major;
	cout<<'\t'<<"班级:"<<h->class_;
	cout<<endl<<endl<<"c++成绩:"<<h->c_grade;
	cout<<'\t'<<"语文成绩:"<<h->chinese_grade;
	cout<<endl<<endl<<"数学成绩:"<<h->math_grade;
	cout<<'\t'<<"英语成绩:"<<h->english_grade;
	cout<<endl<<endl<<"离散成绩:"<<h->lisan_grade;
	cout<<'\t'<<"数字逻辑:"<<h->szlj_grade;
	cout<<endl<<endl<<"体育成绩:"<<h->sport_grade;
	cout<<'\t'<<"马克思成绩:"<<h->makesi_grade;
	cout<<endl<<endl<<"总成绩:"<<h->all_grade<<endl;
    cout<<"********************************************************************************";
}
void save_student_number(__int64 num)
{
	number+=num;
	ofstream onfile1;
	onfile1.open("student_number.dat");
	onfile1<<number;
	onfile1.close();
}
void save_student_date()
{
	student *p=head;
	ofstream onfile;
	onfile.open("student_date.dat");
	for(int i=1;i<=number;i++)
	{
		p=p->next2;
		onfile<<p->student_number<<'\t'<<p->name<<'\t'<<p->sex<<'\t'<<p->faculty<<'\t';
		onfile<<p->major<<'\t'<<p->class_<<'\t'<<p->c_grade<<'\t'<<p->chinese_grade<<'\t';
		onfile<<p->math_grade<<'\t'<<p->english_grade<<'\t'<<p->lisan_grade<<'\t'<<p->szlj_grade<<'\t'<<p->sport_grade<<'\t'<<p->makesi_grade<<'\t'<<p->all_grade<<endl;
	}
	onfile.close();
}
void new_student()
{
	student *p=new student;
	cout<<"请输入学生学号:";
	input_student_number(p);
	cout<<endl<<"请输入学生姓名:";
	cin>>p->name;
	cout<<endl<<"请输入性别:";
	input_sex(p);
	cout<<endl<<"请输入学院:";
	cin>>p->faculty;
	cout<<endl<<"请输入专业:";
	cin>>p->major;
	cout<<endl<<"请输入班级:";
    cin>>p->class_;
    cout<<endl<<"请输入c++成绩(0~100):";
    input_c(p);
    cout<<endl<<"请输入语文成绩(0~100):";
    input_chinese(p);
    cout<<endl<<"请输入数学成绩(0~100):";
    cin>>p->math_grade;
	input_math(p);
    cout<<endl<<"请输入英语成绩(0~100):";
    input_english(p);
    cout<<endl<<"请输入离散成绩(0~100):";
    input_lisan(p);
	cout<<endl<<"请输入数字逻辑成绩(0~100):";
	input_szlj(p);
	cout<<endl<<"请输入体育成绩(0~100):";
	input_sport(p);
	cout<<endl<<"请输入马克思成绩(0~100):";
	input_makesi(p);
	p->all_grade=p->c_grade+p->chinese_grade+p->math_grade+p->english_grade+p->lisan_grade+p->szlj_grade+p->sport_grade+p->makesi_grade;
    cout<<"1.确认添加!"<<'\t'<<"2.放弃添加!"<<endl;
    int n=0;
    char c;
	do{
	    do{
           c=getch();
           if(c==27){
               if(c==27){
                  if(n)cout<<endl;
                  cout<<"确认返回?"<<endl;char d;do{d=getch();if(d==13)return;}while(d!=27);
                  cout<<"返回失败!请继续选择功能:";
                  continue;
                  }
               }
           if(c==13)break;
           cout<<c;
           n=n*10+c-'0';
	      }while(1);
        if(n<1||n>2){cout<<endl<<"输入错误!请重输:";n=0;}
	}while(!n);
	cout<<endl;
	if(n==1)
	{
    panduan.insert(p->student_number);
    head->next1=p;
	p->next2=head;
	s->next2=p;
	p->next1=s;
	s=p;
	save_student_number(1);
	save_student_date();
	cout<<"添加学生成功!按任意键返回..."<<endl;
	}
	else
	{
	    cout<<"学生新建失败!按任意键返回..."<<endl;
	}
	getch();
}
void amend_student()
{
    int n;
    char c;
    student *p3=search();
    if(p3!=NULL)
     {
        student p4;
  loop2:p4=*p3;
        cout<<"请选择修改信息:"<<endl<<"1.学号"<<"2.姓名"<<"3.性别"<<"4:学院"<<"5.专业"<<"6.班级"<<"7.c++成绩"<<"8.语文成绩"<<"9:数学成绩"<<"10:英语成绩";
		cout<<endl<<"11:离散成绩"<<"12:数字逻辑成绩"<<"13:体育成绩"<<"14:马克思成绩"<<endl;
        n=0;
        do{
	       do{
              c=getch();
              if(c==27){
                  if(n)cout<<endl;
                  cout<<"确认返回?";char d;do{d=getch();if(d==13)return;}while(d!=27);system("cls");
                  put_member(&p4);
                  cout<<"请选择修改信息:"<<endl<<"1.学号"<<"2.姓名"<<"3.性别"<<"4:学院"<<"5.专业"<<"6.班级"<<"7.c++成绩"<<"8.语文成绩"<<"9:数学成绩"<<"10:英语成绩";
		          cout<<endl<<"11:离散成绩"<<"12:数字逻辑成绩"<<"13:体育成绩"<<"14:马克思成绩"<<endl;
                  continue;
                  }
              if(c==13)break;
              cout<<c;
              n=n*10+c-'0';
	       }while(1);
           if(n<1||n>14){cout<<endl<<"输入错误!请重输:";n=0;}
	   }while(!n);
	   cout<<endl;
		switch(n)
		{
			case 1:cout<<"请输入新学号:";panduan.erase(panduan.find(p4.student_number));input_student_number(&p4);break;
			case 2:cout<<"请输入新姓名:";cin>>p4.name;break;
			case 3:cout<<"请输入新性别:";input_sex(&p4);break;
			case 4:cout<<"请输入新学院:";cin>>p4.faculty;break;
			case 5:cout<<"请输入新专业";cin>>p4.major;break;
			case 6:cout<<"请输入新班级:";cin>>p4.class_;break;
			case 7:cout<<"请输入学生新c++成绩(0~100):";input_c(&p4);break;
			case 8:cout<<"请输入学生新语文成绩(0~100):";input_chinese(&p4);break;
			case 9:cout<<"请输入学生新数学成绩(0~100):";input_math(&p4);break;
			case 10:cout<<"请输入学生新英语成绩(0~100):";input_english(&p4);break;
			case 11:cout<<"请输入学生新离散成绩(0~100):";input_lisan(&p4);break;
			case 12:cout<<"请输入学生新数字逻辑成绩(0~100):";input_szlj(&p4);break;
			case 13:cout<<"请输入学生新体育成绩(0~100):";input_sport(&p4);break;
			case 14:cout<<"请输入学生新马克思成绩(0~100):";input_makesi(&p4);break;
		}
 	    p4.all_grade=p4.c_grade+p4.chinese_grade+p4.math_grade+p4.english_grade+p4.lisan_grade+p4.szlj_grade+p4.sport_grade+p4.makesi_grade;
		system("cls");
		put_member(&p4);
		cout<<"1.确认修改!"<<'\t'<<"2.重新修改!"<<'\t'<<"3.放弃修改!"<<endl;
        n=0;
	    do{
	       do{
              c=getch();
              if(c==27){
                  if(n)cout<<endl;
                  cout<<"确认返回?";char d;do{d=getch();if(d==13)return;}while(d!=27);system("cls");
                  put_member(&p4);
		          cout<<"1.确认修改!"<<'\t'<<"2.重新修改!"<<'\t'<<"3.放弃修改!"<<endl;
                  continue;
                  }
              if(c==13)break;
              cout<<c;
              n=n*10+c-'0';
	       }while(1);
           if(n<1||n>3){cout<<endl<<"输入错误!请重输:";n=0;}
	   }while(!n);
	   cout<<endl;
	   if(n==1)
		{*p3=p4;
		panduan.insert(p3->student_number);
        save_student_date();
		cout<<"修改成功!按任意键返回...";}
		else
		if(n==2)
		{
		    panduan.insert(p3->student_number);
		    system("cls");
		    put_member(p3);
		    goto loop2;
		}
		else
		{
		    panduan.insert(p3->student_number);
		    cout<<"修改失败!按任意键返回...";
		}
    }
 else cout<<"未找到此学生!请按任意键返回...";
 getch();
}
void search_student()
{
loop:cout<<"请选择查看方式:"<<endl;
	cout<<"1:输入姓名或学号查看"<<endl;
	cout<<"2:输入成绩范围查看"<<endl;
	cout<<"3:输入学院查看"<<endl;
	cout<<"4:输入班级查看"<<endl;
	cout<<"5:全部查看"<<endl;
	cout<<"6:返回主菜单"<<endl;
	__int64 number2=number;
	int n=0;
    char c;
	do{
	    do{
           c=getch();
           if(c==27){
               if(c==27){
                   if(n)cout<<endl;
                  cout<<"确认返回?"<<endl;char d;do{d=getch();if(d==13)return;}while(d!=27);system("cls");
                  goto loop;
                  }
               }
           if(c==13)break;
           cout<<c;
           n=n*10+c-'0';
	      }while(1);
        if(n<1||n>6){cout<<endl<<"输入错误!请重输:";n=0;}
	}while(!n);
system("cls");
switch(n)
{
case 1:
{
	cout<<"请输入学号或姓名:";
	bool a=false;
	string name1;
	__int64 m,n1=0;
	student *p1=head,*p2=head;
	cin>>m;
	system("cls");
	if(cin.fail())
	{
		cin.clear();
		cin>>name1;
		cin.sync();
		while(number2>0)
		{
			p2=p2->next2;
			number2--;
			if(p2->name==name1)
			{
			   n1++;
			   a=true;
			   cout<<n1<<"."<<endl;
			   put_member(p2);
			}
			p1=p1->next1;
			number2--;
			if(p1->name==name1&&number2>=0)
			{
			   n1++;
			   a=true;
			   cout<<n1<<"."<<endl;
			   put_member(p1);
			}
		}
	}
	else
	{
		while(number2>0)
		{    p2=p2->next2;
		     number2--;
			if(p2->student_number==m)
			{
				n1++;
				a=true;
				cout<<n1<<"."<<endl;
				put_member(p2);
			}
			p1=p1->next1;
		    number2--;
			if(p1->student_number==m&&number2>=0)
			{
				n1++;
				a=true;
				cout<<n1<<"."<<endl;
				put_member(p1);
			}
		}
	}if(!a){cout<<"未找到此学生!请按任意键返回...";getch();system("cls");goto loop;}
	 else {cout<<"查询成功!请按任意键返回...";getch();system("cls");goto loop;}
};break;
case 2:
{
	cout<<"请输入学科(如数学)或总分:";
	string stu;
	cin>>stu;
    bool a=false;
    extern double grade1,grade2;
	cout<<"请输入最小分数:";
	cin>>grade1;
	cout<<endl<<"请输入最大分数:";
	cin>>grade2;
	if(cin.fail()||grade2<grade1)
	{
		cin.clear();
		cin.sync();
		cout<<"输入错误,请重输!"<<endl;
		cout<<"请输入最小分数:";
		cin>>grade1;
		cout<<endl<<"请输入最大分数:";
		cin>>grade2;
	}
	system("cls");
	if(stu=="c++")
      {
	     a=scope_c(head,head,0,number);
      }
   else
	  if(stu=="语文")
	  {
		 a=scope_chinese(head,head,0,number);
      }
      else
        if(stu=="数学")
  		  {
			 a=scope_math(head,head,0,number);
	      }
	  else
	    if(stu=="英语")
  		  {
			 a=scope_english(head,head,0,number);
		  }
     else
       if(stu=="离散")
         {
		     a=scope_lisan(head,head,0,number);
		 }
      else
        if(stu=="数字逻辑")
  		  {
			 a=scope_szlj(head,head,0,number);
		  }
     else
       if(stu=="体育")
  		  {
			 a=scope_sport(head,head,0,number);
		  }
     else
       if(stu=="马克思")
         {
		    a=scope_makesi(head,head,0,number);
		 }
       else
         if(stu=="总分"||stu=="总分数"||stu=="总成绩"||stu=="zongfen"||stu=="zongfenshu"||stu=="zongchengji")
         {
		    a=scope_all(head,head,0,number);
		 }
		 else
		 {cout<<"无此学科!请按任意键返回...";getch();system("cls");goto loop;}
		if(!a){cout<<"此分数段范围内无学生!请按任意键返回...";getch();system("cls");goto loop;}
		else {cout<<"查询成功!请按任意键返回...";getch();system("cls");goto loop;}
};break;
case 3:
{
	cout<<"请输入学院:";
	bool a=false;
	string school;
	__int64 n1=0;
	student *p1=head,*p2=head;
	cin>>school;
	system("cls");
	while(number2>0)
		{
			p2=p2->next2;
			number2--;
			if(p2->faculty==school)
			{
			   n1++;
			   a=true;
			   cout<<n1<<"."<<endl;
			   put_member(p2);
			}
			p1=p1->next1;
			number2--;
			if(p1->faculty==school&&number2>=0)
			{
			   n1++;
			   a=true;
			   cout<<n1<<"."<<endl;
			   put_member(p1);
			}
		}
   if(!a){cout<<"无此学院的学生!请按任意键返回...";getch();system("cls");goto loop;}
   else {cout<<"查询成功!请按任意键返回...";getch();system("cls");goto loop;}
};break;
case 4:
{
    cout<<"请输入班级:";
    bool a=false;
	string class1;
	__int64 n1=0;
	student *p1=head,*p2=head;
	cin>>class1;
	system("cls");
	while(number2>0)
		{
			p2=p2->next2;
			number2--;
			if(p2->class_==class1)
			{
			   n1++;
			   a=true;
			   cout<<n1<<"."<<endl;
			   put_member(p2);
			}
			p1=p1->next1;
			number2--;
			if(p1->class_==class1&&number2>=0)
			{
			   n1++;
			   a=true;
			   cout<<n1<<"."<<endl;
			   put_member(p1);
			}
		}
	if(!a){cout<<"无此班级的学生!请按任意键返回...";getch();system("cls");goto loop;}
	else {cout<<"查询成功!请按任意键返回...";getch();system("cls");goto loop;}
};break;
case 5:
{
    cout<<"请输入名称(如:数学,总分)按学科或总分降序输出:";
    string stul;
    cin>>stul;
    system("cls");
	bool a=false;
    if(stul=="c++")
      {
      	a=paixu_c(head,head,0,number);
      }
   else
    if(stul=="语文")
       {
      	  a=paixu_chinese(head,head,0,number);
	   }
   else
	 if(stul=="数学")
       {
      	  a=paixu_math(head,head,0,number);
	   }
   else
	 if(stul=="英语")
       {
      	  a=paixu_english(head,head,0,number);
	   }
   else
	 if(stul=="离散")
       {
      	  a=paixu_lisan(head,head,0,number);
	   }
   else
	 if(stul=="数字逻辑")
       {
      	  a=paixu_szlj(head,head,0,number);
	   }
   else
	 if(stul=="体育")
       {
      	  a=paixu_sport(head,head,0,number);
	   }
   else
	 if(stul=="马克思")
       {
      	  a=paixu_makesi(head,head,0,number);
	   }
    else
      if(stul=="总分"||stul=="总分数"||stul=="总成绩"||stul=="zongfen"||stul=="zongfenshu"||stul=="zongchengji")
       {
      	  a=paixu_all(head,head,0,number);
	   }
      else
       {cout<<"无此学科!请按任意键返回...";getch();system("cls");goto loop;}
	if(!a){cout<<"此系统还未存入学生信息!请按任意键返回...";getch();system("cls");goto loop;}
	else {cout<<"查询成功!请按任意键返回...";getch();system("cls");goto loop;}
};break;
case 6:;
}
}
void delete_student()
{
  student *p3=search();
  if(p3!=NULL)
  {
    cout<<"1.确认删除!"<<'\t'<<"2.放弃删除!"<<endl;
    int n=0;
    char c;
	do{
	    do{
           c=getch();
           if(c==27){
               if(c==27){
                  cout<<"确认返回?"<<endl;char d;do{d=getch();if(d==13)return;}while(d!=27);system("cls");
                  put_member(p3);
                  cout<<"1.确认删除!"<<'\t'<<"2.放弃删除!"<<endl;
                  continue;
                  }
               }
           if(c==13)break;
           cout<<c;
           n=n*10+c-'0';
	      }while(1);
        if(n<1||n>2){cout<<endl<<"输入错误!请重输:";n=0;}
	}while(!n);
	cout<<endl;
  if(n==1)
  {p3->next2->next1=p3->next1;
  p3->next1->next2=p3->next2;
  panduan.erase(panduan.find(p3->student_number));
  delete(p3);
  save_student_number(-1);
  save_student_date();
  cout<<"删除成功!请按任意键返回...";}
  else
   {
      cout<<"删除失败!请按任意键返回..."<<endl;
   }
  }
else cout<<"无此学生!请按任意键返回...";
getch();
}
void main_menu()
{
    cout<<"请输入所需操作(此系统支持按Esc键返回):"<<endl;
	cout<<"1:新建学生信息"<<endl<<endl;
	cout<<"2:修改学生信息"<<endl<<endl;
	cout<<"3:查看学生信息"<<endl<<endl;
	cout<<"4:删除学生信息"<<endl<<endl;
	cout<<"5:保存并退出系统"<<endl;
	int n=0;
	char c;
	do{
	    do{
        c=getch();
       if(c==27){system("cls");end11();_sleep(1500);exit(0);}
       if(c==13)break;
       cout<<c;
       n=n*10+c-'0';}while(1);
       if(n<1||n>5){cout<<endl<<"输入错误!请重输:";n=0;}
	}while(!n);
	switch(n)
	{
		case 1:system("cls");system("COLOR 2E");new_student();break;
		case 2:system("cls");system("COLOR 1D");amend_student();break;
		case 3:system("cls");system("COLOR 6A");search_student();break;
		case 4:system("cls");system("COLOR 84");delete_student();break;
		case 5:system("cls");end11();_sleep(1500);exit(0);
	}
	system("cls");
	system("COLOR 0C");
	return;
}
int main()
{
	begin1();
	_sleep(1500);
	system("cls");
    system("COLOR 0C");
	ifstream infile;
	infile.open("student_number.dat");
	infile>>number;
	infile.close();
	head=new student;
	head->next1=head->next2=NULL;
	s=head;
	ifstream infile1;
	infile1.open("student_date.dat");
	for(int i=1;i<=number;i++)
	{
		student *p=new student;
		head->next1=p;//建立双向链表并导入数据
		p->next2=head;
		s->next2=p;
		p->next1=s;
		s=p;
		infile1>>p->student_number>>p->name>>p->sex>>p->faculty>>p->major>>p->class_>>p->c_grade>>p->chinese_grade>>p->math_grade>>p->english_grade;
		infile1>>p->lisan_grade>>p->szlj_grade>>p->sport_grade>>p->makesi_grade>>p->all_grade;
		panduan.insert(p->student_number);
	}
	infile1.close();
	while(1)
	{main_menu();}
	return 0;
}
/*感悟:由于想加快效率所以使用双向链表，结果所有查找判断的代码都要双份，向前查找和向后查找，
并且输出的时候没有按输入的顺序输出，而是向前查找一个输出然后再向后查找一个输出，代码麻烦多余
以后还是用单向链表或STL中的容器做此类题。*/

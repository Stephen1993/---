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
	cout<<"                     ��ӭʹ��ѧ���ɼ�����ϵͳ   "<<endl<<endl;
    cout<<"********************************************************************************"<<endl;
}
void end11()
{
    system("COLOR 4C");
	cout<<"********************************************************************************"<<endl;
	cout<<"                     ллʹ��ѧ���ɼ�����ϵͳ   "<<endl<<endl;
    cout<<"********************************************************************************"<<endl;
}
void put_member(student *h)
{
	cout<<"ѧ��:"<<h->student_number;
	cout<<'\t'<<"����:"<<h->name;
	cout<<'\t'<<"�Ա�:"<<h->sex;
	cout<<'\t'<<'\t'<<"ѧԺ:"<<h->faculty;
	cout<<endl<<endl<<"רҵ:"<<h->major;
	cout<<'\t'<<"�༶:"<<h->class_;
	cout<<endl<<endl<<"c++�ɼ�:"<<h->c_grade;
	cout<<'\t'<<"���ĳɼ�:"<<h->chinese_grade;
	cout<<endl<<endl<<"��ѧ�ɼ�:"<<h->math_grade;
	cout<<'\t'<<"Ӣ��ɼ�:"<<h->english_grade;
	cout<<endl<<endl<<"��ɢ�ɼ�:"<<h->lisan_grade;
	cout<<'\t'<<"�����߼�:"<<h->szlj_grade;
	cout<<endl<<endl<<"�����ɼ�:"<<h->sport_grade;
	cout<<'\t'<<"���˼�ɼ�:"<<h->makesi_grade;
	cout<<endl<<endl<<"�ܳɼ�:"<<h->all_grade<<endl;
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
	cout<<"������ѧ��ѧ��:";
	input_student_number(p);
	cout<<endl<<"������ѧ������:";
	cin>>p->name;
	cout<<endl<<"�������Ա�:";
	input_sex(p);
	cout<<endl<<"������ѧԺ:";
	cin>>p->faculty;
	cout<<endl<<"������רҵ:";
	cin>>p->major;
	cout<<endl<<"������༶:";
    cin>>p->class_;
    cout<<endl<<"������c++�ɼ�(0~100):";
    input_c(p);
    cout<<endl<<"���������ĳɼ�(0~100):";
    input_chinese(p);
    cout<<endl<<"��������ѧ�ɼ�(0~100):";
    cin>>p->math_grade;
	input_math(p);
    cout<<endl<<"������Ӣ��ɼ�(0~100):";
    input_english(p);
    cout<<endl<<"��������ɢ�ɼ�(0~100):";
    input_lisan(p);
	cout<<endl<<"�����������߼��ɼ�(0~100):";
	input_szlj(p);
	cout<<endl<<"�����������ɼ�(0~100):";
	input_sport(p);
	cout<<endl<<"���������˼�ɼ�(0~100):";
	input_makesi(p);
	p->all_grade=p->c_grade+p->chinese_grade+p->math_grade+p->english_grade+p->lisan_grade+p->szlj_grade+p->sport_grade+p->makesi_grade;
    cout<<"1.ȷ�����!"<<'\t'<<"2.�������!"<<endl;
    int n=0;
    char c;
	do{
	    do{
           c=getch();
           if(c==27){
               if(c==27){
                  if(n)cout<<endl;
                  cout<<"ȷ�Ϸ���?"<<endl;char d;do{d=getch();if(d==13)return;}while(d!=27);
                  cout<<"����ʧ��!�����ѡ����:";
                  continue;
                  }
               }
           if(c==13)break;
           cout<<c;
           n=n*10+c-'0';
	      }while(1);
        if(n<1||n>2){cout<<endl<<"�������!������:";n=0;}
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
	cout<<"���ѧ���ɹ�!�����������..."<<endl;
	}
	else
	{
	    cout<<"ѧ���½�ʧ��!�����������..."<<endl;
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
        cout<<"��ѡ���޸���Ϣ:"<<endl<<"1.ѧ��"<<"2.����"<<"3.�Ա�"<<"4:ѧԺ"<<"5.רҵ"<<"6.�༶"<<"7.c++�ɼ�"<<"8.���ĳɼ�"<<"9:��ѧ�ɼ�"<<"10:Ӣ��ɼ�";
		cout<<endl<<"11:��ɢ�ɼ�"<<"12:�����߼��ɼ�"<<"13:�����ɼ�"<<"14:���˼�ɼ�"<<endl;
        n=0;
        do{
	       do{
              c=getch();
              if(c==27){
                  if(n)cout<<endl;
                  cout<<"ȷ�Ϸ���?";char d;do{d=getch();if(d==13)return;}while(d!=27);system("cls");
                  put_member(&p4);
                  cout<<"��ѡ���޸���Ϣ:"<<endl<<"1.ѧ��"<<"2.����"<<"3.�Ա�"<<"4:ѧԺ"<<"5.רҵ"<<"6.�༶"<<"7.c++�ɼ�"<<"8.���ĳɼ�"<<"9:��ѧ�ɼ�"<<"10:Ӣ��ɼ�";
		          cout<<endl<<"11:��ɢ�ɼ�"<<"12:�����߼��ɼ�"<<"13:�����ɼ�"<<"14:���˼�ɼ�"<<endl;
                  continue;
                  }
              if(c==13)break;
              cout<<c;
              n=n*10+c-'0';
	       }while(1);
           if(n<1||n>14){cout<<endl<<"�������!������:";n=0;}
	   }while(!n);
	   cout<<endl;
		switch(n)
		{
			case 1:cout<<"��������ѧ��:";panduan.erase(panduan.find(p4.student_number));input_student_number(&p4);break;
			case 2:cout<<"������������:";cin>>p4.name;break;
			case 3:cout<<"���������Ա�:";input_sex(&p4);break;
			case 4:cout<<"��������ѧԺ:";cin>>p4.faculty;break;
			case 5:cout<<"��������רҵ";cin>>p4.major;break;
			case 6:cout<<"�������°༶:";cin>>p4.class_;break;
			case 7:cout<<"������ѧ����c++�ɼ�(0~100):";input_c(&p4);break;
			case 8:cout<<"������ѧ�������ĳɼ�(0~100):";input_chinese(&p4);break;
			case 9:cout<<"������ѧ������ѧ�ɼ�(0~100):";input_math(&p4);break;
			case 10:cout<<"������ѧ����Ӣ��ɼ�(0~100):";input_english(&p4);break;
			case 11:cout<<"������ѧ������ɢ�ɼ�(0~100):";input_lisan(&p4);break;
			case 12:cout<<"������ѧ���������߼��ɼ�(0~100):";input_szlj(&p4);break;
			case 13:cout<<"������ѧ���������ɼ�(0~100):";input_sport(&p4);break;
			case 14:cout<<"������ѧ�������˼�ɼ�(0~100):";input_makesi(&p4);break;
		}
 	    p4.all_grade=p4.c_grade+p4.chinese_grade+p4.math_grade+p4.english_grade+p4.lisan_grade+p4.szlj_grade+p4.sport_grade+p4.makesi_grade;
		system("cls");
		put_member(&p4);
		cout<<"1.ȷ���޸�!"<<'\t'<<"2.�����޸�!"<<'\t'<<"3.�����޸�!"<<endl;
        n=0;
	    do{
	       do{
              c=getch();
              if(c==27){
                  if(n)cout<<endl;
                  cout<<"ȷ�Ϸ���?";char d;do{d=getch();if(d==13)return;}while(d!=27);system("cls");
                  put_member(&p4);
		          cout<<"1.ȷ���޸�!"<<'\t'<<"2.�����޸�!"<<'\t'<<"3.�����޸�!"<<endl;
                  continue;
                  }
              if(c==13)break;
              cout<<c;
              n=n*10+c-'0';
	       }while(1);
           if(n<1||n>3){cout<<endl<<"�������!������:";n=0;}
	   }while(!n);
	   cout<<endl;
	   if(n==1)
		{*p3=p4;
		panduan.insert(p3->student_number);
        save_student_date();
		cout<<"�޸ĳɹ�!�����������...";}
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
		    cout<<"�޸�ʧ��!�����������...";
		}
    }
 else cout<<"δ�ҵ���ѧ��!�밴���������...";
 getch();
}
void search_student()
{
loop:cout<<"��ѡ��鿴��ʽ:"<<endl;
	cout<<"1:����������ѧ�Ų鿴"<<endl;
	cout<<"2:����ɼ���Χ�鿴"<<endl;
	cout<<"3:����ѧԺ�鿴"<<endl;
	cout<<"4:����༶�鿴"<<endl;
	cout<<"5:ȫ���鿴"<<endl;
	cout<<"6:�������˵�"<<endl;
	__int64 number2=number;
	int n=0;
    char c;
	do{
	    do{
           c=getch();
           if(c==27){
               if(c==27){
                   if(n)cout<<endl;
                  cout<<"ȷ�Ϸ���?"<<endl;char d;do{d=getch();if(d==13)return;}while(d!=27);system("cls");
                  goto loop;
                  }
               }
           if(c==13)break;
           cout<<c;
           n=n*10+c-'0';
	      }while(1);
        if(n<1||n>6){cout<<endl<<"�������!������:";n=0;}
	}while(!n);
system("cls");
switch(n)
{
case 1:
{
	cout<<"������ѧ�Ż�����:";
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
	}if(!a){cout<<"δ�ҵ���ѧ��!�밴���������...";getch();system("cls");goto loop;}
	 else {cout<<"��ѯ�ɹ�!�밴���������...";getch();system("cls");goto loop;}
};break;
case 2:
{
	cout<<"������ѧ��(����ѧ)���ܷ�:";
	string stu;
	cin>>stu;
    bool a=false;
    extern double grade1,grade2;
	cout<<"��������С����:";
	cin>>grade1;
	cout<<endl<<"������������:";
	cin>>grade2;
	if(cin.fail()||grade2<grade1)
	{
		cin.clear();
		cin.sync();
		cout<<"�������,������!"<<endl;
		cout<<"��������С����:";
		cin>>grade1;
		cout<<endl<<"������������:";
		cin>>grade2;
	}
	system("cls");
	if(stu=="c++")
      {
	     a=scope_c(head,head,0,number);
      }
   else
	  if(stu=="����")
	  {
		 a=scope_chinese(head,head,0,number);
      }
      else
        if(stu=="��ѧ")
  		  {
			 a=scope_math(head,head,0,number);
	      }
	  else
	    if(stu=="Ӣ��")
  		  {
			 a=scope_english(head,head,0,number);
		  }
     else
       if(stu=="��ɢ")
         {
		     a=scope_lisan(head,head,0,number);
		 }
      else
        if(stu=="�����߼�")
  		  {
			 a=scope_szlj(head,head,0,number);
		  }
     else
       if(stu=="����")
  		  {
			 a=scope_sport(head,head,0,number);
		  }
     else
       if(stu=="���˼")
         {
		    a=scope_makesi(head,head,0,number);
		 }
       else
         if(stu=="�ܷ�"||stu=="�ܷ���"||stu=="�ܳɼ�"||stu=="zongfen"||stu=="zongfenshu"||stu=="zongchengji")
         {
		    a=scope_all(head,head,0,number);
		 }
		 else
		 {cout<<"�޴�ѧ��!�밴���������...";getch();system("cls");goto loop;}
		if(!a){cout<<"�˷����η�Χ����ѧ��!�밴���������...";getch();system("cls");goto loop;}
		else {cout<<"��ѯ�ɹ�!�밴���������...";getch();system("cls");goto loop;}
};break;
case 3:
{
	cout<<"������ѧԺ:";
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
   if(!a){cout<<"�޴�ѧԺ��ѧ��!�밴���������...";getch();system("cls");goto loop;}
   else {cout<<"��ѯ�ɹ�!�밴���������...";getch();system("cls");goto loop;}
};break;
case 4:
{
    cout<<"������༶:";
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
	if(!a){cout<<"�޴˰༶��ѧ��!�밴���������...";getch();system("cls");goto loop;}
	else {cout<<"��ѯ�ɹ�!�밴���������...";getch();system("cls");goto loop;}
};break;
case 5:
{
    cout<<"����������(��:��ѧ,�ܷ�)��ѧ�ƻ��ֽܷ������:";
    string stul;
    cin>>stul;
    system("cls");
	bool a=false;
    if(stul=="c++")
      {
      	a=paixu_c(head,head,0,number);
      }
   else
    if(stul=="����")
       {
      	  a=paixu_chinese(head,head,0,number);
	   }
   else
	 if(stul=="��ѧ")
       {
      	  a=paixu_math(head,head,0,number);
	   }
   else
	 if(stul=="Ӣ��")
       {
      	  a=paixu_english(head,head,0,number);
	   }
   else
	 if(stul=="��ɢ")
       {
      	  a=paixu_lisan(head,head,0,number);
	   }
   else
	 if(stul=="�����߼�")
       {
      	  a=paixu_szlj(head,head,0,number);
	   }
   else
	 if(stul=="����")
       {
      	  a=paixu_sport(head,head,0,number);
	   }
   else
	 if(stul=="���˼")
       {
      	  a=paixu_makesi(head,head,0,number);
	   }
    else
      if(stul=="�ܷ�"||stul=="�ܷ���"||stul=="�ܳɼ�"||stul=="zongfen"||stul=="zongfenshu"||stul=="zongchengji")
       {
      	  a=paixu_all(head,head,0,number);
	   }
      else
       {cout<<"�޴�ѧ��!�밴���������...";getch();system("cls");goto loop;}
	if(!a){cout<<"��ϵͳ��δ����ѧ����Ϣ!�밴���������...";getch();system("cls");goto loop;}
	else {cout<<"��ѯ�ɹ�!�밴���������...";getch();system("cls");goto loop;}
};break;
case 6:;
}
}
void delete_student()
{
  student *p3=search();
  if(p3!=NULL)
  {
    cout<<"1.ȷ��ɾ��!"<<'\t'<<"2.����ɾ��!"<<endl;
    int n=0;
    char c;
	do{
	    do{
           c=getch();
           if(c==27){
               if(c==27){
                  cout<<"ȷ�Ϸ���?"<<endl;char d;do{d=getch();if(d==13)return;}while(d!=27);system("cls");
                  put_member(p3);
                  cout<<"1.ȷ��ɾ��!"<<'\t'<<"2.����ɾ��!"<<endl;
                  continue;
                  }
               }
           if(c==13)break;
           cout<<c;
           n=n*10+c-'0';
	      }while(1);
        if(n<1||n>2){cout<<endl<<"�������!������:";n=0;}
	}while(!n);
	cout<<endl;
  if(n==1)
  {p3->next2->next1=p3->next1;
  p3->next1->next2=p3->next2;
  panduan.erase(panduan.find(p3->student_number));
  delete(p3);
  save_student_number(-1);
  save_student_date();
  cout<<"ɾ���ɹ�!�밴���������...";}
  else
   {
      cout<<"ɾ��ʧ��!�밴���������..."<<endl;
   }
  }
else cout<<"�޴�ѧ��!�밴���������...";
getch();
}
void main_menu()
{
    cout<<"�������������(��ϵͳ֧�ְ�Esc������):"<<endl;
	cout<<"1:�½�ѧ����Ϣ"<<endl<<endl;
	cout<<"2:�޸�ѧ����Ϣ"<<endl<<endl;
	cout<<"3:�鿴ѧ����Ϣ"<<endl<<endl;
	cout<<"4:ɾ��ѧ����Ϣ"<<endl<<endl;
	cout<<"5:���沢�˳�ϵͳ"<<endl;
	int n=0;
	char c;
	do{
	    do{
        c=getch();
       if(c==27){system("cls");end11();_sleep(1500);exit(0);}
       if(c==13)break;
       cout<<c;
       n=n*10+c-'0';}while(1);
       if(n<1||n>5){cout<<endl<<"�������!������:";n=0;}
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
		head->next1=p;//����˫��������������
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
/*����:������ӿ�Ч������ʹ��˫������������в����жϵĴ��붼Ҫ˫�ݣ���ǰ���Һ������ң�
���������ʱ��û�а������˳�������������ǰ����һ�����Ȼ����������һ������������鷳����
�Ժ����õ��������STL�е������������⡣*/

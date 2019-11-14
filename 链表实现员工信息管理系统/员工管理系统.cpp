#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
int num=0;
class date
{
	public:
	int year;
	int month;
	int date_;
};
class Employee
{
	public:
	//protected:
	__int64 number;
	string name;
	string sex;
	date year_month;
	string postion;
	string pay;
	//public:
	Employee()
	{}
	void new_member(){}
	void amend_member(){}
	void look_member(){}
	void delete_member(){}
};

class Technician:public Employee
{
	public:
	//protected:
	double time;
};
class saleman:public Technician
{
	public:
	//private:
	__int64 sale;
	string department;
	//public:
	void new_member();
	void amend_member();
	void display();
    void lead_member();
	 //friend void lead_person();
};
vector<saleman>person;
vector<saleman>::iterator j;
void saleman::lead_member()
{
	ifstream infile1;
	infile1.open("员工信息.txt");
	infile1>>number>>name>>sex>>year_month.year>>year_month.month>>year_month.date_;
	infile1>>postion>>pay>>time>>sale>>department;
	infile1.close();
}
void lead_num(int sum)
{
	num+=sum;
	ofstream onfile1;
	onfile1.open("员工人数.txt");
	onfile1<<num;
	onfile1.close();
}
void lead_person()
{
	ofstream onfile2;
	onfile2.open("员工信息.txt");
	for(j=person.begin();j!=person.end();j++)
	{
	    onfile2<<j->number<<' '<<j->name<<' '<<j->sex<<' '<<j->year_month.year<<' '<<j->year_month.month<<' ';
	    onfile2<<j->year_month.date_<<' '<<j->postion<<' '<<j->pay<<' '<<j->time<<' '<<j->sale<<' '<<j->department<<endl;
	}
	onfile2.close();
}
void saleman::new_member()
{
	cout<<"请输入员工号码:";
	cin>>number;
	cin.clear();
	cin.sync();
	cout<<endl<<"请输入员工姓名:";
	cin>>name;
	cout<<endl<<"请输入员工性别:";
	cin>>sex;
	cout<<endl<<"请输入员工出生年份:";
	cin>>year_month.year;
	cout<<endl<<"请输入员工出生月份:";
	cin>>year_month.month;
	cout<<endl<<"请输入员工出生日期:";
	cin>>year_month.date_;
	cout<<endl<<"请输入员工职位:";
	cin>>postion;
	cout<<endl<<"请输入员工薪水:";
	cin>>pay;
	cout<<endl<<"请输入工作时间";
	cin>>time;
	cout<<endl<<"请输入销售业绩(金额):";
	cin>>sale;
	cout<<endl<<"请输入所属部门:";
	cin>>department; 
	cout<<"确认添加?";
	getch();
	cout<<endl<<"添加成功!";
}
void saleman::amend_member()
{
	cout<<"请选择所需修改的信息:";
	cout<<"1.编号"<<"2.姓名"<<"3.性别"<<"4.出生年份"<<"5.出生月份"<<"6.出生日期";
	cout<<"7.职位"<<"8.薪水"<<"9.工作时间"<<"10.销售业绩"<<"11.所属部门"<<endl;
	int m;
	cin>>m;
	cin.clear();
	cin.sync();
	system("cls");
	switch(m)
	{
		case 1:cout<<"请输入新编号:";cin>>number;cout<<"确认修改?";getch();cout<<"修改成功!";break;
		case 2:cout<<"请输入新姓名:";cin>>name;cout<<"确认修改?";getch();cout<<"修改成功!";break;
		case 3:cout<<"请输入新性别:";cin>>sex;cout<<"确认修改?";getch();cout<<"修改成功!";break;
		case 4:cout<<"请输入新年份:";cin>>year_month.year;cout<<"确认修改?";getch();cout<<"修改成功!";break;
		case 5:cout<<"请输入新月份:";cin>>year_month.month;cout<<"确认修改?";getch();cout<<"修改成功!";break;
		case 6:cout<<"请输入新日期:";cin>>year_month.date_;cout<<"确认修改?";getch();cout<<"修改成功!";break;
		case 7:cout<<"请输入新职位:";cin>>postion;cout<<"确认修改?";getch();cout<<"修改成功!";break;
		case 8:cout<<"请输入新薪水:";cin>>pay;cout<<"确认修改?";getch();cout<<"修改成功!";break;
		case 9:cout<<"请输入新工作时间:";cin>>time;cout<<"确认修改?";getch();cout<<"修改成功!";break;
		case 10:cout<<"请输入新销售业绩(金额):";cin>>sale;cout<<"确认修改?";getch();cout<<"修改成功!";break;
		case 11:cout<<"请输入新所属部门:";cin>>department;cout<<"确认修改?";getch();cout<<"修改成功!";break;
		default:cout<<"输入错误!"<<endl;
	}
}
void saleman::display()
{
	cout<<"员工号码:"<<number<<endl<<endl;
	cout<<"员工姓名:"<<name<<endl<<endl;
	cout<<"员工性别:"<<sex<<endl<<endl;
	cout<<"员工出生年份:"<<year_month.year<<'/'<<year_month.month<<'/'<<year_month.date_<<endl<<endl;
	cout<<"员工职位:"<<postion<<endl<<endl;
	cout<<"员工薪水:"<<pay<<endl<<endl;
	cout<<"工作时间"<<time<<endl<<endl;
	cout<<"销售业绩(金额):"<<sale<<endl<<endl;
	cout<<"所属部门:"<<department<<endl;
}
void menue()
{
	cout<<"欢迎使用星夜永恒简易员工信息管理系统"<<endl;
	cout<<"请选择所需功能:"<<endl;
	cout<<"1:新建员工信息"<<endl;
	cout<<"2:修改员工信息"<<endl;
	cout<<"3:查看员工信息"<<endl;
	cout<<"4:删除员工信息"<<endl;
	cout<<"5:保存并退出"<<endl;
	int n;
	cin>>n;
	cin.clear();
	cin.sync();
	system("cls");
	switch(n)
	{
		case 1:
		{
		  saleman man;
		  man.new_member();
		  person.push_back(man);
		  lead_num(1);
		  lead_person();
		};break;
		case 3:
		{
			cout<<"请输入查看方式:"<<endl;
			cout<<"1.全部查看"<<endl;
			cout<<"2.按员工编号或姓名查看"<<endl;
			int m;
			bool summ=false;
			cin>>m;
			cin.clear();
			cin.sync();
			if(m==1)
			{
				for(int i=0;i<person.size();i++)
				{
				person[i].display();
				summ=true;
				}
				if(!summ)cout<<"该系统还未添加任何员工!"<<endl;
			}
			else
			if(m==2)
			{
				cout<<"请输入员工编号或姓名:";
				int n1;
				string name1;
				cin>>n1;
				if(cin.fail())
				{
					cin.clear();
					cin>>name1;
					cin.sync();
					for(int i=0;i<person.size();i++)
				    if(person[i].name==name1)
				    {
					person[i].display();
					summ=true;
					}
				}
				else
			{
				for(int i=0;i<person.size();i++)
				if(person[i].number==n1)
				{
				person[i].display();
				summ=true;
				}
				if(!summ)cout<<"没有找到此人!"<<endl;
			}
		}
		else
			cout<<"输入错误!";
	};break;
		case 2:
		{
			cout<<"请输入员工编号或姓名"<<endl;
			int n1;
			string name1;
			cin>>n1;
			if(cin.fail())
			{
			cin.clear();
			cin>>name1;
			cin.sync();
			for(int i=0;i<person.size();i++)
            if(person[i].name==name1)
            {
			person[i].display();
			person[i].amend_member();
            }
			}
			else
			for(int i=0;i<person.size();i++)
			if(person[i].number==n1)
			{
			person[i].display();
			person[i].amend_member();
			}
		};break;
		case 4:
		{
			cout<<"请输入员工编号或姓名:";
			j=person.begin();
			int n1;
			string name1;
			cin>>n1;
			system("cls");
			if(cin.fail())
			{
			cin.clear();
			cin>>name1;
		    cin.sync();
			for(int i=0;i<person.size();i++,j++)
            if(person[i].name==name1)
            {
			person[i].display();
			cout<<"确认删除?"<<endl;
			getch();
			person.erase(j);
			lead_num(-1);
			lead_person();
			cout<<"删除成功!"<<endl;
			}
			}
			else
			for(int i=0;i<person.size();i++,j++)
			if(person[i].number==n1)
			{
			person[i].display();
			cout<<"确认删除?"<<endl;
			getch();
			person.erase(j);
			lead_num(-1);
			lead_person();
			cout<<"删除成功!"<<endl;
			}
		};break;
		case 5:exit(0);
		default:cout<<"输入错误!";
	} 
	cout<<"按任意键返回...";
	getch();
	system("cls");
	menue();
}
int main()
{
	cout<<"欢迎欢迎，热烈欢迎，祝您天天好心情";
	_sleep(2000);
	system("cls");
	ifstream infile2;
	infile2.open("员工人数.txt"); 
	infile2>>num;
	infile2.close();
	for(int i=0;i<num;i++)
	{
		saleman a;
		a.lead_member();
		person.push_back(a);
	}
	menue();
}

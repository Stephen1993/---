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
	infile1.open("Ա����Ϣ.txt");
	infile1>>number>>name>>sex>>year_month.year>>year_month.month>>year_month.date_;
	infile1>>postion>>pay>>time>>sale>>department;
	infile1.close();
}
void lead_num(int sum)
{
	num+=sum;
	ofstream onfile1;
	onfile1.open("Ա������.txt");
	onfile1<<num;
	onfile1.close();
}
void lead_person()
{
	ofstream onfile2;
	onfile2.open("Ա����Ϣ.txt");
	for(j=person.begin();j!=person.end();j++)
	{
	    onfile2<<j->number<<' '<<j->name<<' '<<j->sex<<' '<<j->year_month.year<<' '<<j->year_month.month<<' ';
	    onfile2<<j->year_month.date_<<' '<<j->postion<<' '<<j->pay<<' '<<j->time<<' '<<j->sale<<' '<<j->department<<endl;
	}
	onfile2.close();
}
void saleman::new_member()
{
	cout<<"������Ա������:";
	cin>>number;
	cin.clear();
	cin.sync();
	cout<<endl<<"������Ա������:";
	cin>>name;
	cout<<endl<<"������Ա���Ա�:";
	cin>>sex;
	cout<<endl<<"������Ա���������:";
	cin>>year_month.year;
	cout<<endl<<"������Ա�������·�:";
	cin>>year_month.month;
	cout<<endl<<"������Ա����������:";
	cin>>year_month.date_;
	cout<<endl<<"������Ա��ְλ:";
	cin>>postion;
	cout<<endl<<"������Ա��нˮ:";
	cin>>pay;
	cout<<endl<<"�����빤��ʱ��";
	cin>>time;
	cout<<endl<<"����������ҵ��(���):";
	cin>>sale;
	cout<<endl<<"��������������:";
	cin>>department; 
	cout<<"ȷ�����?";
	getch();
	cout<<endl<<"��ӳɹ�!";
}
void saleman::amend_member()
{
	cout<<"��ѡ�������޸ĵ���Ϣ:";
	cout<<"1.���"<<"2.����"<<"3.�Ա�"<<"4.�������"<<"5.�����·�"<<"6.��������";
	cout<<"7.ְλ"<<"8.нˮ"<<"9.����ʱ��"<<"10.����ҵ��"<<"11.��������"<<endl;
	int m;
	cin>>m;
	cin.clear();
	cin.sync();
	system("cls");
	switch(m)
	{
		case 1:cout<<"�������±��:";cin>>number;cout<<"ȷ���޸�?";getch();cout<<"�޸ĳɹ�!";break;
		case 2:cout<<"������������:";cin>>name;cout<<"ȷ���޸�?";getch();cout<<"�޸ĳɹ�!";break;
		case 3:cout<<"���������Ա�:";cin>>sex;cout<<"ȷ���޸�?";getch();cout<<"�޸ĳɹ�!";break;
		case 4:cout<<"�����������:";cin>>year_month.year;cout<<"ȷ���޸�?";getch();cout<<"�޸ĳɹ�!";break;
		case 5:cout<<"���������·�:";cin>>year_month.month;cout<<"ȷ���޸�?";getch();cout<<"�޸ĳɹ�!";break;
		case 6:cout<<"������������:";cin>>year_month.date_;cout<<"ȷ���޸�?";getch();cout<<"�޸ĳɹ�!";break;
		case 7:cout<<"��������ְλ:";cin>>postion;cout<<"ȷ���޸�?";getch();cout<<"�޸ĳɹ�!";break;
		case 8:cout<<"��������нˮ:";cin>>pay;cout<<"ȷ���޸�?";getch();cout<<"�޸ĳɹ�!";break;
		case 9:cout<<"�������¹���ʱ��:";cin>>time;cout<<"ȷ���޸�?";getch();cout<<"�޸ĳɹ�!";break;
		case 10:cout<<"������������ҵ��(���):";cin>>sale;cout<<"ȷ���޸�?";getch();cout<<"�޸ĳɹ�!";break;
		case 11:cout<<"����������������:";cin>>department;cout<<"ȷ���޸�?";getch();cout<<"�޸ĳɹ�!";break;
		default:cout<<"�������!"<<endl;
	}
}
void saleman::display()
{
	cout<<"Ա������:"<<number<<endl<<endl;
	cout<<"Ա������:"<<name<<endl<<endl;
	cout<<"Ա���Ա�:"<<sex<<endl<<endl;
	cout<<"Ա���������:"<<year_month.year<<'/'<<year_month.month<<'/'<<year_month.date_<<endl<<endl;
	cout<<"Ա��ְλ:"<<postion<<endl<<endl;
	cout<<"Ա��нˮ:"<<pay<<endl<<endl;
	cout<<"����ʱ��"<<time<<endl<<endl;
	cout<<"����ҵ��(���):"<<sale<<endl<<endl;
	cout<<"��������:"<<department<<endl;
}
void menue()
{
	cout<<"��ӭʹ����ҹ�������Ա����Ϣ����ϵͳ"<<endl;
	cout<<"��ѡ�����蹦��:"<<endl;
	cout<<"1:�½�Ա����Ϣ"<<endl;
	cout<<"2:�޸�Ա����Ϣ"<<endl;
	cout<<"3:�鿴Ա����Ϣ"<<endl;
	cout<<"4:ɾ��Ա����Ϣ"<<endl;
	cout<<"5:���沢�˳�"<<endl;
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
			cout<<"������鿴��ʽ:"<<endl;
			cout<<"1.ȫ���鿴"<<endl;
			cout<<"2.��Ա����Ż������鿴"<<endl;
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
				if(!summ)cout<<"��ϵͳ��δ����κ�Ա��!"<<endl;
			}
			else
			if(m==2)
			{
				cout<<"������Ա����Ż�����:";
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
				if(!summ)cout<<"û���ҵ�����!"<<endl;
			}
		}
		else
			cout<<"�������!";
	};break;
		case 2:
		{
			cout<<"������Ա����Ż�����"<<endl;
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
			cout<<"������Ա����Ż�����:";
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
			cout<<"ȷ��ɾ��?"<<endl;
			getch();
			person.erase(j);
			lead_num(-1);
			lead_person();
			cout<<"ɾ���ɹ�!"<<endl;
			}
			}
			else
			for(int i=0;i<person.size();i++,j++)
			if(person[i].number==n1)
			{
			person[i].display();
			cout<<"ȷ��ɾ��?"<<endl;
			getch();
			person.erase(j);
			lead_num(-1);
			lead_person();
			cout<<"ɾ���ɹ�!"<<endl;
			}
		};break;
		case 5:exit(0);
		default:cout<<"�������!";
	} 
	cout<<"�����������...";
	getch();
	system("cls");
	menue();
}
int main()
{
	cout<<"��ӭ��ӭ�����һ�ӭ��ף�����������";
	_sleep(2000);
	system("cls");
	ifstream infile2;
	infile2.open("Ա������.txt"); 
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

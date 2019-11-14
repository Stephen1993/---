#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>//使用getch()所需的函数,getch()功能为按下任意键后执行下一步语句.
using namespace std;
struct phone_book//电话本结构体
{
	string name;
	string sex;
	__int64 telephone;
	string home_address;
	string email;
	string constellation;
	__int64 QQnumber;
	phone_book *next;//指针，用来指向下一个变量
};
void main_menu(phone_book *head);//主菜单函数
void write_date(phone_book *head);//将数据写入文件的函数
void write_number(__int64 num);//将联系人数量写入文件
void put_member(phone_book *s);//输出函数
__int64 number=0;//number用来记录联系人人数
void write_date(phone_book *head)
{
	phone_book *p=head;
	ofstream onfile;//定义打开文件的变量
	onfile.open("date.txt");//打开文件
	while(p->next!=NULL)//从头指针指向的联系人开始直到最后一个联系人(最后一个联系人的指针指向NULL)导入到文件
	{
		p=p->next;
		onfile<<p->name<<'\t'<<p->sex<<'\t'<<p->telephone<<'\t';
		onfile<<p->home_address<<'\t'<<p->email<<'\t'<<p->constellation<<'\t';
		onfile<<p->QQnumber<<endl;
	}
	onfile.close();//关闭文件
}
void write_number(__int64 num)
{
	number+=num;//新增联系人则传递1过来，即num=1,number增加1.
	ofstream onfile1;
	onfile1.open("number.txt");
	onfile1<<number;
	onfile1.close();
}
void put_member(phone_book *s)
{
	cout<<"姓名:"<<s->name<<endl<<endl;
	cout<<"性别:"<<s->sex<<endl<<endl;
	cout<<"电话号码:"<<s->telephone<<endl<<endl;
	cout<<"家庭住址:"<<s->home_address<<endl<<endl;
	cout<<"邮件箱:"<<s->email<<endl<<endl;
	cout<<"星座:"<<s->constellation<<endl<<endl;
	cout<<"QQ:"<<s->QQnumber<<endl<<endl;
}
void new_member(phone_book *head)//新建联系人
{
	phone_book *p;
	p=new phone_book;
	cout<<"请输入姓名:";
	cin>>p->name;
	cout<<endl<<"请输入性别:";
	cin>>p->sex;
	while(p->sex!="男"&&p->sex!="女")
	    {
    		cout<<"输入错误!请重输...";
    		cout<<endl<<"请输入性别:";
			cin>>p->sex;
    	}
	cout<<endl<<"请输入电话号码:";
	cin>>p->telephone;
	while(cin.fail()){
		cout<<"输入错误，请重输...";
		cin.clear();
		cin.sync();
		getch();
		system("cls");
		cout<<"请输入姓名:";
	    cout<<p->name;
	    cout<<endl<<endl<<"请输入性别:";
	    cout<<p->sex;
	    cout<<endl<<endl<<"请输入电话号码:";
	    cin>>p->telephone;
	}
	cout<<endl<<"请输入家庭住址:";
	cin>>p->home_address;
	cout<<endl<<"请输入邮件箱:";
	cin>>p->email;
	cout<<endl<<"请输入星座:";
	cin>>p->constellation;
	cout<<endl<<"请输入QQ:";
	cin>>p->QQnumber;
	while(cin.fail()){
		cout<<"输入错误，请重输...";
		cin.clear();
		cin.sync();
		getch();
		system("cls");
		cout<<"请输入姓名:";
	    cout<<p->name;
	    cout<<endl<<endl<<"请输入性别:";
	    cout<<p->sex;
		cout<<endl<<endl<<"请输入电话号码:";
	    cout<<p->telephone;
	    cout<<endl<<endl<<"请输入家庭住址:";
	    cout<<p->home_address;
	    cout<<endl<<endl<<"请输入邮件箱:";
	    cout<<p->email;
	    cout<<endl<<endl<<"请输入星座:";
 	    cout<<p->constellation;
	    cout<<endl<<endl<<"请输入QQ:";
	    cin>>p->QQnumber;

	}
	cout<<"确认添加?"<<endl;
	getch();
	write_number(1);
	p->next=head->next;
	head->next=p;
	write_date(head);
	cout<<"添加联系人成功"<<endl;
	cout<<"按任意键返回主菜单..." ;
}
void amend_member(phone_book *head)
{
	bool a=false;
	phone_book *p=head;
	string name1;
	__int64 telephone1,n=0,m=0,x1=0,x2=0;
	cout<<"请输入名字或电话号码选择联系人:";
	cin>>telephone1;
	if(cin.fail())
	{
		cin.clear();
		cin>>name1;
		cin.sync();
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->name==name1)
			{
			   n++;
			   a=true;
			   cout<<n<<"."<<endl;
			   put_member(p);
            }
		}
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->telephone==telephone1)
			{
				m++;
				a=true;
				cout<<m<<"."<<endl;
				put_member(p);
			}
		}
	}
	if(a)
	{
		if(n>1){
			cout<<"请输入编号选择联系人:";
			int x;
			cin>>x;
			system("cls");
			p=head;
			while(p->next!=NULL)
		{
			p=p->next;
			if(p->name==name1)
			{
			   x1++;
			   if(x1==x)
			   {
			   put_member(p);
			   break;
			   }
            }
		}
		}
		if(m>1){
			cout<<"请按编号选择联系人:";
			int x;
			cin>>x;
			system("cls");
			p=head;
			while(p->next!=NULL)
		{
			p=p->next;
			if(p->telephone==telephone1)
			{
				x2++;
				if(x2==x)
				{
				put_member(p);
				break;
				}
			}
		}
	}
		cout<<"请选择修改信息:"<<"1.姓名"<<"2.性别"<<"3.电话号码"<<"4.家庭住址"<<"5.邮箱"<<"6.星座"<<"7.QQ"<<endl;
		int n;
		cin>>n;
		while(cin.fail()||(n<1||n>7)){
			cout<<"输入错误，请重输:";
			cin.clear();
		    cin.sync();
		    cin>>n;
		}
		switch(n)
		{
			case 1:cout<<"请输入新姓名:";cin>>p->name;break;
			case 2:cout<<"请输入新性别:";cin>>p->sex;break;
			case 3:cout<<"请输入新电话号码:";cin>>p->telephone;cin.clear();cin.sync();break;
			case 4:cout<<"请输入新家庭住址:";cin>>p->home_address;break;
			case 5:cout<<"请输入新邮箱:";cin>>p->email;break;
			case 6:cout<<"请输入新星座:";cin>>p->constellation;cin.clear();cin.sync();break;
			case 7:cout<<"请输入新QQ:";cin>>p->QQnumber;break;
		}
		system("cls");
		put_member(p);
		cout<<"确认修改?";
		getch();
		write_date(head);
		cout<<endl<<"修改成功,按任意键返回...";
   }
   else cout<<"未找到此联系人...请按任意键返回!";
}
void delete_member(phone_book *head)
{
	bool b=false;
	phone_book *p,*s;
	p=head;
	string name1;
	__int64 telephone1;
	cout<<"请输入名字或电话号码选择需要删除的联系人:";
	cin>>telephone1;
	if(cin.fail())
	{
		cin.clear();
		cin>>name1;
		cin.sync();
		while(p->next!=NULL)
		{
			s=p;
			p=p->next;
			if(p->name==name1)
			{
			   b=true;
			   put_member(p);
			   cout<<"确认删除?";
			   cin.get();
			   s->next=p->next;
			   delete(p);
			   write_date(head);
			   write_number(-1);
			   cout<<"删除成功...请按任意键返回!";
			   break;
            }
		}
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->telephone==telephone1)
			{
				b=true;
				put_member(p);
			    cout<<"确认删除?";
			    cin.get();
				s->next=p->next;
			    delete(p);
			    write_date(head);
			    write_number(-1);
			    cout<<"删除成功...请按任意键返回!";
				break;
			}
		}
	}
	if(!b)cout<<"不存在此联系人...请按任意键返回!";
}
void search_member(phone_book *head)
{
	phone_book *p;
	bool m=false;
	p=head;
	string name1;
	__int64 telephone1,n=0;
	cout<<"请输入名字或电话号码查看联系人:";
	cin>>telephone1;
	if(cin.fail())
	{
		cin.clear();
		cin>>name1;
		cin.sync();
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->name==name1)
			{
			   n++;
			   cout<<n<<'.'<<endl;
			   m=true;
			   put_member(p);
  	        }
		}
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->telephone==telephone1)
			{
				n++;
				cout<<n<<'.'<<endl;
				m=true;
				put_member(p);
			}
		}
	}
	if(!m)cout<<"不存在此联系人...请按任意键返回!";
	else cout<<"请按任意键返回!";
}
void main_menu(phone_book *head)
{
	cout<<"欢迎使用星夜永恒牌简易电话本"<<endl;
	cout<<"请输入需要实现的功能"<<endl;
	cout<<"1:新建联系人"<<endl;
	cout<<"2:修改联系人信息"<<endl;
	cout<<"3:删除联系人"<<endl;
	cout<<"4:查找联系人"<<endl;
	cout<<"5:查看所有联系人"<<endl;
	cout<<"6:退出并保存"<<endl;
	int n;
	cin>>n;
	cin.clear();
	cin.ignore();
	system("cls");
	switch(n)
	{
		case 1:new_member(head);break;
		case 2:amend_member(head);break;
		case 3:delete_member(head);break;
		case 4:search_member(head);break;
		case 5:phone_book *d=head;cout<<"存在"<<number<<"位联系人"<<endl;for(int i=1;i<=number;i++)
		{cout<<i<<":"<<endl;d=d->next;put_member(d);};cout<<"请按任意键返回主菜单...";break;
		case 6:cout<<"谢谢使用!"<<endl;exit(0);
        default:cout<<"输入错误，请按任意键返回主菜单...";
	}
	getch();
	system("cls");
	main_menu(head);
}
int main()
{
    ifstream infile;
	phone_book *head=new phone_book,*s;
	head->next=NULL;
	s=head;
	phone_book *p;
	infile.open("number.txt");
	infile>>number;
	infile.close();
	ifstream infile2;
	infile2.open("date.txt");
	for(int i=1;i<=number;i++)
	{
		p=new phone_book;
		infile2>>p->name>>p->sex>>p->telephone>>p->home_address>>p->email>>p->constellation>>p->QQnumber;
		p->next=NULL;
		s->next=p;
		s=p;
	}
	infile2.close();
	main_menu(head);
	return 0;
}

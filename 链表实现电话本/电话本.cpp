#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>//ʹ��getch()����ĺ���,getch()����Ϊ�����������ִ����һ�����.
using namespace std;
struct phone_book//�绰���ṹ��
{
	string name;
	string sex;
	__int64 telephone;
	string home_address;
	string email;
	string constellation;
	__int64 QQnumber;
	phone_book *next;//ָ�룬����ָ����һ������
};
void main_menu(phone_book *head);//���˵�����
void write_date(phone_book *head);//������д���ļ��ĺ���
void write_number(__int64 num);//����ϵ������д���ļ�
void put_member(phone_book *s);//�������
__int64 number=0;//number������¼��ϵ������
void write_date(phone_book *head)
{
	phone_book *p=head;
	ofstream onfile;//������ļ��ı���
	onfile.open("date.txt");//���ļ�
	while(p->next!=NULL)//��ͷָ��ָ�����ϵ�˿�ʼֱ�����һ����ϵ��(���һ����ϵ�˵�ָ��ָ��NULL)���뵽�ļ�
	{
		p=p->next;
		onfile<<p->name<<'\t'<<p->sex<<'\t'<<p->telephone<<'\t';
		onfile<<p->home_address<<'\t'<<p->email<<'\t'<<p->constellation<<'\t';
		onfile<<p->QQnumber<<endl;
	}
	onfile.close();//�ر��ļ�
}
void write_number(__int64 num)
{
	number+=num;//������ϵ���򴫵�1��������num=1,number����1.
	ofstream onfile1;
	onfile1.open("number.txt");
	onfile1<<number;
	onfile1.close();
}
void put_member(phone_book *s)
{
	cout<<"����:"<<s->name<<endl<<endl;
	cout<<"�Ա�:"<<s->sex<<endl<<endl;
	cout<<"�绰����:"<<s->telephone<<endl<<endl;
	cout<<"��ͥסַ:"<<s->home_address<<endl<<endl;
	cout<<"�ʼ���:"<<s->email<<endl<<endl;
	cout<<"����:"<<s->constellation<<endl<<endl;
	cout<<"QQ:"<<s->QQnumber<<endl<<endl;
}
void new_member(phone_book *head)//�½���ϵ��
{
	phone_book *p;
	p=new phone_book;
	cout<<"����������:";
	cin>>p->name;
	cout<<endl<<"�������Ա�:";
	cin>>p->sex;
	while(p->sex!="��"&&p->sex!="Ů")
	    {
    		cout<<"�������!������...";
    		cout<<endl<<"�������Ա�:";
			cin>>p->sex;
    	}
	cout<<endl<<"������绰����:";
	cin>>p->telephone;
	while(cin.fail()){
		cout<<"�������������...";
		cin.clear();
		cin.sync();
		getch();
		system("cls");
		cout<<"����������:";
	    cout<<p->name;
	    cout<<endl<<endl<<"�������Ա�:";
	    cout<<p->sex;
	    cout<<endl<<endl<<"������绰����:";
	    cin>>p->telephone;
	}
	cout<<endl<<"�������ͥסַ:";
	cin>>p->home_address;
	cout<<endl<<"�������ʼ���:";
	cin>>p->email;
	cout<<endl<<"����������:";
	cin>>p->constellation;
	cout<<endl<<"������QQ:";
	cin>>p->QQnumber;
	while(cin.fail()){
		cout<<"�������������...";
		cin.clear();
		cin.sync();
		getch();
		system("cls");
		cout<<"����������:";
	    cout<<p->name;
	    cout<<endl<<endl<<"�������Ա�:";
	    cout<<p->sex;
		cout<<endl<<endl<<"������绰����:";
	    cout<<p->telephone;
	    cout<<endl<<endl<<"�������ͥסַ:";
	    cout<<p->home_address;
	    cout<<endl<<endl<<"�������ʼ���:";
	    cout<<p->email;
	    cout<<endl<<endl<<"����������:";
 	    cout<<p->constellation;
	    cout<<endl<<endl<<"������QQ:";
	    cin>>p->QQnumber;

	}
	cout<<"ȷ�����?"<<endl;
	getch();
	write_number(1);
	p->next=head->next;
	head->next=p;
	write_date(head);
	cout<<"�����ϵ�˳ɹ�"<<endl;
	cout<<"��������������˵�..." ;
}
void amend_member(phone_book *head)
{
	bool a=false;
	phone_book *p=head;
	string name1;
	__int64 telephone1,n=0,m=0,x1=0,x2=0;
	cout<<"���������ֻ�绰����ѡ����ϵ��:";
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
			cout<<"��������ѡ����ϵ��:";
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
			cout<<"�밴���ѡ����ϵ��:";
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
		cout<<"��ѡ���޸���Ϣ:"<<"1.����"<<"2.�Ա�"<<"3.�绰����"<<"4.��ͥסַ"<<"5.����"<<"6.����"<<"7.QQ"<<endl;
		int n;
		cin>>n;
		while(cin.fail()||(n<1||n>7)){
			cout<<"�������������:";
			cin.clear();
		    cin.sync();
		    cin>>n;
		}
		switch(n)
		{
			case 1:cout<<"������������:";cin>>p->name;break;
			case 2:cout<<"���������Ա�:";cin>>p->sex;break;
			case 3:cout<<"�������µ绰����:";cin>>p->telephone;cin.clear();cin.sync();break;
			case 4:cout<<"�������¼�ͥסַ:";cin>>p->home_address;break;
			case 5:cout<<"������������:";cin>>p->email;break;
			case 6:cout<<"������������:";cin>>p->constellation;cin.clear();cin.sync();break;
			case 7:cout<<"��������QQ:";cin>>p->QQnumber;break;
		}
		system("cls");
		put_member(p);
		cout<<"ȷ���޸�?";
		getch();
		write_date(head);
		cout<<endl<<"�޸ĳɹ�,�����������...";
   }
   else cout<<"δ�ҵ�����ϵ��...�밴���������!";
}
void delete_member(phone_book *head)
{
	bool b=false;
	phone_book *p,*s;
	p=head;
	string name1;
	__int64 telephone1;
	cout<<"���������ֻ�绰����ѡ����Ҫɾ������ϵ��:";
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
			   cout<<"ȷ��ɾ��?";
			   cin.get();
			   s->next=p->next;
			   delete(p);
			   write_date(head);
			   write_number(-1);
			   cout<<"ɾ���ɹ�...�밴���������!";
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
			    cout<<"ȷ��ɾ��?";
			    cin.get();
				s->next=p->next;
			    delete(p);
			    write_date(head);
			    write_number(-1);
			    cout<<"ɾ���ɹ�...�밴���������!";
				break;
			}
		}
	}
	if(!b)cout<<"�����ڴ���ϵ��...�밴���������!";
}
void search_member(phone_book *head)
{
	phone_book *p;
	bool m=false;
	p=head;
	string name1;
	__int64 telephone1,n=0;
	cout<<"���������ֻ�绰����鿴��ϵ��:";
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
	if(!m)cout<<"�����ڴ���ϵ��...�밴���������!";
	else cout<<"�밴���������!";
}
void main_menu(phone_book *head)
{
	cout<<"��ӭʹ����ҹ�����Ƽ��׵绰��"<<endl;
	cout<<"��������Ҫʵ�ֵĹ���"<<endl;
	cout<<"1:�½���ϵ��"<<endl;
	cout<<"2:�޸���ϵ����Ϣ"<<endl;
	cout<<"3:ɾ����ϵ��"<<endl;
	cout<<"4:������ϵ��"<<endl;
	cout<<"5:�鿴������ϵ��"<<endl;
	cout<<"6:�˳�������"<<endl;
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
		case 5:phone_book *d=head;cout<<"����"<<number<<"λ��ϵ��"<<endl;for(int i=1;i<=number;i++)
		{cout<<i<<":"<<endl;d=d->next;put_member(d);};cout<<"�밴������������˵�...";break;
		case 6:cout<<"ллʹ��!"<<endl;exit(0);
        default:cout<<"��������밴������������˵�...";
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

#include<iostream>
#include<cstdio>
#include<string>
#include<iomanip>
using namespace std;

const int Base=10000;
int op[3];//���������������Ǹ�����������,-1��ʾ���� 

struct List{
	short date;//��������-2^15~2^15-1 
	List *last,*next;
	List(){last=next=NULL;date=0;}
} *head[3];

void add(List *p1,List *p2){//���������,��������һ������ 
    while(p1 && p2){//ÿ�����ڵ�������
    	p1->date+=p2->date;
    	if(p1->date>=Base){//ÿ��dateֻ����λ��,�Ȳ�����10000,������λ 
	    	if(p1->next == NULL){p1->next=p2->next;p1->next->last=p1;}//p1��p2ʣ��ڵ����� 
	    	if(p1->next == NULL){p1->next=new List();p1->next->last=p1;}//����ȻΪ�����½��ڵ�
			p1->next->date+= p1->date/Base;
			p1->date%=Base;
	    }
	    p1=p1->next;
	    p2=p2->next;
    }
    if(p2)p1=p2;//p1��p2ʣ��ڵ�����
	while(p1 && p1->date>=Base){//��λ 
		if(p1->next == NULL){p1->next=new List();p1->next->last=p1;}//λ������:1+9999 = 1,0000 
		p1->next->date+= p1->date/Base;
		p1->date%=Base;
		p1=p1->next;
	} 
}

void sub(List *p1,List *p2){//�������,��������һ������ 
    while(p2){//ÿ�����ڵ�������
    	p1->date-=p2->date;
    	if(p1->date<0){ 
			-- p1->next->date;
			p1->date+=10;
	    }
	    p1=p1->next;
	    p2=p2->next;
    } 
}

bool trans(List *p,string s){//���ַ�����������ת��������ڵ�洢,��12,3456 =>3456 12�洢 
	int sum=0;
	List *temp;
	for(int i=0;s[i] != '\0';++i){
		if(s[i]>='0' && s[i]<='9')sum=sum*10+s[i]-'0';
		if(s[i] == ','){//ͷ�巨����ڵ� 
			temp=new List();
			temp->date=sum;
			temp->next=p->next;
			temp->last=p;
			if(p->next)p->next->last=temp;
			p->next=temp;
			sum=0;
		}
	}
	//�������һ���� 
	temp=new List();
	temp->date=sum;
	temp->next=p->next;
	temp->last=p;
	if(p->next)p->next->last=temp;
	p->next=temp;
}

void Input(int k){//������� 
	string s;
	getline(cin,s);
	trans(head[k],s);//������Ĵ���ת���������� 
	if(s[0] == '-')op[k]=-1;
	else op[k]=1;
}

void output(List* p){
	while(p->next)p=p->next;//���ǵ����ı���:12,3456 =>3456,12�������Ҫ�������,��Ѱ�ҵ�β��
	while(p->date == 0 && p->last != head[1])p=p->last;//ȥ��ǰ��Ϊ0 
	cout<<"�����:";
	if(op[1] == -1 && p->date)cout<<"-";//��ʾ����Ǹ��� 
	cout<<p->date;
	while(p->last != head[1]){p=p->last;cout<<","<<setfill('0')<<setw(4)<<p->date;}
	cout<<endl<<endl;
}

void Free(List *p){//�ͷ�ָ��ָ����ڴ� 
	while(p)head[0]=p->next,delete[] p,p=head[0];
}

bool cmp(List *p1,List *p2){
	int Id=0;
	while(p1 && p2){
		if(p1->date>p2->date)Id=1;
		if(p1->date<p2->date)Id=2;
		p1=p1->next;
		p2=p2->next;
	}
	if(p1 || (p2 == NULL && Id == 1))return true;//p1Ϊ���ʾ�����λ������,�������λ����ͬ��Id=1��ʾp1��������� 
	return false;
}

int main(){
	string n;
	do{
		head[1]=new List(),head[2]=new List();
		cout<<"��ѡ���ܣ�1���ӷ�(+) 2������(-)\n";
		getline(cin,n);
		if(n != "1" && n != "2"){cout<<"�������!\n";continue;}
		cout<<"�밴Ҫ�������һ������";
		Input(1);
		cout<<"�밴Ҫ������ڶ�������";
		Input(2);
		if(op[1]*op[2] == 1 && n == "1")add(head[1]->next,head[2]->next);//head[1]���� + head[2]���� 
		else{//head[1]���� - head[2]���� 
			if(cmp(head[2]->next,head[1]->next)){//�ж�head[1]���� �� head[2]�����ĸ��� 
				head[0]=head[1],head[1]=head[2],head[2]=head[0];//�൱��a>b��a-bʵ������-(b-a)
				op[1]*=-1;//ԭ����a - b����-(b-a)������ű�ɸ���,ԭ����-a+b����b-a������ű������ 
			}
			sub(head[1]->next,head[2]->next);
		}
		output(head[1]);
		Free(head[1]);//�ͷ�����ڵ� 
		Free(head[2]);
	}while(1);
	return 0;
}


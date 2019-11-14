#include<iostream>
#include<cstdio>
#include<string>
#include<iomanip>
using namespace std;

const int Base=10000;
int op[3];//标记输入的两个数是负数还是正数,-1表示负数 

struct List{
	short date;//存整型数-2^15~2^15-1 
	List *last,*next;
	List(){last=next=NULL;date=0;}
} *head[3];

void add(List *p1,List *p2){//大整数相加,结果存入第一个链表 
    while(p1 && p2){//每两个节点的数相加
    	p1->date+=p2->date;
    	if(p1->date>=Base){//每个date只存四位数,既不超过10000,超过进位 
	    	if(p1->next == NULL){p1->next=p2->next;p1->next->last=p1;}//p1与p2剩余节点连接 
	    	if(p1->next == NULL){p1->next=new List();p1->next->last=p1;}//若仍然为空则新建节点
			p1->next->date+= p1->date/Base;
			p1->date%=Base;
	    }
	    p1=p1->next;
	    p2=p2->next;
    }
    if(p2)p1=p2;//p1与p2剩余节点连接
	while(p1 && p1->date>=Base){//进位 
		if(p1->next == NULL){p1->next=new List();p1->next->last=p1;}//位数增加:1+9999 = 1,0000 
		p1->next->date+= p1->date/Base;
		p1->date%=Base;
		p1=p1->next;
	} 
}

void sub(List *p1,List *p2){//大数相减,结果存入第一个链表 
    while(p2){//每两个节点的数相加
    	p1->date-=p2->date;
    	if(p1->date<0){ 
			-- p1->next->date;
			p1->date+=10;
	    }
	    p1=p1->next;
	    p2=p2->next;
    } 
}

bool trans(List *p,string s){//将字符串大数倒序转换成链表节点存储,如12,3456 =>3456 12存储 
	int sum=0;
	List *temp;
	for(int i=0;s[i] != '\0';++i){
		if(s[i]>='0' && s[i]<='9')sum=sum*10+s[i]-'0';
		if(s[i] == ','){//头插法插入节点 
			temp=new List();
			temp->date=sum;
			temp->next=p->next;
			temp->last=p;
			if(p->next)p->next->last=temp;
			p->next=temp;
			sum=0;
		}
	}
	//插入最后一个数 
	temp=new List();
	temp->date=sum;
	temp->next=p->next;
	temp->last=p;
	if(p->next)p->next->last=temp;
	p->next=temp;
}

void Input(int k){//输入大数 
	string s;
	getline(cin,s);
	trans(head[k],s);//将输入的大数转换成链表储存 
	if(s[0] == '-')op[k]=-1;
	else op[k]=1;
}

void output(List* p){
	while(p->next)p=p->next;//数是倒序存的比如:12,3456 =>3456,12所以输出要倒序输出,先寻找到尾部
	while(p->date == 0 && p->last != head[1])p=p->last;//去除前导为0 
	cout<<"结果是:";
	if(op[1] == -1 && p->date)cout<<"-";//表示结果是负数 
	cout<<p->date;
	while(p->last != head[1]){p=p->last;cout<<","<<setfill('0')<<setw(4)<<p->date;}
	cout<<endl<<endl;
}

void Free(List *p){//释放指针指向的内存 
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
	if(p1 || (p2 == NULL && Id == 1))return true;//p1为真表示存的数位数更长,否则如果位数相同则Id=1表示p1存的数更大 
	return false;
}

int main(){
	string n;
	do{
		head[1]=new List(),head[2]=new List();
		cout<<"请选择功能：1：加法(+) 2：减法(-)\n";
		getline(cin,n);
		if(n != "1" && n != "2"){cout<<"输入错误!\n";continue;}
		cout<<"请按要求输入第一个数：";
		Input(1);
		cout<<"请按要求输入第二个数：";
		Input(2);
		if(op[1]*op[2] == 1 && n == "1")add(head[1]->next,head[2]->next);//head[1]的数 + head[2]的数 
		else{//head[1]的数 - head[2]的数 
			if(cmp(head[2]->next,head[1]->next)){//判断head[1]的数 和 head[2]的数哪个大 
				head[0]=head[1],head[1]=head[2],head[2]=head[0];//相当于a>b则a-b实际上是-(b-a)
				op[1]*=-1;//原来是a - b则变成-(b-a)结果符号变成负数,原来是-a+b则变成b-a结果符号变成正数 
			}
			sub(head[1]->next,head[2]->next);
		}
		output(head[1]);
		Free(head[1]);//释放链表节点 
		Free(head[2]);
	}while(1);
	return 0;
}


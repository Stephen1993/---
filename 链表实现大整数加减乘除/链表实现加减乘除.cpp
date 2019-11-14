#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#include<ctype.h>
#include"calculate.h"
#define INF 99999999
using namespace std;

const int MAX=10;

typedef struct stack{
	int *date;//存大数 
	char ch;
	int mark;//mark用来标记符号:正负
	stack *next;
	stack(){
		next=NULL,mark=1;
	}
};

typedef struct head{
	stack *top;
	int size;
	head(){
		top=NULL,size=0;
	}
	void push(stack* &p);
	void Clear();
	void Pop();
};
head stack_dou,stack_ch;//一个用来存数字,一个用来存运算符.

void output(stack* &p){
	cout<<"结果是:";
	int l=p->date[0];
	if(p->date[l] != 0 && p->mark == -1)cout<<"-";
	cout<<p->date[l];
	for(int i=l-1;i>=1;--i)cout<<setfill('0')<<setw(4)<<p->date[i];
	cout<<endl;
}

bool isoperator(char s){//判断运算符s是否符合条件. 
	if(s == '+' || s == '-' || s == '*' || s == '/' || s == '(' || s == ')')return true;
	return false;
}

void head::push(stack* &p){//元素入栈. 
	p->next=this->top;
	this->top=p;
	this->size++;
}

void head::Pop(){//删除栈顶元素. 
	stack *p=this->top;
	this->top=this->top->next;
	this->size--;
	delete p;
}

void head::Clear(){//清空栈. 
	while(this->top){
		stack *p=this->top;
		this->top=this->top->next;
		delete p;
	}
	this->size=0;
}

bool stack_dou_calculate(char s){//s代表运算符,对实数栈的栈顶两个元素进行运算. 
    if(stack_dou.size<2)return false;
	int *second=stack_dou.top->date,mark2=stack_dou.top->mark;
	stack_dou.top->date=NULL;stack_dou.Pop();
	int *first=stack_dou.top->date,mark1=stack_dou.top->mark;
	stack_dou.top->date=NULL;stack_dou.Pop();
	int *sum=new int[100];
	if(s == '+' && mark1*mark2 == 1 || 
	  (s == '-' && mark1*mark2 == -1))add(first,second,sum);//相加 
	if(s == '-' && mark1*mark2 == 1){//相减 
		if(cmp(first,second))sub(first,second,sum);
		else {sub(second,first,sum);mark1=-1*mark2;}
	}
	if(s == '+' && mark1*mark2 == -1){//相减 
		if(cmp(first,second))sub(first,second,sum);
		else {sub(second,first,sum);mark1=mark2;}
	}
	if(s == '*')mult(first,second,sum);//相乘 
	if(s == '/')div(first,second,sum);//相除 
	stack *p=new stack;
	p->date=sum;
	p->mark=mark1;
	stack_dou.push(p);
	delete first;
	delete second;
	return true;
}

bool cmp(char a,char b){//比较运算符a,b的优先级. 
	if(b == '+' || b == '-' || a== '*' || a == '/' || b == ')' || a == '(')return true;
	return false;
}

void calculate(string s){//计算表达式s. 
	string a;
	for(int i=0;i<s.size();++i){
		if(s[i] == ' '){if(a.size()){stack *p=new stack;p->date=new int[100];trans(a,p->date);stack_dou.push(p);a.clear();}continue;}
 		if(isdigit(s[i]))a+=s[i];
		else if(isoperator(s[i])){
			if(a.size()){stack *p=new stack;p->date=new int[100];trans(a,p->date);stack_dou.push(p);a.clear();}
			while(stack_ch.top && cmp(stack_ch.top->ch,s[i])){
				if(stack_ch.top->ch != '('){
					if(!stack_dou_calculate(stack_ch.top->ch))break;
					stack_ch.Pop();
				}
    	        else {stack_ch.Pop();break;}
			}
			if(s[i] != ')'){stack *p=new stack;p->ch=s[i];stack_ch.push(p);}
		}
		else{cout<<"输入错误,请重输!\n";return;}
	}
	if(a.size()){stack *p=new stack;p->date=new int[100];trans(a,p->date);stack_dou.push(p);a.clear();}
	while(stack_ch.top){
		if(!stack_dou_calculate(stack_ch.top->ch))break;
		stack_ch.Pop();
	}
	if(stack_dou.size == 1 && stack_ch.size == 0)
	    output(stack_dou.top);
	else cout<<"输入错误,请重输!\n";
}

string ClearDouHao(string s){
	string tempString="\0";
	for(int i=0;s[i] != '\0';++i){
		if((s[i]>='0' && s[i]<='9') || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			tempString+=s[i];
		}
	}
	return tempString;
}

int main(){
	string s,s1;
	cout<<"请输入表达式:";
	while(getline(cin,s)){//输入表达式s.
		//getline(cin,s1);
		//s+=s1;
		s=ClearDouHao(s); 
		calculate(s);//计算表达式s. 
		stack_dou.Clear();//清空实数栈. 
		stack_ch.Clear();//清空字符栈.
		cout<<"请输入表达式:"; 
	}
	return 0;
}
/*
2+3*4+5
2222222222222222222222222222222222222+1111111111111111111111111111111111
22222222222222222222222222222222*444444444444444444444444444444444
1111111111111111111111111111111111111111111111111111111111111111111111111*10000000000000000000000000000000000000000000
999999999999999999999999999999999999-888888888888888888888+7777777777777777/2222222222222
66666666666666666666666666666666666666/2222222
(2+3)*100000000000000000000000000000000000000
1111-22222222222222222222222
1-2+3*6-(2+4)
5+6/9*7/2
*/


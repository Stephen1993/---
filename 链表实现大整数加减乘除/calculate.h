#include<cstring>
#include<string>
using namespace std;

//******************************************************************************
const int Base=10000,seg=4;
//******************************************************************************

void trans(string ch,int *s){//将字符串转化为数字 
	int i,k=1;
	int L=ch.size()-seg; 
	for(i=L;i>=0;i-=seg,k++){//从字符串后面开始,依次四位四位存入整型数组.
		s[k]=ch[i]-'0';
		for(int j=i+1;j<i+seg;++j){
			s[k]=s[k]*10+ch[j]-'0';
		}
	}
	i+=seg;
	s[k]=0;
	for(int j=0;j<i;++j){
		s[k]=s[k]*10+ch[j]-'0';
	}
	if(s[k])s[0]=k;//s[0]储存该数组的位数. 
	else s[0]=k-1;
}
//******************************************************************************

void add(int *A,int *B,int *sum){//大整数相加 
    int la=max(A[0],B[0]),i,c=0;
    for(int i=A[0]+1;i<=la;++i)A[i]=0;
    for(int i=B[0]+1;i<=la;++i)B[i]=0;
	for(i=1;i<=la;++i){
		sum[i]=A[i]+B[i]+c;
		if(sum[i]>=Base){
			c=sum[i]/Base;
			sum[i]%=Base;
		}else c=0;
	}
    if(c>0){
    	sum[i]=c;
    	sum[0]=i;
    }
    else sum[0]=i-1;
}
//******************************************************************************

void sub(int *A,int *B,int *sum){//大数相减 
	int c=0;
	for(int i=B[0]+1;i<=A[0];++i)B[i]=0;
	for(int i=1;i<=A[0];++i){
		sum[i]=A[i]-B[i]+c;
		if(sum[i]<0){
			sum[i]+=Base;
			c=-1;
		}else c=0;
	}
	sum[0]=1;
	for(int i=A[0];i>=1;--i){
		if(sum[i]){
			sum[0]=i;
			break;
		}
	}
}
//******************************************************************************

void mult(int *A,int *B,int *sum){//大整数相乘 
	int i,j,k;
	int all=A[0]+B[0]-1;
	memset(sum,0,sizeof(int)*(all+3));
	for(i=1,k=1;i<=A[0];++i){
		k=i;
		if(A[i]){
			for(j=1;j<=B[0];++j,++k){
				sum[k]+=A[i]*B[j];
				if(sum[k]>=Base){
				   sum[k+1]+=sum[k]/Base;
				   sum[k]=sum[k]%Base;	
				}
			}
		}
	}
	while(sum[k]>=Base){
		sum[k+1]+=sum[k]/Base;
		sum[k]=sum[k++]%Base;
	}
	if(!sum[k])k--;
	sum[0]=k;
}
//******************************************************************************

//比较a,b的大小 
bool cmp(int *a,int *b){
	if(a[0]>b[0])return true;
	if(a[0]<b[0])return false;
	for(int i=a[0];i>=1;--i){
		if(a[i]>b[i])return true;
		if(a[i]<b[i])return false;
	}
	return true;
}

//比较a从第t个位置开始和b的大小
int cmp(int *a,int *b,int t){
	int i,j=1;
	for(i=b[0];i>=1;--i,++j){
		if(a[t]>b[i])return j;
		if(a[t]<b[i])return -1;
		--t;
	}
	return 0;
} 

void copy(int *a,int *b){
	a[0]=b[0];
	for(int i=1;i<=a[0];++i)a[i]=b[i];
}

int zero[]={1,0};

//sum=a/b,r=a%b
void div(int *a,int *b,int *sum/*,int *r*/){//大整数除法 
	int m=a[0],n=b[0];
	int Base1000=Base*1000,Base100=Base*100,Base10=Base*10;
	if(!cmp(a,b)){
		/*copy(r,a),*/copy(sum,zero);
		return;
	}
	int k=m-n+1;
	for(int i=k;i>=0;--i)sum[i]=0;
	for(int i=k,t=m;i>=1,t>=n;){
		int p=cmp(a,b,t);//a[t]-b[n]
		if(p<0 && t == n)break;
		if(p == 0){
			sum[i]++;
			for(int j=t;j>=t-n+1;--j)a[j]=0;
			t-=n;
			if(t<n)break;
			i-=n;
		}
		if(p>1){
			sum[i]++;
			for(int j=t,q=n;j>=t-n+1;--j,--q)a[j]-=b[q];
			for(int j=t-n+1;j<=t;++j){
				if(a[j]<0){
					a[j]+=Base,a[j+1]--;
				}
			}
			int j;
			for(int j=t;j>=t-n+1;--j)if(a[j])break;
			if(j<n)break;
			i-=(t-j);
			t=j;
		}
		if(p<0 && t>n){
			a[t-1]+=a[t]*Base;
			a[t]=0;
			--t;
			--i;
		}
		if(p == 1){
			int x=a[t]/(b[n]+1);
			sum[i]+=x;
			for(int j=t,q=n;q>=1;--q,--j)a[j]-=x*b[q];
			for(int j=t-n+1;j<=t;++j){
				while(a[j]<=-Base1000){a[j]+=Base1000,a[j+1]-=1000;}
				while(a[j]<=-Base100){a[j]+=Base100,a[j+1]-=100;}
				while(a[j]<=-Base10){a[j]+=Base10,a[j+1]-=10;}
				while(a[j]<=0){a[j]+=Base,a[j+1]-=1;}
			}
		}
	}
	if(sum[k] == 0)sum[0]=k-1;else sum[0]=k;
	/*int i;
	for(i=m;i>=1;--i)if(a[i])break;
	if(i == 0)copy(r,zero);
	else{
		r[0]=i;
		while(i >= 1)r[i]=a[i--];
	}*/
}

#include<stdio.h>
int ReadIn(){
	char ch;
	int num=0;
	while((ch=getchar())!='.'&&(ch<'0'||ch>'9'));
	while((ch>='0'&&ch<='9')||ch=='.'){
		if(ch!='.')
			num=num*10+ch-'0';
		ch=getchar();
	}
	return num;
}
int main(){
	int a,b;
	int ans;
	a=ReadIn();
	b=ReadIn();
	ansa=a%b;
	printf("%d.04%d",ans/10000,ans%10000);
	return 0;
}
/*
#include<stdio.h>

int main(){
	int a,ax,b,bx;
	scanf("%d.%d %d.%d",&a,&ax,&b,&bx);
	a=a*10000+ax;
	b=b*10000+bx;
	printf("%d.%04d",(a%b)/10000,(a%b)%10000);
	return 0;
}
*/
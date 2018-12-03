#include<stdio.h>
int main(){
	int x,ans;
	scanf("%d",&x);
	ans=0;
	ans+=x*5050;
	x-=150;
	if(x>0)ans+=x*1010;
	x-=350;
	if(x>0)ans+=x*1010;
	printf("%d.%04d",ans/10000,ans%10000);
	return 0;
}


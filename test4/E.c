#include<stdio.h>

int main(){
	long long n;
	long long ans2,ans5,ans,tmp;
	scanf("%lld",&n);
	//for(ans2=0,tmp=n;tmp;tmp=tmp/2) ans2+=tmp/2;
	for(ans5=0,tmp=n;tmp;tmp=tmp/5)
		ans5+=tmp/5;
	//ans=ans2>ans5?ans5:ans2;
	ans=ans5;
	printf("%lld",ans);
	return 0;
}

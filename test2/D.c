#include<stdio.h>
int main(){
	int n;
	int ans;
	scanf("%d",&n);
	if(n<3)printf("%d",n);
	else{
		for(ans=1;n>1;n--)
			ans=(ans*n)%1007;
		printf("%d",ans);
	}
	return 0;
}

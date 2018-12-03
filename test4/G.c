#include<stdio.h>
int sum(int n,int m){
	if((n*2)%m)
		return 0;
	else
		return 1;
}

int main(){
	int n;
	int l,r,ans;
	int flag=1;
	scanf("%d",&n);
	for(l=2,r=n;l<r;){
		if(sum(n,(l+r)/2))
			r=(l+r)/2,flag=0;
		else
			l=(l+r)/2+1;
	}
	if(sum(n,(l+r)/2))
		r=(l+r)/2,flag=0;
	if(flag)
		printf("-1");
	else 
		printf("%d",l);
	return 0;
}
	

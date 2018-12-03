#include<stdio.h>

int main(){
	double ans=0;
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(i%2)
			ans+=(double)1/(2*i-1);
		else
			ans-=(double)1/(2*i-1);
	}
	printf("%.6lf",ans);
	return 0;
}

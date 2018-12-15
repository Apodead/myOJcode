#include<stdio.h>
int n;
long long matrix[105][105];

int main(){
	int i,j,k;
	long long ans;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%lld",matrix[i]+j);
	for(i=0;i<n;i++,printf("\n"))
		for(j=0;j<n;j++,printf("%lld ",ans))
			for(k=0,ans=0;k<n;k++)
				ans+=matrix[i][k]*matrix[n-j-1][k];
	return 0;
}

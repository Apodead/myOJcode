#include <stdio.h>

int pascal[1003][1003];
long long now;
const long long mod=1e9+7;
int i,j;
int main(){
	for(i=2,pascal[1][1]=1;i<=1000;i++)
		for(j=2,pascal[i][1]=1;j<=i;j++){
			now=(long long)pascal[i-1][j]+pascal[i-1][j-1];
			pascal[i][j]=now%mod;
		}
	while(scanf("%d",&i)>0){
			for(j=1;j<=i;j++)
				printf("%d ",pascal[i][j]);
			printf("\n");
	}
	return 0;
}


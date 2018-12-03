#include<stdio.h>
int main(){
	int n;
	double a,x,b;
	int i;
	scanf("%d %lf%% %lf %lf",&n,&a,&x,&b);
	for(i=0,a/=100;i<n;i++){
		x=x+x*a;
		x-=b;
	}
	printf("%.3lf",x);
	return 0;
}

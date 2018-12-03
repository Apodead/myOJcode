#include<stdio.h>
int main(){
	double r,h,ans;
	scanf("%lf%lf",&r,&h);
	ans=2*3.14*r*(r+h);
	printf("%.4lf",ans);
	return 0;
}

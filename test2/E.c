#include<stdio.h>
int main(){
	double num;
	scanf("%lf",&num);
	printf("%d %.6lf",(int)num, num-(int)num);
	return 0;
}

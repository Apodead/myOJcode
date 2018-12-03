#include<stdio.h>
int main(){
	long long num;
	scanf("%lld",&num);
	if(num<0)num=-num;
	printf("%lld",num);
	return 0;
}

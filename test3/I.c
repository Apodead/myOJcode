#include<stdio.h>
int main(){
	long long num;
	int cnt=1;
	scanf("%lld",&num);
	while(num>100){
		if(num%1000==158){
			printf("%d 158!158!158!",cnt);
			return 0;
		}
		num/=10;
		cnt++;
	}
	printf("We can't find the qun pet.");
	return 0;
}


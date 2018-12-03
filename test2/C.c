#include<stdio.h>
int main(){
	long long num;
	int i;
	for(i=0;i<4;i++){
		scanf("%lld",&num);
		if(num-(num&-num))
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}

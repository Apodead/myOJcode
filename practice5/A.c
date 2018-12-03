#include<stdio.h>

int main(){
	long long n,x,a,sum;

	sum=0;
	scanf("%lld%lld",&n,&x);
	for(;n>=0;n--){
		scanf("%lld",&a);
		sum*=x;
		sum+=a;
		sum%=1000000007;
	}
	printf("%lld",sum);
	return 0;
}


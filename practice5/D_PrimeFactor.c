
/*
 * 本题使用欧拉线性筛，详细资料可以自行谷歌/百度
 * 好像做的有点麻烦。。。实际上穷举就可以过
 */
#include<stdio.h>
#define MAX (int)1e6+5
int prime[MAX],count;
int isPrime[MAX];

void getPrime(int maxN){
	int i,j;
	count=0;
	for(isPrime[0]=isPrime[1]=0,i=2;i<=maxN;i++) isPrime[i]=1;
	for(i=2;i<=maxN;i++){
		if(isPrime[i])prime[count++]=i;
		for(j=0;j<count&&i*prime[j]<=maxN;j++){
			isPrime[i*prime[j]]=0;
			if(!i%prime[j])break;
		}
	}
}

int main(){
	long long t,x,y,pCount,ans;
	long long num,tmp;
	int i;
	scanf("%lld",&t);
	getPrime(MAX-3);
	while(t--){
		scanf("%lld%lld",&x,&y);
		num=x*y, ans=1;
		for(i=0;i<count&&(long long)prime[i]*2<=num;i++)
			if(num%prime[i]==0){
				tmp=num/prime[i], pCount=1;
				while(0==tmp%prime[i]) pCount++, tmp/=prime[i];
				ans*=pCount+1;
			}
		printf("%lld\n",ans);
	}
	return 0;
}



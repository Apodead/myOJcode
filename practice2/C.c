/*
 * 本题使用欧拉线性筛，详细资料可以自行谷歌/百度
 */
#include<stdio.h>
#define MAX (int)1e4+5
int prime[MAX],count;
int isPrime[MAX];

void getPrime(int maxN){
	int i,j;
	count=0;
	for(isPrime[0]=isPrime[1]=0,i=2;i<=maxN;i++)
		isPrime[i]=1;
	for(i=2;i<=maxN;i++){
		if(isPrime[i])prime[count++]=i;
		for(j=0;j<count&&i*prime[j]<=maxN;j++){
			isPrime[i*prime[j]]=0;
			if(!i%prime[j])break;
		}
	}
}

int main(){
	int n,m;
	int i;
	scanf("[%d,%d]",&n,&m);
	getPrime(m);
	for(i=0;i<count&&prime[i]<n;i++);//注意顺序
	for(;i<count;i++)//maxN == n
		printf("%d ",prime[i]);
	return 0;
}


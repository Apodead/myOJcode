
/*
 * 本题使用欧拉线性筛，详细资料可以自行谷歌/百度
 * 好像做的有点麻烦。。。实际上穷举就可以过
 */
#include<stdio.h>
#include<math.h>

int main(){
	long long t,x,y,ans;
	long long num,num_sqrt, i;
	double esp=1e-9;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&x,&y);
		num=x*y, ans=0, num_sqrt=sqrt(num)+esp;
		if(num_sqrt*num_sqrt==num)ans--;
		for(i=1;i<=num_sqrt;i++){
			if((num/i)*i==num)ans+=2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

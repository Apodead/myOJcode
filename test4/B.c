#include<stdio.h>

double fact[4005]={1,1};
double qpow(double x, int y){
	double ans=1;
	
	while(y){
		if(y&1){
			ans*=x;
		}
		x*=x;
		y>>=1;
	}
	return ans;
}

double factorial(int n){
	if(fact[n])
		return fact[n];
	else 
		return fact[n]=factorial(n-1)*n;
}

int main(){
	double x,ans;
	int m;
	int i;

	scanf("%lf %d",&x,&m);
	for(i=1,ans=1;i<=m;i++){
		ans+=(i%2?-1:1)*qpow(x,i*2)/factorial(i*2);
	}
	printf("%.6lf",ans);
	return 0;
}

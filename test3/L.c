#include<stdio.h>
#define eps 1e-8
int main(){
	int n;
	double  a,x,suma,sumgp;
	int i;
	scanf("%d",&n);
	for(i=0,suma=sumgp=0;i<n;i++){
		scanf("%lf%lf",&a,&x);
		suma+=a;
		if(x>60-eps){
			sumgp+=a*(4-3*(100-x)*(100-x)/1600);
		}
	}
	printf("%.7lf",sumgp/suma);
	return 0;
}

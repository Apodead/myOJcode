#include<stdio.h>
int main(){
	double prca,prcb,cost;
	double eps=1e-8;
	int tot;
	int cnta,cntb;
	scanf("%lf%lf%lf%d",&prca,&prcb,&cost,&tot);
	cnta=(cost-prcb*tot)/((prca-prcb))+eps;
	cntb=tot-cnta;
	if(cnta>=0&&cntb>=0&&cnta*prca+cntb*prcb>cost-eps&&cnta*prca+cntb*prcb<cost+eps)
		printf("%d %d",cnta, cntb);
	else 
		printf("Jenny has a bad memory!");
	return 0;
}


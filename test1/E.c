#include<stdio.h>
int main(){
	double a1,b1,c1;
	double a2,b2,c2;
	double ansx,ansy;
	scanf("%lf%lf%lf",&a1,&b1,&c1);
	scanf("%lf%lf%lf",&a2,&b2,&c2);
	ansx=(b2*c1-b1*c2)/(-a2*b1+a1*b2);
	ansy=(a2*c1-a1*c2)/(a2*b1-a1*b2);
	if(ansx<0.000001&&ansx>-0.000001)ansx=0;
	if(ansy<0.000001&&ansy>-0.000001)ansy=0;
	printf("(%.2lf,%.2lf)",ansx,ansy);
	return 0;
}

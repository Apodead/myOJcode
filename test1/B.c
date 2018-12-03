#include<stdio.h>
int main(){
	int x1,x2,y1,y2;
	double a1,b1,c1;
	double a2,b2,c2;
	double ansx,ansy;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	x2-=x1,y2-=y1;
	a1=y2,b1=-x2,c1=x1*y2-y1*x2;
	//printf("%lf %lf %lf",a1,b1,c1);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	x2-=x1,y2-=y1;
	a2=y2,b2=-x2,c2=x1*y2-y1*x2;
	//printf("%lf %lf %lf",a2,b2,c2);
	if(a2*b1-a1*b2==0.0){
		printf("Zyysb");
	}else{
		//printf("%lf %lf\n",c1,c2);
		ansx=(b2*c1-b1*c2)/(-a2*b1+a1*b2);
		ansy=(a2*c1-a1*c2)/(a2*b1-a1*b2);
		if(ansx<0.000001&&ansx>-0.000001)ansx=0;
		if(ansy<0.000001&&ansy>-0.000001)ansy=0;
		printf("(%.6lf,%.6lf)",ansx,ansy);
	}
	return 0;
}

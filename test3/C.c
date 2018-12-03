#include<stdio.h>
#include<math.h>
#define eps 1e-8
#define swap(x,y) (x^=y^=x^=y^=x)

int main(){
	int a,b,c;
	int delta;
	double ans;
	scanf("%d%d%d",&a,&b,&c);
	delta=b*b-4*a*c;
	if(a<0)a=-a,b=-b,c=-c;
	if(delta>=0){
		ans=(-(double)b+sqrt(delta))/2*a;
	printf("%.4lf %.4lf",(-(double)b-sqrt(delta))/(2*a),(-(double)b+sqrt(delta))/(2*a));
	}else{
		printf("No Solution!");
	}
	return 0;
}

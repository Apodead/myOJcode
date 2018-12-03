#include<stdio.h>

int main(){
	double a,b,c,d,e,f;
	char operation;
	while(scanf("%lf%lf%lf%lf %c",&a,&b,&c,&d,&operation)>0){
		//printf("%.2lf %.2lf\n",a,b);
		//printf("%.2lf %.2lf\n",c,d);
		//putchar(operation);
		switch(operation){
			case '+':
				e=a+c,f=b+d;
				//printf("%.2lf %.2lf\n",e,f);
				break;
			case '-':
				e=a-c,f=b-d;
				break;
			case '*':
				e=a*c-b*d,f=b*c+a*d;
				break;
			case '/':
				a/=(c*c+d*d),b/=(c*c+d*d);
				d=-d;
				e=a*c-b*d,f=b*c+a*d;
				break;
		}
		printf("%.2lf %.2lf\n",e,f);
	}
	return 0;
}

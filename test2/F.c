#include<stdio.h>
int main(){
	int n;
	int min,tsec;
	double sec;
	scanf("%d",&n);
	n%=12;
	if(n==11)n=12;	//Attention!!!
	min=(int)(((double)12/11)*60*n);
	sec=((double)12/11*3600*n);
	min%=60;
	tsec=sec;
	tsec/=60;
	tsec*=60;
	sec-=tsec;
	printf("%d:%d:%.7lf\n",n,min,sec);
	return 0;
}

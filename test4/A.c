#include<stdio.h>

int main(){
	double now,lim,eps=1e-8;
	scanf("%lf%lf",&now,&lim);
	if(now/lim+eps<1.1){
		printf("OK");
	}else if(now/lim+eps<1.5){
		printf("Exceed %.0lf%%. Ticket 200",((eps+now/lim)*100)-100);
	}else{
		printf("Exceed %.0lf%%. License Revoked",((eps+now/lim)*100)-100);
	}

	return 0;
}

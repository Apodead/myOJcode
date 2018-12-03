#include<stdio.h>
int main(){
	int year;
	while(scanf("%d",&year)==1){
		if(year%100){
			if(year%4)
				printf("0\n");
			else 
				printf("1\n");
		}else if(year%400)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}

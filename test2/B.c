#include<stdio.h>
int main(){
	int y,m,d,yy,mm,dd;
	scanf("%d%d%d%d%d%d",&y,&m,&d,&yy,&mm,&dd);
	if(y<yy&&m==mm&&d==dd){
		printf("Anniversary!");
	}else{
		//printf("%d",dd);
		switch(dd){
			case 1: 
			case 21:
			case 31:
				printf("%dst",dd);break;
			case 2: 
			case 22:
				printf("%dnd",dd);break;
			case 3: 
			case 13:
			case 23:
				printf("%drd",dd);break;
			case 11:
			case 12:
			default: 
				printf("%dth",dd);break; 
		}
		putchar(' ');
		switch(mm){
			case 1: printf("Jan.");break;
			case 2: printf("Feb.");break;
			case 3: printf("Mar.");break;
			case 4: printf("Apr.");break;
			case 5: printf("May.");break;
			case 6: printf("Jun.");break;
			case 7: printf("Jul.");break;
			case 8: printf("Aug.");break;
			case 9: printf("Sept.");break;
			case 10: printf("Oct.");break;
			case 11: printf("Nov.");break;
			case 12: printf("Dec.");break;
		}
	}
	return 0;
}

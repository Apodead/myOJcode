#include<stdio.h>

int isRun(int year){
	return (year%100)?!(year%4):!(year%400);
}
int daysOfMonth(int year, int month){
	int days;
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days=31;
			break;
		case 2:
			days=isRun(year)?29:28;
			break;
		default:
			days=30;
	}
	return days;
}

int main(){
	int yy,mm,dd;
	long long days;
	while(scanf("%d%d%d",&yy,&mm,&dd)>0){
		days=dd-1;
		while(--mm)days+=daysOfMonth(yy,mm);
		for(;yy>0;yy--)
			days+=isRun(yy)?366:365;
		switch(days%7){
			case 6:
			case 0:
				printf("DDL is the primary productive force.\n");
				break;
			default:
				printf("All work and no play makes Max a dull boy.\n");
		}
	}
	return 0;
}

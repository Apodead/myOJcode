#include<stdio.h>

int isRun(int year);
int isLegalDate(int year, int month, int day);

int main(){
	int yy,mm,dd,addi;
	scanf("%d%d%d%d",&yy,&mm,&dd,&addi);
	if(!isLegalDate(yy,mm,dd)){
		printf("Unhappy");
		return 0;
	}
	dd+=addi;
	while(dd>366)dd-=isRun(mm>2?yy+1:yy)?366:365,yy++;
	while(!isLegalDate(yy,mm,dd)){
		switch(mm){
			case 2:
				dd-=isRun(yy)?29:28;
				break;
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				dd-=31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				dd-=30;
				break;
			case 13:
				yy++,mm=0;
				break;
		}
		mm++;
	}
	printf("%d %d %d",yy,mm,dd);
	return 0;
}
int isLegalDate(int year, int month, int day){
	if(day<1) return 0;
	else switch(month){
		case 2:
			//printf("%d %d %d\n",year,day,isRun(year)?day<=29:day<=28);
			return isRun(year)?day<=29:day<=28;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return day<=31;
		case 4:
		case 6:
		case 9:
		case 11:
			return day<=30;
		default:
			return 0;
	}
}
int isRun(int year){
	return (year%100)?!(year%4):!(year%400);
}

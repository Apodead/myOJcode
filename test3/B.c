
#include<stdio.h>
#define eps 1e-8
#define swap(x,y) (x^=y^=x^=y^=x)

int main(){
	int key;
	scanf("%d",&key);
	switch(key/13){
		case 0:
			break;
		case 1:
			printf("tam");
			break;
		case 2:
			printf("hel");
			break;
		case 3:
			printf("maa");
			break;
		case 4:
			printf("huh");
			break;
		case 5:
			printf("tou");
			break;
		case 6:
			printf("kes");
			break;
		case 7:
			printf("hei");
			break;
		case 8:
			printf("elo");
			break;
		case 9:
			printf("syy");
			break;
		case 10:
			printf("lok");
			break;
		case 11:
			printf("mer");
			break;
		case 12:
			printf("jou");
			break;
	}
	if(key>12&&key%13)putchar(' ');
	switch(key%13){
		//jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec
		case 0:
			if(key==0)
				printf("tret");
			break;
		case 1:
			printf("jan");
			break;
		case 2:
			printf("feb");
			break;
		case 3:
			printf("mar");
			break;
		case 4:
			printf("apr");
			break;
		case 5:
			printf("may");
			break;
		case 6:
			printf("jun");
			break;
		case 7:
			printf("jly");
			break;
		case 8:
			printf("aug");
			break;
		case 9:
			printf("sep");
			break;
		case 10:
			printf("oct");
			break;
		case 11:
			printf("nov");
			break;
		case 12:
			printf("dec");
			break;
	}
	return 0;
}

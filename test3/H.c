#include <stdio.h>
int main(){
	char ch;
	while((ch=getchar())!=EOF){
		switch(ch){
			case '+':
				printf("jia ");
				break;
			case '-':
				printf("jian ");
				break;
			case '*':
				printf("cheng ");
				break;
			case '/':
				printf("chu ");
				break;
			case '%':
				printf("mo ");
				break;
			case '(':
				printf("zuokuohao ");
				break;
			case ')':
				printf("youkuohao ");
				break;
			case '^':
				printf("yihuo ");
				break;
			case '#':
				printf("jinghao ");
				break;
		}
	}
	return 0;
}

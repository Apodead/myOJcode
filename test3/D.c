#include<stdio.h>
int main(){
	int i;
	char num[15];
	for(i=1;i<=9;i++){
		num[i]=getchar();
	}
	for(i=9;i>0&&num[i]=='0';i-=2);
	for(;i>0;i-=2)putchar(num[i]);
	return 0;
}

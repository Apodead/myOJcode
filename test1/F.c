#include<stdio.h>
int main(){
	char a,b;
	int c,d;
	scanf("%c %c%d%d",&a,&b,&c,&d);
	printf("%d\n%.2lf",a/c+b/d, (double)a/c+(double)b/d);
	return 0;
}

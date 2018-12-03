#include<stdio.h>

int main(){
	int c[10];
	int i;
	for(i=0;i<10;i++)
		scanf("%d",c+i);
	for(i=1;!c[i];i++);
	printf("%d",i);
	c[i]--;
	for(i=0;i<10;i++)
		while(c[i]-->0)
			printf("%d",i);
	return 0;
}


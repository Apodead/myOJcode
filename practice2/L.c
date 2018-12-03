#include<stdio.h>

int main(){
	int n;
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=0,k=n*n/2-i*i/2;j<k;j++)putchar(' ');
		for(j=0,k=i*i/2;j<k;j++)putchar('$');
		if(i%2)
			putchar('$');
		else
			putchar('@');
		for(j=0,k=i*i/2;j<k;j++)putchar('$');
		putchar('\n');
	}
	return 0;
}
	

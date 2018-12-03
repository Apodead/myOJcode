#include<stdio.h>

char result[60][60];

void putAlphabet(char ch, int len, int x){
	int i;
	for(i=x;i<x+len;i++)
		result[x][i]=result[x+len-1][i]=ch;
	for(i=x;i<x+len;i++)
		result[i][x]=result[i][x+len-1]=ch;
}

int main(){
	int n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		putAlphabet(i+'A', 2*(n-i)-1,i);
	}
	for(i=0;i<2*n-1;i++){
		puts(result[i]);
	}
	return 0;
}

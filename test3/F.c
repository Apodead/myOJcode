#include<stdio.h>

int main(){
	int n;
	int a,b,d;
	int xi,yi;
	int i,cnt;
	scanf("%d%d%d%d",&n,&a,&b,&d);
	for(i=0,cnt=0;i<n;i++){
		scanf("%d%d",&xi,&yi);
		if(xi+yi<a+b+d&&xi+yi>a+b-d&&xi-yi>a-b-d&&xi-yi<a-b+d)cnt++;
	}
	printf("%d",cnt);
	return 0;
}

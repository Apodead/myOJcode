#include<stdio.h>
int main(){
	int x;
	int a,b,m,n;
	scanf("%d",&x);
	switch(x){
		case 1:
			scanf("%d%d",&n,&m);
			m--;
			n|=(1<<m);
			printf("%d",n);
			break;
		case 2:
			scanf("%d",&n);
			if(n&(n-1))
				printf("No");
			else 
				printf("Yes");
			break;
		case 3:
			scanf("%d%d",&a,&b);
			a^=b;
			b^=a;
			a^=b;
			printf("%d %d",a,b);
			break;
		case 4:
			scanf("%d",&a);
			if(a&1)
				printf("No");
			else 
				printf("Yes");
			break;
		case 5:
			scanf("%d%d",&n,&m);
			printf("%d",!(!(n&(1<<(m-1)))));
			break;
		default:
			printf("158!158!158!");
	}
	return 0;
}


#include<stdio.h>

int main(){
	int m,n,k;
	int ans=0;
	scanf("%d%d%d",&m,&n,&k);
	switch(k){
		case 1:
			ans=0;//really?
			break;
		case 2:
			ans=4;
			break;
		case 3:
			ans=8;
			break;
		case 4:
			ans=(m-4)*2+(n-4)*2+4;
			break;
		case 5:
			ans=0;
			break;
		case 6:
			ans=(m-4)*2+(n-4)*2;
			break;
		case 7:
			ans=0;
			break;
		case 8:
			ans=(m-4)*(n-4);
			break;
	}
	printf("%d",ans);
	return 0;
}


#include<stdio.h>
int main(){
	int t,x1,y1,r1,x2,y2,r2;
	int d2,sr,mr;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&x1,&y1,&r1);
		scanf("%d%d%d",&x2,&y2,&r2);
		d2=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		sr=(r1+r2)*(r1+r2);
		mr=(r1-r2)*(r1-r2);
		if(d2==0&&mr==0)
			printf("D\n");
		else if(d2>sr)
			printf("R\n");
		else if(d2==sr)
			printf("Q\n");
		else if(d2>mr)
			printf("E\n");
		else if(d2==mr)
			printf("W\n");
		else
			printf("F\n");
	}
	return 0;
}

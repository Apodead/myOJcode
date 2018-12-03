#include<stdio.h>
int area(int a, int b, int c, int d){
	return (c-a)*(d-b);
}
void sort(int *a, int s, int e){
	//notice: array[end] won't be sorted
	int i,j;
	for(i= s;i<e;i++)
		for(j= s;j<e-1;j++)
			if(a[j]>a[j+1])
				a[j+1]^=a[j]^=a[j+1]^=a[j];// it's just swap array[j] & array[j+1]
}
int main(){
	int ans;
	int eh[5],ev[5];//edge horizontal & edge vertical
	int i;
	ans=0;
	for(i=0;i<4;i++)
		scanf("%d%d",eh+i,ev+i);
	ans+=area(eh[0],ev[0],eh[1],ev[1]);
	ans+=area(eh[2],ev[2],eh[3],ev[3]);
	if((eh[0]<=eh[3]&&eh[1]>=eh[2])&&
		(ev[0]<=ev[3]&&ev[1]>=ev[2])){
		sort(eh,0,4);
		sort(ev,0,4);
		ans-=area(eh[1],ev[1],eh[2],ev[2]);
	}
	printf("%d",ans);
	return 0;
}

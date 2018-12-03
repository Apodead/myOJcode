#include<stdio.h>

char num[10];
void dfs(int step, int remain){
	int i;
	if(step==5){
		if(!remain)
			printf("%5s\n",num);
		return;
	}
	if(remain)
		for(i=6;i>=1;i--){
			if(i>remain)
				continue;
			num[step]=i+'0';
			dfs(step+1,remain-i);
		}
	return;
}
int main(){
	int x;
	scanf("%d",&x);
	dfs(0,x);
	return 0;
}

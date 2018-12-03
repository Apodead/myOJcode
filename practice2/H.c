#include<stdio.h>

struct A{
	int num,times;
}buf[1005],num[1005];
void merge_sort(int l, int r){
	int i,j,k;
	if(l>=r)return;
	merge_sort(l, (l+r)/2);
	merge_sort((l+r)/2+1,r);
	for(i=k=l,j=(l+r)/2+1;i<(l+r)/2+1&&j<=r;k++){
		if(num[i].times<num[j].times)
			buf[k]=num[j++];
		else
			buf[k]=num[i++];
	}
	if(k<=r){
		while(i<(l+r)/2+1)buf[k++]=num[i++];
		while(j<=r)buf[k++]=num[j++];
	}
	for(i=l;i<=r;i++)
		num[i]=buf[i];
}

int main(){
	int n;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<=1000;i++)num[i].num=i,num[i].times=0;
	for(i=0;i<n;i++){
		scanf("%d",&j);
		num[j].times++;
	}
	merge_sort(0,1000);
	for(i=0;i<=1000&&num[i].times;i++){
		printf("%d %d\n",num[i].num,num[i].times);
	}
	return 0;
}

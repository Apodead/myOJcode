#include<stdio.h>
int main(){
	int n,m;
	int ans=0,tmp,num;
	int i,flag;
	char ch;
	int wrongLine[1005];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&m);
		num=tmp=flag=0;
		m++;
		while(m&&(ch=getchar())!='\n'){
			switch(ch){
				case '+':
					num+=flag*tmp;
					flag=1;
					tmp=0;
					break;
				case '-':
					num+=flag*tmp;
					flag=-1;
					tmp=0;
					break;
				case ' ':
					m--;
					break;
				default:
					tmp=tmp*10+ch-'0';
			}
			if(num<0){
				wrongLine[ans++]=i;
				break;
			}
		}
		if(ch=='\n'){
			num+=flag*tmp;
			if(num<0)
				wrongLine[ans++]=i;
		}
	}
	printf("%d\n",ans);
	for(i=0;i<ans;i++){
		printf("%d\n",wrongLine[i]);
	}
	return 0;
}

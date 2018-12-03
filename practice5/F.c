#include<stdio.h>

int main(){
	int n,k,p,x;
	int tmp,bit;
	int i;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		switch(k){
			case 10:
				scanf("%d",&x);
				tmp=x,bit=1<<30;
				while(!(tmp&bit))bit>>=1;
				while(bit){
					putchar(((tmp&bit)>0)+'0');
					bit>>=1;
				}
				putchar(' ');
				printf("%o %X\n",x,x);
				break;
			case 2:
			case 8:
			case 16:
				scanf("%d",&p);
				for(x=0,i=0;i<p;i++){
					x*=k;
					while((tmp=getchar())==' ');
					x+=tmp>='A'?tmp-'A'+10:tmp-'0';
				}
				printf("%d\n",x);
				break;
		}
	}
	return 0;
}

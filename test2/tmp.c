#include<stdio.h>
int main() {
	int a,b,c,d,e,f,g,h,S,S1,S2,SS;
	scanf("%d %d %d %d\n%d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h);
	S1=(c-a)*(d-b);
	S2=(g-e)*(h-f);
	SS=0;
	if((a<g&&b<h)&&(e<c&&f<d)) {
		int p[4],i,j,k;
		p[1]=a;
		p[2]=c;
		p[3]=e;
		p[4]=g;
		for(i=1;i<=4;i++) {
			for(j=1;j<=4;j++) {
				if(p[i]>p[j]) {
					k=p[i]; p[i]=p[j]; p[j]=k;
				}
			}
		}
		int q[4],x,y,z;
		q[1]=b;
		q[2]=d;
		q[3]=f;
		q[4]=h;
		for(x=1;x<=4;x++) {
			for(y=1;y<=4;y++) {
				if(q[x]>q[y]) {
					z=q[x]; q[x]=q[y]; q[y]=z;
				}
			}
		}
		SS=(p[2]-p[3])*(q[2]-q[3]);
	}
	S=S1+S2-SS;
	printf("%d",S);
	return 0;
} 


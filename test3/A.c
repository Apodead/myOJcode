#include<stdio.h>
#define eps 1e-8
#define swap(x,y) (x^=y^=x^=y^=x)

int main(){
	int l,r,ans;
	scanf("%d%d",&l,&r);
	ans=(r/10-l/10)*4;
	if(r%10>=8)ans++;
	if(r%10>=7)ans++;
	if(r%10>=3)ans++;
	if(r%10>=1)ans++;
	if(l%10>1)ans--;
	if(l%10>3)ans--;
	if(l%10>7)ans--;
	if(l%10>8)ans--;
	printf("%d",ans);
	return 0;
}

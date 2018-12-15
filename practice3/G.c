#include<stdio.h>
int main(){
	int anslow,anshigh,alllowest;
	int n,price;
	scanf("%d",&n);
	scanf("%d",&price);
	anslow=anshigh=alllowest=price,n--;
	while(n--){
		scanf("%d",&price);
		if(price<alllowest)
			alllowest=price;
		if(anshigh-anslow<price-alllowest)
			anshigh=price,anslow=alllowest;
	}
	printf("%d",anshigh-anslow);
	return 0;
}

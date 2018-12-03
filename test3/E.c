/*#include<stdio.h>

  int readNum(int *num){
  char ch,count=0;
 *num=0;
 while((ch=getchar())!=EOF&&(ch<'0'||ch>'9'));
 while(ch>='0'&&ch<='9')
 *num=*num*10+ch-'0',count++,ch=getchar();
 return count;
 }
 int pow(int x,int y){
 int ans=1;
 for(i=0;i<y;i++)
 ans*=x;
 return ans;
 }
 int main(){
 int num,cnt;
 int i,j;
 while((cnt=readNum(&num))){
 for(i=0;i<cnt;i++){

*/
#include<stdio.h>
int cntn(int num){
	int cnt=0;
	//if(num==0)return 1;
	while(num)cnt++,num/=10;
	return cnt;
}
int pow(int x, int y){
	int ans,i;
	for(i=1,ans=x;i<y;i++)ans*=x;
	return ans;
}
int main(){
	int num,cnt;
	int tmp,numb,i;
	while(EOF!=scanf("%d",&num)){
		if(num>=0){
			cnt=cntn(num);
			for(tmp=num,numb=0,i=0;i<cnt;i++){
				numb+=pow(tmp%10,cnt);
				tmp/=10;
			}
			if(numb==num)
				printf("guna\n");
			else
				printf("%d\n",numb);
		}else{
			num=-num;
			cnt=cntn(num);
			for(tmp=num,numb=0,i=0;i<cnt;i++){
				numb+=pow(tmp%10,cnt);
				tmp/=10;
			}
			printf("%d\n",numb);
		}
	}
	return 0;
}

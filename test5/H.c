#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp( const void * p, const void * q) 
{ 
    return ( * ( long long * ) q - * ( long long * ) p)>0?1:( ( * ( long long * ) q - * ( long long * ) p)==0?0:-1) ; 
}
long long ans,n,i,x,j;
long long num[1005],buf[1005];
long long min;
int main(){
    scanf("%lld %lld ",&n,&x);
    for(i=0;i<n;i++)
        scanf("%lld",num+i);
    qsort(num,n,sizeof(long long),cmp);
    for(min=0,i=0,j=0;i<n;min++,j--,i++){
        if(j==0)
            ans+=num[i],i++,j=x;
    }
    printf("%lld %lld",ans,min);
    return 0;
}

    



#include<stdio.h>

typedef long long T;
int cmpll(T a, T b){
    return a<b;
}
//function 'compare' return 0 when they are sorted
//mergesort will sort array from array[l] to array[r-1]

void mergesort(T* array,T* buffer,int(*compare)(T a,T b), int l, int r){
    int i,j,k;
    if(r-l<2)
        return;
    mergesort(array,buffer,compare,l,(l+r)/2);
    mergesort(array,buffer,compare,(l+r)/2,r);
    for(i=l,j=(l+r)/2,k=l;
            i<(l+r)/2&&j<r;
            k++){
        if(compare(array[i],array[j]))
            buffer[k]=array[j++];
        else
            buffer[k]=array[i++];
    }
    while(i<(l+r)/2)buffer[k++]=array[i++];
    while(j<r)buffer[k++]=array[j++];
    for(i=l;i<r;i++)
        array[i]=buffer[i];
}
long long ans,n,i,x,j;
long long num[1005],buf[1005];
long long min;
int main(){
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld",num+i);
    mergesort(num,buf,cmpll,0,n);
    for(i=0;i<n;i++)
    printf("%lld\n",num[i]);
    for(min=0,i=0,j=0;i<n;min++,j--,i++){
        if(j==0)
            ans+=num[i],i++,j=x;
    }
    printf("%lld %lld",ans,min);
    return 0;
}

    


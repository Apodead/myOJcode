#include<stdio.h>

typedef long long T;
int cmpInt(T a, T b){
    return a>b;
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
int n,i;
long long ansn,ans;
long long num[100005];
long long buf[100005];
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",num+i);
    mergesort(num,buf,cmpInt,0,n);
        //printf("a test\n");
    for(i=1,ansn=num[0],ans=num[1]-num[0];i<n-1;i++){
        if(num[i+1]-num[i]<ans)
            ans=num[i+1]-num[i],ansn=num[i];
    }
    //for(i=0;i<n;i++)printf("%d ",num[i]);
    printf("%lld %lld",ansn,ans+ansn);
    return 0;
}

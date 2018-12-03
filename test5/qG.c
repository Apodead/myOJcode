#include<stdio.h>
typedef int T;
int cmpInt(T a,T b){return a<b;}

void quickSort(T* array, int(*compare)(T a,T b), int l, int r){
    printf("a call\n");
    int i,j;
    T mid;
    if(r-l<2)
        return;
    for(i=l,j=r-1,mid=array[l];i<j;){
    printf("a call1:%d,%d\n",array[i],array[j]);
        while(compare(mid,array[j]))j--;
        array[i]=array[j];
        while(compare(array[i],mid))i++;
        array[j]=array[i];
    }
    array[i]=mid;
    quickSort(array,compare,l,i);
    quickSort(array,compare,i+1,r);
}
int n,i,ans,ansn;
int num[100005];
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",num+i);
    quickSort(num,cmpInt,0,n);
        printf("a test\n");
    for(i=1,ansn=num[0],ans=num[1]-num[0];i<n-1;i++){
        if(num[i+1]-num[i]<ans)
            ans=num[i+1]-num[i],ansn=num[i];
    }
    for(i=0;i<n;i++)printf("%d ",num[i]);
    printf("%d %d",ansn,ans+ansn);
    return 0;
}

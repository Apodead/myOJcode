#include<stdio.h>
#include<string.h>
typedef char T;
int cmpnum(T a,T b){return a>b;}

void quickSort(T* array, int(*compare)(T a,T b), int l, int r){
    int i,j;
    T mid;
    if(r-l<2)
        return;
    for(i=l,j=r-1,mid=array[l];i<j;){
        while(!compare(mid,array[j])&&i<j)j--;
        array[i]=array[j];
        while(!compare(array[i],mid)&&i<j)i++;
        array[j]=array[i];
    }
    array[i]=mid;
    quickSort(array,compare,l,i);
    quickSort(array,compare,i+1,r);
}

char p[255],q[255];
int main(){
    //scanf("%s\n%s",p,q);
    fgets(p,200,stdin);
    fgets(q,200,stdin);
    quickSort(p,cmpnum,0,strlen(p));
    quickSort(q,cmpnum,0,strlen(q));
    if(strcmp(p,q))
        printf("NIE");
    else 
        printf("TAK");
    return 0;
}

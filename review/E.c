#include<stdio.h>
int mat[105][105];
int n,w,h;
int x1,x2,y1,y2;
int color;
int main(){
    int i,j,k;
    scanf("%d%d%d",&n,&w,&h);
    for(i=0;i<w;i++)
        for(j=0;j<h;j++)
            mat[i][j]=0xFFFFFF;
    for(i=0;i<n;i++){
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&color);
        for(j=x1;j<=x2;j++)
            for(k=y1;k<=y2;k++)
                mat[j][k]=color;
    }
    for(i=0;i<h;i++) {
        for(j=0;j<w;j++)
            printf("#%06X ",mat[j][i]);
        if(i!=h-1)putchar('\n');
    }
    return 0;
}

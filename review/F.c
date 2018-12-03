#include<stdio.h>
char buf[10005];
int check[30];
int main(){
    while(scanf("%[^\n]%*[\n]",buf)>0){
        int i=0;
        for(i=0;i<26;i++)check[i]=0;
        for(i=0;buf[i]!='\0';i++){
            if(buf[i]>='A'&&buf[i]<='Z')check[buf[i]-'A']=1;
            if(buf[i]>='a'&&buf[i]<='z')check[buf[i]-'a']=1;
        }
        int all_ok=1;
        for(i=0;i<26;i++){
            if(check[i]==0)all_ok=0,printf("%c ",'A'+i);
            check[i]=0;
        }
        if(all_ok)printf("OK!");
        putchar('\n');
    }
    return 0;
}


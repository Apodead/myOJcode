#include<stdio.h>
int check[30];
char ch;
int exited=0;
int i,all_ok=1;
int main(){
    while(!exited){
        ch=getchar();
        if(!~ch)exited=1;
        if(ch=='\n'){
            for(i=0;i<26;i++){
                if(!check[i]){
                    if(!all_ok)putchar(' ');
                    printf("%c",'A'+i),all_ok=0;
                }
                check[i]=0;
            }
            if(all_ok)
                printf("OK!");
            putchar('\n');
            all_ok=1;
        }
        if(ch>='a'&&ch<='z')check[ch-'a']++;
        if(ch>='A'&&ch<='Z')check[ch-'A']++;
    }
    return 0;
}

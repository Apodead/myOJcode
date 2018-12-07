#include <stdio.h>
#include <string.h>
struct team {
    char name[30];
    int p, q;
} t[5], *pt[5], *tmp;
int maxx;
int max3int(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

int main() {
    int i, j;
    for (i = 0; i < 3; i++) pt[i] = t + i;
    for (i = 0; i < 3; i++) scanf("%s%d%d", t[i].name, &(t[i].p), &(t[i].q));
    for (i = 0; i < 3; i++)
        for (j = 0; j < i; j++)
            if (strcmp(pt[j]->name, pt[j + 1]->name) > 0)
                tmp = pt[j], pt[j] = pt[j + 1], pt[j + 1] = tmp;
    maxx = max3int(pt[0]->p, pt[1]->p, pt[2]->p);
    if(pt[0]->p==maxx)printf("%s ",pt[0]->name);
    if(pt[1]->p==maxx)printf("%s ",pt[1]->name);
    if(pt[2]->p==maxx)printf("%s ",pt[2]->name);
    putchar('\n');
    maxx = max3int(pt[0]->q, pt[1]->q, pt[2]->q);
    if(pt[0]->q==maxx)printf("%s ",pt[0]->name);
    if(pt[1]->q==maxx)printf("%s ",pt[1]->name);
    if(pt[2]->q==maxx)printf("%s ",pt[2]->name);
    putchar('\n');
    for(i=0;i<3;i++)pt[i]->q+=pt[i]->p;
    maxx = max3int(pt[0]->q, pt[1]->q, pt[2]->q);
    if(pt[0]->q==maxx)printf("%s ",pt[0]->name);
    if(pt[1]->q==maxx)printf("%s ",pt[1]->name);
    if(pt[2]->q==maxx)printf("%s ",pt[2]->name);
    putchar('\n');
    return 0;
}
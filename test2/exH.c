#include<stdio.h>
#define MAX 100
struct NODE{
	int l,r;
	int w;
	struct NODE *ls,*rs;
};
typedef struct NODE node;
node buf[MAX];
int newbuf;
int Initialization(

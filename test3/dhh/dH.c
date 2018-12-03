#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	long long  n, i,a, b, d, e, f, i2; char c; int m = 0,h;
	scanf("%lld", &n);
	int an[1000];
	for (i = 1; i <= n; i++)
	{
		scanf("%lld%lld", &a, &b); f = 0;
		for (i2 = 1; i2 <= (a - 1) / 2; i2++)
		{
			//while((c=getchar())==' ');
			scanf(" %c" , &c);
			scanf("%lld", &e);
			if (c == '+') b = b+e;
			if (c == '-') f = f+e;
			if (b < f) { m++; an[m] = i; break; }
		}
	}
	printf("%d\n", m);
	for(h=1;h<=m;h++)
	{
		printf("%d\n", an[h]);
	}
	//system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	long long  n, i, a, b,c, d, e ,m = 0;
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &a);
		if (a==10) {
			scanf("%lld", &c);
			b = c; e = 0;
			while (c > 0) {
				e = e + (c % 2)*pow(10,m );
				c = c / 2;
				m++;
			}
			m = 0;
			printf("%lld %llo %llX\n", e, b, b);
			e = 0;
		} else if(a==2||a==8) {
			scanf("%lld%lld", &c, &d);
			while (d > 0) {
				e = e + (d % 10)*pow(a, m);
				d = d / 10;
				m++;
			}
			m = 0;
			printf("%lld\n", e);
			e = 0;
		} else {
			char h; m = 0;
			scanf("%lld", &c);
			for (e = c; e > 0; e--) {
				while((h=getchar())==' ');
				//scanf("%c",& h);
				switch (h) {
					case 'A':m += 10*pow(16, e - 1);
							 break;
					case'B':m += 11 * pow(16, e - 1);
							break;
					case'C':m += 12 * pow(16, e - 1);
							break;
					case'D':m += 13* pow(16, e - 1);
							break;
					case'E':m += 14 * pow(16, e - 1);
							break;
					case'F':m += 15 * pow(16, e - 1);
							break;
				}
			}
			printf("%lld\n", m);
		}
	}
	//system("pause");
	return 0;
}

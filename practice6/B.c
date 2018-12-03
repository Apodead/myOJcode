#include <math.h>
#include <stdio.h>
#define e 2.71828182845904523536
double y, l, r, m, tmp;
const double acc = 1e-7;
int main() {
    scanf("%lf", &y);
    l = 0.33, r = 10;
    const double pi = acos(-1);

    while (r - l > acc) {
        m = (r + l) / 2;
        tmp = sin(sqrt(m)) + pow(e, -pow(m, 1.0 / 3));
        tmp /= log(pi * m);
        tmp -= y;
        if (tmp < 0)
            r = m;
        else
            l = m;
    }
    printf("%.5lf", (r + l) / 2);
    return 0;
}
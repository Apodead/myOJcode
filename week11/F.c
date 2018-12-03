#include <math.h>
#include <stdio.h>

int main() {
    double y;
    double pi = acos(-1), acc = 0.000001;
    double e = 2.7182818284590452353602874;
    double l = 0.33, r = 10, m;
    double fm;
    scanf("%lf", &y);
    while (r - l > acc) {
        // xn=(cos(sqrt(x))/2/sqrt(x)+pow(e,-pow(x,1.0/3))*log(pi*x)+1/x/log(pi)*(sin(sqrt(x))+pow(e,-pow(x,1.0/3))))/(pow(log(pi*x),2));
        m = (r + l) / 2;
        fm = sin(sqrt(m)) + pow(e, -pow(m, 1.0 / 3));
        fm /= log(pi * m);
        fm -= y;
        if (fm > 0)
            l = m;
        else
            r = m;
    }
    printf("%.5lf", l);
    return 0;
}

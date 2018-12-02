#include <stdio.h>

union num {
    int a;
    float b;
};
int main() {
    int sig, exp, fra;
    union num tmp;
    scanf("%x", &tmp.a);
    sig = (tmp.a & (0x80000000)) >> 31;
    exp = (tmp.a & (0x7f800000)) >> 23;
    fra = (tmp.a & (0x007fffff));
    if (!(exp == 0xff && fra)) tmp.b *= 2;
    printf("%#x", tmp.a);
    return 0;
}

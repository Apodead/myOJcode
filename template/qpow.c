#include <stdio.h>

long long qpow(long long x, int y) {
  long long ans = 1;

  while (y) {
    if (y & 1)
      ans *= x;
    x *= x;
    y >>= 1;
  }
  return ans;
}

int main() {
  long long x, y, ans;
  scanf("%lld %lld", &x, &y);
  ans = qpow(x, y);
  printf("%lld", ans);
  return 0;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int extgcd(int a, int b, int *x, int *y) {
  int ans;
  if (!b) {
    *x = 1, *y = 0, ans = a;
  } else {
    ans = extgcd(b, a % b, y, x);
    *y -= (a / b) * *x;
  }
  return ans;
}

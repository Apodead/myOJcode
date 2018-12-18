#include <stdio.h>

long long solve(int n, int m, int p, int q) {
    long long ans = 0;
    int nn, mm, pp, qq;
    // if(p==1)
    // return q;
    // return solve(m,n-1,m-q+1,p-1)+n;
    while (p != 1) {
        ans += m;
        nn = n, mm = m, pp = p, qq = q;
        n = mm, m = nn - 1, p = mm - qq + 1, q = pp - 1;
    }
    ans += q;
    return ans;
}
int main() {
    int m, n, p, q;
    scanf("%d%d%d%d", &n, &m, &p, &q);
    printf("%lld", solve(n, m, p, q));
    return 0;
}

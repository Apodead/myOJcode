#include <stdio.h>
#define MAXN (int)1e6 + 5
unsigned int m_max, m_min, size, m_array[MAXN];
unsigned int maxn[MAXN], minn[MAXN];
long long ans, gap;
unsigned int i, j, range, bucketnum;
int Sort() {
    if (m_max == m_min)
        return 1;
    bucketnum = (m_max - m_min) / (size + 1);
    range = (m_max - m_min) / bucketnum;
    for (i = 0; i <= range; i++)
        maxn[i] = 0, minn[i] = 0xffffffff;
    unsigned int i, g;
    for (i = 0; i < size; i++) {
        g = (m_array[i] - m_min) / bucketnum;
        if (maxn[g] < m_array[i])
            maxn[g] = m_array[i];
        if (minn[g] > m_array[i])
            minn[g] = m_array[i];
    }
    return 0;
}
int main() {
    int inputtmp;
    // printf("%u\n",0xffffffff);
    while (scanf("%d", &size) > 0) {
        m_max = 0, m_min = 0xffffffff;
        ans = gap = 0;
        for (i = 0; i < size; i++) {
            scanf("%d", &inputtmp);
            // printf("%lld\n",inputtmp);
            m_array[i] = (unsigned int)(inputtmp ^ 0x80000000);
            m_min = m_min < m_array[i] ? m_min : m_array[i];
            m_max = m_max > m_array[i] ? m_max : m_array[i];
        }
        // printf("%u,%u\n",m_min,m_max);
        if (Sort()) {
            printf("0\n");
            continue;
        }
        for (i = 1; i <= range; i++) {
            if (maxn[i] < minn[i]) {
                j = i;
                while (j < range && maxn[j] < minn[j])
                    j++;
                gap = minn[j] - maxn[i - 1];
                i = j;
            }
            if (gap > ans)
                ans = gap;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

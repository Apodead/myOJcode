#include <stdio.h>
#define MAXN (int)1e6 + 5
long long m_max, m_min, size;
long long m_array[MAXN], m_addr[MAXN], m_point[MAXN];
int Sort() {
    int i;
    if (m_max == m_min) return 1;
    for (i = 1; i < size; i++) {
        int j = (m_array[i] - m_min) * (size - 2) / (m_max - m_min) + 1;
        m_addr[j] = m_addr[j] + 1;
    }
    for (i = 2; i < size; i++) m_addr[i] += m_addr[i - 1];
    for (i = size - 1; i > 0; i--) {
        int k = i;
        int g = m_addr[(m_array[k] - m_min) * (size - 2) / (m_max - m_min) + 1];
        while (m_point[g] != 0) {
            if (m_array[k] > m_array[m_point[g]]) {
                int t = k;
                k = m_point[g];
                m_point[g] = t;
            }
            g = g - 1;
        }
        m_point[g] = k;
    }
    return 0;
}
int main() {
    long long i, ans, gap;
    while (scanf("%lld", &size) > 0) {
        m_max = 0, m_min = 1LL << 33;
        ans = gap = 0;
        for (i = 0; i <= size; i++) m_array[i] = m_point[i] = m_addr[i] = 0;
        for (i = 1; i <= size; i++) {
            scanf("%lld", m_array + i);
            m_array[i] += 1LL << 32;
            m_min = m_min < m_array[i] ? m_min : m_array[i];
            m_max = m_max > m_array[i] ? m_max : m_array[i];
        }
        size++;
        Sort();
        size--;
        for (i = 1; i < size; i++) {
            gap = m_array[m_point[i + 1]] - m_array[m_point[i]];
            if (gap > ans) ans = gap;
        }
        printf("%lld\n", ans);
    }
    return 0;
}


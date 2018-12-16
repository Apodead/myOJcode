# 第五次练习题解

本次练习赛共19题。

## 解答情况

- A lx放球：通过率：532/548 (97.08%)    正确率：532/649 (81.97%)
- B lx的简单题：通过率：378/450 (84.00%)    正确率：378/1033 (36.59%)
- C login走迷宫：通过率：371/395 (93.92%)    正确率：371/543 (68.32%)
- D 悠唯的复读序列：通过率：421/438 (96.12%)    正确率：421/639 (65.88%)

## A lx放球

**题意**:n个不同的球放入r个相同的盒子中，不允许有空盒，一共有多少种方法放球。本题实际上考察的是第二类**斯特林数**（Stirling numbers）。关于斯特林数的介绍可参见 [维基百科](https://zh.wikipedia.org/wiki/%E6%96%AF%E7%89%B9%E7%81%B5%E6%95%B0)。关于放球问题可以参见 [百度百科](https://baike.baidu.com/item/%E6%94%BE%E7%90%83%E9%97%AE%E9%A2%98)

**解题思路**：显然，当球数少于盒子的数目时，$F(n,r)=0$。当n个球放入1个盒子中，或者n个球放入n个盒子中时，显然各只有一种方法放置。因此有

$$
F(n,n)=F(n,1)=1
$$

考虑第n个球，有两种情况：n单独放在一个盒子中，前n-1个球放在k-1个盒子中；或者前n-1个球放在k个盒子中，再把n放到任意一个盒子中。因此$F(n,r)$的递推关系将由两部分组成：

$$
F(n,r)=F(n-1,r-1)+rF(n-1,r)
$$

代码如下

```c
//Provid by blackap
#include<stdio.h>

int solveF(int n, int r){
    if(n<r)return 0;
    if(r==1||n==r)return 1;
    return solveF(n-1,r)*r+solveF(n-1,r-1);
}
int main(){
    int n,r;
    scanf("%d%d",&n,&r);
    printf("%d",solveF(n,r));
    return 0;
}
```

---

## B lx的简单题

**题意**：本题求相差最小的两个数。

**解题思路**：容易得到，不存在一个数，其值介于相差最小的两数之间，因此，对数据进行排序之后，相差最小的两数必然是相邻的。我们可以先将数据进行排序，再依次求出相邻两数的差并维护一个最小值,即可求得答案。注意，题目要求“输出符合要求的最小的两个数”，那么如果按照升序排列数据，就要尽可能的选择靠前的数据（即，从前向后遍历，只有遇到一组数据的差比当前最小值小时，才更新最小值；若差等于最小值则不更新最小值）。

**关于排序**：本题数据规模较大（$1 \times 10^5$)，使用冒泡排序等简单算法很有可能超时，因此可使用快速排序、归并排序等$O(Nlog(N))$算法或者使用`qsort()`函数。**注意，由于差会超出`int`的范围，为`qsort()`编写比较函数时务必不要直接相减。**

使用归并排序的版本：

```c
#include <stdio.h>

typedef long long T;
int cmpInt(T a, T b) { return a > b; }

// function 'compare' return 0 when they are sorted
// mergesort will sort array from array[l] to array[r-1]
void mergesort(T *array, T *buffer, int (*compare)(T a, T b), int l, int r) {
    int i, j, k;
    if (r - l < 2)
        return;
    mergesort(array, buffer, compare, l, (l + r) / 2);
    mergesort(array, buffer, compare, (l + r) / 2, r);
    for (i = l, j = (l + r) / 2, k = l; i < (l + r) / 2 && j < r; k++) {
        if (compare(array[i], array[j]))
            buffer[k] = array[j++];
        else
            buffer[k] = array[i++];
    }
    while (i < (l + r) / 2)
        buffer[k++] = array[i++];
    while (j < r)
        buffer[k++] = array[j++];
    for (i = l; i < r; i++)
        array[i] = buffer[i];
}
int n, i;
long long ansn, ans;
long long num[100005];
long long buf[100005];
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%lld", num + i);
    mergesort(num, buf, cmpInt, 0, n);
    for (i = 1, ansn = num[0], ans = num[1] - num[0]; i < n - 1; i++) {
        if (num[i + 1] - num[i] < ans)
            ans = num[i + 1] - num[i], ansn = num[i];
    }
    printf("%lld %lld", ansn, ans + ansn);
    return 0;
}
```

使用`qsort()`的版本：

```c
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    long long result = *(long long *)a - *(long long *)b;
    if (result > 0)
        return 1;
    else if (result == 0)
        return 0;
    else
        return -1;
}
int n, i;
long long ansn, ans;
long long num[100005];
long long buf[100005];
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%lld", num + i);
    qsort(num, n, sizeof(long long), cmp);
    for (i = 1, ansn = num[0], ans = num[1] - num[0]; i < n - 1; i++) {
        if (num[i + 1] - num[i] < ans) ans = num[i + 1] - num[i], ansn = num[i];
    }
    printf("%lld %lld", ansn, ans + ansn);
    return 0;
}
```


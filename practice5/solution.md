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
---

## C login 走迷宫

**题意**：从矩形左上角顺时针螺旋形向中心前进，到达指定位置需要几步。

**解题思路**：本题可以使用模拟的方式解决，但是直接模拟难免超时，因此应对模拟进行一定的优化。

下面提供一种思路：
* 假设一个n行m列的矩形，目标在a行b列，设所需步数为$f(n,m,a,b)$。
* 如果a=1，那么所需步数显然为b-1；
* 如果目标位置不在第一行，那么我们先走m步，然后将矩形逆时针旋转90°之后，很容易发现问题变成了更小的一种情况：
  * m行n-1列的矩形，目标位于m-b+1行a-1列,即$f(m,n-1,m-b+1,a-1)$
* 因此，我们可以得到

$$
f(n,m,a,b)=\left\{
\begin{aligned}
&b-1,    & a=1, \\
&f(m,n-1,m-b+1,a-1)+m, &a \neq 1
\end{aligned}
\right.

$$

代码如下。注意，出于优化目的，此代码中尾递归改为循环。将注释取消即可改为使用递归的版本。

```c
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
```

---

## D 悠唯的复读序列

**解题思路**：由题意显然有

$$
\begin{aligned}
f[1]&=f[2]=f[3]=1,\\
f[i]&=(f[i-2]+f[i-3])\mod 100000007
\end{aligned}
$$

循环求出即可。不使用递归主要是因为递归层数过多可能导致爆栈。
代码如下

```c
#include<stdio.h>
int n;
int in[105];
long long f[500005];
int i,j;
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",in+i),j=in[i]>j?in[i]:j;
    for(f[1]=f[2]=f[3]=1,i=4;i<=j;i++)
        f[i]=f[i-2]+f[i-3],f[i]%=100000007;
    for(i=0;i<n;i++)
        printf("%lld\n",f[in[i]]);
    return 0;
}
```

---

## E Anagrams

**解题思路**：分别对两个字符串进行排序，然后判断是否相同即可。

代码如下。(可以使用qsort以避免自行编写排序函数)

```c
#include<stdio.h>
#include<string.h>
typedef char T;
int cmpnum(T a,T b){return a>b;}

void quickSort(T* array, int(*compare)(T a,T b), int l, int r){
    int i,j;
    T mid;
    if(r-l<2)
        return;
    for(i=l,j=r-1,mid=array[l];i<j;){
        while(!compare(mid,array[j])&&i<j)j--;
        array[i]=array[j];
        while(!compare(array[i],mid)&&i<j)i++;
        array[j]=array[i];
    }
    array[i]=mid;
    quickSort(array,compare,l,i);
    quickSort(array,compare,i+1,r);
}

char p[255],q[255];
int main(){
    //scanf("%s\n%s",p,q);
    fgets(p,200,stdin);
    fgets(q,200,stdin);
    quickSort(p,cmpnum,0,strlen(p));
    quickSort(q,cmpnum,0,strlen(q));
    if(strcmp(p,q))
        printf("NIE");
    else 
        printf("TAK");
    return 0;
}
```

---

## F 求和

**解题思路**：第i个数字串为dddd...dd(一共ai个d)，按照题意构造数字串求和即可。

代码如下

```c
#include <stdio.h>

long long a[10], ans;
int d, n;
int geta(int len) {
    if (!a[len])
        for (int i = 0; i < len; i++) {
            a[len] = a[len] * 10 + d;
        }
    return a[len];
}
int main() {
    int i, tmp;
    scanf("%d%d", &d, &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &tmp);
        ans += geta(tmp);
    }
    printf("%lld", ans);
    return 0;
}
```

---

## G Max的最简真分数

**解题思路**：从大到小穷举所有可能的情况即可。可通过求最大公约数来判断是否是真分数。

代码如下

```c
#include <stdio.h>

int n, a, b;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
    scanf("%d", &n);
    for (a = n / 2, b = n - a; a && gcd(a, b) != 1; a--, b++)
        ;
    printf("%d %d", a, b);
    return 0;
}
```

---

## H 熊大的座位表

**解题思路**：容易找到规律：从左往右先是由大到小的第奇数个人直到第1个人，然后是从第2个人开始由小到大的第偶数个人。按照规律输出即可。

代码如下

```c
#include <stdio.h>

int n, a[1005];
int main() {
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    i = n % 2 ? n : n - 1;
    for (; i > 0; i -= 2) printf("%d ", a[i]);
    for (i = 2; i <= n; i += 2) printf("%d ", a[i]);
    return 0;
}
```

---

## I F7

**解题思路**：注意到总冠军可能的得分显然有一个最小值，因此我们先将选手按照之前比赛的成绩进行排序，然后从高到底依次把1~n分分配给他们，并求出之后的最大值，显然这就是总冠军的最低得分。因此我们给每位选手的“之前成绩”加上n分，大于等于总冠军最低得分就有可能夺冠。

代码如下

```c
#include <stdio.h>
typedef int T;
int cmpInt(T a, T b) { return a > b; }

void quickSort(T *array, int (*compare)(T a, T b), int l, int r) {
    int i, j;
    T mid;
    if (r - l < 2) return;
    for (i = l, j = r - 1, mid = array[l]; i < j;) {
        while (compare(mid, array[j]) && i < j) j--;
        if (i < j) array[i++] = array[j];
        while (compare(array[i], mid) && i < j) i++;
        if (i < j) array[j--] = array[i];
    }
    array[i] = mid;
    quickSort(array, compare, l, i);
    quickSort(array, compare, i + 1, r);
}

int pt[300007], n;
int maxn, max, ans;
int maxPoint;

int main() {
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", pt + i);
    }
    quickSort(pt, cmpInt, 0, n);
    for (i = 0; i < n; i++)
        if (maxPoint < pt[i] + i + 1) maxPoint = pt[i] + i + 1;
    for (i = 0; i < n; i++) {
        if (pt[i] + n >= maxPoint) ans++;
    }
    printf("%d", ans);
    return 0;
}
```

```

## J 等差数列

**解题思路**：一个等差数列显然是**有序**的，因此我们可以先将输入数据排序，然后依次对相邻两项做差，判断是否是等差数列。

代码如下（使用了快速排序算法，可以用qsort代替）


```c
#include <stdio.h>
#include <stdlib.h>
typedef int T;
int cmpInt(T a, T b) { return a < b; }
int cmp(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}

void quickSort(T *array, int (*compare)(T a, T b), int l, int r) {
    int i, j;
    T mid;
    if (r - l < 2) return;
    for (i = l, j = r - 1, mid = array[l]; i < j;) {
        while (compare(mid, array[j]) && i < j) j--;
        if (i < j) array[i++] = array[j];
        while (compare(array[i], mid) && i < j) i++;
        if (i < j) array[j--] = array[i];
    }
    array[i] = mid;
    quickSort(array, compare, l, i);
    quickSort(array, compare, i + 1, r);
}
int n, num[(int)1e6 + 5];
int i, gap;
int main() {
    scanf("%d", &n);
    if (n == 1 || n == 2) {
        printf("Yes");
        return 0;
    }
    for (i = 0; i < n; i++) scanf("%d", num + i);
    //quickSort(num, cmpInt, 0, n);
    qsort(num,n,sizeof(int),cmp);
    gap = num[1] - num[0];
    for (i = 2; i < n; i++)
        if (num[i] - num[i - 1] != gap) {
            printf("NO");
            return 0;
        }

    printf("Yes");
    return 0;
}
```

---

## K lx的难题

> 这种类型的题目被称为“[相邻最大插值](https://www.baidu.com/s?wd=%E7%9B%B8%E9%82%BB%E6%9C%80%E5%A4%A7%E5%B7%AE%E5%80%BC&ie=UTF-8)”，在知乎上有一个漫画版的详解：[漫画算法：无序数组排序后的最大相邻差值](https://zhuanlan.zhihu.com/p/32434125)

**解题思路**：本题其实与B lx的简单题思路相同，即排序后做差求最大值即可。

**坑点**：

* 多组输入
* 数据规模
  * 由于数据规模过大，AC本题需要使用O(n)的算法（甚至还卡常数！过分！）
  * 一种考虑是使用桶排序，关于桶排序算法可以[看这里(Wikipedia)](https://zh.wikipedia.org/wiki/%E6%A1%B6%E6%8E%92%E5%BA%8F)或[百度百科]()
  * 将桶数设为n+1，那么排序完成后一定会出现**至少一个**空桶，并且由于桶排序的特性，空桶不会出现在两端。
  * 显而易见，相差最大的两个数，一定会出现在空桶的两侧。因此，对每个空桶分别找其左侧的最大值，和右侧的最大值，即可找到一对候选。
    * 同时我们可以发现每个桶**只需维护最大值和最小值**即可。
  * 比较每一对候选即可得到最大差值。
  * **！！本题卡常数：请使用int类型数组，long long类型会导致TLE！！**

```c
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
```

---

## L lx学长做乘法2

> 出题人给出的参考资料
> [IEEE 754 - Wikipeida](https://zh.wikipedia.org/wiki/IEEE_754) (浮点格式标准文档)
> [你应该知道的浮点数基础知识](https://www.cnblogs.com/cenalulu/p/4397360.html)

**解题思路**：直接看相关标准文档[IEEE 754](https://zh.wikipedia.org/wiki/IEEE_754)~~并手动实现浮点格式读写和乘法~~ 并利用位运算以及联合体（union）取巧解决。
* 预备知识：[联合体union](https://zh.cppreference.com/w/cpp/language/union)  其实只需要知道联合体内部的多个变量共用同一块内存即可。
* 读入：给出的输入是一个float类型浮点数的内存表示，我们可以用一个int类型读入这个数，来保证实际存在内存中的数据与输入一致
* 分段：根据文档，float在内存中有三段：符号位sig，指数段exp，有效数字段fraction，可以通过位运算取出
* 判断是否合法：根据相关规则判断是否合法即可。NaN的特征：指数段二进制全为1，有效数字段非0。
* 浮点乘法：由于联合体中的int类型a和float类型b共用内存，因此直接对b进行乘法操作即可。
* 输出：要求输出内存表示，仍然通过int类型输出为16进制。

代码如下

```c
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
```
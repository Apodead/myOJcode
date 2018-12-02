#include<stdio.h>
#define MAXN (int)1e6+5
int m_max,m_min,size;
int m_array[MAXN],m_addr[MAXN],m_point[MAXN];
int Sort() 
{ 
    int i; 
    // 取得数组中的最大值和最小值 
    //GetMaxMin(); 
    if( m_max == m_min ) 
    { 
        //cout<< "End SupperSort" << endl; 
        return 1; 
    } 
    // 对冲突元素进行分组计算 
    for(i=1;i<size;i++) 
    { 
        int j=(m_array[i]-m_min)*(size-2)/(m_max-m_min)+1; 
        m_addr[j] = m_addr[j]+1; 
    }

    // 找出每个元素的散列地址区间，即散列末地址 
    for(i=2;i<size;i++) 
        m_addr[i] += m_addr[i-1];

    // k从n到1，依次计算源数组的散列地址区间，若该地址的m_point指针为空，说明无冲突，则将k放入m_point指针； 
    // 若m_point指针不空，则将k前推用插入的方法直接插入到m_point指针 
    for(i=size-1;i>0;i--) 
    { 
        int k=i; 
        int g=m_addr[(m_array[k]-m_min)*(size-2)/(m_max-m_min)+1]; 
        while(m_point[g]!=0) 
        { 
            if( m_array[k]>m_array[m_point[g]] ) 
            { 
                int t = k; 
                k = m_point[g]; 
                m_point[g] = t; 
            } 
            g = g-1; 
        } 
        m_point[g] = k; 
    }
    return 0; 
}
int main(){
    int i;
    scanf("%d",&size);
    m_max=1<<31,m_min=m_max-1;
    for(i=0;i<=size;i++)
        m_array[i]=m_point[i]=m_addr[i]=0;
    for(i=1;i<=size;i++){
        scanf("%d",m_array+i);
        m_min=m_min<m_array[i]?m_min:m_array[i];
        m_max=m_max>m_array[i]?m_max:m_array[i];
    }
    size++;
    Sort();
    size--;
    for(i=1;i<=size;i++){
        printf("%d ",m_array[m_point[i]]);
    }
    return 0;
}


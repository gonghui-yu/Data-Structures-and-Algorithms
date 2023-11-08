# 数据结构与算法

程序 = 数据结构 + 算法

数据结构是一门研究***非数值计算***的程序设计中计算机的***操作对象***以及它们之间的***关系***和***操作***的学科。

## 算法分析

### 正确性、可读性、健壮性

### 高效性
* 时间效率：算法执行所耗费的时间
* 空间效率：算法执行所耗费的存储空间
* ***时间效率和空间效率有时候是矛盾的***

* 度量方法
   * 事后统计：将算法实现，测算其时间和存储空间开销
   * 事前分析：对算法所消耗的资源的一种估算方法

事前分析
  * 算法运行时间 = 一个简单操作所需的时间 x 简单操作次数
  * 算法运行时间 = Σ 每条语句的执行次数 x 该语句执行一次所需的时间

```C++
for {i = 1; i < n; i ++}{   // 执行n+1次，其中n次进入循环体，最后一次执行完结束循环
    for(j = 1; j < n; j++){ // 执行n*(n+1)次
        c[i][j] = 0;    // 执行n*n次
        for(k = 0; k < n; k++){ //执行n*n*(n+1)次
            c[i][j] = c[i][j] + a[i][k] * b[k][j];  // 执行n*n*n次
        }
    }
}
```

#### 时间复杂度
若有某个辅助函数f(n)，使得当n趋近于无穷大时，T(n)/f(n)的极限值为不等于零的常数，则称f(n)是T(n)的同数量级函数。记作T(n) = O(f(n))，称O(f(n))为算法的***渐进时间复杂度***，简称***时间复杂度***。  

例：  T(n) = 2n^3 + 3n^2 + 2n +1  
当n -> ∞ 时，T(n) / n^3 -> 2，这表示n充分大时，T(n)和n^3同阶或同数量级，引入“O”记号，则T(n)可记作：T(n) = O(n^3)

```C++
i = 1; // 语句 1
while(i <= n>){
    i = i * 2; // 语句 2
}

// 若循环执行1次，i = 1 x 2 = 2
// 若循环执行2次，i = 1 x 2 x 2 = 2^2
// 若循环执行3次，i = 1 x 2 x 2 x 2 = 2^3
// 若循环执行x次，i = 2^x
// 假设语句2执行x次，且循环条件为i <= n
// 则2^x <= n，则x <= log2 n
```
随n的增大，不同数量级递增情况
| n | f(1) | f(logn) | f(n) | f(nlogn) | f(n^2) | f(n^3) | f(2^n) | f(n!) |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | 1 | 0 | 1 | 0 | 1 | 1 | 2 | 1 |
| 2 | 1 | 1 | 2 | 2 | 4 | 8 | 4 | 2 |
| 4 | 1 | 2 | 4 | 8 | 16 | 64 | 16 | 24 |
| 8 | 1 | 3 | 8 | 24 | 64 | 512 | 256 | 40320 |
| 16 | 1 | 4 | 16 | 64 | 256 | 4096 | 65536 | 2.0923E+13 |
| 32 | 1 | 5| 32 | 160 | 1024 | 32768 | 4.295E+09| 2.6313E+35 |

#### 空间复杂度
算法所需存储空间的度量，记作：s(n) = O(f(n))

算法要占据的空间包含：  
  * 算法本身要占据的空间，输出/输出，指令，常数，变量等
  * 算法要使用的辅助空间

```C++
// 将一维数组逆序
// 算法1
// 空间复杂度：S(n) = O(1)
for(i = 0; i < n / 2; i++)
{
    t = a[i];
    a[i] = a[n - i - 1];
    a[n - i - 1] = t;
}

// 算法2
// 空间复杂度：S(n) = O(n)
for(i = 0; i < n / 2; i++)
{
    b[i] = a[n - i - 1];
}
for(i = 0; i < n; i++)
{
    a[i] = b[i];
}

```
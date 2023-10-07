# function_1 的list

---

## 头文件

```C
#include<stdio.h>
#include<time.h> 
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<windows.h>
#define Dar(a,n,m,i,j) *(a + i*n + j)//二维数组
```

---

## 函数

### 打印字符

`void PrintS(long time, char ch) {};`

### 判断正负

`int ZorF(float n) {};`

### 能负数的pow

`double powplus(double n, double m) {};`

### 打印长为len的string

`void Print_string_lenth(char *x, int len) {};`

### c语言交换两个数

`void pswp(int *x, int *y) {};`

### 打乱数组

```C
#include<time.h> #include<stdlib.h>
//打乱从1~num
`void Random_card(int *cat_card, int num) {};
```

### 字符串变成数组

但是倒着输入
`void Str_To_Num(char *xs, int *x, int *lenx) {};`

### 比较同位数x与y的大小

x大或者等返回1，否则0
`int JudgeBigBigNum(int *x, int *y, int l) {};`

### 将a取logn

`void Log(double *a, int n) {};`

### 输出logna

`double logn(int a, int n) {};`

### 数组存小数

`void Cal_xs(int *num, int a, int b, int size) {};`

### 更改字体颜色

`//0黑色 1蓝色 4红色 6黄色，10绿色 15白色`
`void textcolor(int color) {};`

### 这里是结构体

```C
struct student 
{
    char name[1000];
    int age, grade;
} mojo, hh, hhh;   //有两种形式。 
//也可以这样(C好像还要加一个struct)student b, c, d; //有两种形式。可以在这里也可以在上面。
```

### 交换结构体的值 注意修改结构体名称

`void SWAP(int i, int j, struct student *ability) {};`

### 转换一个数12345-->54321

`int Turnaway(int x) {};`

### 进制转换 m(hh)->m(10)

`int hhToin(int m, int hh) {};`

### 边界x不超过n

`int Bound(int x, int n) {};`

### 输入数字

`void Pre_0Num(int *N) {};`

### 递归turnaway

`int RecTurnaway(int n) {};`

### 数组转成整数k是位数

`long ArrToInt(int a[], int k);`

### 记录时间

`void timecnt();`
`void timecnt2();`

### 判断升序

`bool JudgeUp(int a[], int l, int r);`

### 猴子排序l~r，Judge & pswp

`void monkey(int *a, int l, int r);`

### double取模

`double Mol(double x, int p);`

### 小写转换 strlwr(x)

#include"function_1.h"
//小写转换 strlwr(x)

#define F(i,n,m) for(int i=n;i<=m;i++)//灵性define，减少码量（for打得我烦） 

//打印字符
void PrintS(long time, char ch){
    for(long i=0; i < time; i++) printf("%c",ch);
}

//判断正负
int ZorF(float n){
    if(n>0) return 1;
    if(n=0) return 0;
    return -1;
}

//能负数的pow
double powplus(double n, double m){
    if(n > 0.0) return pow(n,m);
    if(n < 0.0) return -pow(-n,m);
    return 0;
}

//打印长为len的string
void Print_string_lenth(char *x,int len){
    for(int i = 0; i < len; i++){
        printf("%c",x[i]);
    }
    printf(" ");
}

//c语言交换两个数
void pswp(int *x,int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

//打乱数组 //#include<time.h> #include<stdlib.h>打乱从1~num
void Random_card(int *cat_card,int num)
{
    srand(time(0));//随机种子
    for(int i=num; i>1; i--){
		int r = rand() % (i+1) + 1;
		if(r != i)
        {
            int R = cat_card[i];
            cat_card[i] = cat_card[r];
            cat_card[r] = R;
        } 
	}
}

//字符串变成数组 但是倒着输入
void Str_To_Num(char *xs,int *x,int *lenx)
{
    memset(x,0,sizeof(x));
    *lenx = strlen(xs);
        for(int j=*lenx-1, r=0; j>=0; r++ , j--)
        {
            x[r] = xs[j] - '0';  //字符串倒着输入到数组 123 就输入成321000000
        }
}

//比较同位数x与y的大小，x大或者等返回1，否则0
int JudgeBigBigNum(int *x,int *y,int l)
{
    for(int i = l; i > 0;i--)
    {
        if(x[i] > y[i]) return 1;
        else if (x[i] == y[i])
        {
            if(i == 1) return 1;
            continue;
        }else return 0;
    }
    return 0;
}

//将a取logn
void Log(double *a,int n)
{
    *a = log(*a)/log(n);
}
//输出logna
double logn(int a,int n)
{
    return (log(a)/log(n));
}

//数组存小数
void Cal_xs(int *num,int a,int b,int size){
    for(int i=0;i<size;i++){
        num[i] = a/b;
        a%=b;
        a*=10;
    }
}

// 更改字体颜色 0黑色 1蓝色 4红色 6黄色，10绿色 15白色
void textcolor(int color) 
{
	//在文本模式中选择新的字符颜色
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); // 得到标准输出的句柄
	SetConsoleTextAttribute(hOutput, color);//Attribute:属性
}

/*
//这里是结构体
struct student {
	char name[1000];
	int age, grade;
} mojo, hh, hhh;   //有两种形式。 
//也可以这样(C还要加一个struct)student b, c, d; //有两种形式。可以在这里也可以在上面。
*/
//交换结构体的值 注意修改结构体名称
void SWAP(int i, int j, struct student *ability)
{
    struct student t = ability[i];
    ability[i] = ability[j];
    ability[j] = t;
}

//转换一个数12345-->54321
int Turnaway(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return sum;
}

//进制转换 m(hh)->m(10)
int hhToin(int m, int hh)
{
    int sum = 0;
    int x = log10(m) + 1;
    for (int i = 0;i < x;i++)
    {
        if (m % 10 >= hh) return -1;
        sum += (m % 10) * pow(hh, i);
        m /= 10;
    }
    return sum;
}

//边界
int Bound(int x, int n)
{
    return (x + n)%n;
}

//输入数字
void Pre_0Num(int *N) {
    while (*N < 2 || *N > 5)
    {
        if (scanf("%d", &N) == 0)
        {
            char *hh;
            scanf("%s", hh);
        }
        textcolor(1);
        printf("请再次输入正确的游戏人数(2-5)");
        textcolor(15);
    }
}

//递归turnaway
int RecTurnaway(int n)
{
    int k = log10(n);
    if (n < 10)
        return n;
    //else
    int upup = n / 10, now = n % 10;
    return RecTurnaway(upup) + now*pow(10,k);
}

//数组转成整数k是位数
long ArrToInt(int a[], int k)
{
    long shu = 0;  //将数组转化成数
    for (int i = 1;i <= k;i++)
    {
        shu = shu * 10 + a[i];
    }
    return shu;
}

//#include<time.h> #include<windows.h>
//记录时间
void timecnt() 
{
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    /// @brief 
    /// @return 
    QueryPerformanceCounter(&t2);
    printf("time %lf\n", (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart);
}
void timecnt2()
{
    clock_t t1, t2;
    t1 = clock();
    /// @brief 
    /// @return 
    t2 = clock();
    printf("time %lf\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
}

//判断升序
bool JudgeUp(int a[], int l, int r)
{
    F(i, l, r-1)
    {
        if (a[i] > a[i + 1])
            return 0;
    }
    return 1;
}

//猴子排序l~r，Judge & pswp
void monkey(int *a, int l, int r)
{
    //cnt++;
    for (int i = r;i >= l;i--)
    {
        int t = rand() % (r - l + 1) + l;
        pswp(&a[i], &a[t]);
    }
    if (!Judge(a, l, r))
        monkey(a, l, r);
}

//double取模
double Mol(double x, int p)
{
    int a = x / p;
    return x - a * p;
}

/*******************************************
struct MyArray
{
    int a[N], len;
    
    void insert(int pos, int x)
    {
        ++len;
        for (int i = len; i > pos; --i)
            a[i] = a[i - 1];
        a[pos] = x;
    }
    
    void erase(int pos)
    {
        --len;
        for (int i = pos; i <= len; ++i)
            a[i] = a[i + 1];
    }
}

 *int main()                            **
{                                       **
    struct MyArray arr;                 **
    int n;                              **
    scanf("%d", &n);                    **
    for (int i = 1; i <= n; ++i)        **
        scanf("%d", &arr.a[i]);         **
    int pos, x;                         **
    scanf("%d%d", &pos, &x);            **
    arr.insert(pos, x);                 **
    arr.erase(pos);                     **
    return 0;                           **
}                                       **
*******************************************/

char *s_gets(char *st, int n) {
    char *retval;
    char *find;

    retval = fgets(st, n, stdin);
    if (retval)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return retval;
}


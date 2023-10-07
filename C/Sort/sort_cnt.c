#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 计数排序
void CountSort(int *a, int n) {
        int max = a[0], min = a[0];
        for (int i = 1; i < n; i++)
        {
                if (a[i] > max)
                        max = a[i];
                if (a[i] < min)
                        min = a[i];
        }//找出数组的最大值和最小值
        int *tmp = (int *)malloc((max - min + 1) * sizeof(int));
        assert(tmp);
        for (int i = 0; i < max - min + 1; i++)
                tmp[i] = 0;
        for (int i = 0; i < n; i++)
                tmp[a[i] - min]++;
        int cur = 0;
        for (int i = 0; i < max - min + 1; i++)
        {
                int x = tmp[i];//数字i+min出现的次数
                for (int j = 0; j < x; j++)
                        a[cur++] = i + min;
        }
        free(tmp);
        tmp = NULL;
}
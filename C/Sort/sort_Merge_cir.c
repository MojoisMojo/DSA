#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MyMin(a,b) (a) < (b) ? (a) : (b)

void sortMerge(int *arr, int arrSize) {
    int groupNum = 1;
    int reg[arrSize];
    while (groupNum < arrSize)
    {
        int k = 0;
        memset(reg, 0, sizeof(reg));
        int left1 = 0, right1 = groupNum - 1, left2 = groupNum, right2 = MyMin(2 * groupNum - 1, arrSize - 1);
        while (left1 < arrSize)
        {
            k = left1;
            //arr[l1~r1] & arr[l2~r2]
            while (left1 <= right1 && left2 <= right2)
                reg[k++] = (arr[left1] < arr[left2] ? arr[left1++] : arr[left2++]);
            while (left1 <= right1)
                reg[k++] = arr[left1++];
            while (left2 <= right2)
                reg[k++] = arr[left2++];

            left1 = right2 + 1;
            left2 = MyMin(left1 + groupNum, arrSize - 1);
            right1 = left2 - 1;
            right2 = MyMin(right1 + groupNum, arrSize - 1);
        }
        for (int i = 0; i < arrSize; i++)
            arr[i] = reg[i];
        groupNum *= 2;
    }
}
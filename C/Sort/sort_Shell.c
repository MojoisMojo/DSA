#include<stdio.h>

int a[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };

void shell_sort(int arr[], int len) {
        int gap, i, j;
        int temp;
        for (gap = len >> 1; gap > 0; gap >>= 1) {
                for (i = gap; i < len; i++) {
                        temp = arr[i];
                        for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                                arr[j + gap] = arr[j];
                        arr[j + gap] = temp;
                }
        }
}
int main() {

        int len = (int)sizeof(a) / sizeof(*a);
        shell_sort(a, len);
        int i;
        for (i = 0; i < len; i++)
                printf("%d ", a[i]);
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX 10

void *my_thread(void *arg) {
    int tmp = *(int *)arg;
    usleep(tmp * 10000);
    printf("%d ", tmp);
}

int main() {
    int a[MAX] = { 11,12,25,36,21,8,0,3,10,14 };
    int j = 0;
    pthread_t thid[MAX];
    for (j = 0;j < MAX;j++) {
        printf("%d ", a[j]);
    }printf("\n");
    for (j = 0;j < MAX;j++) {
        pthread_create(&thid[j], NULL, my_thread, &a[j]);
    }
    for (j = 0;j < MAX;j++) {
        pthread_join(thid[j], NULL);
    }
    printf("\n");
    return 0;
}

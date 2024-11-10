#include <pthread.h>
#include <stdio.h>

pthread_mutex_t fLock, sLock;

void *lockToFirst(void *arg) {
    pthread_mutex_lock(&fLock);
    printf("Thread 1 obteve fLock\n");
    sleep(1);
    pthread_mutex_lock(&sLock);
    printf("Thread 1 obteve sLock\n");
    pthread_mutex_unlock(&sLock);
    pthread_mutex_unlock(&fLock);
    return NULL;
}

void *lockToSecond(void *arg) {
    pthread_mutex_lock(&sLock);
    printf("Thread 2 obteve sLock\n");
    sleep(1);
    pthread_mutex_lock(&fLock);
    printf("Thread 2 obteve fLock\n");
    pthread_mutex_unlock(&fLock);
    pthread_mutex_unlock(&sLock);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&fLock, NULL);
    pthread_mutex_init(&sLock, NULL);

    pthread_create(&t1, NULL, lockToFirst, NULL);
    pthread_create(&t2, NULL, lockToSecond, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&fLock);
    pthread_mutex_destroy(&sLock);
    return 0;
}

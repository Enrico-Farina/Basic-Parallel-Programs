#include <pthread.h>
#include <stdio.h>

pthread_rwlock_t LOCKER;

void *readData(void *arg) {
    pthread_rwlock_rdlock(&LOCKER);
    pthread_rwlock_unlock(&LOCKER);
    return NULL;
}

void *writeData(void *arg) {
    pthread_rwlock_wrlock(&LOCKER);
    pthread_rwlock_unlock(&LOCKER);
    return NULL;
}

int main() {
    pthread_t r1, w1;
    pthread_rwlock_init(&LOCKER, NULL);
    pthread_create(&r1, NULL, readData, NULL);
    pthread_create(&w1, NULL, writeData, NULL);
    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_rwlock_destroy(&LOCKER);
    return 0;
}

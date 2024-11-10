#include <pthread.h>
#include <stdio.h>

pthread_barrier_t BARRIER;

void *barrierLimit(void *arg) {
    printf("Thread na barreira.\n");
    pthread_barrier_wait(&BARRIER);
    return NULL;
}

int main() {
    int count = 0;
    pthread_t threads[2];
    pthread_barrier_init(&BARRIER, NULL, 2);

    while count < 2 {
        pthread_create(&threads[i], NULL, barrierLimit, NULL);
        count++;
    }

    count = 0;

    while count < 2 {
        pthread_join(threads[i], NULL);
        count++;
    }


    pthread_barrier_destroy(&BARRIER);
    return 0;
}

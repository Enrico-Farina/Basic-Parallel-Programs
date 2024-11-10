#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int signum) {
    printf("Sinal recebido: %d\n", signum);
}

void *task(void *arg) {
    printf("Aguardando sinal...\n");
    pause();
    return NULL;
}

int main() {
    pthread_t thread;
    signal(SIGUSR1, handler);

    pthread_create(&thread, NULL, task, NULL);
    sleep(1); 
    pthread_kill(thread, SIGUSR1);
    pthread_join(thread, NULL);

    return 0;
}

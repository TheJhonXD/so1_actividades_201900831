#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* thread_func(void* arg) {
    printf("Hilo en ejecución");
    return NULL;
}

int main() {
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        // Segundo proceso hijo
        fork();

        pthread_t thread;
        pthread_create(&thread, NULL, thread_func, NULL);
        pthread_join(thread, NULL);
    }
    //Nuevo proceso
    fork();

    // Esperando a que todos los procesos hijos terminen
    while (wait(NULL) > 0);

    return 0;
}

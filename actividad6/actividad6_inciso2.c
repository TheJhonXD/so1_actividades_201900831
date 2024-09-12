#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

int main() {
    pid_t pid;
    
    // Nuevo proceso
    pid = fork();
    
    if (pid == 0) {
        // Duermo al hijo por 10 segundos
        printf("Proceso hijo PID: %d.\n", getpid());
        sleep(10);
        
        printf("Proceso hijo terminando.\n");
        // Fin del proceso hijo
        exit(EXIT_SUCCESS);
    } else {
        // El padre no espera a que el hijo termine
        printf("PID del padre %d. PID del hijo %d.\n", getpid(), pid);
        // Duermo al padre para que el hijo se convierta en zombie
        sleep(60);
        
        printf("El proceso padre ha terminado.\n");
        exit(EXIT_SUCCESS);
    }
}

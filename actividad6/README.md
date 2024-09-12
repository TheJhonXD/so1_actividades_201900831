# Actividad 6 - Procesos e Hilos

1. ¿Incluyendo el proceso inicial, cuantos procesos son creados por el siguiente programa?

``` c
#include <stdio.h>
#include <unistd.h>

int main(){
    // fork a child process
    fork();

    // fork another child process    
    fork();

    // and fork another
    fork();

    return 0;
}
```

**Respuesta**: Por cada llamada a fork el numero de procesos se duplica, teniendo esto en cuenta el numero de procesos que crea el programa es de 8, incluyendo el proceso inicial.

2. Utilizando un sistema Linux, escriba un programa en C que cree un proceso hijo (fork) 
que finalmente se convierta en un proceso zombie. Este proceso zombie debe 
permanecer en el sistema durante al menos 60 segundos. 

**Solución en el archivo actividad6_inciso2**

3. Completar el programa para que sea ejecutable y responder las siguientes preguntas:

- ¿Cuántos procesos únicos son creados?

    Se crean **5** procesos únicos

- ¿Cuántos hilos únicos son creados?

    Se crea **1** hilo

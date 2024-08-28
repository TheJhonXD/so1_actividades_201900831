# Tipos de kernel

## 1. Tipos de Kernel y sus diferencias

### Kernel Monolítico

Es un Kernel de gran tamaño que puede gestionar todas las tareas. Se encarga de la gestión de memoria y procesos, así como de la comunicación entre los procesos y el soporte de las diferentes funciones de los drivers y el hardware. Los sistemas operativos que recurren al Kernel monolítico son Linux, OS X y Windows.

- **Ventajas**: Ofrece un rendimiento alto debido a que las operaciones no necesitan cambiar de contexto entre procesos.
- **Desventajas**: Puede ser menos seguro y más difícil de depurar, ya que un fallo en alguna de las partes del kernel puede afectar a todo el sistema.

### Microkernel

Los Kernel que están diseñados con pequeños tamaños tienen una clara función: evitar el colapso total del sistema en caso de un fallo. Para cumplir con todas las tareas como un Kernel monolítico cuenta con diferentes módulos. Es curioso, pero hasta ahora solo el Mach de OS X es el único que utiliza el microkernel.

- **Ventajas**: Es más seguro y modular, ya que los fallos en servicios que corren en el espacio de usuario no afectan al núcleo.
- **Desventajas**: El rendimiento puede ser inferior al de un kernel monolítico debido a la sobrecarga asociada con la comunicación entre procesos.

### Kernel Híbrido

Combinación entre el microkernel y el Kernel monolítico. Nos encontramos ante un Kernel grande, pero compacto y que puede ser modulado y otras partes del mismo Kernel pueden cargarse de manera dinámica. Es utilizado en Linux y OS X.

- **Ventajas**: Intenta ofrecer un equilibrio entre rendimiento y modularidad.
- **Desventajas**: Puede ser más complejo de implementar y mantener.

### Exokernel

La estructura que propone un exokernel es innovadora ya que se estructura de manera vertical. Los núcleos son pequeños y su desarrollo tiene fines investigativos. En un exokernel la toma de decisiones está a cargo de los programas, para hacer el uso de los recursos del hardware en ciertas bibliotecas.

- **Ventajas**: Proporciona gran flexibilidad y eficiencia al permitir a las aplicaciones personalizar sus interacciones con el hardware.
- **Desventajas**: Su complejidad en diseño y desarrollo puede dificultar su adopción.

### Nanokernel

Si el microernel es pequeño, este es todavía más reducido, pero su uso está destinado a sistemas embebidos ya que el nivel de fiabilidad es mayor.

- **Ventajas**: Ideal para entornos muy específicos que requieren un kernel extremadamente ligero.
- **Desventajas**: Limitado en funcionalidad y aplicable solo en nichos muy específicos.

## 2. User Mode vs Kernel Mode

### User Mode

En este modo, el código tiene acceso limitado al hardware y a las áreas críticas del sistema operativo. Las aplicaciones y procesos de usuario se ejecutan en este modo.

- **Seguridad**: El modo usuario previene que el software dañe o interfiera con el sistema operativo o con otros programas. Si un programa intenta acceder a recursos restringidos, se genera una interrupción (trap) que transfiere el control al kernel.
- **Ventajas**: Protege la integridad del sistema y aísla los procesos de usuario.

### Kernel Mode

En este modo, el código tiene acceso completo a todos los recursos del sistema (hardware, memoria, etc.). El kernel del sistema operativo y los controladores de dispositivos se ejecutan en este modo.

- **Seguridad**: Es un modo privilegiado, por lo que cualquier error o vulnerabilidad puede comprometer todo el sistema.
- **Ventajas**: Permite al sistema operativo controlar el hardware y realizar tareas críticas.

## 3. Interrupts vs Traps

Ambos términos se refieren a eventos que alteran el flujo de ejecución normal de un programa.

### Interrupts

Son señales generadas por el hardware o software que interrumpen el flujo de ejecución normal del CPU para atender eventos urgentes o importantes.

Se utilizan para manejar eventos asíncronos, como la llegada de datos desde un dispositivo de entrada/salida.

- **Tipos**:
  - **Interrupciones de hardware**: Provienen de dispositivos de hardware como teclados, ratones, discos duros, etc.
  - **Interrupciones de software**: Generadas por el software para indicar que necesita la atención del kernel.

### Traps (Excepciones)

Son interrupciones generadas exclusivamente por el software, que ocurren como resultado de una condición específica durante la ejecución de un programa.

Son utilizadas para manejar errores y solicitar servicios del sistema operativo.

- **Tipos**:
  - **Traps intencionados**: Por ejemplo, cuando un programa solicita un servicio del sistema operativo a través de una llamada al sistema.
  - **Excepciones**: Se generan cuando ocurre un error durante la ejecución de un programa, como una división por cero o una falla de segmentación.

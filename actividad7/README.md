# Completely Fair Scheduler

El Completely Fair Scheduler (CFS) en el kernel de Linux es un planificador compartido proporcional que divide proporcionalmente el tiempo de la CPU entre grupos de tareas dependiendo de la prioridad/peso de las tareas o partes asignadas a un grupo de tareas. En CFS, un grupo de tareas puede obtener más CPU de la que necesita si hay suficientes ciclos ociosos de CPU disponibles en el sistema, debido a la naturaleza conservadora del planificador.

## Características

1. Equidad: CFS busca proporcionar una distribución justa del tiempo de CPU entre todos los procesos activos, sin importar si son procesos de usuario o del sistema.

2. Modelo basado en vruntime: Cada proceso tiene un valor de "tiempo virtual" (vruntime), que se incrementa a medida que usa la CPU. El proceso con el menor vruntime es el siguiente en ejecutarse.

3. Árbol rojo-negro: Para mantener el orden de los procesos según su vruntime, CFS utiliza un árbol rojo-negro, una estructura de datos balanceada que permite búsquedas, inserciones y eliminaciones en tiempo logarítmico, asegurando eficiencia.

4. Tiempo de ejecución ponderado: CFS pondera el tiempo de CPU en función de la prioridad del proceso, utilizando la noción de "nice value". Los procesos con menor valor nice (mayor prioridad) incrementan su vruntime más lentamente.

5. Sin intervalos de tiempo fijos: A diferencia de los planificadores basados en rondas o cuantums, CFS no utiliza intervalos de tiempo fijos para asignar la CPU. Se enfoca en mantener el vruntime de todos los procesos lo más balanceado posible.

6. Comportamiento de baja latencia: CFS está diseñado para minimizar la latencia de respuesta, lo cual es importante para la interacción de usuario.

7. Debido a su diseño, el gestor de tareas CFS no es proclive a ninguno de los ataques que existen a día de hoy contra los heurísticos del gestor de tareas: fiftyp.c, thud.c, chew.c, ring-test.c, massive_intr.c todos trabajan correctamente y no tienen impacto en la interacción y se comportan de la forma esperada.

8. El balanceo de tareas SMP ha sido rehecho/mejorado: el avance por las colas de ejecución de tareas ha desaparecido del código de balanceo de carga, y ahora se usan iteradores en la gestión de módulos. El balanceo del código ha sido simplificado como resultado esto.

## Funcionamiento

1. Cola de procesos: Los procesos se organizan en un árbol rojo-negro según su vruntime. El proceso con el menor valor de vruntime siempre se encuentra en la raíz del árbol y es el que se selecciona para ejecutarse.

2. Ejecución de procesos: Cuando un proceso utiliza la CPU, su vruntime aumenta. El proceso cede la CPU cuando su vruntime alcanza el valor de los otros procesos en la cola, lo que garantiza que todos tengan una oportunidad equitativa de ejecución.

3. Asignación de tiempos: Los procesos con menor nice reciben más tiempo de CPU, ya que su vruntime aumenta más lentamente en comparación con aquellos con mayor nice.

4. Interrupción y cambio de contexto: Si llega un proceso nuevo o un proceso existente se vuelve elegible para ejecutarse (por ejemplo, un proceso que estaba bloqueado en I/O), se recalcula el proceso que tiene el menor vruntime, lo que puede resultar en un cambio de contexto.

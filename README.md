# OS_UASLP
Ejercicios de la materia de Sistemas Operativos en NachOS

## Parcial 1:
### Tarea 1:
Este es un repaso de las definiciones basicas de lo que se vio en "sistemas Operaivos A". Conceptos basicos para entender y poner en contexto el contenido de esta materia "sistemas operativos B".

#### Proceso:
Es una abstraccion de un programa en ejecución, incluye los valores que tienen el contador de programa, los registros y las variables.

#### Conmutacion de contexto:
Es el hecho de cambiar el turno de procesamiento entre procesos, para ello primero el sistema tiene que interrumpir el proceso en ejecucion  y posteriormente :
1. Guardar el estado del programa que se estaba ejecutando. El estado, también denominado contexto, consiste en los valores de todos los registros del microprocesador. Se copian en la memoria principal.

2. Seleccionar otro programa para ejecutar. Entre todos los programas que estén preparados para ejecutarse, la rutina selecciona uno de ellos siguiendo algún algoritmo equitativo.

3. Restaurar el estado del programa seleccionado. Para ello, se toma el estado previamente copiado en la memoria principal y se vuelca en los registros del microprocesador.

4. Ejecutar el programa seleccionado La rutina termina su ejecución saltando a la instrucción que estaba pendiente de ejecutar en el programa seleccionado.

#### BCP(Bloque de control de procesos):
El bloque de control del proceso (BCP) o en inglés PCB (Process Control Block) es un registro especial donde el sistema operativo agrupa toda la información que necesita conocer respecto a un proceso particular. Cada vez que se crea un proceso el sistema operativo crea el BCP correspondiente para que sirva como descripción en tiempo de ejecución durante toda la vida del proceso.

Cuando el proceso termina, su BCP es borrado y el registro puede ser utilizado para otros procesos. Un proceso resulta conocido para el sistema operativo y por tanto elegible para competir por los recursos del sistema sólo cuando existe un BCP activo asociado a él. El bloque de control de proceso es una estructura de datos con campos para registrar los diferentes aspectos de la ejecución del proceso y de la utilización de recursos. La información almacenada en un BCP incluye típicamente algunos o todos los campos siguientes:

- Identificador de proceso (Process Identificator -PID-, de sus siglas en inglés).
- Estado del proceso. Por ej: listo, en espera, bloqueado.
- Contador de programa: dirección de la próxima instrucción a ejecutar.
- Valores de registro de CPU. Se utilizan también en el cambio de contexto.
- Espacio de direcciones de memoria.
- Prioridad en caso de utilizarse dicho algoritmo para planificación de CPU.
- Lista de recursos asignados (incluyendo descriptores de archivos y sockets abiertos).
- Estadísticas del proceso.
- Datos del propietario (owner).
- Permisos asignados.
- Señales (Signals) pendientes de ser servidas. (Almacenados en un mapa de bits).


Esta lista es simplemente indicativa, cada sistema operativo tiene su propio diseño de BCP, con el conjunto de metadatos necesarios para la administración. Puede medir desde 32 bits a 1024. Su denominación cambia según el sistema operativo.

#### Concurrencia:
Esta palabra intuitivamente la entendemos como la confluencia o el encuentro de varias cosas o procesos en un sólo lugar al mismo tiempo. Cuando un lugar está lleno de gente decimos que “está muy concurrido”. Esto nos puede llevar a confundir el término con paralelismo. En cuanto a las ciencias computacionales, es algo totalmente diferente: es una manera de diseñar, componer o estructurar programas. Concurrencia, entonces, se puede definir de la siguiente forma:
`La composición de elementos (funciones, procesos, programas, etc) que se ejecutan independientemente pero interactúan entre sí. No necesariamente se ejecutan al mismo tiempo.`

#### Paralelismo:
Se refiere a la ejecución simultánea de varios procesos computacionales. Esto significa que se requieren varios medios de ejecución física: varios procesadores (o un procesador con varios núcleos) o varias computadoras (sistemas distribuidos) y la suficiente memoria para mantenerlos. Los procesos pueden estar relacionados entre ellos, para realizar una misma tarea, o no.

El paralelismo está relacionado con la capacidad del sistema en el que se ejecuta el programa, con sus recursos disponibles y que el software lo pueda aprovechar.

#### Multitarea:
Característica de los sistemas operativos modernos que permite que varios procesos o aplicaciones se ejecuten aparentemente al mismo tiempo, compartiendo uno o más procesadores.

Los sistemas operativos multitarea son capaces de dar servicio a más de un proceso a la vez para permitir la ejecución de muchos más programas.

#### Multiprogramación:
Se denomina multiprogramación al concepto de conmutar rapidamente entre procesos. Virtualmente cada proceso tiene su propia CPU; lo que realmente pasa es que un CPU cambia de forma continua de un proceso a otro. Esto con el fin de que aprovechar los recursos(procesamiento del CPU) Teniendo siempre un proceso en ejecución.

#### Estados validos de un proceso:
1. En ejecución(usando la CPU en ese instante).

2. Listo( puede ejecutarse; detenido en forma temporal para permitir que se ejecute otro proceso).

3. Bloqueado(No puede ejecutarse mientras no ocurra cierto suceso externo).

#### Planificador a de procesos:
La planificación de la CPU, en el sentido de conmutarla entre los distintos procesos, es una de las funciones del sistema operativo. Este es llevado a cabo por un pequeño programa llamado planificador a corto plazo o dispatcher (despachador). La misión del dispatcher consiste en asignar la CPU a uno de los procesos ejecutables del sistema, para ello sigue un determinado algoritmo. Para que el dispatcher conmute el procesador entre dos procesos es necesario realizar un cambio de proceso.

Los acontecimientos que pueden provocar la llamada al dispatcher dependen del sistema (son un subconjunto de las interrupciones), pero son alguno de estos:

- El proceso en ejecución acaba su ejecución o no puede seguir ejecutándose (por una E/S, operación WAIT, etc).

- Un elemento del sistema operativo ordena el bloqueo del proceso en ejecución (ver estados de un proceso).

- El proceso en ejecución agota su cuantum o cuanto de estancia en la CPU.

- Un proceso pasa a estado listo.

Hay que destacar el hecho de que cuanto menos se llame al dispatcher menos tiempo ocupa la CPU un programa del sistema operativo, y, por tanto, se dedica más tiempo a los procesos del usuario (un cambio de proceso lleva bastante tiempo).

Así, si sólo se activa el dispatcher como consecuencia de los 2 primeros acontecimientos se estará haciendo un buen uso del procesador. Este criterio es acertado en sistemas por lotes en los que los programas no son interactivos. Sin embargo, en un sistema de tiempo compartido no es adecuado, pues un proceso que se dedicara a realizar cálculos, y no realizara E/S, monopolizaría el uso de la CPU. En estos sistemas hay que tener en cuenta el conjunto de todos los procesos, activándose el dispatcher con la circunstancia tercera y, posiblemente, la cuarta. Los sistema operativos en que las dos siguientes circunstancias no provocan la activación del dispatcher muestran preferencia por el proceso en ejecución, si no ocurre esto se tiene más en cuenta el conjunto de todos los procesos.
Se puede definir el scheduling -algunas veces traducido como -planificación- como el conjunto de políticas y mecanismos construidos dentro del sistema operativo que gobiernan la forma de conseguir que los procesos a ejecutar lleguen a ejecutarse.

El scheduling está asociado a las cuestiones de:

- Cuándo introducir un nuevo proceso en el Sistema.

- Determinar el orden de ejecución de los procesos del sistema.

El scheduling está muy relacionado con la gestión de los recursos. Existen tres niveles de scheduling, estos son:

 1. Planificador de la CPU o a corto plazo.

 2. Planificador a medio plazo.

 3. Planificador a largo plazo.

 
##### Corto plazo:

El planificador a largo plazo se ejecuta con relativa poca frecuencia, tomando una primera decisión sobre si tomar o no un nuevo proceso y cuál tomar. El planificador a medio plazo se ejecuta con algo más de frecuencia, para tomar la decisión del intercambio. El planificador a corto plazo, también conocido como distribuidor (dispatcher), es el de ejecución más frecuente y toma decisiones con un mayor detalle sobre el proceso que se ejecutará a continuación.

El planificador a corto plazo se ejecuta cuando ocurre un suceso que puede conducir a la interrupción del proceso actual o que ofrece la oportunidad de expulsar de la ejecución al proceso actual en favor de otro. Como ejemplos de estos sucesos se tienen:

-         Interrupciones del reloj.

-         Interrupciones de E/S.

-         Llamadas al sistema operativo.

-         Señales.

##### Mediano Plazo:
En los sistemas de multiprogramación y tiempo compartido varios procesos residen en la memoria principal. El tamaño limitado de ésta hace que el número de procesos que residen en ella sea finito. Puede ocurrir que todos los procesos en memoria estén bloqueados, desperdiciándose así la CPU. En algunos sistemas se intercambian procesos enteros (swap) entre memoria principal y memoria secundaria (normalmente discos), con esto se aumenta el número de procesos, y, por tanto, la probabilidad de una mayor utilización de la CPU.

El planificador a medio plazo es el encargado de regir las transiciones de procesos entre memoria principal y secundaria, actúa intentando maximizar la utilización de los recursos. Por ejemplo, transfiriendo siempre a memoria secundaria procesos bloqueados, o transfiriendo a memoria principal procesos bloqueados únicamente por no tener memoria.

##### Largo plazo:
Este planificador está presente en algunos sistemas que admiten además de procesos interactivos trabajos por lotes. Usualmente , se les asigna una prioridad baja a los trabajos por lotes, utilizándose estos para mantener ocupados a los recursos del sistema durante períodos de baja actividad de los procesos interactivos. Normalmente, los trabajos por lotes realizan tareas rutinarias como el cálculo de nóminas; en este tipo de tareas el programador puede estimar su gasto en recursos, indicándoselo al sistema. Esto facilita el funcionamiento del planificador a largo plazo.

El objetivo primordial del planificador a largo plazo es el de dar al planificador de la CPU una mezcla equilibrada de trabajos, tales como los limitados por la CPU (utilizan mucho la CPU) o la E/S. Así, por ejemplo, cuando la utilización de la CPU es baja, el planificador puede admitir más trabajos para aumentar el número de procesos listos y, con ello, la probabilidad de tener algún trabajo útil en espera de que se le asigne la CPU. A la inversa, cuando la utilización de la CPU llega a ser alta, y el tiempo de respuesta comienza a reflejarlo, el planificador a largo plazo puede optar por reducir la frecuencia de admisión de trabajos.

Normalmente, se invoca al planificador a largo plazo siempre que un proceso termina. La frecuencia de invocación depende, pues, de la carga del sistema, pero generalmente es mucho menor que la de los otros dos planificadores. Esta baja frecuencia de uso hace que este planificador pueda permitirse utilizar algoritmos complejos, basados en las estimaciones de los nuevos trabajos.

#### Cola de trabajo:
##### Listos:
##### Suspendidos:
##### Removidos:
#### Modelos de cominicacion entre procesos:
#### Semáforo:
#### Monitor:
#### Interbloqueos:

#### Bibliografía:
- TANEMBAUM, A. S. (2001c). Sistemas operativos modernos (2ª ed.). México, México: Pearson Educación.
- Cambio de contexto. (s.f.). De Wikipedia. Recuperado el 20 Enero de 2020  de https://es.wikipedia.org/wiki/Cambio_de_contexto .
- SISTEMAS OPERATIVOS - Planificacion De procesos.(s.f.). De sistemas-operativos-41.es.tl. Recuperado el 20 Enero de 2020  de https://sistemas-operativos-41.es.tl/Planificacion-De-procesos.htm .
- La diferencia entre concurrencia y paralelismo.(s.f.). De the Dojo Blog. Recuperado el 20 Enero de 2020  de https://blog.thedojo.mx/2019/04/17/la-diferencia-entre-concurrencia-y-paralelismo.html .
https://es.wikipedia.org/wiki/Multitarea
https://es.wikipedia.org/wiki/Bloque_de_control_del_proceso
https://lsi.vc.ehu.eus/pablogn/docencia/manuales/SO/TemasSOuJaen/PLANIFICACIONDEPROCESOS/1NivelesdePlanificacion.htm#planificador_lp
https://sites.google.com/site/osupaep2010/administracion-de-procesos/planificacion-del-procesador/tipos-de-planificacion/planificacion-a-corto-plazo
### Tarea 2:

### Tarea 3:

### Tarea 4:

## Parcial 2:

## Parcial 3:

## Parcial 4:

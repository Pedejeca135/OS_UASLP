# PRACTICA 0


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


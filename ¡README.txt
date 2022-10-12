Franco-v2.5 - NOVEDADES

- Menus: Cambios y mejoras finales agregadas
	- Se agregó una funcionalidad en forma de menú que pregunta al usuario si desea o no continuar, y en base a eso se sigue en dentro del menú o se vuelve al anterior.
	- Se agregó un sistema que detecta los cambios al usuario. Esta funcionalidad hace una copia de los datos previo a los cambios, y la conserva hasta luego que el usuario termina de realizar los cambios, momento en que se compara la lista original con la nueva, y si hubo algún cambio, se le preguntará al usuario si desea guardarlos. 
	Este sistema es capaz de discernir cuando hay o no cambios, incluso en los casos que el usuario hace una modificacion que resulta tener los mismos datos que antes de realizarla, lo que no se consideraría como cambio (ej.: ordenar una lista que ya estaba ordenada, modificar un dato e ingresar los mismos datos que tenía antes, etc.).
	- Se agregó una serie de "menús de acción", previo al ingreso de varios menúes, que dictaminan la forma en que se ejecutarán. Son 3 "modos de acción":
		- 1 - Individual: se pide un indice de la lista al usuario (ej.: 2).
		- 2 - Selección (*) : se pide al usuario una seleccion de índices particulares en la lista (ej.: 2, 6, 31, etc.). 
		- 3 - Rango: se pide al usuario un indice mínimo y uno máximo en la lista, para operar con todos los datos dentro del rango definido por estos índices (ej.: del 14 al 37).
	Todos estos menúes de acción tienen sus propias barreras de seguridad, que chequean que los índices que se elijan estén dentro de los límites de la lista correspondiente.
	(*) : Este modo permite seleccionar los índices desordenadamente. Estos serán ordenados posteriormente.

 - TDACentroLogistico: 
	- Funcion cerrarReparto: ahora cada vez que se cierre un reparto, se realizará una copia del mismo, en lugar de simplemente moverlo a la lista de cerrados, lo que permitirá mantener un registro del estado de los repartos cuando se cerraron, y a su vez poder modificar los recursos (el chofer, vehículo o la pila de paquetes) sin afectar al mismo.
	- Funcion mostrarRepartos: ahora muestra los repartos sin los paquetes. Si se quieren ver, utilizar la funcion mostrarRepartos.
	- Funcion filtrarPorFechaSalida: antes simplemente ordenaba y mostraba la lista cronológicamente. Ahora la ordena y muestra solo los repartos que coincidan con un DÍA, MES Y AÑO determinados (implementacion: utiliza el día juliano).

---------------------------------------------------------------------------------------------------------------------

BUG FIXES

- Se arregló el error que crasheaba el programa al escanear un string largo cualquiera (util.c - Funcion crearStringDinámico).

- Ahora la funcion "menuMostrarPaquetes" muestra los paquetes correctamente, sólo si la lista de paquetes den centro logístico tiene contenidos.

- Files - Funcion abrirTodo: se solucionó el problema generado por tratar de recibir el nombre del centro logistico del archivo definiendo una variable tipo char * (se cambio a char [] y ahora funciona correctamente).

- Funcion presionarEnterYLimpiarPantalla: ahora funciona correctamente.

---------------------------------------------------------------------------------------------------------------------

BUGS


---------------------------------------------------------------------------------------------------------------------

MEJORAS



---------------------------------------------------------------------------------------------------------------------

CORRECCIONES



---------------------------------------------------------------------------------------------------------------------

main-v3.0.0-FINAL - NOVEDADES

- Files:
	- Agregadas funciones privadas "crearCarpeta"  y "abrirCarpeta". crearCarpeta crea una carpeta dentro del archivo del proyecto con el nombre de "Archivos", y abrirCarpeta la abre (si existe). Ambas funciones son invocadas en algunas de las funciones de abrir y guardar datos.
	- Ahora los archivos se guardan y abren desde la carpeta "Archivos" para mayor comodidad.

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

- Se arregló un error de lógica en el diseño de los menúes que impedía volver al menú anterior o ir al menú principal. EXPLICACIÓN:
		- while(!(op==0 && op==-1));
	usuario elige volver (op==0)
		     	  true && false = true
	NO SALE AUN SI SE ELIGE VOLVER O IR AL MENU PPAL
			a = op==0, b = op==-1
			!a && !b = !(a || b)
			!a * !b = !(a + b)

- Menus: ahora todas las funciones (excepto las de creacion de datos) no hacen nada si la lista correspondiente está vacía, lo que evita posibles errores si, por ejemplo, se quiere modificar un dato en una lista vacía.

- funcion mostrarPersona: se solucionó el error que impedía mostrar el nombre y apellido de la persona en cuestión. Había un cierre de paréntesis mal puesto en el printf.

---------------------------------------------------------------------------------------------------------------------

BUGS

- Files - Funcion guardarPaquetes al terminar de cargar paquetes crashea el programa.

- Menus - Funcion eliminarPersona (y otras seguro que también): ahora elimina en el índice que corresponde, pero si se quiere eliminar el último elemento de la lista, no deja, dice que el indice excede el limite de la lista.

---------------------------------------------------------------------------------------------------------------------

MEJORAS



---------------------------------------------------------------------------------------------------------------------

CORRECCIONES



---------------------------------------------------------------------------------------------------------------------

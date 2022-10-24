main-v3.0.0-FINAL - NOVEDADES

- GLOBAL - TDAS: agregada familia de funciones "copiarX". Estas reciben un TDA y crean una copia del mismo en memoria dinámica con una copia de los contenidos (sin asignacion de punteros).
	Estas funciones fueron hechas para facilitar y abstraer el trabajo con la funcion "copiarLista", así como arreglar esta funcion, ya que antes realmente no se hacía una copia de los elementos de la lista, sino que se creaba un nuevo puntero a esos datos, aunque se pusieron como funciones públicas por si se llega a precisar volverlas a usar en otro lado.
	Nota: todas las funciones de copia internamente llaman a su respectiva "crearXDirect", excepto por "copiarReparto", que llama a las de los demás TDA, ya que por la enorme dimension del TDA no posee una propia.

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

- funcion MostrarPaquete / mostrarPaquetes: se arregló el error que corrompía los datos luego de mostrar un paquete o lista de paquetes 1 vez. El problema residía en la funcion mostrarPaquete, que mostraba la fecha de entrega del paquete usando un puntero a char, lo que provocaba problemas. Se reemplazó por un vector de char de 18 caracteres (la cantidad justa y necesaria para este caso), y ahora funciona correctamente, sin importar cuantas veces se utilice la funcion.

---------------------------------------------------------------------------------------------------------------------

BUGS

- Files - Funcion guardarPaquetes al terminar de cargar paquetes crashea el programa.

- MENUS
	- Funcion eliminarPersona (y otras seguro que también): ahora elimina en el índice que corresponde, pero si se quiere eliminar el último elemento de la lista, no deja, dice que el indice excede el limite de la lista.
	- Funcion modificarPaquete: luego de seleccionar el modo de accion, se sale del menu.
	- Funciones de mostrar datos: la opcion "-1. MENU PRINCIPAL" funciona como "0. Volver".
	- Funciones de Modificacion de Datos: el programa crashea al querer setear un nuevo domicilio, ya que en todas estas funciones, la nueva fecha o domicilio solo fueron declaradas y no se hizo espacio en memoria dinámica para que se mantengan en la estructura luego de ser seteadas. 
		SOLUCIÓN: Para todos los TDA que tengan campos que sean estructuras, modificar todos los respectivos setters para que no asignen directamente la nueva estructura, sino que copien el contenido de cada una.
		YA SE HIZO, AHORA FALTA VER SI ARREGLÓ EL PROBLEMA O PERSISTE.
	- Funcion detectarCambios: la condicion para detectarlos, que llama a la familia de funciones "XIguales" hace que crashee.
		FUNCION PAQUETES IGUALES PARCHEADA, PERO FUNCIONA PARCIALMENTE. PROBARLA COMO ESTABA ANTES (DESCOMENTAR EL CÓDIGO).

- FILES
	- Funciones guardar/abrirPaquetes: Los datos son corrompidos cuando se abre y muestra una lista de paquetes. No logré encontrar pistas de donde está el error, todavía.

---------------------------------------------------------------------------------------------------------------------

MEJORAS

- TDAFechaYHora: las funciones de traer fechas con strings ahora son más eficientes, ya que usan sprintf y strcat para construir la fecha en forma de string. (Mejora antigua pero no se había informado).

---------------------------------------------------------------------------------------------------------------------

CORRECCIONES

- MENUS 
	[Corregido por franco sosa]
	Funcion eliminarPersona
	Se debe modificar la condicion del menuModoAccion1, en el cual en lugar de estar expresado asi [while(eleccion <= 0 || eleccion >= tamanioLista);] 
	debe estar asi [while(eleccion <= 0 || eleccion > tamanioLista);], de esta forma considera el ultimo elemento elegido (el tamanioLista)
	
	[Corregido por franco sosa]
	Funciones de mostrar datos
	Se debe agregar un parametro en las funciones de mostrado a modo de puntero tal que [menuMostrarPaquetes(CentroLogisticoPtr centroLogistico, int* op1)]
	y cuando se seleccione la opcion (-1) se emplee este formato [*op1 = 0], y asi con todas las funciones de menuMostrado

	[Pendiente]
	Funcion modificarPaquete (Y las demas de modificacion...)
	El problema reside en que al utilizar los diferentes if(accion1, accion2, accion3), no se considera cada condicion de las clausulas,
	quiero decir, al elegir 2 indices [1 al 3], se pregunta una vez sola que dato nuevo quiere cambiar, y lo termina haciendo la cantidad de
	indices con el mismo valor, el paquete 1,2,3 se cambia con el nuevo valor, cuando deberia haberse cambiado solo el 1, la solucion radica en 
	modificar las clausulas de menu modo accion de cada menuModificacion, respetando su formato (Buscar ejemplo en Gastpn v3.0 [menuModificar de los campos])
	- se traspasa mi version de los menuModoAccion del main || se modifica linea a linea los menuModoAccion de cada menu del main
	
	[Pendiente]
	Funcion de modificacion de datos
	Funciona correctamente, existe la alternativa de usar por ejemplo [actualizarDomicilio(getDirRetiro(paqueteAModificar))], y terminaria 
	siendo el mismo procedimiento, (La forma actual no esta mal, de hecho, esta bien ejecutada), no es neceario cambiarlo, lo que si es 
	necesario es cambiar la forma de ejecutar los menuModoAccion

	[Corregido por franco sosa]
	Funcion detectarCambios

---------------------------------------------------------------------------------------------------------------------

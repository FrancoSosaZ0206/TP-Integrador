main-v3.1.0-FINAL - NOVEDADES

- FILES:
	- Funciones abrir/guardarTodo: Había un problema donde, si el usuario se registraba, guardaba los cambios en la funcion de menu, y salía, el nombre del centro logístico no se guardaba, por lo que al iniciar sesion no se podía ingresar, a pesar de que sí se guardaban las listas de datos que el usuario cargó.
						Para prevenir esto, se dividió el proceso de estas funciones en 2 nuevas funciones:
							- guardarNombreCentroLogistico, y
							- abrirNombreCentroLogistico,
						que permiten a main solventar esta situación, simplemente llamando a la primer función en el caso que se elija "0. SALIR" y el sistema no detecte que hayan cambios o cambios sin guardar.

---------------------------------------------------------------------------------------------------------------------

BUG FIXES

- FILES:
	- Se arregló el error que corrompía los datos al guardar paquetes en un archivo. Aún se desconoce la causa del problema, pero se probó guardando en archivos binarios en lugar de .txt y ahora funciona correctamente, incluso guardandolos en una carpeta.

		EXPLICACION DE CAUSA PROBABLE: "En esta versión quisimos usar .txt simple y llanamente porque podías abrir el archivo con el bloc de notas y ver que estaba pasando adentro, pero parece que por alguna razón genera problemas. Quizás sea que necesite serializar los datos de alguna manera, convirtiendo todo a string y agregando "\n" al final de cada uno de ellos, pero eso llevaría mucho trabajo, y a esta altura solo queremos que todo funcione bien."


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

- Funciones de mostrar datos: opcion "-1. MENU PRINCIPAL" arreglada.

- Funcion eliminarPersona (y otras seguro que también): problema al tratar de eliminar el último elemento de la lista solucionado. El problema estaba en menuModoAccion1, que en la validacion de indice a tomar accion había un mayor o igual a la dimension de la lista, cuando debía ser mayor ESTRICTO.

- Funciones de Modificacion de Datos: el programa crashea al querer setear un nuevo domicilio, ya que en todas estas funciones, la nueva fecha o domicilio solo fueron declaradas y no se hizo espacio en memoria dinámica para que se mantengan en la estructura luego de ser seteadas. 
		SOLUCIÓN: Para todos los TDA que tengan campos que sean estructuras, se modificaron todos los respectivos setters para que no asignen directamente la nueva estructura, sino que copien el contenido de cada una.
		AHORA FALTA VER SI ARREGLÓ EL PROBLEMA O PERSISTE.

---------------------------------------------------------------------------------------------------------------------

BUGS

- Files - Funcion guardarPaquetes al terminar de cargar paquetes crashea el programa.

- MENUS
	- Funcion modificarPaquete: luego de seleccionar el modo de accion, se sale del menu.
	- Funcion detectarCambios: la condicion para detectarlos, que llama a la familia de funciones "XIguales" hace que crashee.
		FUNCION PAQUETES IGUALES PARCHEADA, PERO FUNCIONA PARCIALMENTE. PROBARLA COMO ESTABA ANTES (DESCOMENTAR EL CÓDIGO).
- FILES
	- Funciones guardar/abrirPaquetes: Los datos son corrompidos cuando se abre y muestra una lista de paquetes. No logré encontrar pistas de donde está el error, todavía.

---------------------------------------------------------------------------------------------------------------------

MEJORAS

- TDAFechaYHora: las funciones de traer fechas con strings ahora son más eficientes, ya que usan sprintf y strcat para construir la fecha en forma de string. (Mejora antigua pero no se había informado).

- UTIL - funcion destruirStringDinámico: ahora no es más de tipo void, sino char *, con lo que realmente retorna NULL, siguiendo la convencion de funciones destructoras como se hace en los TDAs con sus estructuras.

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

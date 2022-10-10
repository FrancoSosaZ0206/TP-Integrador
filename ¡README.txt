VERSION 2.0.0 - NOVEDADES

- Se incluyeron nuevas funciones:
	- Muestra y filtrado de repartos.
	- Funciones de ordenamiento de repartos, paquetes y vehículos
	- Funciones que chequean si un dato ya existía a la hora de cargarlo:
		- TDACentroLogistico: esCuilExistente
		- TDACentroLogistico: esRepartoExistente

- TDACentroLogistico: SE CAMBIÓ LA IMPLEMENTACIÓN DE LAS LISTAS DE REPARTOS. Ahora, los repartos cerrados se almacenan en una lista aparte.
	- Por tanto, muchas funciones de este TDA que usaban repartos cambiaron su implementacion. En su mayoría, ahora tienen un nuevo parámetro booleano que le indica a la funcion si se trata de la lista de repartos abiertos, o la de cerrados. Para más informacion, ver: TDACentroLogistico.h
	- FILES: los cambios a este TDA tambien se aplicaron a las funciones de apertura y guardado de listas de repartos.

---------------------------------------------------------------------------------------------------------------------

BUG FIXES


---------------------------------------------------------------------------------------------------------------------


BUGS

- (Pendiente) main.c - START MENU - Opcion "ABRIR ARCHIVOS": a veces, cuando hay archivos creados pero están vacíos, el programa crashea.

---------------------------------------------------------------------------------------------------------------------

MEJORAS

- Se optimizaron funciones de muestra de listas de datos, ordenamiento y otras.

---------------------------------------------------------------------------------------------------------------------

PENDIENTES

- Crear funciones de menu de guardado usando las funciones nuevas de los archivos Files. Agregarlas a los menues de main.c.

- (SECUNDARIO) MOTIVO POR EL QUE NO SE PUDO ENTREGAR. Una de dos:
  1. O bien nos quedamos con lo que tenemos, la variable int estado del paquete,
  2. O bien agregamos un string aparte. Tip: hay un motivo de entrega solo si hay un problema con dicha entrega, lo que quiere decir que sería un dato circunstancial. Entonces, es posible que no haga falta meterlo en una estructura, sino que los tengamos aparte.

	- Posible implementacion: Creamos el paquete con el campo "motivo de entrega" vacío. Luego, tendríamos que tener una funcion "agregarMotivo", recibe el string del motivo por el cual no se pudo entregar, y en el campo de la estrctura paquete, crea el string dinamicamente y le copia el contenido.

- Agregar llamado a las funciones de repartos.

- (IMPORTANTE) Agregar lo que decia en las consignas del TP "El sistema debe/no debe permitir...". Tip: es posible que necesitemos hacer más funciones de búsqueda.
	FALTAN:
		   debe permitir:
			- 6 (desarrollar)
			-  7 (llamar a la funcion "filtrarPaquetesPorEstado")
		    no debe permitir: 
			- 1, 2: las hizo Franquete, revisar.
			- 5: la estan haciendo Franquete y Santiti.

- (OPCIONAL) Menus: agregar un submenu donde puedas elegir si queres tomar accion sobre un solo dato o un grupo de datos a la vez, para evitar tener que entrar al menu varias veces (sería tedioso). Dentro de la segunda opcion (habria una 3ra, volver), podemos elegir si queremos tomar accion de un rango de indices, o bien si queremos tomar accion sobre varios indices especificos.

- (OPCIONAL) Agregar getters y setters adicionales para las subestructuras de cada estructura (domicilio, cuil o fecha). Por ejemplo, agregar getters y setters a sus campos específicos).

- (IMPORTANTE) TDACentroLogistico - Funcion "esPaqueteExistente" y TDARepartos - Funcion "esPaqueteCargado": Justo el ID es raro que coincida. Además, eso se genera automáticamente, y no lo pone el usuario, así que realmente no sirve. Una forma útil de verificar coincidencias de paquetes, sería chequeando si todos los datos del paquete coinciden, o al menos, las dimensiones, el peso y las direcciones de retiro y entrega.

- (IMPORTANTE) GLOBAL: agregar familia de funciones "... Idéntico(s)" - funcion que retorna un booleano dependiendo de si las dos estructuras recibidas son idénticas o no.
	- Hechas:
		- paquetesIguales.

- ARREGLAR POSIBLES BUGS :(


---------------------------------------------------------------------------------------------------------------------

CORRECCIONES


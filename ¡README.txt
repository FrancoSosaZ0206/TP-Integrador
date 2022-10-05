NOVEDADES

	V1.9 (Franco) - v1.9.1-alpha
		- Arreglo de Errores y cambio a funciones de menus:
			- Se arreglaron varios errores menores con el debugger y se cambiaron los menues de actualizacion de datos con las nuevas funciones y cambios al TDA Cuil.

			- Menus.c: se unificaron las funciones "menuModificarCliente" y "menuModificarChofer" en una sola única funcion "menuModificarPersona", que pide un booleano para saber de que tipo de persona se trata, y desplegar distinta informacion de acuerdo a ello, lo cual reduce la carga de ejecución.

			- También se agregó un nuevo menú de creacion de centro logistico de forma rápida, utilizada en el START MENU de main.c

		CORRECCIONES DEL 3/10 - ARREGLADAS - v1.9.2-alpha
			- TDA Fecha - Funcion validarFecha: se cambio el switch largo para validar el dia, por un vector con una dimension igual a la cantidad de meses del año, cuyas posiciones contienen el valor máximo particular de dias de cada mes. Esto redujo mucho código a solo algunas líneas.
			- Funcion anterior y Menus.c - Funciones abrir/guardar todo: se comprimio el conjugado de booleanos en una sola variable, a la que se progresivamente se le van agregando condiciones. Nos ahorramos variables.
			- Se eliminaron las funciones "sugerirCuilValido" y "convertirACuilValido" ya que realmente no podían cumplir su propósito:

			*****
				Profe: "Esas funciones están bien, pero no conviene que las 					usen..."
				Franco: "¿Por qué? Si el usuario ingresa mal el cuil, la funcion 					automaticamente calcula para que sea valido."
				Profe: "Pero si el usuario ingresa mal el dni, el calculo tambien va a 				fallar. ¿Como haces ahí?"
				Franco: "Ah, es verdad."

				CONCLUSION: SE DESCARTAN LAS FUNCIONES. "Hagan que si el 				usuario ingresa un cuil invalido, le salga un mensaje de error y 					listo, que el usuario se fije. Sino, es muy dificil."
			*****

			- Agregamos la implementacion de la funcion "menuArmarReparto". Muestra una lista de cada campo y se selecciona por indice.


---------------------------------------------------------------------------------------------------------------------

BUG FIXES

- Menus.c - GLOBAL: Se reemplazaron los strings de punteros a char a arrays de char, ya que esto generaba errores en el ingreso de datos y generaba una terminacion abrupta del programa.

---------------------------------------------------------------------------------------------------------------------


BUGS

- ***ARREGLADO - VER SECCION BUG FIXES*** En START MENU, opcion 1 - Soy nuevo (empezar de cero), el programa crashea luego de pedir el nombre para el nuevo centro logistico.

---------------------------------------------------------------------------------------------------------------------

MEJORAS

- Se quitaron los varios system("pause") porque aletargaban el proceso de navegar por el menu.

---------------------------------------------------------------------------------------------------------------------

PENDIENTES

- Crear funciones de menu de guardado usando las funciones nuevas de los archivos Files. Agregarlas a los menues de main.c.

- IMPORTANTE: MOTIVO POR EL QUE NO SE PUDO ENTREGAR. Una de dos:
  1. O bien nos quedamos con lo que tenemos, la variable int estado del paquete,
  2. O bien agregamos un string aparte. Tip: hay un motivo de entrega solo si hay un problema con dicha entrega, lo que quiere decir que sería un dato circunstancial. Entonces, es posible que no haga falta meterlo en una estructura, sino que los tengamos aparte.

Creamos el paquete con el campo "motivo de entrega" vacío. Luego, tendríamos que tener una funcion "agregarMotivo", recibe el string del motivo por el cual no se pudo entregar, y en el campo de la estrctura paquete, crea el string dinamicamente y le copia el contenido.





- Agregar llamado a las funciones de repartos.

- IMPORTANTE: agregar lo que decia en las consignas del TP "El sistema debe/no debe permitir...". Tip: es posible que necesitemos hacer más funciones de búsqueda.
	FALTAN:
		   debe permitir:
			- 6 (desarrollar)
			-  7 (llamar a la funcion "filtrarPaquetesPorEstado")
		    no debe permitir: 
			- 1, 2: las hizo Franquete, revisar.
			- 5: la estan haciendo Franquete y Santiti.

- Menus: agregar un submenu donde puedas elegir si queres tomar accion sobre un solo dato o un grupo de datos a la vez, para evitar tener que entrar al menu varias veces (sería tedioso). Dentro de la segunda opcion (habria una 3ra, volver), podemos elegir si queremos tomar accion de un rango de indices, o bien si queremos tomar accion sobre varios indices especificos. (opcional)

- Agregar getters y setters adicionales para las subestructuras de cada estructura (domicilio, cuil o fecha). Por ejemplo, agregar getters y setters a sus campos específicos) (opcional).

- ARREGLAR POSIBLES BUGS :(


---------------------------------------------------------------------------------------------------------------------

CORRECCIONES


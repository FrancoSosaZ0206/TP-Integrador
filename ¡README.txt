main-v3.2 - NOVEDADES

- MAIN
	- GLOBAL: Se agregó al sistema de deteccion de cambios la capacidad de detectar la primera vez que se se ingresa al programa (iniciar sesión), lo que despliega mensajes especiales al entrar y salir del menu ppal.

---------------------------------------------------------------------------------------------------------------------

MEJORAS

- TDAFechaYHora: las funciones de traer fechas con strings ahora son más eficientes, ya que usan sprintf y strcat para construir la fecha en forma de string. (Mejora antigua pero no se había informado).

- UTIL - funcion destruirStringDinámico: ahora no es más de tipo void, sino char *, con lo que realmente retorna NULL, siguiendo la convencion de funciones destructoras como se hace en los TDAs con sus estructuras.

- TDACentroLogistico: funciones de ordenamiento ahora ordenan por metodo shell.

---------------------------------------------------------------------------------------------------------------------

CORRECCIONES

	[Pendiente]
	- menuModoAccion: modificar para que cuando se elige modo accion 2 o 3 se pregunte y modifique para cada dato en particular, en lugar de asignar un dato a todos. ver: Gaston-v4.1 en adelante.
	
	[Pendiente]
	- métodos de ordenamiento de listas: no funciona bien, cambiar a la implementacion utilizada en la v4.1 de Gaston en adelante (método shell y trabaja directamente sobre las listas, no con un vector).


---------------------------------------------------------------------------------------------------------------------

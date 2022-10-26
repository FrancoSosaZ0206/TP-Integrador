main-v3.2 - NOVEDADES

- MAIN
	- GLOBAL: Se agregó al sistema de deteccion de cambios la capacidad de detectar la primera vez que se se ingresa al programa (iniciar sesión), lo que despliega mensajes especiales al entrar y salir del menu ppal.

---------------------------------------------------------------------------------------------------------------------

MEJORAS

- TDAFechaYHora: las funciones de traer fechas con strings ahora son más eficientes, ya que usan sprintf y strcat para construir la fecha en forma de string. (Mejora antigua pero no se había informado).

- UTIL - funcion destruirStringDinámico: ahora no es más de tipo void, sino char *, con lo que realmente retorna NULL, siguiendo la convencion de funciones destructoras como se hace en los TDAs con sus estructuras.

- TDACentroLogistico: funciones de ordenamiento ahora ordenan por metodo shell.

---------------------------------------------------------------------------------------------------------------------

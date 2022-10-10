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

- Se arregló el error que hacía que PLIM PLIM PLIM

---------------------------------------------------------------------------------------------------------------------

BUGS

- (Pendiente) main.c - START MENU - Opcion "ABRIR ARCHIVOS": a veces, cuando hay archivos creados pero están vacíos, el programa crashea.

---------------------------------------------------------------------------------------------------------------------

MEJORAS

- Se optimizaron funciones de muestra de listas de datos, ordenamiento y otras.

---------------------------------------------------------------------------------------------------------------------

PENDIENTES

- Menus: 
	- Agregar un submenu donde puedas elegir si queres tomar accion sobre un solo dato o un grupo de datos a la vez, para evitar tener que entrar al menu varias veces (sería tedioso). Dentro de la segunda opcion (habria una 3ra, volver), podemos elegir si queremos tomar accion de un rango de indices, o bien si queremos tomar accion sobre varios indices especificos.
	1. Al final, siempre preguntar: "Desea continuar?"
	2. Tomar accion en un rango de datos (de este indice a este)
	3. Tomar accion en un solo dato (indice tal)
	4. Tomar accion en una serie de indices especificos (PARA ELIMINAR NO)
	
	IMPLEMENTACION:
		1. Do ... while (desee continuar)
		2. Pedimos indice minimo y maximo, sacamos la diferencia y la metemos como límite en un for. Ejecutamos la accion siempre en el iMin hasta que se llegue a esa diferencia.
		3. Ya está, por defecto.
		4. Preguntamos la cantidad de indices a almacenar, almacenamos los indices en un vector, y tomamos accion en c/u de los indices.

		- Falta implementar en:
			- Funciones de modificacion de datos: 4.
			- Funciones de carga de datos: NINGUNA
			- Funciones de eliminacion de datos: NINGUNA.
			- Funciones de ordenamiento: 1.
			- Funciones de busqueda: NINGUNA
			- Funciones de muestra: 1.


- TDA Centro Logistico.c:

	- Funcion "cerrarReparto": ahora la funcion debe obtener el dato, copiarlo con la funcion armarReparto, y agregarlo a la lista de cerrados, en lugar de simplemente moverlo.

	- Funcion "mostrarRepartosPorFechaSalida" :
		- agregar parámetro "fecha" con el día para filtrar.
		- de esa fecha, tomar el día y en el while, en lugar de mostrar todos los repartos, que muestre solo los que coincidan con el día de la fecha recibida (filtrar por día).
		- cambiar nombre de la funcion a "filtrarPorFechaSalida" EN TODO LUGAR DONDE SE HAYA USADO LA FUNCION EN EL PROYECTO.

	- Funcion "mostrarRepartos": cuando esRepartoAbierto == FALSE, agregar un mensaje previo (o luego) a mostrar la lista de repartos, que avise que los repartos que están ahí son un registro, que ahora pueden estar cambiados, y que para ver como están ahora, ir a la opcion "mostrar lista de repartos abiertos" o alguna de las funciones de emitir listados de los datos de los repartos (paquetes, vehiculos...) del centro logistico.




- TESTEAR PROYECTO - ENCONTRAR, REPORTAR Y ARREGLAR POSIBLES BUGS.
	- PROCEDIMIENTO: 
		1. Probamos todas las funciones del proyecto.
		2. Si detectamos un error, lo primero que hacemos es reportarlo. En la seccion "bugs" de este README, para cada bug agregamos:
			a. Una breve descripcion del error, qué pasó.
			b. Como se produjo, y/o como reproducir el error, con el mayor detalle posible.
			c. En qué línea (aprox) estabamos cuando el error se produjo
			d. El nombre de la rama de la persona que encontró el error.
			e. (OPCIONAL) Si se tiene sospechas del posible origen del error, agregarlas, pero para evitar confusiones, ACLARAR SIEMPRE QUE SON SOSPECHAS.

		3. Los errores reportados pueden ser revisados y arreglados por todos.
		4. Cuando un error se arregla,
			a. Se quita del apartado "BUGS".
			b. Se agrega al apartado "BUG FIXES"
			c. Solo se conserva el punto 2. a. (descripcion del error) y una breve descripcion de por qué sucedía.
			d. La persona que arreglo este error notifica a todas las demás de ello, para que nadie siga trabajando en el.
		5. ACLARACIONES:
			a. CADA UNO TENDRÁ SU PROPIA RAMA, PARTIENDO DE LA VERSION FINAL DEL PROYECTO, CON UN README DONDE IRÁ REPORTANDO LOS ERRORES QUE ENCUENTRE.
			b. A MEDIDA QUE EL PROCESO AVANCE, CADA UNO TENDRÁ QUE IR ACTUALIZANDO SU README Y EL CÓDIGO DE SU RAMA CON LOS BUGS Y BUG FIXES DE LOS DEMÁS.
			c. SI UN BUG QUE SE HABÍA ARREGLADO PREVIAMENTE SE VUELVE A GENERAR, EL PROCESO ANTES MENCIONADO SE REPITE (REPORTAMOS, ARREGLAMOS, NOTIFICAMOS A LOS DEMÁS Y C/U ACTUALIZA SU README Y CÓDIGO) HASTA QUE EL ERROR NO VUELVA A SURGIR.

		6. EL PROCESO FINALIZARÁ CUANDO SE HAYAN PROBADO TODAS LAS FUNCIONES DEL PROYECTO Y NINGUNA PRESENTE BUGS. CUANDO ESTO SUCEDA:
			a. Todos los bug fixes deben quedar escritos y el apartado BUGS debe estar vacío.
			b. TODOS MERGEAMOS NUESTRAS RAMAS A UNA SOLA, FINAL.


---------------------------------------------------------------------------------------------------------------------

CORRECCIONES



---------------------------------------------------------------------------------------------------------------------

IDEAS

- Guardado de datos en archivos: Todo lo que sea strings se puede guardar con un '\n' al final del string, de modo que no se guarde "basura" y sea más legible a la hora de ver lo que hay adentro del archivo.

- MENUS - DETECCIÓN DE CAMBIOS:
   1. funciones de menu que hacen cambios analizan el imput del usuario y retornan un booleano:
        true o false dependiendo de si se hizo o no un cambio.
    2. Definimos e inicializamos un flag en main:
            bool cambios=false;
    3. Cuando cualquiera de las funciones de menu de ordenamiento, carga, actualizacion y
       eliminacion de datos (en el caso de los repartos, en vez de carga es apertura,
       y aparte de eliminacion está el cierre de repartos) detecte que hubo un cambio,
       retornará true.
    4. Almacenaremos ese valor en nuestra variable "cambios".
    5. Al final del switch, cuando se elige la opcion "Volver" o "MENU PRINCIPAL",
       se habrá una cláusula if que preguntará por el valor del flag.
       Dentro, tendrá el siguiente código:

                    do
                    {
                        printf("Guardar Cambios?\t1.SI\t0.NO\t");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();
                        switch(op2)
                        {
                        case 1:
                            if(guardarXXX(centroLogistico))
                                printf("\n\nCambios guardados exitosamente.\n\n");
                            else
                                printf("\n\nERROR AL GUARDAR.\n\n");
                            break;
                        case 0:
                            break;
                        default:
                            printf("\n\nOpcion incorrecta\n\n");
                            break;
                        }
                        presionarEnterYLimpiarPantalla();
                    } while(op2!=1 && op2!=0);

       De esta manera, podremos desplegar este submenú sólo si el usuario realmente hizo cambios,
       y que este pueda elegir si guardar los datos en un archivo o no.

       Además, podemos incluso usar esta variable para cuando salimos del menú principal,
       preguntando si quiere guardar todos los cambios realizados y salir, o salir sin guardar.
       La manera de hacerlo sería añadiendo al booleano de retorno que retorne true SI LOS CAMBIOS
       REALIZADOS SE GUARDARON, y false de lo contrario. De esta forma sabremos mejor cuando desplegar este
       último menú, y cuando no es necesario hacerlo (por ej. cuando se hicieron cambios, pero se guardaron).

       De esta forma, la nueva overview de las funciones de menú sería:

       bool cambios=false; //cambia a true si se cambia/elimina algún dato o se ordena una lista - esta variable es interna de la funcion
       bool cambiosGuardados=false; //cambia a true si el usuario elige guardar los cambios en archivo

       ... //se hacen las cosas del menú

       cambios=!datosIguales(datoOriginal,nuevoDato);

       if(cambios) //esto es por si los cambios introducidos resultan ser iguales a los que estaban antes.
                   //Es decir, que se paso por el menu, pero igualmente no se cambio nada.
       {
           Preguntamos si se quiere guardar los cambios
           if(el usuario elige guardar los cambios)
                cambiosGuardados=true;
       }

       return cambiosGuardados;


---------------------------------------------------------------------------------------------------------------------
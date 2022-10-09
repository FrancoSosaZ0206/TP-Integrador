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
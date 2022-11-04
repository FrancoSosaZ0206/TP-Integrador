#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "Files.h"
#include "TDACentroLogistico.h"
#include "test.h"
#include "util.h"
#include "Menus.h"


///--------------------------------------------------------------------------------------------------------------------------///

///                                                  FUNCIONES AYUDANTES

///--------------------------------------------------------------------------------------------------------------------------///


/* OPERACIÓN: copia una lista
PRECONDICIÓN: listaOriginal debe haber sido creada y tener contenido.
POSTCONDICIÓN: copia una lista con todos sus elementos, cuales quiera sean sus tipos.
PARÁMETROS:
    - listaOriginal: puntero a la lista como estaba antes de hacer alguna modificación
    - tipoDato: entero representando la lista a buscar cambios.
                  1 = Paquetes
                  2 = Personas (Clientes / Choferes)
                  3 = Vehiculos
                  4 = Repartos (Abiertos / Cerrados)
DEVUELVE: puntero a la copia de la lista. */
ListaPtr copiarLista(ListaPtr listaOriginal,int tipoDato)
{
    ListaPtr copiaLista=crearLista();
//Hacemos lo mismo pero para cada elemento de la lista
    PtrDato datoOriginal;
    PtrDato copiaDato;
//Para recorrer la lista original
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux,listaOriginal);

    ListaPtr temp = crearLista(); //Para mantener el orden original de la lista
    while(!listaVacia(listaAux))
    { ///Para mantener el orden original de la lista,
      ///en lugar de agregar los datos directamente a copiaLista,
      ///usamos una lista temporal de por medio.
        datoOriginal=getCabecera(listaAux);
    ///Copiamos el contenido de cada elemento según el tipo de dato que es
        switch(tipoDato)
        {
        case 1: //creamos un paquete
            copiaDato = (PaquetePtr) copiarPaquete((PaquetePtr) datoOriginal);
            break;
        case 2: //creamos una persona
            copiaDato = (PersonaPtr) copiarPersona((PersonaPtr) datoOriginal);
            break;
        case 3: //creamos un vehiculo
            copiaDato = (VehiculoPtr) copiarVehiculo((VehiculoPtr) datoOriginal);
            break;
        case 4: //creamos un reparto
            copiaDato = (RepartoPtr) copiarReparto((RepartoPtr) datoOriginal);
            break;
        }
     ///Agregamos el dato original a la lista
        agregarDatoLista(temp,copiaDato);
        listaAux=getResto(listaAux);
    }
    listaAux=destruirLista(listaAux,false);

    while(!listaVacia(temp))
    {
        agregarDatoLista(copiaLista,getCabecera(temp));
        temp=getResto(temp);
    }
    temp=destruirLista(temp,false);

    return copiaLista;
}

/* OPERACIÓN: deteccion de cambios
PRECONDICIÓN: debe haberse usado copiarLista previamente, y por tanto, copiaLista ya debe
              haber recibido los contenidos de la lista original.
POSTCONDICION: compara las listas, retornando si hubo cambios o no.
PARÁMETROS:
    - listaOriginal: puntero a la lista como estaba antes de hacer alguna modificación
    - copiaLista: puntero a la copia de la lista que se hizo
    - tipoDato: entero representando la lista a buscar cambios.
                  1 = Paquetes
                  2 = Personas (Clientes / Choferes)
                  3 = Vehiculos
                  4 = Repartos (Abiertos / Cerrados)
DEVUELVE: booleano informando:
            true = hubo cambios en, al menos, 1 elemento.
            false = no hubo ningún cambio, listaOriginal está igual que antes de pasar por el menú. */
bool detectarCambios(ListaPtr listaOriginal,ListaPtr copiaLista,int tipoDato)
{
    ListaPtr listaAux = crearLista(); //solo la usaremos para la lista original. La otra la destruiremos de todas formas, así que no hay problema.
    agregarLista(listaAux,listaOriginal);

    ListaPtr listaAux2 = crearLista();
    agregarLista(listaAux2,copiaLista);

    bool datosIguales;
///Recorremos la lista: antes y después de hacer el cambio

    while(!listaVacia(listaAux))
    {
        PtrDato datoOriginal=getCabecera(listaAux);
        PtrDato copiaDato=getCabecera(listaAux2);
    ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
        switch(tipoDato)
        {
        case 1:
            datosIguales = paquetesIguales((PaquetePtr)datoOriginal,(PaquetePtr)copiaDato);
            break;
        case 2:
            datosIguales = personasIguales((PersonaPtr)datoOriginal,(PersonaPtr)copiaDato);
            break;
        case 3:
            datosIguales = vehiculosIguales((VehiculoPtr)datoOriginal,(VehiculoPtr)copiaDato);
            break;
        case 4:
            datosIguales = repartosIguales((RepartoPtr)datoOriginal,(RepartoPtr)copiaDato);
            break;
        }
        if(!datosIguales) //aunque sea solo 1 que tenga algo distinto
        {
            listaAux = destruirLista(listaAux,false); //destruimos las listas antes de retornar
            listaAux2 = destruirLista(listaAux2,false);
            copiaLista = destruirLista(copiaLista,true); //esta ya no la necesitamos, así que también destruimos la copia de cada elemento.
            return true; //Retornamos que si (true), hubo un cambio.
        }
        listaAux=getResto(listaAux);
        listaAux2=getResto(listaAux2);
    }
    listaAux = destruirLista(listaAux,false); //destruimos las listas antes de retornar
    listaAux2 = destruirLista(listaAux2,false);
    copiaLista = destruirLista(copiaLista,true); //esta ya no la necesitamos, así que también destruimos la copia de cada elemento.

    return false; //Retornamos que no (false), no hubo ningún cambio.
}

/* OPERACIÓN: menu de guardado de cambios
PRECONDICIÓN:
    - centroLogistico debe haber sido creado y llenado con la lista de datos correspondiente.
    - debe haberse usado la funcion detectarCambios previamente.
POSTCONDICION: se despliega un menú por pantalla preguntando al usuario si quiere guardar los cambios realizados en la funcion correspondiente.
PARÁMETROS:
    - centroLogistico: puntero a entero representando la opcion del menu anterior
    - tipoDato: entero representando el tipo de lista que corresponde guardar:
                  1 = Paquetes
                  2 = Personas (Clientes / Choferes)
                  3 = Vehiculos
                  4 = Repartos (Abiertos / Cerrados)
DEVUELVE: booleano indicando si se guardaron (true) o no (false) los cambios. */
bool menuGuardarCambios(CentroLogisticoPtr centroLogistico,int tipoDato)
{
    int opGuardar=0;

    bool guardarLista;
    bool cambiosGuardados=false;
    do
    {
        printf("Guardar cambios? 1=SI , 0=NO | ");
        scanf("%d",&opGuardar);
        limpiarBufferTeclado();
        system("cls");
        switch(opGuardar)
        {
        case 1:
            switch(tipoDato)
            {
            case 1:
                guardarLista = guardarPaquetes(centroLogistico);
                break;
            case 2:
                guardarLista = guardarPersonas(centroLogistico);
                break;
            case 3:
                guardarLista = guardarVehiculos(centroLogistico);
                break;
            case 4:
                guardarLista = guardarRepartos(centroLogistico,true) && guardarRepartos(centroLogistico,false);
                break;
            }
            if(guardarLista)
            {
                printf("Cambios guardados exitosamente.");
                presionarEnterYLimpiarPantalla();
                cambiosGuardados=true;
            }
            else
            {
                printf("ERROR AL GUARDAR\n\n");
                exit(1);
            }
            break;
        case 0:
            break;
        default:
            printf("Opcion incorrecta.");
            presionarEnterYLimpiarPantalla();
            break;
        }
    } while(opGuardar<0 || opGuardar>1);

    return cambiosGuardados;
}

/* OPERACIÓN: menu de modo de accion
PRECONDICIÓN: ninguna
POSTCONDICION: se imprime en pantalla un menu preguntando como proceder a la accion sobre una lista de datos.
PARÁMETROS:
  opMenuAnterior: puntero a entero representando la opcion del menu anterior
DEVUELVE: entero representando la opcion elegida. */
int menuModoAccion(int *opMenuAnterior)
{
    int eleccion;
    do
    {
        printf("Accion:\n");
        printf("1. Sobre un indice unico [Ej: Posicion 1]\n");
        printf("2. Sobre conjunto de indices [Ej: Posiciones 1,18,4,25,7,6] (*)\n");
        printf("3. Sobre rango de indices [Ej: Posiciones 1 - 4 (1,2,3,4)]\n");
        printf("0. Volver\n");
        printf("-1. MENU PRINCIPAL");
        printf("\n\n-------------------------------------------------------------\n");
        printf("Opcion: ");
        scanf("%d", &eleccion);
        limpiarBufferTeclado();

        if(eleccion<-1 || eleccion>3)
        {
            printf("\nOpcion incorrecta.");
            presionarEnterYLimpiarPantalla();
        }
    } while(eleccion<-1 || eleccion>3);
    system("cls");

    if(eleccion==-1)
        *opMenuAnterior=-1;

    return eleccion;
}
/* OPERACIÓN: menu de modo de accion
PRECONDICIÓN: haber usado menuModoAccion
POSTCONDICION: se ejecuta el modo de accion 1 - se toma un indice por pantalla.
PARÁMETROS:
  lista: puntero representando la lista sobre la que se quiere accionar (repartos, personas...).
DEVUELVE: entero representando el índice elegido. */
int menuModoAccion1(ListaPtr lista)
{
    int n=longitudLista(lista);
    int i=0;
    do
    {
        printf("\n\nIngrese indice donde tomar accion: ");
        scanf("%d",&i);
        limpiarBufferTeclado();
        if(i<1 || i>n)
        {
            printf("\n\nERROR: indice inexistente. Vuelva a elegir.");
            presionarEnterYLimpiarPantalla();
        }
        else
            system("cls");
    } while(i<1 || i>n);

    return i;
}
/* OPERACIÓN: menu de modo de accion
PRECONDICIÓN: haber usado menuModoAccion
POSTCONDICION: se ejecuta el modo de accion 2 - se toma un conjunto de índices por pantalla.
PARÁMETROS:
  lista: puntero representando la lista sobre la que se quiere accionar (repartos, personas...).
  cantIndices: entero representando la variable que se cargará con la cantidad de indices seleccionados
DEVUELVE: vector de enteros representando la seleccion de índices elegidos.
*//**
ADVERTENCIA: Cuidado con menus o funciones que modifiquen la longitud de la lista (ej: menuEliminar). */
void menuModoAccion2(ListaPtr lista,int* cantIndices, int* indices)
{
    int n=longitudLista(lista);
//Ingresamos la cantidad de indices a seleccionar
    do
    {
        printf("Ingrese cantidad de indices a seleccionar: ");
        scanf("%d",&(*cantIndices));
        if((*cantIndices)<1 || (*cantIndices) > n)
        {
            printf("\n\nCantidad incorrecta.");
            presionarEnterYLimpiarPantalla();
        }
    } while((*cantIndices)<1 || (*cantIndices) > n);
    //Elegimos los indices
    for(int i=0;i<(*cantIndices);i++)
    {
        do
        {
            printf("\n\nIngrese indice %d: ",i+1);
            scanf("%d",&indices[i]);
            limpiarBufferTeclado();
            if(indices[i]<1 || indices[i]>n)
            {
                printf("\n\nIndice inexistente. Vuelva a ingresar.");
                presionarEnterYLimpiarPantalla();
            }
        } while(indices[i]<1 || indices[i]>n);
    }
    int salto=round(n/2);
    int temp=0;
    while(salto>0)
    {
        bool hayCambio=false;
        for(int i=0;i<n-salto;i++)
        {
            if(indices[i]>indices[i+salto])
            {
                hayCambio=true;
                temp=indices[i];
                indices[i]=indices[i+salto];
                indices[i+salto]=temp;
            }
        }
        if(!hayCambio)
            salto=round(salto/2);
    }
    system("cls");
}

/* OPERACIÓN: menu de modo de accion
PRECONDICIÓN: haber usado menuModoAccion
POSTCONDICION: se ejecuta el modo de accion 3 - se toma un rango de índices por pantalla.
PARÁMETROS:
  lista: puntero representando la lista sobre la que se quiere accionar (repartos, personas...).
  desde: entero representando la variable donde se cargará el índice mínimo.
  hasta: entero representando la variable donde se cargará el índice máximo.
DEVUELVE: nada. */
void menuModoAccion3(ListaPtr lista,int* desde,int* hasta)
{
    int n=longitudLista(lista);
    do
    {
        printf("Ingrese el indice minimo: ");
        scanf("%d",&(*desde));
        limpiarBufferTeclado();
        if((*desde)<1 || (*desde)>n)
        {
            printf("\n\nIndice incorrecto. Vuelva a ingresar.");
            presionarEnterYLimpiarPantalla();
        }
    } while((*desde)<1 || (*desde)>n);
    do
    {
        printf("Ingrese el indice maximo: ");
        scanf("%d",&(*hasta));
        limpiarBufferTeclado();
        if((*hasta)<(*desde) || (*hasta)>n)
        {
            printf("\n\nIndice incorrecto. Vuelva a ingresar.");
            presionarEnterYLimpiarPantalla();
        }
        else
            system("cls");
    } while((*hasta) < 1 || (*hasta) > n);
    if((*desde) > (*hasta))
    {
        int temp = 0;
        temp = (*desde);
        (*desde) = (*hasta);
        (*hasta) = temp;
    }
//El sistema permite que desde y hasta sean iguales si la lista tiene solo 1 elemento.
}

/*OPERACIÓN: menu para continuar en un menú
PRECONDICIÓN: ninguna
POSTCONDICION: se imprime en pantalla un menu preguntando como proceder a la accion sobre una lista de datos.
PARÁMETROS: ninguno
DEVUELVE: booleano representando la opcion elegida:
              true = SI, DESEA CONTINUAR
              false = NO, DESEA SALIR */
bool menuContinuar()
{
    int eleccion;
    do
    {
        printf("Desea continuar?\n");
        printf("1. SI \n");
        printf("0. NO \n");
        printf("Opcion: ");
        scanf("%d", &eleccion);
        limpiarBufferTeclado();
        system("cls");
    } while(eleccion<0 || eleccion>1);

    if(eleccion==1)
        return true;
    else
        return false;
}


///--------------------------------------------------------------------------------------------------------------------------///

///                             FUNCIONES DE CARGA, VALIDACIÓN Y ACTUALIZACIÓN DE SUBESTRUCTURAS

///--------------------------------------------------------------------------------------------------------------------------///

/* OPERACIÓN: carga de cuil con datos
PRECONDICIÓN: cuil debe haber sido DECLARADO
POSTCONDICION: se piden datos por pantalla y se crea un cuil en memoria dinamica con datos válidos
PARÁMETROS: ninguno
DEVUELVE: puntero al cuil cargado
*//**
ADVERTENCIA: No debe crearse el cuil con su constructora, causará memory leaks. */
CuilPtr cargarCuil()
{
    CuilPtr cuil = crearCuil("0000000000000");
    char strCuil[100];
    do
    {
        helpCuil();
        printf("\n\tCUIL: ");
        limpiarBufferTeclado();
        scanf("%[^\n]%*c",strCuil);
        setCuil(cuil,strCuil);
        if(!esCuilValido(cuil))
        {
            printf("Cuil invalido. Vuelva a ingresar.\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(!esCuilValido(cuil));

    return cuil;
}
/* OPERACIÓN: carga de domicilio con datos
PRECONDICIÓN: domicilio debe haber sido DECLARADO
POSTCONDICION: se piden datos por pantalla y se crea un domicilio en memoria dinamica
PARÁMETROS: ninguno
DEVUELVE: puntero al domicilio cargado
*//**
ADVERTENCIA: No debe crearse el domicilio con su constructora, causará memory leaks. */
DomicilioPtr cargarDomicilio()
{
    char calle[100];
    int altura;
    char localidad[100];

    printf("\n\t\tCalle: ");
    scanf("%[^\n]%*c",calle);
    limpiarBufferTeclado();
    printf("\n\t\tAltura: ");
    scanf("%d",&altura);
    limpiarBufferTeclado();
    printf("\n\t\tLocalidad: ");
    scanf("%[^\n]%*c",localidad);
    limpiarBufferTeclado();

    return crearDomicilio(calle,altura,localidad);
}
/* OPERACIÓN: carga de fecha con datos
PRECONDICIÓN: fecha debe haber sido DECLARADA
POSTCONDICION: se piden datos por pantalla y se crea una fecha con datos válidos
PARÁMETROS: ninguno
DEVUELVE: puntero a la fecha cargada
*//**
ADVERTENCIA: No debe crearse la fecha con su constructora, causará memory leaks. */
FechaPtr cargarFecha()
{
    FechaPtr fecha;

    int dia=0;
    int mes=0;
    int anio=0;
    int hora=0;
    int minuto=0;

    bool primeraVez=true;

    do
    {
        printf("\n\t\tFecha (DD MM AAAA): ");
        scanf("%d %d %d",&dia,&mes,&anio);
        limpiarBufferTeclado();
        printf("\n\t\tHorario (HH MM): ");
        scanf("%d %d",&hora,&minuto);
        limpiarBufferTeclado();


        if(primeraVez)
            fecha=crearFecha(dia,mes,anio,hora,minuto);
        else
        {
            setDia(fecha,dia);
            setMes(fecha,mes);
            setAnio(fecha,anio);
            setHora(fecha,hora);
            setMinuto(fecha,minuto);
            if(!esFechaValida(fecha))
                printf("\n\nFecha invalida. Reingrese la fecha.\n\n");
        }
        primeraVez=false;
        if(primeraVez==false)
            system("cls");
    } while (!esFechaValida(fecha));

    return fecha;
}

/* OPERACIÓN: actualiza los datos de un cuil
PRECONDICIÓN: cuil debe haberse creado
POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion, y se actualiza la estructura
PARÁMETROS:
  puntero a la estructura a actualizar
DEVUELVE: Nada */
void actualizarCuil(CuilPtr cuil)
{
    char strCuil[100];
    int i=0;
    do
    {
        helpCuil();
        printf("\n\tNuevo CUIL:");
        scanf("%[^\n]%*c",strCuil);
        limpiarBufferTeclado();
        if(i<4)
            setCuil(cuil,strCuil);
        else    //if(i==4)
            printf("\n\nIntentos agotados.\n\n");
        i++;
        if(i>1)
            system("cls");
    } while(!esCuilValido(cuil));
}
/* OPERACIÓN: actualiza los datos de un domicilio
PRECONDICIÓN: domicilio debe haberse creado
POSTCONDICION: se piden datos por pantalla y se actualiza la estructura
PARÁMETROS:
  puntero a la estructura a actualizar
DEVUELVE: Nada */
void actualizarDomicilio(DomicilioPtr domicilio)
{
    char calle[100];
    int altura;
    char localidad[100];

    printf("\n\t\tCalle: ");
    scanf("%[^\n]%*c",calle);
    limpiarBufferTeclado();
    printf("\n\t\tAltura: ");
    scanf("%d",&altura);
    limpiarBufferTeclado();
    printf("\n\t\tLocalidad: ");
    scanf("%[^\n]%*c",localidad);
    limpiarBufferTeclado();

    setCalle(domicilio,calle);
    setAltura(domicilio,altura);
    setLocalidad(domicilio,localidad);
}
/* OPERACIÓN: actualiza los datos de una fecha
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion, y se actualiza la estructura
PARÁMETROS:
  puntero a la estructura a actualizar
DEVUELVE: Nada */
void actualizarFecha(FechaPtr fecha)
{
    int dia=0;
    int mes=0;
    int anio=0;
    int hora=0;
    int minuto=0;

    int i=0;

    do
    {
        printf("\n\t\tFecha (DD MM AAAA): ");
        scanf("%d %d %d",&dia,&mes,&anio);
        limpiarBufferTeclado();
        printf("\n\t\tHorario (HH MM): ");
        scanf("%d %d",&hora,&minuto);
        limpiarBufferTeclado();

        setDia(fecha,dia);
        setMes(fecha,mes);
        setAnio(fecha,anio);
        setHora(fecha,hora);
        setMinuto(fecha,minuto);
        if(!esFechaValida(fecha) && i<4)
        {
            printf("\n\nFecha invalida. Reingrese la fecha.");
            presionarEnterYLimpiarPantalla();
        }
        else if(i==4)
        {
            printf("\n\nSe agotaron los intentos.");
            presionarEnterYLimpiarPantalla();
            break;
        }
    } while (!esFechaValida(fecha));
}


///--------------------------------------------------------------------------------------------------------------------------///

///                                                FUNCIONES DE CARGA DE ESTRUCTURAS

///--------------------------------------------------------------------------------------------------------------------------///

bool menuCargarPaquete(CentroLogisticoPtr centroLogistico)
{
    bool continuar;
    int i = 1;
    ///Paquete
    PaquetePtr paquete;
    int ID=0;   //el ID del paquete se genera automáticamente, no lo tiene que ingresar el usuario.
    int ancho=0;//el mismo se genera aleatoriamente.
    int alto=0;
    int largo=0;
    int peso=0;
    //por defecto, los paquetes se cargan con el estado 0: 'en depósito'.
    ///Variables para funciones
    srand(time(NULL));
    do
    {
        printf("CARGAR PAQUETE %d.\n\n", i++);
        //esto no se mostrará sino al final de la carga del paquete.
        ID = longitudLista(getPaquetes(centroLogistico))+1;
        while(!VerificarIDUnico(centroLogistico, ID))
        {
            ID++;
        }
        printf("\tIngrese Ancho: ");
        scanf("%d",&ancho);
        limpiarBufferTeclado();
        printf("\n\tIngrese Alto: ");
        scanf("%d",&alto);
        limpiarBufferTeclado();
        printf("\n\tIngrese Largo: ");
        scanf("%d",&largo);
        limpiarBufferTeclado();
        printf("\n\tIngrese Peso: ");
        scanf("%d",&peso);
        limpiarBufferTeclado();
        printf("\n\tDireccion de retiro:");
        DomicilioPtr dirRetiro = cargarDomicilio();
        printf("\n\tDireccion de entrega:");
        DomicilioPtr dirEntrega = cargarDomicilio();

        printf("\n\tFecha de entrega:");
        FechaPtr fechaEntrega = cargarFecha();

        paquete=crearPaquete(ID,ancho,alto,largo,peso,dirRetiro,dirEntrega,fechaEntrega,0);
        agregarPaquete(centroLogistico,paquete);

        printf("\n\nPaquete #%d cargado exitosamente.",ID);
        presionarEnterYLimpiarPantalla();

        continuar=menuContinuar();
    } while(continuar);

    return menuGuardarCambios(centroLogistico,1);
}
bool menuCargarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    bool CuilUnico = false;
    bool continuar;
    ///Variables para funciones
    int i = 1;
    ///Cliente
    char nombre[100];
    char apellido[100];
    PersonaPtr persona;
    CuilPtr cuil;
    do
    {
        if(esChofer) { printf("CARGAR CHOFER %d.\n\n", i++); }
        if(!esChofer) { printf("CARGAR CLIENTE %d.\n\n", i++); }

        printf("\tIngrese Nombre: ");
        scanf("%[^\n]%*c",nombre);
        limpiarBufferTeclado();
        printf("\n\tIngrese Apellido: ");
        scanf("%[^\n]%*c",apellido);
        limpiarBufferTeclado();

        printf("\n\tDomicilio");
        DomicilioPtr domicilio = cargarDomicilio();

        CuilUnico = false;
        while(!CuilUnico)
        {
            CuilUnico = true;
            cuil = cargarCuil();
            if(!VerificarCuilUnico(centroLogistico, getCuil(cuil)))
            {
                CuilUnico = false;
                printf("\n\n\t[Cuil existente...]\n");
                presionarEnterYLimpiarPantalla();
            }
        }

        if(cuil != NULL)
        {
            persona = crearPersona(nombre, apellido, domicilio, cuil, false);
            agregarPersona(centroLogistico, persona);
        }

        if(cuil == NULL)
        {
            printf("\n\n\tCuil invalido, saliendo del menu.");
            presionarEnterYLimpiarPantalla();
        }

        if(esChofer) { printf("Cliente cargado exitosamente."); }
        if(!esChofer) { printf("Cliente cargado exitosamente."); }

        presionarEnterYLimpiarPantalla();

        continuar=menuContinuar();

    } while(continuar);

    return menuGuardarCambios(centroLogistico,2);
}
bool menuCargarVehiculo(CentroLogisticoPtr centroLogistico)
{
    bool PatenteValida = false;
    bool PatenteUnica = false;
    bool continuar;
    ///Variables para funciones
    int i = 1;
    ///Vehiculo
    int tipoVehiculo=0;
    char marca[100];
    char modelo[100];
    char patente[100];
    VehiculoPtr vehiculo;
    do
    {
        printf("\n\nVEHICULO %d\n\n",i++);
        helpTipoVehiculo();
        printf("\tSeleccione un Tipo: ");
        scanf("%d",&tipoVehiculo);

        limpiarBufferTeclado();
        printf("\n\n\tMarca: ");
        scanf("%[^\n]%*c",marca);

        limpiarBufferTeclado();
        printf("\n\tModelo: ");
        scanf("%[^\n]%*c",modelo);

        PatenteUnica = false;
        PatenteValida = false;
        while(!PatenteUnica || !PatenteValida)
        {
            PatenteValida = true;
            PatenteUnica = true;
            limpiarBufferTeclado();
            printf("\n\n\tFormato: [AA 111 AA]");
            printf("\n\n\tPatente: ");
            scanf("%[^\n]%*c", patente);
            if(!VerificarPatenteUnica(centroLogistico, patente))
            {
                PatenteUnica = false;
                printf("\n\n\t [Patente existente...]\n");
                presionarEnterYLimpiarPantalla();
            }
            if(!VerificarPatenteValida(patente))
            {
                PatenteValida = false;
                printf("\n\n\t [Patente invalida...]\n");
                presionarEnterYLimpiarPantalla();
            }
        }


        vehiculo=crearVehiculo(tipoVehiculo,marca,modelo,patente);
        agregarDatoLista(centroLogistico->listaVehiculos,(VehiculoPtr)vehiculo);

        printf("\n\nVehiculo cargado exitosamente.");
        presionarEnterYLimpiarPantalla();

        continuar=menuContinuar();

    } while(continuar);

    return menuGuardarCambios(centroLogistico,3);
}


///--------------------------------------------------------------------------------------------------------------------------///

///                                                FUNCIONES DE ELIMINACIÓN DE ESTRUCTURAS

///--------------------------------------------------------------------------------------------------------------------------///

bool menuEliminarPaquete(CentroLogisticoPtr centroLogistico,int *opMenuAnterior)
{
    int indices[100];
    int cantIndices = 0;
    PaquetePtr PaqueteRemover;
    ListaPtr listaAux = getPaquetes(centroLogistico);

    if(listaVacia(listaAux))
    {
        printf("ERROR: Lista vacia. Debe agregar paquetes para poder eliminarlos.");
        presionarEnterYLimpiarPantalla();
        return true;
    }
    else
    {

/// ////////////////////////////////////////////////////////////////////////////////// ///
        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion==0 && modoAccion==-1))
        {
            bool continuar;
            do
            {
            //para el modo de accion 1,
                int indice;
            //para el modo de accion 2,
            //para el modo de accion 3,
                int desde=0,hasta=0;
/// ////////////////////////////////////////////////////////////////////////////////// ///
                switch(modoAccion)
                {
                    case 1:
                        printf("ELIMINAR PAQUETE\n");
                        mostrarPaquetes(centroLogistico);
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Paquete a remover: ");
                        indice=menuModoAccion1(listaAux);
                        ///Obtenemos y destruimos el elemento seleccionado
                        destruirPaquete(removerPaquete(centroLogistico,indice-1));
                        printf("\nPaquete eliminado exitosamente.\n\n");
                        break;
                    case 2:
                        printf("ELIMINAR PAQUETES\n");
                        mostrarPaquetes(centroLogistico);
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Paquetes a remover: \n");
                        menuModoAccion2(listaAux,&cantIndices,indices);
                        printf("\n\nCantidad indices: %d", cantIndices);
                        printf("\n\nPrimer indice: %d", indices[0]);
                        ///Obtenemos y destruimos los elementos en los indices seleccionados
                        for(int j=0;j<cantIndices;j++)
                        {
                            PaqueteRemover = removerPaquete(centroLogistico,indices[j]-j-1);
                            PaqueteRemover = destruirPaquete(PaqueteRemover);
                        }
                        printf("\nPaquetes eliminados exitosamente.\n\n");
                        break;
                    case 3:
                        printf("ELIMINAR PAQUETES\n");
                        mostrarPaquetes(centroLogistico);
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Paquetes a remover: ");
                        menuModoAccion3(listaAux,&desde,&hasta);
                        ///Obtenemos y destruimos los elementos en el rango de indices
                        for(int i=desde;i<=hasta;i++)
                        {
                            destruirPaquete(removerPaquete(centroLogistico,desde-1));
                        }
                        printf("\nPaquetes eliminados exitosamente.\n\n");
                        break;
                }

                continuar=menuContinuar();
            } while(continuar);

            return menuGuardarCambios(centroLogistico,1);
       }
       else //if(modoAccion == 0 || modoAccion == -1)
       {
           //ya nos encargamos de poner opMenuAnterior en la funcion menuModoAccion
           return true;
       }
    }
}
bool menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer,int *opMenuAnterior)
{
    ListaPtr listaAux = getPersonas(centroLogistico);

    if(listaVacia(listaAux))
    {
        if(esChofer)
            printf("ERROR: Lista vacia. Debe agregar choferes para poder eliminarlos.");
        else
            printf("ERROR: Lista vacia. Debe agregar clientes para poder eliminarlos.");
        presionarEnterYLimpiarPantalla();
        return true;
    }
    else
    {
/// ////////////////////////////////////////////////////////////////////////////////// ///
        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion==0 && modoAccion==-1))
        {
            bool continuar;
            do
            {
            //para el modo de accion 1,
                int indice;
            //para el modo de accion 2,
                int nIndices = 0;
                int indices[100];
            //para el modo de accion 3,
                int desde=0,hasta=0;
/// ////////////////////////////////////////////////////////////////////////////////// ///
                if(modoAccion==1)
                {
                    if(esChofer)
                    {
                        printf("ELIMINAR CHOFER\n");
                        mostrarPersonas(centroLogistico,1);
                    }
                    else
                    {
                        printf("ELIMINAR CLIENTE\n");
                        mostrarPersonas(centroLogistico,2);
                    }
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Persona a remover: ");
                    indice=menuModoAccion1(listaAux);
                //Obtenemos y destruimos el elemento seleccionado
                    destruirPersona(removerPersona(centroLogistico,indice-1));
                    if(esChofer)
                        printf("\nChofer eliminado exitosamente.\n\n");
                    else
                        printf("\nCliente eliminado exitosamente.\n\n");
                }
                else if(modoAccion==2)
                {
                    if(esChofer)
                    {
                        printf("ELIMINAR CHOFERES\n");
                        mostrarPersonas(centroLogistico,1);
                    }
                    else
                    {
                        printf("ELIMINAR CLIENTES\n");
                        mostrarPersonas(centroLogistico,2);
                    }
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Personas a remover: ");
                    menuModoAccion2(listaAux,&nIndices,indices);
                //Obtenemos y destruimos los elementos seleccionados
                    for(int i=0,j=0;i<nIndices;i++,j++)
                        destruirPersona(removerPersona(centroLogistico,indices[i]-j-1));
                    if(esChofer)
                        printf("\nChoferes eliminados exitosamente.\n\n");
                    else
                        printf("\nClientes eliminados exitosamente.\n\n");

                }
                else
                {
                    if(esChofer)
                    {
                        printf("ELIMINAR CHOFERES\n");
                        mostrarPersonas(centroLogistico,1);
                    }
                    else
                    {
                        printf("ELIMINAR CLIENTES\n");
                        mostrarPersonas(centroLogistico,2);
                    }
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Personas a remover: ");
                    menuModoAccion3(listaAux,&desde,&hasta);
                //Obtenemos y destruimos los elementos en el rango de indices
                    for(int i=desde;i<=hasta;i++)
                        destruirPersona(removerPersona(centroLogistico,desde-1));
                    if(esChofer)
                        printf("\nChoferes eliminados exitosamente.\n\n");
                    else
                        printf("\nClientes eliminados exitosamente.\n\n");
                }

                continuar=menuContinuar();
            } while(continuar);

            return menuGuardarCambios(centroLogistico,2);
        }
        else //if(modoAccion == 0 || modoAccion == -1)
            return true; //ya nos encargamos de poner opMenuAnterior en la funcion menuModoAccion
    }
}
bool menuEliminarVehiculo(CentroLogisticoPtr centroLogistico,int *opMenuAnterior)
{
    ListaPtr listaAux = getVehiculos(centroLogistico);

    if(listaVacia(listaAux))
    {
        printf("ERROR: Lista vacia. Debe agregar vehiculos para poder eliminarlos.");
        presionarEnterYLimpiarPantalla();
        return true;
    }
    else
    {
/// ////////////////////////////////////////////////////////////////////////////////// ///
        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion==0 && modoAccion==-1))
        {
            bool continuar;
            do
            {
            //para el modo de accion 1,
                int indice;
            //para el modo de accion 2,
                int nIndices = 0;
                int indices[100];
            //para el modo de accion 3,
                int desde=0,hasta=0;
/// ////////////////////////////////////////////////////////////////////////////////// ///
                if(modoAccion==1)
                {
                    printf("ELIMINAR VEHICULO\n");
                    mostrarVehiculos(centroLogistico);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Vehiculo a remover: ");
                    indice=menuModoAccion1(listaAux);
                //Obtenemos y destruimos el elemento seleccionado
                    destruirVehiculo(removerVehiculo(centroLogistico,indice-1));
                    printf("\nVehiculo eliminado exitosamente.\n\n");
                }
                else if(modoAccion==2)
                {
                    printf("ELIMINAR VEHICULOS\n");
                    mostrarVehiculos(centroLogistico);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Vehiculos a remover: ");
                    menuModoAccion2(listaAux,&nIndices,indices);
                //Obtenemos y destruimos los elementos en los indices seleccionados
                    for(int i=0,j=0;i<nIndices;i++,j++)
                        destruirVehiculo(removerVehiculo(centroLogistico,indices[i]-j-1));
                    printf("\nVehiculos eliminados exitosamente.\n\n");

                }
                else
                {
                    printf("ELIMINAR VEHICULOS\n");
                    mostrarVehiculos(centroLogistico);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Vehiculos a remover: ");
                    menuModoAccion3(listaAux,&desde,&hasta);
                //Obtenemos y destruimos los elementos en el rango de indices
                    for(int i=desde;i<=hasta;i++)
                        destruirVehiculo(removerVehiculo(centroLogistico,desde-1));
                    printf("\nVehiculos eliminados exitosamente.\n\n");
                }

                continuar=menuContinuar();
            } while(continuar);

            return menuGuardarCambios(centroLogistico,3);
        }
        else //if(modoAccion == 0 || modoAccion == -1)
            return true; //ya nos encargamos de poner opMenuAnterior en la funcion menuModoAccion
    }
}
bool menuEliminarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int *opMenuAnterior)
{
    bool continuar;

    ListaPtr listaAux = getRepartos(centroLogistico,esRepartoAbierto);

    if(listaVacia(listaAux))
    {
        printf("ERROR: Lista vacia. Debe agregar repartos para poder eliminarlos.");
        presionarEnterYLimpiarPantalla();
        return true;
    }
    else
    {
/// ////////////////////////////////////////////////////////////////////////////////// ///
        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion==0 && modoAccion==-1))
        {
            do
            {
            //para el modo de accion 1,
                int indice;
            //para el modo de accion 2,
                int nIndices = 0;
                int indices[100];
            //para el modo de accion 3,
                int desde=0,hasta=0;
/// ////////////////////////////////////////////////////////////////////////////////// ///
                if(modoAccion==1)
                {
                    if(esRepartoAbierto)
                        printf("ELIMINAR REPARTO ABIERTO\n");
                    else
                        printf("ELIMINAR REPARTO CERRADO\n");
                    mostrarRepartos(centroLogistico,esRepartoAbierto);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Reparto a remover: ");
                    indice=menuModoAccion1(listaAux);
                //Obtenemos y destruimos el elemento seleccionado
                    destruirReparto(removerReparto(centroLogistico,indice-1,esRepartoAbierto));
                    printf("\nReparto eliminado exitosamente.\n\n");
                }
                else if(modoAccion==2)
                {
                    if(esRepartoAbierto)
                        printf("ELIMINAR REPARTOS ABIERTOS\n");
                    else
                        printf("ELIMINAR REPARTOS CERRADOS\n");
                    mostrarRepartos(centroLogistico,esRepartoAbierto);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Repartos a remover: ");
                    menuModoAccion2(listaAux,&nIndices,indices);
                //Obtenemos y destruimos los elementos seleccionados
                    for(int i=0,j=0;i<nIndices;i++,j++)
                        destruirReparto(removerReparto(centroLogistico,indices[i]-j,esRepartoAbierto));
                    printf("\nRepartos eliminados exitosamente.\n\n");

                }
                else
                {
                    if(esRepartoAbierto)
                        printf("ELIMINAR REPARTOS ABIERTOS\n");
                    else
                        printf("ELIMINAR REPARTOS CERRADOS\n");
                    mostrarRepartos(centroLogistico,esRepartoAbierto);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Repartos a remover: ");
                    menuModoAccion3(listaAux,&desde,&hasta);
                //Obtenemos y destruimos los elementos en el rango de indices
                    for(int i=desde;i<=hasta;i++)
                        destruirReparto(removerReparto(centroLogistico,desde,esRepartoAbierto));
                    printf("\nRepartos eliminados exitosamente.\n\n");
                }

                continuar=menuContinuar();
            } while(continuar);

            return menuGuardarCambios(centroLogistico,4);
        }
        else //if(modoAccion == 0 || modoAccion == -1)
            return true; //ya nos encargamos de poner opMenuAnterior en la funcion menuModoAccion
    }
}


///--------------------------------------------------------------------------------------------------------------------------///

///                                                FUNCIONES DE MODIFICACIÓN DE ESTRUCTURAS

///--------------------------------------------------------------------------------------------------------------------------///

bool menuModificarPaquete(CentroLogisticoPtr centroLogistico,int *opMenuAnterior)
{
    ListaPtr listaAux=getPaquetes(centroLogistico);
    int nDimension=0; //vale para ancho, alto, largo y peso.
    DomicilioPtr nDireccion = crearDomicilio("",0,""); //vale para retiro y entrega
    FechaPtr nFechaEntrega = crearFecha(0,0,0,0,0);
    PaquetePtr* paquetesAModificar = NULL;
    int nEstado;


    if(listaVacia(listaAux))
    {
        printf("ERROR: Lista vacia. Debe agregar paquetes para poder modificarlos.");
        presionarEnterYLimpiarPantalla();
        return true; //"todo sigue igual que lo guardado."
    }
    else
    {
        ListaPtr copiaLista = copiarLista(listaAux,1);

        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion == 0 || modoAccion == -1))
        {
            bool continuar;
            int op=0;
            do
            {
                mostrarPaquetes(centroLogistico);
/// ////////////////////////////////////////////////////////////////////////////////// ///
            //para el modo de accion 1,
                int indice;
                PaquetePtr paqueteAModificar;
            //para el modo de accion 2,
                int nIndices=0;
                int indices[100];
            //para el modo de accion 3,
                int desde=0,hasta=0;
            //para los modos de accion 2 y 3,

                if(modoAccion==1)
                {
                    printf("MODIFICAR PAQUETE\n\n");
                    indice=menuModoAccion1(listaAux);
                //Obtenemos el elemento seleccionado
                    paqueteAModificar=(PaquetePtr)getDatoLista(listaAux,indice-1);

                    printf("Ha elegido - ");
                    mostrarPaquete(paqueteAModificar);
                }
                else if(modoAccion==2)
                {
                    printf("MODIFICAR PAQUETES\n\n");
                    menuModoAccion2(listaAux,&nIndices,indices);

                    printf("Ha elegido Paquetes");
                    for(int i=0;i<nIndices;i++)
                    { //Obtenemos los elementos en los indices seleccionados y los mostramos
                        paquetesAModificar[i]=(PaquetePtr)getDatoLista(listaAux,indices[i]-1);
                        printf("%d. ",indices[i]-1);
                        mostrarPaquete(paquetesAModificar[i]);
                    }
                }
                else
                {
                    printf("MODIFICAR PAQUETES\n\n");
                    menuModoAccion3(listaAux,&desde,&hasta);

                    for(int i=desde;i<=hasta;i++)

                    printf("Ha elegido Paquetes {%d - %d}\n",desde,hasta);
                    for(int i=0,j=desde;i<=(hasta-desde);i++,j++)
                    { //Obtenemos los elementos en el rango de indices y los mostramos
                        paquetesAModificar[i]=(PaquetePtr)getDatoLista(listaAux,i-1);

                        printf("%d. ",j);
                        mostrarPaquete(paquetesAModificar[i]);
                    }
                }
/// ////////////////////////////////////////////////////////////////////////////////// ///


                printf("\n\nQue desea modificar?\n\n");

                printf("1. Ancho\n");
                printf("2. Alto\n");
                printf("3. Largo\n");
                printf("4. Peso\n");
                printf("5. Direccion de Retiro\n");
                printf("6. Direccion de Entrega\n");
                printf("7. Fecha de Entrega\n");
                printf("8. Estado\n");
                printf("0. Volver\n");
                printf("-1. MENU PRINCIPAL");
                printf("\n\n-----------------------------------------\n\n");
                printf("Seleccione una opcion: ");
                scanf("%d",&op);
                limpiarBufferTeclado();

                system("cls");
                switch(op)
                {
                case 1:
                    do
                    {
                        printf("Ingrese nuevo Ancho: ");
                        scanf("%d",&nDimension);
                        limpiarBufferTeclado();

                        if(nDimension<=0)
                        {
                            printf("\n\nERROR: una dimension debe ser mayor a cero. Vuelva a ingresar.");
                            presionarEnterYLimpiarPantalla();
                        }
                        else
                            system("cls");
                    } while(nDimension<=0);

                    if(modoAccion==1)
                        setAncho(paqueteAModificar,nDimension);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setAncho(paquetesAModificar[i],nDimension);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setAncho(paquetesAModificar[i],nDimension);
                    break;
                case 2:
                    do
                    {
                        printf("Ingrese nuevo Alto: ");
                        scanf("%d",&nDimension);
                        limpiarBufferTeclado();

                        if(nDimension<=0)
                        {
                            printf("\n\nERROR: una dimension debe ser mayor a cero. Vuelva a ingresar.");
                            presionarEnterYLimpiarPantalla();
                        }
                        else
                            system("cls");
                    } while(nDimension<=0);

                    if(modoAccion==1)
                        setAlto(paqueteAModificar,nDimension);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setAlto(paquetesAModificar[i],nDimension);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setAlto(paquetesAModificar[i],nDimension);
                    break;
                case 3:
                    do
                    {
                        printf("Ingrese nuevo Largo: ");
                        scanf("%d",&nDimension);
                        limpiarBufferTeclado();

                        if(nDimension<=0)
                        {
                            printf("\n\nERROR: una dimension debe ser mayor a cero. Vuelva a ingresar.");
                            presionarEnterYLimpiarPantalla();
                        }
                        else
                            system("cls");
                    } while(nDimension<=0);

                    if(modoAccion==1)
                        setLargo(paqueteAModificar,nDimension);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setLargo(paquetesAModificar[i],nDimension);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setLargo(paquetesAModificar[i],nDimension);
                    break;
                case 4:
                    do
                    {
                        printf("Ingrese nuevo Peso: ");
                        scanf("%d",&nDimension);
                        limpiarBufferTeclado();

                        if(nDimension<=0)
                        {
                            printf("\n\nERROR: una dimension debe ser mayor a cero. Vuelva a ingresar.");
                            presionarEnterYLimpiarPantalla();
                        }
                        else
                            system("cls");
                    } while(nDimension<=0);

                    if(modoAccion==1)
                        setPeso(paqueteAModificar,nDimension);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setPeso(paquetesAModificar[i],nDimension);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setPeso(paquetesAModificar[i],nDimension);
                    break;
                case 5:
                    printf("Nueva Direccion de Retiro: ");
                    actualizarDomicilio(nDireccion);

                    if(modoAccion==1)
                        setDirRetiro(paqueteAModificar,nDireccion);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setDirRetiro(paquetesAModificar[i],nDireccion);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setDirRetiro(paquetesAModificar[i],nDireccion);
                    break;
                case 6:
                    printf("Nueva Direccion de Entrega: ");
                    actualizarDomicilio(nDireccion);

                    if(modoAccion==1)
                        setDirEntrega(paqueteAModificar,nDireccion);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setDirEntrega(paquetesAModificar[i],nDireccion);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setDirEntrega(paquetesAModificar[i],nDireccion);
                    break;
                case 7:
                    printf("Nueva Fecha de Entrega: ");
                    actualizarFecha(nFechaEntrega);

                    if(modoAccion==1)
                        setFechaEntrega(paqueteAModificar,nFechaEntrega);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setFechaEntrega(paquetesAModificar[i],nFechaEntrega);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setFechaEntrega(paquetesAModificar[i],nFechaEntrega);
                    break;
                case 8:
                    do
                    {
                        helpEstadoPaquete();

                        printf("Ingrese el numero del nuevo estado: ");
                        scanf("%d",&nEstado);
                        limpiarBufferTeclado();
                        if(nEstado<0 || nEstado>5)
                        {
                            printf("\n\nERROR: estado inexistente. Vuelva a ingresar.");
                            presionarEnterYLimpiarPantalla();
                        }
                        else
                            system("cls");
                    } while(nEstado<0 || nEstado>5);

                    if(modoAccion==1)
                        setEstado(paqueteAModificar,nEstado);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setEstado(paquetesAModificar[i],nEstado);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setEstado(paquetesAModificar[i],nEstado);
                    break;
                case 0:
                    break;
                case -1:
                    *opMenuAnterior=-1;
                    break;
                default:
                    printf("\nOpcion incorrecta.");
                    presionarEnterYLimpiarPantalla();
                    break;
                }

                if(!(op==0 || op==-1))
                {
                    printf("\n\nDatos modificados exitosamente.\n\n");
                    continuar=menuContinuar();
                }
            } while(!(op==0 || op==-1) && continuar);
        }
        else //if(modoAccion == 0 || modoAccion == -1)
            return true; //ya nos encargamos de poner opMenuAnterior en la funcion menuModoAccion

        bool cambioDetectado = detectarCambios(listaAux,copiaLista,1);
        nDireccion = destruirDomicilio(nDireccion);
        nFechaEntrega = destruirFecha(nFechaEntrega);
        if(cambioDetectado)
            return menuGuardarCambios(centroLogistico,1);
        else
            return true; //"todo sigue igual que lo guardado."
    }
}
bool menuModificarPersona(CentroLogisticoPtr centroLogistico,bool esChofer,int *opMenuAnterior)
{
    bool ExistenDatos = true;
    DomicilioPtr nDomicilio = crearDomicilio("",0,"");
    CuilPtr nCuil = crearCuil("000000000000000");
    PersonaPtr *personasAModificar = NULL;
    ListaPtr listaAux=getPersonas(centroLogistico);

    if(esChofer)
    {
        if(!VerificarExistenciaChoferes(centroLogistico))
        {
            ExistenDatos = false;
            printf("\n\n\tNo existen choferes para modificar.");
            presionarEnterYLimpiarPantalla();
        }
    }
    if(!esChofer)
    {
        if(!VerificarExistenciaClientes(centroLogistico))
        {
            ExistenDatos = false;
            printf("\n\n\tNo existen clientes para modificar.");
            presionarEnterYLimpiarPantalla();
        }
    }
    if(ExistenDatos)
    {
        ListaPtr copiaLista = copiarLista(listaAux,2);

        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion == 0 || modoAccion == -1))
        {
            bool continuar;
            int op=0;
            do
            {
                if(esChofer)
                    mostrarPersonas(centroLogistico,1);
                else
                    mostrarPersonas(centroLogistico,2);
/// ////////////////////////////////////////////////////////////////////////////////// ///
            //para el modo de accion 1,
                int indice;
                PersonaPtr personaAModificar;
            //para el modo de accion 2,
                int nIndices=0;
                int indices[100];
            //para el modo de accion 3,
                int desde=0,hasta=0;
            //para los modos de accion 2 y 3,

                if(modoAccion==1)
                {
                    if(esChofer)
                        printf("MODIFICAR CHOFER\n\n");
                    else
                        printf("MODIFICAR CLIENTE\n\n");
                    indice=menuModoAccion1(listaAux);
                //Obtenemos el elemento seleccionado
                    personaAModificar=(PersonaPtr)getDatoLista(listaAux,indice-1);

                    printf("Ha elegido - ");
                    mostrarPersona(personaAModificar);
                }
                else if(modoAccion==2)
                {
                    if(esChofer)
                        printf("MODIFICAR CHOFERES\n\n");
                    else
                        printf("MODIFICAR CLIENTES\n\n");
                    menuModoAccion2(listaAux,&nIndices,indices);

                    if(esChofer)
                        printf("Ha elegido Choferes");
                    else
                        printf("Ha elegido Clientes");
                    for(int i=0;i<nIndices;i++)
                    { //Obtenemos los elementos en los indices seleccionados y los mostramos
                        personasAModificar[i]=(PersonaPtr)getDatoLista(listaAux,indices[i]-1);
                        printf("%d. ",indices[i]);
                        mostrarPersona(personasAModificar[i]);
                    }

                }
                else
                {
                    if(esChofer)
                        printf("MODIFICAR CHOFERES\n\n");
                    else
                        printf("MODIFICAR CLIENTES\n\n");
                    menuModoAccion3(listaAux,&desde,&hasta);

                    for(int i=desde;i<=hasta;i++)

                    if(esChofer)
                        printf("Ha elegido Choferes {%d - %d}\n",desde,hasta);
                    else
                        printf("Ha elegido Clientes {%d - %d}\n",desde,hasta);
                    for(int i=0,j=desde;i<=(hasta-desde);i++,j++)
                    { //Obtenemos los elementos en el rango de indices y los mostramos
                        personasAModificar[i]=(PersonaPtr)getDatoLista(listaAux,i-1);

                        printf("%d. ",j);
                        mostrarPersona(personasAModificar[i]);
                    }
                }
/// ////////////////////////////////////////////////////////////////////////////////// ///
                char nNombre[100];
                char nApellido[100];
                bool nEsChofer;


                printf("\n\nQue desea modificar?\n\n");

                printf("1. Nombre\n");
                printf("2. Apellido\n");
                printf("3. Domicilio\n");
                printf("4. Cuil\n");
                if(esChofer)
                    printf("5. Cambiar persona a: CLIENTE\n");
                else
                    printf("5. Cambiar persona a: CHOFER\n");
                printf("0. Volver\n");
                printf("-1. MENU PRINCIPAL");
                printf("\n\n-----------------------------------------\n\n");
                printf("Seleccione una opcion: ");
                scanf("%d",&op);

                system("cls");
                switch(op)
                {
                case 1:
                    printf("Ingrese el nuevo nombre: ");
                    scanf("%[^\n]%*c",nNombre);

                    if(modoAccion==1)
                        setNombre(personaAModificar,nNombre);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setNombre(personasAModificar[i],nNombre);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setNombre(personasAModificar[i],nNombre);
                    break;
                case 2:
                    printf("Ingrese el nuevo apellido: ");
                    scanf("%[^\n]%*c",nApellido);

                    if(modoAccion==1)
                        setApellido(personaAModificar,nApellido);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setApellido(personasAModificar[i],nApellido);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setApellido(personasAModificar[i],nApellido);
                    break;
                case 3:
                    printf("\n\nNuevo Domicilio:");
                    actualizarDomicilio(nDomicilio);

                    if(modoAccion==1)
                        setDomicilio(personaAModificar,nDomicilio);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setDomicilio(personasAModificar[i],nDomicilio);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setDomicilio(personasAModificar[i],nDomicilio);
                    break;
                case 4:
                    printf("\n\nNuevo CUIL:");
                    actualizarCuil(nCuil);

                    if(modoAccion==1)
                        setCuilPersona(personaAModificar,nCuil);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setCuilPersona(personasAModificar[i],nCuil);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setCuilPersona(personasAModificar[i],nCuil);
                    break;
                case 5:
                    if(esChofer)
                        nEsChofer=false;
                    else
                        nEsChofer=true;

                    if(modoAccion==1)
                        setEsChofer(personaAModificar,nEsChofer);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setEsChofer(personasAModificar[i],nEsChofer);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setEsChofer(personasAModificar[i],nEsChofer);
                    break;
                case 0:
                    break;
                case -1:
                    *opMenuAnterior=-1;
                    break;
                default:
                    printf("\nOpcion incorrecta.");
                    presionarEnterYLimpiarPantalla();
                    break;
                }
                if(!(op==0 || op==-1))
                {
                    printf("\n\nDatos modificados exitosamente.\n\n");
                    continuar=menuContinuar();
                }
            } while(!(op==0 || op==-1) && continuar);
        }
        else //if(modoAccion == 0 || modoAccion == -1)
            return true; //ya nos encargamos de poner opMenuAnterior en la funcion menuModoAccion

        bool cambioDetectado = detectarCambios(listaAux,copiaLista,2);
        nCuil = destruirCuil(nCuil);
        nDomicilio = destruirDomicilio(nDomicilio);

        if(cambioDetectado)
            return menuGuardarCambios(centroLogistico,2);
    }
    return true;
}
bool menuModificarVehiculo(CentroLogisticoPtr centroLogistico,int *opMenuAnterior)
{
    ListaPtr listaAux=getVehiculos(centroLogistico);

    if(listaVacia(listaAux))
    {
        printf("ERROR: Lista vacia. Debe agregar vehiculos para poder modificarlos.");
        presionarEnterYLimpiarPantalla();
        return true;
    }
    else
    {
        ListaPtr copiaLista = copiarLista(listaAux,3);

        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion == 0 || modoAccion == -1))
        {
            bool continuar;
            int op=0;
            do
            {
                mostrarVehiculos(centroLogistico);
/// ////////////////////////////////////////////////////////////////////////////////// ///
            //para el modo de accion 1,
                int indice;
                VehiculoPtr vehiculoAModificar;
            //para el modo de accion 2,
                int nIndices=0;
                int indices[100];
            //para el modo de accion 3,
                int desde=0,hasta=0;
            //para los modos de accion 2 y 3,
                VehiculoPtr *vehiculosAModificar = NULL;

                if(modoAccion==1)
                {
                    printf("MODIFICAR VEHICULO\n\n");
                    indice=menuModoAccion1(listaAux);
                //Obtenemos el elemento seleccionado
                    vehiculoAModificar=(VehiculoPtr)getDatoLista(listaAux,indice-1);

                    printf("Ha elegido - ");
                    mostrarVehiculo(vehiculoAModificar);
                }
                else if(modoAccion==2)
                {
                    printf("MODIFICAR VEHICULOS\n\n");
                    menuModoAccion2(listaAux,&nIndices,indices);

                    printf("Ha elegido Vehiculos");
                    for(int i=0;i<nIndices;i++)
                    { //Obtenemos los elementos en los indices seleccionados y los mostramos
                        vehiculosAModificar[i]=(VehiculoPtr)getDatoLista(listaAux,indices[i]-1);
                        printf("%d. ",indices[i]);
                        mostrarVehiculo(vehiculosAModificar[i]);
                    }

                }
                else
                {
                    printf("MODIFICAR VEHICULOS\n\n");
                    menuModoAccion3(listaAux,&desde,&hasta);

                    for(int i=desde;i<=hasta;i++)

                    printf("Ha elegido Vehiculos {%d - %d}\n",desde,hasta);
                    for(int i=0,j=desde;i<=(hasta-desde);i++,j++)
                    { //Obtenemos los elementos en el rango de indices y los mostramos
                        vehiculosAModificar[i]=(VehiculoPtr)getDatoLista(listaAux,i-1);

                        printf("%d. ",j);
                        mostrarVehiculo(vehiculosAModificar[i]);
                    }
                }
/// ////////////////////////////////////////////////////////////////////////////////// ///

                int opNTipo;

                int nTipo=0;
                char nMarca[100];
                char nModelo[100];
                char nPatente[100];


                printf("\n\nQue desea modificar?\n\n");

                printf("1. Tipo de vehiculo\n");
                printf("2. Marca\n");
                printf("3. Modelo\n");
                printf("4. Patente\n");
                printf("0. Volver\n");
                printf("-1. MENU PRINCIPAL");
                printf("\n\n-----------------------------------------\n\n");
                printf("Seleccione una opcion: ");
                scanf("%d",&op);

                system("cls");
                switch(op)
                {
                case 1:
                    printf("\n\n");
                    do
                    {
                        helpTipoVehiculo();

                        printf("\n\nSeleccione una opcion: ");
                        scanf("%d",&opNTipo);

                        system("cls");
                        switch(opNTipo)
                        {
                        case 1:
                            nTipo=1;
                            break;
                        case 2:
                            nTipo=2;
                            break;
                        case 3:
                            nTipo=3;
                            break;
                        default:
                            printf("\nERROR: esa opcion no existe.");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(!(opNTipo<1 && opNTipo>3));

                    if(modoAccion==1)
                        setTipoVehiculo(vehiculoAModificar,nTipo);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setTipoVehiculo(vehiculosAModificar[i],nTipo);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setTipoVehiculo(vehiculosAModificar[i],nTipo);
                    break;
                case 2:
                    printf("\n\nIngrese la nueva marca:");
                    scanf("%[^\n]%*c",nMarca);

                    if(modoAccion==1)
                        setMarca(vehiculoAModificar,nMarca);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setMarca(vehiculosAModificar[i],nMarca);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setMarca(vehiculosAModificar[i],nMarca);
                    break;
                case 3:
                    printf("\n\nIngrese el nuevo modelo:");
                    scanf("%[^\n]%*c",nModelo);

                    if(modoAccion==1)
                        setModelo(vehiculoAModificar,nModelo);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setModelo(vehiculosAModificar[i],nModelo);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setModelo(vehiculosAModificar[i],nModelo);
                    break;
                case 4:
                    printf("\n\nIngrese la nueva patente (AA 111 AA):\n\t");
                    scanf("%[^\n]%*c",nPatente);

                    if(modoAccion==1)
                        setPatente(vehiculoAModificar,nPatente);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setPatente(vehiculosAModificar[i],nPatente);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setPatente(vehiculosAModificar[i],nPatente);
                    break;
                case 0:
                    break;
                case -1:
                    *opMenuAnterior=-1;
                    break;
                default:
                    printf("\nOpcion incorrecta.");
                    presionarEnterYLimpiarPantalla();
                    break;
                }

                if(!(op==0 || op==-1))
                {
                    printf("\n\nDatos modificados exitosamente.\n\n");
                    continuar=menuContinuar();
                }
            } while(!(op==0 || op==-1) && continuar);
        }
        else //if(modoAccion == 0 || modoAccion == -1)
            return true; //ya nos encargamos de poner opMenuAnterior en la funcion menuModoAccion

        bool cambioDetectado = detectarCambios(listaAux,copiaLista,3);

        if(cambioDetectado)
            return menuGuardarCambios(centroLogistico,3);
    }
    return true;
}

bool menuModificarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int *opMenuAnterior)
{
    FechaPtr fechaAModificar = crearFecha(0,0,0,0,0);
    ListaPtr listaAux=getRepartos(centroLogistico,esRepartoAbierto);

    if(listaVacia(listaAux))
    {
        printf("ERROR: Lista vacia. Debe agregar repartos para poder modificarlos.");
        presionarEnterYLimpiarPantalla();
        return true;
    }
    else
    {
        ListaPtr copiaLista = copiarLista(listaAux,4);

        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion == 0 || modoAccion == -1))
        {
            int op2=0;
            int op3=0;
            bool continuar;

            do
            {
                if(esRepartoAbierto)
                    printf("MODIFICAR REPARTO ABIERTO\n");
                else
                    printf("MODIFICAR REPARTO CERRADO\n");
                printf("\n\n-----------------------------------------\n\n");
                mostrarRepartos(centroLogistico,esRepartoAbierto);
                printf("\n\n-----------------------------------------\n\n");
/// ////////////////////////////////////////////////////////////////////////////////// ///
            //para el modo de accion 1,
                int indice;
                RepartoPtr repartoAModificar;
                PilaPtr pilaAux;
                PaquetePtr *paquetesAModificar = NULL;
            //para el modo de accion 2,
                int nIndices=0;
                int indices[100];
            //para el modo de accion 3,
                int desde=0,hasta=0;
            //para los modos de accion 2 y 3,
                RepartoPtr *repartosAModificar = NULL;
                PilaPtr *pilasAux = NULL;
            //para todos los modos,
                int nPaquetes;

                if(modoAccion==1)
                {
                    indice=menuModoAccion1(listaAux);
                //Obtenemos el elemento seleccionado
                    repartoAModificar=(RepartoPtr)getDatoLista(listaAux,indice-1);
                }
                else if(modoAccion==2)
                {
                    menuModoAccion2(listaAux,&nIndices,indices);
                //Obtenemos los elementos en los indices seleccionados
                    for(int i=0;i<nIndices;i++)
                        repartosAModificar[i]=(RepartoPtr)getDatoLista(listaAux,indices[i]-1);
                }
                else
                {
                    menuModoAccion3(listaAux,&desde,&hasta);
                //Obtenemos los elementos en el rango de indices
                    for(int i=desde;i<=hasta;i++)
                        repartosAModificar[i]=(RepartoPtr)getDatoLista(listaAux,i-1);
                }
/// ////////////////////////////////////////////////////////////////////////////////// ///
                int nuevoEstado;

                system("cls");
/// ////////////////////////////////////////////////////////////////////////////////// ///
                if(modoAccion==1)
                {
                    printf("Ha elegido - ");
                    mostrarRepartoSinPaquetes(repartoAModificar);
                }
                else if(modoAccion==2)
                {
                    printf("Ha elegido Repartos");
                    int i;
                    for(i=0;i<nIndices;i++)
                    {
                        printf("%d. ",indices[i]);
                        mostrarRepartoSinPaquetes(repartosAModificar[i]);
                    }

                }
                else
                {
                    printf("Ha elegido Repartos {%d - %d}\n",desde,hasta);
                    for(int i=0,j=desde;i<=(hasta-desde);i++,j++)
                    {
                        printf("%d. ",j);
                        mostrarRepartoSinPaquetes(repartosAModificar[i]);
                    }
                }
/// ////////////////////////////////////////////////////////////////////////////////// ///
                printf("\n\n-----------------------------------------\n\n");
                printf("Que desea modificar?\n\n");

                printf("1. Cambiar Chofer\n");
                printf("2. Cambiar Vehiculo\n");
                printf("3. Fecha de Salida\n");
                printf("4. Fecha de Retorno\n");
                printf("5. Paquetes Cargados\n");
                printf("0. Volver\n");
                printf("-1. MENU PRINCIPAL");
                printf("\n\n-----------------------------------------\n\n");
                printf("Ingrese una opcion: ");
                scanf("%d",&op2);
                limpiarBufferTeclado();

                system("cls");
                switch(op2)
                {
                case 1:
                    printf("CAMBIAR CHOFER");
                    printf("\n\n-----------------------------------------\n\n");
                    mostrarPersonas(centroLogistico,1);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Seleccione el indice del nuevo chofer: ");
                    break;
                case 2:
                    printf("CAMBIAR VEHICULO");
                    printf("\n\n-----------------------------------------\n\n");
                    mostrarVehiculos(centroLogistico);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Seleccione el indice del nuevo vehiculo: ");
                    break;
                case 3:
                    printf("MODIFICAR FECHA SALIDA");
                    printf("\n\n-----------------------------------------\n\n");
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    actualizarFecha(fechaAModificar);
                    if(modoAccion==1)
                        setFechaSalida(repartoAModificar,fechaAModificar);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setFechaSalida(repartosAModificar[i],fechaAModificar);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setFechaSalida(repartosAModificar[i],fechaAModificar);
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    break;
                case 4:
                    printf("MODIFICAR FECHA RETORNO");
                    printf("\n\n-----------------------------------------\n\n");
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    actualizarFecha(fechaAModificar);
                    if(modoAccion==1)
                        setFechaRetorno(repartoAModificar,fechaAModificar);
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setFechaRetorno(repartosAModificar[i],fechaAModificar);
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setFechaRetorno(repartosAModificar[i],fechaAModificar);
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    break;
                }
            ///Hacemos un tajo en medio del switch para hacer cosas que de otra forma no podríamos.
                if(!(op2>=3 && op2<=5))
                    scanf("%d",&indice);
            ///Proseguimos...
                switch(op2)
                {
                case 1:
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    if(modoAccion==1)
                        setChofer(repartoAModificar,(PersonaPtr)getDatoLista(getPersonas(centroLogistico),indice-1));
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setChofer(repartosAModificar[i],(PersonaPtr)getDatoLista(getPersonas(centroLogistico),indice-1));
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setChofer(repartosAModificar[i],(PersonaPtr)getDatoLista(getPersonas(centroLogistico),indice-1));
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    break;
                case 2:
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    if(modoAccion==1)
                        setVehiculo(repartoAModificar,(VehiculoPtr)getDatoLista(getVehiculos(centroLogistico),indice-1));
                    else if(modoAccion==2)
                        for(int i=0;i<nIndices;i++)
                            setVehiculo(repartosAModificar[i],(VehiculoPtr)getDatoLista(getVehiculos(centroLogistico),indice-1));
                    else
                        for(int i=0;i<=(hasta-desde);i++)
                            setVehiculo(repartosAModificar[i],(VehiculoPtr)getDatoLista(getVehiculos(centroLogistico),indice-1));
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    break;
                case 5:
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    if(modoAccion==1)
                    {
                        pilaAux=getPaquetesReparto(repartoAModificar);
                        nPaquetes=cantidadPaquetes(repartoAModificar);
                        if(pilaVacia(pilaAux))
                        {
                            printf("ERROR: este reparto no tiene paquetes.\n\n");
                            exit(1);
                        }
                        for(int i=0;i<nPaquetes;i++)
                            paquetesAModificar[i]=(PaquetePtr)desapilar(pilaAux);
                        do
                        {
                            printf("MODIFICAR PAQUETES DEL REPARTO");
                            printf("\n\n-----------------------------------------\n\n");
                            for(int i=0;i<nPaquetes;i++)
                                mostrarPaquete(paquetesAModificar[i]);
                            printf("\n\n-----------------------------------------\n\n");
                            printf("\n\nIngrese indice del paquete a modificar: ");
                            scanf("%d",&indice);
                            limpiarBufferTeclado();
                            if(indice<0 || indice>nPaquetes)
                            {
                                printf("\n\nERROR: indice inexistente. Vuelva a elegir.");
                                presionarEnterYLimpiarPantalla();
                            }
                        } while(indice<0 || indice>nPaquetes);

                        printf("Ha elegido - ");
                        mostrarPaquete(paquetesAModificar[indice]);
                    }
                    else
                        printf("MODIFICAR PAQUETES DE LOS REPARTOS");
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    do
                    {
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Que desea modificar?\n\n");

                        printf("1. ESTADO - Marcar como Retirado\n");
                        printf("2. ESTADO - Marcar como Entregado\n");
                        printf("3. ESTADO - Marcar como Demorado\n");
                        printf("4. ESTADO - Marcar como Suspendido\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL");
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Ingrese una opcion: ");
                        scanf("%d",&op3);
                        limpiarBufferTeclado();

                        system("cls");
                        switch(op3)
                        {
                        case 1:
                            nuevoEstado=2;
                            break;
                        case 2:
                            nuevoEstado=3;
                            break;
                        case 3:
                            nuevoEstado=4;
                            break;
                        case 4:
                            nuevoEstado=5;
                            break;
                        case 0:
                            break;
                        case -1:
                            op2=-1;
                            break;
                        default:
                            printf("Opcion incorrecta.");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(!(op3==0 || op3==-1));
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    if(modoAccion==1)
                        setEstado(paquetesAModificar[indice],nuevoEstado);
                    else if(modoAccion==2)
                    {
                        for(int i=0;i<nIndices;i++)
                        {
                            pilasAux[i]=getPaquetesReparto(repartosAModificar[i]);
                            nPaquetes=cantidadPaquetes(repartosAModificar[i]);
                            for(int j=0;j<nPaquetes;j++)
                            {
                                paquetesAModificar[j]=(PaquetePtr)desapilar(pilasAux[i]);
                                setEstado(paquetesAModificar[j],nuevoEstado);
                            }
                            for(int j=nPaquetes;j>0;j--)
                                apilar(pilasAux[i],(PaquetePtr)paquetesAModificar[j]);
                        }
                    }
                    else
                    {
                        for(int i=0;i<=(hasta-desde);i++)
                        {
                            pilasAux[i]=getPaquetesReparto(repartosAModificar[i]);
                            nPaquetes=cantidadPaquetes(repartosAModificar[i]);
                            for(int j=0;j<nPaquetes;j++)
                            {
                                paquetesAModificar[j]=(PaquetePtr)desapilar(pilasAux[i]);
                                setEstado(paquetesAModificar[j],nuevoEstado);
                            }
                            for(int j=nPaquetes;j>0;j--)
                                apilar(pilasAux[i],(PaquetePtr)paquetesAModificar[j]);
                        }
                    }
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    break;
                case 0:
                    break;
                case -1:
                    *opMenuAnterior=0;
                    break;
                default:
                    printf("Opcion incorrecta.");
                    presionarEnterYLimpiarPantalla();
                    break;
                }
                continuar=menuContinuar();
            }while(!(op2==0 || op2==-1) && continuar);
        }


        bool cambioDetectado = detectarCambios(listaAux,copiaLista,4);
        fechaAModificar = destruirFecha(fechaAModificar);
        if(cambioDetectado)
            return menuGuardarCambios(centroLogistico,4);
        else
            return true;
    }
}


///--------------------------------------------------------------------------------------------------------------------------///

///                                                FUNCIONES DE BÚSQUEDA DE ESTRUCTURAS

///--------------------------------------------------------------------------------------------------------------------------///

void menuBuscarPaquete(CentroLogisticoPtr centroLogistico)
{
    bool continuar;

    if(listaVacia(getPaquetes(centroLogistico)))
    {
        printf("ERROR: Lista vacia. No hay paquetes para buscar.");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            int ID=0;
            printf("BUSCAR PAQUETE\n\n");

            printf("Ingrese ID del paquete a buscar: ");
            scanf("%d",&ID);
            limpiarBufferTeclado();
            printf("\n\n");

            if(!buscarPaquete(centroLogistico,ID))
                printf("\n\nNo se pudo encontrar el paquete con ID #%d.\n\n",ID);

            continuar=menuContinuar();
        } while(continuar);
    }
}
void menuBuscarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    bool continuar;
    char cadena[100];
    if(listaVacia(getPersonas(centroLogistico)))
    {
        if(esChofer)
            printf("ERROR: Lista vacia. No hay choferes para buscar.");
        else
            printf("ERROR: Lista vacia. No hay clientes para buscar.");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            CuilPtr cuilABuscar = crearCuil("000000000000");
            if(esChofer){
                printf("BUSCAR CHOFER\n\n");
            }else{
                printf("BUSCAR CLIENTE\n\n");
                printf("Ingrese el CUIL del cliente a buscar: ");
            }
            printf("\n\n");
            limpiarBufferTeclado();
            scanf("%[^\n]%*c",cadena);
            setCuil(cuilABuscar,cadena);
            if(!buscarPersona(centroLogistico,cuilABuscar,esChofer))
            {
                if(esChofer)
                    printf("\n\nNo se pudo encontrar el chofer con CUIL %s.\n\n",getCuil(cuilABuscar));
                else
                    printf("\n\nNo se pudo encontrar el cliente con CUIL %s.\n\n",getCuil(cuilABuscar));
            }

            continuar=menuContinuar();
        } while(continuar);
    }
}
void menuBuscarVehiculo(CentroLogisticoPtr centroLogistico)
{
    bool continuar;

    if(listaVacia(getVehiculos(centroLogistico)))
    {
        printf("ERROR: Lista vacia. No hay vehiculos para buscar.");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            char patente[100];
            printf("BUSCAR VEHICULO\n\n");

            printf("Ingrese la patente del vehiculo a buscar (AA 111 AA): ");
            scanf("%[^\n]%*c",patente);

            if(!buscarVehiculo(centroLogistico,patente))
                printf("\n\nNo se pudo encontrar el vehiculo con patente %s.\n\n",patente);

            continuar=menuContinuar();
        } while(continuar);
    }
}
RepartoPtr menuBuscarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    ListaPtr listaAux = getRepartos(centroLogistico,esRepartoAbierto);

    if(listaVacia(listaAux))
    {
        printf("ERROR: Lista vacia. No hay repartos para buscar.");
        presionarEnterYLimpiarPantalla();
        return NULL;
    }
    else
    {
        int i=0;
        int n=longitudLista(listaAux);
        RepartoPtr repartoBuscar;

        bool continuar;
        do
        {
            printf("Seleccione un reparto para buscar mediante su indice: ");
            scanf("%d",&i);
            if(i>=0 && i<n)
            {
                repartoBuscar=getDatoLista(listaAux,i-1);
                mostrarReparto(repartoBuscar);
            }
            else
                printf("Reparto inexistente\n");

            presionarEnterYLimpiarPantalla();

            continuar=menuContinuar();
        } while(continuar);

        return repartoBuscar;
    }
}


///--------------------------------------------------------------------------------------------------------------------------///

///                                                FUNCIONES DE MUESTRA DE ESTRUCTURAS

///--------------------------------------------------------------------------------------------------------------------------///

bool menuMostrarPaquetes(CentroLogisticoPtr centroLogistico,int *opMenuAnterior)
{
    if(listaVacia(getPaquetes(centroLogistico)))
    {
        printf("ERROR: La lista esta vacia.");
        presionarEnterYLimpiarPantalla();
        return true;
    }
    else
    {
        int op=0;
        do
        {
            printf("EMITIR LISTADO DE PAQUETES");
            printf("\n\n-----------------------------------------\n\n");
            printf("1. Ordenados por ID\n");
            printf("2. Ordenados por Fecha de Entrega\n");
            printf("3. Ordenados por Estado\n");
            printf("4. SIN ORDENAR\n");
            printf("0. Volver\n");
            printf("-1. MENU PRINCIPAL");
            printf("\n\n-----------------------------------------\n\n");
            printf("Elija una opcion: ");
            scanf("%d",&op);
            limpiarBufferTeclado();
            system("cls");
            switch(op)
            {
            case 1:
                printf("LISTADO DE PAQUETES (ORDENADOS POR ID)");
                ordenarPaquetes(centroLogistico,1);
                break;
            case 2:
                printf("LISTADO DE PAQUETES (ORDENADOS POR FECHA DE SALIDA)");
                ordenarPaquetes(centroLogistico,2);
                break;
            case 3:
                printf("LISTADO DE PAQUETES (ORDENADOS POR ESTADO)");
                ordenarPaquetes(centroLogistico,3);
                break;
            case 4:
                printf("LISTADO DE PAQUETES (SIN ORDENAR)");
                break;
            case 0:
                break;
            case -1:
                *opMenuAnterior=0;
                break;
            default:
                printf("\nOpcion incorrecta.");
                break;
            }
            if(!(op==0 || op==-1))
            {
                printf("\n\n-----------------------------------------------------\n");
                mostrarPaquetes(centroLogistico);
                presionarEnterYLimpiarPantalla();
            }
        } while(!(op==0 || op==-1));

        return true;
    }
}
bool menuMostrarPersonas(CentroLogisticoPtr centroLogistico,int tipo,int *opMenuAnterior)
{
    if(listaVacia(getPersonas(centroLogistico)))
    {
        printf("ERROR: La lista esta vacia.");
        presionarEnterYLimpiarPantalla();
        return true;
    }
    else
    {
        int op=0;

        do
        {
            switch(tipo)
            {
            case 1:
                printf("EMITIR LISTADO DE CHOFERES\n");
                break;
            case 2:
                printf("EMITIR LISTADO DE CLIENTES\n");
                break;
            case 3:
                printf("EMITIR LISTADO DE PERSONAS\n");
                break;
            }
            printf("\n\n-----------------------------------------\n\n");
            printf("1. Ordenados por Nombre\n");
            printf("2. Ordenados por Apellido\n");
            printf("3. Ordenados por Nombre y Apellido\n");
            printf("4. SIN ORDENAR\n");
            printf("0. Volver\n");
            printf("-1. MENU PRINCIPAL");
            printf("\n\n-----------------------------------------\n\n");
            printf("Elija una opcion: ");
            scanf("%d",&op);
            limpiarBufferTeclado();

            system("cls");

            if(op==-1)
                *opMenuAnterior=0;
            else if(op<-1 || op>4)
            {
                printf("Opcion Incorrecta.");
                presionarEnterYLimpiarPantalla();
            }
            else if(op>=1 && op<=4)
            {
                switch(tipo)
                {
                case 1:
                    printf("LISTADO DE CHOFERES ");
                    break;
                case 2:
                    printf("LISTADO DE CLIENTES ");
                    break;
                case 3:
                    printf("LISTADO DE PERSONAS ");
                    break;
                case 0:
                    break;
                }
                switch(op)
                {
                case 1:
                    printf("(ORDENADOS POR NOMBRE)");
                    ordenarPersonas(centroLogistico,1);
                    break;
                case 2:
                    printf("(ORDENADOS POR APELLIDO)");
                    ordenarPersonas(centroLogistico,2);
                    break;
                case 3:
                    printf("(ORDENADOS POR NOMBRE Y APELLIDO)");
                    ordenarPersonas(centroLogistico,3);
                    break;
                case 4:
                    printf("(SIN ORDENAR)");
                    break;
                }

                printf("\n\n-----------------------------------------------------\n\n");
                switch(tipo)
                {
                case 1:
                    mostrarPersonas(centroLogistico,1);
                    break;
                case 2:
                    mostrarPersonas(centroLogistico,2);
                    break;
                case 3:
                    mostrarPersonas(centroLogistico,3);
                    break;
                }
                printf("\n\n-----------------------------------------------------");
                presionarEnterYLimpiarPantalla();
            }
        } while(!(op==0 || op==-1));

        return true;
    }
}
bool menuMostrarVehiculos(CentroLogisticoPtr centroLogistico,int *opMenuAnterior)
{
    if(listaVacia(getVehiculos(centroLogistico)))
    {
        printf("ERROR: La lista esta vacia.");
        presionarEnterYLimpiarPantalla();
        return true;
    }
    else
    {
        int op=0;;

        do
        {
            printf("EMITIR LISTADO DE VEHICULOS\n");
            printf("\n\n-----------------------------------------\n\n");
            printf("1. Ordenados por Marca\n");
            printf("2. Ordenados por Marca y Modelo\n");
            printf("3. SIN ORDENAR\n");
            printf("0. Volver\n");
            printf("-1. MENU PRINCIPAL");
            printf("\n\n-----------------------------------------\n\n");
            printf("Elija una opcion: ");
            scanf("%d",&op);
            limpiarBufferTeclado();
            system("cls");
            switch(op)
            {
            case 1:
                printf("LISTADO DE VEHICULOS (ORDENADOS POR MARCA)");
                ordenarVehiculos(centroLogistico,1);
                break;
            case 2:
                printf("LISTADO DE VEHICULOS (ORDENADOS POR MARCA Y MODELO)");
                ordenarVehiculos(centroLogistico,2);
                break;
            case 3:
                printf("LISTADO DE VEHICULOS (SIN ORDENAR)");
                break;
            case 0:
                break;
            case -1:
                *opMenuAnterior=0;
                break;
            default:
                printf("\nOpcion incorrecta.");
                presionarEnterYLimpiarPantalla();
                break;
            }
            if(op>=1 && op<=3)
            {
                printf("\n\n-----------------------------------------------------\n\n");
                mostrarVehiculos(centroLogistico);
                printf("\n\n-----------------------------------------------------");
                presionarEnterYLimpiarPantalla();
            }
        } while(!(op==0 || op==-1));

        return true;
    }
}
bool menuMostrarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int *opMenuAnterior)
{
    FechaPtr fechaSalida = crearFecha(0,0,0,0,0);
    if(listaVacia(getRepartos(centroLogistico,esRepartoAbierto)))
    {
        printf("ERROR: La lista esta vacia.");
        presionarEnterYLimpiarPantalla();
        return true;
    }
    else
    {
        int op2=0;
        int op3=0;

        int i=0;

        do
        {
            if(esRepartoAbierto)
                printf("EMITIR LISTADO DE REPARTOS ABIERTOS\n");
            else
                printf("EMITIR LISTADO DE REPARTOS CERRADOS\n");
            printf("\n\n-----------------------------------------\n\n");
            printf("1. Mostrar un reparto\n");
            printf("2. Mostrar lista de repartos\n");
            printf("3. Ordenar lista y mostrar...\n");
            printf("0. Volver\n");
            printf("-1. MENU PRINCIPAL");
            printf("\n\n-----------------------------------------\n\n");
            printf("Elija una opcion:");
            scanf("%d",&op2);
            limpiarBufferTeclado();

            system("cls");
            switch(op2)
            {
            case 1:
                do
                {
                    mostrarRepartos(centroLogistico,esRepartoAbierto);

                    printf("\nSeleccione un reparto para mostrar:");
                    scanf("%d",&i);
                    limpiarBufferTeclado();
                    if(i<=0 || i>=longitudLista(getRepartos(centroLogistico,esRepartoAbierto)))
                        printf("\n\nIndice inexistente. Vuelva a ingresarlo.");
                    presionarEnterYLimpiarPantalla();
                } while(i>0 && i<longitudLista(getRepartos(centroLogistico,esRepartoAbierto)));

                mostrarReparto(getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),i-1));

                presionarEnterYLimpiarPantalla();
                break;
            case 2:
                do
                {
                    printf("MOSTRAR LISTA DE REPARTOS:\n");

                    printf("1. Filtrados por fecha de salida\n");
                    printf("2. Sin filtrar\n");
                    printf("0. Volver\n");
                    printf("-1. MENU PRINCIPAL");
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d",&op3);

                    system("cls");
                    switch(op3)
                    {
                    case 1:
                        printf("MOSTRAR LISTA DE REPARTOS FILTRADOS POR FECHA DE SALIDA\n\n");

                        printf("Fecha para filtrar\n");
                        cargarFecha(fechaSalida);
                        ordenarRepartos(centroLogistico,esRepartoAbierto,1);
                        break;
                    case 2:
                        mostrarRepartos(centroLogistico, esRepartoAbierto);
                        break;
                    case 0:
                        break;
                    case -1:
                        op2=-1;
                        break;
                    default:
                        printf("Opcion incorrecta.");
                        break;
                    }
                    if(!(op3==0 || op3==-1))
                        presionarEnterYLimpiarPantalla();
                } while(!(op3==0 || op3==-1));
                break;
            case 3:
                do
                {
                    printf("ORDENAR Y MOSTRAR POR:\n");

                    printf("1. Fecha de salida\n");
                    printf("2. Fecha de retorno\n");
                    printf("3. Fecha de salida y retorno\n");
                    printf("4. Nombre del chofer\n");
                    printf("5. Apellido del chofer\n");
                    printf("6. Nombre y apellido del chofer\n");
                    printf("0. Volver\n\n");
                    printf("-1. MENU PRINCIPAL");
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Elija una opcion: ");
                    scanf("%d",&op3);

                    system("cls");
                    switch(op3)
                    {
                    case 1:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,1);
                        break;
                    case 2:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,2);
                        break;
                    case 3:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,3);
                        break;
                    case 4:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,4);
                        break;
                    case 5:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,5);
                        break;
                    case 6:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,6);
                        break;
                    case 0:
                        break;
                    case -1:
                        op2=-1; //En lugar de poner cada una en 0, ponemos en -1 para que vaya a la cláusula del menú anterior, haciendo todo de una
                    default:
                        printf("Opcion incorrecta.");
                        presionarEnterYLimpiarPantalla();
                        break;
                    }
                    if(op3>=1 && op3<=6) //si se eligio volver o una opcion invalida,
                    {
                        mostrarRepartos(centroLogistico,esRepartoAbierto); //no mostramos nada.
                        presionarEnterYLimpiarPantalla();
                    }
                } while(!(op3==0 || op3==-1));
                break;
            case 0:
                break;
            case -1:
                *opMenuAnterior=0;
            default:
                printf("Opcion incorrecta.");
                presionarEnterYLimpiarPantalla();
                break;
            }
        } while(!(op2==0 || op2==-1));
        fechaSalida = destruirFecha(fechaSalida);
        return true;
    }
}

///--------------------------------------------------------------------------------------------------------------------------///

///                                                FUNCIONES AYUDANTES ESPECIALES

///--------------------------------------------------------------------------------------------------------------------------///


///PENDIENTE: modificar donde se llama a la funcion
bool choferEnReparto(CentroLogisticoPtr centroLogistico, PersonaPtr choferEvaluar,bool esRepartoAbierto)
{
    //bool match = false;

    RepartoPtr repartoAux;
    PersonaPtr personaAux;

    CuilPtr cuilAux;
    CuilPtr cuilEvaluar = getCuilPersona(choferEvaluar);

    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getRepartos(centroLogistico, esRepartoAbierto));
    while(!listaVacia(listaAux))
    {
        repartoAux = (RepartoPtr)getCabecera(listaAux);
        personaAux = getChofer(repartoAux);

        if(cuilsIguales(getCuilPersona(personaAux)),getCuilPersona(choferEvaluar))
        {
            listaAux = destruirLista(listaAux, false);
            return false;
        }
        listaAux = getResto(listaAux);
    }
    listaAux = destruirLista(listaAux, false);

    return true;
}

///////////////////////////////////////////////COMENTARIOS FRANCO/////////////////////////////////////////////////////
///Podría directamente retornar el índice / indices (o la cantidad) donde se encontraron los choferes o -1 si no hay, sería más útil.
/** OPERACIÓN:
PRECONDICIÓN:
POSTCONDICIÓN:
PARÁMETROS:
    -
DEVUELVE: Nada. */
bool hayChoferes(CentroLogisticoPtr centroLogistico)
{
    bool match = false;
    PersonaPtr personaAux;
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getPersonas(centroLogistico));
    while(!listaVacia(listaAux))
    {
        personaAux = (PersonaPtr)getCabecera(listaAux);
        if(getEsChofer(personaAux))
            match = true;
        listaAux = getResto(listaAux);
    }
    listaAux = destruirLista(listaAux, false);
    return match;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** OPERACIÓN:
PRECONDICIÓN:
POSTCONDICIÓN:
PARÁMETROS:
    -
DEVUELVE: Nada. */
void mostrarChoferesDisponibles(CentroLogisticoPtr centroLogistico)
{
    int cont = 1;

    bool condicion=false; ///Cambiamos el flag a una condicion compuesta

    PersonaPtr personaAux;
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getPersonas(centroLogistico));
    while(!listaVacia(listaAux))
    {
        personaAux = (PersonaPtr)getCabecera(listaAux);

        condicion = getEsChofer(personaAux)
                    && !choferEnReparto(centroLogistico, personaAux,true);
    //Condicion: tiene que ser un chofer, y no figurar en la lista de repartos abiertos
        if(!condicion) ///De esta manera, no se vuelve necesario encadenar tantos ifs.
        {
            printf("\n\nPosicion %d.\n\n", cont);
            mostrarPersona(personaAux);
        }
        listaAux = getResto(listaAux);
        cont++;
    }
    listaAux = destruirLista(listaAux, false);
}

/** OPERACIÓN:
PRECONDICIÓN:
POSTCONDICIÓN:
PARÁMETROS:
    -
DEVUELVE: Nada. */
void mostrarPaquetesDisponibles(CentroLogisticoPtr centroLogistico)
{
    int cont = 1;

    PaquetePtr paqueteAux;
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getPaquetes(centroLogistico));

    while(!listaVacia(listaAux))
    {
        paqueteAux = (PaquetePtr)getCabecera(listaAux);

        int estado = getEstado(paqueteAux);
        bool paqueteDisponible = estado == 0 || estado == 5;
        if(paqueteDisponible)
        {
            printf("\n\n Posicion %d. \n\n", cont);
            mostrarPaquete(paqueteAux);
        }

        listaAux = getResto(listaAux);
        cont++;
    }
    listaAux = destruirLista(listaAux, false);
}

/** OPERACIÓN:
PRECONDICIÓN:
POSTCONDICIÓN:
PARÁMETROS:
    -
DEVUELVE: Nada. */
bool hayPaquetesDisponibles(CentroLogisticoPtr centroLogistico)
{
    bool match = false;

    PaquetePtr paqueteAux;
    ListaPtr listaAux = crearLista();
    agregarLista(listaAux, getPaquetes(centroLogistico));

    while(!listaVacia(listaAux))
    {
        paqueteAux = (PaquetePtr)getCabecera(listaAux);

        int estado = getEstado(paqueteAux);
        bool paqueteDisponible = estado == 0 || estado == 5;
        if(paqueteDisponible)
            match = true;
        listaAux = getResto(listaAux);
    }
    listaAux = destruirLista(listaAux, false);
    return match;
}


///--------------------------------------------------------------------------------------------------------------------------///

///                                                FUNCIONES DEDICADAS A REPARTOS

///--------------------------------------------------------------------------------------------------------------------------///

bool menuArmarReparto(CentroLogisticoPtr centroLogistico)
{
    int k=0;
    int n=0;
    int i=0;

    bool continuar = false;

    bool hayRecursos = true;

    bool choferValido = false;
    bool vehiculoValido = false;
    bool paqueteValido = false;
    bool seguirApilando = false;

    RepartoPtr reparto;

    PersonaPtr choferElegido;
    VehiculoPtr vehiculoElegido;
    PaquetePtr paqueteElegido;

    PilaPtr pilaPaquetesElegidos = crearPila();

//------------------------------------------//
///SECCION DE VERIFICACION DE RECURSOS
//------------------------------------------//

    if(hayChoferes(centroLogistico)
       && !listaVacia(getVehiculos(centroLogistico))
       && !listaVacia(getPaquetes(centroLogistico))
       && hayPaquetesDisponibles(centroLogistico))
    { //Si hay recursos disponibles para armar un reparto, armamos

    //------------------------------------------//
    ///SECCION DE ARMADO
    //------------------------------------------//

        do
        {

        //------------------------------------------//
        ///SECCION DE VALIDACION
        //------------------------------------------//

        printf("ARMAR REPARTO\n\n");
            do
            { /// Validación y elección de chofer
                n = longitudLista(getPersonas(centroLogistico));
                mostrarChoferesDisponibles(centroLogistico);

                printf("\n\nSeleccione un chofer ingresando su indice: ");
                scanf("%d",&k);
                limpiarBufferTeclado();

                if(k > 0 && k < n)
                {
                    choferElegido = getDatoLista(getPersonas(centroLogistico), k-1);
                    if(getEsChofer(choferElegido))
                    {
                        if(!choferEnReparto(centroLogistico, choferElegido,false))
                            choferValido=true;
                        else
                        {
                            printf("\n\nERROR: El chofer elegido ya esta en un reparto abierto. Vuelva a elegir.");
                            presionarEnterYLimpiarPantalla();
                        }
                    }
                    else
                    {
                        printf("\n\nERROR: La persona elegida no es un chofer. Vuelva a elegir.");
                        presionarEnterYLimpiarPantalla();
                    }
                }
                else
                {
                    printf("\n\nIndice inexistente. Vuelva a elegir.");
                    presionarEnterYLimpiarPantalla();
                }
                system("cls");
            }while(!choferValido);

            choferElegido = getDatoLista(getPersonas(centroLogistico),k-1);

            do
            { /// Validación y elección de vehículo
                n = longitudLista(getVehiculos(centroLogistico));
                mostrarVehiculos(centroLogistico);

                printf("\n\nSeleccione un vehiculo ingresando su indice: ");
                scanf("%d",&k);
                limpiarBufferTeclado();

                if(k > 0 && k < n)
                {
                    vehiculoElegido = getDatoLista(getVehiculos(centroLogistico),k-1);
                    if(!buscarVehiculoRepartos(centroLogistico, getPatente(vehiculoElegido)))
                        vehiculoValido = true;
                    else
                    {
                        printf("\n\nVehiculo en otro reparto. Vuelva a elegir.");
                        presionarEnterYLimpiarPantalla();
                    }
                }
                else
                {
                    printf("\n\nIndice inexistente. Vuelva a elegir.");
                    presionarEnterYLimpiarPantalla();
                }
            } while(!vehiculoValido);

            vehiculoElegido=getDatoLista(getVehiculos(centroLogistico),k-1);

            system("cls");
            printf("\n\nFecha de salida:");
            FechaPtr fechaSalida = cargarFecha();
            printf("\n\nFecha de retorno:");
            FechaPtr fechaRetorno = cargarFecha();
            system("cls");

            do
            {
                paqueteValido = false;
                do
                {
                    ///SELECCION DE PAQUETES
                    n = longitudLista(getPaquetes(centroLogistico));
                    mostrarPaquetesDisponibles(centroLogistico);
                    printf("\n\nPaquete nro: %d. \n", i+1);
                    printf("Seleccione el paquete a cargar ingresando su indice: ");
                    limpiarBufferTeclado();
                    scanf("%d",&k);
                    if(k > 0 && k < n)
                    {
                        paqueteElegido = getDatoLista(getPaquetes(centroLogistico), k-1);
                        if(getEstado(paqueteElegido) == 0)
                        {
                            paqueteValido = true;
                        }
                        else
                        {
                            printf("\n\nERROR: Paquete actualmente en curso. Vuelva a elegir.");
                            presionarEnterYLimpiarPantalla();
                        }
                    }
                    else
                    {
                        printf("\n\nERROR: indice inexistente. Vuelva a elegir.");
                        presionarEnterYLimpiarPantalla();
                    }
                    system("cls");
                }while(!paqueteValido && hayPaquetesDisponibles(centroLogistico));
                setEstado(paqueteElegido, 1);
                apilar(pilaPaquetesElegidos, (PaquetePtr)paqueteElegido);
                seguirApilando = menuContinuar();
                i++;
            } while(seguirApilando);

            reparto = armarReparto(choferElegido, vehiculoElegido, fechaSalida, fechaRetorno, pilaPaquetesElegidos);
            if(esRepartoExistente(centroLogistico,reparto,true) && esRepartoExistente(centroLogistico,reparto,false))
            {
                reparto = destruirReparto(reparto);
                printf("ERROR: el reparto armado ya existia en el centro logistico. Pruebe seleccionando otro chofer o cambiando la fecha.");
            }
            else
            {
                agregarReparto(centroLogistico, reparto, true);
                printf("\n\nReparto armado exitosamente.");
            }

            continuar=menuContinuar();
        } while(continuar);
    }

    return menuGuardarCambios(centroLogistico,4);
}


bool menuCerrarReparto(CentroLogisticoPtr centroLogistico,int *opMenuAnterior)
{
    RepartoPtr* repartosCerrar = NULL;
    if(listaVacia(getRepartos(centroLogistico,true)))
    {
        printf("ERROR: La lista esta vacia.");
        presionarEnterYLimpiarPantalla();
        return true;
    }
    else
    {
        bool continuar;

/// ////////////////////////////////////////////////////////////////////////////////// ///
        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion==0 && modoAccion==-1))
        {
        //para el modo de accion 1,
            int indice;
            RepartoPtr repartoCerrar;
        //para el modo de accion 2,
            int nIndices = 0;
            int indices[100];
        //para el modo de accion 3,
            int desde=0,hasta=0;
        //para los modos de accion 2 y 3,
/// ////////////////////////////////////////////////////////////////////////////////// ///
            do
            {
                bool existeEnCerrados=false;

                ListaPtr listaAux=getRepartos(centroLogistico,true);
                do
                {
                    mostrarRepartos(centroLogistico,true);
                    if(modoAccion==1)
                    {
                        printf("CERRAR REPARTO\n");
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Reparto a cerrar:");
                        indice = menuModoAccion1(listaAux);

                        repartoCerrar=(RepartoPtr)getDatoLista(getRepartos(centroLogistico,true),indice-1);
                        existeEnCerrados = esRepartoExistente(centroLogistico,repartoCerrar,false);
                        if(existeEnCerrados)
                        {
                            printf("\n\nERROR: el reparto seleccionado ya existe en la lista de repartos cerrados.");
                            presionarEnterYLimpiarPantalla();
                        }
                    }
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
                    else if(modoAccion==2)
                    {
                        printf("CERRAR REPARTOS\n");
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Repartos a cerrar:");
                        menuModoAccion2(listaAux,&nIndices,indices);
                        int i=0;
                        while(i<nIndices && !existeEnCerrados)
                        {
                            repartosCerrar[i]=(RepartoPtr)getDatoLista(getRepartos(centroLogistico,false),indices[i]-1);
                            if(esRepartoExistente(centroLogistico,repartoCerrar,false))
                                existeEnCerrados=true;
                            i++;
                        }

                        if(existeEnCerrados)
                        {
                            printf("\n\nERROR: hay repartos seleccionados que ya existen en la lista de repartos cerrados.");
                            presionarEnterYLimpiarPantalla();
                        }
                    }
                    else
                    {
                        printf("CERRAR REPARTOS\n");
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Repartos a cerrar:");
                        menuModoAccion3(listaAux,&desde,&hasta);
                        int i=desde;
                        while(i<=hasta && !existeEnCerrados)
                        {
                            repartosCerrar[i]=(RepartoPtr)getDatoLista(getRepartos(centroLogistico,false),i);
                            if(esRepartoExistente(centroLogistico,repartoCerrar,false))
                                existeEnCerrados=true;
                            i++;
                        }
                        if(existeEnCerrados)
                        {
                            printf("\n\nERROR: hay repartos seleccionados que ya existen en la lista de repartos cerrados.");
                            presionarEnterYLimpiarPantalla();
                        }
                    }
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
                }while(existeEnCerrados);

                if(modoAccion==1)
                {
                    cerrarReparto(centroLogistico,indice-1);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Reparto cerrado exitosamente.\n\n");
                }
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
                else if(modoAccion==2)
                {
                    for(int i=0,j=0;i<nIndices;i++,j++)
                        cerrarReparto(centroLogistico,indices[i]-j-1);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Repartos cerrados exitosamente.\n\n");
                }
                else
                {
                    for(int i=desde;i<=hasta;i++)
                        cerrarReparto(centroLogistico,desde-1);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Repartos cerrados exitosamente.\n\n");
                }
                continuar=menuContinuar();
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
            } while(continuar);
        ///Como sí o sí vamos a hacer un cambio, no se necesita detectarlos en este menú.
            return menuGuardarCambios(centroLogistico,4);
        }
        else //if(modoAccion == 0 || modoAccion == -1)
            return true; //ya nos encargamos de poner opMenuAnterior en la funcion menuModoAccion
    }
}
bool menuActualizarReparto(CentroLogisticoPtr centroLogistico)
{
    if(listaVacia(getRepartos(centroLogistico,true)))
    {
        printf("ERROR: Lista Vacia.");
        presionarEnterYLimpiarPantalla();
        return true;
    }
    else
    {
        bool continuar;

        ListaPtr listaAux = getRepartos(centroLogistico,true);
        ListaPtr copiaLista = copiarLista(listaAux,4);

        do
        {
            RepartoPtr repartoActualizar = menuBuscarReparto(centroLogistico,true);

            PilaPtr pilaAux = getPaquetesReparto(repartoActualizar);
            int n=longitudPila(pilaAux);
            PaquetePtr paquetesPila[n];
            if(pilaVacia(pilaAux))
            {
                printf("ERROR: Este reparto no tiene entregas.");
                presionarEnterYLimpiarPantalla();
            }
            else
            {
                int op;

                int opEstado;
                int nEstado;

                for(int i=0;i<n;i++)
                    paquetesPila[i]=(PaquetePtr)desapilar(pilaAux);
                do
                {
                    printf("\n\nSeleccione el indice de la entrega a actualizar: ");
                    scanf("%d",&op);
                    if(op<=0 || op>n)
                    {
                        printf("Entrega inexistente.");
                        presionarEnterYLimpiarPantalla();
                    }
                } while(op<=0 || op>n);

                limpiarBufferTeclado();
                system("cls");

                do
                {
                    mostrarPaquete(paquetesPila[op]);

                    printf("\n--------------------------------------------------\n\n");
                    printf("NUEVO ESTADO DE LA ENTREGA: \n\n");
                    printf("1. Ya se RETIRO de la direccion del vendedor\n");
                    printf("2. Ya se ENTREGO en la direccion del comprador\n");
                    printf("3. Hubo un problema y esta DEMORADA\n");
                    printf("4. La entrega queda SUSPENDIDA hasta nuevo aviso\n");
                    printf("0. Volver\n");
                    printf("\n\n--------------------------------------------------\n\n");
                    printf("Indique el estado actual informado por el chofer: ");
                    scanf("%d",&opEstado);
                    limpiarBufferTeclado();

                    system("cls");
                    switch(opEstado)
                    {
                    case 1:
                        nEstado = 2;
                        break;
                    case 2:
                        nEstado = 3;
                        break;
                    case 3:
                        nEstado = 4;
                        break;
                    case 4:
                        nEstado = 5;
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opcion incorrecta.");
                        break;
                    }
                    if(opEstado>=1 && opEstado<=4)
                        setEstado(paquetesPila[opEstado],nEstado);

                    if(opEstado!=0)
                        presionarEnterYLimpiarPantalla();
                } while(opEstado!=0);
            }
            continuar=menuContinuar();
        } while(continuar);

        bool cambioDetectado = detectarCambios(listaAux,copiaLista,4);

        if(cambioDetectado)
            return menuGuardarCambios(centroLogistico,4);
        else
            return true;
    }
}


///--------------------------------------------------------------------------------------------------------------------------///

///                                                FUNCIONES ESPECIALES

///--------------------------------------------------------------------------------------------------------------------------///

CentroLogisticoPtr menuCrearNuevoCtroLogRapido(CentroLogisticoPtr ctroLog)
{
    char nuevoNombre[100];

    printf("INGRESE EL NOMBRE DEL CENTRO LOGISTICO: ");
    scanf("%[^\n]%*c",nuevoNombre);
    limpiarBufferTeclado();

    ctroLog=crearCentroLogisticoRapido(nuevoNombre);

    return ctroLog;
}

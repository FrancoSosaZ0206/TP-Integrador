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


///--------------------------------------------------------------------------------------------------------------------------

///                                                  FUNCIONES AYUDANTES

///--------------------------------------------------------------------------------------------------------------------------

//OPERACIÓN: menu de modo de accion
//PRECONDICIÓN: ninguna
//POSTCONDICION: se imprime en pantalla un menu preguntando como proceder a la accion sobre una lista de datos.
//PARÁMETROS:
//  opMenuAnterior: entero representando la opcion del menu anterior
//DEVUELVE: entero representando la opcion elegida.
int menuModoAccion(int opMenuAnterior)
{
    int eleccion = 0;
    do
    {
        limpiarBufferTeclado();
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
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(eleccion<-1 || eleccion>3);

    if(eleccion==-1)
        opMenuAnterior=-1;

    return eleccion;
}
//OPERACIÓN: menu de modo de accion
//PRECONDICIÓN: haber usado menuModoAccion
//POSTCONDICION: se ejecuta el modo de accion 1 - se toma un indice por pantalla.
//PARÁMETROS:
//  lista: puntero representando la lista sobre la que se quiere accionar (repartos, personas...).
//DEVUELVE: entero representando el índice elegido.
int menuModoAccion1(ListaPtr lista)
{
    int n=longitudLista(lista);
    int i;
    do
    {
        printf("\n\nIngrese indice donde tomar accion: ");
        scanf("%d",&i);
        limpiarBufferTeclado();
        if(i<=0 || i>=n)
        {
            printf("\n\nERROR: indice inexistente. Vuelva a elegir.\n\n");
            presionarEnterYLimpiarPantalla();
        }
        else
            system("cls");
    } while(i<=0 || i>=n);

    return i;
}
//OPERACIÓN: menu de modo de accion
//PRECONDICIÓN: haber usado menuModoAccion
//POSTCONDICION: se ejecuta el modo de accion 2 - se toma un conjunto de índices por pantalla.
//PARÁMETROS:
//  lista: puntero representando la lista sobre la que se quiere accionar (repartos, personas...).
//  cantIndices: entero representando la variable que se cargará con la cantidad de indices seleccionados
//DEVUELVE: vector de enteros representando la seleccion de índices elegidos.
///ADVERTENCIA: No usar con menus o funciones que modifiquen la longitud de la lista (ej: menuEliminar).
int *menuModoAccion2(ListaPtr lista,int cantIndices)
{
    int n=longitudLista(lista);
//Ingresamos la cantidad de indices a seleccionar
    do
    {
        printf("Ingrese cantidad de indices a seleccionar: ");
        scanf("%d",&cantIndices);
        if(cantIndices<=0)
        {
            printf("\n\nCantidad incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(cantIndices<=0);

    int *indices;
//Elegimos los indices
    for(int i=0;i<cantIndices;i++)
    {
        do
        {
            printf("\n\nIngrese indice %d: ",i+1);
            scanf("%d",&indices[i]);
            limpiarBufferTeclado();
            if(indices[i]<1 || indices[i]>n)
            {
                printf("\n\nIndice inexistente. Vuelva a ingresar.\n\n");
                presionarEnterYLimpiarPantalla();
            }
        } while(indices[i]<1 || indices[i]>n);
    }
    system("cls");
///NUEVO: ordenamos los índices de menor a mayor, lo que simplificará varias funciones
    int salto=n/2;
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
            salto=salto/2;
    }
//Retornamos el vector
    return indices;
}
//OPERACIÓN: menu de modo de accion
//PRECONDICIÓN: haber usado menuModoAccion
//POSTCONDICION: se ejecuta el modo de accion 3 - se toma un rango de índices por pantalla.
//PARÁMETROS:
//  lista: puntero representando la lista sobre la que se quiere accionar (repartos, personas...).
//  desde: entero representando la variable donde se cargará el índice mínimo.
//  hasta: entero representando la variable donde se cargará el índice máximo.
//DEVUELVE: nada.
void menuModoAccion3(ListaPtr lista,int desde,int hasta)
{
    int n=longitudLista(lista);
    do
    {
        printf("Ingrese el indice minimo: ");
        scanf("%d",&desde);
        limpiarBufferTeclado();
        if(desde<1 || desde>n)
        {
            printf("\n\nIndice incorrecto. Vuelva a ingresar.\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(desde<1 || desde>n);
    do
    {
        printf("Ingrese el indice maximo: ");
        scanf("%d",&hasta);
        limpiarBufferTeclado();
        if(hasta<desde || hasta>n)
        {
            printf("\n\nIndice incorrecto. Vuelva a ingresar.\n\n");
            presionarEnterYLimpiarPantalla();
        }
        else
            system("cls");
    } while(hasta<desde || hasta>n);
//El sistema permite que desde y hasta sean iguales si la lista tiene solo 1 elemento.
}

//OPERACIÓN: menu para continuar en un menú
//PRECONDICIÓN: ninguna
//POSTCONDICION: se imprime en pantalla un menu preguntando como proceder a la accion sobre una lista de datos.
//PARÁMETROS: ninguno
//DEVUELVE: booleano representando la opcion elegida:
//              true = SI, DESEA CONTINUAR
//              false = NO, DESEA SALIR
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


///--------------------------------------------------------------------------------------------------------------------------

///                             FUNCIONES DE CARGA, VALIDACIÓN Y ACTUALIZACIÓN DE SUBESTRUCTURAS

///--------------------------------------------------------------------------------------------------------------------------

//OPERACIÓN: carga de cuil con datos
//PRECONDICIÓN: cuil debe haber sido DECLARADO
//POSTCONDICION: se piden datos por pantalla y se crea un cuil en memoria dinamica con datos válidos
//PARÁMETROS:
// puntero a la estructura cuil que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse el cuil con su constructora, causará memory leaks.
void cargarCuil(CuilPtr cuil)
{
    char strCuil[100];

    int i=0;

    do
    {
        helpCuil();
        printf("\n\tCUIL:");
        scanf("%[^\n]%*c",strCuil);
        limpiarBufferTeclado();
        if(i==0)
            cuil=crearCuil(strCuil); ///IMPLEMENTACION CAMBIADA
        else if(i>0 && i<4)
            setCuil(cuil,strCuil);
        else    //if(i==4)
            printf("\n\nIntentos agotados.\n\n");

        i++;
        if(i>1)
            system("cls");
    } while(!esCuilValido(cuil));
}
//OPERACIÓN: carga de domicilio con datos
//PRECONDICIÓN: domicilio debe haber sido DECLARADO
//POSTCONDICION: se piden datos por pantalla y se crea un domicilio en memoria dinamica
//PARÁMETROS:
// puntero a la estructura domicilio que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse el domicilio con su constructora, causará memory leaks.
void cargarDomicilio(DomicilioPtr domicilio)
{
    char calle[100];
    int altura;
    char localidad[100];

    printf("\n\t\tCalle y Altura [CALLE, ALTURA]: ");
    scanf("%[^,]%*c, %d",calle,&altura);
    limpiarBufferTeclado();
    printf("\n\t\tLocalidad: ");
    scanf("%[^\n]%*c",localidad);
    limpiarBufferTeclado();

    domicilio=crearDomicilio(calle,altura,localidad);
}
//OPERACIÓN: carga de fecha con datos
//PRECONDICIÓN: fecha debe haber sido DECLARADA
//POSTCONDICION: se piden datos por pantalla y se crea una fecha con datos válidos
//PARÁMETROS:
// puntero a la estructura fecha que se quiere cargar
//DEVUELVE: Nada
///ADVERTENCIA: No debe crearse la fecha con su constructora, causará memory leaks.
void cargarFecha(FechaPtr fecha)
{
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
}

//OPERACIÓN: actualiza los datos de un cuil
//PRECONDICIÓN: cuil debe haberse creado
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion, y se actualiza la estructura
//PARÁMETROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
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
//OPERACIÓN: actualiza los datos de un domicilio
//PRECONDICIÓN: domicilio debe haberse creado
//POSTCONDICION: se piden datos por pantalla y se actualiza la estructura
//PARÁMETROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
void actualizarDomicilio(DomicilioPtr domicilio)
{
    char calle[100];
    int altura;
    char localidad[100];

    printf("\n\t\tCalle y Altura [CALLE, ALTURA]: ");
    scanf("%[^,]%*c, %d",calle,&altura);
    limpiarBufferTeclado();
    printf("\n\t\tLocalidad: ");
    scanf("%[^\n]%*c",localidad);
    limpiarBufferTeclado();

    setCalle(domicilio,calle);
    setAltura(domicilio,altura);
    setLocalidad(domicilio,localidad);
}
//OPERACIÓN: actualiza los datos de una fecha
//PRECONDICIÓN: fecha debe haberse creado
//POSTCONDICION: se piden datos por pantalla, se pasan por un proceso de validacion, y se actualiza la estructura
//PARÁMETROS:
//  puntero a la estructura a actualizar
//DEVUELVE: Nada
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
            printf("\n\nFecha invalida. Reingrese la fecha.\n\n");
            presionarEnterYLimpiarPantalla();
        }
        else if(i==4)
        {
            printf("\n\nSe agotaron los intentos.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }
    } while (!esFechaValida(fecha));
}

bool menuCargarPaquete(CentroLogisticoPtr centroLogistico)
{
    ///Variables para funciones
    int n=0;
    ///Paquete
    PaquetePtr paquete;
    int ID=0;   //el ID del paquete se genera automáticamente, no lo tiene que ingresar el usuario.
    int ancho=0;//el mismo se genera aleatoriamente.
    int alto=0;
    int largo=0;
    int peso=0;
        //Fecha
    FechaPtr fechaEntrega;
        //Domicilios
    DomicilioPtr dirRetiro;
    DomicilioPtr dirEntrega;
//por defecto, los paquetes se cargan con el estado 0: 'en depósito'.

    srand(time(NULL));

    bool continuar;
    bool cambiosGuardados=false;

    do
    {
        do
        {
            printf("CARGAR PAQUETE\n\n");
            printf("Ingrese cantidad de paquetes a cargar: ");
            scanf("%d",&n);
            limpiarBufferTeclado();

            if(n<1)
                printf("\nCantidad incorrecta.\n");
            presionarEnterYLimpiarPantalla();
        } while(n<1);

        for(int i=0;i<n;i++)
        {
            if(n>1)
                printf("\n\nPAQUETE %d\n\n",i+1);
            ID=rand(); //esto no se mostrará sino al final de la carga del paquete.
            printf("\tAncho: ");
            scanf("%d",&ancho);
            limpiarBufferTeclado();
            printf("\n\tAlto: ");
            scanf("%d",&alto);
            limpiarBufferTeclado();
            printf("\n\tLargo: ");
            scanf("%d",&largo);
            limpiarBufferTeclado();
            printf("\n\tPeso: ");
            scanf("%d",&peso);
            limpiarBufferTeclado();
            printf("\n\tDireccion de retiro:");
            cargarDomicilio(dirRetiro);
            printf("\n\tDireccion de entrega:");
            cargarDomicilio(dirEntrega);

            printf("\n\tFecha de entrega:");
            cargarFecha(fechaEntrega);

            paquete=crearPaquete(ID,ancho,alto,largo,peso,dirRetiro,dirEntrega,fechaEntrega,0);
            agregarPaquete(centroLogistico,paquete);

            printf("\n\nPaquete #%d cargado exitosamente.\n\n",ID);
            presionarEnterYLimpiarPantalla();
        }
        if(n>1)
            printf("Paquetes cargados exitosamente.\n\n");

        continuar=menuContinuar();
    } while(continuar);

    int opGuardar=0;
    do
    {
        printf("Guardar cambios? 1=SI , 0=NO | ");
        scanf("%d",&opGuardar);
        limpiarBufferTeclado();
        system("cls");
        switch(opGuardar)
        {
        case 1:
            if(guardarPaquetes(centroLogistico))
            {
                cambiosGuardados=true;
                printf("Cambios guardados exitosamente.\n\n");
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
            printf("Opcion incorrecta.\n\n");
            break;
        }
        if(opGuardar!=0)
            presionarEnterYLimpiarPantalla();
    } while(opGuardar!=0);

    return cambiosGuardados;
}
bool menuCargarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    ///Variables para funciones
    int n=0;
    ///Cliente
    char nombre[100];
    char apellido[100];
    PersonaPtr persona;
        //Domicilio
    DomicilioPtr domicilio;
        //Cuil
    CuilPtr cuil;

    bool continuar;
    bool cambiosGuardados=false;

    do
    {
        do
        {
            if(esChofer)
            {
                printf("CARGAR CHOFER\n\n");
                printf("Ingrese cantidad de choferes a cargar: ");
            }
            else
            {
                printf("CARGAR CLIENTE\n\n");
                printf("Ingrese cantidad de clientes a cargar: ");
            }
            scanf("%d",&n);
            limpiarBufferTeclado();
            if(n<1)
                printf("\nCantidad incorrecta.\n");
            presionarEnterYLimpiarPantalla();

        } while(n<1);


        for(int i=0;i<n;i++)
        {
            if(n>1)
            {
                if(esChofer)
                    printf("CHOFER %d\n\n",i+1);
                else
                    printf("CLIENTE %d\n\n",i+1);
            }
            printf("\n\n\tNombre: ");
            scanf("%[^\n]%*c",nombre);
            limpiarBufferTeclado();
            printf("\n\tApellido: ");
            scanf("%[^\n]%*c",apellido);
            limpiarBufferTeclado();

            printf("\n\tDomicilio");
            cargarDomicilio(domicilio);

            cargarCuil(cuil);

            persona=crearPersona(nombre,apellido,domicilio,cuil,false);
            agregarPersona(centroLogistico,persona);

            if(esChofer)
                printf("Cliente cargado exitosamente.\n\n");
            else
                printf("Cliente cargado exitosamente.\n\n");
            presionarEnterYLimpiarPantalla();
            system("pause");
        }
        if(esChofer && n>1)
            printf("Choferes cargados exitosamente.\n\n");
        else if(n>1)
            printf("Clientes cargados exitosamente.\n\n");

        continuar=menuContinuar();
    } while(continuar);

    int opGuardar=0;
    do
    {
        printf("Guardar cambios? 1=SI , 0=NO | ");
        scanf("%d",&opGuardar);
        limpiarBufferTeclado();
        system("cls");
        switch(opGuardar)
        {
        case 1:
            if(guardarPersonas(centroLogistico))
            {
                cambiosGuardados=true;
                printf("Cambios guardados exitosamente.\n\n");
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
            printf("Opcion incorrecta.\n\n");
            break;
        }
        if(opGuardar!=0)
            presionarEnterYLimpiarPantalla();
    } while(opGuardar!=0);

    return cambiosGuardados;
}
bool menuCargarVehiculo(CentroLogisticoPtr centroLogistico)
{
    ///Variables para funciones
    int n=0;
    ///Vehiculo
    int tipoVehiculo=0;
    char marca[100];
    char modelo[100];
    char patente[100];
    VehiculoPtr vehiculo;

    bool continuar;
    bool cambiosGuardados=false;

    do
    {
        do
        {
            printf("CARGAR VEHICULO\n\n");
            printf("Ingrese cantidad de vehiculos a cargar: ");
            scanf("%d",&n);
            limpiarBufferTeclado();

            if(n<1)
                printf("\nCantidad incorrecta.\n");
            presionarEnterYLimpiarPantalla();
        } while(n<1);

        for(int i=0;i<n;i++)
        {
            if(n>1)
                printf("\n\nVEHICULO %d\n\n",i+1);
            helpTipoVehiculo();
            printf("\n\n\tSeleccione un Tipo: ");
            scanf("%d",&tipoVehiculo);
            limpiarBufferTeclado();
            printf("\n\n\tMarca: ");
            scanf("%[^\n]%*c",marca);
            printf("\n\tModelo: ");
            scanf("%[^\n]%*c",modelo);
            limpiarBufferTeclado();
            printf("\n\tPatente (AA 000 AA): ");
            scanf("%[^\n]%*c",patente);
            limpiarBufferTeclado();

            vehiculo=crearVehiculo(tipoVehiculo,marca,modelo,patente);
            agregarDatoLista(centroLogistico->listaVehiculos,(VehiculoPtr)vehiculo);

            printf("\n\nVehiculo cargado exitosamente.\n\n");
            presionarEnterYLimpiarPantalla();
        }
        if(n>1)
            printf("\n\nVehiculos cargados exitosamente.\n\n");

        continuar=menuContinuar();
    } while(continuar);

    int opGuardar=0;
    do
    {
        printf("Guardar cambios? 1=SI , 0=NO | ");
        scanf("%d",&opGuardar);
        limpiarBufferTeclado();
        system("cls");
        switch(opGuardar)
        {
        case 1:
            if(guardarVehiculos(centroLogistico))
            {
                cambiosGuardados=true;
                printf("Cambios guardados exitosamente.\n\n");
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
            printf("Opcion incorrecta.\n\n");
            break;
        }
        if(opGuardar!=0)
            presionarEnterYLimpiarPantalla();
    } while(opGuardar!=0);

    return cambiosGuardados;
}

void menuBuscarPaquete(CentroLogisticoPtr centroLogistico)
{
    bool continuar;

    if(listaVacia(getPaquetes(centroLogistico)))
        printf("ERROR: Lista vacia. No hay paquetes para buscar\n");
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

    if(listaVacia(getPersonas(centroLogistico)))
    {
        if(esChofer)
            printf("ERROR: Lista vacia. No hay choferes para buscar\n");
        else
            printf("ERROR: Lista vacia. No hay clientes para buscar\n");
    }
    else
    {
        do
        {
            CuilPtr cuilABuscar;
            if(esChofer)
            {
                printf("BUSCAR CHOFER\n\n");
                printf("Ingrese el CUIL del chofer a buscar: ");
            }
            else
            {
                printf("BUSCAR CLIENTE\n\n");
                printf("Ingrese el CUIL del cliente a buscar: ");
            }
            cargarCuil(cuilABuscar);
            printf("\n\n");

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
        printf("ERROR: Lista vacia. No hay vehiculos para buscar\n");
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

bool menuEliminarPaquete(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    bool cambiosGuardados=false;
    bool continuar;

    ListaPtr listaAux = getPaquetes(centroLogistico);

    if(listaVacia(listaAux))
        printf("ERROR: Lista vacía. Debe agregar paquetes para poder eliminarlos.\n\n");
    else
    {
/// ////////////////////////////////////////////////////////////////////////////////// ///
        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion==0 && modoAccion==-1))
        {
        //para el modo de accion 1,
            int indice;
        //para el modo de accion 2,
            int nIndices;
            int *indices;
        //para el modo de accion 3,
            int desde=0,hasta=0;
/// ////////////////////////////////////////////////////////////////////////////////// ///
            if(modoAccion==1)
            {
                printf("ELIMINAR PAQUETE\n");
                mostrarPaquetes(centroLogistico);
                printf("\n\n-----------------------------------------\n\n");
                printf("Paquete a remover: ");
                indice=menuModoAccion1(listaAux);
            //Obtenemos y destruimos el elemento seleccionado
                destruirPaquete(removerPaquete(centroLogistico,indice));
            }
            else if(modoAccion==2)
            {
                printf("ELIMINAR PAQUETES\n");
                mostrarPaquetes(centroLogistico);
                printf("\n\n-----------------------------------------\n\n");
                printf("Paquetes a remover: ");
                indices = menuModoAccion2(listaAux,nIndices);
            //Obtenemos y destruimos los elementos en los indices seleccionados
                for(int i=0,j=0;i<nIndices;i++,j++)
                    destruirPaquete(removerPaquete(centroLogistico,indices[i]-j));
            }
            else
            {
                printf("ELIMINAR PAQUETES\n");
                mostrarPaquetes(centroLogistico);
                printf("\n\n-----------------------------------------\n\n");
                printf("Paquetes a remover: ");
                menuModoAccion3(listaAux,desde,hasta);
            //Obtenemos y destruimos los elementos en el rango de indices
                for(int i=desde;i<=hasta;i++)
                    destruirPaquete(removerPaquete(centroLogistico,desde));
            }

            continuar=menuContinuar();
        } while(continuar);

        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&opGuardar);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1:
                if(guardarPaquetes(centroLogistico))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
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
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(opGuardar!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }
    return cambiosGuardados;
}
bool menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer,int opMenuAnterior)
{
    bool cambiosGuardados=false;
    bool continuar;

    ListaPtr listaAux = getPersonas(centroLogistico);

    if(listaVacia(listaAux))
    {
        if(esChofer)
            printf("ERROR: Lista vacía. Debe agregar choferes para poder eliminarlos.\n\n");
        else
            printf("ERROR: Lista vacía. Debe agregar clientes para poder eliminarlos.\n\n");
    }
    else
    {
/// ////////////////////////////////////////////////////////////////////////////////// ///
        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion==0 && modoAccion==-1))
        {
        //para el modo de accion 1,
            int indice;
        //para el modo de accion 2,
            int nIndices;
            int *indices;
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
                destruirPersona(removerPersona(centroLogistico,indice));
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
                indices = menuModoAccion2(listaAux,nIndices);
            //Obtenemos y destruimos los elementos seleccionados
                for(int i=0,j=0;i<nIndices;i++,j++)
                    destruirPersona(removerPersona(centroLogistico,indices[i]-j));
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
                menuModoAccion3(listaAux,desde,hasta);
            //Obtenemos y destruimos los elementos en el rango de indices
                for(int i=desde;i<=hasta;i++)
                    destruirPersona(removerPersona(centroLogistico,desde));
            }

            continuar=menuContinuar();
        } while(continuar);

        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&opGuardar);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1:
                if(guardarPersonas(centroLogistico))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
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
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(opGuardar!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }
    return cambiosGuardados;
}
bool menuEliminarVehiculo(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    bool cambiosGuardados=false;
    bool continuar;

    ListaPtr listaAux = getVehiculos(centroLogistico);

    if(listaVacia(listaAux))
        printf("ERROR: Lista vacía. Debe agregar vehiculos para poder eliminarlos.\n\n");
    else
    {
/// ////////////////////////////////////////////////////////////////////////////////// ///
        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion==0 && modoAccion==-1))
        {
        //para el modo de accion 1,
            int indice;
        //para el modo de accion 2,
            int nIndices;
            int *indices;
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
                destruirVehiculo(removerVehiculo(centroLogistico,indice));
            }
            else if(modoAccion==2)
            {
                printf("ELIMINAR VEHICULOS\n");
                mostrarVehiculos(centroLogistico);
                printf("\n\n-----------------------------------------\n\n");
                printf("Vehiculos a remover: ");
                indices = menuModoAccion2(listaAux,nIndices);
            //Obtenemos y destruimos los elementos en los indices seleccionados
                for(int i=0,j=0;i<nIndices;i++,j++)
                    destruirVehiculo(removerVehiculo(centroLogistico,indices[i]-j));
            }
            else
            {
                printf("ELIMINAR VEHICULOS\n");
                mostrarVehiculos(centroLogistico);
                printf("\n\n-----------------------------------------\n\n");
                printf("Vehiculos a remover: ");
                menuModoAccion3(listaAux,desde,hasta);
            //Obtenemos y destruimos los elementos en el rango de indices
                for(int i=desde;i<=hasta;i++)
                    destruirVehiculo(removerVehiculo(centroLogistico,desde));
            }

            continuar=menuContinuar();
        } while(continuar);

        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&opGuardar);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1:
                if(guardarVehiculos(centroLogistico))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
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
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(opGuardar!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }
    return cambiosGuardados;
}

bool menuModificarPaquete(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    ListaPtr listaAux=getPaquetes(centroLogistico);

    bool cambioDetectado=false;
    bool cambiosGuardados=false;

    if(listaVacia(listaAux))
        printf("ERROR: Lista vacía. Debe agregar paquetes para poder modificarlos.\n\n");
    else
    {
    ///Creamos una lista "original" para ver si hay cambios,
    ///y una "auxiliar" para obtener y recorrer la lista.
        ListaPtr listaOriginal=crearLista();

        ListaPtr listaAux2=crearLista();
        agregarLista(listaAux2,getPaquetes(centroLogistico));
    //Hacemos lo mismo pero para cada elemento de la lista
        PaquetePtr paqueteOriginal;

        PaquetePtr paqueteAux;
        while(!listaVacia(listaAux2))
        {
            paqueteAux=getCabecera(listaAux2);
        ///Copiamos el contenido de cada elemento
            paqueteOriginal=crearPaquete(getID(paqueteAux),
                                         getAncho(paqueteAux),
                                         getAlto(paqueteAux),
                                         getLargo(paqueteAux),
                                         getPeso(paqueteAux),
                                         getDirRetiro(paqueteAux),
                                         getDirEntrega(paqueteAux),
                                         getFechaEntrega(paqueteAux),
                                         getEstado(paqueteAux));
         ///Agregamos el dato original a la lista
            agregarDatoLista(listaOriginal,(PaquetePtr)paqueteOriginal);
            listaAux2=getResto(listaAux2);
        }
        listaAux2=destruirLista(listaAux2,false);

        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!modoAccion == 0 && modoAccion == -1)
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
                int *indices;
            //para el modo de accion 3,
                int desde=0,hasta=0;
            //para los modos de accion 2 y 3,
                PaquetePtr *paquetesAModificar;

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
                    indices=menuModoAccion2(listaAux,nIndices);

                    printf("Ha elegido Paquetes");
                    for(int i=0;i<nIndices;i++)
                    { //Obtenemos los elementos en los indices seleccionados y los mostramos
                        paquetesAModificar[i]=(PaquetePtr)getDatoLista(listaAux,indices[i]);
                        printf("%d. ",indices[i]);
                        mostrarPaquete(paquetesAModificar[i]);
                    }
                }
                else
                {
                    printf("MODIFICAR PAQUETES\n\n");
                    menuModoAccion3(listaAux,desde,hasta);

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

                int nDimension=0; //vale para ancho, alto, largo y peso.
                DomicilioPtr nDireccion; //vale para retiro y entrega
                FechaPtr nFechaEntrega;
                int nEstado;


                printf("\n\nQué desea modificar?\n\n");

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

                system("cls");
                switch(op)
                {
                case 1:
                    do
                    {
                        printf("Ingrese nuevo Ancho: ");
                        scanf("%d",&nDimension);

                        if(nDimension<=0)
                        {
                            printf("\n\nERROR: una dimension debe ser mayor a cero. Vuelva a ingresar.\n\n");
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

                        if(nDimension<=0)
                        {
                            printf("\n\nERROR: una dimension debe ser mayor a cero. Vuelva a ingresar.\n\n");
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

                        if(nDimension<=0)
                        {
                            printf("\n\nERROR: una dimension debe ser mayor a cero. Vuelva a ingresar.\n\n");
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

                        if(nDimension<=0)
                        {
                            printf("\n\nERROR: una dimension debe ser mayor a cero. Vuelva a ingresar.\n\n");
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
                        if(nEstado<0 || nEstado>5)
                        {
                            printf("\n\nERROR: estado inexistente. Vuelva a ingresar.\n\n");
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
                    opMenuAnterior=-1;
                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    presionarEnterYLimpiarPantalla();
                    break;
                }

                printf("\n\nDatos modificados exitosamente.\n\n");

                continuar=menuContinuar();
            } while(!(op==0 && op==-1) && continuar);
        }

        listaAux2=crearLista();
        agregarLista(listaAux2,getPaquetes(centroLogistico));
    ///Recorremos la lista: antes y después de hacer el cambio
        while(!listaVacia(listaAux2))
        {
            paqueteAux=getCabecera(listaAux2);
            paqueteOriginal=getCabecera(listaOriginal);
        ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
            if(!paquetesIguales(paqueteOriginal,paqueteAux))
                cambioDetectado=true;

            listaAux2=getResto(listaAux2);
            listaOriginal=getResto(listaOriginal);
        }
        listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
        listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.

        if(cambioDetectado)
        {
            int opGuardar=0;
            do
            {
                printf("Guardar cambios? 1=SI , 0=NO | ");
                scanf("%d",&opGuardar);
                limpiarBufferTeclado();
                system("cls");
                switch(opGuardar)
                {
                case 1:
                    if(guardarPaquetes(centroLogistico))
                    {
                        cambiosGuardados=true;
                        printf("Cambios guardados exitosamente.\n\n");
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
                    printf("Opcion incorrecta.\n\n");
                    break;
                }
                if(opGuardar!=0)
                    presionarEnterYLimpiarPantalla();
            } while(opGuardar!=0);
        }
    }

    return cambiosGuardados;
}
bool menuModificarPersona(CentroLogisticoPtr centroLogistico,bool esChofer,int opMenuAnterior)
{
    ListaPtr listaAux=getPersonas(centroLogistico);

    bool cambioDetectado=false;
    bool cambiosGuardados=false;

    if(listaVacia(listaAux))
    {
        if(esChofer)
            printf("ERROR: Lista vacía. Debe agregar choferes para poder modificarlos.\n\n");
        else
            printf("ERROR: Lista vacía. Debe agregar clientes para poder modificarlos.\n\n");
    }
    else
    {
    ///Creamos una lista "original" para ver si hay cambios,
    ///y una "auxiliar" para obtener y recorrer la lista.
        ListaPtr listaOriginal=crearLista();

        ListaPtr listaAux2=crearLista();
        agregarLista(listaAux2,getPersonas(centroLogistico));
    //Hacemos lo mismo pero para cada elemento de la lista
        PersonaPtr personaOriginal;

        PersonaPtr personaAux;
        while(!listaVacia(listaAux2))
        {
            personaAux=getCabecera(listaAux2);
        ///Copiamos el contenido de cada elemento
            personaOriginal=crearPersona(getNombre(personaAux),
                                         getApellido(personaAux),
                                         getDomicilio(personaAux),
                                         getCuilPersona(personaAux),
                                         getEsChofer(personaAux));
         ///Agregamos el dato original a la lista
            agregarDatoLista(listaOriginal,(PersonaPtr)personaOriginal);
            listaAux2=getResto(listaAux2);
        }
        listaAux2=destruirLista(listaAux2,false);

        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!modoAccion == 0 && modoAccion == -1)
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
                int *indices;
            //para el modo de accion 3,
                int desde=0,hasta=0;
            //para los modos de accion 2 y 3,
                PersonaPtr *personasAModificar;

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
                    indices=menuModoAccion2(listaAux,nIndices);

                    if(esChofer)
                        printf("Ha elegido Choferes");
                    else
                        printf("Ha elegido Clientes");
                    for(int i=0;i<nIndices;i++)
                    { //Obtenemos los elementos en los indices seleccionados y los mostramos
                        personasAModificar[i]=(PersonaPtr)getDatoLista(listaAux,indices[i]);
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
                    menuModoAccion3(listaAux,desde,hasta);

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
                DomicilioPtr nDomicilio;
                CuilPtr nCuil;
                bool nEsChofer;


                printf("\n\nQué desea modificar?\n\n");

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
                    opMenuAnterior=-1;
                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    presionarEnterYLimpiarPantalla();
                    break;
                }

                printf("\n\nDatos modificados exitosamente.\n\n");

                continuar=menuContinuar();
            } while(!(op==0 && op==-1) && continuar);
        }

        listaAux2=crearLista();
        agregarLista(listaAux2,getPersonas(centroLogistico));
    ///Recorremos la lista: antes y después de hacer el cambio
        while(!listaVacia(listaAux2))
        {
            personaAux=getCabecera(listaAux2);
            personaOriginal=getCabecera(listaOriginal);
        ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
            if(!personasIguales(personaOriginal,personaAux))
                cambioDetectado=true;

            listaAux2=getResto(listaAux2);
            listaOriginal=getResto(listaOriginal);
        }
        listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
        listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.

        if(cambioDetectado)
        {
            int opGuardar=0;
            do
            {
                printf("Guardar cambios? 1=SI , 0=NO | ");
                scanf("%d",&opGuardar);
                limpiarBufferTeclado();
                system("cls");
                switch(opGuardar)
                {
                case 1:
                    if(guardarPersonas(centroLogistico))
                    {
                        cambiosGuardados=true;
                        printf("Cambios guardados exitosamente.\n\n");
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
                    printf("Opcion incorrecta.\n\n");
                    break;
                }
                if(opGuardar!=0)
                    presionarEnterYLimpiarPantalla();
            } while(opGuardar!=0);
        }
    }

    return cambiosGuardados;
}
bool menuModificarVehiculo(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    ListaPtr listaAux=getVehiculos(centroLogistico);

    bool cambioDetectado=false;
    bool cambiosGuardados=false;

    if(listaVacia(listaAux))
        printf("ERROR: Lista vacía. Debe agregar vehiculos para poder modificarlos.\n\n");
    else
    {
    ///Creamos una lista "original" para ver si hay cambios,
    ///y una "auxiliar" para obtener y recorrer la lista.
        ListaPtr listaOriginal=crearLista();

        ListaPtr listaAux2=crearLista();
        agregarLista(listaAux2,getVehiculos(centroLogistico));
    //Hacemos lo mismo pero para cada elemento de la lista
        VehiculoPtr vehiculoOriginal;

        VehiculoPtr vehiculoAux;
        while(!listaVacia(listaAux2))
        {
            vehiculoAux=getCabecera(listaAux2);
        ///Copiamos el contenido de cada elemento
            vehiculoOriginal=crearVehiculo(getTipoVehiculo(vehiculoAux),
                                           getMarca(vehiculoAux),
                                           getModelo(vehiculoAux),
                                           getPatente(vehiculoAux));
         ///Agregamos el dato original a la lista
            agregarDatoLista(listaOriginal,(VehiculoPtr)vehiculoOriginal);
            listaAux2=getResto(listaAux2);
        }
        listaAux2=destruirLista(listaAux2,false);

        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!modoAccion == 0 && modoAccion == -1)
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
                int *indices;
            //para el modo de accion 3,
                int desde=0,hasta=0;
            //para los modos de accion 2 y 3,
                VehiculoPtr *vehiculosAModificar;

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
                    indices=menuModoAccion2(listaAux,nIndices);

                    printf("Ha elegido Vehiculos");
                    for(int i=0;i<nIndices;i++)
                    { //Obtenemos los elementos en los indices seleccionados y los mostramos
                        vehiculosAModificar[i]=(VehiculoPtr)getDatoLista(listaAux,indices[i]);
                        printf("%d. ",indices[i]);
                        mostrarVehiculo(vehiculosAModificar[i]);
                    }
                }
                else
                {
                    printf("MODIFICAR VEHICULOS\n\n");
                    menuModoAccion3(listaAux,desde,hasta);

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


                printf("\n\nQué desea modificar?\n\n");

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
                            printf("\nERROR: esa opcion no existe.\n\n");
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
                    opMenuAnterior=-1;
                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    presionarEnterYLimpiarPantalla();
                    break;
                }

                printf("\n\nDatos modificados exitosamente.\n\n");

                continuar=menuContinuar();
            } while(!(op==0 && op==-1) && continuar);
        }

        listaAux2=crearLista();
        agregarLista(listaAux2,getVehiculos(centroLogistico));
    ///Recorremos la lista: antes y después de hacer el cambio
        while(!listaVacia(listaAux2))
        {
            vehiculoAux=getCabecera(listaAux2);
            vehiculoOriginal=getCabecera(listaOriginal);
        ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
            if(!vehiculosIguales(vehiculoOriginal,vehiculoAux))
                cambioDetectado=true;

            listaAux2=getResto(listaAux2);
            listaOriginal=getResto(listaOriginal);
        }
        listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
        listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.

        if(cambioDetectado)
        {
            int opGuardar=0;
            do
            {
                printf("Guardar cambios? 1=SI , 0=NO | ");
                scanf("%d",&opGuardar);
                limpiarBufferTeclado();
                system("cls");
                switch(opGuardar)
                {
                case 1:
                    if(guardarVehiculos(centroLogistico))
                    {
                        cambiosGuardados=true;
                        printf("Cambios guardados exitosamente.\n\n");
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
                    printf("Opcion incorrecta.\n\n");
                    break;
                }
                if(opGuardar!=0)
                    presionarEnterYLimpiarPantalla();
            } while(opGuardar!=0);
        }
    }

    return cambiosGuardados;
}

bool menuMostrarPaquetes(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    int op=0;

    bool cambioDetectado=false;
    bool cambiosGuardados=false;

///Creamos una lista "original" para ver si hay cambios,
///y una "auxiliar" para obtener y recorrer la lista.
    ListaPtr listaOriginal=crearLista();

    ListaPtr listaAux2=crearLista();
    agregarLista(listaAux2,getPaquetes(centroLogistico));

    if(listaVacia(listaAux2))
    {
        printf("ERROR: La lista que se desea mostrar está vacía.\n\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
    //Hacemos lo mismo pero para cada elemento de la lista
        PaquetePtr paqueteOriginal;

        PaquetePtr paqueteAux;
        while(!listaVacia(listaAux2))
        {
            paqueteAux=getCabecera(listaAux2);
        ///Copiamos el contenido de cada elemento
            paqueteOriginal=crearPaquete(getID(paqueteAux),
                                         getAncho(paqueteAux),
                                         getAlto(paqueteAux),
                                         getLargo(paqueteAux),
                                         getPeso(paqueteAux),
                                         getDirRetiro(paqueteAux),
                                         getDirEntrega(paqueteAux),
                                         getFechaEntrega(paqueteAux),
                                         getEstado(paqueteAux));
         ///Agregamos el dato original a la lista
            agregarDatoLista(listaOriginal,(PaquetePtr)paqueteOriginal);
            listaAux2=getResto(listaAux2);
        }
        listaAux2=destruirLista(listaAux2,false);

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
                opMenuAnterior=0;
                break;
            default:
                printf("\nOpcion incorrecta.\n\n");
                break;
            }
            if(!(op==0 && op==-1))
                mostrarPaquetes(centroLogistico);
            if(op>=1 && op<=3) //Si se ordenó la lista
            {
                listaAux2=crearLista();
                agregarLista(listaAux2,getPaquetes(centroLogistico));
            ///Recorremos la lista: antes y después de hacer el cambio
                while(!listaVacia(listaAux2))
                {
                    paqueteAux=getCabecera(listaAux2);
                    paqueteOriginal=getCabecera(listaOriginal);
                ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
                    if(!paquetesIguales(paqueteOriginal,paqueteAux))
                        cambioDetectado=true;

                    listaAux2=getResto(listaAux2);
                    listaOriginal=getResto(listaOriginal);
                }
                listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
                listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.
            }
            if(!(op==0 && op==-1))
            {
                printf("\n\n-----------------------------------------------------\n\n");
                mostrarPaquetes(centroLogistico);
                printf("\n\n-----------------------------------------------------\n\n");
                presionarEnterYLimpiarPantalla();
            }
        } while(!(op==0 && op==-1));

        if(cambioDetectado)
        {
            int opGuardar=0;
            do
            {
                printf("Guardar cambios? 1=SI , 0=NO | ");
                scanf("%d",&op);
                limpiarBufferTeclado();
                system("cls");
                switch(opGuardar)
                {
                case 1:
                    if(guardarPaquetes(centroLogistico))
                    {
                        cambiosGuardados=true;
                        printf("Cambios guardados exitosamente.\n\n");
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
                    printf("Opcion incorrecta.\n\n");
                    break;
                }
                if(op!=0)
                    presionarEnterYLimpiarPantalla();
            } while(opGuardar!=0);
        }
    }

    return cambiosGuardados;
}
bool menuMostrarPersonas(CentroLogisticoPtr centroLogistico,int tipo,int opMenuAnterior)
{
    int op=0;

    bool cambioDetectado=false;
    bool cambiosGuardados=false;

///Creamos una lista "original" para ver si hay cambios,
///y una "auxiliar" para obtener y recorrer la lista.
    ListaPtr listaOriginal=crearLista();

    ListaPtr listaAux2=crearLista();
    agregarLista(listaAux2,getPersonas(centroLogistico));
//Hacemos lo mismo pero para cada elemento de la lista
    PersonaPtr personaOriginal;

    PersonaPtr personaAux;
    while(!listaVacia(listaAux2))
    {
        personaAux=getCabecera(listaAux2);
    ///Copiamos el contenido de cada elemento
        personaOriginal=crearPersona(getNombre(personaAux),
                                     getApellido(personaAux),
                                     getDomicilio(personaAux),
                                     getCuilPersona(personaAux),
                                     getEsChofer(personaAux));
     ///Agregamos el dato original a la lista
        agregarDatoLista(listaOriginal,(PersonaPtr)personaOriginal);
        listaAux2=getResto(listaAux2);
    }
    listaAux2=destruirLista(listaAux2,false);

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
        }

        switch(op)
        {
        case 1:
            printf("(ORDENADO POR NOMBRE)");
            ordenarPersonas(centroLogistico,1);
            break;
        case 2:
            printf("(ORDENADO POR APELLIDO)");
            ordenarPersonas(centroLogistico,2);
            break;
        case 3:
            printf("(ORDENADO POR NOMBRE Y APELLIDO)");
            ordenarPersonas(centroLogistico,3);
            break;
        case 4:
            printf("(SIN ORDENAR)");
            break;
        case 0:
            break;
        case -1:
            opMenuAnterior=0;
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            break;
        }
        if(op>=1 && op<=3) //Si se ordenó la lista
        {
            listaAux2=crearLista();
            agregarLista(listaAux2,getPersonas(centroLogistico));
        ///Recorremos la lista: antes y después de hacer el cambio
            while(!listaVacia(listaAux2))
            {
                personaAux=getCabecera(listaAux2);
                personaOriginal=getCabecera(listaOriginal);
            ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
                if(!personasIguales(personaOriginal,personaAux))
                    cambioDetectado=true;

                listaAux2=getResto(listaAux2);
                listaOriginal=getResto(listaOriginal);
            }
            listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
            listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.
        }
        if(!(op==0 && op==-1))
        {
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
            printf("\n\n-----------------------------------------------------\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(!(op==0 && op==-1));

    if(cambioDetectado)
    {
        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&op);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1:
                if(guardarPersonas(centroLogistico))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
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
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(op!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }

    return cambiosGuardados;
}
bool menuMostrarVehiculos(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    int op=0;

    bool cambioDetectado=false;
    bool cambiosGuardados=false;

///Creamos una lista "original" para ver si hay cambios,
///y una "auxiliar" para obtener y recorrer la lista.
    ListaPtr listaOriginal=crearLista();

    ListaPtr listaAux2=crearLista();
    agregarLista(listaAux2,getVehiculos(centroLogistico));
//Hacemos lo mismo pero para cada elemento de la lista
    VehiculoPtr vehiculoOriginal;

    VehiculoPtr vehiculoAux;
    while(!listaVacia(listaAux2))
    {
        vehiculoAux=getCabecera(listaAux2);
    ///Copiamos el contenido de cada elemento
        vehiculoOriginal=crearVehiculo(getTipoVehiculo(vehiculoAux),
                                       getMarca(vehiculoAux),
                                       getModelo(vehiculoAux),
                                       getPatente(vehiculoAux));
     ///Agregamos el dato original a la lista
        agregarDatoLista(listaOriginal,(VehiculoPtr)vehiculoOriginal);
        listaAux2=getResto(listaAux2);
    }
    listaAux2=destruirLista(listaAux2,false);

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
            opMenuAnterior=0;
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            break;
        }
        if(op>=1 && op<=2) //Si se ordenó la lista
        {
            listaAux2=crearLista();
            agregarLista(listaAux2,getVehiculos(centroLogistico));
        ///Recorremos la lista: antes y después de hacer el cambio
            while(!listaVacia(listaAux2))
            {
                vehiculoAux=getCabecera(listaAux2);
                vehiculoOriginal=getCabecera(listaOriginal);
            ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
                if(!vehiculosIguales(vehiculoOriginal,vehiculoAux))
                    cambioDetectado=true;

                listaAux2=getResto(listaAux2);
                listaOriginal=getResto(listaOriginal);
            }
            listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
            listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.
        }
        if(!(op==0 && op==-1))
        {
            printf("\n\n-----------------------------------------------------\n\n");
            mostrarVehiculos(centroLogistico);
            printf("\n\n-----------------------------------------------------\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(!(op==0 && op==-1));

    if(cambioDetectado)
    {
        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&op);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1:
                if(guardarVehiculos(centroLogistico))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
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
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(op!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }

    return cambiosGuardados;
}

bool menuArmarReparto(CentroLogisticoPtr centroLogistico)
{
    RepartoPtr reparto;
    int n=0;
    int k=0;
    PersonaPtr choferElegido;
    VehiculoPtr vehiculoElegido;

    FechaPtr fechaSalida;
    FechaPtr fechaRetorno;

    PilaPtr pilaPaquetesElegidos=crearPila();
    int cantPaquetesElegidos=0;
    PaquetePtr paqueteElegido;

    bool cambiosGuardados=false;
    bool continuar=true;

    do
    {
        do
        {
            printf("ARMAR REPARTO\n\n");
            printf("Ingrese cantidad de repartos a armar: ");
            scanf("%d",&n);
            limpiarBufferTeclado();

            if(n<1)
                printf("\nCantidad incorrecta.\n");
            presionarEnterYLimpiarPantalla();
        } while(n<1);

        int longLista=0;
        int i=0;
        while(i<n && continuar)
        {
            if(n>1)
                printf("\n\nREPARTO %d\n\n",i+1);
            do
            { //Cargamos el chofer
                longLista = longitudLista(getPersonas(centroLogistico));

                mostrarPersonas(centroLogistico,1);
                printf("\n\nSeleccione un chofer ingresando su indice: ");
                scanf("%d",&k);
                limpiarBufferTeclado();

                choferElegido=(PersonaPtr)getDatoLista(getPersonas(centroLogistico),k-1);

                if(k>0 && k<longLista && !getEsChofer(choferElegido))
                    printf("\n\nERROR: el indice ingresado no corresponde a un chofer. Vuelva a elegir.\n\n");
                else if(k<=0 || k>=longLista)
                    printf("\n\nERROR: indice inexistente. Vuelva a elegir.\n\n");

                system("cls");
            } while(k<=0 || k>=longLista || !getEsChofer(choferElegido));

            presionarEnterYLimpiarPantalla();

            do
            {
                longLista = longitudLista(getVehiculos(centroLogistico));

                mostrarVehiculos(centroLogistico);
                printf("\n\nSeleccione un vehiculo ingresando su indice: ");
                scanf("%d",&k);
                limpiarBufferTeclado();

                if(k<=0 || k>=longLista)
                    printf("\n\nERROR: indice inexistente. Vuelva a elegir.\n\n");

                system("cls");
            } while(k<=0 || k>=longLista);

            vehiculoElegido=getDatoLista(getVehiculos(centroLogistico),k-1);
            presionarEnterYLimpiarPantalla();

            printf("\n\nFecha de salida:");
            cargarFecha(fechaSalida);
            printf("\n\nFecha de retorno:");
            cargarFecha(fechaRetorno);

            presionarEnterYLimpiarPantalla();

            do
            {
                printf("Ingrese cantidad de paquetes a agregar al reparto: ");
                scanf("%d",&cantPaquetesElegidos);
                if(n<1)
                {
                    printf("\n\nERROR: cantidad incorrecta. Vuelva a ingresar.\n\n");
                    presionarEnterYLimpiarPantalla();
                }
            } while(n<1);

            for(int j=0;j<cantPaquetesElegidos;j++)
            {
                do
                {
                    mostrarPaquetes(centroLogistico);
                    if(cantPaquetesElegidos>1)
                        printf("\n\nPaquete N. %d\n",j+1);

                    printf("Seleccione el paquete a cargar ingresando su indice: ");
                    scanf("%d",&k);
                    limpiarBufferTeclado();

                    if(k<=0 || k>=longLista)
                        printf("\n\nERROR: indice inexistente. Vuelva a elegir.\n\n");
                    system("cls");
                } while(k<=0 || k>=longLista);

                paqueteElegido=getDatoLista(getPaquetes(centroLogistico),k-1);
                apilar(pilaPaquetesElegidos,(PaquetePtr)paqueteElegido);
            }


            reparto=armarReparto(choferElegido,vehiculoElegido,fechaSalida,fechaRetorno,pilaPaquetesElegidos);
            agregarReparto(centroLogistico,reparto,true);

            printf("\n\nReparto armado exitosamente.\n\n");
            presionarEnterYLimpiarPantalla();
            i++;

            continuar=menuContinuar();
        }
        if(n>1)
            printf("Repartos cargados exitosamente.\n\n");

        continuar=menuContinuar();
    } while(continuar);

    int opGuardar=0;
    do
    {
        printf("Guardar cambios? 1=SI , 0=NO | ");
        scanf("%d",&opGuardar);
        limpiarBufferTeclado();
        system("cls");
        switch(opGuardar)
        {
        case 1:
            if(guardarRepartos(centroLogistico,true))
            {
                cambiosGuardados=true;
                printf("Cambios guardados exitosamente.\n\n");
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
            printf("Opcion incorrecta.\n\n");
            break;
        }
        if(opGuardar!=0)
            presionarEnterYLimpiarPantalla();
    } while(opGuardar!=0);

    return cambiosGuardados;
}
bool menuCerrarReparto(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    bool cambiosGuardados=false;
    bool continuar;

/// ////////////////////////////////////////////////////////////////////////////////// ///
    int modoAccion = menuModoAccion(opMenuAnterior);
    if(!(modoAccion==0 && modoAccion==-1))
    {
    //para el modo de accion 1,
        int indice;
        RepartoPtr repartoCerrar;
    //para el modo de accion 2,
        int nIndices;
        int *indices;
    //para el modo de accion 3,
        int desde=0,hasta=0;
    //para los modos de accion 2 y 3,
        RepartoPtr *repartosCerrar;
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

                    repartoCerrar=(RepartoPtr)getDatoLista(getRepartos(centroLogistico,false),indice);
                    existeEnCerrados = esRepartoExistente(centroLogistico,repartoCerrar,false);
                    if(existeEnCerrados)
                    {
                        printf("\n\nERROR: el reparto seleccionado ya existe en la lista de repartos cerrados.\n\n");
                        presionarEnterYLimpiarPantalla();
                    }
                }
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
                else if(modoAccion==2)
                {
                    printf("CERRAR REPARTOS\n");
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Repartos a cerrar:");
                    indices = menuModoAccion2(listaAux,nIndices);
                    int i=0;
                    while(i<nIndices && !existeEnCerrados)
                    {
                        repartosCerrar[i]=(RepartoPtr)getDatoLista(getRepartos(centroLogistico,false),indices[i]);
                        if(esRepartoExistente(centroLogistico,repartoCerrar,false))
                            existeEnCerrados=true;
                        i++;
                    }
                    if(existeEnCerrados)
                    {
                        printf("\n\nERROR: hay repartos seleccionados que ya existen en la lista de repartos cerrados.\n\n");
                        presionarEnterYLimpiarPantalla();
                    }
                }
                else
                {
                    printf("CERRAR REPARTOS\n");
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Repartos a cerrar:");
                    menuModoAccion3(listaAux,desde,hasta);
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
                        printf("\n\nERROR: hay repartos seleccionados que ya existen en la lista de repartos cerrados.\n\n");
                        presionarEnterYLimpiarPantalla();
                    }
                }
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
            }while(existeEnCerrados);

            if(modoAccion==1)
            {
                cerrarReparto(centroLogistico,indice);
                printf("\n\n-----------------------------------------\n\n");
                printf("Reparto cerrado exitosamente.\n\n");
            }
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
            else if(modoAccion==2)
            {
                for(int i=0,j=0;i<nIndices;i++,j++)
                    cerrarReparto(centroLogistico,indices[i]-j);
                printf("\n\n-----------------------------------------\n\n");
                printf("Repartos cerrados exitosamente.\n\n");
            }
            else
            {
                for(int i=desde;i<=hasta;i++)
                    cerrarReparto(centroLogistico,desde);
                printf("\n\n-----------------------------------------\n\n");
                printf("Repartos cerrados exitosamente.\n\n");
            }
            continuar=menuContinuar();
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
        } while(continuar);
    ///Como sí o sí vamos a hacer un cambio, no se necesita detectarlos en este menú.
        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&opGuardar);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1: //Sobreescribimos los cambios en las 2 listas de repartos
                if(guardarRepartos(centroLogistico,true) && guardarRepartos(centroLogistico,false))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
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
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(opGuardar!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }

    return cambiosGuardados;
}
bool menuEliminarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int opMenuAnterior)
{
    bool cambiosGuardados=false;
    bool continuar;

    ListaPtr listaAux = getRepartos(centroLogistico,esRepartoAbierto);

    if(listaVacia(listaAux))
        printf("ERROR: Lista vacía. Debe agregar repartos para poder eliminarlos.\n\n");
    else
    {
/// ////////////////////////////////////////////////////////////////////////////////// ///
        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion==0 && modoAccion==-1))
        {
        //para el modo de accion 1,
            int indice;
        //para el modo de accion 2,
            int nIndices;
            int *indices;
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
                destruirReparto(removerReparto(centroLogistico,indice,esRepartoAbierto));
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
                indices = menuModoAccion2(listaAux,nIndices);
            //Obtenemos y destruimos los elementos seleccionados
                /* Funcionamiento
                1 2 5 9 12
                elimino 1
                2 5 9 12 => 1 4 8 11
                elimino 1
                4 8 11 => 3 7 10
                elimino 3
                7 10 => 6 9
                elimino 6
                9 => 8
                elimino 8

                *************************

                llegamos al límite del vector, termino de iterar.
                */

                for(int i=0,j=0;i<nIndices;i++,j++)
                    destruirReparto(removerReparto(centroLogistico,indices[i]-j,esRepartoAbierto));
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
                menuModoAccion3(listaAux,desde,hasta);
            //Obtenemos y destruimos los elementos en el rango de indices
                for(int i=desde;i<=hasta;i++)
                    destruirReparto(removerReparto(centroLogistico,desde,esRepartoAbierto));
            }

            continuar=menuContinuar();
        } while(continuar);

        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&opGuardar);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1:
                if(guardarRepartos(centroLogistico,esRepartoAbierto))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
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
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(opGuardar!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }
    return cambiosGuardados;
}
bool menuModificarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int opMenuAnterior)
{
    ListaPtr listaAux=getRepartos(centroLogistico,esRepartoAbierto);

    bool cambioDetectado=false;
    bool cambiosGuardados=false;

    if(listaVacia(listaAux))
        printf("ERROR: Lista vacía. Debe agregar repartos para poder modificarlos.\n\n");
    else
    {
    ///Creamos una lista "original" para ver si hay cambios,
    ///y una "auxiliar" para obtener y recorrer la lista.
        ListaPtr listaOriginal=crearLista();

        ListaPtr listaAux2=crearLista();
        agregarLista(listaAux2,getRepartos(centroLogistico,esRepartoAbierto));
    //Hacemos lo mismo pero para cada elemento de la lista
        RepartoPtr repartoOriginal;

        RepartoPtr repartoAux;
        while(!listaVacia(listaAux2))
        {
            repartoAux=getCabecera(listaAux2);
        ///Copiamos el contenido de cada elemento
            repartoOriginal=armarReparto(getChofer(repartoAux),
                                         getVehiculo(repartoAux),
                                         getFechaSalida(repartoAux),
                                         getFechaRetorno(repartoAux),
                                         getPaquetesReparto(repartoAux));
         ///Agregamos el dato original a la lista
            agregarDatoLista(listaOriginal,(RepartoPtr)repartoOriginal);
            listaAux2=getResto(listaAux2);
        }
        listaAux2=destruirLista(listaAux2,false);

        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!modoAccion == 0 && modoAccion == -1)
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
                PaquetePtr *paquetesAModificar;
            //para el modo de accion 2,
                int nIndices=0;
                int *indices;
            //para el modo de accion 3,
                int desde=0,hasta=0;
            //para los modos de accion 2 y 3,
                RepartoPtr *repartosAModificar;
                PilaPtr *pilasAux;
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
                    indices=menuModoAccion2(listaAux,nIndices);
                //Obtenemos los elementos en los indices seleccionados
                    for(int i=0;i<nIndices;i++)
                        repartosAModificar[i]=(RepartoPtr)getDatoLista(listaAux,indices[i]);
                }
                else
                {
                    menuModoAccion3(listaAux,desde,hasta);
                //Obtenemos los elementos en el rango de indices
                    for(int i=desde;i<=hasta;i++)
                        repartosAModificar[i]=(RepartoPtr)getDatoLista(listaAux,i-1);
                }
/// ////////////////////////////////////////////////////////////////////////////////// ///
                FechaPtr fechaAModificar;
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
                printf("Qué desea modificar?\n\n");

                printf("1. Cambiar Chofer\n");
                printf("2. Cambiar Vehiculo\n");
                printf("3. Fecha de Salida\n");
                printf("4. Fecha de Retorno\n");
                printf("5. Paquetes Cargados\n");
                printf("0. Volver\n");
                printf("-1. MENU PRINCIPAL\n\n");
                printf("\n\n-----------------------------------------\n\n");
                printf("Ingrese una opcion: ");
                scanf("%d",&op2);
                limpiarBufferTeclado();

                system("cls");
                switch(op2)
                {
                case 1:
                    printf("CAMBIAR CHOFER\n");
                    printf("\n\n-----------------------------------------\n\n");
                    mostrarPersonas(centroLogistico,1);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Seleccione el indice del nuevo chofer: ");
                    break;
                case 2:
                    printf("CAMBIAR VEHICULO\n");
                    printf("\n\n-----------------------------------------\n\n");
                    mostrarVehiculos(centroLogistico);
                    printf("\n\n-----------------------------------------\n\n");
                    printf("Seleccione el indice del nuevo vehiculo: ");
                    break;
                case 3:
                    printf("MODIFICAR FECHA SALIDA\n");
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
                    printf("MODIFICAR FECHA RETORNO\n");
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
                            printf("MODIFICAR PAQUETES DEL REPARTO\n");
                            printf("\n\n-----------------------------------------\n\n");
                            for(int i=0;i<nPaquetes;i++)
                                mostrarPaquete(paquetesAModificar[i]);
                            printf("\n\n-----------------------------------------\n\n");
                            printf("\n\nIngrese indice del paquete a modificar: ");
                            scanf("%d",&indice);
                            limpiarBufferTeclado();
                            if(indice<0 || indice>nPaquetes)
                            {
                                printf("\n\nERROR: indice inexistente. Vuelva a elegir.\n\n");
                                presionarEnterYLimpiarPantalla();
                            }
                        } while(indice<0 || indice>nPaquetes);

                        printf("Ha elegido - ");
                        mostrarPaquete(paquetesAModificar[indice]);
                    }
                    else
                        printf("MODIFICAR PAQUETES DE LOS REPARTOS\n");
/// ////////////////////////////////////////////////////////////////////////////////// ///
                    do
                    {
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Qué desea modificar?\n\n");

                        printf("1. ESTADO - Marcar como Retirado\n");
                        printf("2. ESTADO - Marcar como Entregado\n");
                        printf("3. ESTADO - Marcar como Demorado\n");
                        printf("4. ESTADO - Marcar como Suspendido\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL\n\n");
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
                            printf("Opcion incorrecta.\n\n");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(!(op3==0 && op3==-1));
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
                    opMenuAnterior=0;
                    break;
                default:
                    printf("Opcion incorrecta.\n\n");
                    presionarEnterYLimpiarPantalla();
                    break;
                }
                continuar=menuContinuar();
            }while(!(op2==0 && op2==-1) && continuar);
        }


        listaAux2=crearLista();
        agregarLista(listaAux2,getRepartos(centroLogistico,esRepartoAbierto));
    ///Recorremos la lista: antes y después de hacer el cambio
        while(!listaVacia(listaAux2))
        {
            repartoAux=getCabecera(listaAux2);
            repartoOriginal=getCabecera(listaOriginal);
        ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
            if(!repartosIguales(repartoOriginal,repartoAux))
                cambioDetectado=true;

            listaAux2=getResto(listaAux2);
            listaOriginal=getResto(listaOriginal);
        }
        listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
        listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.

        if(cambioDetectado)
        {
            int opGuardar=0;
            do
            {
                printf("Guardar cambios? 1=SI , 0=NO | ");
                scanf("%d",&opGuardar);
                limpiarBufferTeclado();
                system("cls");
                switch(opGuardar)
                {
                case 1:
                    if(guardarRepartos(centroLogistico,esRepartoAbierto))
                    {
                        cambiosGuardados=true;
                        printf("Cambios guardados exitosamente.\n\n");
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
                    printf("Opcion incorrecta.\n\n");
                    break;
                }
                if(opGuardar!=0)
                    presionarEnterYLimpiarPantalla();
            } while(opGuardar!=0);
        }
    }

    return cambiosGuardados;
}
void menuBuscarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    int i=0;
    int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));
    RepartoPtr repartoBuscar;
    bool continuar;

    if(listaVacia(getRepartos(centroLogistico,esRepartoAbierto)))
        printf("ERROR: Lista vacia. No hay repartos para buscar\n");
    else
    {
        do
        {
            presionarEnterYLimpiarPantalla();
            printf("Seleccione un reparto para buscar mediante su indice: ");
            scanf("%d",&i);
            if(i>=0 && i<n)
            {
                repartoBuscar=getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),i-1);
                mostrarReparto(repartoBuscar);
            }else
                printf("Reparto inexistente\n");

            continuar=menuContinuar();
        } while(continuar);
    }
}
bool menuMostrarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int opMenuAnterior)
{
	int op2=0;
	int op3=0;

    bool cambioDetectado=false;
    bool cambiosGuardados=false;

///Creamos una lista "original" para ver si hay cambios,
///y una "auxiliar" para obtener y recorrer la lista.
    ListaPtr listaOriginal=crearLista();

    ListaPtr listaAux2=crearLista();
    agregarLista(listaAux2,getRepartos(centroLogistico,esRepartoAbierto));
//Hacemos lo mismo pero para cada elemento de la lista
    RepartoPtr repartoOriginal;

    RepartoPtr repartoAux;
    while(!listaVacia(listaAux2))
    {
        repartoAux=getCabecera(listaAux2);
    ///Copiamos el contenido de cada elemento
        repartoOriginal=armarReparto(getChofer(repartoAux),
                                     getVehiculo(repartoAux),
                                     getFechaSalida(repartoAux),
                                     getFechaRetorno(repartoAux),
                                     getPaquetesReparto(repartoAux));
     ///Agregamos el dato original a la lista
        agregarDatoLista(listaOriginal,(RepartoPtr)repartoOriginal);
        listaAux2=getResto(listaAux2);
    }
    listaAux2=destruirLista(listaAux2,false);

	int i=0;
	int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));

    FechaPtr fechaSalida;

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
                if(i<=0 || i>=n)
                    printf("\n\nIndice inexistente. Vuelva a ingresarlo.\n\n");
                presionarEnterYLimpiarPantalla();
            } while(i>0 && i<n);

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
                    filtrarPorFechaSalida(centroLogistico,esRepartoAbierto,fechaSalida);
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
                    break;
                }
                if(!(op3==0 && op3==-1))
                    presionarEnterYLimpiarPantalla();
            } while(!(op3==0 && op3==-1));
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
                    printf("Opcion incorrecta.\n\n");
                    break;
                }
                if(op3>=1 && op3<=6) //si se eligio volver o una opcion invalida,
                    mostrarRepartos(centroLogistico,esRepartoAbierto); //no mostramos nada.
                presionarEnterYLimpiarPantalla();
                system("cls");
            } while(!(op3==0 && op3==-1));
            break;
        case 0:
            break;
        case -1:
            opMenuAnterior=0;
        default:
            printf("Opcion incorrecta\n\n");
            break;
        }
    } while(!(op2==0 && op2==-1));

    listaAux2=crearLista();
    agregarLista(listaAux2,getRepartos(centroLogistico,esRepartoAbierto));
///Recorremos la lista: antes y después de hacer el cambio
    while(!listaVacia(listaAux2))
    {
        repartoAux=getCabecera(listaAux2);
        repartoOriginal=getCabecera(listaOriginal);
    ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
        if(!repartosIguales(repartoOriginal,repartoAux))
            cambioDetectado=true;

        listaAux2=getResto(listaAux2);
        listaOriginal=getResto(listaOriginal);
    }
    listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
    listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.

    if(cambioDetectado)
    {
        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&opGuardar);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1:
                if(guardarRepartos(centroLogistico,esRepartoAbierto))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
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
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(opGuardar!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }

    return cambiosGuardados;
}


CentroLogisticoPtr menuCrearNuevoCtroLogRapido(CentroLogisticoPtr ctroLog)
{
    char nuevoNombre[100];

    printf("INGRESE EL NOMBRE DEL CENTRO LOGISTICO: ");
    scanf("%[^\n]%*c",nuevoNombre);
    limpiarBufferTeclado();

    ctroLog=crearCentroLogisticoRapido(nuevoNombre);

    return ctroLog;
}

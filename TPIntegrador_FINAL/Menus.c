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
        printf("\n-------------------------------------------------------------\n");
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
        limpiarBufferTeclado();
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
    } while(hasta<desde || hasta>n);
//El sistema permite que desde y hasta sean iguales si la lista tiene solo 1 elemento.
}

void* menuModoAccion1Nuevo(ListaPtr lista)
{
    int n=longitudLista(lista);
    int i;
    do
    {
        limpiarBufferTeclado();
        printf("\n\nIngrese indice donde tomar accion: ");
        scanf("%d",&i);
        limpiarBufferTeclado();
        if(i<=0 || i>n)
        {
            printf("\n\nERROR: indice inexistente. Vuelva a elegir.\n\n");
            presionarEnterYLimpiarPantalla();
        }
        else
            system("cls");
    } while(i<=0 || i>n);

    printf("REMOVIDO EXITOSAMENTE!!! \n\n");
    return removerDeLista(lista, i-1);
}

int calcularCantidad()
{
    int cantIndices=0;
    //Ingresamos la cantidad de indices a seleccionar
    do
    {
        limpiarBufferTeclado();
        printf("Ingrese cantidad de indices a seleccionar: ");
        scanf("%d",&cantIndices);
        limpiarBufferTeclado();
        if(cantIndices<=0)
        {
            printf("\n\nCantidad incorrecta.\n\n");
        }
    } while(cantIndices<=0);
    return cantIndices;
}

void menuModoAccion2Nuevo(ListaPtr lista,int cantIndices,int* vec)
{
    int n=longitudLista(lista);
    int *indices[cantIndices];
//Elegimos los indices
    for(int i=0;i<cantIndices;i++)
    {
        do
        {
            printf("\n\nIngrese indice %d: ",i+1);
            scanf("%d",&indices[i]);
            limpiarBufferTeclado();
            if(indices[i]<1 && indices[i]>n)
            {
                printf("\n\nIndice inexistente. Vuelva a ingresar.\n\n");
                presionarEnterYLimpiarPantalla();
            }
        } while(indices[i]<1 && indices[i]>n);
    }
    system("cls");
///NUEVO: ordenamos los índices de menor a mayor, lo que simplificará varias funciones
    int salto=n/2;
    int temp=0;
    /*while(salto>0)
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
    }*/
    for(int i=0;i<cantIndices-1;i++)
    {
        for(int j=i;j<cantIndices;j++)
        {
            if(indices[j]>indices[j+1])
            {
                int aux=0;
                aux=indices[j];
                indices[j]=indices[j+1];
                indices[j+1]=aux;
            }
        }
    }
    for(int i=0;i<cantIndices;i++)
    {
        vec[i] = indices[i];
    }

    /*for(int i=0;i<cantIndices;i++)
    {
        dato=removerDeLista(lista,indices[i]-i);
    }*/
}

void menuModoAccion3Nuevo(ListaPtr lista,int desde,int hasta,int* vec)
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
    } while(hasta<desde || hasta>n);
    vec[0]=desde;
    vec[1]=hasta;
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
        if(i>=1)
            system("cls");
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

    limpiarBufferTeclado();
    printf("\n\t\tCalle: ");
    scanf("%[^\n]%*c",calle);
    limpiarBufferTeclado();
    printf("\n\t\tAltura: ");
    scanf("%d",&altura);
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
        limpiarBufferTeclado();
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
}

void menuBuscarPaquete(CentroLogisticoPtr centroLogistico)
{
    int op=0;
    do
    {
        int ID=0;
        printf("BUSCAR PAQUETE\n\n");

        printf("Ingrese ID del paquete a buscar: ");
        scanf("%d",&ID);
        limpiarBufferTeclado();
        printf("\n\n");

        if(buscarPaquete(centroLogistico,ID)==false)
            printf("\n\nNo se pudo encontrar el paquete con ID #%d.\n\n",ID);

        printf("Volver? 0=Si, 1=No");
        scanf("%d",&op);
        limpiarBufferTeclado();
    } while(op!=0);
}
void menuBuscarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    int op=0;
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

        if(buscarPersona(centroLogistico,cuilABuscar,esChofer)==false)
        {
            if(esChofer)
                printf("\n\nNo se pudo encontrar el chofer con CUIL %s.\n\n",getCuil(cuilABuscar));
            else
                printf("\n\nNo se pudo encontrar el cliente con CUIL %s.\n\n",getCuil(cuilABuscar));
        }
        printf("Volver? 0=Si, 1=No");
        scanf("%d",&op);
        limpiarBufferTeclado();
    } while(op!=0);
}
void menuBuscarVehiculo(CentroLogisticoPtr centroLogistico)
{
    int op=0;
    do
    {
        char patente[100];
        printf("BUSCAR VEHICULO\n\n");

        printf("Ingrese la patente del vehiculo a buscar (AA 111 AA): ");
        scanf("%[^\n]%*c",patente);

        if(buscarVehiculo(centroLogistico,patente)==false)
            printf("\n\nNo se pudo encontrar el vehiculo con patente %s.\n\n",patente);
    } while(op!=0);
}

bool menuEliminarPaquete(CentroLogisticoPtr centroLogistico)
{
    int cantIndices=0;
    ListaPtr paquetesLista = getPaquetes(centroLogistico);
    PaquetePtr paqueteRemovido;
    printf("ELIMINAR PAQUETE\n\n");
    /*mostrarPaquetes(centroLogistico);
    paqueteRemovido = (PaquetePtr)menuModoAccion1Nuevo(getPaquetes(centroLogistico));
    paqueteRemovido=destruirPaquete(paqueteRemovido);*/
    mostrarPaquetes(centroLogistico);
    cantIndices=calcularCantidad();
    int vec[cantIndices];
    menuModoAccion2Nuevo(paquetesLista,cantIndices,vec);
    for(int i=0;i<cantIndices;i++)
    {

    }
}
bool menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    int iElim=0;
    if(esChofer)
    {
        printf("ELIMINAR CHOFER\n\n");

        mostrarPersonas(centroLogistico,1);

        printf("\n\nSeleccione indice del chofer a eliminar: ");
        scanf("%d",&iElim);
    }
    else
    {
        printf("ELIMINAR CLIENTE\n\n");

        mostrarPersonas(centroLogistico,2);

        printf("\n\nSeleccione indice del cliente a eliminar: ");
        scanf("%d",&iElim);
    }

    PersonaPtr personaRemovida=removerPersona(centroLogistico,iElim);
    if(personaRemovida!=NULL)
        printf("\n\nCliente %d eliminado exitosamente.\n\n",iElim);
    else
        printf("\n\nEl cliente %d no se pudo eliminar.\n\n",iElim);

    personaRemovida=destruirPersona(personaRemovida);
}
bool menuEliminarVehiculo(CentroLogisticoPtr centroLogistico)
{
    int iElim=0;
    printf("ELIMINAR VEHICULO\n\n");

    mostrarVehiculos(centroLogistico);

    printf("\n\nSeleccione indice del vehiculo a eliminar: ");
    scanf("%d",&iElim);

    VehiculoPtr vehiculoRemovido=removerVehiculo(centroLogistico,iElim);
    if(vehiculoRemovido!=NULL)
        printf("\n\nVehiculo %d eliminado exitosamente.\n\n",iElim);
    else
        printf("\n\nEl vehiculo %d no se pudo eliminar.\n\n",iElim);

    vehiculoRemovido=destruirVehiculo(vehiculoRemovido);
}

bool menuModificarPaquete(CentroLogisticoPtr centroLogistico)
{
    int iMod=0;
    int op=0;
    int seguirMod=0; //para no volver a entrar al menu si queremos cambiar varios parámetros de un dato.

    int nAncho=0;
    int nAlto=0;
    int nLargo=0;
    int nPeso=0;

    DomicilioPtr nuevaDirRetiro;
    DomicilioPtr nuevaDirEntrega;
    FechaPtr nuevaFechaEntrega;

    int nEstado=0;
    printf("MODIFICAR PAQUETE\n\n");

    mostrarPaquetes(centroLogistico);

    printf("\n\nIngrese indice del paquete a modificar: ");
    scanf("%d",&iMod);

    PaquetePtr paqueteAModificar=(PaquetePtr)getDatoLista(getPaquetes(centroLogistico),iMod-1); //-1 porque muestra con i+1 dentro de la funcion.

    do
    {
        system("cls");
        printf("Ha elegido el ");
        mostrarPaquete(paqueteAModificar);

        printf("\n\nQué desea modificar?\n\n");

        printf("1. Ancho\n");
        printf("2. Alto\n");
        printf("3. Largo\n");
        printf("4. Peso\n");
        printf("5. Direccion de Retiro\n");
        printf("6. Direccion de Entrega\n");
        printf("7. Fecha de Entrega\n");
        printf("8. Estado\n");

        printf("Seleccione una opcion: ");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            printf("\n\nIngrese el nuevo ancho: ");
            scanf("%d",&nAncho);

            setAncho(paqueteAModificar,nAncho);
            break;
        case 2:
            printf("\n\nIngrese el nuevo alto: ");
            scanf("%d",&nAlto);

            setAlto(paqueteAModificar,nAlto);
            break;
        case 3:
            printf("\n\nIngrese el nuevo largo: ");
            scanf("%d",&nLargo);

            setLargo(paqueteAModificar,nLargo);
            break;
        case 4:
            printf("\n\nIngrese el nuevo peso: ");
            scanf("%d",&nPeso);

            setPeso(paqueteAModificar,nPeso);
            break;
        case 5:
            printf("\n\nIngrese la nueva direccion de retiro:");
            actualizarDomicilio(nuevaDirRetiro);
            setDirRetiro(paqueteAModificar,nuevaDirRetiro);
            break;
        case 6:
            printf("\n\nIngrese la nueva direccion de entrega:");
            actualizarDomicilio(nuevaDirEntrega);
            setDirEntrega(paqueteAModificar,nuevaDirEntrega);
            break;
        case 7:
            printf("\n\nIngrese la nueva fecha y horario de entrega: ");
            actualizarFecha(nuevaFechaEntrega);
            setFechaEntrega(paqueteAModificar,nuevaFechaEntrega);
            break;
        case 8:
            helpEstadoPaquete();

            printf("\n\nIngrese el nuevo estado: ");
            scanf("%d",&nEstado);

            setEstado(paqueteAModificar,nEstado);
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }

        printf("\n\nDatos modificados exitosamente.\n\n");

        printf("Desea seguir modificando este paquete?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");

        printf("Seleccione una opcion: ");
        scanf("%d",&seguirMod);
    } while(seguirMod!=0);
}
bool menuModificarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    int iMod=0;
    int op=0;
    int seguirMod=0;

    char nNombre[100];
    char nApellido[100];

    DomicilioPtr nuevoDomicilio;
    CuilPtr nuevoCuil;

//esChofer se puede modificar sin crear una variable

    if(esChofer)
    {
        printf("MODIFICAR CHOFER\n\n");
        mostrarPersonas(centroLogistico,1);
        printf("\n\nIngrese indice del chofer a modificar: ");
    }
    else
    {
        printf("MODIFICAR CLIENTE\n\n");
        mostrarPersonas(centroLogistico,2);
        printf("\n\nIngrese indice del cliente a modificar: ");
    }

    scanf("%d",&iMod);
//Obtenemos la persona del índice de la lista de personas que se eligió (-1 porque la funcion siempre obtiene el siguiente al pedido. CORROBORAR)
    PersonaPtr personaAModificar=(PersonaPtr)getDatoLista(getPersonas(centroLogistico),iMod-1);

    do
    {
        system("cls");
        printf("Ha elegido - ");
        mostrarPersona(personaAModificar);

        printf("\n\nQué desea modificar?\n\n");

        printf("1. Nombre y Apellido\n");
        printf("2. Domicilio\n");
        printf("3. CUIL\n");

        if(esChofer)
            printf("4. Cambiar persona a: CLIENTE\n");
        else
            printf("4. Cambiar persona a: CHOFER\n");

        printf("Seleccione una opcion: ");
        scanf("%d",&op);


        switch(op)
        {
        case 1:
            printf("\n\nIngrese el nuevo nombre y apellido de esta manera:");
            printf("\n\t[Nombre];[Apellido]\n\t");
            scanf("%[^;]%*c;%[^\n]%*c",nNombre,nApellido);

            setNombre(personaAModificar,nNombre);
            setApellido(personaAModificar,nApellido);
            break;
        case 2:
            printf("\n\nIngrese el nuevo domicilio:");
            actualizarDomicilio(nuevoDomicilio);
            setDomicilio(personaAModificar,nuevoDomicilio);
            break;
        case 3:
            actualizarCuil(nuevoCuil);
            setCuilPersona(personaAModificar,nuevoCuil);
            break;
        case 4:
            if(esChofer)
                setEsChofer(personaAModificar,false);
            else
                setEsChofer(personaAModificar,true);
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }

        printf("\n\nDatos modificados exitosamente.\n\n");

        printf("Desea seguir modificando esta persona?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");

        printf("Seleccione una opcion: ");
        scanf("%d",&seguirMod);
    } while(seguirMod!=0);
}
bool menuModificarVehiculo(CentroLogisticoPtr centroLogistico, int opMenuAnterior)
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
            vehiculoOriginal=armarVehiculo(getTipo(vehiculoAux),
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
            if(modoAccion==1)
            {

            }
            else if(modoAccion==2)
            {

            }
            else
            {

            }
        }
    }
    int iMod=0;
    int op=0;
    int seguirMod=0;

    int nTipo=0;
    char nMarca[100];
    char nModelo[100];
    char nPatente[100];

    printf("MODIFICAR VEHICULO\n\n");

    mostrarVehiculos(centroLogistico);

    printf("\n\nIngrese indice del vehiculo a modificar: ");
    scanf("%d",&iMod);

    VehiculoPtr vehiculoAModificar=(VehiculoPtr)getDatoLista(getVehiculos(centroLogistico),iMod-1);

    do
    {
        system("cls");
        printf("Ha elegido - ");
        mostrarVehiculo(vehiculoAModificar);

        printf("\n\nQué desea modificar?\n\n");

        printf("1. Tipo de vehiculo\n");
        printf("2. Marca\n");
        printf("3. Modelo\n");
        printf("4. Patente\n");

        printf("Seleccione una opcion: ");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            printf("\n\n");
            helpTipoVehiculo();

            printf("\n\nSeleccione una opcion: ");
            scanf("%d",&nTipo);

            switch(nTipo)
            {
            case 1:
                setTipoVehiculo(vehiculoAModificar,1);
                break;
            case 2:
                setTipoVehiculo(vehiculoAModificar,2);
                break;
            case 3:
                setTipoVehiculo(vehiculoAModificar,3);
                break;
            default:
                printf("\nERROR: esa opcion no existe.\n\n");
                presionarEnterYLimpiarPantalla();
                break;
            }
            break;
        case 2:
            printf("\n\nIngrese la nueva marca:");
            scanf("%[^\n]%*c",nMarca);

            setMarca(vehiculoAModificar,nMarca);
            break;
        case 3:
            printf("\n\nIngrese el nuevo modelo:");
            scanf("%[^\n]%*c",nModelo);

            setModelo(vehiculoAModificar,nModelo);
            break;
        case 5:
            printf("\n\nIngrese la nueva patente (AA 111 AA):\n\t");
            scanf("%[^\n]%*c",nPatente);
            setPatente(vehiculoAModificar,nPatente);
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }

        printf("\n\nDatos modificados exitosamente.\n\n");

        printf("Desea seguir modificando este vehiculo?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");

        printf("Seleccione una opcion: ");
        scanf("%d",&seguirMod);
    } while(seguirMod!=0);
}

/** ///////////////////////////////////////////////////////////////////////////////////////////// ///

    FEATURES "GUARDAR CAMBIOS", "MENU MODO ACCION" Y "MENU CONTINUAR" AGREGADAS DE ACÁ PARA ABAJO

/// ///////////////////////////////////////////////////////////////////////////////////////////// /*/
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
        printf("EMITIR LISTADO DE PAQUETES\n");
        printf("\n-----------------------------------------\n\n");
        printf("1. Ordenados por ID\n");
        printf("2. Ordenados por Fecha de Entrega\n");
        printf("3. Ordenados por Estado\n");
        printf("4. SIN ORDENAR\n");
        printf("0. Volver\n");
        printf("-1. MENU PRINCIPAL");
        printf("\n-----------------------------------------\n\n");
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
                if(paquetesIguales(paqueteOriginal,paqueteAux))
                    cambioDetectado=true;

                listaAux2=getResto(listaAux2);
                listaOriginal=getResto(listaOriginal);
            }
            listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
            listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.
        }
        if(op!=0 && op!=-1)
        {
            printf("\n-----------------------------------------------------\n\n");
            mostrarPaquetes(centroLogistico);
            printf("\n-----------------------------------------------------\n\n");
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
        printf("\n-----------------------------------------\n\n");
        printf("1. Ordenados por Nombre\n");
        printf("2. Ordenados por Apellido\n");
        printf("3. Ordenados por Nombre y Apellido\n");
        printf("4. SIN ORDENAR\n");
        printf("0. Volver\n");
        printf("-1. MENU PRINCIPAL");
        printf("\n-----------------------------------------\n\n");
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
                if(personasIguales(personaOriginal,personaAux))
                    cambioDetectado=true;

                listaAux2=getResto(listaAux2);
                listaOriginal=getResto(listaOriginal);
            }
            listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
            listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.
        }
        if(!(op==0 && op==-1))
        {
            printf("\n-----------------------------------------------------\n\n");
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
            printf("\n-----------------------------------------------------\n\n");
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
        printf("\n-----------------------------------------\n\n");
        printf("1. Ordenados por Marca\n");
        printf("2. Ordenados por Marca y Modelo\n");
        printf("3. SIN ORDENAR\n");
        printf("0. Volver\n");
        printf("-1. MENU PRINCIPAL");
        printf("\n-----------------------------------------\n\n");
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
                if(vehiculosIguales(vehiculoOriginal,vehiculoAux))
                    cambioDetectado=true;

                listaAux2=getResto(listaAux2);
                listaOriginal=getResto(listaOriginal);
            }
            listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
            listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.
        }
        if(!(op==0 && op==-1))
        {
            printf("\n-----------------------------------------------------\n\n");
            mostrarVehiculos(centroLogistico);
            printf("\n-----------------------------------------------------\n\n");
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
                    printf("\n-----------------------------------------\n\n");
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
                    printf("\n-----------------------------------------\n\n");
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
                    printf("\n-----------------------------------------\n\n");
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
            int i=0;
            if(modoAccion==1)
            {
                cerrarReparto(centroLogistico,i);
                printf("\n-----------------------------------------\n\n");
                printf("Reparto cerrado exitosamente.\n\n");
            }
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
            else if(modoAccion==2)
            {
                for(int i=0;i<nIndices;i++)
                    cerrarReparto(centroLogistico,indices[i]-i);
                printf("\n-----------------------------------------\n\n");
                printf("Repartos cerrados exitosamente.\n\n");
            }
            else
            {
                for(int i=desde;i<=hasta;i++)
                    cerrarReparto(centroLogistico,desde);
                printf("\n-----------------------------------------\n\n");
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

    int i=0;
    ListaPtr listaAux = getRepartos(centroLogistico,esRepartoAbierto);

    if(listaVacia(listaAux))
        printf("ERROR: Lista vacía. Debe agregar repartos para poder eliminarlos.\n\n");
    else
    {
        do
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
                    printf("\n-----------------------------------------\n\n");
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
                    {
                        printf("ELIMINAR REPARTOS CERRADOS\n");
                        mostrarRepartos(centroLogistico,esRepartoAbierto);
                        printf("\n-----------------------------------------\n\n");
                        printf("Repartos a remover: ");
                        indices = menuModoAccion2(listaAux,nIndices);
                    }
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

                    for(int i=0;i<nIndices;i++)
                    {
                        destruirReparto(removerReparto(centroLogistico,indices[i]-i,esRepartoAbierto));
                    }
                }
                else
                {
                    if(esRepartoAbierto)
                        printf("ELIMINAR REPARTOS ABIERTOS\n");
                    else
                    {
                        printf("ELIMINAR REPARTOS CERRADOS\n");
                        mostrarRepartos(centroLogistico,esRepartoAbierto);
                        printf("\n-----------------------------------------\n\n");
                        printf("Repartos a remover: ");
                        menuModoAccion3(listaAux,desde,hasta);
                    }
                //Obtenemos y destruimos los elementos en el rango de indices
                    for(int i=desde;i<=hasta;i++)
                        destruirReparto(removerReparto(centroLogistico,desde,esRepartoAbierto));
                }

                continuar=menuContinuar();
            }
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
                printf("\n-----------------------------------------\n\n");
                mostrarRepartos(centroLogistico,esRepartoAbierto);
                printf("\n-----------------------------------------\n\n");
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
                    for(int i=0;i<=(hasta-desde);i++)
                    {
                        int j=desde;
                        printf("%d. ",j);
                        mostrarRepartoSinPaquetes(repartosAModificar[i]);
                        j++;
                    }
                }
/// ////////////////////////////////////////////////////////////////////////////////// ///
                printf("\n-----------------------------------------\n\n");
                printf("Qué desea modificar?\n\n");

                printf("1. Cambiar Chofer\n");
                printf("2. Cambiar Vehiculo\n");
                printf("3. Fecha de Salida\n");
                printf("4. Fecha de Retorno\n");
                printf("5. Paquetes Cargados\n");
                printf("0. Volver\n");
                printf("-1. MENU PRINCIPAL\n\n");
                printf("\n-----------------------------------------\n\n");
                printf("Ingrese una opcion: ");
                scanf("%d",&op2);
                limpiarBufferTeclado();

                system("cls");
                switch(op2)
                {
                case 1:
                    printf("CAMBIAR CHOFER\n");
                    printf("\n-----------------------------------------\n\n");
                    mostrarPersonas(centroLogistico,1);
                    printf("\n-----------------------------------------\n\n");
                    printf("Seleccione el indice del nuevo chofer: ");
                    break;
                case 2:
                    printf("CAMBIAR VEHICULO\n");
                    printf("\n-----------------------------------------\n\n");
                    mostrarVehiculos(centroLogistico);
                    printf("\n-----------------------------------------\n\n");
                    printf("Seleccione el indice del nuevo vehiculo: ");
                    break;
                case 3:
                    printf("MODIFICAR FECHA SALIDA\n");
                    printf("\n-----------------------------------------\n\n");
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
                    printf("\n-----------------------------------------\n\n");
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
                            printf("\n-----------------------------------------\n\n");
                            for(int i=0;i<nPaquetes;i++)
                                mostrarPaquete(paquetesAModificar[i]);
                            printf("\n-----------------------------------------\n\n");
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
                        printf("\n-----------------------------------------\n\n");
                        printf("Qué desea modificar?\n\n");

                        printf("1. ESTADO - Marcar como Retirado\n");
                        printf("2. ESTADO - Marcar como Entregado\n");
                        printf("3. ESTADO - Marcar como Demorado\n");
                        printf("4. ESTADO - Marcar como Suspendido\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL\n\n");
                        printf("\n-----------------------------------------\n\n");
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
    if(n!=0)
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
        printf("\n-----------------------------------------\n\n");
        printf("1. Mostrar un reparto\n");
        printf("2. Mostrar lista de repartos\n");
        printf("3. Ordenar lista y mostrar...\n");
        printf("0. Volver\n");
        printf("-1. MENU PRINCIPAL");
        printf("\n-----------------------------------------\n\n");
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
                printf("\n-----------------------------------------\n\n");
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
                printf("\n-----------------------------------------\n\n");
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

    ctroLog=crearCentroLogisticoRapido(nuevoNombre);

    return ctroLog;
}

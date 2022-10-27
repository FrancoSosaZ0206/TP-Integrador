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
#include "TDARepartos.h"

///--------------------------------------------------------------------------------------------------------------------------
                                            ///FUNCIONES DE MENUES AYUDANTES///
///--------------------------------------------------------------------------------------------------------------------------

int menuGuardarCambios()
{
    int opGuardar=0;
    do
    {
        printf("\n\n\t Guardar cambios? \n\n");
        printf("\t     [ 0 = NO ] \n");
        printf("\t     [ 1 = SI ] \n");
        printf("\n\t   Opcion: ");
        opGuardar = seleccionarNumero();
        if(opGuardar != 0 && opGuardar != 1)
        {
            printf("\n\t [Usted ha ingresado una opcion invalida] \n");
            printf("\n\t [Reingrese una opcion valida] \n");
        }
    }while(opGuardar != 0 && opGuardar != 1);
    return opGuardar;
}

bool menuContinuar()
{
    int eleccion;
    do
    {
        printf("\n\n\t Desea seguir en este menu? \n\n");
        printf("\t     [ 0. NO ] \n");
        printf("\t     [ 1. SI ] \n");
        printf("\n\t   Opcion: ");
        eleccion = seleccionarNumero();
        if(eleccion != 0 && eleccion != 1)
        {
            printf("\n\t [Usted ha ingresado una opcion invalida] \n");
            printf("\n\t [Reingrese una opcion valida] \n");
        }
    } while(eleccion < 0 || eleccion > 1);
    if(eleccion == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int menuModoAccion()
{
    system("cls");
    int eleccion = 0;
    printf("Accion:\n");
    printf("1. Sobre un indice unico [Ej: Posicion 1]\n");
    printf("2. Sobre conjunto de indices [Ej: Posiciones 1,18,4,25,7,6] (*)\n");
    printf("3. Sobre rango de indices [Ej: Posiciones 1 - 4 (1,2,3,4)]\n");
    printf("0. Volver\n");
    printf("\n-------------------------------------------------------------\n");
    printf("Opcion: ");
    eleccion = seleccionarNumero();
    system("cls");
    return eleccion;
}

int menuModoAccion1(ListaPtr lista)
{
    int eleccion = 0;
    int tamanioLista = longitudLista(lista);
    do
    {
        printf("\n\nIngrese indice donde tomar accion: ");
        eleccion = seleccionarNumero();
        if(eleccion < 1 || eleccion > tamanioLista)
        {
            printf("\t(Indice inexistente)\n");
        }
    } while(eleccion < 1 || eleccion > tamanioLista);
    eleccion--;
    return eleccion;
}

void menuModoAccion2(ListaPtr lista, int cantIndices,int* indices)
{
    //Elegimos los indices
    for(int i = 0;i < cantIndices+1;i++)
    {
        printf("\n Elemento %d", i+1);
        indices[i] = menuModoAccion1(lista);
    }
    int Salto = round(cantIndices / 2);
    bool cambios = true;
    while(Salto > 0)
    {
        cambios = false;
        for(int i=0; i< (cantIndices - Salto); i++)
        {
            if(indices[i] > indices[i+1])
            {
                int aux = indices[i];
                indices[i] = indices[i+1];
                indices[i+1] = aux;
                cambios = true;
            }
        }
        if(!cambios)
        {
            Salto = round(Salto / 2);
        }
    }
}

void menuModoAccion3(ListaPtr lista,int* vec)
{
    printf("\n\n Indice minimo: \n\n");
    vec[0] = menuModoAccion1(lista);
    printf("\n\n Indice maximo: \n\n");
    vec[1] = menuModoAccion1(lista);
    if(vec[0] > vec[1])
    {
        int aux = vec[0];
        vec[0] = vec[1];
        vec[1] = aux;
    }
    //El sistema permite que desde y hasta sean iguales si la lista tiene solo 1 elemento.
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

void tipoPersona(bool esChofer)
{
    if(esChofer)
    {
        printf("CHOFER");
    }
    else
    {
        printf("CLIENTE");
    }
}

void notificacionListaVacia(ListaPtr ListaAnalizar)
{
    if( listaVacia(ListaAnalizar)  )
    {
        printf("\n\n\t [Se ha salido del menu de eliminacion debido que no existen elementos] \n");
        printf("\t [Para eliminar, debe agregar mas para poder continuar] \n\n");
        presionarEnterYLimpiarPantalla();
    }
}

int menuTipoBusquedaCliente()
{
   int eleccion = 0;
   system("cls");
   printf("MENU DE SELECCION DE CLIENTE DE PAQUETE \n");
   printf("1. Seleccion mediante INDICE \n");
   printf("2. Seleccion mediante CUIL \n");
   printf("OPCION: ");
   eleccion = seleccionarNumero();
   return eleccion;
}

int menuTipoOrdenamientoPaquetes()
{
    int op = 0;
    system("cls");
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
    limpiarBufferTeclado();
    scanf("%d",&op);
    limpiarBufferTeclado();
    system("cls");
    return op;
}

int menuTipoOrdenamientoPersonas()
{
    int op = 0;
    printf("\n-----------------------------------------\n\n");
    printf("1. Ordenados por Nombre\n");
    printf("2. Ordenados por Apellido\n");
    printf("3. Ordenados por Cuil\n");
    printf("4. SIN ORDENAR\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    scanf("%d",&op);
    limpiarBufferTeclado();
    system("cls");
    return op;
}

int menuTipoOrdenamientoVehiculos()
{
    int op = 0;
    system("cls");
    printf("EMITIR LISTADO DE VEHICULOS\n");
    printf("\n-----------------------------------------\n\n");
    printf("1. Ordenados por Marca\n");
    printf("2. Ordenados por Modelo\n");
    printf("3. Ordenados por tipo\n");
    printf("4. SIN ORDENAR\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op);
    limpiarBufferTeclado();
    system("cls");
    return op;
}

int menuTipoRepartos()
{
   system("cls");
   int eleccion=0;
   fflush(stdin);
   printf("BUSCAR POR: \n");
   printf("1. Indice \n");
   printf("2. Cuil chofer \n");
   printf("3. Patente vehiculo \n");
   printf("4. Fecha salida \n");
   printf("5. Fecha retorno \n");
   printf("6. ID paquete \n");
   printf("0. Volver \n");
   printf("Eleccion: ");
   scanf("%d",&eleccion);
   fflush(stdin);
   return eleccion;
}


int MenuSeleccionAtributoReparto()
{
    int eleccion;
    printf("Seleccione un atributo de [ REPARTO ] para modificar \n");
    printf("1. Chofer \n");
    printf("2. Vehiculo \n");
    printf("3. Fecha de salida \n");
    printf("4. Fecha de retorno \n");
    printf("5. Paquete \n");
    printf("Opcion: ");
    limpiarBufferTeclado();
    scanf("%d", &eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuListadoReparto()
{
    int op2=0;
    system("cls");
    printf("\n-----------------------------------------\n\n");
    printf("1. Mostrar un reparto\n");
    printf("2. Ordenar lista y mostrar...\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion:");
    limpiarBufferTeclado();
    scanf("%d",&op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuOrdenarRepartos()
{
    int op3=0;
    system("cls");
    printf("ORDENAR Y MOSTRAR POR:\n");
    printf("1. Fecha de salida\n");
    printf("2. Fecha de retorno\n");
    printf("3. Fecha de salida y retorno\n");
    printf("4. Nombre del chofer\n");
    printf("5. Apellido del chofer\n");
    printf("6. Nombre y apellido del chofer\n");
    printf("7. Sin ordenar\n");
    printf("0. Volver\n\n");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op3);
    limpiarBufferTeclado();
    system("cls");
    return op3;
}


///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE MENUES DEL MAIN///
///-----------------------------------------------------------------------------------------------------------///

int menuMainMenu()
{
    int START_OP=0;
    system("cls");
    printf("MENU DE INICIO - BIENVENIDO\n\n");
    printf("\t1. REGISTRARSE\n");
    printf("\t2. INICIAR SESION\n");
    printf("\t0. SALIR\n\n");
    printf("Seleccione una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&START_OP);
    limpiarBufferTeclado();
    system("cls");
    return START_OP;
}

int menuPrincipal(CentroLogisticoPtr centroLogistico)
{
    int MAIN_OP=0;
    system("cls");
    printf("CENTRO LOGISTICO '%s' - MENU PRINCIPAL\n\n",getNombreCentroLogistico(centroLogistico));
    printf("1. BASE DE DATOS\n");
    printf("2. REPARTOS\n");
    printf("3. INDICAR RESULTADOS DE ENTREGAS\n");
    printf("4. EMITIR LISTADOS\n");
    printf("5. GUARDAR CAMBIOS\n"); ///NUEVO
    printf("0. SALIR\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d", &MAIN_OP);
    limpiarBufferTeclado();
    system("cls");
    return MAIN_OP;
}

int menuBaseDeDatos()
{
    int op1=0;
    system("cls");
    printf("BASE DE DATOS\n\n");
    printf("1. Cargar Datos\n");
    printf("2. Eliminar Datos\n");
    printf("3. Modificar Datos\n");
    printf("4. Buscar Datos\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d", &op1);
    limpiarBufferTeclado();
    system("cls");
    return op1;
}

int menuCargaDeDatos()
{
    int op2=0;
    system("cls");
    printf("CARGAR DATOS\n\n");
    printf("1. Cargar paquete\n");
    printf("2. Cargar cliente\n");
    printf("3. Cargar chofer\n");
    printf("4. Cargar vehiculo\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d", &op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuEliminarDatos()
{
    int op2=0;
    system("cls");
    printf("ELIMINAR DATOS\n\n");
    printf("1. Eliminar Paquete\n");
    printf("2. Eliminar Cliente\n");
    printf("3. Eliminar Chofer\n");
    printf("4. Eliminar Vehiculo\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuModificacionDatos()
{
    int op2=0;
    system("cls");
    printf("MODIFICAR DATOS\n\n");
    printf("1. Modificar Paquete\n");
    printf("2. Modificar Cliente\n");
    printf("3. Modificar Chofer\n");
    printf("4. Modificar Vehiculo\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuBusquedaDatos()
{
    int op2=0;
    system("cls");
    printf("BUSCAR DATOS\n\n");
    printf("1. Buscar paquete\n"); //buscamos por ID
    printf("2. Buscar cliente\n"); //buscamos por
    printf("3. Buscar chofer\n"); //cuil
    printf("4. Buscar vehiculo\n"); //buscamos por patente
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d", &op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuOperacionesReparto()
{
    int op1=0;
    system("cls");
    printf("MENU DE REPARTOS\n\n");
    ///Son solo para repartos abiertos:
    printf("1. Armar reparto\n"); //Este
    printf("2. Cerrar reparto\n"); //Y este
    printf("3. Eliminar reparto\n");
    printf("4. Modificar reparto\n");
    printf("5. Buscar reparto\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op1);
    limpiarBufferTeclado();
    system("cls");
    return op1;
}

int menuEliminarRepartoCompleto()
{
    int op2=0;
    system("cls");
    printf("ELIMINAR REPARTO:\n\n");
    printf("1. Abierto\n");
    printf("2. Cerrado\n");
    printf("0. Volver");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Seleccione una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuModificarRepartoCompleto()
{
    int op2=0;
    system("cls");
    printf("MODIFICAR REPARTO:\n\n");
    printf("1. Abierto\n");
    printf("2. Cerrado\n");
    printf("0. Volver");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Seleccione una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuBuscadoReparto()
{
    int op2=0;
    system("cls");
    printf("BUSCAR REPARTO:\n\n");
    printf("1. Abierto\n");
    printf("2. Cerrado\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Seleccione una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuActualizarRepartoCompleto()
{
    int op1=0;
    system("cls");
    printf("VER RESULTADOS DE ENTREGAS");
    printf("\n-----------------------------------------\n\n");
    printf("1. Ver en Lista de Paquetes\n");
    printf("2. Ver en Repartos ABIERTOS\n");
    printf("3. Ver en Repartos CERRADOS\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op1);
    limpiarBufferTeclado();
    system("cls");
    return op1;
}

int menuListados()
{
    int op1=0;
    system("cls");
    printf("EMITIR LISTADOS DE:\n\n");
    printf("1. Paquetes\n");
    printf("2. Choferes\n");
    printf("3. Clientes\n");
    printf("4. Clientes y Choferes\n");
    printf("5. Vehiculos\n");
    printf("6. Repartos - ABIERTOS\n");
    printf("7. Repartos - CERRADOS\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op1);
    limpiarBufferTeclado();
    system("cls");
    return op1;
}

int menuGuardarCambiosMain()
{
    int op1=0;
    system("cls");
    printf("GUARDAR CAMBIOS\n\n");
    printf("\n-----------------------------------------\n\n");
    printf("1. Lista de Paquetes\n");
    printf("2. Lista de Personas\n");
    printf("3. Lista de Vehiculos\n");
    printf("4. Lista de Repartos Abiertos\n");
    printf("5. Lista de Repartos Cerrados\n");
    printf("6. TODAS LAS LISTAS\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op1);
    limpiarBufferTeclado();
    system("cls");
    return op1;
}

int menuGuardadoRespaldo()
{
    int op1=0;
    system("cls");
    printf("Tiene cambios sin guardar. Seguro que quiere salir?\n");
    printf("\n----------------------------------------------------\n\n");
    printf("1. Guardar y salir\n");
    printf("2. Salir sin guardar\n");
    printf("0. Volver\n\n");
    printf("\n----------------------------------------------------\n\n");
    printf("Seleccione una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op1);
    limpiarBufferTeclado();
    system("cls");
    return op1;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Files.h"
#include "Lista.h"
#include "Menus.h"
#include "test.h"
#include "util.h"


/**
DIRECTORIOS (FRANCO S.)

Para crear y linkear archivos
E:\Franco\9. PROGRAMAS\GitHub\GitHub - Repositorios\TP-Integrador-Repositorio\TPIntegrador_FINAL\

Para abrir/guardar files = CARPETA "Archivos"
E:\Franco\9. PROGRAMAS\GitHub\GitHub - Repositorios\TP-Integrador-Repositorio\Archivos\
*/


///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE REGISTRO DE USUARIO///
///-----------------------------------------------------------------------------------------------------------///

int main()
{
    CentroLogisticoPtr centroLogistico;
    int START_OP=0;
    ListaPtr vehiculos = crearListaVehiculosGenerico();
    ListaPtr paquetes1 = crearListaPaquetesGenerico();
    ListaPtr personas = crearListaPersonasGenerica();
    ListaPtr repartosA = crearListaRepartosPorDefectoConLista();
    ListaPtr repartosC = crearLista();
    centroLogistico = crearCentroLogistico("Distribuidora",paquetes1,personas,vehiculos,repartosA,repartosC);
    do
    {
        START_OP = menuMainMenu();
        switch(START_OP)
        {
        case 1:
            ///centroLogistico=menuCrearNuevoCtroLogRapido(centroLogistico);
            system("cls");
            START_OP = MAIN_MENU(centroLogistico);
            centroLogistico=destruirCentroLogistico(centroLogistico);
            break;
        case 2:
            centroLogistico = abrirTodo();
            if(centroLogistico==NULL)
            {
                printf("ERROR AL ABRIR.\n\n");
                exit(1);
            }
            else
            {
                START_OP = MAIN_MENU(centroLogistico);
                centroLogistico=destruirCentroLogistico(centroLogistico);
            }
            break;
        case 0:
            break;
        default:
            printf("Opcion incorrecta.\n\n");
            break;
        }
    } while(START_OP!=0);
    printf("Hasta pronto!\n\n");
    return 0;
}

///-----------------------------------------------------------------------------------------------------------///
                        ///SECCION DE FUNCIONES DE OPERACIONES POSIBLES DEL USUARIO///
///-----------------------------------------------------------------------------------------------------------///

int MAIN_MENU(CentroLogisticoPtr centroLogistico)
{
    ///Menúes
    int MAIN_OP=1,op1=0,op2=0;
    bool resultadoGuardado=false;
    bool cambiosGuardados=false;
    do
    {
        MAIN_OP = menuPrincipal(centroLogistico);
        switch(MAIN_OP)
        {
        case 1:
            do
            {
                op1=menuBaseDeDatos();
                switch(op1)
                {
                case 1:
                    do
                    {
                        op2=menuCargaDeDatos();
                        switch(op2)
                        {
                        case 1:
                            cambiosGuardados = menuCargarPaquete(centroLogistico);
                            break;
                        case 2:
                            cambiosGuardados = menuCargarPersona(centroLogistico,false);
                            break;
                        case 3:
                            cambiosGuardados = menuCargarPersona(centroLogistico,true);
                            break;
                        case 4:
                            cambiosGuardados = menuCargarVehiculo(centroLogistico);
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            op2=0;
                            break;
                        default:
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                    } while(op2!=0);
                    break;
                case 2:
                    do
                    {
                        op2=menuEliminarDatos();
                        switch(op2)
                        {
                        case 1:
                            cambiosGuardados = menuEliminarPaquete(centroLogistico);
                            break;
                        case 2:
                            cambiosGuardados = menuEliminarPersona(centroLogistico,false);
                            break;
                        case 3:
                            cambiosGuardados = menuEliminarPersona(centroLogistico,true);
                            break;
                        case 4:
                            cambiosGuardados = menuEliminarVehiculo(centroLogistico);
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            op2=0;
                            break;
                        default:
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                    } while(op2!=0);
                    break;
                case 3:
                    do
                    {
                        op2=menuModificacionDatos();
                        switch(op2)
                        {
                        case 1:
                            cambiosGuardados = menuModificarPaquete(centroLogistico);
                            break;
                        case 2:
                            cambiosGuardados = menuModificarPersona(centroLogistico,false);
                            break;
                        case 3:
                            cambiosGuardados = menuModificarPersona(centroLogistico,true);
                            break;
                        case 4:
                            cambiosGuardados = menuModificarVehiculo(centroLogistico);
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            op2=0;
                            break;
                        default:
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                    } while(op2!=0);
                    break;
                case 4:
                    do
                    {
                        op2=menuBusquedaDatos();
                        switch(op2)
                        {
                        case 1:
                            menuBuscarPaquete(centroLogistico);
                            break;
                        case 2:
                            menuBuscarPersona(centroLogistico,false);
                            break;
                        case 3:
                            menuBuscarPersona(centroLogistico,true);
                            break;
                        case 4:
                            menuBuscarVehiculo(centroLogistico);
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            op2=0;
                            break;
                        default:
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                    } while(op2!=0);
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion incorrecta.\n\n");
                    break;
                }
            } while(op1!=0);
            break;
        case 2:
            do
            {
                op1=menuOperacionesReparto();
                switch(op1)
                {
                case 1:
                    cambiosGuardados = menuArmarReparto(centroLogistico);
                    break;
                case 2:
                    cambiosGuardados = menuCerrarReparto(centroLogistico);
                    break;
                case 3:
                    do
                    {
                        op2=menuEliminarRepartoCompleto();
                        switch(op2)
                        {
                        case 1:
                            cambiosGuardados = menuEliminarReparto(centroLogistico,true);
                            break;
                        case 2:
                            cambiosGuardados = menuEliminarReparto(centroLogistico,false);
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            op2=0;
                            break;
                        default:
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                    } while(op2!=0);
                    break;
                case 4:
                    do
                    {
                        op2=menuModificarRepartoCompleto();
                        switch(op2)
                        {
                        case 1:
                            cambiosGuardados = menuModificarReparto(centroLogistico,true);
                            break;
                        case 2:
                            cambiosGuardados = menuModificarReparto(centroLogistico,false);
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            op2=0;
                            break;
                        default:
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                    } while(op2!=0);
                    break;
                case 5:
                    do
                    {
                        op2=menuBuscadoReparto();
                        switch(op2)
                        {
                        case 1:
                            menuBuscarReparto(centroLogistico,true);
                            break;
                        case 2:
                            menuBuscarReparto(centroLogistico,false);
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            op2=0;
                            break;
                        default:
                            printf("Opcion incorrecta.\n\n");
                            break;
                    } while(op2!=0);
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion incorrecta.\n\n");
                    break;
                }while(op2!=0);
            }
        } while(op1!=0);
            break;
        case 3:
            ///op1=menuActualizarRepartoCompleto();
            menuActualizarReparto(centroLogistico);
            break;
        case 4:
            do
            {
                op1=menuListados();
                switch(op1)
                {
                case 1:
                    cambiosGuardados = menuMostrarPaquetes(centroLogistico);
                    break;
                case 2:
                    cambiosGuardados = menuMostrarPersonas(centroLogistico,2);
                    break;
                case 3:
                    cambiosGuardados = menuMostrarPersonas(centroLogistico,1);
                    break;
                case 4:
                    cambiosGuardados = menuMostrarPersonas(centroLogistico,3);
                    break;
                case 5:
                    cambiosGuardados = menuMostrarVehiculos(centroLogistico);
                    break;
                case 6:
                    cambiosGuardados = menuMostrarRepartos(centroLogistico,true);
                    break;
                case 7:
                    cambiosGuardados = menuMostrarRepartos(centroLogistico,false);
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion incorrecta.\n\n");
                    break;
                }
            } while(op1!=0);
            break;
        case 5:
            do
            {
                op1=menuGuardarCambiosMain();
                switch(op1)
                {
                case 1:
                    resultadoGuardado=guardarPaquetes(centroLogistico);
                    if(resultadoGuardado)
                        printf("Lista de Paquetes guardada exitosamente.\n\n");
                    break;
                case 2:
                    resultadoGuardado=guardarPersonas(centroLogistico);
                    if(resultadoGuardado)
                        printf("Lista de Personas guardada exitosamente.\n\n");
                    break;
                case 3:
                    resultadoGuardado=guardarVehiculos(centroLogistico);
                    if(resultadoGuardado)
                        printf("Lista de Vehiculos guardada exitosamente.\n\n");
                    break;
                case 4:
                    resultadoGuardado=guardarRepartos(centroLogistico,true);
                    if(resultadoGuardado)
                        printf("Lista de Repartos Abiertos guardada exitosamente.\n\n");
                    break;
                case 5:
                    resultadoGuardado=guardarRepartos(centroLogistico,false);
                    if(resultadoGuardado)
                        printf("Lista de Repartos Cerrados guardada exitosamente.\n\n");
                    break;
                case 6:
                    resultadoGuardado=guardarTodo(centroLogistico);
                    cambiosGuardados=resultadoGuardado;
                    if(resultadoGuardado)
                        printf("Todas las listas han sido guardadas exitosamente.\n\n");
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion incorrecta.\n\n");
                    break;
                }
                if(!resultadoGuardado)
                {
                    printf("ERROR AL GUARDAR\n\n");
                    exit(1);
                }

            } while(op1!=0);
            break;
        case 0:
            if(!cambiosGuardados) //"Si no se efectuaron cambios o si se efectuaron y no se guardaron"
            {
                do
                {
                    op1=menuGuardadoRespaldo();
                    switch(op1)
                    {
                    case 1:
                        if(guardarTodo(centroLogistico))
                        {
                            cambiosGuardados=true;
                            printf("Cambios guardados exitosamente.\n\n");
                        }
                        else
                        {
                            printf("ERROR AL GUARDAR LOS CAMBIOS.\n\n");
                            exit(1);
                        }
                        MAIN_OP=0;
                        break;
                    case 2:
                        MAIN_OP=0;
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opcion incorrecta.\n\n");
                        break;
                    }
                } while(op1!=1 && op1!=2 && op1!=0);
            }
            break;
        default:
            printf("Opcion incorrecta.\n\n");
            break;
        }
    } while(MAIN_OP!=0);

    return MAIN_OP; //salimos de todo el programa
}


///---------------------------------------------------------------//////---------------------------------------------------------------///

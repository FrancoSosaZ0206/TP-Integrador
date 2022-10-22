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
E:\Franco\9. PROGRAMAS\GitHub\GitHub - Repositorios\TP-Integrador-Repositorio\TPIntegrador_FINAL\Archivos\
*/

void actualizarDomicilioPrueba(DomicilioPtr domicilio)
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

int MAIN_MENU(CentroLogisticoPtr centroLogistico);

int main()
{
/// **************************************************************************************************************
///                                             SECCI�N DE PRUEBAS R�PIDAS
/// **************************************************************************************************************
/*
    CentroLogisticoPtr ctroPrueba = crearCentroLogisticoRapido("Prueba");

    PaquetePtr paq1 = crearPaqueteDirect(21652,12,34,25,68,
                                         "Teniente Alvarez",1877,
                                         "Hurlingam",
                                         "Borlo Frezzini",55,
                                         "La Matanza",
                                         15,11,2022,19,22,0);
    PaquetePtr paq2 = crearPaqueteDirect(20514,33,34,35,79,
                                         "Coronel Chamaco",5604,
                                         "Haedo",
                                         "Lavalle",1333,
                                         "Valentin Alsina",
                                         16,12,2022,17,35,0);

    agregarPaquete(ctroPrueba,paq1);
    agregarPaquete(ctroPrueba,paq2); //paq2 estar� arriba de todo al mostrar la lista.

    mostrarPaquete(paq1); //Mostramos el paquete a modificar
    printf("\n\nACTUALICE LA DIRECCION DE RETIRO\n");
    actualizarDomicilioPrueba(getDirRetiro(paq1)); //Modificamos la direccion de retiro
    presionarEnterYLimpiarPantalla();

    mostrarPaquete(paq1); //Lo volvemos a mostrar con el nuevo domicilio.

    return 0;
*/
/// **************************************************************************************************************

    CentroLogisticoPtr centroLogistico;

    int START_OP=0;

    do
    {
        printf("\t    MENU DE INICIO - BIENVENIDO");
        printf("\n\n\t-----------------------------------\n\n");
        printf("\t\t 1. REGISTRARSE\n");
        printf("\t\t 2. INICIAR SESION\n");
        printf("\t\t 0. SALIR");
        printf("\n\n\t-----------------------------------\n\n");
        printf("\t     Seleccione una opcion: ");
        scanf("%d",&START_OP);

        limpiarBufferTeclado();

        system("cls");
        switch(START_OP)
        {
        case 1:
            centroLogistico=menuCrearNuevoCtroLogRapido(centroLogistico);
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
            printf("\t\tHasta pronto!\n\n");
            break;
        default:
            printf("Opcion incorrecta.");
            presionarEnterYLimpiarPantalla();
            break;
        }
    } while(START_OP!=0);

    return 0;
}


int MAIN_MENU(CentroLogisticoPtr centroLogistico)
{
    ///Men�es
    int MAIN_OP = 0;
    int op1=0;
    int op2=0;

    bool cambiosGuardados=true; //Asumimos que es verdad para que la opcion al salir no salga si no hacemos nada.

    do
    {
        printf("CENTRO LOGISTICO '%s' - MENU PRINCIPAL",getNombreCentroLogistico(centroLogistico));
        printf("\n\n-----------------------------------------\n\n");
        printf("1. BASE DE DATOS\n");
        printf("2. REPARTOS\n");
        printf("3. INDICAR RESULTADOS DE ENTREGAS\n");
        printf("4. EMITIR LISTADOS\n");
        printf("5. GUARDAR CAMBIOS\n"); ///NUEVO
        printf("0. SALIR");
        printf("\n\n-----------------------------------------\n\n");
        printf("Elija una opcion: ");
        scanf("%d", &MAIN_OP);
        limpiarBufferTeclado();

        system("cls");
        switch(MAIN_OP)
        {
        case 1:
            do
            {
                printf("BASE DE DATOS");
                printf("\n\n-----------------------------------------\n\n");
                printf("1. Cargar Datos\n");
                printf("2. Eliminar Datos\n");
                printf("3. Modificar Datos\n");
                printf("4. Buscar Datos\n");
                printf("0. Volver");
                printf("\n\n-----------------------------------------\n\n");
                printf("Elija una opcion: ");
                scanf("%d", &op1);
                limpiarBufferTeclado();

                system("cls");
                switch(op1)
                {
                case 1:
                    do
                    {
                        printf("CARGAR DATOS");
                        printf("\n\n-----------------------------------------\n\n");
                        printf("1. Cargar paquete\n");
                        printf("2. Cargar cliente\n");
                        printf("3. Cargar chofer\n");
                        printf("4. Cargar vehiculo\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL");
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Elija una opcion: ");
                        scanf("%d", &op2);
                        limpiarBufferTeclado();

                        system("cls");
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
                            break;
                        default:
                            printf("Opcion incorrecta.");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(!(op2==0 || op2==-1));
                    break;
                case 2:
                    do
                    {
                        printf("ELIMINAR DATOS");
                        printf("\n\n-----------------------------------------\n\n");
                        printf("1. Eliminar Paquete\n");
                        printf("2. Eliminar Cliente\n");
                        printf("3. Eliminar Chofer\n");
                        printf("4. Eliminar Vehiculo\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL");
                        printf("\n\n-----------------------------------------\n\n");

                        printf("Elija una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();

                        system("cls");
                        switch(op2)
                        {
                        case 1:
                            cambiosGuardados = menuEliminarPaquete(centroLogistico,&op2);
                            break;
                        case 2:
                            cambiosGuardados = menuEliminarPersona(centroLogistico,false,&op2);
                            break;
                        case 3:
                            cambiosGuardados = menuEliminarPersona(centroLogistico,true,&op2);
                            break;
                        case 4:
                            cambiosGuardados = menuEliminarVehiculo(centroLogistico,&op2);
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            break;
                        default:
                            printf("Opcion incorrecta.");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(!(op2==0 || op2==-1));
                    break;
                case 3:
                    do
                    {
                        printf("MODIFICAR DATOS");
                        printf("\n\n-----------------------------------------\n\n");
                        printf("1. Modificar Paquete\n");
                        printf("2. Modificar Cliente\n");
                        printf("3. Modificar Chofer\n");
                        printf("4. Modificar Vehiculo\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL");
                        printf("\n\n-----------------------------------------\n\n");

                        printf("Elija una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();

                        system("cls");
                        switch(op2)
                        {
                        case 1:
                            cambiosGuardados = menuModificarPaquete(centroLogistico,&op2);
                            break;
                        case 2:
                            cambiosGuardados = menuModificarPersona(centroLogistico,false,&op2);
                            break;
                        case 3:
                            cambiosGuardados = menuModificarPersona(centroLogistico,true,&op2);
                            break;
                        case 4:
                            cambiosGuardados = menuModificarVehiculo(centroLogistico,&op2);
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            break;
                        default:
                            printf("Opcion incorrecta.");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(!(op2==0 || op2==-1));
                    break;
                case 4:
                    do
                    {
                        printf("BUSCAR DATOS");
                        printf("\n\n-----------------------------------------\n\n");
                        printf("1. Buscar paquete\n"); //buscamos por ID
                        printf("2. Buscar cliente\n"); //buscamos por
                        printf("3. Buscar chofer\n"); //cuil
                        printf("4. Buscar vehiculo\n"); //buscamos por patente
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL");
                        printf("\n\n-----------------------------------------\n\n");

                        printf("Elija una opcion: ");
                        scanf("%d", &op2);
                        limpiarBufferTeclado();

                        system("cls");
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
                            break;
                        default:
                            printf("Opcion incorrecta.");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(!(op2==0 || op2==-1));
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion incorrecta.");
                    presionarEnterYLimpiarPantalla();
                    break;
                }
            } while(op1!=0);
            break;
        case 2:
            do
            {
                printf("MENU DE REPARTOS");
                printf("\n\n-----------------------------------------\n\n");
                    ///Son solo para repartos abiertos:
                printf("1. Armar reparto\n"); //Este
                printf("2. Cerrar reparto\n"); //Y este
                printf("3. Eliminar reparto\n");
                printf("4. Modificar reparto\n");
                printf("5. Buscar reparto\n");
                printf("0. Volver");
                printf("\n\n-----------------------------------------\n\n");
                printf("Elija una opcion: ");
                scanf("%d",&op1);

                limpiarBufferTeclado();
                system("cls");
                switch(op1)
                {
                case 1:
                    cambiosGuardados = menuArmarReparto(centroLogistico);
                    break;
                case 2:
                    cambiosGuardados = menuCerrarReparto(centroLogistico,&op1);
                    break;
                case 3:
                    do
                    {
                        printf("ELIMINAR REPARTO:\n\n");
                        printf("1. Abierto\n");
                        printf("2. Cerrado\n");
                        printf("0. Volver");
                        printf("-1. MENU PRINCIPAL");
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Seleccione una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();
                        system("cls");
                        switch(op2)
                        {
                        case 1:
                            cambiosGuardados = menuEliminarReparto(centroLogistico,true,&op2);
                            break;
                        case 2:
                            cambiosGuardados = menuEliminarReparto(centroLogistico,false,&op2);
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            break;
                        default:
                            printf("Opcion incorrecta.");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(!(op2==0 || op2==-1));
                    break;
                case 4:
                    do
                    {
                        printf("MODIFICAR REPARTO:\n\n");
                        printf("1. Abierto\n");
                        printf("2. Cerrado\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL");
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Seleccione una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();
                        system("cls");
                        switch(op2)
                        {
                        case 1:
                            cambiosGuardados = menuModificarReparto(centroLogistico,true,&op2);
                            break;
                        case 2:
                            cambiosGuardados = menuModificarReparto(centroLogistico,false,&op2);
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            break;
                        default:
                            printf("Opcion incorrecta.");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(!(op2==0 || op2==-1));
                    break;
                case 5:
                    do
                    {
                        printf("BUSCAR REPARTO:\n\n");
                        printf("1. Abierto\n");
                        printf("2. Cerrado\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL");
                        printf("\n\n-----------------------------------------\n\n");
                        printf("Seleccione una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();
                        system("cls");
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
                            break;
                        default:
                            printf("Opcion incorrecta.");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(!(op2==0 || op2==-1));
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion incorrecta.");
                    presionarEnterYLimpiarPantalla();
                    break;
                    }
            } while(op1!=0);
            break;
        case 3:
            printf("INDICAR RESULTADOS DE ENTREGAS");
            printf("\n\n-----------------------------------------\n\n");

            cambiosGuardados = menuActualizarReparto(centroLogistico);
            break;
        case 4:
            do
            {
                printf("EMITIR LISTADOS DE:\n\n");

                printf("1. Paquetes\n");
                printf("2. Clientes\n");
                printf("3. Choferes\n");
                printf("4. Clientes y Choferes\n");
                printf("5. Vehiculos\n");
                printf("6. Repartos - ABIERTOS\n");
                printf("7. Repartos - CERRADOS\n");
                printf("0. Volver");
                printf("\n\n-----------------------------------------\n\n");

                printf("Elija una opcion: ");
                scanf("%d",&op1);
                limpiarBufferTeclado();

                system("cls");
                switch(op1)
                {
                case 1:
                    cambiosGuardados = menuMostrarPaquetes(centroLogistico,&op1);
                    break;
                case 2:
                    cambiosGuardados = menuMostrarPersonas(centroLogistico,2,&op1);
                    break;
                case 3:
                    cambiosGuardados = menuMostrarPersonas(centroLogistico,1,&op1);
                    break;
                case 4:
                    cambiosGuardados = menuMostrarPersonas(centroLogistico,3,&op1);
                    break;
                case 5:
                    cambiosGuardados = menuMostrarVehiculos(centroLogistico,&op1);
                    break;
                case 6:
                    cambiosGuardados = menuMostrarRepartos(centroLogistico,true,&op1);
                    break;
                case 7:
                    cambiosGuardados = menuMostrarRepartos(centroLogistico,false,&op1);
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion incorrecta.");
                    presionarEnterYLimpiarPantalla();
                    break;
                }
            } while(op1!=0);
            break;
        case 5:
            do
            {
                printf("GUARDAR CAMBIOS");
                printf("\n\n-----------------------------------------\n\n");
                printf("1. Lista de Paquetes\n");
                printf("2. Lista de Personas\n");
                printf("3. Lista de Vehiculos\n");
                printf("4. Lista de Repartos Abiertos\n");
                printf("5. Lista de Repartos Cerrados\n");
                printf("6. TODAS LAS LISTAS\n");
                printf("0. Volver");
                printf("\n\n-----------------------------------------\n\n");
                printf("Elija una opcion: ");
                scanf("%d",&op1);

                limpiarBufferTeclado();
                system("cls");
                switch(op1)
                {
                case 1:
                    if(guardarPaquetes(centroLogistico))
                        printf("Lista de Paquetes guardada exitosamente.");
                    else
                    {
                        printf("ERROR AL GUARDAR\n\n");
                        exit(1);
                    }
                    break;
                case 2:
                    if(guardarPersonas(centroLogistico))
                        printf("Lista de Personas guardada exitosamente.");
                    else
                    {
                        printf("ERROR AL GUARDAR\n\n");
                        exit(1);
                    }
                    break;
                case 3:
                    if(guardarVehiculos(centroLogistico))
                        printf("Lista de Vehiculos guardada exitosamente.");
                    else
                    {
                        printf("ERROR AL GUARDAR\n\n");
                        exit(1);
                    }
                    break;
                case 4:
                    if(guardarRepartos(centroLogistico,true))
                        printf("Lista de Repartos Abiertos guardada exitosamente.");
                    else
                    {
                        printf("ERROR AL GUARDAR\n\n");
                        exit(1);
                    }
                    break;
                case 5:
                    if(guardarRepartos(centroLogistico,false))
                        printf("Lista de Repartos Cerrados guardada exitosamente.");
                    else
                    {
                        printf("ERROR AL GUARDAR\n\n");
                        exit(1);
                    }
                    break;
                case 6:
                    if(guardarTodo(centroLogistico))
                    {
                        cambiosGuardados=true; //Si se guarda todo, no queremos que despliegue el mensaje final al querer salir.
                        printf("Todas las listas han sido guardadas exitosamente.");
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
                    break;
                }
                if(op1!=0)
                    presionarEnterYLimpiarPantalla();
            } while(op1!=0);
            break;
        case 0:
            if(!cambiosGuardados) //"Si no se efectuaron cambios o si se efectuaron y no se guardaron"
            {
                do
                {
                    printf("Tiene cambios sin guardar. Seguro que quiere salir?");
                    printf("\n\n----------------------------------------------------\n\n");
                    printf("1. Guardar y salir\n");
                    printf("2. Salir sin guardar\n");
                    printf("0. Volver");
                    printf("\n\n----------------------------------------------------\n\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d",&op1);

                    system("cls");
                    switch(op1)
                    {
                    case 1:
                        if(guardarTodo(centroLogistico))
                        {
                            cambiosGuardados=true;
                            printf("Cambios guardados exitosamente.");
                        }
                        else
                        {
                            printf("ERROR AL GUARDAR LOS CAMBIOS.\n\n");
                            exit(1);
                        }
                        break;
                    case 2:
                        break;
                    case 0:
                        MAIN_OP=1; //Cambiamos el valor para evitar que salga el programa. No pasa nada, luego se espera a que el usuario ingrese una opcion.
                        break;
                    default:
                        printf("Opcion incorrecta.");
                        break;
                    }
                    if(op1==1)
                        presionarEnterYLimpiarPantalla();
                } while(op1<0 || op1>2);
            }
            break;
        default:
            printf("Opcion incorrecta.");
            presionarEnterYLimpiarPantalla();
            break;
        }
    } while(MAIN_OP!=0);

    return MAIN_OP; //salimos de todo el programa
}

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

int MAIN_MENU(CentroLogisticoPtr centroLogistico);

int main()
{
    CentroLogisticoPtr centroLogistico;

    int START_OP=0;

    do
    {
        printf("MENU DE INICIO - BIENVENIDO\n\n");
        printf("\t1. REGISTRARSE\n");
        printf("\t2. INICIAR SESION\n");
        printf("\t0. SALIR\n\n");
        printf("Seleccione una opcion: ");
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
            printf("Hasta pronto!\n\n");
            break;
        default:
            printf("Opcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }
    } while(START_OP!=0);

    return 0;
}


int MAIN_MENU(CentroLogisticoPtr centroLogistico)
{
    ///Menúes
    int MAIN_OP = 0;
    int op1=0;
    int op2=0;

    bool cambiosGuardados=false;

    do
    {
        printf("CENTRO LOGISTICO '%s' - MENU PRINCIPAL\n\n",getNombreCentroLogistico(centroLogistico));

        printf("1. BASE DE DATOS\n");
        printf("2. REPARTOS\n");
        printf("3. VER RESULTADOS DE ENTREGAS\n");
        printf("4. EMITIR LISTADOS\n");
        printf("5. GUARDAR CAMBIOS\n"); ///NUEVO
        printf("0. SALIR\n");
        printf("\n-----------------------------------------\n\n");
        printf("Elija una opcion: ");
        scanf("%d", &MAIN_OP);
        limpiarBufferTeclado();

        system("cls");
        switch(MAIN_OP)
        {
        case 1:
            do
            {
                printf("BASE DE DATOS\n\n");

                printf("1. Cargar Datos\n");
                printf("2. Eliminar Datos\n");
                printf("3. Modificar Datos\n");
                printf("4. Buscar Datos\n");
                printf("0. Volver\n");
                printf("\n-----------------------------------------\n\n");
                printf("Elija una opcion: ");
                scanf("%d", &op1);
                limpiarBufferTeclado();

                system("cls");
                switch(op1)
                {
                case 1:
                    do
                    {
                        printf("CARGAR DATOS\n\n");

                        printf("1. Cargar paquete\n");
                        printf("2. Cargar cliente\n");
                        printf("3. Cargar chofer\n");
                        printf("4. Cargar vehiculo\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL\n");
                        printf("\n-----------------------------------------\n\n");
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
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                        if(!(op2==0 && op2==-1)) //A menos que elija volver,
                            presionarEnterYLimpiarPantalla(); //hacemos esto
                    } while(!(op2==0 && op2==-1));
                    break;
                case 2:
                    do
                    {
                        printf("ELIMINAR DATOS\n\n");

                        printf("1. Eliminar Paquete\n");
                        printf("2. Eliminar Cliente\n");
                        printf("3. Eliminar Chofer\n");
                        printf("4. Eliminar Vehiculo\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL\n");
                        printf("\n-----------------------------------------\n\n");

                        printf("Elija una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();

                        system("cls");
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
                            break;
                        default:
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                        if(!(op2==0 && op2==-1))
                            presionarEnterYLimpiarPantalla();
                    } while(!(op2==0 && op2==-1));
                    break;
                case 3:
                    do
                    {
                        printf("MODIFICAR DATOS\n\n");

                        printf("1. Modificar Paquete\n");
                        printf("2. Modificar Cliente\n");
                        printf("3. Modificar Chofer\n");
                        printf("4. Modificar Vehiculo\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL\n");
                        printf("\n-----------------------------------------\n\n");

                        printf("Elija una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();

                        system("cls");
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
                            break;
                        default:
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                        if(!(op2==0 && op2==-1))
                            presionarEnterYLimpiarPantalla();
                    } while(!(op2==0 && op2==-1));
                    break;
                case 4:
                    do
                    {
                        printf("BUSCAR DATOS\n\n");

                        printf("1. Buscar paquete\n"); //buscamos por ID
                        printf("2. Buscar cliente\n"); //buscamos por
                        printf("3. Buscar chofer\n"); //cuil
                        printf("4. Buscar vehiculo\n"); //buscamos por patente
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL\n");
                        printf("\n-----------------------------------------\n\n");

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
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                        if(!(op2==0 && op2==-1))
                            presionarEnterYLimpiarPantalla();
                    } while(!(op2==0 && op2==-1));
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion incorrecta.\n\n");
                    break;
                }
                presionarEnterYLimpiarPantalla();
            } while(op1!=0);
            break;
        case 2:
            do
            {
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
                scanf("%d",&op1);

                limpiarBufferTeclado();
                system("cls");
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
                        printf("ELIMINAR REPARTO:\n\n");
                        printf("1. Abierto\n");
                        printf("2. Cerrado\n");
                        printf("0. Volver");
                        printf("-1. MENU PRINCIPAL");
                        printf("\n-----------------------------------------\n\n");
                        printf("Seleccione una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();
                        system("cls");
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
                            break;
                        default:
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                        if(!(op2==0 && op2==-1)) //A menos que elija volver,
                            presionarEnterYLimpiarPantalla(); //hacemos esto
                    } while(!(op2==0 && op2==-1));
                    break;
                case 4:
                    do
                    {
                        printf("MODIFICAR REPARTO:\n\n");
                        printf("1. Abierto\n");
                        printf("2. Cerrado\n");
                        printf("0. Volver");
                        printf("-1. MENU PRINCIPAL");
                        printf("\n-----------------------------------------\n\n");
                        printf("Seleccione una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();
                        system("cls");
                        switch(op2)
                        {
                        case 1:
                            cambiosGuardados = menuModificarReparto(centroLogistico,true,op2);
                            break;
                        case 2:
                            cambiosGuardados = menuModificarReparto(centroLogistico,false,op2);
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            break;
                        default:
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                        if(!(op2==0 && op2==-1)) //A menos que elija volver,
                            presionarEnterYLimpiarPantalla(); //hacemos esto
                    } while(!(op2==0 && op2==-1));
                    break;
                case 5:
                    do
                    {
                        printf("BUSCAR REPARTO:\n\n");
                        printf("1. Abierto\n");
                        printf("2. Cerrado\n");
                        printf("0. Volver");
                        printf("-1. MENU PRINCIPAL");
                        printf("\n-----------------------------------------\n\n");
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
                            printf("Opcion incorrecta.\n\n");
                            break;
                        }
                        if(!(op2==0 && op2==-1)) //A menos que elija volver,
                            presionarEnterYLimpiarPantalla(); //hacemos esto
                    } while(!(op2==0 && op2==-1));
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion incorrecta.\n\n");
                    break;
                    }
                presionarEnterYLimpiarPantalla();
            } while(op1!=0);
            break;
        case 3:
    /**Idea: se puede generar un estado al azar entre "entregado" (3) y "suspendido" (5)
        Luego, se muestra los resultados de las entregas de los repartos
    */
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
                printf("0. Volver\n");
                printf("\n-----------------------------------------\n\n");

                printf("Elija una opcion: ");
                scanf("%d",&op1);
                limpiarBufferTeclado();

                system("cls");
                switch(op1)
                {
                case 1:
                    cambiosGuardados = menuMostrarPaquetes(centroLogistico,op1);
                    break;
                case 2:
                    cambiosGuardados = menuMostrarPersonas(centroLogistico,2,op1);
                    break;
                case 3:
                    cambiosGuardados = menuMostrarPersonas(centroLogistico,1,op1);
                    break;
                case 4:
                    cambiosGuardados = menuMostrarPersonas(centroLogistico,3,op1);
                    break;
                case 5:
                    cambiosGuardados = menuMostrarVehiculos(centroLogistico,op1);
                    break;
                case 6:
                    cambiosGuardados = menuMostrarRepartos(centroLogistico,true,op1);
                    break;
                case 7:
                    cambiosGuardados = menuMostrarRepartos(centroLogistico,false,op1);
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion incorrecta.\n\n");
                    break;
                }
                if(op1!=0)
                    presionarEnterYLimpiarPantalla();
            } while(op1!=0);
            break;
        case 5:
            do
            {
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
                scanf("%d",&op1);

                limpiarBufferTeclado();
                system("cls");
                switch(op1)
                {
                case 1:
                    if(guardarPaquetes(centroLogistico))
                        printf("Lista de Paquetes guardada exitosamente.\n\n");
                    else
                    {
                        printf("ERROR AL GUARDAR\n\n");
                        exit(1);
                    }
                    break;
                case 2:
                    if(guardarPersonas(centroLogistico))
                        printf("Lista de Personas guardada exitosamente.\n\n");
                    else
                    {
                        printf("ERROR AL GUARDAR\n\n");
                        exit(1);
                    }
                    break;
                case 3:
                    if(guardarVehiculos(centroLogistico))
                        printf("Lista de Vehiculos guardada exitosamente.\n\n");
                    else
                    {
                        printf("ERROR AL GUARDAR\n\n");
                        exit(1);
                    }
                    break;
                case 4:
                    if(guardarRepartos(centroLogistico,true))
                        printf("Lista de Repartos Abiertos guardada exitosamente.\n\n");
                    else
                    {
                        printf("ERROR AL GUARDAR\n\n");
                        exit(1);
                    }
                    break;
                case 5:
                    if(guardarRepartos(centroLogistico,false))
                        printf("Lista de Repartos Cerrados guardada exitosamente.\n\n");
                    else
                    {
                        printf("ERROR AL GUARDAR\n\n");
                        exit(1);
                    }
                    break;
                case 6:
                    if(guardarTodo(centroLogistico))
                    {
                        cambiosGuardados=false; //Si se guarda todo, no queremos que despliegue el mensaje final al querer salir.
                        printf("Todas las listas han sido guardadas exitosamente.\n\n");
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
                if(op1!=0)
                    presionarEnterYLimpiarPantalla();
            } while(op1!=0);
            break;
        case 0:
            if(!cambiosGuardados) //"Si no se efectuaron cambios o si se efectuaron y no se guardaron"
            {
                do
                {
                    printf("Tiene cambios sin guardar. Seguro que quiere salir?\n");
                    printf("\n----------------------------------------------------\n\n");
                    printf("1. Guardar y salir\n");
                    printf("2. Salir sin guardar\n");
                    printf("0. Volver\n\n");
                    printf("\n----------------------------------------------------\n\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d",&op1);

                    system("cls");
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
                        break;
                    case 2:
                        break;
                    case 0:
                        MAIN_OP=1; //Cambiamos el valor para evitar que salga el programa. No pasa nada, luego se espera a que el usuario ingrese una opcion.
                        break;
                    default:
                        printf("Opcion incorrecta.\n\n");
                        presionarEnterYLimpiarPantalla();
                        break;
                    }
                } while(!(op1>0 && op1<2));
            }
            break;
        default:
            printf("Opcion incorrecta.\n\n");
            break;
        }
        presionarEnterYLimpiarPantalla();
    } while(MAIN_OP!=0);

    return MAIN_OP; //salimos de todo el programa
}

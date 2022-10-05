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
        printf("START MENU - BIENVENIDO\n\n");
        printf("\t1. INICIAR DE CERO\n");
        printf("\t2. ABRIR ARCHIVOS\n");
        printf("\t0. SALIR\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&START_OP);

        limpiarBufferTeclado();
        system("cls");



        switch(START_OP)
        {
        case 1:
            centroLogistico=menuCrearNuevoCtroLogRapido(centroLogistico);
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
    int op1=0;  //usamos otras para los loops internos, para evitar que,
    int op2=0;  //si queremos volver atrás, se vuelva todo atrás o cosas así.
    int op3 = 0;
    do
    {
        system("cls");
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


        switch(MAIN_OP)
        {
        case 1:
            do
            {
                system("cls");
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


                        switch(op2)
                        {
                        case 1:
                            menuCargarPaquete(centroLogistico);
                            break;
                        case 2:
                            menuCargarPersona(centroLogistico,false);
                            break;
                        case 3:
                            menuCargarPersona(centroLogistico,true);
                            break;
                        case 4:
                            menuCargarVehiculo(centroLogistico);
                            break;
                        case 0:
                            break;
                        case -1:
                            op2=0;
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            break;
                        }
                        if(op2!=0) //A menos que elija volver,
                            presionarEnterYLimpiarPantalla(); //hacemos esto
                    } while(op2!=0);
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


                        switch(op2)
                        {
                        case 1:
                            menuEliminarPaquete(centroLogistico);
                            break;
                        case 2:
                            menuEliminarPersona(centroLogistico,false);
                            break;
                        case 3:
                            menuEliminarPersona(centroLogistico,true);
                            break;
                        case 4:
                            menuEliminarVehiculo(centroLogistico);
                            break;
                        case 0:
                            break;
                        case -1:
                            op2=0;
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            break;
                        }
                        if(op2!=0)
                            presionarEnterYLimpiarPantalla();
                    } while(op2!=0);
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


                        switch(op2)
                        {
                        case 1:
                            menuModificarPaquete(centroLogistico);
                            break;
                        case 2:
                            menuModificarPersona(centroLogistico,false);
                            break;
                        case 3:
                            menuModificarPersona(centroLogistico,true);
                            break;
                        case 4:
                            menuModificarVehiculo(centroLogistico);
                            break;
                        case 0:
                            break;
                        case -1:
                            op2=0;
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            break;
                        }
                        if(op2!=0)
                            presionarEnterYLimpiarPantalla();
                    } while(op2!=0);
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
                            op2=0;
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            break;
                        }
                        if(op2!=0)
                            presionarEnterYLimpiarPantalla();
                    } while(op2!=0);
                    break;
                case 0:
                    //guardar lista de clientes / choferes;
                    //guardar repartos;

                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    presionarEnterYLimpiarPantalla();
                    break;
                }
            } while(op1!=0);
            break;
        case 2:
            printf("Seccion de repartos\n\n");

            printf("1. Repartos abiertos\n");
            printf("2. Repartos cerrados\n");
            printf("0. Volver\n");
            printf("-1. MENU PRINCIPAL\n");
            printf("\n-----------------------------------------\n\n");

            printf("Elija una opcion: ");
            scanf("%d", &op2);
            limpiarBufferTeclado();
            switch(op2)
            {
                case 1:
                    do
                    {
                        printf("Repartos abiertos\n");

                        printf("1. Armar reparto\n");
                        printf("2. Eliminar reparto\n"); //Borramos su existencia (cerrados y abiertos)
                        printf("3. Mostrar repartos\n"); //Plural
                        printf("4. Buscar reparto\n"); //Particular
                        printf("5. Cerrar un reparto\n");//Lo cambiamos de lista de abierto a cerrado
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL\n");
                        printf("\n-----------------------------------------\n\n");

                        printf("Elija una opcion: ");
                        scanf("%d", &op3);
                        limpiarBufferTeclado();
                    switch(op3)
                    {
                        case 1:
                            menuArmarReparto(centroLogistico);
                        break;
                        case 2:
                            menuEliminarReparto(centroLogistico, true);
                        break;
                        case 3:
                            mostrarRepartos(centroLogistico, true);
                        break;
                        case 4:
                            menuMostrarEntregasReparto(centroLogistico, true);
                        break;
                        case 5:
                            menuCerrarReparto(centroLogistico);
                        break;

                        default:
                        printf("\nOpcion incorrecta.\n\n");
                        presionarEnterYLimpiarPantalla();
                        break;
                    }
                } while(op3!=0);
            break;

            case 2:
                    do
                    {
                        printf("Repartos cerrados\n");

                        printf("1. Armar reparto\n");
                        printf("2. Eliminar reparto\n"); //Borramos su existencia (cerrados y abiertos)
                        printf("3. Mostrar repartos\n"); //Plural
                        printf("4. Buscar reparto\n"); //Particular
                        printf("5. Cerrar un reparto\n");//Lo cambiamos de lista de abierto a cerrado
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL\n");
                        printf("\n-----------------------------------------\n\n");

                        printf("Elija una opcion: ");
                        scanf("%d", &op3);
                        limpiarBufferTeclado();
                    switch(op3)
                    {
                        case 1:
                            menuArmarReparto(centroLogistico);
                        break;
                        case 2:
                            menuEliminarReparto(centroLogistico, true);
                        break;
                        case 3:
                            mostrarRepartos(centroLogistico, true);
                        break;
                        case 4:
                            menuMostrarEntregasReparto(centroLogistico, true);
                        break;
                        case 5:
                            menuCerrarReparto(centroLogistico);
                        break;

                        default:
                        printf("\nOpcion incorrecta.\n\n");
                        presionarEnterYLimpiarPantalla();
                        break;
                    }
                } while(op3!=0);
            break;
            }
        break;
        case 3:
            printf("Seccion de repartos\n\n");

            printf("1. Repartos abiertos\n");
            printf("2. Repartos cerrados\n");
            printf("0. Volver\n");
            printf("-1. MENU PRINCIPAL\n");
            printf("\n-----------------------------------------\n\n");

            printf("Elija una opcion: ");
            scanf("%d", &op2);
            limpiarBufferTeclado();
            switch(op2)
            {
            case 1:
                menuActualizarReparto(centroLogistico, true);
                break;
            case 2:
                menuActualizarReparto(centroLogistico, false);
                break;
            }
            break;
        case 4:
            do
            {
                printf("EMITIR LISTADOS DE:\n\n");

                printf("1. Paquetes\n");
                printf("2. Clientes\n");
                printf("3. Choferes\n");
                printf("4. Vehiculos\n");
                printf("5. Repartos - ABIERTOS\n");
                printf("6. Repartos - CERRADOS\n");
                printf("0. Volver\n");
                printf("\n-----------------------------------------\n\n");

                printf("Elija una opcion: ");
                scanf("%d",&op1);
                limpiarBufferTeclado();

                system("cls");
                switch(op1)
                {
                case 1:
                    printf("Mostrar paquetes como:\n\n");

                    printf("1. Universal\n");
                    printf("2. En curso\n");
                    printf("0. Volver\n");
                    printf("\n-----------------------------------------\n\n");

                    printf("Elija una opcion: ");
                    scanf("%d",&op2);
                    limpiarBufferTeclado();

                    switch(op2)
                    {
                    case 1:
                        mostrarPaquetes(centroLogistico);
                        break;
                    case 2:
                        filtrarPaquetes(centroLogistico, 1);
                        filtrarPaquetes(centroLogistico, 2);
                        break;
                    }

                    break;
                case 2:
                    printf("EMITIENDO LISTADO DE CLIENTES\n\n");
                    mostrarClientes(centroLogistico);
                    break;
                case 3:
                    printf("EMITIENDO LISTADO DE CHOFERES\n\n");
                    mostrarChoferes(centroLogistico);
                    break;
                case 4:
                    printf("EMITIENDO LISTADO DE VEHICULOS\n\n");
                    mostrarVehiculos(centroLogistico);
                    break;
                case 5:
                        printf("Mostrar repartos en formato:\n\n");
                        printf("1. Particular\n");
                        printf("2. Universal\n");
                        printf("0. Volver\n");
                        printf("\n-----------------------------------------\n\n");

                        printf("Elija una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();

                        switch(op2)
                        {
                        case 1:
                            menuMostrarEntregasReparto(centroLogistico, true);
                            break;
                        case 2:
                            mostrarRepartos(centroLogistico, true);
                            break;
                        }
                    break;
                case 6:
                        printf("Mostrar repartos en formato:\n\n");
                        printf("1. Particular\n");
                        printf("2. Universal\n");
                        printf("0. Volver\n");
                        printf("\n-----------------------------------------\n\n");

                        printf("Elija una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();

                        switch(op2)
                        {
                        case 1:
                            menuMostrarEntregasReparto(centroLogistico, false);
                            break;
                        case 2:
                            mostrarRepartos(centroLogistico, false);
                            break;
                        }
                case 0:
                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    break;
                }
                if(op1!=0)
                    presionarEnterYLimpiarPantalla();
            } while(op1!=0);
            break;
        case 5:
            break;
        case 0:
            do
            {
                system("cls");
                printf("Tiene cambios sin guardar. Seguro que quiere salir?\n\n");

                printf("1. Guardar cambios y salir\n");
                printf("2. Salir sin guardar\n");
                printf("0. Volver\n\n");

                printf("Seleccione una opcion: ");
                scanf("%d",&op1);

                switch(op1)
                {
                case 1:
                    guardarTodo(centroLogistico);
                    break;
                case 2:
                    presionarEnterYLimpiarPantalla();
                    break;
                case 0:
                    MAIN_OP=1; //Cambiamos el valor para evitar que salga el programa. No pasa nada, luego se espera a que el usuario ingrese una opcion.
                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    presionarEnterYLimpiarPantalla();
                    break;
                }
            } while(op1!=0 && op1!=1 && op1!=2);
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }
    } while(MAIN_OP!=0);

    return MAIN_OP; //salimos de todo el programa
}

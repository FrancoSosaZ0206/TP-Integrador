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
    int

    int n=0;
    bool res;

    ///NO ESTOY SEGURO DE SI VAN O NO
    //Datos por defecto
    CentroLogisticoPtr datosPorDefecto = crearCentroLogisticoRapido("DATOS POR DEFECTO");

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
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            break;
                        }
                        if(op2!=0 && op2!=-1) //A menos que elija volver,
                            presionarEnterYLimpiarPantalla(); //hacemos esto
                    } while(op2!=0 && op2!=-1);
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
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            break;
                        }
                        if(op2!=0 && op2!=-1)
                            presionarEnterYLimpiarPantalla();
                    } while(op2!=0 && op2!=-1);
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
                            op1=0; //reseteamos esta opcion tambien para que no vuelva al menu anterior, sino al ppal (el de "op")
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            break;
                        }
                        if(op2!=0 && op2!=-1)
                            presionarEnterYLimpiarPantalla();
                    } while(op2!=0 && op2!=-1);
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
                            printf("\nOpcion incorrecta.\n\n");
                            break;
                        }
                        if(op2!=0 && op2!=-1)
                            presionarEnterYLimpiarPantalla();
                    } while(op2!=0 && op2!=-1);
                    break;
                case 0:
                    do
                    {
                        printf("Guardar Cambios?\t1.SI\t0.NO\t");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();
                    } while(op2!=1 && op2!=0);
                    switch(op2)
                    {
                    case 1:
                        res = guardarListaPaquetes(centroLogistico);
                        res = res && guardarListaPersonas(centroLogistico);
                        res = res && guardarListaVehiculos(centroLogistico);
                        if(res)
                            printf("\n\nCambios guardados exitosamente.\n\n");
                        else
                            printf("\n\nERROR AL GUARDAR.\n\n");
                        break;
                    case 0:
                        break;
                    }
                    presionarEnterYLimpiarPantalla();
                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    break;
                }
                presionarEnterYLimpiarPantalla();
            } while(op1!=0);
            break;
        case 2:
            break;
        case 3:
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
                    printf("EMITIENDO LISTADO DE PAQUETES\n\n");
                    mostrarPaquetes(centroLogistico);
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
                    menuMostrarRepartos(centroLogistico,true);
                    break;
                case 6:
                    menuMostrarRepartos(centroLogistico,false);
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
            do
            {
                printf("GUARDAR CAMBIOS\n\n");

                printf("1. Listas del Centro Logistico\n");
                printf("2. Datos por Defecto\n");
                printf("0. Volver\n");
                printf("\n-----------------------------------------\n\n");
                printf("Elija una opcion: ");
                scanf("%d",&op1);

                limpiarBufferTeclado();
                system("cls");
                switch(op1)
                {
                case 1:
                    do
                    {
                        printf("GUARDAR LISTAS DEL CENTRO LOGISTICO\n\n");

                        printf("1. Lista de Paquetes\n");
                        printf("2. Lista de Personas\n");
                        printf("3. Lista de Vehiculos\n");
                        printf("4. Lista de Repartos Abiertos\n");
                        printf("5. Lista de Repartos Cerrados\n");
                        printf("6. TODAS LAS LISTAS\n");
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
                            if(guardarListaPaquetes(centroLogistico))
                                printf("Lista de Paquetes guardada exitosamente.\n\n");
                            else
                            {
                                printf("ERROR AL GUARDAR\n\n");
                                exit(1);
                            }
                            break;
                        case 2:
                            if(guardarListaPersonas(centroLogistico))
                                printf("Lista de Personas guardada exitosamente.\n\n");
                            else
                            {
                                printf("ERROR AL GUARDAR\n\n");
                                exit(1);
                            }
                            break;
                        case 3:
                            if(guardarListaVehiculos(centroLogistico))
                                printf("Lista de Vehiculos guardada exitosamente.\n\n");
                            else
                            {
                                printf("ERROR AL GUARDAR\n\n");
                                exit(1);
                            }
                            break;
                        case 4:
                            if(guardarListaRepartos(centroLogistico,true))
                                printf("Lista de Repartos Abiertos guardada exitosamente.\n\n");
                            else
                            {
                                printf("ERROR AL GUARDAR\n\n");
                                exit(1);
                            }
                            break;
                        case 5:
                            if(guardarListaRepartos(centroLogistico,false))
                                printf("Lista de Repartos Cerrados guardada exitosamente.\n\n");
                            else
                            {
                                printf("ERROR AL GUARDAR\n\n");
                                exit(1);
                            }
                            break;
                        case 6:
                            if(guardarTodo(centroLogistico))
                                printf("Todas las listas han sido guardadas exitosamente.\n\n");
                            else
                            {
                                printf("ERROR AL GUARDAR\n\n");
                                exit(1);
                            }
                            break;
                        case 0:
                            break;
                        case -1:
                            op1=0;
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            break;
                        }
                        if(op2!=0 && op2!=-1)
                            presionarEnterYLimpiarPantalla();
                    } while(op2!=0 && op2!=-1);
                    break;
                case 2:
                    do
                    {
                        printf("GUARDAR DATOS POR DEFECTO\n\n");
                        printf("1. Paquetes\n");
                        printf("2. Personas\n");
                        printf("3. Vehiculos\n");
                        printf("4. Repartos\n");
                        printf("5. TODOS LOS DATOS POR DEFECTO\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL\n");
                        printf("\n-----------------------------------------\n\n");
                        printf("Elija una opcion: ");
                        scanf("%d",&op2);

                        limpiarBufferTeclado();
                        switch(op2)
                        {
                        case 1:
                            do
                            {
                                printf("Ingrese la cantidad de Paquetes a guardar: ");
                                scanf("%d",&n);
                                limpiarBufferTeclado();
                                if(n<1)
                                    printf("\n\nERROR: cantidad incorrecta. Vuelva a ingresarla.\n");
                            } while(n<1);

                            if(guardarPaquetes(datosPorDefecto))
                                printf("Paquetes por defecto guardados exitosamente.\n\n");
                            else
                            {
                                printf("ERROR AL GUARDAR\n\n");
                                exit(1);
                            }
                            break;
                        case 2:
                            do
                            {
                                printf("Ingrese la cantidad de Personas a guardar: ");
                                scanf("%d",&n);
                                limpiarBufferTeclado();
                                if(n<1)
                                    printf("\n\nERROR: cantidad incorrecta. Vuelva a ingresarla.\n");
                            } while(n<1);

                            if(guardarPersonas(datosPorDefecto))
                                printf("Personas por defecto guardadas exitosamente.\n\n");
                            else
                            {
                                printf("ERROR AL GUARDAR\n\n");
                                exit(1);
                            }
                            break;
                        case 3:
                            do
                            {
                                printf("Ingrese la cantidad de Vehiculos a guardar: ");
                                scanf("%d",&n);
                                limpiarBufferTeclado();
                                if(n<1)
                                    printf("\n\nERROR: cantidad incorrecta. Vuelva a ingresarla.\n");
                            } while(n<1);

                            if(guardarVehiculos(datosPorDefecto))
                                printf("Vehiculos por defecto guardados exitosamente.\n\n");
                            else
                            {
                                printf("ERROR AL GUARDAR\n\n");
                                exit(1);
                            }
                            break;
                        case 4:
                            do
                            {
                                printf("Ingrese la cantidad de repartos a guardar: ");
                                scanf("%d",&n);
                                limpiarBufferTeclado();
                                if(n<1)
                                    printf("\n\nERROR: cantidad incorrecta. Vuelva a ingresarla.\n");
                            } while(n<1);

                            if(guardarRepartos(datosPorDefecto,true) && guardarRepartos(datosPorDefecto,false))
                                printf("Repartos por defecto guardados exitosamente.\n\n");
                            else
                            {
                                printf("ERROR AL GUARDAR\n\n");
                                exit(1);
                            }
                            break;
                        case 5:
                            if(guardarTodoPorDefecto(datosPorDefecto))
                                printf("Todos los datos por defecto han sido guardados exitosamente.\n\n");
                            else
                            {
                                printf("ERROR AL GUARDAR\n\n");
                                exit(1);
                            }
                            break;
                        case 0:
                            break;
                        case -1:

                            op1=0;
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            break;
                        }
                        if(op2!=0 && op2!=-1)
                            presionarEnterYLimpiarPantalla();
                    } while(op2!=0 && op2!=-1);
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    break;
                }
                presionarEnterYLimpiarPantalla();
            } while(op1!=0);
            break;
        case 0:
            do
            {
                printf("Es posible que tenga cambios sin guardar. Seguro que quiere salir?\n\n");

                printf("1. Guardar y salir\n");
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
            break;
        }
        presionarEnterYLimpiarPantalla();
    } while(MAIN_OP!=0);

    return MAIN_OP; //salimos de todo el programa
}

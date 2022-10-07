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

int deseaGuardarAntesDeSalir()
{
    int eleccion=0;
    do{
        system("cls");
        fflush(stdin);
        printf("Seccion seguro ACTIVADA\n");
        printf("Desea guardar antes de salir?\n");
        printf("1. Guardar cambios y salir\n");
        printf("2. Salir sin guardar cambios\n");
        printf("Eleccion: ");
        scanf("%d",&eleccion);
        fflush(stdin);
    }while(eleccion<1 && eleccion>2);
    return eleccion;
}

int MAIN_MENU(CentroLogisticoPtr centroLogistico);

int main()
{
    CentroLogisticoPtr centroLogistico;
    ListaPtr listaClientes = crearLista();
    ListaPtr listaVehiculos = crearLista();
    ListaPtr listaChoferes = crearLista();
    ListaPtr listaPaquetes = crearLista();
    listaChoferes=crearListaChoferesGenerico();
    listaClientes=crearListaClientesGenerico();
    listaVehiculos=crearListaVehiculosGenerico();
    listaPaquetes=crearListaPaquetesGenerico();

    for(int i=0;i<longitudLista(listaChoferes);i++){
        printf("%d.",i);
        mostrarPersona((PersonaPtr)getDatoLista(listaChoferes,i));
    }


    system("pause");
    int START_OP=0;
    do{
        system("cls");
        fflush(stdin);
        printf("START MENU - BIENVENIDO\n\n");
        printf("\t1. INICIAR DE CERO\n");
        printf("\t2. ABRIR ARCHIVOS\n");
        printf("\t0. SALIR\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&START_OP);
        fflush(stdin);
        system("cls");
        switch(START_OP){
        case 1:
            centroLogistico=menuCrearNuevoCtroLogRapido(centroLogistico);
            centroLogistico=setPaquetes(centroLogistico,listaPaquetes);
            //centroLogistico=setPersonas(centroLogistico,listaChoferes);
            centroLogistico=setClientes(centroLogistico,listaClientes);
            centroLogistico=setChoferes(centroLogistico,listaChoferes);
            centroLogistico=setVehiculos(centroLogistico,listaVehiculos);
            START_OP = MAIN_MENU(centroLogistico);
            //centroLogistico=destruirCentroLogistico(centroLogistico);
            break;
        case 2:
            centroLogistico = abrirTodo();
            if(centroLogistico==NULL){
                printf("ERROR AL ABRIR.\n\n");
                exit(1);
            }else{
                START_OP = MAIN_MENU(centroLogistico);
                //centroLogistico=destruirCentroLogistico(centroLogistico);
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
    bool resultadoGuardadoGeneral;
    int MAIN_OP=0,op1=0,op2=0,op3=0,op4=0,op5=0,op6=0;///Para cada Sub Menu
    do{
        system("cls");
        fflush(stdin);
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
        fflush(stdin);
        switch(MAIN_OP){
        case 1:
            do{
                system("cls");
                fflush(stdin);
                printf("BASE DE DATOS\n\n");
                printf("1. Cargar Datos\n");
                printf("2. Eliminar Datos\n");
                printf("3. Modificar Datos\n");
                printf("4. Buscar Datos\n");
                printf("0. Volver\n");
                printf("\n-----------------------------------------\n\n");
                printf("Elija una opcion: ");
                scanf("%d", &op2);
                fflush(stdin);
                system("cls");
                switch(op2){
                case 1:
                    do{
                        printf("CARGAR DATOS\n\n");
                        printf("1. Cargar paquete\n");
                        printf("2. Cargar cliente\n");
                        printf("3. Cargar chofer\n");
                        printf("4. Cargar vehiculo\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL\n");
                        printf("\n-----------------------------------------\n\n");
                        printf("Elija una opcion: ");
                        scanf("%d", &op3);
                        fflush(stdin);
                        switch(op3){
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
                        if(op3!=0) //A menos que elija volver,
                            system("cls"); //hacemos esto
                    } while(op3!=0);
                    break;
                case 2:
                    do{
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
                        fflush(stdin);
                        switch(op2){
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
                    do{
                        printf("MODIFICAR DATOS\n\n");
                        printf("1. Modificar Paquete\n");
                        printf("2. Modificar Cliente\n");
                        printf("3. Modificar Chofer\n");
                        printf("4. Modificar Vehiculo\n");
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL\n");
                        printf("\n-----------------------------------------\n\n");
                        fflush(stdin);
                        printf("Elija una opcion: ");
                        scanf("%d",&op2);
                        fflush(stdin);
                        switch(op2){
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
                    do{
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
                        fflush(stdin);
                        switch(op2){
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
                    }while(op2!=0);
                    break;
                case 0:
                    /*op2=deseaGuardarAntesDeSalir();
                    switch(op2){
                    case 1:
                        guardarListaRepartos(centroLogistico,true);
                        break;
                    case 2:
                        break;
                    }
                    break;*/
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    presionarEnterYLimpiarPantalla();
                    break;
                }
            }while(op2!=0);
            break;
        case 2:
            system("cls");
            fflush(stdin);
            printf("Seccion de repartos\n\n");
            printf("1. Repartos abiertos\n");
            printf("2. Repartos cerrados\n");
            printf("0. Volver\n");
            printf("-1. MENU PRINCIPAL\n");
            printf("\n-----------------------------------------\n\n");
            printf("Elija una opcion: ");
            scanf("%d", &op2);
            fflush(stdin);
            switch(op2){
                case 1:
                    do{
                        system("cls");
                        fflush(stdin);
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
                        system("cls");
                        fflush(stdin);
                    switch(op3){
                        case 1:
                            fflush(stdin);
                            menuArmarReparto(centroLogistico);
                            system("cls");
                            mostrarRepartos(centroLogistico,true);
                            system("pause");
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
                        case 0:
                            /*op2=deseaGuardarAntesDeSalir();
                            switch(op2){
                            case 1:
                                guardarListaRepartos(centroLogistico,true);
                                break;
                            case 2:
                                break;
                            }
                            break;*/

                        default:
                        printf("\nOpcion incorrecta.\n\n");
                        presionarEnterYLimpiarPantalla();
                        break;
                    }
                }while(op3!=0);
            break;

            case 2:
                    do
                    {
                        printf("Repartos cerrados\n");
                        printf("1. Eliminar reparto\n"); //Borramos su existencia (cerrados y abiertos)
                        printf("2. Mostrar repartos\n"); //Plural
                        printf("3. Buscar reparto\n"); //Particular
                        printf("0. Volver\n");
                        printf("-1. MENU PRINCIPAL\n");
                        printf("\n-----------------------------------------\n\n");

                        printf("Elija una opcion: ");
                        scanf("%d", &op3);
                        limpiarBufferTeclado();
                    switch(op3)
                    {
                        case 1:
                            menuEliminarReparto(centroLogistico, true);
                        break;
                        case 2:
                            mostrarRepartos(centroLogistico, true);
                        break;
                        case 3:
                            menuMostrarEntregasReparto(centroLogistico, true);
                        break;
                        case 0:
                            /*op2=deseaGuardarAntesDeSalir();
                            switch(op2){
                            case 1:
                                guardarListaRepartos(centroLogistico,true);
                                break;
                            case 2:
                                break;
                            }
                            break;*/
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
            menuActualizarReparto(centroLogistico);
                //case 0:
                    /*op2=deseaGuardarAntesDeSalir();
                    switch(op2){
                    case 1:
                        guardarListaRepartos(centroLogistico,true);
                        guardarListaRepartos(centroLogistico,false);
                        break;
                    case 2:
                        break;
                    }
                    break;*/
               // }
            //}while(op2!=0);
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
                fflush(stdin);
                printf("Elija una opcion: ");
                scanf("%d",&op2);
                fflush(stdin);
                system("cls");
                switch(op2){
                case 1:
                    printf("Mostrar paquetes como:\n\n");
                    printf("1. Universal\n");
                    printf("2. En curso\n");
                    printf("0. Volver\n");
                    printf("\n-----------------------------------------\n\n");
                    fflush(stdin);
                    printf("Elija una opcion: ");
                    scanf("%d",&op3);
                    fflush(stdin);
                    switch(op3){
                    case 1:
                        mostrarPaquetes(centroLogistico);
                        system("pause");
                        break;
                    case 2:
                        filtrarPaquetes(centroLogistico, 1);
                        filtrarPaquetes(centroLogistico, 2);
                        system("pause");
                        break;
                    }
                    break;
                case 2:
                    printf("EMITIENDO LISTADO DE CLIENTES\n\n");
                    mostrarClientes(centroLogistico);
                    system("pause");
                    break;
                case 3:
                    printf("EMITIENDO LISTADO DE CHOFERES\n\n");
                    mostrarChoferes(centroLogistico);
                    system("pause");
                    break;
                case 4:
                    printf("EMITIENDO LISTADO DE VEHICULOS\n\n");
                    mostrarVehiculos(centroLogistico);
                    system("pause");
                    break;
                case 5:
                        printf("Mostrar repartos en formato:\n\n");
                        printf("1. Particular\n");
                        printf("2. Universal\n");
                        printf("0. Volver\n");
                        printf("\n-----------------------------------------\n\n");
                        printf("Elija una opcion: ");
                        scanf("%d",&op3);
                        fflush(stdin);
                        switch(op3){
                        case 1:
                            menuMostrarEntregasReparto(centroLogistico, true);
                            system("pause");
                            break;
                        case 2:
                            mostrarRepartos(centroLogistico, true);
                            system("pause");
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
                        fflush(stdin);
                        switch(op2){
                        case 1:
                            menuMostrarEntregasReparto(centroLogistico, false);
                            system("pause");
                            break;
                        case 2:
                            mostrarRepartos(centroLogistico, false);
                            system("pause");
                            break;
                        }
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    break;
                }
                if(op1!=0)
                    presionarEnterYLimpiarPantalla();
            } while(op1!=0);
            break;
        case 5:
            resultadoGuardadoGeneral=guardarTodo(centroLogistico);
            if(resultadoGuardadoGeneral==false){
                printf("No se han podido guardar los datos\n");
                printf("Es muy probable que la funcion GUARDAR_TODO\n");
                printf("Este funcionando incorrectamente\n");
                printf("Dirigase a solucionarlo\n");
                exit(1);
            }
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
                switch(op1){
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
            system("cls");
            break;
        }
    } while(MAIN_OP!=0);

    return MAIN_OP; //salimos de todo el programa
}

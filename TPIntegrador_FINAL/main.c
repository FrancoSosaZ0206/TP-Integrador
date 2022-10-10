#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Lista.h"
#include "Pila.h"
#include "TDACentroLogistico.h"
#include "TDACuil.h"
#include "TDADomicilio.h"
#include "TDAFechaYHora.h"
#include "TDANodo.h"
#include "TDAPaquetes.h"
#include "TDAPersona.h"
#include "TDARepartos.h"
#include "TDAVehiculo.h"
#include "Files.h"
#include "Menus.h"
#include "test.h"

/**
DIRECTORIOS (FRANCO S.)

Para crear y linkear archivos
E:\Franco\9. PROGRAMAS\GitHub\GitHub - Repositorios\TP-Integrador-Repositorio\TPIntegrador_FINAL\

Para abrir/guardar files = CARPETA "Archivos"
E:\Franco\9. PROGRAMAS\GitHub\GitHub - Repositorios\TP-Integrador-Repositorio\Archivos\
*/

int menuPrincipal();

int MAIN_MENU(CentroLogisticoPtr centroLogistico);

int menuTipoListado();

int menuTipoListadoPaquete();

int menuListados();

int menuRepartosCerrados();

int menuRepartos();

int menuSeleccionTipoRepartos();

int menuBusquedaDatos();

int menuModificarDatos();

int menuEliminarDatos();

int menuCargadoDatos();

int menuBaseDatos();

int menuCentroLogistico(CentroLogisticoPtr centroLogistico);

int menuGuardadoRespaldo();

int deseaGuardarAntesDeSalir();

///--------------------------------------------------------------------------------------------------------------///
///--------------------------------------------------------------------------------------------------------------///
///--------------------------------------------------------------------------------------------------------------///
///--------------------------------------------------------------------------------------------------------------///
///--------------------------------------------------------------------------------------------------------------///

int main(){
    CentroLogisticoPtr centroLogistico;
    ListaPtr listaClientes=crearListaClientesGenerico();
    ListaPtr listaVehiculos=crearListaVehiculosGenerico();
    ListaPtr listaRepartos=crearListaRepartosPorDefecto();
    ListaPtr listaChoferes=crearListaChoferesGenerico();
    ListaPtr listaPaquetes=crearListaPaquetesGenerico();
    ListaPtr listaRepartosCerrados=crearLista();
    int START_OP=0;
    do{
        START_OP=menuPrincipal();
        system("cls");
        switch(START_OP){
            case 1:
                centroLogistico=crearCentroLogistico("Distribuidora",listaPaquetes,listaClientes,listaChoferes,listaVehiculos,listaRepartos,listaRepartosCerrados);
                START_OP=MAIN_MENU(centroLogistico);
                centroLogistico=destruirCentroLogistico(centroLogistico);
            break;
            case 2:
                centroLogistico=AbrirTodoNuevo();
                if(centroLogistico==NULL){
                    printf("ERROR AL ABRIR.\n\n");
                    exit(1);
                }else{
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

int MAIN_MENU(CentroLogisticoPtr centroLogistico){
    ///Menúes
    bool resultadoGuardadoGeneral;
    int MAIN_OP=0,op1=0,op2=0,op3=0;///Para cada Sub Menu
    do{
        system("cls");
        MAIN_OP=menuCentroLogistico(centroLogistico);
            switch(MAIN_OP){
                case 1:
                    do{
                        system("cls");
                        op1=menuBaseDatos();
                        switch(op1){
                            case 1:
                                do{
                                    system("cls");
                                    op2=menuCargadoDatos();
                                switch(op2){
                                    case 1:
                                        menuCargarPaquete(centroLogistico);
                                        break;
                                    case 2:
                                        menuCargarCliente(centroLogistico);
                                        break;
                                    case 3:
                                        menuCargarChofer(centroLogistico);
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
                                    system("cls"); //hacemos esto
                            } while(op2!=0);
                            break;
                        case 2:
                            do{
                                op2=menuEliminarDatos();
                                switch(op2){
                                    case 1:
                                        menuEliminarPaquete(centroLogistico);
                                        break;
                                    case 2:
                                        menuEliminarCliente(centroLogistico);
                                        break;
                                    case 3:
                                        menuEliminarChofer(centroLogistico);
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
                                op2=menuModificarDatos();
                                switch(op2){
                                    case 1:
                                        menuModificarPaquete(centroLogistico);
                                        break;
                                    case 2:
                                        menuModificarCliente(centroLogistico);
                                        break;
                                    case 3:
                                        menuModificarChofer(centroLogistico);
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
                                op2=menuBusquedaDatos();
                                switch(op2){
                                    case 1:
                                        menuBuscarPaquete(centroLogistico);
                                        break;
                                    case 2:
                                        menuBuscarCliente(centroLogistico);
                                        break;
                                    case 3:
                                        menuBuscarChofer(centroLogistico);
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
                            break;
                        default:
                                printf("\nOpcion incorrecta.\n\n");
                                presionarEnterYLimpiarPantalla();
                            break;
                        }
                    }while(op1!=0);
                    break;
                    case 2:
                        do{
                        system("cls");
                        op2=menuSeleccionTipoRepartos();
                            switch(op2){
                                case 1:
                                    do{
                                        system("cls");
                                        op3=menuRepartos();
                                    switch(op3){
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
                                        case 0:
                                            break;
                                        default:
                                            printf("\nOpcion incorrecta.\n\n");
                                            presionarEnterYLimpiarPantalla();
                                        break;
                                    }
                            }while(op3!=0);
                            break;

                            case 2:
                                    do{
                                    op3=menuRepartosCerrados();
                                    switch(op3){
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
                                            break;
                                        default:
                                                printf("\nOpcion incorrecta.\n\n");
                                                presionarEnterYLimpiarPantalla();
                                            break;
                                    }
                            }while(op3!=0);
                            break;
                        }
                    }while(op2!=0);
                break;

                case 3:
                    menuActualizarReparto(centroLogistico);
                break;

                case 4:
                    do{
                        op2=menuListados();
                        system("cls");
                        switch(op2){
                            case 1:
                                op3=menuTipoListadoPaquete();
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
                                    mostrarClientes(centroLogistico);
                                    system("pause");
                                break;
                            case 3:
                                    mostrarChoferes(centroLogistico);
                                    system("pause");
                                break;
                            case 4:
                                    mostrarVehiculos(centroLogistico);
                                    system("pause");
                                break;
                            case 5:
                                    op3=menuTipoListado();
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
                                    op2=menuTipoListado();
                                    system("cls");
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
                    break;
                    case 5:
                            GuardarTodoNuevo(centroLogistico);
                    break;
                } while(op2!=0);
                break;
                case 0:
                    do{
                        system("cls");
                        op1=menuGuardadoRespaldo();
                            switch(op1){
                            case 1:
                                    GuardarTodoNuevo(centroLogistico);
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
    return MAIN_OP;
}



///--------------------------------------------------------------------------------------------------------------///
///--------------------------------------------------------------------------------------------------------------///
///--------------------------------------------------------------------------------------------------------------///
///--------------------------------------------------------------------------------------------------------------///
///--------------------------------------------------------------------------------------------------------------///


int menuPrincipal(){
    int eleccion;
    limpiarBufferTeclado();
    printf("START MENU - BIENVENIDO\n\n");
    printf("\t1. INICIAR DE CERO\n");
    printf("\t2. ABRIR ARCHIVOS\n");
    printf("\t0. SALIR\n\n");
    printf("Seleccione una opcion: ");
    scanf("%d",&eleccion);
    limpiarBufferTeclado();
    return eleccion;
}


///--------------------------------------------------------------------------------------------------------------///
///--------------------------------------------------------------------------------------------------------------///
///--------------------------------------------------------------------------------------------------------------///
///--------------------------------------------------------------------------------------------------------------///
///--------------------------------------------------------------------------------------------------------------///


int menuCentroLogistico(CentroLogisticoPtr centroLogistico){
    int eleccion;
    limpiarBufferTeclado();
    printf("CENTRO LOGISTICO '%s' - MENU PRINCIPAL\n\n",getNombreCentroLogistico(centroLogistico));
    printf("1. BASE DE DATOS\n");
    printf("2. REPARTOS\n");
    printf("3. VER RESULTADOS DE ENTREGAS\n");
    printf("4. EMITIR LISTADOS\n");
    printf("5. GUARDAR CAMBIOS\n"); ///NUEVO
    printf("0. SALIR\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuBaseDatos(){
    int eleccion;
    limpiarBufferTeclado();
    printf("BASE DE DATOS\n\n");
    printf("1. Cargar Datos\n");
    printf("2. Eliminar Datos\n");
    printf("3. Modificar Datos\n");
    printf("4. Buscar Datos\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuCargadoDatos(){
    int eleccion;
    limpiarBufferTeclado();
    printf("CARGAR DATOS\n\n");
    printf("1. Cargar paquete\n");
    printf("2. Cargar cliente\n");
    printf("3. Cargar chofer\n");
    printf("4. Cargar vehiculo\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuEliminarDatos(){
    int eleccion;
    limpiarBufferTeclado();
    printf("ELIMINAR DATOS\n\n");
    printf("1. Eliminar Paquete\n");
    printf("2. Eliminar Cliente\n");
    printf("3. Eliminar Chofer\n");
    printf("4. Eliminar Vehiculo\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    scanf("%d",&eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuModificarDatos(){
    int eleccion;
    printf("MODIFICAR DATOS\n\n");
    printf("1. Modificar Paquete\n");
    printf("2. Modificar Cliente\n");
    printf("3. Modificar Chofer\n");
    printf("4. Modificar Vehiculo\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    limpiarBufferTeclado();
    printf("Elija una opcion: ");
    scanf("%d",&eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuBusquedaDatos(){
    int eleccion;
    limpiarBufferTeclado();
    printf("BUSCAR DATOS\n\n");
    printf("1. Buscar paquete\n"); //buscamos por ID
    printf("2. Buscar cliente\n"); //buscamos por
    printf("3. Buscar chofer\n"); //cuil
    printf("4. Buscar vehiculo\n"); //buscamos por patente
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuSeleccionTipoRepartos(){
    int eleccion;
    limpiarBufferTeclado();
    printf("Seccion de repartos\n\n");
    printf("1. Repartos abiertos\n");
    printf("2. Repartos cerrados\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuRepartos(){
    int eleccion;
    limpiarBufferTeclado();
    printf("Repartos abiertos\n");
    printf("1. Armar reparto\n");
    printf("2. Eliminar reparto\n"); //Borramos su existencia (cerrados y abiertos)
    printf("3. Mostrar repartos\n"); //Plural
    printf("4. Mostrar entregas reparto\n"); //Particular
    printf("5. Cerrar un reparto\n");//Lo cambiamos de lista de abierto a cerrado
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuRepartosCerrados(){
    int eleccion;
    limpiarBufferTeclado();
    printf("Repartos cerrados\n");
    printf("1. Eliminar reparto\n"); //Borramos su existencia (cerrados y abiertos)
    printf("2. Mostrar repartos\n"); //Plural
    printf("3. Buscar reparto\n"); //Particular
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    scanf("%d", &eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuListados(){
    int eleccion;
    limpiarBufferTeclado();
    printf("EMITIR LISTADOS DE:\n\n");
    printf("1. Paquetes\n");
    printf("2. Clientes\n");
    printf("3. Choferes\n");
    printf("4. Vehiculos\n");
    printf("5. Repartos - ABIERTOS\n");
    printf("6. Repartos - CERRADOS\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    limpiarBufferTeclado();
    printf("Elija una opcion: ");
    scanf("%d",&eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuTipoListadoPaquete(){
    int eleccion;
    limpiarBufferTeclado();
    printf("Mostrar paquetes como:\n\n");
    printf("1. Universal\n");
    printf("2. En curso\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    limpiarBufferTeclado();
    printf("Elija una opcion: ");
    scanf("%d",&eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuTipoListado(){
    int eleccion;
    printf("Mostrar repartos en formato:\n\n");
    printf("1. Particular\n");
    printf("2. Universal\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    scanf("%d",&eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int menuGuardadoRespaldo(){
    int eleccion;
    limpiarBufferTeclado();
    printf("Tiene cambios sin guardar. Seguro que quiere salir?\n\n");
    printf("1. Guardar cambios y salir\n");
    printf("2. Salir sin guardar\n");
    printf("0. Volver\n\n");
    printf("Seleccione una opcion: ");
    scanf("%d",&eleccion);
    limpiarBufferTeclado();
    return eleccion;
}


int deseaGuardarAntesDeSalir(){
    int eleccion=0;
    system("cls");
    limpiarBufferTeclado();
    printf("Seccion seguro ACTIVADA\n");
    printf("Desea guardar cambios antes de salir?\n");
    printf("1. Guardar cambios y salir\n");
    printf("2. Salir sin guardar cambios\n");
    printf("Eleccion: ");
    scanf("%d",&eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

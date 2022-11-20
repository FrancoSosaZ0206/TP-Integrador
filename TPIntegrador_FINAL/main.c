#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Files.h"
#include "Lista.h"
#include "Menus.h"
#include "test.h"
#include "util.h"


int MAIN_MENU(CentroLogisticoPtr centroLogistico,bool primeraVez);

int main()
{
/** **************************************************************************************************************
///                                             SECCIÓN DE PRUEBAS RÁPIDAS
/// **************************************************************************************************************

    CentroLogisticoPtr c = crearCentroLogisticoRapido("prueba");
    PersonaPtr chof1 = crearPersonaDirect("aaa","aaa","a",1,"a","20 43265222 0",true);
    PersonaPtr chof2 = crearPersonaDirect("bbb","bbb","b",2,"b","27 44389013 6",true);
    PersonaPtr chof3 = crearPersonaDirect("zzz","zzz","z",9,"z","23 58679636 4",true);
    PersonaPtr cli1 = crearPersonaDirect("ccc","ccc","c",1,"c","20 11238840 1",false);
    PersonaPtr cli2 = crearPersonaDirect("ddd","ddd","d",2,"d","27 33497693 4",false);

    agregarPersona(c,chof1);
    agregarPersona(c,cli2);
    agregarPersona(c,cli1);
    agregarPersona(c,chof2);
    agregarPersona(c,chof3);


    VehiculoPtr v = crearVehiculo(1,"Acme","Acme","BU 843 ZP");
    PaquetePtr paq = crearPaqueteDirect(200,1,2,3,4,"z",9,"z","zA",99,"zA",13,12,2022,10,45,1);
    PaquetePtr paq2 = crearPaqueteDirect(201,1,2,3,4,"a",9,"a","aaa",123,"aaa",13,12,2022,10,45,1);
    PaquetePtr paq3 = crearPaqueteDirect(202,1,2,3,4,"b",9,"b","bbb",66,"bbb",13,12,2022,10,45,1);
    PaquetePtr paq4 = crearPaqueteDirect(203,1,2,3,4,"c",9,"c","ccc",88,"ccc",13,12,2022,10,45,1);

    agregarVehiculo(c,v);
    agregarPaquete(c,paq);
    agregarPaquete(c,paq2);
    agregarPaquete(c,paq3);
    agregarPaquete(c,paq4);

    PilaPtr pPaq = crearPila();
    apilar(pPaq,(PaquetePtr)paq);

    FechaPtr fS = crearFecha(13,12,2022,9,30);
    FechaPtr fR = crearFecha(13,12,2022,18,36);

    RepartoPtr r = armarReparto(chof3,v,fS,fR,pPaq);
    agregarReparto(c,r,true);

    FechaPtr fS2 = crearFecha(13,12,2022,11,25);

    bool valido=false;
    int n=longitudLista(getPersonas(c));

    do
    {
        valido = false;
/// //////////////////////////////////////////// ///
        mostrarChoferesDisponibles(c,fS2);

        char strFecha[100];
        traerFechaCorta(fS2,strFecha);
        printf("\n\nFECHA DE SALIDA A ANALIZAR: %s\n\n",strFecha);

        int i=0;
        printf("\n\nSeleccione Chofer: ");
        scanf("%d",&i);

        PersonaPtr cE = (PersonaPtr)getDatoLista(getPersonas(c),i-1);

        if(i<0 || i>n)
            printf("\n\nIndice incorrecto.");
        else if(!getEsChofer(cE))
            printf("\n\nNo es un chofer.");
        else if(choferEnReparto(c,cE,fS2))
            printf("\n\nChofer en reparto.");
        else
        {
            valido=true;
            system("cls");
            printf("Chofer Valido!!\n\n\n");
            mostrarPersona(cE);
            system("pause");
        }
        if(!valido)
            presionarEnterYLimpiarPantalla();
    } while(!valido);
/// //////////////////////////////////////////// ///
    c=destruirCentroLogistico(c);
    return 0;

/// **************************************************************************************************************/
    CentroLogisticoPtr centroLogistico=NULL;
    int START_OP=0;
    do
    {
        printf("\t    MENU DE INICIO - BIENVENIDO");
        printf("\n\n\t-----------------------------------\n\n");
        printf("\t\t 1. REGISTRARSE\n");
        printf("\t\t 2. INICIAR SESION\n");
        printf("\t\t 3. SESION DE PRUEBAS\n");
        printf("\t\t 0. SALIR");
        printf("\n\n\t-----------------------------------\n\n");
        printf("\t       Seleccione una opcion\n\n\n\t\t\t");
        scanf("%d",&START_OP);

        limpiarBufferTeclado();

        system("cls");
        switch(START_OP)
        {
        case 1:
            centroLogistico=menuCrearNuevoCtroLogRapido(centroLogistico);
            system("cls");
            START_OP = MAIN_MENU(centroLogistico,true);
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
                START_OP = MAIN_MENU(centroLogistico,false);
                centroLogistico=destruirCentroLogistico(centroLogistico);
            }
            break;
        case 3:
            centroLogistico = crearCentroLogisticoDefecto();
            guardarPersonaPrueba( getDatoLista(getPersonas(centroLogistico), 0) );
            leerPersonaPrueba();
            system("pause");
            if(centroLogistico==NULL)
            {
                printf("ERROR: problema al crear centroLogistico por defecto.\n\n");
                exit(1);
            }
            else
            {
                START_OP = MAIN_MENU(centroLogistico,true);
                centroLogistico=destruirCentroLogistico(centroLogistico);
            }
            break;
        case 0:
            break;
        default:
            printf("Opcion incorrecta.");
            presionarEnterYLimpiarPantalla();
            break;
        }
    } while(START_OP!=0);

    printf("\t\tHasta pronto!\n\n");
    return 0;
}

int MAIN_MENU(CentroLogisticoPtr centroLogistico,bool primeraVez)
{
    ///Menúes
    int MAIN_OP = 0;
    int op1=0;
    int op2=0;

    bool cambiosGuardados=true; //Asumimos que no es verdad para que la opcion al salir no salga si no hacemos nada.

    if(primeraVez)
    {
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t   B   I   E   N   V   E   N   I   D   O\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\t\t\t\t********************************************\n");
        printf("\n\n\n\n\n\n\n\t\t\t\t  ");
        system("pause");
        system("cls");
    }
    else
        actualizarRepartos(centroLogistico);

    do
    {
        printf("CENTRO LOGISTICO '%s' - MENU PRINCIPAL",getNombreCentroLogistico(centroLogistico));
        printf("\n\n-----------------------------------------\n\n");
        printf("1. BASE DE DATOS\n");
        printf("2. REPARTOS\n");
        printf("3. INDICAR RESULTADOS DE ENTREGAS\n");
        printf("4. EMITIR LISTADOS\n");
        printf("5. GUARDAR CAMBIOS\n");
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
                printf("1. Armar reparto\n"); ///Esta es solo para repartos abiertos
                printf("2. Eliminar reparto\n");
                printf("3. Modificar reparto\n");
                printf("4. Buscar reparto\n");
                printf("0. Volver");
                printf("\n\n-----------------------------------------\n\n");
                printf("Elija una opcion: ");
                scanf("%d",&op1);

                limpiarBufferTeclado();
                system("cls");

                actualizarRepartos(centroLogistico);

                switch(op1)
                {
                case 1:
                    cambiosGuardados = menuArmarReparto(centroLogistico);
                    break;
                case 2:
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

                        actualizarRepartos(centroLogistico);

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
                case 3:
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
                        actualizarRepartos(centroLogistico);

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
                case 4:
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

                        actualizarRepartos(centroLogistico);

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

            actualizarRepartos(centroLogistico);

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
                    if(!primeraVez)
                        printf("Tiene cambios sin guardar. Seguro que quiere salir?");
                    else
                        printf("Su sesion aun no ha sido guardada. Podria perder todos sus datos. Seguro que quiere salir?");
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
                            printf("Cambios guardados exitosamente.\n\n");
                            if(primeraVez)
                            {
                                printf("*************************************************************************\n\n");
                                printf("Los datos de tu nueva sesion han sido guardados en la carpeta Archivos.\n\n");
                                printf("*************************************************************************\n\n\n");
                            }
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

        actualizarRepartos(centroLogistico);
    } while(MAIN_OP!=0);

    return MAIN_OP; //salimos de todo el programa
}

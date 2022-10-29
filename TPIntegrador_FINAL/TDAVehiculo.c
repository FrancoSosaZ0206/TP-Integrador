#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "TDAVehiculo.h"
#include "TDACentroLogistico.h"
#include "Lista.h"
#include "Menus.h"
#include "Files.h"
#include "util.h"

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE CREACION///
///-----------------------------------------------------------------------------------------------------------///

VehiculoPtr crearVehiculo(int tipo,char *marca,char *modelo,char *patente)
{
    VehiculoPtr vehiculo=(VehiculoPtr)obtenerMemoria(sizeof(Vehiculo));
    vehiculo->tipo=tipo;
    vehiculo->marca=crearStringDinamico(marca);
    vehiculo->modelo=crearStringDinamico(modelo);
    vehiculo->patente=crearStringDinamico(patente);
    return vehiculo;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE DESTRUCCION///
///-----------------------------------------------------------------------------------------------------------///

VehiculoPtr destruirVehiculo(VehiculoPtr vehiculo)
{
    destruirStringDinamico(vehiculo->marca);
    destruirStringDinamico(vehiculo->modelo);
    destruirStringDinamico(vehiculo->patente);
    free(vehiculo);
    return NULL;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE GETTERS///
///-----------------------------------------------------------------------------------------------------------///

int getTipoVehiculo(VehiculoPtr vehiculo) { return vehiculo->tipo; }

char *getMarca(VehiculoPtr vehiculo) { return vehiculo->marca; }

char *getModelo(VehiculoPtr vehiculo) { return vehiculo->modelo; }

char *getPatente(VehiculoPtr vehiculo) { return vehiculo->patente; }

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE SETTERS///
///-----------------------------------------------------------------------------------------------------------///

void setTipoVehiculo(VehiculoPtr vehiculo, int tipo) { vehiculo->tipo = tipo; }

void setMarca(VehiculoPtr vehiculo, char *marca) { strcpy(vehiculo->marca, marca); }

void setModelo(VehiculoPtr vehiculo, char *modelo) { strcpy(vehiculo->modelo, modelo); }

void setPatente(VehiculoPtr vehiculo, char *patente) { strcpy(vehiculo->patente, patente); }

///-----------------------------------------------------------------------------------------------------------///
                        ///SECCION DE FUNCIONES DE OPERACION CON VEHICULO///
///-----------------------------------------------------------------------------------------------------------///

void mostrarVehiculo(VehiculoPtr vehiculo)
{
    printf("\tTipo: ");
    tipoVehiculo(vehiculo);
    printf("\tMarca: %s\n",getMarca(vehiculo));
    printf("\tModelo: %s\n",getModelo(vehiculo));
    printf("\tPatente: %s\n",getPatente(vehiculo));
}

///muestra al usuario que significa cada numero de tipo de vehiculo.
void helpTipoVehiculo()
{
    //1: Moto, 2: Auto, 3: Camión.
    printf("Tipo 1 = MOTO\n");
    printf("Tipo 2 = AUTO\n");
    printf("Tipo 3 = CAMION\n");
}

void tipoVehiculo(VehiculoPtr vehiculo)
{
    switch(getTipoVehiculo(vehiculo))
    {
        case 1: printf("MOTO\n"); break;
        case 2: printf("AUTO\n"); break;
        case 3: printf("CAMION\n"); break;
    }
}


///informa al usuario de que tipo es el vehículo que ingresa.
void mostrarTipoVehiculo(VehiculoPtr vehiculo)
{
    switch(getTipoVehiculo(vehiculo))
    {
        case 1: printf("El vehiculo recibido es de tipo MOTO.\n\n"); break;
        case 2: printf("El vehiculo recibido es de tipo AUTO.\n\n"); break;
        case 3: printf("El vehiculo recibido es de tipo CAMION.\n\n"); break;
    }
    printf("\n\n");
}

bool vehiculosIguales(VehiculoPtr vehiculo1,VehiculoPtr vehiculo2)
{
    bool Igualdad = false;
    int ResultadoComparacion = 0;
    ResultadoComparacion = strcmp(getPatente(vehiculo1),getPatente(vehiculo2));
    if(ResultadoComparacion == 0)
    {
        Igualdad = true;
    }
    return Igualdad;
}


bool VerificarPatenteUnica(CentroLogisticoPtr centroLogistico, char* PatenteComprobar)
{
    VehiculoPtr VehiculoTemporal;
    bool PatenteUnica = true;
    ListaPtr ListaAuxiliar = crearLista();
    agregarLista(ListaAuxiliar, getVehiculos(centroLogistico) );
    while(!listaVacia(ListaAuxiliar))
    {
        VehiculoTemporal = (VehiculoPtr)getCabecera(ListaAuxiliar);
        if( strcmp( PatenteComprobar, getPatente(VehiculoTemporal) ) == 0 )
        {
            PatenteUnica = false;
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    return PatenteUnica;
}

bool VerificarPatenteValida(char* PatenteValidar)
{
    bool Valido = false;
    int ContadorValidas = 0;

    ///Se evalua si tiene 4 letras y 3 numeros

    if( isalpha(PatenteValidar[0]) ) { ContadorValidas++; }
    if( isalpha(PatenteValidar[1]) ) { ContadorValidas++; }

    if( isdigit(PatenteValidar[3]) ) { ContadorValidas++; }
    if( isdigit(PatenteValidar[4]) ) { ContadorValidas++; }
    if( isdigit(PatenteValidar[5]) ) { ContadorValidas++; }

    if( isalpha(PatenteValidar[7]) ) { ContadorValidas++; }
    if( isalpha(PatenteValidar[8]) ) { ContadorValidas++; }

    if( ContadorValidas == 7 ){ Valido = true; }

    return Valido;
}


bool menuCargarVehiculo(CentroLogisticoPtr centroLogistico)
{
    int tipoVehiculo=0,i=1,resultado=0;
    char marca[100];
    char modelo[100];
    char patente[100];
    VehiculoPtr vehiculo;
    bool TipoValido = false;
    bool PatenteUnica = false;
    bool PatenteValida = false;
    bool cambiosGuardados=false, continuar;
    do
    {
        system("cls");
        printf("VEHICULO %d\n\n",i++);

        while(!TipoValido)
        {
            helpTipoVehiculo();
            printf("\n\n\tSeleccione un Tipo: ");
            tipoVehiculo = seleccionarNumero();
            if(!TipoValido)
            {
                printf("\n\n\t [Ingrese un tipo valido por favor...] \n\n");
                presionarEnterYLimpiarPantalla();
            }
        }

        printf("\n\tMarca: ");
        seleccionarString(marca);

        printf("\n\tModelo: ");
        seleccionarString(modelo);

        while( !PatenteUnica || !PatenteValida )
        {
            printf("\n\tPatente (AA 000 AA): ");
            seleccionarString(patente);
            PatenteUnica = VerificarPatenteUnica(centroLogistico, patente);
            PatenteValida = VerificarPatenteValida(patente);
            if(!PatenteUnica)
            {
                printf("\n\n\t [Usted ha ingresado una patente ya existente...] \n\n");presionarEnterYLimpiarPantalla();
            }
            if(!PatenteValida)
            {
                printf("\n\n\t [Usted ha ingresado una patente invalida...] \n\n");
                presionarEnterYLimpiarPantalla();
            }
        }
        ConvertirMayusculasString(patente);
        vehiculo=crearVehiculo(tipoVehiculo,marca,modelo,patente);
        agregarVehiculo(centroLogistico,vehiculo);

        continuar = menuContinuar();
    } while(continuar);
    resultado=menuGuardarCambios();
    if(resultado==1)
    {
        cambiosGuardados = guardarVehiculos(centroLogistico);
    }
    return cambiosGuardados;
}

bool menuEliminarVehiculo(CentroLogisticoPtr centroLogistico)
{
    int opcion=0;
    bool cambiosGuardados = true;
    bool continuar;
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int indices[100];
    int cantIndices=0;
    VehiculoPtr vehiculoRemovido;
    do
    {
        if(listaVacia(getVehiculos(centroLogistico)))
        {
            printf("ERROR: Lista vacía. Debe agregar vehiculos para poder eliminarlos.\n\n");
        }
        else
        {
            EleccionMenuModoAccion = menuModoAccion();
            if(EleccionMenuModoAccion != 0)
            {
                mostrarVehiculos(centroLogistico);
            }
            printf("ELIMINAR VEHICULO \n\n");
                switch(EleccionMenuModoAccion)
                {
                    case 1:
                        EleccionAccion = menuModoAccion1(getVehiculos(centroLogistico));
                        vehiculoRemovido = removerVehiculo(centroLogistico, EleccionAccion);
                        vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
                        cambiosGuardados = false;
                        break;
                    case 2:
                        printf("[ACLARACION]Eliga la cantidad de indices...\n");
                        cantIndices = menuModoAccion1( getVehiculos(centroLogistico) );
                        menuModoAccion2(getVehiculos(centroLogistico),cantIndices,indices);
                        for(int i=0;i<cantIndices+1;i++)
                        {
                            vehiculoRemovido = removerVehiculo(centroLogistico,indices[i]-i);
                            vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
                        }
                        cambiosGuardados = false;
                        break;
                    case 3:
                        menuModoAccion3(getVehiculos(centroLogistico),indices);
                        for(int i=0;i<indices[1]-indices[0]+1;i++)
                        {
                            vehiculoRemovido = removerVehiculo(centroLogistico,indices[0]);
                            vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
                        }
                        cambiosGuardados = false;
                        break;
                    case 0:
                        break;
                    default:
                        printf("Eleccion equivocada \n");
                        break;
                }
            if(EleccionMenuModoAccion == 0)
            {
                continuar = false;
            }
            else
            {
                continuar = menuContinuar();
            }
        }
    }while(continuar && !listaVacia( getVehiculos(centroLogistico) ) );
    notificacionListaVacia( getVehiculos(centroLogistico) );
    if( !cambiosGuardados )
    {
        opcion = menuGuardarCambios();
        if(opcion == 1)
        {
            cambiosGuardados=guardarPersonas(centroLogistico);
        }
    }
    return cambiosGuardados;
}

void cambiarVehiculo(CentroLogisticoPtr centroLogistico, VehiculoPtr vehiculoAModificar)
{
    int op=0;
    int nTipo=0;
    char nMarca[100];
    char nModelo[100];
    char nPatente[100];
    bool PatenteValida = false;
    bool PatenteUnica = false;
    bool TipoValido = false;
    int seguirMod=0;
    do
    {
        system("cls");
        printf("Ha elegido - \n");
        mostrarVehiculo(vehiculoAModificar);
        printf("\n\nQué desea modificar?\n\n");
        printf("1. Tipo de vehiculo\n");
        printf("2. Marca\n");
        printf("3. Modelo\n");
        printf("4. Patente\n");
        printf("0. Volver\n");
        printf("Seleccione una opcion: ");
        limpiarBufferTeclado();
        scanf("%d",&op);
        limpiarBufferTeclado();
        switch(op)
        {
        case 1:
            while(!TipoValido)
            {
                printf("\n\n");
                helpTipoVehiculo();
                printf("\n\n Seleccione una opcion: ");
                nTipo = seleccionarNumero();
                if(nTipo > 0 && nTipo < 4)
                {
                    TipoValido = true;
                }
                if(!TipoValido)
                {
                    printf("\n\n\t [Ingrese un tipo de vehiculo valido...] \n\n");
                    presionarEnterYLimpiarPantalla();
                }
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
        case 4:
            do
            {
                printf("\n\n\t Ingrese la nueva patente (AA 111 AA):");
                seleccionarString(nPatente);
                PatenteUnica = VerificarPatenteUnica(centroLogistico, nPatente);
                PatenteValida = VerificarPatenteValida(nPatente);
                if(!PatenteUnica)
                {
                    printf("\n\n\t [Patente ya  existente...] \n");
                    printf("\n\t [Ingrese una valida por favor...] \n");
                    printf("\n\t [Compruebe las patentes existentes...] \n\n");
                    mostrarVehiculos(centroLogistico);
                    presionarEnterYLimpiarPantalla();
                }
                if(!PatenteValida)
                {
                    printf("\n\n\t [Patente invalida...] \n");
                    printf("\n\t [Formato valido: [AA 111 AAA] ...] \n");
                    printf("\n\t [Formato valido: [(LETRA)(LETRA) (NUMERO)(NUMERO)(NUMERO) (LETRA)(LETRA)] ...] \n\n");
                    presionarEnterYLimpiarPantalla();
                }
            }while(!PatenteUnica || !PatenteValida);
            setPatente(vehiculoAModificar,nPatente);
            break;
        case 0:
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            break;
        }
        if(op == 0)
        {
            seguirMod = 0;
        }
        else
        {
            printf("\n\n Datos modificados exitosamente. \n\n");
            printf("Desea seguir modificando este vehiculo? \n\n");
            printf("\t 1. SI \n");
            printf("\t 0. NO \n\n");
            printf("Seleccione una opcion: ");
            scanf("%d",&seguirMod);
        }
    } while(seguirMod!=0);
}


ListaPtr OriginalVehiculos(CentroLogisticoPtr centroLogistico)
{
    ///Creamos una lista "original" para ver si hay cambios,
    ///y una "auxiliar" para obtener y recorrer la lista.
    ListaPtr listaOriginal=crearLista();
    ListaPtr listaAux2=crearLista();
    agregarLista(listaAux2,getVehiculos(centroLogistico));
    ///Hacemos lo mismo pero para cada elemento de la lista
    VehiculoPtr vehiculoOriginal;
    VehiculoPtr vehiculoAux;
    while(!listaVacia(listaAux2))
    {
        vehiculoAux=getCabecera(listaAux2);
        ///Copiamos el contenido de cada elemento
        vehiculoOriginal=crearVehiculo(getTipoVehiculo(vehiculoAux),getMarca(vehiculoAux),getModelo(vehiculoAux),getPatente(vehiculoAux));
        ///Agregamos el dato original a la lista
        agregarDatoLista(listaOriginal,(VehiculoPtr)vehiculoOriginal);
        listaAux2=getResto(listaAux2);
    }
    listaAux2=destruirLista(listaAux2,false);
    return listaOriginal;
}

bool CambiosVehiculos(CentroLogisticoPtr centroLogistico, ListaPtr listaOriginal)
{
    bool cambioDetectado=false;
    ListaPtr listaAux2=crearLista();
    VehiculoPtr vehiculoAux;
    VehiculoPtr vehiculoOriginal;
    agregarLista(listaAux2,getVehiculos(centroLogistico));
    ///Recorremos la lista: antes y después de hacer el cambio
    while(!listaVacia(listaAux2))
    {
        vehiculoAux=getCabecera(listaAux2);
        vehiculoOriginal=getCabecera(listaOriginal);
        ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
        if(!vehiculosIguales(vehiculoOriginal,vehiculoAux))
            cambioDetectado=true;
        listaAux2=getResto(listaAux2);
        listaOriginal=getResto(listaOriginal);
    }
    ///Destruimos ambas listas, ya no las necesitamos más
    listaAux2=destruirLista(listaAux2,false);
    ///Como en esta copiamos los contenidos, ponemos true para removerlos.
    listaOriginal=destruirLista(listaOriginal,true);
    return cambioDetectado;
}

bool menuModificarVehiculo(CentroLogisticoPtr centroLogistico)
{
    bool cambiosGuardados = true;
    bool continuar;
    int modoAccion, Cantidad, Eleccion, resultado;
    int Elecciones[10];
    VehiculoPtr vehiculoModificar;
    if(listaVacia(getVehiculos(centroLogistico)))
    {
        printf("ERROR: Lista vacía. Debe agregar vehiculos para poder modificarlos.\n\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            modoAccion = menuModoAccion();
            if(modoAccion != 0)
            {
                mostrarVehiculos(centroLogistico);
            }
            switch(modoAccion)
            {
                case 1:
                        Eleccion=menuModoAccion1(getVehiculos(centroLogistico));
                        vehiculoModificar=getDatoLista(getVehiculos(centroLogistico),Eleccion);
                        cambiarVehiculo(centroLogistico, vehiculoModificar);
                        cambiosGuardados = false;
                    break;
                case 2:
                        printf("[ACLARACION]Eliga la cantidad de indices...\n");
                        Cantidad=menuModoAccion1(getVehiculos(centroLogistico));
                        menuModoAccion2(getVehiculos(centroLogistico),Cantidad,Elecciones);
                        for(int i=0;i<Cantidad+1;i++)
                        {
                            vehiculoModificar=getDatoLista(getVehiculos(centroLogistico),Elecciones[i]);
                            cambiarVehiculo(centroLogistico, vehiculoModificar);
                        }
                        cambiosGuardados = false;
                    break;
                case 3:
                        menuModoAccion3(getVehiculos(centroLogistico),Elecciones);
                        for(int i=Elecciones[0];i<=Elecciones[1];i++)
                        {
                            vehiculoModificar=getDatoLista(getVehiculos(centroLogistico),i);
                            cambiarVehiculo(centroLogistico, vehiculoModificar);
                        }
                        cambiosGuardados = false;
                    break;
                default:
                    printf("Eleccion equivocada \n");
                    break;
            }
            if(modoAccion == 0)
            {
                continuar = false;
            }
            else
            {
                continuar = menuContinuar();
            }
        } while(continuar);
    }
    if( !cambiosGuardados )
    {
        resultado=menuGuardarCambios();
        if(resultado==1)
        {
            cambiosGuardados=guardarVehiculos(centroLogistico);
        }
    }
    return cambiosGuardados;
}

void menuBuscarVehiculo(CentroLogisticoPtr centroLogistico)
{
    bool continuar;
    if(listaVacia(getVehiculos(centroLogistico)))
    {
        printf("ERROR: Lista vacia. No hay vehiculos para buscar\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            system("cls");
            char patente[100];
            printf("BUSCAR VEHICULO\n\n");
            printf("0. Volver\n");
            printf("Ingrese la patente del vehiculo a buscar (AA 111 AA): ");
            scanf("%[^\n]%*c",patente);
            if(!buscarVehiculo(centroLogistico,patente) && strlen(patente) != 1)
            {
                printf("\n\nNo se pudo encontrar el vehiculo con patente %s.\n\n",patente);
            }
            if(strlen(patente) == 1)
            {
                continuar = false;
            }
            else
            {
                continuar = menuContinuar();
            }
        } while(continuar);
    }
}

bool menuMostrarVehiculos(CentroLogisticoPtr centroLogistico, int* op1)
{
    int op=0;
    bool cambiosGuardados=false;
    if(listaVacia(getVehiculos(centroLogistico)))
    {
        printf("Lista vacia de vehiculos, agregue un elemento por favor\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            op = menuTipoOrdenamientoVehiculos();
            switch(op)
            {
            case 1:
                printf("LISTADO DE VEHICULOS (ORDENADOS POR MARCA)");
                ordenarVehiculos(centroLogistico,1);
                break;
            case 2:
                printf("LISTADO DE VEHICULOS (ORDENADOS POR MODELO)");
                ordenarVehiculos(centroLogistico,2);
                break;
            case 3:
                printf("LISTADO DE VEHICULOS (ORDENADOS TIPO)");
                ordenarVehiculos(centroLogistico,3);
                break;
            case 4:
                printf("LISTADO DE VEHICULOS (SIN ORDENAR)");
                ordenarVehiculos(centroLogistico,4);
                break;
            case 0:
                break;
            case -1:
                op = 0;
                *op1 = 0;
                break;
            default:
                printf("\nOpcion incorrecta.\n\n");
                break;
            }
        }while(op!=0 && op!=-1);
    }
    return cambiosGuardados;
}

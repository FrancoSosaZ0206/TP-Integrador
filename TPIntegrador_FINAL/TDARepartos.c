#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TDACentroLogistico.h"
#include "Lista.h"
#include "TDAPersona.h"
#include "TDAVehiculo.h"
#include "TDAFechaYHora.h"
#include "TDAPaquetes.h"
#include "Pila.h"
#include "TDARepartos.h"
#include "Files.h"
#include "Menus.h"

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE CREACION///
///-----------------------------------------------------------------------------------------------------------///

RepartoPtr crearReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,ListaPtr paquetes)
{
    RepartoPtr reparto=(RepartoPtr)obtenerMemoria(sizeof(Reparto));
    reparto->chofer=chofer;
    reparto->vehiculo=vehiculo;
    reparto->fechaSalida=fechaSalida;
    reparto->fechaRetorno=fechaRetorno;
    reparto->paquetes=paquetes;
    return reparto;
}

RepartoPtr armarReparto(PersonaPtr chofer,VehiculoPtr vehiculo,FechaPtr fechaSalida,FechaPtr fechaRetorno,ListaPtr paquetes)
{
    RepartoPtr reparto=crearReparto(chofer,vehiculo,fechaSalida,fechaRetorno,paquetes);
    return reparto;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE DESTRUCCION///
///-----------------------------------------------------------------------------------------------------------///

RepartoPtr destruirReparto(RepartoPtr reparto)
{
//liberamos la memoria de todos los campos que hayan sido reservados dinamicamente con sus respectivas funciones. En este caso, son todos los campos.
/**Como el chofer y vehiculo se los pasamos como punteros, destruirlos acá ocasionaría que se eliminen tambien del centro logistico.
No queremos eso, así que simplemente no las destruimos.*/
    reparto->fechaSalida=destruirFecha(reparto->fechaSalida);
    reparto->fechaRetorno=destruirFecha(reparto->fechaRetorno);
    reparto->paquetes=destruirLista(reparto->paquetes,true);
    free(reparto);
    return NULL;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE GETTERS///
///-----------------------------------------------------------------------------------------------------------///

PersonaPtr getChofer(RepartoPtr reparto)
{
    return reparto->chofer;
}

VehiculoPtr getVehiculo(RepartoPtr reparto)
{
    return reparto->vehiculo;
}

FechaPtr getFechaSalida(RepartoPtr reparto)
{
    return reparto->fechaSalida;
}

FechaPtr getFechaRetorno(RepartoPtr reparto)
{
    return reparto->fechaRetorno;
}

ListaPtr getPaquetesReparto(RepartoPtr reparto)
{
    return reparto->paquetes;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE SETTERS///
///-----------------------------------------------------------------------------------------------------------///

void setChofer(RepartoPtr reparto,PersonaPtr chofer)
{
    reparto->chofer=chofer;
}

void setVehiculo(RepartoPtr reparto,VehiculoPtr vehiculo)
{
    reparto->vehiculo=vehiculo;
}

void setFechaSalida(RepartoPtr reparto,FechaPtr fechaSalida)
{
    reparto->fechaSalida=fechaSalida;
}

void setFechaRetorno(RepartoPtr reparto,FechaPtr fechaRetorno)
{
    reparto->fechaRetorno=fechaRetorno;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE OPERACIONES CON REPARTO///
///-----------------------------------------------------------------------------------------------------------///

void mostrarReparto(RepartoPtr reparto)
{
    mostrarPersona(getChofer(reparto));
    mostrarVehiculo(getVehiculo(reparto));
    printf("\n\tFECHA DE SALIDA: ");
    mostrarFecha(getFechaSalida(reparto));
    printf("\n\tFECHA DE RETORNO: ");
    mostrarFecha(getFechaRetorno(reparto));
    printf("\n\n");
    mostrarPaquetesReparto(reparto);
    printf("\n\n");
}

void mostrarRepartoSinPaquetes(RepartoPtr reparto)
{
    mostrarPersona(getChofer(reparto));
    mostrarVehiculo(getVehiculo(reparto));
    printf("\nFECHA DE SALIDA: ");
    mostrarFecha(getFechaSalida(reparto));
    printf("\nFECHA DE RETORNO: ");
    mostrarFecha(getFechaRetorno(reparto));
    printf("\n\n");
}

void mostrarPaquetesReparto(RepartoPtr reparto)
{
    int i = 0;
    ListaPtr ListaAuxiliar = crearLista();
    agregarLista(ListaAuxiliar, getPaquetesReparto(reparto));
    PaquetePtr PaqueteAuxiliar;
    while(!listaVacia(ListaAuxiliar))
    {
        PaqueteAuxiliar = (PaquetePtr)getCabecera(ListaAuxiliar);
        printf("\n %d. ", i+1);
        mostrarPaquete(PaqueteAuxiliar);
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
        i++;
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
}

bool repartosIguales(RepartoPtr reparto1,RepartoPtr reparto2) ///NUEVA
{
    bool condicion = personasIguales(getChofer(reparto1),getChofer(reparto2));
    condicion = condicion && vehiculosIguales(getVehiculo(reparto1),getVehiculo(reparto2));
    condicion = condicion && fechasIguales(getFechaSalida(reparto1),getFechaSalida(reparto2));
    condicion = condicion && fechasIguales(getFechaRetorno(reparto1),getFechaRetorno(reparto2));
    bool pilasIguales=false; //para los paquetes;
    int n=longitudLista(getPaquetesReparto(reparto1))-longitudLista(getPaquetesReparto(reparto2));
    if(n<0)
    {
        n=longitudLista(getPaquetesReparto(reparto2));
    }
    else if(n==0) //si tienen la misma cantidad de paquetes, usamos cualquiera de las dos
    {
        n=longitudLista(getPaquetesReparto(reparto1));
    }
    else if(n>0)
    {
        n=longitudLista(getPaquetesReparto(reparto1));
    }
    PaquetePtr paqueteAux1;
    PaquetePtr paqueteAux2;
    for(int i=0;i<n;i++)
    {
        paqueteAux1=getDatoLista(getPaquetesReparto(reparto1),i);
        paqueteAux2=getDatoLista(getPaquetesReparto(reparto2),i);
        if(paquetesIguales(paqueteAux1,paqueteAux2))
        {
            pilasIguales=true;
        }
    }
    return condicion && pilasIguales;
}

void verificacionPaquetesCurso(ListaPtr ListaPaquetes)
{
    int EstadoPaquete = 0;
    ListaPtr ListaAuxiliar = crearLista();
    agregarLista(ListaAuxiliar, ListaPaquetes);
    PaquetePtr PaqueteAuxiliar;
    while(!listaVacia(ListaAuxiliar))
    {
        PaqueteAuxiliar = (PaquetePtr)getCabecera(ListaAuxiliar);
        EstadoPaquete = getEstado(PaqueteAuxiliar);
        if(EstadoPaquete != 3)
        {
            ///LOS DEVOLVEMOS AL DEPOSITO
            setEstado(PaqueteAuxiliar, 0);
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        destruirLista(ListaDestruir, false);
    }
    destruirLista(ListaAuxiliar, false);
}


bool menuArmarReparto(CentroLogisticoPtr centroLogistico)
{
    RepartoPtr reparto;
    int k=0;
    int resultado=0;
    PersonaPtr choferElegido;
    VehiculoPtr vehiculoElegido;
    FechaPtr fechaSalida = NULL;
    FechaPtr fechaRetorno = NULL;
    ListaPtr paquetes=crearLista();
    PaquetePtr paqueteElegido;
    bool ExistenDatos=true;
    bool cambiosGuardados=false;
    bool continuar;
    bool valido=false;
    if(!listaVacia(getVehiculos(centroLogistico)))
    {
        if(!existenVehiculosDisponibles(centroLogistico))
        {
            ExistenDatos=false;
            printf("Faltan vehiculos para agregar al reparto...\n");
        }
    }
    else
    {
        ExistenDatos=false;
        printf("Faltan vehiculos para agregar al reparto...\n");
    }
    if(!listaVacia(getPersonas(centroLogistico)))
    {
        if(!existenChoferesDisponibles(centroLogistico))
        {
            ExistenDatos=false;
            printf("Faltan choferes para agregar al reparto...\n");
        }
    }
    else
    {
        ExistenDatos=false;
        printf("Faltan choferes para agregar al reparto...\n");
    }
    if(!listaVacia(getPaquetes(centroLogistico)))
    {
        if(!existenPaquetesDisponibles(centroLogistico))
        {
            ExistenDatos=false;
            printf("Faltan paquetes para agregar al reparto...\n");
        }
    }
    else
    {
        ExistenDatos=false;
        printf("Faltan paquetes para agregar al reparto...\n");
    }
    if(ExistenDatos)
    {
        do
        {
            ///Cargamos el chofer
            mostrarChoferesDisponibles(centroLogistico);
            printf("\n\nSeleccione un chofer ingresando su indice: ");
            k = menuModoAccion1(getPersonas(centroLogistico));
            choferElegido=getDatoLista(getPersonas(centroLogistico),k);
            if(!buscarChoferRepartos(centroLogistico, getCuil(getCuilPersona(choferElegido))))
            {
                if(!getRepartoDiario(choferElegido))
                {
                    if(getEsChofer(choferElegido))
                    {
                        valido=true;
                    }
                    else
                    {
                        printf("\n\nEl chofer elegido resulto no ser un chofer\n\n");
                        presionarEnterYLimpiarPantalla();
                    }
                }
                else
                {
                    printf("\n\n\t [El chofer elegido resulto haber concretado su reparto diario...] \n\n");
                    presionarEnterYLimpiarPantalla();
                }
            }
            else
            {

                printf("\nEl chofer resulto estar en otro reparto\n\n");
                presionarEnterYLimpiarPantalla();
            }
            system("cls");
        }while(!valido);
        system("cls");
        valido=false;
        do
        {
            mostrarVehiculosDisponibles(centroLogistico);
            printf("\n\nSeleccione un vehiculo ingresando su indice: ");
            k = menuModoAccion1(getVehiculos(centroLogistico));
            if(!buscarVehiculoRepartos(centroLogistico,getPatente(getDatoLista(getVehiculos(centroLogistico),k))))
            {
                vehiculoElegido=getDatoLista(getVehiculos(centroLogistico),k);
                valido=true;
            }
            else
            {
                printf("\n\nVehiculo actualmente en un reparto\n\n");
                presionarEnterYLimpiarPantalla();
            }
            system("cls");
        }while(!valido);
        system("cls");
        printf("\n\nFecha de salida:");
        fechaSalida=cargarFecha(fechaSalida);
        printf("\n\nFecha de retorno:");
        fechaRetorno=cargarFecha(fechaRetorno);
        system("cls");
        int j = 1;
        do
        {
            do
            {
                valido=false;
                system("cls");
                mostrarPaquetesDisponibles(centroLogistico);
                printf("\n\nPaquete N. %d\n",j++);
                printf("Seleccione el paquete a cargar ingresando su indice: ");
                k=menuModoAccion1(getPaquetes(centroLogistico));
                if(getEstado(getDatoLista(getPaquetes(centroLogistico),k))==0)
                {
                    valido=true;
                }
                else
                {
                    printf("\n\nPaquete actualmente en curso\n\n");
                    presionarEnterYLimpiarPantalla();
                }
            }while(!valido);
            paqueteElegido=getDatoLista(getPaquetes(centroLogistico),k);
            setEstado(paqueteElegido,1);
            agregarDatoLista(paquetes,(PaquetePtr)paqueteElegido);
            continuar = menuContinuar();
        }while(continuar && existenPaquetesDisponibles(centroLogistico));
        if(!existenPaquetesDisponibles(centroLogistico))
        {
            printf("\n\n\t [Se ha quedado sin paquetes para seleccionar, agregue mas...] \n\n");
        }
        reparto=crearReparto(choferElegido,vehiculoElegido,fechaSalida,fechaRetorno,paquetes);
        cambiosGuardados = true;
        agregarReparto(centroLogistico,reparto,true);
        printf("\n\nReparto armado exitosamente.\n\n");
    }
    if( cambiosGuardados )
    {
        resultado = menuGuardarCambios();
        if(resultado == 1)
        {
            cambiosGuardados = guardarRepartos(centroLogistico, true);
        }
    }
    return cambiosGuardados;
}

bool menuCerrarReparto(CentroLogisticoPtr centroLogistico)
{
    bool cambiosGuardados = true;
    bool continuar;
    int EleccionMenuModoAccion=0,EleccionAccion=0,cantIndices=0,resultado=0;
    int indices[100];
    RepartoPtr repartoCerrado;
    do
    {
        if(listaVacia(getRepartos(centroLogistico, true)))
        {
            printf("Lista vacia,, no puede cerrar repartos\n");
            presionarEnterYLimpiarPantalla();
        }
        else
        {
            EleccionMenuModoAccion = menuModoAccion();
            if(EleccionMenuModoAccion != 0)
            {
                mostrarRepartos(centroLogistico,true);
            }
            printf("CERRAR REPARTO \n\n");
            switch(EleccionMenuModoAccion)
            {
                case 1:
                    EleccionAccion = menuModoAccion1(getRepartos(centroLogistico, true));
                    repartoCerrado = removerReparto(centroLogistico,EleccionAccion,true);
                    verificacionPaquetesCurso(getPaquetesReparto(repartoCerrado));
                    setRepartoDiario(getChofer(repartoCerrado),true);
                    agregarReparto(centroLogistico,repartoCerrado,false);
                    cambiosGuardados = false;
                    break;
                case 2:
                    cantIndices = menuModoAccion1(getRepartos(centroLogistico,true));
                    menuModoAccion2(getRepartos(centroLogistico, true),cantIndices,indices);
                    for(int i=0;i<cantIndices;i++)
                    {
                        repartoCerrado = removerReparto(centroLogistico,indices[i]-i,true);
                        agregarLista(getPaquetesReparto(repartoCerrado),getPaquetesReparto(repartoCerrado));
                        verificacionPaquetesCurso(getPaquetesReparto(repartoCerrado));
                        setRepartoDiario(getChofer(repartoCerrado),true);
                        agregarReparto(centroLogistico,repartoCerrado,false);
                    }
                    cambiosGuardados = false;
                    break;
                case 3:
                    menuModoAccion3(getRepartos(centroLogistico, true),indices);
                    for(int i=0;i<indices[1]-indices[0]+1;i++)
                    {
                        repartoCerrado = removerReparto(centroLogistico,indices[i],true);
                        agregarLista(getPaquetesReparto(repartoCerrado),getPaquetesReparto(repartoCerrado));
                        verificacionPaquetesCurso(getPaquetesReparto(repartoCerrado));
                        setRepartoDiario(getChofer(repartoCerrado),true);
                        agregarReparto(centroLogistico,repartoCerrado,false);
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
    } while(continuar && !listaVacia(getRepartos(centroLogistico,true)));
    notificacionListaVacia(getRepartos(centroLogistico, true));
    if( !cambiosGuardados )
    {
        resultado = menuGuardarCambios();
        if(resultado == 1)
        {
            cambiosGuardados = guardarRepartos(centroLogistico,true);
            cambiosGuardados = cambiosGuardados && guardarRepartos(centroLogistico,false);
        }
    }
    return cambiosGuardados;
}

bool menuEliminarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    int resultado=0;
    bool cambiosGuardados = true;
    bool continuar;
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int indices[100];
    int cantIndices=0;
    RepartoPtr repartoRemovido;
    do
    {
        if(listaVacia(getRepartos(centroLogistico,esRepartoAbierto)))
        {
            printf("ERROR: Lista vacía. Debe agregar repartos para poder eliminarlos.\n\n");
        }
        else
        {
            EleccionMenuModoAccion = menuModoAccion();
            if(EleccionMenuModoAccion != 0)
            {
                mostrarRepartos(centroLogistico,esRepartoAbierto);
            }
            printf("ELIMINAR REPARTO \n\n");
            switch(EleccionMenuModoAccion)
            {
                case 1:
                    EleccionAccion = menuModoAccion1(getRepartos(centroLogistico,esRepartoAbierto));
                    repartoRemovido = removerReparto(centroLogistico, EleccionAccion,esRepartoAbierto);
                    repartoRemovido = destruirReparto(repartoRemovido);
                    cambiosGuardados = false;
                    break;
                case 2:
                    printf("[ACLARACION]Eliga la cantidad de indices...\n");
                    cantIndices = menuModoAccion1( getRepartos(centroLogistico, esRepartoAbierto) );
                    menuModoAccion2(getRepartos(centroLogistico,esRepartoAbierto),cantIndices,indices);
                    for(int i=0;i<cantIndices+1;i++)
                    {
                        repartoRemovido = removerReparto(centroLogistico,indices[i]-i,esRepartoAbierto);
                        repartoRemovido = destruirReparto(repartoRemovido);
                    }
                    cambiosGuardados = false;
                    break;
                case 3:
                    menuModoAccion3(getRepartos(centroLogistico,esRepartoAbierto),indices);
                    for(int i=0;i<indices[1]-indices[0]+1;i++)
                    {
                        repartoRemovido = removerReparto(centroLogistico,indices[0],esRepartoAbierto);
                        repartoRemovido = destruirReparto(repartoRemovido);
                    }
                    cambiosGuardados = false;
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
                continuar=menuContinuar();
            }
        }
    } while(continuar && !listaVacia(getRepartos(centroLogistico,esRepartoAbierto)));
    notificacionListaVacia(getRepartos(centroLogistico,esRepartoAbierto));
    if( cambiosGuardados )
    {
        resultado = menuGuardarCambios();
        if(resultado == 1)
        {
            cambiosGuardados = guardarRepartos(centroLogistico,esRepartoAbierto);
        }
    }
    return cambiosGuardados;
}

ListaPtr OriginalRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
        ///Creamos una lista "original" para ver si hay cambios,
        ///y una "auxiliar" para obtener y recorrer la lista.
        ListaPtr listaOriginal=crearLista();
        ListaPtr listaAux2=crearLista();
        agregarLista(listaAux2,getRepartos(centroLogistico,esRepartoAbierto));
        ///Hacemos lo mismo pero para cada elemento de la lista
        RepartoPtr repartoOriginal;
        RepartoPtr repartoAux;
        while(!listaVacia(listaAux2))
        {
            repartoAux=getCabecera(listaAux2);
            ///Copiamos el contenido de cada elemento
            repartoOriginal=armarReparto(getChofer(repartoAux),getVehiculo(repartoAux),getFechaSalida(repartoAux),getFechaRetorno(repartoAux),getPaquetesReparto(repartoAux));
            ///Agregamos el dato original a la lista
            agregarDatoLista(listaOriginal,(RepartoPtr)repartoOriginal);
            listaAux2=getResto(listaAux2);
        }
        listaAux2=destruirLista(listaAux2,false);
        return listaOriginal;
}

bool CambiosRepartos(CentroLogisticoPtr centroLogistico, ListaPtr listaOriginal,bool esRepartoAbierto)
{
    bool cambioDetectado=false;
    ListaPtr listaAux2=crearLista();
    RepartoPtr repartoAux;
    RepartoPtr repartoOriginal;
    agregarLista(listaAux2,getRepartos(centroLogistico,esRepartoAbierto));
    ///Recorremos la lista: antes y después de hacer el cambio
    while(!listaVacia(listaAux2))
    {
        repartoAux=getCabecera(listaAux2);
        repartoOriginal=getCabecera(listaOriginal);
        ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
        if(!repartosIguales(repartoOriginal,repartoAux))
            cambioDetectado=true;
        listaAux2=getResto(listaAux2);
        listaOriginal=getResto(listaOriginal);
    }
    ///Destruimos ambas listas, ya no las necesitamos más
    listaAux2=destruirLista(listaAux2,false);
    ///Como en esta copiamos los contenidos, ponemos true para remover
    listaOriginal=destruirLista(listaOriginal,true);
    return cambioDetectado;
}


void cambiarAtributoReparto(CentroLogisticoPtr centroLogistico, RepartoPtr repartoModificar)
{
    int SubMenu,iMod,seguirMod;
    PersonaPtr choferModificar;
    VehiculoPtr vehiculoModificar;
    FechaPtr fechaModificar;
    PaquetePtr paqueteModificar;
    do
    {
        system("cls");
        mostrarReparto(repartoModificar);
        SubMenu = MenuSeleccionAtributoReparto();
        switch(SubMenu)
        {
            case 1:
                printf("MODIFICAR CHOFER \n");
                choferModificar = getChofer(repartoModificar);
                cambiarPersona(centroLogistico, choferModificar, true);
            break;
            case 2:
                printf("MODIFICAR VEHICULO \n");
                vehiculoModificar = getVehiculo(repartoModificar);
                cambiarVehiculo(centroLogistico, vehiculoModificar);
            break;
            case 3:
                printf("MODIFICAR FECHA DE SALIDA \n");
                fechaModificar = getFechaSalida(repartoModificar);
                actualizarFecha(fechaModificar);
            break;
            case 4:
                printf("MODIFICAR FECHA DE RETORNO \n");
                fechaModificar = getFechaRetorno(repartoModificar);
                actualizarFecha(fechaModificar);
            break;
            case 5:
                system("cls");
                printf("MODIFICAR PAQUETE \n");
                mostrarPaquetesReparto(repartoModificar);
                printf("Seleccione un paquete ");
                iMod = menuModoAccion1(getPaquetesReparto(repartoModificar));
                paqueteModificar = getDatoLista(getPaquetesReparto(repartoModificar), iMod);
                cambiarPaquete(centroLogistico, paqueteModificar);
            break;
            case 0:
                break;
            default:
                printf("Eleccion ewuivocada\n");
            break;
        }
        if(SubMenu == 0)
        {
            seguirMod = 0;
        }
        else
        {
            printf("\n\nDatos modificados exitosamente.\n\n");
            printf("Desea seguir modificando este REPARTO?\n\n");
            printf("\t1. SI\n\t");
            printf("0. NO\n\n");
            printf("Seleccione una opcion: ");
            scanf("%d",&seguirMod);
        }
    }while(seguirMod!=0);
}

bool menuModificarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    bool cambiosGuardados = true;
    bool continuar;
    int resultado=0;
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int indices[100];
    int cantIndices=0;
    RepartoPtr repartoModificar = (RepartoPtr)obtenerMemoria(sizeof(Reparto));
    if(listaVacia(getRepartos(centroLogistico,esRepartoAbierto)))
    {
        printf("ERROR: Lista vacía. Debe agregar repartos para poder modificarlos.\n\n");
    }
    else
    {
        do
        {
            EleccionMenuModoAccion = menuModoAccion();
            if(EleccionMenuModoAccion != 0)
            {
                mostrarRepartos(centroLogistico,esRepartoAbierto);
            }
            printf("MODIFICAR REPARTO\n\n");
            switch(EleccionMenuModoAccion)
            {
            case 1:
                EleccionAccion = menuModoAccion1(getRepartos(centroLogistico,esRepartoAbierto));
                repartoModificar = getDatoLista(getRepartos(centroLogistico,esRepartoAbierto), EleccionAccion);
                cambiarAtributoReparto(centroLogistico, repartoModificar);
                cambiosGuardados = false;
                break;
            case 2:
                printf("[ACLARACION]Eliga la cantidad de indices...\n");
                cantIndices = menuModoAccion1(getRepartos(centroLogistico,esRepartoAbierto));
                menuModoAccion2(getRepartos(centroLogistico,esRepartoAbierto),cantIndices,indices);
                for(int i=0;i<cantIndices+1;i++)
                {
                    repartoModificar = getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),indices[i]-i);
                    cambiarAtributoReparto(centroLogistico, repartoModificar);
                }
                cambiosGuardados = false;
                break;
            case 3:
                menuModoAccion3(getRepartos(centroLogistico,esRepartoAbierto),indices);
                for(int i=indices[0];i<=indices[1];i++)
                {
                    repartoModificar = getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),i);
                    cambiarAtributoReparto(centroLogistico, repartoModificar);
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
                continuar=menuContinuar();
            }
        }while(continuar);
    }
    if( !cambiosGuardados )
    {
        resultado = menuGuardarCambios();
        if(resultado==1)
        {
            cambiosGuardados = guardarRepartos(centroLogistico,esRepartoAbierto);
        }
    }
    return cambiosGuardados;
}

RepartoPtr SeleccionRepartoPorAtributo(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    char CuilBuscar[100];
    char PatenteBuscar[100];
    int ID_Buscar;
    int diaBuscar,mesBuscar,anioBuscar,horaBuscar,minutosBuscar;
    FechaPtr FechaBuscar;
    int Menu;
    int Indice;
    RepartoPtr RepartoElegido = NULL;
    if( listaVacia( getRepartos( centroLogistico, esRepartoAbierto ) ) )
    {
        printf("Lista de repartos vacia, agregue elementos para seleccionar...\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            system("cls");
            Menu = menuTipoRepartos();
            switch(Menu)
            {
                case 1:
                    mostrarRepartos(centroLogistico, true);
                    Indice = menuModoAccion1( getRepartos(centroLogistico, esRepartoAbierto) );
                    RepartoElegido = (RepartoPtr)getDatoLista( getRepartos(centroLogistico, esRepartoAbierto) , Indice);
                    break;
                case 2:
                    printf("Ingrese el cuil: ");
                    seleccionarString(CuilBuscar);
                    RepartoElegido = devolverRepartoChofer(centroLogistico, CuilBuscar, esRepartoAbierto);
                    break;
                case 3:
                    printf("Ingrese la patente: ");
                    seleccionarString(PatenteBuscar);
                    RepartoElegido = devolverRepartoVehiculo(centroLogistico, PatenteBuscar, esRepartoAbierto);
                    break;
                case 4:
                    printf("Ingrese la fecha de salida [DD/MM/AA HH:MM]: ");
                    fflush(stdin);
                    scanf("%d %d %d %d %d", &diaBuscar,&mesBuscar,&anioBuscar,&horaBuscar,&minutosBuscar);
                    fflush(stdin);
                    FechaBuscar = crearFecha(diaBuscar,mesBuscar,anioBuscar,horaBuscar,minutosBuscar);
                    RepartoElegido = devolverRepartoFechaSalida(centroLogistico, FechaBuscar, esRepartoAbierto);
                    FechaBuscar = destruirFecha(FechaBuscar);
                    break;
                case 5:
                    printf("Ingrese la fecha de retorno [DD/MM/AA HH:MM]: ");
                    fflush(stdin);
                    scanf("%d %d %d %d %d", &diaBuscar,&mesBuscar,&anioBuscar,&horaBuscar,&minutosBuscar);
                    fflush(stdin);
                    FechaBuscar = crearFecha(diaBuscar,mesBuscar,anioBuscar,horaBuscar,minutosBuscar);
                    RepartoElegido = devolverRepartoFechaRetorno(centroLogistico, FechaBuscar, esRepartoAbierto);
                    FechaBuscar = destruirFecha(FechaBuscar);
                    break;
                case 6:
                    printf("Ingrese el ID: ");
                    ID_Buscar = seleccionarNumero();
                    RepartoElegido = devolverRepartoPaquete(centroLogistico, ID_Buscar, esRepartoAbierto);
                    break;
                default:
                    printf("Opcion equivocada... \n");
                    presionarEnterYLimpiarPantalla();
                    break;
            }
        }while(RepartoElegido == NULL);
    }
    return RepartoElegido;
}

void menuActualizarReparto(CentroLogisticoPtr centroLogistico)
{
    int eleccion = 0;
    int EstadoPaquete = 0;
    PaquetePtr paqueteActual;
    RepartoPtr RepartoActualizar;
    if(listaVacia(getRepartos(centroLogistico,true)))
    {
        printf("No existen repartos para actualizar...\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        RepartoActualizar = SeleccionRepartoPorAtributo(centroLogistico, true);
        ListaPtr paquetes = getPaquetesReparto(RepartoActualizar);
        ListaPtr listaRespaldo=crearLista();
        agregarLista(listaRespaldo,paquetes);
        while(!listaVacia(listaRespaldo))
        {
            paqueteActual = (PaquetePtr)getCabecera(listaRespaldo);
            EstadoPaquete = getEstado(paqueteActual);
            ///SI ES DISTINTO DE ENTREGADO Y SUSPENDIDO
            if(EstadoPaquete != 3 && EstadoPaquete != 5)
            {
                break;
            }
            ListaPtr ListaDestruir = listaRespaldo;
            listaRespaldo = getResto(listaRespaldo);
            ListaDestruir = destruirLista(ListaDestruir, false);
        }
        listaRespaldo = destruirLista(listaRespaldo,false);
        system("cls");
        helpEstadoPaquete();
        do
        {
            printf("El paquete que esta modificando es: \n");
            mostrarPaquete(paqueteActual);
            printf("SELECCIONE EL ESTADO: ");
            eleccion = seleccionarNumero();
            if(eleccion == 0)
            {
                printf("\n\n\t [Que haces seleccionando un paquete en estado 'DEPOSITO'?] \n\n");
                presionarEnterYLimpiarPantalla();
            }
            if(eleccion < 1 || eleccion > 6)
            {
                printf("\n\n\t [Eliga bien por favor...] \n\n");
                presionarEnterYLimpiarPantalla();
            }
        }while(eleccion < 1 || eleccion > 6);
        setEstado(paqueteActual,eleccion);
    }
}

void menuBuscarPorIndiceReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    int i = 0;
    RepartoPtr repartoBuscar;
    printf("Seleccione un reparto para buscar mediante su indice: ");
    i = menuModoAccion1(getRepartos(centroLogistico,esRepartoAbierto));
    system("cls");
    repartoBuscar=getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),i);
    mostrarReparto(repartoBuscar);
}

void menuBuscarRepartoPorCuilChofer(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    char cuilBuscar[100];
    RepartoPtr repartoMostrar;
    printf("\n\n Ingrese el cuil a buscar: \n\n");
    seleccionarString(cuilBuscar);
    repartoMostrar=devolverRepartoChofer(centroLogistico, cuilBuscar, esRepartoAbierto);
    if(repartoMostrar!=NULL)
    {
        system("cls");
        mostrarReparto(repartoMostrar);
    }
    else
    {
        system("cls");
        printf("\n\n\t [ERROR: Reparto no localizado...] \n\n");
        presionarEnterYLimpiarPantalla();
    }
}

void menuBuscarRepartoPorPatenteVehiculo(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    RepartoPtr repartoMostrar;
    char patenteBuscar[100];
    printf("Ingrese la patente a buscar: ");
    seleccionarString(patenteBuscar);
    repartoMostrar=devolverRepartoVehiculo(centroLogistico, patenteBuscar, esRepartoAbierto);
    if(repartoMostrar != NULL)
    {
        system("cls");
        mostrarReparto(repartoMostrar);
    }
    else
    {
        system("cls");
        printf("\n\n\t [ERROR: Reparto no localizado...] \n\n");
        presionarEnterYLimpiarPantalla();
    }
}

void menuBuscarRepartoPorFechaSalida(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    int dia,mes,anio,hora,minutos;
    FechaPtr fechaBuscar;
    RepartoPtr repartoMostrar;
    fflush(stdin);
    printf("Ingrese la fecha salida [DD/MM/AA - HH:MM]: ");
    scanf("%d %d %d %d %d", &dia,&mes,&anio,&hora,&minutos);
    fflush(stdin);
    fechaBuscar=crearFecha(dia,mes,anio,hora,minutos);
    repartoMostrar=devolverRepartoFechaSalida(centroLogistico,fechaBuscar, esRepartoAbierto);
    if(repartoMostrar != NULL)
    {
        system("cls");
        mostrarReparto(repartoMostrar);
    }
    else
    {
        system("cls");
        printf("\n\n\t [ERROR: Reparto no localizado...] \n\n");
        presionarEnterYLimpiarPantalla();
    }
    fechaBuscar=destruirFecha(fechaBuscar);
}

void menuBuscarRepartoPorFechaRetorno(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    int dia,mes,anio,hora,minutos;
    FechaPtr fechaBuscar;
    RepartoPtr repartoMostrar;
    fflush(stdin);
    printf("Ingrese la fecha salida [DD/MM/AA - HH:MM]: ");
    scanf("%d %d %d %d %d", &dia,&mes,&anio,&hora,&minutos);
    fflush(stdin);
    fechaBuscar=crearFecha(dia,mes,anio,hora,minutos);
    repartoMostrar=devolverRepartoFechaRetorno(centroLogistico,fechaBuscar, esRepartoAbierto);
    if(repartoMostrar != NULL)
    {
        system("cls");
        mostrarReparto(repartoMostrar);
    }
    else
    {
        system("cls");
        printf("\n\n\t [ERROR: Reparto no localizado...] \n\n");
        presionarEnterYLimpiarPantalla();
    }
    fechaBuscar=destruirFecha(fechaBuscar);
}

void menuBuscarRepartoPorIDPaquete(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    int ID;
    RepartoPtr repartoMostrar;
    printf("Ingrese ID para buscar: ");
    ID = seleccionarNumero();
    repartoMostrar = devolverRepartoPaquete(centroLogistico, ID, esRepartoAbierto);
    if(repartoMostrar != NULL)
    {
        system("cls");
        mostrarReparto(repartoMostrar);
    }
    else
    {
        system("cls");
        printf("\n\n\t [ERROR: Reparto no localizado...] \n\n");
        presionarEnterYLimpiarPantalla();
    }
}

void menuBuscarReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    int eleccion=0;
    bool continuar=false;
    if(listaVacia(getRepartos(centroLogistico,esRepartoAbierto)))
    {
        printf("ERROR: Lista vacia. No hay repartos para buscar\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            system("cls");
            eleccion = menuTipoRepartos();
            if(eleccion != 0)
            {
                mostrarRepartos(centroLogistico,esRepartoAbierto);
            }
            switch(eleccion)
            {
                case 1:
                    menuBuscarPorIndiceReparto(centroLogistico, esRepartoAbierto);
                    break;
                case 2:
                    menuBuscarRepartoPorCuilChofer(centroLogistico, esRepartoAbierto);
                    break;
                case 3:
                    menuBuscarRepartoPorPatenteVehiculo(centroLogistico, esRepartoAbierto);
                    break;
                case 4:
                    menuBuscarRepartoPorFechaSalida(centroLogistico, esRepartoAbierto);
                    break;
                case 5:
                    menuBuscarRepartoPorFechaRetorno(centroLogistico, esRepartoAbierto);
                    break;
                case 6:
                    menuBuscarRepartoPorIDPaquete(centroLogistico, esRepartoAbierto);
                    break;
                case 0:
                    break;
                default:
                    printf("\n\n\t [Opcion invalida...] \n\n");
                    presionarEnterYLimpiarPantalla();
                    break;
            }
            if(eleccion == 0)
            {
                continuar = false;
            }
            else
            {
                continuar=menuContinuar();
            }
        }while(continuar);
    }
}


bool menuMostrarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto, int* op1)
{
	int Main_1=0,Main_2=0,i=0;
    bool cambiosGuardados = false;
    if(listaVacia(getRepartos(centroLogistico,esRepartoAbierto)))
    {
        printf("Lista de repartos vacia, por favor, agregue elementos para mostrar\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            system("cls");
            if(esRepartoAbierto)
            {
                printf("EMITIR LISTADO DE REPARTOS ABIERTOS\n");
            }
            else
            {
                printf("EMITIR LISTADO DE REPARTOS CERRADOS\n");
            }
            Main_1=menuListadoReparto();
            switch(Main_1)
            {
            case 1:
                mostrarRepartos(centroLogistico,esRepartoAbierto);
                printf("\nSeleccione un reparto para mostrar:");
                i = menuModoAccion1(getRepartos(centroLogistico,esRepartoAbierto));
                system("cls");
                mostrarReparto(getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),i));
                system("pause");
                break;
            case 2:
                do
                {
                    Main_2=menuOrdenarRepartos();
                    switch(Main_2)
                    {
                    case 1:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,1);
                        break;
                    case 2:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,2);
                        break;
                    case 3:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,3);
                        break;
                    case 4:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,4);
                        break;
                    case 5:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,5);
                        break;
                    case 6:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,6);
                        break;
                    case 7:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,7);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opcion incorrecta.\n\n");
                        break;
                    }
                    system("cls");
                } while(Main_2!=0);
                break;
            case 0:
                break;
           case -1:
                *op1 = 0;
                Main_1 = 0;
                Main_2 = 0;
                break;
            default:
                printf("Opcion incorrecta\n\n");
                break;
            }
        } while(Main_1!=0);
    }
    return cambiosGuardados;
}

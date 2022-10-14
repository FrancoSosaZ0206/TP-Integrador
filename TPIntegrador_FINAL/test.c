#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "TDACentroLogistico.h"
#include "test.h"
#include "util.h"
#include "TDARepartos.h"
#include "Files.h"

ListaPtr crearListaRepartosPorDefectoConLista(){
    ListaPtr listaRepartos=crearLista();
    DomicilioPtr domicilioChofer1=crearDomicilio("Vieytes",2000,"Lomas de zamora");
    DomicilioPtr dirRetiro1=crearDomicilio("Deposito",5000,"Sector industrial"); /// (*)
    DomicilioPtr dirEntrega1=crearDomicilio("Santa fe",1500,"Banfield"); /// (**)
    FechaPtr fechaSalida1=crearFechaDirect(2500000,16,45); //Para el reparto
    FechaPtr fechaRetorno1=crearFechaDirect(2500000,17,45); //Para el reparto
    FechaPtr fechaEntrega1=crearFechaDirect(2500000,18,45);
    CuilPtr cuil1=crearCuil("20346547546");
    PersonaPtr chofer1=crearPersona("Roberto","Garcia",domicilioChofer1,cuil1,true);
    PaquetePtr paquete1=crearPaquete(1,4,5,2,65,dirRetiro1,dirEntrega1,fechaEntrega1,0);
    VehiculoPtr vehiculo1=crearVehiculo(3,"Mercedes Benz","Actros","17 UJI 30");
    ListaPtr listaPaquetes=crearLista();
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete1);
    RepartoPtr reparto1=0;
    reparto1=crearReparto(chofer1,vehiculo1,fechaSalida1,fechaRetorno1,listaPaquetes);

    DomicilioPtr domicilioChofer2=crearDomicilio("Boqueron",1500,"Villa Fiorito");
    DomicilioPtr dirRetiro2=crearDomicilio("Repositorio Intel",5000,"Sector industrial");
    DomicilioPtr dirEntrega2=crearDomicilio("Italia",3000,"Palermo");
    FechaPtr fechaSalida2=crearFechaDirect(2500000,8,30);
    FechaPtr fechaRetorno2=crearFechaDirect(2500000,9,30);
    FechaPtr fechaEntrega2=crearFechaDirect(2500000,10,30);
    CuilPtr cuil2=crearCuil("27245764567");
    PersonaPtr chofer2=crearPersona("Maria","Gonzalez",domicilioChofer2,cuil2,true);
    PaquetePtr paquete2=crearPaquete(2,2,5,3,120,dirRetiro2,dirEntrega2,fechaEntrega2,0);
    ListaPtr listaPaquetes2=crearLista();
    agregarDatoLista(listaPaquetes2,(PaquetePtr)paquete2);
    VehiculoPtr vehiculo2=crearVehiculo(3,"Mercedes Benz","Actros","81 NMB 30");
    RepartoPtr reparto2=0;
    reparto2=crearReparto(chofer2,vehiculo2,fechaSalida2,fechaRetorno2,listaPaquetes2);

    DomicilioPtr domicilioChofer3=crearDomicilio("Espania",1500,"Puerto Madero");
    DomicilioPtr dirRetiro3=crearDomicilio("Tesla Industry",10000,"Washington DC");
    DomicilioPtr dirEntrega3=crearDomicilio("24 de mayo",3000,"Capital Federal");
    FechaPtr fechaSalida3=crearFechaDirect(2500000,19,15);
    FechaPtr fechaRetorno3=crearFechaDirect(2500000,21,15);
    FechaPtr fechaEntrega3=crearFechaDirect(2500000,22,15);
    CuilPtr cuil3=crearCuil("30234565431");
    PersonaPtr chofer3=crearPersona("Gonzalo","Gutierrez",domicilioChofer3,cuil3,true);
    PaquetePtr paquete3=crearPaquete(3,8,8,10,800,dirRetiro3,dirEntrega3,fechaEntrega3,0);
    ListaPtr listaPaquetes3=crearLista();
    agregarDatoLista(listaPaquetes3,(PaquetePtr)paquete3);
    VehiculoPtr vehiculo3=crearVehiculo(3,"Mercedes Benz","Actros","19 JUY 78");
    RepartoPtr reparto3=0;
    reparto3=crearReparto(chofer3,vehiculo3,fechaSalida3,fechaRetorno3,listaPaquetes3);

    agregarDatoLista(listaRepartos,(RepartoPtr)reparto1);
    agregarDatoLista(listaRepartos,(RepartoPtr)reparto2);
    agregarDatoLista(listaRepartos,(RepartoPtr)reparto3);
    return listaRepartos;
}

ListaPtr crearListaPaquetesGenerico(){
    ListaPtr listaPaquetes = crearLista();
    PaquetePtr paquete1 = crearPaqueteDirect(rand(),4,2,5,150,"Sixto Fernandez",1800,"Lomas de Zamora","Calle Morazan",2100,"Villa fiorito",10,12,2022,16,45,0);
    PaquetePtr paquete2 = crearPaqueteDirect(rand(),20,7,3,200,"Sixto Fernandez",1700,"Lomas de Zamora","Calle Morazan",2020,"Villa fiorito",10,12,2022,17,45,0);
    PaquetePtr paquete3 = crearPaqueteDirect(rand(),15,5,9,75,"Sixto Fernandez",1220,"Lomas de Zamora","Calle Morazan",2310,"Villa fiorito",10,12,2022,18,45,0);
    PaquetePtr paquete4 = crearPaqueteDirect(rand(),25,14,15,54,"Sixto Fernandez",5000,"Lomas de Zamora","Calle Morazan",250,"Villa fiorito",10,12,2022,19,45,0);
    PaquetePtr paquete5 = crearPaqueteDirect(rand(),12,11,23,54,"Sixto Fernandez",1000,"Lomas de Zamora","Calle Morazan",650,"Villa fiorito",10,12,2022,20,45,0);
    PaquetePtr paquete6 = crearPaqueteDirect(rand(),14,16,31,54,"Sixto Fernandez",2000,"Lomas de Zamora","Calle Morazan",550,"Villa fiorito",10,12,2022,21,45,0);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete1);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete2);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete3);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete4);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete5);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete6);
    return listaPaquetes;
}

ListaPtr crearListaPersonasGenerica()
{
    ListaPtr personas = crearLista();
    DomicilioPtr domicilio1 = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    CuilPtr cuil_1 = crearCuil("20654342349");
    PersonaPtr cliente1 = crearPersona("Javier","Gonzalez",domicilio1,cuil_1,false);

    DomicilioPtr domicilio2 = crearDomicilio("Italia",1000,"Lomas de zamora");
    CuilPtr cuil_2 = crearCuil("20655612339");
    PersonaPtr cliente2 = crearPersona("Gonzalo","Gutierrez",domicilio2,cuil_2,false);

    DomicilioPtr domicilio3 = crearDomicilio("Espania",3000,"Lomas de zamora");
    CuilPtr cuil_3 = crearCuil("20245432349");
    PersonaPtr cliente3 = crearPersona("Gabriel","Alonzo",domicilio3,cuil_3,false);

    DomicilioPtr domicilio4 = crearDomicilio("9 de mayo",2000,"Lomas de zamora");
    CuilPtr cuil_4 = crearCuil("20126543212");
    PersonaPtr cliente4 = crearPersona("Alfonso","Romero",domicilio4,cuil_4,false);

    DomicilioPtr domicilio5 = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    CuilPtr cuil_5 = crearCuil("20654342349");
    PersonaPtr chofer1 = crearPersona("Javier","Gonzalez",domicilio5,cuil_5,true);

    DomicilioPtr domicilio6 = crearDomicilio("Italia",1000,"Lomas de zamora");
    CuilPtr cuil_6 = crearCuil("20655612339");
    PersonaPtr chofer2 = crearPersona("Gonzalo","Gutierrez",domicilio6,cuil_6,true);

    DomicilioPtr domicilio7 = crearDomicilio("Espania",3000,"Lomas de zamora");
    CuilPtr cuil_7 = crearCuil("20245432349");
    PersonaPtr chofer3 = crearPersona("Gabriel","Alonzo",domicilio7,cuil_7,true);

    DomicilioPtr domicilio8 = crearDomicilio("9 de mayo",2000,"Lomas de zamora");
    CuilPtr cuil_8 = crearCuil("20126543212");
    PersonaPtr chofer4 = crearPersona("Alfonso","Romero",domicilio8,cuil_8,true);

    agregarDatoLista(personas,(PersonaPtr)chofer1);
    agregarDatoLista(personas,(PersonaPtr)chofer2);
    agregarDatoLista(personas,(PersonaPtr)chofer3);
    agregarDatoLista(personas,(PersonaPtr)chofer4);

    agregarDatoLista(personas,(PersonaPtr)cliente1);
    agregarDatoLista(personas,(PersonaPtr)cliente2);
    agregarDatoLista(personas,(PersonaPtr)cliente3);
    agregarDatoLista(personas,(PersonaPtr)cliente4);

    return personas;
}

ListaPtr clientesGenericos()
{
    ListaPtr clientes = crearLista();
    DomicilioPtr domicilio1 = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    CuilPtr cuil_1 = crearCuil("20654342349");
    PersonaPtr cliente1 = crearPersona("Javier","Gonzalez",domicilio1,cuil_1,false);

    DomicilioPtr domicilio2 = crearDomicilio("Italia",1000,"Lomas de zamora");
    CuilPtr cuil_2 = crearCuil("20655612339");
    PersonaPtr cliente2 = crearPersona("Gonzalo","Gutierrez",domicilio2,cuil_2,false);

    DomicilioPtr domicilio3 = crearDomicilio("Espania",3000,"Lomas de zamora");
    CuilPtr cuil_3 = crearCuil("20245432349");
    PersonaPtr cliente3 = crearPersona("Gabriel","Alonzo",domicilio3,cuil_3,false);

    DomicilioPtr domicilio4 = crearDomicilio("9 de mayo",2000,"Lomas de zamora");
    CuilPtr cuil_4 = crearCuil("20126543212");
    PersonaPtr cliente4 = crearPersona("Alfonso","Romero",domicilio4,cuil_4,false);

    agregarDatoLista(clientes,(PersonaPtr)cliente1);
    agregarDatoLista(clientes,(PersonaPtr)cliente2);
    agregarDatoLista(clientes,(PersonaPtr)cliente3);
    agregarDatoLista(clientes,(PersonaPtr)cliente4);

    return clientes;
}

ListaPtr choferesGenericos()
{
    ListaPtr choferes=crearLista();
    DomicilioPtr domicilio5 = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    CuilPtr cuil_5 = crearCuil("20654342349");
    PersonaPtr chofer1 = crearPersona("Javier","Gonzalez",domicilio5,cuil_5,true);

    DomicilioPtr domicilio6 = crearDomicilio("Italia",1000,"Lomas de zamora");
    CuilPtr cuil_6 = crearCuil("20655612339");
    PersonaPtr chofer2 = crearPersona("Gonzalo","Gutierrez",domicilio6,cuil_6,true);

    DomicilioPtr domicilio7 = crearDomicilio("Espania",3000,"Lomas de zamora");
    CuilPtr cuil_7 = crearCuil("20245432349");
    PersonaPtr chofer3 = crearPersona("Gabriel","Alonzo",domicilio7,cuil_7,true);

    DomicilioPtr domicilio8 = crearDomicilio("9 de mayo",2000,"Lomas de zamora");
    CuilPtr cuil_8 = crearCuil("20126543212");
    PersonaPtr chofer4 = crearPersona("Alfonso","Romero",domicilio8,cuil_8,true);

    agregarDatoLista(choferes,(PersonaPtr)chofer1);
    agregarDatoLista(choferes,(PersonaPtr)chofer2);
    agregarDatoLista(choferes,(PersonaPtr)chofer3);
    agregarDatoLista(choferes,(PersonaPtr)chofer4);
    return choferes;
}

ListaPtr crearListaVehiculosGenerico(){
    ListaPtr listaVehiculos = crearLista();
    VehiculoPtr vehiculo1=crearVehiculo(3,"Mercedes Benz","Actros","99 UJI 99");
    VehiculoPtr vehiculo2=crearVehiculo(3,"Ferrari","Benne","65MNJ91");
    VehiculoPtr vehiculo3=crearVehiculo(3,"Volkswagen","17720","98 UYT 98");
    VehiculoPtr vehiculo4=crearVehiculo(3,"Ford","C916","97 JUI 97");
    agregarDatoLista(listaVehiculos,(VehiculoPtr)vehiculo1);
    agregarDatoLista(listaVehiculos,(VehiculoPtr)vehiculo2);
    agregarDatoLista(listaVehiculos,(VehiculoPtr)vehiculo3);
    agregarDatoLista(listaVehiculos,(VehiculoPtr)vehiculo4);
    return listaVehiculos;
}


void probandoGenericas(CentroLogisticoPtr cl)
{
    system("cls");
    mostrarRepartos(cl,true);
    system("pause");
    system("cls");
    mostrarPaquetes(cl);
    system("pause");
    system("cls");
    mostrarVehiculos(cl);
    system("pause");
    system("cls");
    mostrarPersonas(cl,3);
    system("pause");
    system("cls");
}

void verificacion(bool resultado)
{
    if(resultado)
    {
        printf("FUNCIONA CORRECTAMETE!!!\n");
    }
    else
    {
        printf("NO FUNCIONA ADECUADAMENTE!!!\n");
    }
}



/*
///NUEVA
void cerrarReparto(CentroLogisticoPtr centroLogistico, int posicion)
{ ///extraemos el reparto de la lista de abiertos
    RepartoPtr repartoACerrar = removerReparto(centroLogistico,posicion,true);
///Copiamos el contenido del reparto en uno nuevo.
    PersonaPtr copiaChofer = crearPersonaDirect(getNombre(getChofer(repartoACerrar)),
                                                getApellido(getChofer(repartoACerrar)),
                                                getCalle(getDomicilio(getChofer(repartoACerrar))),
                                                getAltura(getDomicilio(getChofer(repartoACerrar))),
                                                getLocalidad(getDomicilio(getChofer(repartoACerrar))),
                                                getCuil(getCuilPersona(getChofer(repartoACerrar))),
                                                getEsChofer(getChofer(repartoACerrar)));

    VehiculoPtr copiaVehiculo = crearVehiculo(getTipoVehiculo(getVehiculo(repartoACerrar)),
                                              getMarca(getVehiculo(repartoACerrar)),
                                              getModelo(getVehiculo(repartoACerrar)),
                                              getPatente(getVehiculo(repartoACerrar)));

    FechaPtr copiaFechaSalida = crearFechaDirect(getDiaJuliano(getFechaSalida(repartoACerrar)),
                                                 getHora(getFechaSalida(repartoACerrar)),
                                                 getMinuto(getFechaSalida(repartoACerrar)));

    FechaPtr copiaFechaRetorno = crearFechaDirect(getDiaJuliano(getFechaRetorno(repartoACerrar)),
                                                 getHora(getFechaRetorno(repartoACerrar)),
                                                 getMinuto(getFechaRetorno(repartoACerrar)));

///Obtenemos cada paquete de la pila y le cambiamos el estado a 3: "entregado"
    int n=longitudLista(getPaquetesReparto(repartoACerrar));
    PaquetePtr paquetesAux[n];

    PaquetePtr copiaPaquetes[n];
    PilaPtr copiaPilaPaquetes=crearPila();

    int estadoPaquetes[6];
    for(int i=0;i<n;i++)
    {
        paquetesAux[i] = descargarPaquete(repartoACerrar);
    ///Hacemos una copia de cada paquete
        copiaPaquetes[i]  = crearPaqueteDirect(getID(paquetesAux[i]),
                                               getAncho(paquetesAux[i]),
                                               getAlto(paquetesAux[i]),
                                               getLargo(paquetesAux[i]),
                                               getPeso(paquetesAux[i]),
                                               getCalle(getDirRetiro(paquetesAux[i])),
                                               getAltura(getDirRetiro(paquetesAux[i])),
                                               getLocalidad(getDirRetiro(paquetesAux[i])),
                                               getCalle(getDirEntrega(paquetesAux[i])),
                                               getAltura(getDirEntrega(paquetesAux[i])),
                                               getLocalidad(getDirEntrega(paquetesAux[i])),
                                               getDia(getFechaEntrega(paquetesAux[i])),
                                               getMes(getFechaEntrega(paquetesAux[i])),
                                               getAnio(getFechaEntrega(paquetesAux[i])),
                                               getHora(getFechaEntrega(paquetesAux[i])),
                                               getMinuto(getFechaEntrega(paquetesAux[i])),
                                               getEstado(paquetesAux[i]));
    ///Salvamos el conjunto de estados de los paquetes de la pila como valores de verdad en un vector de enteros
        switch(getEstado(paquetesAux[i]))
        {
        case 0:
            estadoPaquetes[0]=1;
            break;
        case 1:
            estadoPaquetes[1]=1;
            break;
        case 2:
            estadoPaquetes[2]=1;
            break;
        case 3:
            estadoPaquetes[3]=1;
            break;
        case 4:
            estadoPaquetes[4]=1;
            break;
        case 5:
            estadoPaquetes[5]=1;
            break;
        }
    }
    for(int i=n;i>0;i--)
    {
        cargarPaquete(repartoACerrar,paquetesAux[i]);
        apilar(copiaPilaPaquetes,(PaquetePtr)copiaPaquetes[i]);
    }

    RepartoPtr copiaReparto=armarReparto(copiaChofer,
                                         copiaVehiculo,
                                         copiaFechaSalida,
                                         copiaFechaRetorno,
                                         copiaPilaPaquetes);

///Agregamos la copia del reparto cerrado a la lista de cerrados
    agregarReparto(centroLogistico,copiaReparto,false);
///Destruimos el reparto original
    repartoACerrar=destruirReparto(repartoACerrar);

    printf("\n\nCerrando reparto...\n\n");
    bool condicion = estadoPaquetes[0]==0;
    condicion = condicion && estadoPaquetes[1]==0;
    condicion = condicion && estadoPaquetes[2]==0;
    condicion = condicion && estadoPaquetes[3]==1;
    condicion = condicion && estadoPaquetes[4]==0;
    condicion = condicion && estadoPaquetes[5]==0;
///Imprimimos un mensaje informativo acerca del estado de los paquetes
    if(condicion)
        printf("Todos los paquetes fueron entregados con exito.\n\n");
    else if(estadoPaquetes[0]==1)
        printf("ADVERTENCIA: Quedaron paquetes marcados como 'EN DEPOSITO'.\n\n");
    else if(estadoPaquetes[1]==1 || estadoPaquetes[2]==1)
        printf("Quedaron paquetes sin entregar. Revisarlos y reasignarlos a un nuevo reparto.\n\n");
    else if(estadoPaquetes[4]==1)
        printf("Algunos paquetes estan demorados. Revisarlos y reasignarlos a un nuevo reparto.\n\n");
    else if(estadoPaquetes[5]==1)
        printf("Se suspendieron algunos paquetes. Revisarlos y reasignarlos a un nuevo reparto.\n\n");
}
*/
/*
PaquetePtr copiaPaquete(PaquetePtr PC)
{
    PaquetePtr paqueteCopiado;
    ///---------------------------------------------------------------------------///
    paqueteCopiado  = crearPaqueteDirect(getID(PC),getAncho(PC),getAlto(PC),getLargo(PC),getPeso(PC),getCalle(getDirRetiro(PC)),
    getAltura(getDirRetiro(PC)),getLocalidad(getDirRetiro(PC)),getCalle(getDirEntrega(PC)),getAltura(getDirEntrega(PC)),
    getLocalidad(getDirEntrega(PC)),getDia(getFechaEntrega(PC)),getMes(getFechaEntrega(PC)),getAnio(getFechaEntrega(PC)),
    getHora(getFechaEntrega(PC)),getMinuto(getFechaEntrega(PC)),getEstado(PC));
    ///---------------------------------------------------------------------------///
    return paqueteCopiado;
}
*/
/*

///Getters
//  Cuil
char *fgetCuil(fCuilPtr pfcuil)
{
    return pfcuil->cuil;
}
//  Domicilio
char *fgetCalle(fDomicilioPtr pfdomicilio)
{
    return pfdomicilio->calle;
}
int fgetAltura(fDomicilioPtr pfdomicilio)
{
    return pfdomicilio->altura;
}
char *fgetLocalidad(fDomicilioPtr pfdomicilio)
{
    return pfdomicilio->localidad;
}
//  Fecha
int fgetDiaJuliano(fFechaPtr pffecha) //no necesitamos pasar los días, meses y anios.
{
    return pffecha->diaJuliano;
}
int fgetHora(fFechaPtr pffecha)
{
    return pffecha->hora;
}
int fgetMinuto(fFechaPtr pffecha)
{
    return pffecha->minuto;
}
//  Persona
char *fgetNombre(fPersonaPtr pfpersona)
{
    return pfpersona->nombre;
}
char *fgetApellido(fPersonaPtr pfpersona)
{
    return pfpersona->apellido;
}
fDomicilioPtr fgetDomicilio(fPersonaPtr pfpersona)
{
    return &pfpersona->domicilio;
}
fCuilPtr fgetCuilPersona(fPersonaPtr pfpersona)
{
    fCuilPtr pfcuil = &pfpersona->cuil;
    return pfcuil;
}
bool fgetEsChofer(fPersonaPtr pfpersona)
{
    return pfpersona->esChofer;
}
//  Paquete
int fgetID(fPaquetePtr pfpaquete)
{
    return pfpaquete->ID;
}
int fgetAncho(fPaquetePtr pfpaquete)
{
    return pfpaquete->ancho;
}
int fgetAlto(fPaquetePtr pfpaquete)
{
    return pfpaquete->alto;
}
int fgetLargo(fPaquetePtr pfpaquete)
{
    return pfpaquete->largo;
}
int fgetPeso(fPaquetePtr pfpaquete)
{
    return pfpaquete->peso;
}
fDomicilioPtr fgetDirRetiro(fPaquetePtr pfpaquete)
{
    return &pfpaquete->dirRetiro;
}
fDomicilioPtr fgetDirEntrega(fPaquetePtr pfpaquete)
{
    return &pfpaquete->dirEntrega;
}
fFechaPtr fgetFechaEntrega(fPaquetePtr pfpaquete)
{
    return &pfpaquete->fechaEntrega;
}
int fgetEstado(fPaquetePtr pfpaquete)
{
    return pfpaquete->estado;
}
//  Vehiculo
int fgetTipoVehiculo(fVehiculoPtr pfvehiculo)
{
    return pfvehiculo->tipo;
}
char *fgetMarca(fVehiculoPtr pfvehiculo)
{
    return pfvehiculo->marca;
}
char *fgetModelo(fVehiculoPtr pfvehiculo)
{
    return pfvehiculo->modelo;
}
char *fgetPatente(fVehiculoPtr pfvehiculo)
{
    return pfvehiculo->patente;
}
//  Reparto
fPersonaPtr fgetChofer(fRepartoPtr pfreparto)
{
    return &pfreparto->chofer;
}
fVehiculoPtr fgetVehiculo(fRepartoPtr pfreparto)
{
    return &pfreparto->vehiculo;
}
fFechaPtr fgetFechaSalida(fRepartoPtr pfreparto)
{
    return &pfreparto->fechaSalida;
}
fFechaPtr fgetFechaRetorno(fRepartoPtr pfreparto)
{
    return &pfreparto->fechaRetorno;
}

///este si retorna puntero x q almacenamos los paquetes como array.
fPaquete *fgetPaquetesReparto(fRepartoPtr pfreparto)
{
    return pfreparto->paquetes;
}



///Setters

Se puede setear toda la estructura de una.
Postcondición: si setParaGuardar == true, setea cuil en fCuil.
               De lo contrario, hace el proceso inverso (ayuda a la hora de abrir un archivo).

void fsetCuil(fCuilPtr fcuil,CuilPtr cuil,bool setParaGuardar)
{
    if(setParaGuardar)
        strcpy(fcuil->cuil,getCuil(cuil));
    else ///asumimos que la estructura está vacía y la creamos.
        cuil=crearCuil(fgetCuil(fcuil));
}
void fsetDomicilio(fDomicilioPtr pfdomicilio,DomicilioPtr domicilio,bool setParaGuardar)
{
    if(setParaGuardar)
    {
        strcpy(pfdomicilio->calle,getCalle(domicilio));
        pfdomicilio->altura=getAltura(domicilio);
        strcpy(pfdomicilio->localidad,getLocalidad(domicilio));
    }
    else ///asumimos que la estructura está vacía y la creamos.
        domicilio=crearDomicilio(fgetCalle(pfdomicilio),fgetAltura(pfdomicilio),fgetLocalidad(pfdomicilio));
}
void fsetFecha(fFechaPtr pffecha,FechaPtr fecha,bool setParaGuardar)
{
    if(setParaGuardar)
    {
        pffecha->diaJuliano=getDiaJuliano(fecha);
        pffecha->hora=getHora(fecha);
        pffecha->minuto=getMinuto(fecha);
    }
    else ///asumimos que la estructura está vacía y la creamos.
        fecha = crearFechaDirect(fgetDiaJuliano(pffecha),fgetHora(pffecha),fgetMinuto(pffecha));
}
void fsetPersona(fPersonaPtr pfpersona,PersonaPtr persona,bool setParaGuardar)
{
    if(setParaGuardar)
    {
        strcpy(pfpersona->nombre,getNombre(persona));
        strcpy(pfpersona->apellido,getApellido(persona));

        fsetDomicilio(fgetDomicilio(pfpersona),getDomicilio(persona),true);
        fsetCuil(fgetCuilPersona(pfpersona),getCuilPersona(persona),true); ///MUCHO OJO: TODAVIA NO SE CAMBIO EL NOMBRE ORIGINAL, SE DEBE HACER ESO PARA QUE FUNCIONE.

        pfpersona->esChofer=getEsChofer(persona);
    }
    else ///asumimos que la estructura está vacía y la creamos.
    {
        DomicilioPtr domicilio=0;
        CuilPtr cuil=0;
        fsetDomicilio(fgetDomicilio(pfpersona),domicilio,false);
        fsetCuil(fgetCuilPersona(pfpersona),cuil,false);
        persona=crearPersona(fgetNombre(pfpersona),fgetApellido(pfpersona),domicilio,cuil,fgetEsChofer(pfpersona));
    }
}
void fsetPaquete(fPaquetePtr pfpaquete,PaquetePtr paquete,bool setParaGuardar)
{
    if(setParaGuardar)
    {
        pfpaquete->ID=getID(paquete);
        pfpaquete->ancho=getAncho(paquete);
        pfpaquete->alto=getAlto(paquete);
        pfpaquete->largo=getLargo(paquete);
        pfpaquete->peso=getPeso(paquete);

        fsetDomicilio(fgetDirRetiro(pfpaquete),getDirRetiro(paquete),true);
        fsetDomicilio(fgetDirEntrega(pfpaquete),getDirEntrega(paquete),true);
        fsetFecha(fgetFechaEntrega(pfpaquete),getFechaEntrega(paquete),true);

        pfpaquete->estado=getEstado(paquete);
    }
    else ///asumimos que la estructura está vacía y la creamos.
    {
        DomicilioPtr dirRetiro=0;
        DomicilioPtr dirEntrega=0;
        FechaPtr fechaEntrega=0;

        fsetDomicilio(fgetDirRetiro(pfpaquete),dirRetiro,false);
        fsetDomicilio(fgetDirEntrega(pfpaquete),dirEntrega,false);
        fsetFecha(fgetFechaEntrega(pfpaquete),fechaEntrega,false);

        paquete=crearPaquete(fgetID(pfpaquete),fgetAncho(pfpaquete),fgetAlto(pfpaquete),fgetLargo(pfpaquete),fgetPeso(pfpaquete),dirRetiro,dirEntrega,fechaEntrega,fgetEstado(pfpaquete));
    }
}
void fsetVehiculo(fVehiculoPtr pfvehiculo,VehiculoPtr vehiculo,bool setParaGuardar)
{
    if(setParaGuardar)
    {
        pfvehiculo->tipo=getTipoVehiculo(vehiculo);

        strcpy(pfvehiculo->marca,getMarca(vehiculo));
        strcpy(pfvehiculo->modelo,getModelo(vehiculo));
        strcpy(pfvehiculo->patente,getPatente(vehiculo));
    }
    else ///asumimos que la estructura está vacía y la creamos.
        vehiculo=crearVehiculo(fgetTipoVehiculo(pfvehiculo),fgetMarca(pfvehiculo),fgetModelo(pfvehiculo),fgetPatente(pfvehiculo));
}
void fsetReparto(fRepartoPtr pfreparto,RepartoPtr reparto,bool setParaGuardar)
{
    int n=0;
    PaquetePtr paqueteAux=0;

    if(setParaGuardar)
    {
        fsetPersona(fgetChofer(pfreparto),getChofer(reparto),true);
        fsetVehiculo(fgetVehiculo(pfreparto),getVehiculo(reparto),true);
        fsetFecha(fgetFechaSalida(pfreparto),getFechaSalida(reparto),true);
        fsetFecha(fgetFechaRetorno(pfreparto),getFechaRetorno(reparto),true);

        while(!pilaVacia(getPaquetesReparto(reparto)))
        {
            paqueteAux = descargarPaquete(reparto);
            fsetPaquete(&pfreparto->paquetes[n],paqueteAux,true);
            n++;
        }
        pfreparto->tamanioPilaPaq = n;
    }
    else ///asumimos que la estructura está vacía y la creamos.
    {
        PersonaPtr chofer=0;
        VehiculoPtr vehiculo=0;
        FechaPtr fechaSalida=0;
        FechaPtr fechaRetorno=0;

        fsetPersona(fgetChofer(pfreparto),chofer,false);
        fsetVehiculo(fgetVehiculo(pfreparto),vehiculo,false);
        fsetFecha(fgetFechaSalida(pfreparto),fechaSalida,false);
        fsetFecha(fgetFechaRetorno(pfreparto),fechaRetorno,false);

        PilaPtr paquetes = crearPila();
        n=pfreparto->tamanioPilaPaq;

        for(int i=n;i>0;i--) ///lo hacemos al revés para mantener el orden original de la pila.
        {
            fsetPaquete(&pfreparto->paquetes[i],paqueteAux,false);
            apilar(paquetes,(PaquetePtr)paqueteAux);
        }
        reparto = crearReparto(chofer,vehiculo,fechaSalida,fechaRetorno,paquetes);
    }
    paqueteAux = NULL;
}




///                                             FUNCIONES PÚBLICAS/DE LA INTERFAZ

//  listas de datos / estructuras
bool guardarPersonas(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Personas.txt","w");

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
        int n = longitudLista(getPersonas(centroLogistico));
        fwrite(&n,sizeof(int),1,archivo);

        fPersona fpersona;
        ListaPtr listaAux = crearLista();
        agregarLista(listaAux , getPersonas(centroLogistico));

        while(!listaVacia(listaAux))
        {
            PersonaPtr personaAux = (PersonaPtr)getCabecera(listaAux);
            fsetPersona(&fpersona,personaAux,true);

            fwrite(&fpersona,sizeof(fPersona),1,archivo);

            listaAux=getResto(listaAux);
        }
        listaAux=destruirLista(listaAux,false);

        fclose(archivo);
        return true;
    }
}
bool guardarPaquetes(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Paquetes.txt","w");

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
        int n = longitudLista(getPaquetes(centroLogistico));
        fwrite(&n,sizeof(int),1,archivo);

        fPaquete fpaquete;
        ListaPtr listaAux = crearLista();
        agregarLista(listaAux , getPaquetes(centroLogistico));

        while(!listaVacia(listaAux))
        {
            PaquetePtr paqueteAux = (PaquetePtr)getCabecera(listaAux);
            fsetPaquete(&fpaquete,paqueteAux,true);

            fwrite(&fpaquete,sizeof(fPaquete),1,archivo);

            listaAux=getResto(listaAux);
        }
        listaAux=destruirLista(listaAux,false);

        fclose(archivo);
        return true;
    }
}
bool guardarVehiculos(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Vehiculos.txt","w");

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
        int n = longitudLista(getVehiculos(centroLogistico));
        fwrite(&n,sizeof(int),1,archivo);

        fVehiculo fvehiculo;
        ListaPtr listaAux = crearLista();
        agregarLista(listaAux , getVehiculos(centroLogistico));

        while(!listaVacia(listaAux))
        {
            VehiculoPtr vehiculoAux = (VehiculoPtr)getCabecera(listaAux);
            fsetVehiculo(&fvehiculo,vehiculoAux,true);

            fwrite(&fvehiculo,sizeof(fVehiculo),1,archivo);

            listaAux=getResto(listaAux);
        }
        listaAux=destruirLista(listaAux,false);

        fclose(archivo);
        return true;
    }
}
bool guardarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    FILE *archivo;
	if(esRepartoAbierto)
		archivo = fopen("Lista de Repartos Abiertos.txt","w");
	else
		archivo = fopen("Lista de Repartos Cerrados.txt","w");

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, guardamos primero la cantidad de elementos de la lista
        int n; ///guardamos primero la cantidad de elementos de la lista
		if(esRepartoAbierto)
			n = longitudLista(getRepartos(centroLogistico,true));
		else
			n = longitudLista(getRepartos(centroLogistico,false));

        fwrite(&n,sizeof(int),1,archivo);

        fReparto freparto;
        ListaPtr listaAux = crearLista();
        if(esRepartoAbierto)
			agregarLista(listaAux,getRepartos(centroLogistico,true));
		else
			agregarLista(listaAux,getRepartos(centroLogistico,false));

        while(!listaVacia(listaAux))
        {
            RepartoPtr repartoAux = (RepartoPtr)getCabecera(listaAux);
            fsetReparto(&freparto,repartoAux,true);

            fwrite(&freparto,sizeof(fReparto),1,archivo);

            listaAux=getResto(listaAux);
        }
        listaAux=destruirLista(listaAux,false);

        fclose(archivo);
        return true;
    }
}
//  general
bool guardarTodo(CentroLogisticoPtr centroLogistico) //implementacion: llamará a las otras funciones de guardado
{
    FILE *archivo = fopen("Nombre del Centro Logistico.txt","w");
    bool res = true; //a diferencia de las funciones anteriores, usamos una bandera para juntar al conjugado.
    if(archivo==NULL)
        res=false;
    else
    {
        char temp[100];
        strcpy(temp,getNombreCentroLogistico(centroLogistico));
        fwrite(temp,sizeof(char),100,archivo);
        fclose(archivo);
    }
    res = res && guardarPaquetes(centroLogistico);
    res = res && guardarPersonas(centroLogistico);
    res = res && guardarVehiculos(centroLogistico);
    res = res && GuardarRepartosNuevo(centroLogistico,true);
    res = res && GuardarRepartosNuevo(centroLogistico,false);
///Un booleano almacenará el valor de verdad de los resultados de todas las funciones.
///De esta manera, si alguno falla, el conjugado será falso, lo retornará, y nos daremos cuenta.
    return res;
}


//  listas de datos (CentroLogistico)
bool abrirPersonas(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Personas.txt","r");

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fPersona fpersona;
        PersonaPtr personaAux=0;

        for(int i=0;i<n;i++)
        {
            fread(&fpersona,sizeof(fPersona),1,archivo);

            fsetPersona(&fpersona,personaAux,false);
            agregarPersona(centroLogistico,personaAux);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirPaquetes(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Paquetes.txt","r");

    if(archivo==NULL)
    {
        printf("\n\nARCHIVO = NULL");
        return false;
    }
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fPaquete fpaquete;
        PaquetePtr paqueteAux=0;

        for(int i=0;i<n;i++)
        {
            fread(&fpaquete,sizeof(fPaquete),1,archivo);

            fsetPaquete(&fpaquete,paqueteAux,false);
            agregarPaquete(centroLogistico,paqueteAux);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirVehiculos(CentroLogisticoPtr centroLogistico)
{
    FILE *archivo = fopen("Lista de Vehiculos.txt","r");

    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fVehiculo fvehiculo;
        VehiculoPtr vehiculoAux=0;

        for(int i=0;i<n;i++)
        {
            fread(&fvehiculo,sizeof(fVehiculo),1,archivo);

            fsetVehiculo(&fvehiculo,vehiculoAux,false);
            agregarVehiculo(centroLogistico,vehiculoAux);
        }
        fclose(archivo);
        return true;
    }
}
bool abrirRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    FILE *archivo;
	if(esRepartoAbierto)
		archivo = fopen("Lista de Repartos Abiertos.txt","r");
	else
		archivo = fopen("Lista de Repartos Cerrados.txt","r");


    if(archivo==NULL)
        return false;
    else
    {
    ///Como hicimos en funciones anteriores, recuperamos primero la cantidad de elementos de la lista
        int n = 0;
        fread(&n,sizeof(int),1,archivo);

        fReparto freparto;
        RepartoPtr repartoAux=0;

        for(int i=0;i<n;i++)
        {
            fread(&freparto,sizeof(fReparto),1,archivo);

            fsetReparto(&freparto,repartoAux,false);
            if(esRepartoAbierto)
                agregarReparto(centroLogistico,repartoAux,true);
            else
                agregarReparto(centroLogistico,repartoAux,false);
        }
        fclose(archivo);
        return true;
    }
}
//  general

CentroLogisticoPtr abrirTodo() //implementacion: creará un centro logistico y lo llenará de datos. Llamará a las otras funciones de apertura
{
    //Primero, recuperamos el nombre del centro logistico.
    FILE *archivo = fopen("Nombre del Centro Logistico.txt","r");
    bool res=true;

    char nombreCtroLog[100];

    if(archivo==NULL)
        res=false;
    else
    {
        if(LeerString(archivo,nombreCtroLog,100,'\n')==EOF)
            res=false; ///volvemos a poner false si el archivo abre, pero está vacío por alguna razón.
    }

    CentroLogisticoPtr centroLogistico = crearCentroLogisticoRapido(nombreCtroLog);

    res = res && abrirPaquetes(centroLogistico);
    res = res && abrirPersonas(centroLogistico);
    res = res && abrirVehiculos(centroLogistico);
    res = res && abrirRepartos(centroLogistico,true);
    res = res && abrirRepartos(centroLogistico,false);
///Un booleano almacenará el valor de verdad de los resultados de todas las funciones.
///De esta manera, si alguna funcion falla, la booleana será falso, y nos daremos cuenta.
    if(res)
        return centroLogistico;
    else
        return NULL; //retornamos null si hubo algún error.
}


///                                     ESPECIALES - AYUDANTES


// Función para leer líneas de texto terminadas con un
// caracter determinado
int LeerString(FILE *archivo,char buffer[], int longitudMax,char terminador){
    // leemos caracter a caracter hasta encontrar terminador o EOF
    char caracter;
    int k=0;
    do{
        caracter=fgetc(archivo);
        if(k<longitudMax)
            buffer[k]=caracter;
        k++;
    } while(caracter!=EOF && caracter!=terminador);
    buffer[k]=0; // agregamos el terminador
    if(caracter==EOF)
        return EOF;
    else
        return k;
}

*/

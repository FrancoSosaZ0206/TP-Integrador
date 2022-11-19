#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "TDAFechaYHora.h"
#include "TDACuil.h"
#include "TDADomicilio.h"
#include "TDAVehiculo.h"
#include "TDAPersona.h"
#include "TDAPaquetes.h"
#include "TDARepartos.h"
#include "TDACentroLogistico.h"
#include "util.h"
#include "test.h"

///-------------------------------------------------------------------------------------------------////


void crearListaRepartosDefecto(CentroLogisticoPtr c)
{
    /*  FECHAS EN FORMATO ANTIGUO (POR AHORA USAREMOS EL TIEMPO ACTUAL PARA AGILIZAR LAS PRUEBAS CON EL SISTEMA DE ACTUALIZACION DE REPARTOS)
    FechaPtr fechaEntrega1=crearFecha(17,11,2022,17,35);
    FechaPtr fechaEntrega2=crearFecha(17,11,2022,17,30);
    FechaPtr fechaEntrega3=crearFecha(17,11,2022,17,40);
    FechaPtr fechaEntrega4=crearFecha(17,11,2022,17,30);

    FechaPtr fechaSalida1=crearFecha(17,11,2022,17,20); //Para el reparto
    FechaPtr fechaSalida2=crearFecha(17,11,2022,17,20);
    FechaPtr fechaSalida3=crearFecha(17,11,2022,17,20);
    FechaPtr fechaSalida4=crearFecha(17,11,2022,17,20);

    FechaPtr fechaRetorno1=crearFecha(17,11,2022,21,3); //Para el reparto
    FechaPtr fechaRetorno2=crearFecha(17,11,2022,21,5);
    FechaPtr fechaRetorno3=crearFecha(17,11,2022,21,9);
    FechaPtr fechaRetorno4=crearFecha(17,11,2022,21,12);
    */

    FechaPtr fechasEntrega = getTiempoActual();
    FechaPtr fechasSalida = getTiempoActual();
    FechaPtr fechasRetorno = getTiempoActual();

    fechasEntrega = sumarAFecha(fechasEntrega,0,0,15);
    fechasSalida = sumarAFecha(fechasSalida,0,0,10);
    fechasRetorno = sumarAFecha(fechasRetorno,0,0,20);



    int n=4;
    DomicilioPtr domsChofer[n];
    domsChofer[0]=crearDomicilio("Vieytes",2000,"Lomas de zamora");
    domsChofer[1]=crearDomicilio("Boqueron",1500,"Villa Fiorito");
    domsChofer[2]=crearDomicilio("Espania",1500,"Puerto Madero");
    domsChofer[3]=crearDomicilio("Espania",1500,"Puerto Madero");



    CuilPtr cuilsChofer[n];
    cuilsChofer[0]=crearCuil("20 34654754 6");
    cuilsChofer[1]=crearCuil("27 24576456 7");
    cuilsChofer[2]=crearCuil("30 23456543 1");
    cuilsChofer[3]=crearCuil("30 23456543 1");



    DomicilioPtr dirsRetiro[n];
    dirsRetiro[0]=crearDomicilio("Deposito",5000,"Sector industrial");
    dirsRetiro[1]=crearDomicilio("Repositorio Intel",5000,"Sector industrial");
    dirsRetiro[2]=crearDomicilio("Tesla Industry",10000,"Washington DC");
    dirsRetiro[3]=crearDomicilio("Tesla Industry",10000,"Washington DC");



    DomicilioPtr dirsEntrega[n];
    dirsEntrega[0]=crearDomicilio("Santa fe",1500,"Banfield");
    dirsEntrega[1]=crearDomicilio("Italia",3000,"Palermo");
    dirsEntrega[2]=crearDomicilio("24 de mayo",3000,"Capital Federal");
    dirsEntrega[3]=crearDomicilio("24 de mayo",3000,"Capital Federal");



    PersonaPtr choferes[n];
    choferes[0]=crearPersona("Roberto","Garcia",domsChofer[0],cuilsChofer[0],true);
    choferes[1]=crearPersona("Maria","Gonzalez",domsChofer[1],cuilsChofer[1],true);
    choferes[2]=crearPersona("Gonzalo","Gutierrez",domsChofer[2],cuilsChofer[2],true);
    choferes[3]=crearPersona("Alberto","Alonzo",domsChofer[3],cuilsChofer[3],true);



    VehiculoPtr vehiculos[n];
    vehiculos[0]=crearVehiculo(3,"Mercedes Benz","Actros","17 UJI 30");
    vehiculos[1]=crearVehiculo(3,"Mercedes Benz","Actros","81 NMB 30");
    vehiculos[2]=crearVehiculo(3,"Mercedes Benz","Actros","19 JUY 78");
    vehiculos[3]=crearVehiculo(3,"Mercedes Benz","Actros","19 JUY 78");



    PaquetePtr paquetes[n];
    paquetes[0]=crearPaquete(1,4,5,2,65,dirsRetiro[0],dirsEntrega[0],fechasEntrega,6);
    paquetes[1]=crearPaquete(2,2,5,3,120,dirsRetiro[1],dirsEntrega[1],fechasEntrega,6);
    paquetes[2]=crearPaquete(3,8,8,10,800,dirsRetiro[2],dirsEntrega[2],fechasEntrega,6);
    paquetes[3]=crearPaquete(3,8,8,10,800,dirsRetiro[3],dirsEntrega[3],fechasEntrega,6);



    PilaPtr pilasPaquetes[n];
    RepartoPtr repartos[n];
    for(int i=0;i<n;i++)
    {
        pilasPaquetes[i] = crearPila();
        apilar(pilasPaquetes[i], (PaquetePtr)paquetes[i]);

        repartos[i]=armarReparto(choferes[i],vehiculos[i],fechasSalida,fechasRetorno,pilasPaquetes[i]);

        agregarPaquete(c,paquetes[i]);
        agregarPersona(c,choferes[i]);
        agregarVehiculo(c,vehiculos[i]);
        agregarReparto(c,repartos[i],true);
    }
}

void crearListaPaquetesGenerico(CentroLogisticoPtr c)
{
    int n=6;
    PaquetePtr paquetes[n];
    paquetes[0] = crearPaqueteDirect(1,4,2,5,150,"Sixto Fernandez",1800,"Lomas de Zamora","Calle Morazan",2100,"Villa fiorito",10,12,2022,16,45,0);
    paquetes[1] = crearPaqueteDirect(2,20,7,3,200,"Sixto Fernandez",1700,"Lomas de Zamora","Calle Morazan",2020,"Villa fiorito",10,12,2022,17,45,0);
    paquetes[2] = crearPaqueteDirect(3,15,5,9,75,"Sixto Fernandez",1220,"Lomas de Zamora","Calle Morazan",2310,"Villa fiorito",10,12,2022,18,45,0);
    paquetes[3] = crearPaqueteDirect(4,25,14,15,54,"Sixto Fernandez",5000,"Lomas de Zamora","Calle Morazan",250,"Villa fiorito",10,12,2022,19,45,0);
    paquetes[4] = crearPaqueteDirect(5,12,11,23,54,"Sixto Fernandez",1000,"Lomas de Zamora","Calle Morazan",650,"Villa fiorito",10,12,2022,20,45,0);
    paquetes[5] = crearPaqueteDirect(6,14,16,31,54,"Sixto Fernandez",2000,"Lomas de Zamora","Calle Morazan",550,"Villa fiorito",10,12,2022,21,45,0);

    for(int i=0;i<n;i++)
        agregarPaquete(c,paquetes[i]);
}

void crearListaPersonasGenerica(CentroLogisticoPtr c)
{
    int n=8;
    DomicilioPtr domicilios[n];
    CuilPtr cuils[n];
    PersonaPtr personas[n];

    domicilios[0] = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    domicilios[1] = crearDomicilio("Italia",1000,"Lomas de zamora");
    domicilios[2] = crearDomicilio("Espania",3000,"Lomas de zamora");
    domicilios[3] = crearDomicilio("9 de mayo",2000,"Lomas de zamora");
    domicilios[4] = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    domicilios[5] = crearDomicilio("Italia",1000,"Lomas de zamora");
    domicilios[6] = crearDomicilio("Espania",3000,"Lomas de zamora");
    domicilios[7] = crearDomicilio("9 de mayo",2000,"Lomas de zamora");

    cuils[0] = crearCuil("20654342341");
    cuils[1] = crearCuil("20655612332");
    cuils[2] = crearCuil("20245432343");
    cuils[3] = crearCuil("20126543214");
    cuils[4] = crearCuil("20654342345");
    cuils[5] = crearCuil("20655612336");
    cuils[6] = crearCuil("20245432347");
    cuils[7] = crearCuil("20126543218");

///Clientes:
    personas[0] = crearPersona("Javier","Gonzalez",domicilios[0],cuils[0],false);
    personas[1] = crearPersona("Gonzalo","Gutierrez",domicilios[1],cuils[1],false);
    personas[2] = crearPersona("Gabriel","Alonzo",domicilios[2],cuils[2],false);
    personas[3] = crearPersona("Alfonso","Romero",domicilios[3],cuils[3],false);
///Choferes:
    personas[4] = crearPersona("Javier","Gonzalez",domicilios[4],cuils[4],true);
    personas[5] = crearPersona("Gonzalo","Gutierrez",domicilios[5],cuils[5],true);
    personas[6] = crearPersona("Gabriel","Alonzo",domicilios[6],cuils[6],true);
    personas[7] = crearPersona("Alfonso","Romero",domicilios[7],cuils[7],true);

    for(int i=0;i<n;i++)
        agregarPersona(c,personas[i]);
}

void crearPersonasGenericasEspecificas(CentroLogisticoPtr c,bool esChofer)
{
    int n=4;
    DomicilioPtr domicilios[n];
    CuilPtr cuils[n];
    PersonaPtr personas[n];

    domicilios[0] = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    domicilios[1] = crearDomicilio("Italia",1000,"Lomas de zamora");
    domicilios[2] = crearDomicilio("Espania",3000,"Lomas de zamora");
    domicilios[3] = crearDomicilio("9 de mayo",2000,"Lomas de zamora");

    cuils[0] = crearCuil("20654342349");
    cuils[1] = crearCuil("20655612339");
    cuils[2] = crearCuil("20245432349");
    cuils[3] = crearCuil("20126543212");

    personas[0] = crearPersona("Javier","Gonzalez",domicilios[0],cuils[0],esChofer);
    personas[1] = crearPersona("Gonzalo","Gutierrez",domicilios[1],cuils[1],esChofer);
    personas[2] = crearPersona("Gabriel","Alonzo",domicilios[2],cuils[2],esChofer);
    personas[3] = crearPersona("Alfonso","Romero",domicilios[3],cuils[3],esChofer);

    for(int i=0;i<n;i++)
        agregarPersona(c,personas[i]);
}

void crearListaVehiculosGenerico(CentroLogisticoPtr c)
{
    int n=4;
    VehiculoPtr vehiculos[n];

    vehiculos[0]=crearVehiculo(3,"Mercedes Benz","Actros","99 UJI 99");
    vehiculos[1]=crearVehiculo(3,"Ferrari","Benne","65MNJ91");
    vehiculos[2]=crearVehiculo(3,"Volkswagen","17720","98 UYT 98");
    vehiculos[3]=crearVehiculo(3,"Ford","C916","97 JUI 97");

    for(int i=0;i<n;i++)
        agregarVehiculo(c,vehiculos[i]);
}

CentroLogisticoPtr crearCentroLogisticoDefecto()
{
    CentroLogisticoPtr cDef = crearCentroLogisticoRapido("Distribuidora");

    crearListaPaquetesGenerico(cDef);
    crearListaPersonasGenerica(cDef);
    crearListaVehiculosGenerico(cDef);
    crearListaRepartosDefecto(cDef);

    return cDef;
}







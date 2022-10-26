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

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE CREACION///
///-----------------------------------------------------------------------------------------------------------///

ListaPtr crearListaRepartosPorDefectoConLista()
{
    ListaPtr listaRepartos=crearLista();
    DomicilioPtr domicilioChofer1=crearDomicilio("Vieytes",2000,"Lomas de zamora");
    DomicilioPtr dirRetiro1=crearDomicilio("Deposito",5000,"Sector industrial"); /// (*)
    DomicilioPtr dirEntrega1=crearDomicilio("Santa fe",1500,"Banfield"); /// (**)
    FechaPtr fechaSalida1=crearFecha(10,12,2022,8,30); //Para el reparto
    FechaPtr fechaRetorno1=crearFecha(10,12,2022,8,30); //Para el reparto
    FechaPtr fechaEntrega1=crearFecha(10,12,2022,8,30);
    CuilPtr cuil1=crearCuil("20346547546");
    PersonaPtr chofer1=crearPersona("Roberto","Garcia",domicilioChofer1,cuil1,true);
    PersonaPtr cliente1=crearPersona("Roberto","Garcia",domicilioChofer1,cuil1,false);
    PaquetePtr paquete1=crearPaquete(1,4,5,2,65,dirRetiro1,dirEntrega1,fechaEntrega1,cliente1,0);
    VehiculoPtr vehiculo1=crearVehiculo(3,"Mercedes Benz","Actros","17 UJI 30");
    ListaPtr listaPaquetes=crearLista();
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete1);
    RepartoPtr reparto1=0;
    reparto1=crearReparto(chofer1,vehiculo1,fechaSalida1,fechaRetorno1,listaPaquetes);

    DomicilioPtr domicilioChofer2=crearDomicilio("Boqueron",1500,"Villa Fiorito");
    DomicilioPtr dirRetiro2=crearDomicilio("Repositorio Intel",5000,"Sector industrial");
    DomicilioPtr dirEntrega2=crearDomicilio("Italia",3000,"Palermo");
    FechaPtr fechaSalida2=crearFecha(10,12,2022,9,30);
    FechaPtr fechaRetorno2=crearFecha(10,12,2022,9,30);
    FechaPtr fechaEntrega2=crearFecha(10,12,2022,8,30);
    CuilPtr cuil2=crearCuil("27245764567");
    PersonaPtr chofer2=crearPersona("Maria","Gonzalez",domicilioChofer2,cuil2,true);
    PaquetePtr paquete2=crearPaquete(2,2,5,3,120,dirRetiro2,dirEntrega2,fechaEntrega2,cliente1,0);
    ListaPtr listaPaquetes2=crearLista();
    agregarDatoLista(listaPaquetes2,(PaquetePtr)paquete2);
    VehiculoPtr vehiculo2=crearVehiculo(3,"Mercedes Benz","Actros","81 NMB 30");
    RepartoPtr reparto2=0;
    reparto2=crearReparto(chofer2,vehiculo2,fechaSalida2,fechaRetorno2,listaPaquetes2);

    DomicilioPtr domicilioChofer3=crearDomicilio("Espania",1500,"Puerto Madero");
    DomicilioPtr dirRetiro3=crearDomicilio("Tesla Industry",10000,"Washington DC");
    DomicilioPtr dirEntrega3=crearDomicilio("24 de mayo",3000,"Capital Federal");
    FechaPtr fechaSalida3=crearFecha(10,12,2022,10,30);
    FechaPtr fechaRetorno3=crearFecha(10,12,2022,10,30);
    FechaPtr fechaEntrega3=crearFecha(10,12,2022,8,30);
    CuilPtr cuil3=crearCuil("30234565431");
    PersonaPtr chofer3=crearPersona("Gonzalo","Gutierrez",domicilioChofer3,cuil3,true);
    PaquetePtr paquete3=crearPaquete(3,8,8,10,800,dirRetiro3,dirEntrega3,fechaEntrega3,cliente1,0);
    ListaPtr listaPaquetes3=crearLista();
    agregarDatoLista(listaPaquetes3,(PaquetePtr)paquete3);
    VehiculoPtr vehiculo3=crearVehiculo(3,"Mercedes Benz","Actros","19 JUY 78");
    RepartoPtr reparto3=0;
    reparto3=crearReparto(chofer3,vehiculo3,fechaSalida3,fechaRetorno3,listaPaquetes3);

    DomicilioPtr domicilioChofer4=crearDomicilio("Espania",1500,"Puerto Madero");
    DomicilioPtr dirRetiro4=crearDomicilio("Tesla Industry",10000,"Washington DC");
    DomicilioPtr dirEntrega4=crearDomicilio("24 de mayo",3000,"Capital Federal");
    FechaPtr fechaSalida4=crearFecha(10,12,2022,10,30);
    FechaPtr fechaRetorno4=crearFecha(10,12,2022,10,30);
    FechaPtr fechaEntrega4=crearFecha(10,12,2022,8,30);
    CuilPtr cuil4=crearCuil("30234565431");
    PersonaPtr chofer4=crearPersona("Alberto","Alonzo",domicilioChofer4,cuil4,true);
    PaquetePtr paquete4=crearPaquete(3,8,8,10,800,dirRetiro4,dirEntrega4,fechaEntrega4,cliente1,0);
    ListaPtr listaPaquetes4=crearListaPaquetesGenerico();
    agregarDatoLista(listaPaquetes4,(PaquetePtr)paquete4);
    VehiculoPtr vehiculo4=crearVehiculo(3,"Mercedes Benz","Actros","19 JUY 78");
    RepartoPtr reparto4=0;
    reparto4=crearReparto(chofer4,vehiculo4,fechaSalida4,fechaRetorno4,listaPaquetes4);

    agregarDatoLista(listaRepartos,(RepartoPtr)reparto1);
    agregarDatoLista(listaRepartos,(RepartoPtr)reparto2);
    agregarDatoLista(listaRepartos,(RepartoPtr)reparto3);
    agregarDatoLista(listaRepartos,(RepartoPtr)reparto4);
    return listaRepartos;
}

ListaPtr crearListaPaquetesGenerico()
{
    ListaPtr listaPaquetes = crearLista();
    PaquetePtr paquete1 = crearPaqueteDirect(rand(),4,2,5,150,"Sixto Fernandez",1800,"Lomas de Zamora","Calle Morazan",2100,"Villa fiorito",10,12,2022,16,45,"Javier","Gonzalez","Sixto",1200,"Lomas","20458730955",0);
    PaquetePtr paquete2 = crearPaqueteDirect(rand(),20,7,3,200,"Sixto Fernandez",1700,"Lomas de Zamora","Calle Morazan",2020,"Villa fiorito",10,12,2022,17,45,"Javier","Gonzalez","Sixto",1200,"Lomas","20458730955",0);
    PaquetePtr paquete3 = crearPaqueteDirect(rand(),15,5,9,75,"Sixto Fernandez",1220,"Lomas de Zamora","Calle Morazan",2310,"Villa fiorito",10,12,2022,18,45,"Javier","Gonzalez","Sixto",1200,"Lomas","20458730955",0);
    PaquetePtr paquete4 = crearPaqueteDirect(rand(),25,14,15,54,"Sixto Fernandez",5000,"Lomas de Zamora","Calle Morazan",250,"Villa fiorito",10,12,2022,19,45,"Javier","Gonzalez","Sixto",1200,"Lomas","20458730955",0);
    PaquetePtr paquete5 = crearPaqueteDirect(rand(),12,11,23,54,"Sixto Fernandez",1000,"Lomas de Zamora","Calle Morazan",650,"Villa fiorito",10,12,2022,20,45,"Javier","Gonzalez","Sixto",1200,"Lomas","20458730955",0);
    PaquetePtr paquete6 = crearPaqueteDirect(rand(),14,16,31,54,"Sixto Fernandez",2000,"Lomas de Zamora","Calle Morazan",550,"Villa fiorito",10,12,2022,21,45,"Javier","Gonzalez","Sixto",1200,"Lomas","20458730955",0);
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
    CuilPtr cuil_1 = crearCuil("20654342341");
    PersonaPtr cliente1 = crearPersona("Javier","Gonzalez",domicilio1,cuil_1,false);

    DomicilioPtr domicilio2 = crearDomicilio("Italia",1000,"Lomas de zamora");
    CuilPtr cuil_2 = crearCuil("20655612332");
    PersonaPtr cliente2 = crearPersona("Gonzalo","Gutierrez",domicilio2,cuil_2,false);

    DomicilioPtr domicilio3 = crearDomicilio("Espania",3000,"Lomas de zamora");
    CuilPtr cuil_3 = crearCuil("20245432343");
    PersonaPtr cliente3 = crearPersona("Gabriel","Alonzo",domicilio3,cuil_3,false);

    DomicilioPtr domicilio4 = crearDomicilio("9 de mayo",2000,"Lomas de zamora");
    CuilPtr cuil_4 = crearCuil("20126543214");
    PersonaPtr cliente4 = crearPersona("Alfonso","Romero",domicilio4,cuil_4,false);

    DomicilioPtr domicilio5 = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    CuilPtr cuil_5 = crearCuil("20654342345");
    PersonaPtr chofer1 = crearPersona("Javier","Gonzalez",domicilio5,cuil_5,true);

    DomicilioPtr domicilio6 = crearDomicilio("Italia",1000,"Lomas de zamora");
    CuilPtr cuil_6 = crearCuil("20655612336");
    PersonaPtr chofer2 = crearPersona("Gonzalo","Gutierrez",domicilio6,cuil_6,true);

    DomicilioPtr domicilio7 = crearDomicilio("Espania",3000,"Lomas de zamora");
    CuilPtr cuil_7 = crearCuil("20245432347");
    PersonaPtr chofer3 = crearPersona("Gabriel","Alonzo",domicilio7,cuil_7,true);

    DomicilioPtr domicilio8 = crearDomicilio("9 de mayo",2000,"Lomas de zamora");
    CuilPtr cuil_8 = crearCuil("20126543218");
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

ListaPtr crearListaVehiculosGenerico()
{
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

CentroLogisticoPtr crearCentroLogisticoDefecto()
{
    ListaPtr repartosAbiertos=crearListaRepartosPorDefectoConLista();
    ListaPtr repartosCerrados=crearLista();
    ListaPtr paquetes=crearListaPaquetesGenerico();
    ListaPtr personas=crearListaPersonasGenerica();
    ListaPtr vehiculos=crearListaVehiculosGenerico();
    CentroLogisticoPtr centroLogistico;
    centroLogistico=crearCentroLogistico("Distribuidora",paquetes,personas,vehiculos,repartosAbiertos,repartosCerrados);
    return centroLogistico;
}


///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE TESTEO///
///-----------------------------------------------------------------------------------------------------------///

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

void probarGuardado()
{
    bool resultado;
    CentroLogisticoPtr centroLogistico;
    ListaPtr vehiculos = crearListaVehiculosGenerico();
    ListaPtr paquetes1 = crearListaPaquetesGenerico();
    ListaPtr personas = crearListaPersonasGenerica();
    ListaPtr repartosA = crearListaRepartosPorDefectoConLista();
    ListaPtr repartosC = crearLista();
    centroLogistico = crearCentroLogistico("Distribuidora",paquetes1,personas,vehiculos,repartosA,repartosC);
    resultado=guardarPaquetes(centroLogistico);
    resultado=resultado && guardarPersonas(centroLogistico);
    resultado=resultado && guardarRepartos(centroLogistico,true);
    resultado=resultado && guardarRepartos(centroLogistico,false);
    resultado=resultado && guardarVehiculos(centroLogistico);
    verificacion(resultado);
    system("pause");
}

void probarApertura()
{
    CentroLogisticoPtr CL;
    CL=crearCentroLogisticoRapido("");
    bool resultado;
    resultado=abrirPaquetes(CL);
    resultado=resultado && abrirVehiculos(CL);
    resultado=resultado && abrirPersonas(CL);
    resultado=resultado && abrirRepartos(CL,true);
    resultado=resultado && abrirRepartos(CL,false);
    verificacion(resultado);
    probandoGenericas(CL);
    system("pause");
}

void probandoAmbos()
{
    probarGuardado();
    probarApertura();
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "TDACentroLogistico.h"
#include "test.h"
#include "util.h"

VehiculoPtr crearVehiculoPorDefecto() ///Crea un vehículo de forma rápida con datos predeterminados.
{
    VehiculoPtr vehiculo=crearVehiculo(3,"Mercedes-Benz","Actros","ZZ 999 ZZ");
    return vehiculo;
}
VehiculoPtr crearVehiculoGenerico() ///Crea un vehículo de forma rápida con datos aleatorios. BROKEN
{
/*
NOTA: En esta version, simplifiqué el funcionamiento para que sea más facil de entender.

Qué quiero que pase?
    1. Se elige un tipo y una marca de vehiculo al azar.
    2. Según la marca y el tipo, se elige un modelo.
    3. Para la patente, se eligen letras y numeros al azar y se ponen en un string con sprintf().

Tips:
    -Solo saldrán marcas y modelos de vehiculos que tengan el tipo que tocó.
    -Solo saldrán modelos de vehiculos que sean de una determinada marca.

Fórmula para calcular un numero aleatorio entre dos límites determinados:
    int res=(rand()% (superior-inferior+1)) + inferior);
*/

    VehiculoPtr vehiculo=(VehiculoPtr)obtenerMemoria(sizeof(Vehiculo));

    char **marca=(char**)obtenerMemoria((sizeof(char)*14)*10); //14 para el string + largo, 10 por la cantidad de strings.
    marca[0]="Toyota"; //tiene todos los tipos.
    marca[1]="Mercedes-Benz"; //no tiene moto.
    marca[2]="Kia"; //no tiene moto.
    marca[3]="Ford"; //no tiene moto.
    marca[4]="Chevrolet"; //no tiene moto.
    marca[5]="Fiat"; //solo autos.
    marca[6]="Yamaha"; //solo motos.
    marca[7]="Ducati"; //solo motos.
    marca[8]="Volkswagen"; //no tiene moto.
    marca[9]="Citroen"; //solo autos.

    char **modelo=(char**)obtenerMemoria((sizeof(char)*29)*30); //29 para el string + largo, 30 por la cantidad de modelos.
//Toyota
    modelo[0]="Profia FR1AWHG"; //camion
    modelo[1]="Corolla"; //auto
    modelo[2]="TZF 450"; //moto
//Mercedes-Benz
    modelo[3]="Actros"; //camion
    modelo[4]="S600"; //auto
    modelo[5]="EQC"; //auto
//Kia
    modelo[6]="K3000"; //camion
    modelo[7]="Rio"; //auto
    modelo[8]="Sportage 2018 Facelift"; //auto
//Ford
    modelo[9]="FMax"; //camion
    modelo[10]="Fiesta"; //auto
    modelo[11]="EcoSport"; //auto
//Chevrolet
    modelo[12]="Corsa"; //auto
    modelo[13]="FVZ 34T"; //camion
    modelo[14]="Colorado"; //camion
//Fiat
    modelo[15]="Cronos"; //auto
    modelo[16]="Toro"; //auto
    modelo[17]="500"; //auto
//Yamaha
    modelo[18]="R125"; //moto
    modelo[19]="FZ6R"; //moto
    modelo[20]="Niken"; //moto
//Ducati
    modelo[21]="Monster 1200R"; //moto
    modelo[22]="1198S"; //moto
    modelo[23]="Streetfighter V4 2020"; //moto
//Volkswagen
    modelo[24]="Golf"; //auto
    modelo[25]="Amarok"; //auto
    modelo[26]="Constellation 26420 V-Tronic"; //camion
//Citroen
    modelo[27]="C4 Cactus"; //auto
    modelo[28]="C3 Aircross"; //auto
    modelo[29]="Berlingo"; //auto

    //char *patente; //para esta, tenemos que generar letras y numeros aleatorios
    int limInf=1;
    int limSup=3; //empezamos del 1 al 3 para el tipo
    int resTipo=0;
    int resMarca=0;
    int resModelo=0;

    srand(time(NULL));
    resTipo=(rand()%(limSup-limInf+1))+limInf; //definimos el tipo
    vehiculo->tipo=resTipo; ///lo asignamos a la estructura.

    limSup=10;
    resMarca=rand()%(limSup+1); //definimos la marca
    vehiculo->marca=crearStringDinamico(marca[resMarca]);

    limSup=30;
    resModelo=rand()%(limSup+1); //definimos la marca
    vehiculo->modelo=crearStringDinamico(modelo[resModelo]);

///Ahora, generamos la patente aleatoria.

    limInf=65;
    limSup=90;
    int resLetra;
    char letra;
    char *patente=(char*)obtenerMemoria(sizeof(char)*10); //primero pasa acá, luego a la estructura.

    for(int i=0;i<2;i++) //asignamos las 2 primeras letras
    {
        resLetra=(rand()%(limSup-limInf+1))+limInf;
        letra=(char)resLetra;
        patente[i]=letra;
        printf("%s\n",patente); //imprimimos para ver como va progresando.
    }

    strcat(patente,"-"); //para añadir legibilidad, concatenamos un espacio al final de las 2 1ras letras.

    for(int i=0;i<3;i++) //asignamos los 3 numeros del medio
    {
        limInf=0;
        limSup=9;
        resLetra=(rand()%(limSup-limInf+1))+limInf;
        patente[i+3]=resLetra;
    } //i+3 porque queremos que se inserten luego de lo que ya pusimos: las letras y el espacio.

    strcat(patente,"-"); //concatenamos otro espacio al final de los 3 numeros.

    for(int i=0;i<2;i++) //asignamos las 2 ultimas letras
    {
        resLetra=(rand()%(limSup-limInf+1))+limInf;
        letra=(char)resLetra;
        patente[i+7]=letra;
        printf("%s\n",patente); //imprimimos para ver como va progresando.
    } //i+7 porque queremos que se inserten luego de lo que ya pusimos: las letras, los numeros y los 2 espacios entre medio de ellos.

    patente[10]='\0'; //terminamos el string.
    vehiculo->patente=crearStringDinamico(patente); ///asignamos a la estructura.

//destruimos los elementos que ya no utilizaremos.
    for(int i=0;i<10;i++)
    {
        marca[i]=NULL;
    }
    free(marca);
    for(int i=0;i<10;i++)
    {
        modelo[i]=NULL;
    }
    free(modelo);

    destruirStringDinamico(patente);
//Retornamos un puntero a la estructura generada.
    return vehiculo;
}

ListaPtr crearListaRepartosPorDefecto()
{
///Creamos una lista de repartos
    ListaPtr listaRepartos=crearLista();


//Creamos un grupo de domicilios
    DomicilioPtr domicilioChofer=crearDomicilio("Vieytes",2000,"Lomas de zamora");
    DomicilioPtr dirRetiro=crearDomicilio("Deposito",5000,"Sector industrial"); /// (*)
    DomicilioPtr dirEntrega=crearDomicilio("Santa fe",1500,"Banfield"); /// (**)
//Creamos una serie de fechas
    FechaPtr fechaSalida=crearFechaDirect(2459610,16,45); //Para el reparto
    FechaPtr fechaRetorno=crearFechaDirect(2459610,17,45); //Para el reparto
    FechaPtr fechaEntrega=crearFechaDirect(2459610,18,45);
//Creamos un Cuil
    CuilPtr cuil=crearCuil("20 34654754 6");

//Creamos un chofer
    PersonaPtr chofer=crearPersona("Roberto","Garcia",domicilioChofer,cuil,true);
//Creamos un paquete con (*) y (**)
    PaquetePtr paquete=crearPaquete(1,4,5,2,65,dirRetiro,dirEntrega,fechaEntrega,0);
//Creamos una pila de paquetes para el reparto
    PilaPtr pilaPaquetes=crearPila();
    apilar(pilaPaquetes,(PaquetePtr)paquete); /// Pila de 1 paquete
//Creamos un vehículo genérico aprovechando que tenemos hecha la funcion
    VehiculoPtr vehiculo=crearVehiculoGenerico();
///Creamos un reparto con los datos creados previamente
    RepartoPtr reparto=crearReparto(chofer,vehiculo,fechaSalida,fechaRetorno,pilaPaquetes);


///REPETIMOS EL PROCESO 2 VECES MÁS
    DomicilioPtr domicilioChofer1=crearDomicilio("Boqueron",1500,"Villa Fiorito");
    DomicilioPtr dirRetiro1=crearDomicilio("Repositorio Intel",5000,"Sector industrial");
    DomicilioPtr dirEntrega1=crearDomicilio("Italia",3000,"Palermo");

    FechaPtr fechaSalida1=crearFechaDirect(2459300,8,30);
    FechaPtr fechaRetorno1=crearFechaDirect(2459610,9,30);
    FechaPtr fechaEntrega1=crearFechaDirect(2459610,10,30);

    CuilPtr cuil1=crearCuil("27 24576456 7");

    PersonaPtr chofer1=crearPersona("Maria","Gonzalez",domicilioChofer1,cuil1,true);

    PaquetePtr paquete1=crearPaquete(2,2,5,3,120,dirRetiro1,dirEntrega1,fechaEntrega1,0);
    PilaPtr pilaPaquetes1=crearPila();
    apilar(pilaPaquetes1,(PaquetePtr)paquete1);

    VehiculoPtr vehiculo1=crearVehiculoGenerico();

    RepartoPtr reparto1=crearReparto(chofer1,vehiculo1,fechaSalida1,fechaRetorno1,pilaPaquetes1);



    DomicilioPtr domicilioChofer2=crearDomicilio("Espania",1500,"Puerto Madero");
    DomicilioPtr dirRetiro2=crearDomicilio("Tesla Industry",10000,"Washington DC");
    DomicilioPtr dirEntrega2=crearDomicilio("24 de mayo",3000,"Capital Federal");

    FechaPtr fechaSalida2=crearFechaDirect(2378300,19,15);
    FechaPtr fechaRetorno2=crearFechaDirect(2378300,21,15);
    FechaPtr fechaEntrega2=crearFechaDirect(2378300,22,15);

    CuilPtr cuil2=crearCuil("30 23456543 1");

    PersonaPtr chofer2=crearPersona("Sociedades","Anonimas",domicilioChofer2,cuil2,true);

    PaquetePtr paquete2=crearPaquete(3,8,8,10,800,dirRetiro2,dirEntrega2,fechaEntrega2,0);
    PilaPtr pilaPaquetes2=crearPila();
    apilar(pilaPaquetes2,(PaquetePtr)paquete);

    VehiculoPtr vehiculo2=crearVehiculoGenerico();

    RepartoPtr reparto2=crearReparto(chofer2,vehiculo2,fechaSalida2,fechaRetorno2,pilaPaquetes2);


///Agregamos los 3 repartos a la lista
    agregarDatoLista(listaRepartos,(RepartoPtr)reparto);
    agregarDatoLista(listaRepartos,(RepartoPtr)reparto1);
    agregarDatoLista(listaRepartos,(RepartoPtr)reparto2);
///Retornamos la lista de repartos
    return listaRepartos;
}

ListaPtr crearListaPaquetesGenerico()
{
    ListaPtr listaPaquetes = crearLista();
    PaquetePtr paquete1 = crearPaqueteDirect(rand(),4,2,5,150,"Sixto Fernandez",1800,"Lomas de Zamora","Calle Morazan",2100,"Villa fiorito",10,12,2022,16,45,0);
    PaquetePtr paquete2 = crearPaqueteDirect(rand(),20,7,3,200,"Sixto Fernandez",1700,"Lomas de Zamora","Calle Morazan",2020,"Villa fiorito",10,12,2022,17,45,0);
    PaquetePtr paquete3 = crearPaqueteDirect(rand(),15,5,9,75,"Sixto Fernandez",1220,"Lomas de Zamora","Calle Morazan",2310,"Villa fiorito",10,12,2022,18,45,0);
    PaquetePtr paquete4 = crearPaqueteDirect(rand(),25,14,15,54,"Sixto Fernandez",5000,"Lomas de Zamora","Calle Morazan",250,"Villa fiorito",10,12,2022,19,45,0);
    PaquetePtr paquete5 = crearPaqueteDirect(rand(),12,11,23,54,"Sixto Fernandez",1000,"Lomas de Zamora","Calle Morazan",650,"Villa fiorito",10,12,2022,20,45,0);
    PaquetePtr paquete6 = crearPaqueteDirect(rand(),14,16,31,54,"Sixto Fernandez",2000,"Lomas de Zamora","Calle Morazan",550,"Villa fiorito",10,12,2022,21,45,0);
    insertarDatoLista(listaPaquetes,(PaquetePtr)paquete1, longitudLista(listaPaquetes));
    insertarDatoLista(listaPaquetes,(PaquetePtr)paquete2, longitudLista(listaPaquetes));
    insertarDatoLista(listaPaquetes,(PaquetePtr)paquete3, longitudLista(listaPaquetes));
    insertarDatoLista(listaPaquetes,(PaquetePtr)paquete4, longitudLista(listaPaquetes));
    insertarDatoLista(listaPaquetes,(PaquetePtr)paquete5, longitudLista(listaPaquetes));
    insertarDatoLista(listaPaquetes,(PaquetePtr)paquete6, longitudLista(listaPaquetes));
    /*
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete1);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete2);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete3);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete4);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete5);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete6);
    */
    return listaPaquetes;
}

ListaPtr crearListaClientesGenerico()
{
    ListaPtr listaClientes = crearLista();
    //Cliente 1
    DomicilioPtr domicilio1 = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    CuilPtr cuil_1 = crearCuil("20654342349");
    PersonaPtr cliente1 = crearPersona("Javier","Gonzalez",domicilio1,cuil_1,false);
    //Cliente 2
    DomicilioPtr domicilio2 = crearDomicilio("Italia",1000,"Lomas de zamora");
    CuilPtr cuil_2 = crearCuil("20655612339");
    PersonaPtr cliente2 = crearPersona("Gonzalo","Gutierrez",domicilio2,cuil_2,false);
    //Cliente 3
    DomicilioPtr domicilio3 = crearDomicilio("Espania",3000,"Lomas de zamora");
    CuilPtr cuil_3 = crearCuil("20245432349");
    PersonaPtr cliente3 = crearPersona("Gabriel","Alonzo",domicilio3,cuil_3,false);
    //Cliente 4
    DomicilioPtr domicilio4 = crearDomicilio("9 de mayo",2000,"Lomas de zamora");
    CuilPtr cuil_4 = crearCuil("20126543212");
    PersonaPtr cliente4 = crearPersona("Alfonso","Romero",domicilio4,cuil_4,false);
    /*agregarDatoLista(listaPaquetes,(PersonaPtr)cliente1);
    agregarDatoLista(listaPaquetes,(PersonaPtr)cliente2);
    agregarDatoLista(listaPaquetes,(PersonaPtr)cliente3);
    agregarDatoLista(listaPaquetes,(PersonaPtr)cliente4);*/
    int i=0;
    insertarDatoLista(listaClientes,(PersonaPtr)cliente1,i++);
    insertarDatoLista(listaClientes,(PersonaPtr)cliente2,i++);
    insertarDatoLista(listaClientes,(PersonaPtr)cliente3,i++);
    insertarDatoLista(listaClientes,(PersonaPtr)cliente4,i++);
    return listaClientes;
}


ListaPtr crearListaChoferesGenerico()
{
    ListaPtr listaChoferes = crearLista();
    //chofer 1
    DomicilioPtr domicilio1 = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    CuilPtr cuil_1 = crearCuil("20654342349");
    PersonaPtr chofer1 = crearPersona("Javier","Gonzalez",domicilio1,cuil_1,true);
    //chofer 2
    DomicilioPtr domicilio2 = crearDomicilio("Italia",1000,"Lomas de zamora");
    CuilPtr cuil_2 = crearCuil("20655612339");
    PersonaPtr chofer2 = crearPersona("Gonzalo","Gutierrez",domicilio2,cuil_2,true);
    //chofer 3
    DomicilioPtr domicilio3 = crearDomicilio("Espania",3000,"Lomas de zamora");
    CuilPtr cuil_3 = crearCuil("20245432349");
    PersonaPtr chofer3 = crearPersona("Gabriel","Alonzo",domicilio3,cuil_3,true);
    //chofer 4
    DomicilioPtr domicilio4 = crearDomicilio("9 de mayo",2000,"Lomas de zamora");
    CuilPtr cuil_4 = crearCuil("20126543212");
    PersonaPtr chofer4 = crearPersona("Alfonso","Romero",domicilio4,cuil_4,true);
    /*agregarDatoLista(listaChoferes,(PersonaPtr)chofer1);
    agregarDatoLista(listaChoferes,(PersonaPtr)chofer1);
    agregarDatoLista(listaChoferes,(PersonaPtr)chofer1);
    agregarDatoLista(listaChoferes,(PersonaPtr)chofer1);*/
    int i=0;
    insertarDatoLista(listaChoferes,(PersonaPtr)chofer1,i++);
    insertarDatoLista(listaChoferes,(PersonaPtr)chofer2,i++);
    insertarDatoLista(listaChoferes,(PersonaPtr)chofer3,i++);
    insertarDatoLista(listaChoferes,(PersonaPtr)chofer4,i++);
    return listaChoferes;
}

ListaPtr crearListaVehiculosGenerico()
{
    ListaPtr listaVehiculos = crearLista();
    //vehiculo 1
    VehiculoPtr vehiculo1 = crearVehiculo(3,"Mercedes Benz","Actros","19 UJI 30");
    //vehiculo 2
    VehiculoPtr vehiculo2 = crearVehiculo(3,"Ferrari","Benne","65 MNJ 91");
    //vehiculo 3
    VehiculoPtr vehiculo3 = crearVehiculo(3,"Volkswagen","17720","54 UYT 95");
    //vehiculo 4
    VehiculoPtr vehiculo4 = crearVehiculo(3,"Ford","C916","20 JUI 12");
    /*agregarDatoLista(listaVehiculos,(VehiculoPtr)vehiculo1);
    agregarDatoLista(listaVehiculos,(VehiculoPtr)vehiculo2);
    agregarDatoLista(listaVehiculos,(VehiculoPtr)vehiculo3);
    agregarDatoLista(listaVehiculos,(VehiculoPtr)vehiculo4);*/
    int i=0;
    insertarDatoLista(listaVehiculos,(VehiculoPtr)vehiculo1,i++);
    insertarDatoLista(listaVehiculos,(VehiculoPtr)vehiculo2,i++);
    insertarDatoLista(listaVehiculos,(VehiculoPtr)vehiculo3,i++);
    insertarDatoLista(listaVehiculos,(VehiculoPtr)vehiculo4,i++);
    return listaVehiculos;
}


void MetodoDistintoDeMostrado()
{
    int i=0;
    ListaPtr listaPaquetes = crearLista();
    listaPaquetes = crearListaPaquetesGenerico();
    while(i<longitudLista(listaPaquetes)){
        printf("%d.",i);
        mostrarPaquete((PaquetePtr)getDatoLista(listaPaquetes,i++));
    }
    ListaPtr listaPaquetes1 = crearLista();
    listaPaquetes = crearListaPaquetesGenerico();
    CentroLogisticoPtr centroLogistico = crearCentroLogisticoRapido("Distribuidora");
    setPaquetes(centroLogistico, listaPaquetes);
    printf("Paquetes del centro logistico: %s\n", getNombreCentroLogistico(centroLogistico));
    for(int i=0;i<longitudLista(getPaquetes(centroLogistico));i++){
        printf("%d.",i);
        mostrarPaquete((PaquetePtr)getDatoLista(getPaquetes(centroLogistico),i));
    }
    system("pause");
}












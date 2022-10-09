#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "TDACentroLogistico.h"
#include "test.h"
#include "util.h"
#include "Files.h"

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

RepartoPtr crearRepartoGenerico(){
    DomicilioPtr domicilioChofer1=crearDomicilio("Vieytes",2000,"Lomas de zamora");
    DomicilioPtr dirRetiro1=crearDomicilio("Deposito",5000,"Sector industrial"); /// (*)
    DomicilioPtr dirEntrega1=crearDomicilio("Santa fe",1500,"Banfield"); /// (**)
    FechaPtr fechaSalida1=crearFechaDirectN(10,12,2022,16,45); //Para el reparto
    FechaPtr fechaRetorno1=crearFechaDirectN(10,12,2022,17,45); //Para el reparto
    FechaPtr fechaEntrega1=crearFechaDirectN(10,12,2022,18,45);
    CuilPtr cuil1=crearCuil("20346547546");
    PersonaPtr chofer1=crearPersona("Roberto","Garcia",domicilioChofer1,cuil1,true);
    PaquetePtr paquete1=crearPaquete(1,4,5,2,65,dirRetiro1,dirEntrega1,fechaEntrega1,chofer1,0);
    ListaPtr listaPaquetes1=crearLista();
    agregarDatoLista(listaPaquetes1,(PaquetePtr)paquete1);
    VehiculoPtr vehiculo1=crearVehiculo(3,"Mercedes Benz","Actros","17 UJI 30");
    RepartoPtr reparto1=crearReparto(chofer1,vehiculo1,fechaSalida1,fechaRetorno1,listaPaquetes1);
    return reparto1;
}


ListaPtr crearListaRepartosPorDefecto(){
    ListaPtr listaRepartos=crearLista();
    DomicilioPtr domicilioChofer1=crearDomicilio("Vieytes",2000,"Lomas de zamora");
    DomicilioPtr dirRetiro1=crearDomicilio("Deposito",5000,"Sector industrial"); /// (*)
    DomicilioPtr dirEntrega1=crearDomicilio("Santa fe",1500,"Banfield"); /// (**)
    FechaPtr fechaSalida1=crearFechaDirectN(10,12,2022,16,45); //Para el reparto
    FechaPtr fechaRetorno1=crearFechaDirectN(10,12,2022,17,45); //Para el reparto
    FechaPtr fechaEntrega1=crearFechaDirectN(10,12,2022,18,45);
    CuilPtr cuil1=crearCuil("20346547546");
    PersonaPtr chofer1=crearPersona("Roberto","Garcia",domicilioChofer1,cuil1,true);
    PaquetePtr paquete1=crearPaquete(1,4,5,2,65,dirRetiro1,dirEntrega1,fechaEntrega1,chofer1,0);
    ListaPtr listaPaquetes1 = crearLista();
    insertarDatoLista(listaPaquetes1,(PaquetePtr)paquete1,0);
    VehiculoPtr vehiculo1=crearVehiculo(3,"Mercedes Benz","Actros","17 UJI 30");
    RepartoPtr reparto1=crearReparto(chofer1,vehiculo1,fechaSalida1,fechaRetorno1,listaPaquetes1);

    DomicilioPtr domicilioChofer2=crearDomicilio("Boqueron",1500,"Villa Fiorito");
    DomicilioPtr dirRetiro2=crearDomicilio("Repositorio Intel",5000,"Sector industrial");
    DomicilioPtr dirEntrega2=crearDomicilio("Italia",3000,"Palermo");
    FechaPtr fechaSalida2=crearFechaDirectN(10,12,2022,8,30);
    FechaPtr fechaRetorno2=crearFechaDirectN(10,12,2022,9,30);
    FechaPtr fechaEntrega2=crearFechaDirectN(10,12,2022,10,30);
    CuilPtr cuil2=crearCuil("27245764567");
    PersonaPtr chofer2=crearPersona("Maria","Gonzalez",domicilioChofer2,cuil2,true);
    PaquetePtr paquete2=crearPaquete(2,2,5,3,120,dirRetiro2,dirEntrega2,fechaEntrega2,chofer2,0);
    ListaPtr listaPaquetes2=crearLista();
    insertarDatoLista(listaPaquetes2,(PaquetePtr)paquete2,0);
    VehiculoPtr vehiculo2=crearVehiculo(3,"Mercedes Benz","Actros","81 NMB 30");
    RepartoPtr reparto2=crearReparto(chofer2,vehiculo2,fechaSalida2,fechaRetorno2,listaPaquetes2);

    DomicilioPtr domicilioChofer3=crearDomicilio("Espania",1500,"Puerto Madero");
    DomicilioPtr dirRetiro3=crearDomicilio("Tesla Industry",10000,"Washington DC");
    DomicilioPtr dirEntrega3=crearDomicilio("24 de mayo",3000,"Capital Federal");
    FechaPtr fechaSalida3=crearFechaDirectN(10,12,2022,19,15);
    FechaPtr fechaRetorno3=crearFechaDirectN(10,12,2022,21,15);
    FechaPtr fechaEntrega3=crearFechaDirectN(10,12,2022,22,15);
    CuilPtr cuil3=crearCuil("30234565431");
    PersonaPtr chofer3=crearPersona("Gonzalo","Gutierrez",domicilioChofer3,cuil3,true);
    PaquetePtr paquete3=crearPaquete(3,8,8,10,800,dirRetiro3,dirEntrega3,fechaEntrega3,chofer3,0);
    ListaPtr listaPaquetes3=crearLista();
    insertarDatoLista(listaPaquetes3,(PaquetePtr)paquete3,0);
    VehiculoPtr vehiculo3=crearVehiculo(3,"Mercedes Benz","Actros","19 JUY 78");
    RepartoPtr reparto3=crearReparto(chofer3,vehiculo3,fechaSalida3,fechaRetorno3,listaPaquetes3);

    agregarDatoLista(listaRepartos,(RepartoPtr)reparto1);
    agregarDatoLista(listaRepartos,(RepartoPtr)reparto2);
    agregarDatoLista(listaRepartos,(RepartoPtr)reparto3);
    return listaRepartos;
}

ListaPtr crearListaPaquetesGenerico(){
    ListaPtr listaPaquetes = crearLista();
    DomicilioPtr domicilio1 = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    CuilPtr cuil_1 = crearCuil("20654342349");
    PersonaPtr cliente1 = crearPersona("Javier","Gonzalez",domicilio1,cuil_1,false);
    PaquetePtr paquete1 = crearPaqueteDirect(rand(),4,2,5,150,"Sixto Fernandez",1800,"Lomas de Zamora","Calle Morazan",2100,"Villa fiorito",10,12,2022,16,45,0,cliente1);
    PaquetePtr paquete2 = crearPaqueteDirect(rand(),20,7,3,200,"Sixto Fernandez",1700,"Lomas de Zamora","Calle Morazan",2020,"Villa fiorito",10,12,2022,17,45,0,cliente1);
    PaquetePtr paquete3 = crearPaqueteDirect(rand(),15,5,9,75,"Sixto Fernandez",1220,"Lomas de Zamora","Calle Morazan",2310,"Villa fiorito",10,12,2022,18,45,0,cliente1);
    PaquetePtr paquete4 = crearPaqueteDirect(rand(),25,14,15,54,"Sixto Fernandez",5000,"Lomas de Zamora","Calle Morazan",250,"Villa fiorito",10,12,2022,19,45,0,cliente1);
    PaquetePtr paquete5 = crearPaqueteDirect(rand(),12,11,23,54,"Sixto Fernandez",1000,"Lomas de Zamora","Calle Morazan",650,"Villa fiorito",10,12,2022,20,45,0,cliente1);
    PaquetePtr paquete6 = crearPaqueteDirect(rand(),14,16,31,54,"Sixto Fernandez",2000,"Lomas de Zamora","Calle Morazan",550,"Villa fiorito",10,12,2022,21,45,0,cliente1);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete1);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete2);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete3);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete4);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete5);
    agregarDatoLista(listaPaquetes,(PaquetePtr)paquete6);
    return listaPaquetes;
}

PaquetePtr crearPaqueteGenerico(){
    DomicilioPtr domicilio1 = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    CuilPtr cuil_1 = crearCuil("20654342349");
    PersonaPtr cliente1 = crearPersona("Javier","Gonzalez",domicilio1,cuil_1,false);
    PaquetePtr paquete1 = crearPaqueteDirect(rand(),4,2,5,150,"Sixto Fernandez",1800,"Lomas de Zamora","Calle Morazan",2100,"Villa fiorito",10,12,2022,16,45,0,cliente1);
    return paquete1;
}

ListaPtr crearListaClientesGenerico(){
    ListaPtr listaClientes = crearLista();
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
    agregarDatoLista(listaClientes,(PersonaPtr)cliente1);
    agregarDatoLista(listaClientes,(PersonaPtr)cliente2);
    agregarDatoLista(listaClientes,(PersonaPtr)cliente3);
    agregarDatoLista(listaClientes,(PersonaPtr)cliente4);
    return listaClientes;
}


ListaPtr crearListaChoferesGenerico(){
    ListaPtr listaChoferes = crearLista();
    DomicilioPtr domicilio1 = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    CuilPtr cuil_1 = crearCuil("20654342349");
    PersonaPtr chofer1 = crearPersona("Javier","Gonzalez",domicilio1,cuil_1,true);
    DomicilioPtr domicilio2 = crearDomicilio("Italia",1000,"Lomas de zamora");
    CuilPtr cuil_2 = crearCuil("20655612339");
    PersonaPtr chofer2 = crearPersona("Gonzalo","Gutierrez",domicilio2,cuil_2,true);
    DomicilioPtr domicilio3 = crearDomicilio("Espania",3000,"Lomas de zamora");
    CuilPtr cuil_3 = crearCuil("20245432349");
    PersonaPtr chofer3 = crearPersona("Gabriel","Alonzo",domicilio3,cuil_3,true);
    DomicilioPtr domicilio4 = crearDomicilio("9 de mayo",2000,"Lomas de zamora");
    CuilPtr cuil_4 = crearCuil("20126543212");
    PersonaPtr chofer4 = crearPersona("Alfonso","Romero",domicilio4,cuil_4,true);
    agregarDatoLista(listaChoferes,(PersonaPtr)chofer1);
    agregarDatoLista(listaChoferes,(PersonaPtr)chofer2);
    agregarDatoLista(listaChoferes,(PersonaPtr)chofer3);
    agregarDatoLista(listaChoferes,(PersonaPtr)chofer4);
    return listaChoferes;
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


void MetodoDistintoDeMostrado(){
    int i=0;
    ListaPtr listaPaquetes = crearLista();
    listaPaquetes = crearListaPaquetesGenerico();
    while(i<longitudLista(listaPaquetes)){
        printf("%d.",i);
        mostrarPaquete((PaquetePtr)getDatoLista(listaPaquetes,i++));
    }
    //ListaPtr listaPaquetes1 = crearLista();
    listaPaquetes = crearListaPaquetesGenerico();
    CentroLogisticoPtr centroLogistico = crearCentroLogisticoRapido("Distribuidora");
    setPaquetes(centroLogistico, listaPaquetes);
    printf("Paquetes del centro logistico: %s\n", getNombreCentroLogistico(centroLogistico));
    for(int i=0;i<longitudLista(getPaquetes(centroLogistico));i++){
        printf("%d.",i);
        mostrarPaquete((PaquetePtr)getDatoLista(getPaquetes(centroLogistico),i));
    }
    /*
    ListaPtr listaAuxiliar=getLista(centroLogistico);
    while(!listaVacia(listaAuxiliar)){
        mostrarElemento(getCabecera(listaAuxiliar));
        listaAuxiliar=getResto(listaAuxiliar);
    }
    listaAuxiliar=destruirLista(listaAuxiliar,false);
    */
    ListaPtr listaAux=listaPaquetes;
    for(int i=0;i<longitudLista(listaPaquetes);i++){
        printf("%d. ",i);
        mostrarPersona((PersonaPtr)getCabecera(listaAux));
        listaAux=getResto(listaAux);
    }

    ListaPtr LA;
    ///LA=listaChoferes;
    while(!listaVacia(LA)){
        mostrarPersona(getCabecera(LA));
        LA=getResto(LA);
    }
    system("pause");
}


void ProbarFuncionesArchivos(){
    ListaPtr listaClientes=crearListaClientesGenerico();
    ListaPtr listaVehiculos=crearListaVehiculosGenerico();
    ListaPtr listaRepartos=crearListaRepartosPorDefecto();
    ListaPtr listaChoferes=crearListaChoferesGenerico();
    ListaPtr listaPaquetes=crearListaPaquetesGenerico();
    //ListaPtr listaRepartosCerrados=crearLista();
    GuardarListaClientesYChoferesNuevo(listaChoferes,false);
    GuardarListaClientesYChoferesNuevo(listaClientes,true);
    GuardarListaPaquetesNuevo(listaPaquetes);
    GuardarListaRepartosNuevo(listaRepartos,true);
    GuardarListaVehiculosNuevo(listaVehiculos);
    LeerListaClientesYChoferesNuevo(false);
    LeerListaClientesYChoferesNuevo(true);
    LeerListaPaquetesNuevo();
    LeerListaRepartosNuevo(true);
    LeerListaVehiculosNuevo();



    ///CentroLogisticoPtr centroLogistico=crearCentroLogistico("Distribuidora",listaPaquetes,listaClientes,listaChoferes,listaVehiculos,listaRepartos,listaRepartosCerrados);
    ///GuardarTodoNuevo(centroLogistico);
    ///CentroLogisticoPtr cntroLog;
    ///cntroLog=AbrirTodoNuevo();
}


///--------------------------------------------------------------------------///

///--------------------------------------------------------------------------///

///--------------------------------------------------------------------------///

                ///SECCION DE PRUEBAS DE FILES.C///


///--------------------------------------------------------------------------///

///--------------------------------------------------------------------------///

///--------------------------------------------------------------------------///




/*
void pruebaPasajeReparto(){
    fReparto RE;
    RepartoPtr RD=crearRepartoGenerico();
    ListaPtr LP=getListaPaquetesReparto(RD);
    ///mostrarPaquetesListaReparto(RD);
    fPaquete P[10];
    PasajeRepartoDinamico(&RE,RD,false);
    RepartoPtr RDP=PasajeRepartoDinamico(&RE,RDP,true);
    mostrarReparto(RDP);
    ///PaquetePtr PD=crearPaqueteGenerico();
    ///PasajePaqueteDinamico(&P[0],PD,false);
    ///PaquetePtr PDP=PasajePaqueteDinamico(&P[0],PDP,true);
    ///mostrarPaquete(PDP);
    //PasajePaqueteDinamico(&P[0],PD,false);
    //PasajeArrayPaquetesAestatico(&P[0],PD);
    //PaquetePtr PDP=PasajeArrayPaquetesAdinamico(P[0]);
    //ListaPtr LA=PROBANDO(P);
    //PaquetePtr PDP=getCabecera(LA);
    //printf("%d %d %d\n", PDP->alto,PDP->ancho,PDP->peso);
    system("pause");

    /// printf("%d\n", sizeof(fReparto));
    ///printf("%d\n",sizeof(paquetes));
    ///printf("%d\n",sizeof(fPaquete));
    for(int i=0;i<10;i++){
        PasajePaqueteDinamico(&paquetes[i],PD,false);
    }*/
    ///pasajePaquetePrueba(&paquetes,PD);
    /*for(int i=0;i<10;i++){
        printf("\n\n");
        printf("%d\n", paquetes[0].alto);
        printf("%d\n", paquetes[0].ancho);
    }*/
    //PDP=PasajePaqueteDinamico(&paquetes[0],PDP,true);
    ///pasajePaquetePrueba(&paquetes,PD);
    ///int valor=paquetes[0].alto;
    ///PDP->alto=valor;
    ///printf("%d\n", PDP->alto);
    ///printf("%d\n", valor);
    ///printf("%d\n", paquetes[0].alto);
    ///mostrarReparto(RD);
    /*PasajeRepartoDinamico(&RE,RD,false);
    printf("REPARTO ESTATICO\n\n");
    printf("%s \n", RE.chofer.nombre);
    system("pause");
    RepartoPtr RDP=PasajeRepartoDinamico(&RE,RDP,true);*/
    ///mostrarPersona(RDP->chofer);
    ///mostrarVehiculo(RDP->vehiculo);
    ///mostrarFecha(RDP->fechaSalida);
    ///mostrarFecha(RDP->fechaRetorno);
    ///mostrarReparto(RDP);
//}





///-----------------------------------------------------------------------///

/*
void pruebaPasajePaquete(){
    fPaquete PE;
    DomicilioPtr domicilio1 = crearDomicilio("Sixto Fernandez",2000,"Lomas de zamora");
    CuilPtr cuil_1 = crearCuil("20654342349");
    PersonaPtr cliente1 = crearPersona("Javier","Gonzalez",domicilio1,cuil_1,false);
    PaquetePtr PD=crearPaqueteDirect1(1,1,1,1,1,"1",1,"1","1",1,"1",1,1,2022,1,1,1,"1","1","1",1,"1","1","1","1","1",1,"1","1",false);
    ///mostrarPaquete(PD);
    PasajePaqueteDinamico(&PE,PD,false);
    PaquetePtr PDP=PasajePaqueteDinamico(&PE,PDP,true);
    system("cls");
    mostrarPaquete(PDP);
    printf("%d\n", PE.alto);
    printf("%d\n", PE.fechaEntrega.dia);
    printf("%d\n", PE.dirEntrega.altura);
    printf("%d\n", PE.dirRetiro.altura);
    printf("%s\n", PE.cliente.nombre);
}*/


/*

void pruebaPasaje(ListaPtr listaVehiculos){
    fVehiculo VE;///Vehiculo en memoria estatica
    fVehiculo VEP;///Vehiculo en memoria estatica de prueba
    VehiculoPtr VD;///Vehiculo en memoria dinamica
    VehiculoPtr VDP;///Vehiculo en memoria dinamica de prueba
    VehiculoPtr VDPV2;///Vehiculo en memoria dinamica de prueba version 2

    printf("Nueva prueba: \n\n");
    ///printf("%s\n", getMarca(&VE));///BROKEN
    ///mostrarVehiculo(&VE);
    VD=crearVehiculo(3,"Mercedes Benz","Actros","19JKU89");
    PasajeVehiculoDinamico(&VE,VD,false);
    VD=destruirVehiculo(VD);
    VDP=PasajeVehiculoDinamico(&VE,VDP,true);
    ///mostrarVehiculo(VDP);

    FILE* a;
    a=fopen("PROBANDO.bin","wb");
    fwrite(&VE,sizeof(fVehiculo),1,a);
    fclose(a);
    a=fopen("PROBANDO.bin","rb");
    fread(&VEP,sizeof(fVehiculo),1,a);
    fclose(a);
    VDPV2=PasajeVehiculoDinamico(&VEP,VDPV2,true);
    mostrarVehiculo(VDPV2);
    system("pause");
}
*/

    /*VD=crearVehiculo(3,"Mercedes Benz","Actros","19JKU89");
    DinamicoEstatico(VD,&VE);
    printf("Prueba inicial de pasaje dinamico-estatico\n");
    printf("%d\n", VE.tipo);
    printf("%s\n", VE.marca);
    printf("%s\n", VE.modelo);
    printf("%s\n", VE.patente);
    fVehiculoPtr VED;///Vehiculo en memoria dinamico con tamanio campos en memoria estatica
    FILE *a;
    a=fopen("probando.bin","wb");
    fwrite(&VE,sizeof(fVehiculo),1,a);
    fclose(a);
    a=fopen("probando.bin","rb");
    fread(&VEP,sizeof(fVehiculo),1,a);
    fclose(a);
    printf("Prueba inicial de lectura\n");
    printf("%d\n", VEP.tipo);
    printf("%s\n", VEP.marca);
    printf("%s\n", VEP.modelo);
    printf("%s\n", VEP.patente);*/

    /*
void pruebaDePasajes(){
    fCuil CE;
    CuilPtr CD=crearCuil("20458730955");
    fDomicilio DE;
    DomicilioPtr DD=crearDomicilio("Sixto",1200,"Lomas");
    fFecha FE;
    FechaPtr FD=crearFecha(10,12,2022,16,45);
    PasajeCuilDinamico(&CE,CD,false);
    PasajeDomicilioDinamico(&DE,DD,false);
    PasajeFechaDinamico(&FE,FD,false);
    printf("Evaluacion de las pruebas: \n\n");
    printf("Cuil: %s\n", CE.cuil);
    printf("Domicilio: %s - %d - %s \n", DE.calle,DE.altura,DE.localidad);
    printf("Fecha: %d / %d / %d -- %d : %d \n", FE.dia,FE.mes,FE.anio,FE.hora,FE.minuto);
    system("pause");
}*/

/*
void pruebaPasajePersona(){
    fPersona PE;
    PersonaPtr PD=crearPersonaDirect("GASTON","ROMERO","SIXTO",1200,"LOMAS","20458730955",false);
    mostrarPersona(PD);
    PasajePersonaDinamico(&PE,PD,false);
    printf("Probando Resultados:\n\n");
    printf("%s - %s - %s - %d - %s - %s \n", PE.nombre,PE.apellido,PE.domicilio.calle,PE.domicilio.altura,PE.domicilio.localidad,PE.cuil);
    system("pause");
}
*/






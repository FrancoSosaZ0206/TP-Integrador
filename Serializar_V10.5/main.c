#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "TDAVehiculo.h"
#include "FilesV2.h"
#include "TDACentroLogistico.h"
#include "test.h"

void perfiles(CentroLogisticoPtr c)
{
    int i = 0;
    char nombreCarpeta[100];
    printf("1. Crear perfil\n");
    printf("2. Guardar perfil\n");
    printf("3. Cargar perfil\n");
    limpiarBufferTeclado();
    scanf("%d", &i);
    limpiarBufferTeclado();
    switch(i)
    {
        case 1:
            printf("Seleccione el nombre de la carpeta: ");
            limpiarBufferTeclado();
            scanf("%[^\n]%*c", nombreCarpeta);
            limpiarBufferTeclado();
            if( crearCarpeta(nombreCarpeta) )
            {
                return;
            }
            else
            {
                printf("Carpeta existente\n");
                system("pause");
            }
            break;
        case 2:
            printf("Seleccione el nombre de la carpeta: ");
            limpiarBufferTeclado();
            scanf("%[^\n]%*c", nombreCarpeta);
            limpiarBufferTeclado();
            if( guardarTodo(c, nombreCarpeta) )
            {
                return;
            }
            else
            {
                printf("Fallo al guardar los datos del usuario\n");
                system("pause");
            }
            break;
        case 3:
            printf("Seleccione el nombre de la carpeta: ");
            limpiarBufferTeclado();
            scanf("%[^\n]%*c", nombreCarpeta);
            limpiarBufferTeclado();
            if( abrirCarpeta(nombreCarpeta) )
            {
                 if( abrirTodo(c, nombreCarpeta) )
                 {
                     return;
                 }
                 else
                 {
                     printf("Fallo al abrir al encontrar al usuario\n");
                     system("pause");
                 }
            }
            else
            {
                printf("No se pudo abrir la carpeta\n");
                system("pause");
            }
            break;
    }
}


int main()
{
//    CentroLogisticoPtr c = crearCentroLogisticoRapido("Fuente");
    CentroLogisticoPtr c = NULL;
    perfiles(c);
//
//
//    printf("\n\n\nSEGUNDA FASE\n\n\n");
//    system("pause");
//
//
//
//    int n=2;
//
//    VehiculoPtr v[n];
//    PersonaPtr p[n];
//    PaquetePtr paq[n];
//    RepartoPtr r[n];
//
//    PilaPtr pilaPaqReparto = crearPila();
//    FechaPtr fechaSalida = getTiempoActual();
//    FechaPtr fechaEntrega = getTiempoActual();
//    FechaPtr fechaRetorno = getTiempoActual();
//
//    fechaEntrega = sumarAFecha(fechaRetorno,0,0,10);
//    fechaRetorno = sumarAFecha(fechaRetorno,0,0,30);
//
//    v[0] = crearVehiculo(2,"Lamborghini","Aventador","FG 445 ZT");
////    v[1] = crearVehiculo(3,"Fiat","Fiorino","AA 111 AA");
////    v[2] = crearVehiculo(2,"Ford","Fiesta","BB 222 BB");
//
//    p[0] = crearPersonaDirect("Juan Carlos","Mellino","a",1,"a","20 43265222 0",true);
////    p[1] = crearPersonaDirect("Aurelio","Pulido Alarcon","San Martin",1670,"Azul","20 64861835 3",false);
////    p[2] = crearPersonaDirect("Lola","Arenas Barragan","Victor Martinez",1739,"Caniuelas","27 44389013 6",true);
//
//    paq[0] = crearPaqueteDirect(1,1,1,1,1,"1",1,"1","11",11,"11",getDia(fechaEntrega),getMes(fechaEntrega),getAnio(fechaEntrega),getHora(fechaEntrega),getMinuto(fechaEntrega),0);
////    paq[1] = crearPaqueteDirect(2,2,2,2,2,"2",2,"2","22",22,"22",getDia(fechaEntrega),getMes(fechaEntrega),getAnio(fechaEntrega),getHora(fechaEntrega),getMinuto(fechaEntrega),1);
////    paq[2] = crearPaqueteDirect(3,3,3,3,3,"3",3,"3","33",33,"33",getDia(fechaEntrega),getMes(fechaEntrega),getAnio(fechaEntrega),getHora(fechaEntrega),getMinuto(fechaEntrega),2);
////    paq[3] = crearPaqueteDirect(4,4,4,4,4,"4",4,"4","44",44,"44",getDia(fechaEntrega),getMes(fechaEntrega),getAnio(fechaEntrega),getHora(fechaEntrega),getMinuto(fechaEntrega),3);
////    paq[4] = crearPaqueteDirect(5,5,5,5,5,"5",5,"5","55",55,"55",getDia(fechaEntrega),getMes(fechaEntrega),getAnio(fechaEntrega),getHora(fechaEntrega),getMinuto(fechaEntrega),4);
////    paq[5] = crearPaqueteDirect(6,6,6,6,6,"6",6,"6","66",66,"66",getDia(fechaEntrega),getMes(fechaEntrega),getAnio(fechaEntrega),getHora(fechaEntrega),getMinuto(fechaEntrega),5);
//
//
//
//
////    for(int i=0,j=0;i<n;i++,j=j+2)
////    {
//    r[0] = armarReparto(p[0],v[0],fechaSalida,fechaRetorno,pilaPaqReparto);
//    cargarPaquete(r[0],paq[0]);
////    cargarPaquete(r[0],paq[1]);
////        cargarPaquete(r[i],paq[j+2]);
////    }
//
////    for(int i=0,j=0;i<n;i++,j=j+2)
////    {
//    agregarVehiculo(c,v[0]);
//    agregarPersona(c,p[0]);
//    agregarPaquete(c,paq[0]);
////    agregarPaquete(c,paq[1]);
//    agregarReparto(c,r[0]);
////    }
//
//    printf("\n\n");
//    for(int i=0;i<1;i++)
//        mostrarReparto(r[0]);
//    presionarEnterYLimpiarPantalla();
//
//    if(!serializarPaquetes(c) || !serializarPersonas(c) || !serializarVehiculos(c) || !serializarRepartos(c))
//        exit(1);
//    c = destruirCentroLogistico(c);
//
//    c = crearCentroLogisticoRapido("Recuperado");
//
//    if(!deserializarPaquetes(c) || !deserializarPersonas(c) || !deserializarVehiculos(c) || !deserializarRepartos(c))
//        exit(2);
//
//    printf("Luego de deserializar: \n\n");
////    mostrarPaquetes(c);
////    mostrarPersonas(c,3);
////    mostrarVehiculos(c);
////    mostrarRepartos(c,true);
////    printf("\n\n");
////    for(int i=0;i<1;i++)
////    {
////        mostrarReparto(r[0]);
////        printf("\n\nPaquete del reparto (%d): %p\n",i+1,descargarPaquete(r[i]));
////    }
//    mostrarReparto(getDatoLista(getRepartos(c),0));
//
//    c = destruirCentroLogistico(c);


    return 0;
}

/**
VALIDO = FALSE;

WHILE(!VALIDO)
{
    CHOFER = ELEGIRCHOFER();
    VALIDO = CHOFERDISPONIBLE(CHOFER);
}

WHILE()
{
    WHILE()
    {

        FOR()
        {

        }

    }

}

**/

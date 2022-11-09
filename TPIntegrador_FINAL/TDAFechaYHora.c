#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "TDAFechaYHora.h"
#include "util.h"

int calcularDiaJuliano(int dia, int mes, int anio)
{
    return (1461 * (anio + 4800 + (mes - 14)/12))/4
           + (367 * (mes - 2 - 12 * ((mes - 14)/12)))/12
           - (3 * ((anio + 4900 + (mes - 14)/12)/100))/4 + dia - 32075;
}
//creacion y destruccion:
FechaPtr crearFecha(int dia,int mes,int anio,int hora,int minuto)
{
    FechaPtr f=(FechaPtr)obtenerMemoria(sizeof(Fecha));
    f->diaJuliano=calcularDiaJuliano(dia,mes,anio);

    f->hora=hora;
    f->minuto=minuto; ///Agregamos estas dos a la estructura antes de retornar f.

    return f;
}
///Orientada a crear fecha a partir de otra fecha (o si se parte de d. julianos) (utilizada en Files).
FechaPtr crearFechaDirect(int diaJuliano,int hora,int minuto)
{
    FechaPtr f = (FechaPtr)obtenerMemoria(sizeof(Fecha));
    f->diaJuliano=diaJuliano;
    f->hora=hora;
    f->minuto=minuto;

    return f;
}
FechaPtr destruirFecha(FechaPtr fecha)
{
    free(fecha);
    return NULL;
}
//getters:
int getDiaJuliano(FechaPtr fecha)
{
    return fecha->diaJuliano;
}
int getDia(FechaPtr fecha)
{
    int j = fecha->diaJuliano;
    int f = j + 1401 + (((4 * j + 274277) / 146097) * 3) / 4 -38;
    int e = 4 * f + 3;
    int g = (e % 1461) / 4;
    int h = 5 * g + 2;
    return ((h % 153) / 5) + 1;
}
int getMes(FechaPtr fecha)
{
    int j = fecha->diaJuliano;
    int f = j + 1401 + (((4 * j + 274277) / 146097) * 3) / 4 -38;
    int e = 4 * f + 3;
    int g = (e % 1461) / 4;
    int h = 5 * g + 2;
    return ((h / 153 + 2) % 12) + 1;
}
int getAnio(FechaPtr fecha)
{
    int j = fecha->diaJuliano;
    int f = j + 1401 + (((4 * j + 274277) / 146097) * 3) / 4 -38;
    int e = 4 * f + 3;
    int g = (e % 1461) / 4;
    int h = 5 * g + 2;
    int mes =((h / 153 + 2) % 12) + 1;
    return (e / 1461) - 4716 + (12 + 2 - mes) / 12;
}
int getHora(FechaPtr fecha)
{
    return fecha->hora;
}
int getMinuto(FechaPtr fecha)
{
    return fecha->minuto;
}
///setters
void setDiaJuliano(FechaPtr fecha,int diaJuliano)
{
    fecha->diaJuliano=diaJuliano;
}
void setDia(FechaPtr fecha,int dia)
{
    int d=getDia(fecha); //convertimos el dia juliano a dia gregoriano
    d=dia; //cambiamos el día antiguo por el nuevo
    int m=getMes(fecha);
    int a=getAnio(fecha); //para calcular el nuevo dia juliano tambien precisamos obtener el mes y anio
    int newDay=calcularDiaJuliano(d,m,a); //calculamos el nuevo día juliano llamando a la funcion
    fecha->diaJuliano=newDay; //seteamos el nuevo día calculado
}
void setMes(FechaPtr fecha,int mes)
{ //para el resto de setters es la misma logica
    int m=getMes(fecha);
    m=mes;
    int d=getDia(fecha);
    int a=getAnio(fecha);
    int newMonth=calcularDiaJuliano(d,m,a);
    fecha->diaJuliano=newMonth;
}
void setAnio(FechaPtr fecha,int anio)
{
    int a=getAnio(fecha);
    a=anio;
    int d=getDia(fecha);
    int m=getMes(fecha);
    int newYear=calcularDiaJuliano(d,m,a);
    fecha->diaJuliano=newYear;
}
void setHora(FechaPtr fecha,int hora)
{
    fecha->hora=hora;
}
void setMinuto(FechaPtr fecha,int minuto)
{
    fecha->minuto=minuto;
}
//Operaciones
int *calcularDiferenciaFechas(FechaPtr fecha1,FechaPtr fecha2) ///Nueva implementación
{
    int *diferencias = obtenerMemoria(sizeof(int)*3);

    diferencias[0] = getDiaJuliano(fecha1) - getDiaJuliano(fecha2);
    diferencias[1] = getHora(fecha1) - getHora(fecha2);
    diferencias[2] = getMinuto(fecha1) - getMinuto(fecha2);

    return diferencias;
}
void traerFechaCorta(FechaPtr fecha,char *buffer)
{ /**OPTIMIZACION DE LA FUNCIÓN:
En lugar de calcular donde poner las barras haciendo una cadena de ifs
que contemplen la cantidad de dígitos posibles del día y mes de la fecha,
Usamos la funcion strcat, con lo que concatenamos la barra al final del
string como esta en ese momento, sin importar que tantos dígitos tengan
los meses y días de la fecha.
*/

    sprintf(buffer,"%d",getDia(fecha)); //insertamos el día
    strcat(buffer,"/"); ///insertamos la barra al final del string
    sprintf(buffer+strlen(buffer),"%d",getMes(fecha)); //repetimos para mes y año
    strcat(buffer,"/");
    sprintf(buffer+strlen(buffer),"%d",getAnio(fecha));
}
char *traerFechaCortaDinamica(FechaPtr fecha)
{
    char *buffer=(char *)obtenerMemoria(sizeof(char)*11);
    traerFechaCorta(fecha,buffer);
    return buffer;
}
bool esBiciesto(FechaPtr fecha)
{
    int anio=getAnio(fecha);
    if(anio%400==0 || (anio%4==0 && anio%100!=0))
        return true;
    else
        return false;
}
FechaPtr sumarAFecha(FechaPtr fecha,int dias)
{
    fecha->diaJuliano+=dias;
    return fecha;
}
int diaSemana(FechaPtr fecha)
{
    return (fecha->diaJuliano+1) % 7;
}
void diaSemanaStr(FechaPtr fecha,char *buffer)
{
    int res=diaSemana(fecha);
    char *dias[]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
    strcpy(buffer,dias[res]);
}
void traerFechaLarga(FechaPtr fecha, char* buffer)
{ /* PROCESO:
    1. Almacenamos el día de la semana.
    2. Ponemos la coma, el espacio y metemos el día.
    3. Ponemos " de " y el mes.
    4. Ponemos " de " y el año.

    Los nombres de los días de la semana y los meses
    pueden variar dependiendo de cual se trate, asimismo
    con la longitud resultante del string, por lo que usar
    strlen() y sprintf se encargaría de medir cada una de
    estas palabras, resolviendo el problema.
*/


    char *diaSemana=(char*)obtenerMemoria((sizeof(char)*9)+1);
    diaSemanaStr(fecha,diaSemana);
    char *mes[]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio",
                 "Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

    int i=getMes(fecha)-1; //este será el mes numerico.
    //Le restamos 1 x q mes[] va de 0 a 11, y getMes() va de 1 a 12

    strcpy(buffer,diaSemana); //copiamos el dia de la semana
    strcat(buffer,", "); //ponemos la coma al final de eso

    sprintf(buffer+strlen(buffer),"%d",getDia(fecha)); //agregamos el dia numerico
    strcat(buffer," de "); //concatenamos " de " al final del buffer

    strcat(buffer,mes[i]); //concatenamos el mes
    strcat(buffer," de ");

    sprintf(buffer+strlen(buffer),"%d",getAnio(fecha)); //agregamos el anio numerico

    free(diaSemana);
    diaSemana=NULL;
}
void traerFechaYHora(FechaPtr fecha,char *buffer)
{
    traerFechaCorta(fecha,buffer);
    strcat(buffer,", ");
    sprintf(buffer+strlen(buffer),"%d",getHora(fecha));
    strcat(buffer,":");
    sprintf(buffer+strlen(buffer),"%d",getMinuto(fecha));
}/// Nota: cuando usamos buffer+strlen(buffer), realmente no hace falta restar nada. Así como está, está bien.
char *traerFechaYHoraDinamica(FechaPtr fecha)
{
    char *buffer=(char*)obtenerMemoria(sizeof(char)*18);
    ///18 porque es el tamaño mas grande posible para este formato de fecha y hora.
    traerFechaYHora(fecha,buffer);
    return buffer;
}

bool esFechaValida(FechaPtr fecha)
{
    bool resultado=true;

//    E  F    M  A  M  J  J  A  S  O  N  D  <<<MESES
//    31 29/8 31 30 31 30 31 31 30 31 30 31 <<<DIAS

    int n=11;
    int vecMes[]={31,28,31,30,31,30,31,31,30,31,30,31};

    int mes=getMes(fecha);

    resultado = mes>=1 && mes<=n+1;

    int dia=getDia(fecha);

    if(mes==2)
        if(esBiciesto(fecha))
            vecMes[mes-1]++;

    resultado = resultado && (dia>=1 && dia<=vecMes[mes-1]);

    resultado = resultado && ((getAnio(fecha)>=2000) && (getAnio(fecha)<=2030)); //entre 2000 y 2030

    resultado = resultado && ((getHora(fecha)>=0) && (getHora(fecha)<=23));

    resultado = resultado && ((getMinuto(fecha)>=0) && (getMinuto(fecha)<=59));

    return resultado;
}

bool fechasIguales(FechaPtr fecha1,FechaPtr fecha2) ///NUEVA
{
    bool SonFechasIguales = true;
    SonFechasIguales = SonFechasIguales && (getDia(fecha1) == getDia(fecha2));
    SonFechasIguales = SonFechasIguales && (getMes(fecha1) == getMes(fecha2));
    SonFechasIguales = SonFechasIguales && (getAnio(fecha1) == getAnio(fecha2));
    SonFechasIguales = SonFechasIguales && (getHora(fecha1) == getHora(fecha2));
    SonFechasIguales = SonFechasIguales && (getMinuto(fecha1) == getMinuto(fecha2));
    return SonFechasIguales;
}

void MostrarFecha(FechaPtr fecha)
{
    printf(" %d / %d / %d - %d : %d \n\n", getDia(fecha), getMes(fecha), getAnio(fecha), getHora(fecha), getMinuto(fecha));
}

#ifndef TDAFECHAYHORA_H_INCLUDED
#define TDAFECHAYHORA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/** **********************************************************************************************************************
**************************************************************************************************************************
**************************************************************************************************************************

                                            INTERFAZ DEL TDA FECHA Y HORA

**************************************************************************************************************************
**************************************************************************************************************************
*** ****************************************************************************************************************** **/

typedef struct Fecha
{
    int diaJuliano;
    int hora;
    int minuto;
}   Fecha;
typedef Fecha * FechaPtr;

typedef struct tm time_e;

/// OPERACIONES


/** OPERACI�N: calcula el dia juliano
PRECONDICI�N: ninguna.
POSTCONDICI�N: Se calcula el dia juliano en base a un dia, mes y a�o.
PAR�METROS:
    - dia: entero representando el dia.
    - mes: entero representando el mes.
    - anio: entero representando el a�o.
DEVUELVE: entero representando el dia juliano calculado. */
int calcularDiaJuliano(int dia, int mes, int anio);

///creacion y destruccion

/** OPERACI�N: creaci�n (constructora) - crea una fecha.
PRECONDICI�N: Fecha no debe estar creada.
POSTCONDICI�N: Se crea fecha con dia, mes, anio, minuto y hora.
PAR�METROS:
    - dia: entero representando el dia.
    - mes: entero representando el mes.
    - anio: entero representando el a�o.
    - hora: entero representando la hora.
    - minuto: entero representando los minutos.
DEVUELVE: puntero a la fecha creada. */
FechaPtr crearFecha(int dia,int mes,int anio,int hora,int minuto);

/// Orientada a crear fecha a partir de otra fecha (o si se parte de d. julianos) (utilizada en Files).
/** OPERACI�N: Crea una fecha a partir de dia juliano en lugar de dia, mes y anio.
PRECONDICI�N: Fecha no debe estar creada.
POSTCONDICI�N: Se crea fecha con dia, mes, anio, minuto y hora.
PAR�METROS:
    - diaJuliano: entero representando el dia juliano (dia, mes y anio en 1 sola variable)
    - hora: entero representando la hora.
    - minuto: entero representando los minutos.
DEVUELVE: puntero a la fecha creada. */
FechaPtr crearFechaDirect(int diaJuliano,int hora,int minuto);

/** OPERACI�N: destrucci�n (destructora).
PRECONDICI�N: Que fecha este creada.
POSTCONDICI�N: Destruye la fecha y libera la memoria.
PAR�METROS:
    - fecha: puntero a la estructura a destruir.
DEVUELVE: NULL. */
FechaPtr destruirFecha(FechaPtr fecha);


///Getters

/** OPERACI�N: Obtencion de dia juliano.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene el dia juliano de fecha
PAR�METROS:
    - fecha: Fecha de la que se quiere obtener el dia juliano
DEVUELVE: un entero representando el d�a juliano. */
int getDiaJuliano(FechaPtr fecha);

/** OPERACI�N: Obtiene el dia.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene el dia de fecha
PAR�METROS:
    - fecha: Fecha del que es obtiene el dia.
DEVUELVE: un entero representando el d�a del mes. */
int getDia(FechaPtr fecha);

/** OPERACI�N: Obtiene el dia.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene el mes de fecha
PAR�METROS:
    - fecha: Fecha del que es obtiene el mes.
DEVUELVE: un entero representando el mes del a�o. */
int getMes(FechaPtr fecha);

/** OPERACI�N: Obtiene el dia.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene el a�o de fecha
PAR�METROS:
    - fecha: Fecha del que es obtiene el a�o.
DEVUELVE: un entero representando el a�o de la fecha. */
int getAnio(FechaPtr fecha);

/** OPERACI�N: Obtiene el dia.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene la hora de fecha
PAR�METROS:
    - fecha: Fecha del que es obtiene la hora.
DEVUELVE: un entero representando la hora del d�a. */
int getHora(FechaPtr fecha);

/** OPERACI�N: Obtiene el dia.
PRECONDICI�N: fecha debe haberse creado.
POSTCONDICI�N: se obtiene el minuto de fecha
PAR�METROS:
    - fecha: Fecha del que es obtiene el minuto.
DEVUELVE: un entero representando el minuto del d�a. */
int getMinuto(FechaPtr fecha);


///setters

/** OPERACI�N: Asigna el dia juliano a la fecha.
PRECONDICI�N: fecha debe haberse creado.
POSTCONDICI�N: fecha cambia con el nuevo valor de dia juliano.
PAR�METROS:
    - fecha: puntero a estructura fecha al que se asignara el nuevo valor
    - diaJuliano: entero representando el nuevo valor del dia juliano
DEVUELVE: nada. */
void setDiaJuliano(FechaPtr fecha,int diaJuliano);

/** OPERACI�N: Asigna el dia a la fecha.
PRECONDICI�N: fecha debe haberse creado.
POSTCONDICI�N: fecha cambia con el nuevo valor de dia.
PAR�METROS:
    - fecha: TDAFecha al que se asignara el nuevo valor de mes
    - dia: entero representando el nuevo valor del dia
DEVUELVE: nada. */
void setDia(FechaPtr fecha,int dia);

/** OPERACI�N: Asigna el mes a la fecha.
PRECONDICI�N: fecha debe haberse creado.
POSTCONDICI�N: fecha cambia con el nuevo valor de mes.
PAR�METROS:
    - fecha: TDAFecha al que se asignara el nuevo valor de mes
    - mes: entero representando el nuevo valor del mes
DEVUELVE: nada. */
void setMes(FechaPtr fecha,int mes);

/** OPERACI�N: Asigna el a�o a la fecha.
PRECONDICI�N: fecha debe haberse creado.
POSTCONDICI�N: fecha cambia con el nuevo valor de a�o.
PAR�METROS:
    - fecha: TDAFecha al que se asignara el nuevo valor de mes
    - anio: entero representando el nuevo valor del a�o
DEVUELVE: nada. */
void setAnio(FechaPtr fecha,int anio);

/** OPERACI�N: Asigna la hora a la fecha.
PRECONDICI�N: fecha debe haberse creado.
POSTCONDICI�N: fecha cambia con el nuevo valor de hora.
PAR�METROS:
    - fecha: TDAFecha al que se asignara el nuevo valor de mes
    - hora: entero representando el nuevo valor de la hora
DEVUELVE: nada. */
void setHora(FechaPtr fecha,int hora);

/** OPERACI�N: Asigna los minutos a la fecha.
PRECONDICI�N: fecha debe haberse creado.
POSTCONDICI�N: fecha cambia con el nuevo valor de minuto.
PAR�METROS:
    - fecha: TDAFecha al que se asignara el nuevo valor de mes
    - minuto: entero representando el nuevo valor de los minutos
DEVUELVE: nada. */
void setMinuto(FechaPtr fecha,int minuto);


///OPERACIONES ESPECIALES

/** OPERACI�N: de resta de fechas
PRECONDICI�N: fecha1 y fecha2 deben haberse creado
POSTCONDICI�N: se obtiene la diferencia entre ambas fechas (fecha1-fecha2) en d�as, horas y minutos.
PAR�METROS:
    - fecha1: TDAFecha al que se restar� fecha2
    - fecha2: TDAFecha que restar� a fecha1
DEVUELVE: un vector de enteros en memoria din�mica.
        Tiene 3 posiciones, cada una representando la diferencia entre fechas, de esta forma:
             - Posici�n 0: diferencia en d�as.
             - Posici�n 1: diferencia en horas.
             - Posici�n 2: diferencia en minutos.
        Para cualquiera de sus posiciones, si:
             - diferencias==0, no hay diferencia en ese campo.
             - diferencia<0, fecha1 es menor a fecha2 (es decir, fecha1 sucede antes que fecha2)
             - diferencia>0, fecha1 es mayor a fecha2 (es decir, fecha1 sucede despu�s que fecha2)

        *** Si diferencia==0 EN TODAS SUS POSICIONES, entonces las fechas son totalmente id�nticas*** */
// **** RECORDAR LIBERAR MEMORIA LUEGO DE USAR **** //
int *calcularDiferenciaFechas(FechaPtr fecha1,FechaPtr fecha2);

/** OPERACI�N de conversi�n a string
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene la representaci�n "dd/mm/aaaa" de la fecha
PAR�METROS:
    - fecha: TDAFecha a convertir
    - Buffer: buffer de memoria con capacidad para 11 char
DEVUELVE: nada. */
void traerFechaCorta(FechaPtr fecha,char *buffer);

/** OPERACI�N de conversi�n a string
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene la representaci�n "dd/mm/aaaa" de la fecha en un string de memoria din�mica
PAR�METROS:
    - fecha: TDAFecha a convertir
DEVUELVE: string din�mico con el contenido de la fecha recibida. */
// **** RECORDAR LIBERAR MEMORIA LUEGO DE USAR **** //
char *traerFechaCortaDinamica(FechaPtr fecha);

/** OPERACI�N para saber si el a�o es bisiesto
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene true/ false si la fecha es bisiesto
PAR�METROS:
    - fecha: TDA a verificar
DEVUELVE: booleano indicando si es biciesto (true) o no (false). */
bool esBiciesto(FechaPtr fecha);

///Nueva implementaci�n: ahora tambi�n podemos sumar horas y minutos
/** OPERACI�N: suma dias, horas y/o minutos a una fecha
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: a la fecha se le sumar�n los d�as indicados
PAR�METROS:
    - fecha: puntero a la fecha original
    - dias: entero representando los dias a sumar
    - horas: entero representando las horas a sumar
    - minutos: entero representando los minutos a sumar
DEVUELVE: puntero a la fecha con los d�as, horas y/o minutos sumados. */
FechaPtr sumarAFecha(FechaPtr fecha,int dias,int horas,int minutos);

/** OPERACI�N: Indica el n�mero de semana.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: Se sabe que numero de la semana es.
PAR�METROS:
    - fecha: estructura a sacar el calculo.
DEVUELVE: un entero a representar el numero de semana. */
int diaSemana(FechaPtr fecha);

/** OPERACI�N: Da el nombre del d�a.
PRECONDICI�N: fecha debe haberse creado.
POSTCONDICI�N: El buffer contiene el nombre del dia.
PAR�METROS:
    - fecha: estructura a sacar el nombre.
    - buffer: string que representa el nombre del dia.
DEVUELVE: nada. */
void diaSemanaStr(FechaPtr fecha,char *buffer);

/** OPERACI�N: Pone la fecha en string en el buffer.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: Buffer va a poseer la fecha en formato string.
PAR�METROS:
    - fecha: estructura a sacar el nombre.
    - buffer: string para guardar el nombre de la fecha.
DEVUELVE: nada. */
void traerFechaLarga(FechaPtr fecha, char* buffer);

/** OPERACI�N: Pone la fecha y la hora en string en el buffer.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: Buffer va a poseer la fecha y la hora en formato string.
PAR�METROS:
    - fecha: estructura a sacar el nombre.
    - buffer: string para guardar el nombre  y la hora de la fecha.
DEVUELVE: nada. */
void traerFechaYHora(FechaPtr fecha,char *buffer);

/** OPERACI�N: Pone la fecha y la hora en un string dinamico en el buffer.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: Buffer va a poseer la fecha y la hora en formato string dinamico.
PAR�METROS:
    - fecha: estructura a sacar el nombre
DEVUELVE: un string en memoria dinamica con la fecha recibida. */
// ****RECORDAR LIBERAR LA MEMORIA LUEGO DE USAR**** //
char *traerFechaYHoraDinamica(FechaPtr fecha);

/** OPERACI�N: Validacion de fecha
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: Se determina si la fecha es v�lida.
PAR�METROS:
    - fecha: puntero a la fecha a v�lidar.
DEVUELVE: true si es v�lida, false si no es valida. */
bool esFechaValida(FechaPtr fecha);

/** OPERACI�N: verifica si dos fechas son iguales.
PRECONDICI�N: Ambas fechas deben haber sido creadas.
POSTCONDICI�N: chequea si las estructuras son id�nticas en d�as, horas y minutos (utiliza la funcion diferenciaFechas)
PAR�METROS:
    - fecha1: puntero a la estructura a verificar.
    - fecha2: puntero a la estructura a verificar.
DEVUELVE: true si son id�nticas, false de lo contrario. */
bool fechasIguales(FechaPtr fecha1,FechaPtr fecha2);

/** OPERACI�N: muestra de una fecha
PRECONDICI�N: fecha debe haberse creado con crearFecha
POSTCONDICI�N: imprime por pantalla la fecha en formato [DD/MM/AAAA - hh:mm]
PAR�METROS:
    - fecha: puntero a la fecha a mostrar
DEVUELVE: nada. */
void mostrarFecha(FechaPtr fecha);


///FUNCIONES ESPECIALES:

/// //////////////////////////////////////////////////////////////////////////////////// ///
/** OPERACI�N: conversion de tipo de dato del tiempo a tipo TDA Fecha
PRECONDICI�N: tiempo debe haber sido cargado con la fecha actual.
POSTCONDICI�N: convierte un tiempo (fecha y hora) a TDA Fecha.
PAR�METROS:
    - tiempo: puntero a la estructura de tiempo de time.h
DEVUELVE: puntero a TDA fecha con el tiempo recibido. */
FechaPtr convertirAFecha(time_e *tiempo);
///Estas 2 son independientes entre s�.
/** OPERACI�N: obtencion del tiempo actual en un TDA Fecha
PRECONDICI�N: ninguna.
POSTCONDICI�N: obtiene el tiempo actual con las funciones de time.
               y las pone en un TDA fecha para hacerlo compatible
               con funciones de TDAFechaYHora.h .
PAR�METROS: ninguno.
DEVUELVE: puntero a TDA fecha con la hora actual. */
FechaPtr getTiempoActual();
/// //////////////////////////////////////////////////////////////////////////////////// ///


/** OPERACI�N: revisa si queda tiempo entre una fecha y el tiempo actual.
PRECONDICI�N: fechaLimite debe haber sido creada con crearFecha.
POSTCONDICI�N: calcula la diferencia de tiempo entre la fecha l�mite y el tiempo actual.
PAR�METROS:
    - fechaLimite: puntero a TDA fecha representando una fecha l�mite determinada.
DEVUELVE: booleano informando si queda tiempo (true) o no (false) antes de la fecha l�mite. */
bool quedaTiempo(FechaPtr fechaLimite);


#endif // TDAFECHAYHORA_H_INCLUDED

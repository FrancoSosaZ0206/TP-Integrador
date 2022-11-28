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


/** OPERACIÓN: calcula el dia juliano
PRECONDICIÓN: ninguna.
POSTCONDICIÓN: Se calcula el dia juliano en base a un dia, mes y año.
PARÁMETROS:
    - dia: entero representando el dia.
    - mes: entero representando el mes.
    - anio: entero representando el año.
DEVUELVE: entero representando el dia juliano calculado. */
int calcularDiaJuliano(int dia, int mes, int anio);

///creacion y destruccion

/** OPERACIÓN: creación (constructora) - crea una fecha.
PRECONDICIÓN: Fecha no debe estar creada.
POSTCONDICIÓN: Se crea fecha con dia, mes, anio, minuto y hora.
PARÁMETROS:
    - dia: entero representando el dia.
    - mes: entero representando el mes.
    - anio: entero representando el año.
    - hora: entero representando la hora.
    - minuto: entero representando los minutos.
DEVUELVE: puntero a la fecha creada. */
FechaPtr crearFecha(int dia,int mes,int anio,int hora,int minuto);

/// Orientada a crear fecha a partir de otra fecha (o si se parte de d. julianos) (utilizada en Files).
/** OPERACIÓN: Crea una fecha a partir de dia juliano en lugar de dia, mes y anio.
PRECONDICIÓN: Fecha no debe estar creada.
POSTCONDICIÓN: Se crea fecha con dia, mes, anio, minuto y hora.
PARÁMETROS:
    - diaJuliano: entero representando el dia juliano (dia, mes y anio en 1 sola variable)
    - hora: entero representando la hora.
    - minuto: entero representando los minutos.
DEVUELVE: puntero a la fecha creada. */
FechaPtr crearFechaDirect(int diaJuliano,int hora,int minuto);

/** OPERACIÓN: destrucción (destructora).
PRECONDICIÓN: Que fecha este creada.
POSTCONDICIÓN: Destruye la fecha y libera la memoria.
PARÁMETROS:
    - fecha: puntero a la estructura a destruir.
DEVUELVE: NULL. */
FechaPtr destruirFecha(FechaPtr fecha);


///Getters

/** OPERACIÓN: Obtencion de dia juliano.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene el dia juliano de fecha
PARÁMETROS:
    - fecha: Fecha de la que se quiere obtener el dia juliano
DEVUELVE: un entero representando el día juliano. */
int getDiaJuliano(FechaPtr fecha);

/** OPERACIÓN: Obtiene el dia.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene el dia de fecha
PARÁMETROS:
    - fecha: Fecha del que es obtiene el dia.
DEVUELVE: un entero representando el día del mes. */
int getDia(FechaPtr fecha);

/** OPERACIÓN: Obtiene el dia.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene el mes de fecha
PARÁMETROS:
    - fecha: Fecha del que es obtiene el mes.
DEVUELVE: un entero representando el mes del año. */
int getMes(FechaPtr fecha);

/** OPERACIÓN: Obtiene el dia.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene el año de fecha
PARÁMETROS:
    - fecha: Fecha del que es obtiene el año.
DEVUELVE: un entero representando el año de la fecha. */
int getAnio(FechaPtr fecha);

/** OPERACIÓN: Obtiene el dia.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene la hora de fecha
PARÁMETROS:
    - fecha: Fecha del que es obtiene la hora.
DEVUELVE: un entero representando la hora del día. */
int getHora(FechaPtr fecha);

/** OPERACIÓN: Obtiene el dia.
PRECONDICIÓN: fecha debe haberse creado.
POSTCONDICIÓN: se obtiene el minuto de fecha
PARÁMETROS:
    - fecha: Fecha del que es obtiene el minuto.
DEVUELVE: un entero representando el minuto del día. */
int getMinuto(FechaPtr fecha);


///setters

/** OPERACIÓN: Asigna el dia juliano a la fecha.
PRECONDICIÓN: fecha debe haberse creado.
POSTCONDICIÓN: fecha cambia con el nuevo valor de dia juliano.
PARÁMETROS:
    - fecha: puntero a estructura fecha al que se asignara el nuevo valor
    - diaJuliano: entero representando el nuevo valor del dia juliano
DEVUELVE: nada. */
void setDiaJuliano(FechaPtr fecha,int diaJuliano);

/** OPERACIÓN: Asigna el dia a la fecha.
PRECONDICIÓN: fecha debe haberse creado.
POSTCONDICIÓN: fecha cambia con el nuevo valor de dia.
PARÁMETROS:
    - fecha: TDAFecha al que se asignara el nuevo valor de mes
    - dia: entero representando el nuevo valor del dia
DEVUELVE: nada. */
void setDia(FechaPtr fecha,int dia);

/** OPERACIÓN: Asigna el mes a la fecha.
PRECONDICIÓN: fecha debe haberse creado.
POSTCONDICIÓN: fecha cambia con el nuevo valor de mes.
PARÁMETROS:
    - fecha: TDAFecha al que se asignara el nuevo valor de mes
    - mes: entero representando el nuevo valor del mes
DEVUELVE: nada. */
void setMes(FechaPtr fecha,int mes);

/** OPERACIÓN: Asigna el año a la fecha.
PRECONDICIÓN: fecha debe haberse creado.
POSTCONDICIÓN: fecha cambia con el nuevo valor de año.
PARÁMETROS:
    - fecha: TDAFecha al que se asignara el nuevo valor de mes
    - anio: entero representando el nuevo valor del año
DEVUELVE: nada. */
void setAnio(FechaPtr fecha,int anio);

/** OPERACIÓN: Asigna la hora a la fecha.
PRECONDICIÓN: fecha debe haberse creado.
POSTCONDICIÓN: fecha cambia con el nuevo valor de hora.
PARÁMETROS:
    - fecha: TDAFecha al que se asignara el nuevo valor de mes
    - hora: entero representando el nuevo valor de la hora
DEVUELVE: nada. */
void setHora(FechaPtr fecha,int hora);

/** OPERACIÓN: Asigna los minutos a la fecha.
PRECONDICIÓN: fecha debe haberse creado.
POSTCONDICIÓN: fecha cambia con el nuevo valor de minuto.
PARÁMETROS:
    - fecha: TDAFecha al que se asignara el nuevo valor de mes
    - minuto: entero representando el nuevo valor de los minutos
DEVUELVE: nada. */
void setMinuto(FechaPtr fecha,int minuto);


///OPERACIONES ESPECIALES

/** OPERACIÓN: de resta de fechas
PRECONDICIÓN: fecha1 y fecha2 deben haberse creado
POSTCONDICIÓN: se obtiene la diferencia entre ambas fechas (fecha1-fecha2) en días, horas y minutos.
PARÁMETROS:
    - fecha1: TDAFecha al que se restará fecha2
    - fecha2: TDAFecha que restará a fecha1
DEVUELVE: un vector de enteros en memoria dinámica.
        Tiene 3 posiciones, cada una representando la diferencia entre fechas, de esta forma:
             - Posición 0: diferencia en días.
             - Posición 1: diferencia en horas.
             - Posición 2: diferencia en minutos.
        Para cualquiera de sus posiciones, si:
             - diferencias==0, no hay diferencia en ese campo.
             - diferencia<0, fecha1 es menor a fecha2 (es decir, fecha1 sucede antes que fecha2)
             - diferencia>0, fecha1 es mayor a fecha2 (es decir, fecha1 sucede después que fecha2)

        *** Si diferencia==0 EN TODAS SUS POSICIONES, entonces las fechas son totalmente idénticas*** */
// **** RECORDAR LIBERAR MEMORIA LUEGO DE USAR **** //
int *calcularDiferenciaFechas(FechaPtr fecha1,FechaPtr fecha2);

/** OPERACIÓN de conversión a string
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene la representación "dd/mm/aaaa" de la fecha
PARÁMETROS:
    - fecha: TDAFecha a convertir
    - Buffer: buffer de memoria con capacidad para 11 char
DEVUELVE: nada. */
void traerFechaCorta(FechaPtr fecha,char *buffer);

/** OPERACIÓN de conversión a string
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene la representación "dd/mm/aaaa" de la fecha en un string de memoria dinámica
PARÁMETROS:
    - fecha: TDAFecha a convertir
DEVUELVE: string dinámico con el contenido de la fecha recibida. */
// **** RECORDAR LIBERAR MEMORIA LUEGO DE USAR **** //
char *traerFechaCortaDinamica(FechaPtr fecha);

/** OPERACIÓN para saber si el año es bisiesto
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene true/ false si la fecha es bisiesto
PARÁMETROS:
    - fecha: TDA a verificar
DEVUELVE: booleano indicando si es biciesto (true) o no (false). */
bool esBiciesto(FechaPtr fecha);

///Nueva implementación: ahora también podemos sumar horas y minutos
/** OPERACIÓN: suma dias, horas y/o minutos a una fecha
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: a la fecha se le sumarán los días indicados
PARÁMETROS:
    - fecha: puntero a la fecha original
    - dias: entero representando los dias a sumar
    - horas: entero representando las horas a sumar
    - minutos: entero representando los minutos a sumar
DEVUELVE: puntero a la fecha con los días, horas y/o minutos sumados. */
FechaPtr sumarAFecha(FechaPtr fecha,int dias,int horas,int minutos);

/** OPERACIÓN: Indica el número de semana.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: Se sabe que numero de la semana es.
PARÁMETROS:
    - fecha: estructura a sacar el calculo.
DEVUELVE: un entero a representar el numero de semana. */
int diaSemana(FechaPtr fecha);

/** OPERACIÓN: Da el nombre del día.
PRECONDICIÓN: fecha debe haberse creado.
POSTCONDICIÓN: El buffer contiene el nombre del dia.
PARÁMETROS:
    - fecha: estructura a sacar el nombre.
    - buffer: string que representa el nombre del dia.
DEVUELVE: nada. */
void diaSemanaStr(FechaPtr fecha,char *buffer);

/** OPERACIÓN: Pone la fecha en string en el buffer.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: Buffer va a poseer la fecha en formato string.
PARÁMETROS:
    - fecha: estructura a sacar el nombre.
    - buffer: string para guardar el nombre de la fecha.
DEVUELVE: nada. */
void traerFechaLarga(FechaPtr fecha, char* buffer);

/** OPERACIÓN: Pone la fecha y la hora en string en el buffer.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: Buffer va a poseer la fecha y la hora en formato string.
PARÁMETROS:
    - fecha: estructura a sacar el nombre.
    - buffer: string para guardar el nombre  y la hora de la fecha.
DEVUELVE: nada. */
void traerFechaYHora(FechaPtr fecha,char *buffer);

/** OPERACIÓN: Pone la fecha y la hora en un string dinamico en el buffer.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: Buffer va a poseer la fecha y la hora en formato string dinamico.
PARÁMETROS:
    - fecha: estructura a sacar el nombre
DEVUELVE: un string en memoria dinamica con la fecha recibida. */
// ****RECORDAR LIBERAR LA MEMORIA LUEGO DE USAR**** //
char *traerFechaYHoraDinamica(FechaPtr fecha);

/** OPERACIÓN: Validacion de fecha
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: Se determina si la fecha es válida.
PARÁMETROS:
    - fecha: puntero a la fecha a válidar.
DEVUELVE: true si es válida, false si no es valida. */
bool esFechaValida(FechaPtr fecha);

/** OPERACIÓN: verifica si dos fechas son iguales.
PRECONDICIÓN: Ambas fechas deben haber sido creadas.
POSTCONDICIÓN: chequea si las estructuras son idénticas en días, horas y minutos (utiliza la funcion diferenciaFechas)
PARÁMETROS:
    - fecha1: puntero a la estructura a verificar.
    - fecha2: puntero a la estructura a verificar.
DEVUELVE: true si son idénticas, false de lo contrario. */
bool fechasIguales(FechaPtr fecha1,FechaPtr fecha2);

/** OPERACIÓN: muestra de una fecha
PRECONDICIÓN: fecha debe haberse creado con crearFecha
POSTCONDICIÓN: imprime por pantalla la fecha en formato [DD/MM/AAAA - hh:mm]
PARÁMETROS:
    - fecha: puntero a la fecha a mostrar
DEVUELVE: nada. */
void mostrarFecha(FechaPtr fecha);


///FUNCIONES ESPECIALES:

/// //////////////////////////////////////////////////////////////////////////////////// ///
/** OPERACIÓN: conversion de tipo de dato del tiempo a tipo TDA Fecha
PRECONDICIÓN: tiempo debe haber sido cargado con la fecha actual.
POSTCONDICIÓN: convierte un tiempo (fecha y hora) a TDA Fecha.
PARÁMETROS:
    - tiempo: puntero a la estructura de tiempo de time.h
DEVUELVE: puntero a TDA fecha con el tiempo recibido. */
FechaPtr convertirAFecha(time_e *tiempo);
///Estas 2 son independientes entre sí.
/** OPERACIÓN: obtencion del tiempo actual en un TDA Fecha
PRECONDICIÓN: ninguna.
POSTCONDICIÓN: obtiene el tiempo actual con las funciones de time.
               y las pone en un TDA fecha para hacerlo compatible
               con funciones de TDAFechaYHora.h .
PARÁMETROS: ninguno.
DEVUELVE: puntero a TDA fecha con la hora actual. */
FechaPtr getTiempoActual();
/// //////////////////////////////////////////////////////////////////////////////////// ///


/** OPERACIÓN: revisa si queda tiempo entre una fecha y el tiempo actual.
PRECONDICIÓN: fechaLimite debe haber sido creada con crearFecha.
POSTCONDICIÓN: calcula la diferencia de tiempo entre la fecha límite y el tiempo actual.
PARÁMETROS:
    - fechaLimite: puntero a TDA fecha representando una fecha límite determinada.
DEVUELVE: booleano informando si queda tiempo (true) o no (false) antes de la fecha límite. */
bool quedaTiempo(FechaPtr fechaLimite);


#endif // TDAFECHAYHORA_H_INCLUDED

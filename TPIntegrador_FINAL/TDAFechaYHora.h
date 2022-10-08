#ifndef TDAFECHAYHORA_H_INCLUDED
#define TDAFECHAYHORA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


///Interfaz del TDA FECHA



///Definicion de la estructura fecha:


typedef struct Fecha
{//definicion del TDA con su variante puntero
    int diaJuliano;
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
}   Fecha;
typedef Fecha * FechaPtr;



///Operaciones


///creacion y destruccion
//Operación: Crea fecha.
//Precondición: Fecha no debe estar creada.
//Postcondición: Se crea fecha con dia, mes, anio, minuto y hora.
//Parámetros:
// dia: entero representando el dia.
// mes: entero representando el mes.
// anio: entero representando el año.
// hora: entero representando la hora.
// minuto: entero representando los minutos.
//Devuelve un puntero a la estructura.
FechaPtr crearFecha(int dia,int mes,int anio,int hora,int minuto);
///NUEVA: Orientada a crear fecha a partir de otra fecha (o si se parte de d. julianos) (utilizada en Files).
//Operación: Crea fecha a partir de dia juliano en lugar de dia, mes y anio.
//Precondición: Fecha no debe estar creada.
//Postcondición: Se crea fecha con dia, mes, anio, minuto y hora.
//Parámetros:
// diaJuliano: entero representando el dia juliano (dia, mes y anio en 1 sola variable)
// hora: entero representando la hora.
// minuto: entero representando los minutos.
//Devuelve un puntero a la estructura.
FechaPtr crearFechaDirect(int diaJuliano,int hora,int minuto);
//Operación: Destruir fecha.
//Precondición: Que fecha este creada.
//Postcondición: Destruye fecha y libera la memoria.
//Parámetros:
// fecha: puntero a la estructura a destruir.
//Devuelve NULL.
FechaPtr destruirFecha(FechaPtr fecha);

///Getters

//Operación: Obtencion de dia juliano.
//Precondición: fecha debe haberse creado
//Postcondición: se obtiene el dia juliano de fecha
//Parámetros:
//  fecha: Fecha de la que se quiere obtener el dia juliano
// Devuelve un entero representando el día juliano.
int getDiaJuliano(FechaPtr fecha); ///NUEVA
//Operación: Obtiene el dia.
//Precondición: fecha debe haberse creado
//Postcondición: se obtiene el dia de fecha
//Parámetros:
//  fecha: Fecha del que es obtiene el dia.
// Devuelve un entero representando el día del mes
int getDia(FechaPtr fecha);
//Operación: Obtiene el dia.
//Precondición: fecha debe haberse creado
//Postcondición: se obtiene el mes de fecha
//Parámetros:
//  fecha: Fecha del que es obtiene el mes.
// Devuelve un entero representando el mes del año.
int getMes(FechaPtr fecha);
//Operación: Obtiene el dia.
//Precondición: fecha debe haberse creado
//Postcondición: se obtiene el año de fecha
//Parámetros:
//  fecha: Fecha del que es obtiene el año.
// Devuelve un entero representando el año de la fecha.
int getAnio(FechaPtr fecha);
//Operación: Obtiene el dia.
//Precondición: fecha debe haberse creado
//Postcondición: se obtiene la hora de fecha
//Parámetros:
//  fecha: Fecha del que es obtiene la hora.
// Devuelve un entero representando la hora de la fecha.
int getHora(FechaPtr fecha);
//Operación: Obtiene el dia.
//Precondición: fecha debe haberse creado.
//Postcondición: se obtiene el minuto de fecha
//Parámetros:
//  fecha: Fecha del que es obtiene el minuto.
// Devuelve un entero representando el minuto de la fecha.
int getMinuto(FechaPtr fecha);
///setters
//Operación: Asigna el dia juliano a la fecha.
//Precondición: fecha debe haberse creado.
//Postcondición: fecha cambia con el nuevo valor de dia juliano.
//Parámetros:
//  fecha: puntero a estructura fecha al que se asignara el nuevo valor
//  diaJuliano: entero representando el nuevo valor del dia juliano
//No devuelve nada
void setDiaJuliano(FechaPtr fecha,int diaJuliano); ///NUEVA
//Operación: Asigna el dia a la fecha.
//Precondición: fecha debe haberse creado.
//Postcondición: fecha cambia con el nuevo valor de dia.
//Parámetros:
//  fecha: TDAFecha al que se asignara el nuevo valor de mes
//  dia: entero representando el nuevo valor del dia
//No devuelve nada
void setDia(FechaPtr fecha,int dia);
//Operación: Asigna el mes a la fecha.
//Precondición: fecha debe haberse creado.
//Postcondición: fecha cambia con el nuevo valor de mes.
//Parámetros:
//  fecha: TDAFecha al que se asignara el nuevo valor de mes
//  mes: entero representando el nuevo valor del mes
//No devuelve nada
void setMes(FechaPtr fecha,int mes);
//Operación: Asigna el año a la fecha.
//Precondición: fecha debe haberse creado.
//Postcondición: fecha cambia con el nuevo valor de año.
//Parámetros:
//  fecha: TDAFecha al que se asignara el nuevo valor de mes
//  anio: entero representando el nuevo valor del año
//No devuelve nada
void setAnio(FechaPtr fecha,int anio);
//Operación: Asigna la hora a la fecha.
//Precondición: fecha debe haberse creado.
//Postcondición: fecha cambia con el nuevo valor de hora.
//Parámetros:
//  fecha: TDAFecha al que se asignara el nuevo valor de mes
//  hora: entero representando el nuevo valor de la hora
//No devuelve nada
void setHora(FechaPtr fecha,int hora);
//Operación: Asigna los minutos a la fecha.
//Precondición: fecha debe haberse creado.
//Postcondición: fecha cambia con el nuevo valor de minuto.
//Parámetros:
//  fecha: TDAFecha al que se asignara el nuevo valor de mes
//  minuto: entero representando el nuevo valor de los minutos
//No devuelve nada
void setMinuto(FechaPtr fecha,int minuto);
//Operación: de resta de fechas
//Precondición: fecha1 y fecha2 deben haberse creado
///Postcondición: se obtiene la diferencia entre ambas fechas (fecha1-fecha2) en días, horas y minutos.
//Parámetros:
//  fecha1: TDAFecha al que se restará fecha2
//  fecha2: TDAFecha que restará a fecha1
///Devuelve un vector de enteros de 3 posiciones representando la diferencia entre fechas, de esta forma:
///             - Posición 0: diferencia en días.
///             - Posición 1: diferencia en horas.
///             - Posición 2: diferencia en minutos.
///     Para cualquiera de sus posiciones, si:
///             - diferencias==0, no hay diferencia en ese campo.
///             - diferencia<0, fecha1 es menor a fecha2 (es decir, fecha1 sucede antes que fecha2)
///             - diferencia>0, fecha1 es mayor a fecha2 (es decir, fecha1 sucede después que fecha2)

///     *** Si diferencia==0 EN TODAS SUS POSICIONES, entonces las fechas son totalmente idénticas.
///     ADVERTENCIA: manejar con cuidado, chequeando siempre con lo explicado acá.
int *calcularDiferenciaFechas(FechaPtr fecha1,FechaPtr fecha2); ///Nueva implementación
// Operación de conversión a string
// Precondición: fecha debe haberse creado
// Postcondición: se obtiene la representación "dd/mm/aaaa" de la fecha
// Parámetros:
//  fecha: TDAFecha a convertir
//  Buffer: buffer de memoria con capacidad para 11 char
// No devuelve valor.
void traerFechaCorta(FechaPtr fecha,char *buffer);
// Operación de conversión a string
// Precondición: fecha debe haberse creado
// Postcondición: se obtiene la representación "dd/mm/aaaa" de la fecha en memoria dinámica
// Parámetros:
//  fecha: TDAFecha a convertir
// Devuelve puntero a la representación como srtring en memoria dinámica
// **** Recordar liberar memoria luego de utilizar ****//
char *traerFechaCortaDinamica(FechaPtr fecha);
//Operación para saber si el año es bisiesto
//Precondición: fecha debe haberse creado
//Postcondición: se obtiene true/ false si la fecha es bisiesto
//Parámetros:
// fecha: TDA a verificar
// Devuelve un boleano
bool esBiciesto(FechaPtr fecha);
//Operación para sumar dias a una fecha
//Precondición: fecha debe haberse creado
//Postcondición: fecha va a tener sumado los dias que le pase
//Parámetros:
// fecha: TDA a sumar
// dias: dias a sumar
//Devuelve un puntero a la estructura
FechaPtr sumarAFecha(FechaPtr fecha,int dias);
//Operación: Indica el numero de semana.
//Precondición: fecha debe haberse creado
//Postcondición: Se sabe que numero de la semana es.
//Parámetros:
// fecha: estructura a sacar el calculo.
//Devuelve un entero a representar el numero de semana.
int diaSemana(FechaPtr fecha);
//Operación: Da el nombre del dia.
//Precondición: fecha debe haberse creado.
//Postcondición: El buffer contiene el nombre del dia.
//Parámetros:
// fecha: estructura a sacar el nombre.
// buffer: string que representa el nombre del dia.
//No devuelve nada
void diaSemanaStr(FechaPtr fecha,char *buffer);
//Operación: Pone la fecha en string en el buffer.
//Precondición: fecha debe haberse creado
//Postcondición: Buffer va a poseer la fecha en formato string.
//Parámetros:
// fecha: estructura a sacar el nombre.
// buffer: string para guardar el nombre de la fecha.
//No devuelve nada
void traerFechaLarga(FechaPtr fecha, char* buffer);
//Operación: Pone la fecha y la hora en string en el buffer.
//Precondición: fecha debe haberse creado
//Postcondición: Buffer va a poseer la fecha y la hora en formato string.
//Parámetros:
// fecha: estructura a sacar el nombre.
// buffer: string para guardar el nombre  y la hora de la fecha.
//No devuelve nada
void traerFechaYHora(FechaPtr fecha,char *buffer);
//Operación: Pone la fecha y la hora en un string dinamico en el buffer.
//Precondición: fecha debe haberse creado
//Postcondición: Buffer va a poseer la fecha y la hora en formato string dinamico.
//Parámetros:
// fecha: estructura a sacar el nombre
//Devuelve un string en memoria dinamica.
///****RECORDAR LIBERAR LA MEMORIA LUEGO DE USAR****
char *traerFechaYHoraDinamica(FechaPtr fecha);

//Operación: Validacion de fecha
//Precondición: fecha debe haberse creado
//Postcondición: Se determina si la fecha es válida.
//Parámetros:
// fecha: puntero a la fecha a válidar.
//Devuelve true si es válida, false si no es valida.
bool esFechaValida(FechaPtr fecha); ///NUEVA

#endif //TDAFECHAYHORA_H_INCLUDED

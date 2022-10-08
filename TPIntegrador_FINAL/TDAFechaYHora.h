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
//Operaci�n: Crea fecha.
//Precondici�n: Fecha no debe estar creada.
//Postcondici�n: Se crea fecha con dia, mes, anio, minuto y hora.
//Par�metros:
// dia: entero representando el dia.
// mes: entero representando el mes.
// anio: entero representando el a�o.
// hora: entero representando la hora.
// minuto: entero representando los minutos.
//Devuelve un puntero a la estructura.
FechaPtr crearFecha(int dia,int mes,int anio,int hora,int minuto);
///NUEVA: Orientada a crear fecha a partir de otra fecha (o si se parte de d. julianos) (utilizada en Files).
//Operaci�n: Crea fecha a partir de dia juliano en lugar de dia, mes y anio.
//Precondici�n: Fecha no debe estar creada.
//Postcondici�n: Se crea fecha con dia, mes, anio, minuto y hora.
//Par�metros:
// diaJuliano: entero representando el dia juliano (dia, mes y anio en 1 sola variable)
// hora: entero representando la hora.
// minuto: entero representando los minutos.
//Devuelve un puntero a la estructura.
FechaPtr crearFechaDirect(int diaJuliano,int hora,int minuto);
//Operaci�n: Destruir fecha.
//Precondici�n: Que fecha este creada.
//Postcondici�n: Destruye fecha y libera la memoria.
//Par�metros:
// fecha: puntero a la estructura a destruir.
//Devuelve NULL.
FechaPtr destruirFecha(FechaPtr fecha);

///Getters

//Operaci�n: Obtencion de dia juliano.
//Precondici�n: fecha debe haberse creado
//Postcondici�n: se obtiene el dia juliano de fecha
//Par�metros:
//  fecha: Fecha de la que se quiere obtener el dia juliano
// Devuelve un entero representando el d�a juliano.
int getDiaJuliano(FechaPtr fecha); ///NUEVA
//Operaci�n: Obtiene el dia.
//Precondici�n: fecha debe haberse creado
//Postcondici�n: se obtiene el dia de fecha
//Par�metros:
//  fecha: Fecha del que es obtiene el dia.
// Devuelve un entero representando el d�a del mes
int getDia(FechaPtr fecha);
//Operaci�n: Obtiene el dia.
//Precondici�n: fecha debe haberse creado
//Postcondici�n: se obtiene el mes de fecha
//Par�metros:
//  fecha: Fecha del que es obtiene el mes.
// Devuelve un entero representando el mes del a�o.
int getMes(FechaPtr fecha);
//Operaci�n: Obtiene el dia.
//Precondici�n: fecha debe haberse creado
//Postcondici�n: se obtiene el a�o de fecha
//Par�metros:
//  fecha: Fecha del que es obtiene el a�o.
// Devuelve un entero representando el a�o de la fecha.
int getAnio(FechaPtr fecha);
//Operaci�n: Obtiene el dia.
//Precondici�n: fecha debe haberse creado
//Postcondici�n: se obtiene la hora de fecha
//Par�metros:
//  fecha: Fecha del que es obtiene la hora.
// Devuelve un entero representando la hora de la fecha.
int getHora(FechaPtr fecha);
//Operaci�n: Obtiene el dia.
//Precondici�n: fecha debe haberse creado.
//Postcondici�n: se obtiene el minuto de fecha
//Par�metros:
//  fecha: Fecha del que es obtiene el minuto.
// Devuelve un entero representando el minuto de la fecha.
int getMinuto(FechaPtr fecha);
///setters
//Operaci�n: Asigna el dia juliano a la fecha.
//Precondici�n: fecha debe haberse creado.
//Postcondici�n: fecha cambia con el nuevo valor de dia juliano.
//Par�metros:
//  fecha: puntero a estructura fecha al que se asignara el nuevo valor
//  diaJuliano: entero representando el nuevo valor del dia juliano
//No devuelve nada
void setDiaJuliano(FechaPtr fecha,int diaJuliano); ///NUEVA
//Operaci�n: Asigna el dia a la fecha.
//Precondici�n: fecha debe haberse creado.
//Postcondici�n: fecha cambia con el nuevo valor de dia.
//Par�metros:
//  fecha: TDAFecha al que se asignara el nuevo valor de mes
//  dia: entero representando el nuevo valor del dia
//No devuelve nada
void setDia(FechaPtr fecha,int dia);
//Operaci�n: Asigna el mes a la fecha.
//Precondici�n: fecha debe haberse creado.
//Postcondici�n: fecha cambia con el nuevo valor de mes.
//Par�metros:
//  fecha: TDAFecha al que se asignara el nuevo valor de mes
//  mes: entero representando el nuevo valor del mes
//No devuelve nada
void setMes(FechaPtr fecha,int mes);
//Operaci�n: Asigna el a�o a la fecha.
//Precondici�n: fecha debe haberse creado.
//Postcondici�n: fecha cambia con el nuevo valor de a�o.
//Par�metros:
//  fecha: TDAFecha al que se asignara el nuevo valor de mes
//  anio: entero representando el nuevo valor del a�o
//No devuelve nada
void setAnio(FechaPtr fecha,int anio);
//Operaci�n: Asigna la hora a la fecha.
//Precondici�n: fecha debe haberse creado.
//Postcondici�n: fecha cambia con el nuevo valor de hora.
//Par�metros:
//  fecha: TDAFecha al que se asignara el nuevo valor de mes
//  hora: entero representando el nuevo valor de la hora
//No devuelve nada
void setHora(FechaPtr fecha,int hora);
//Operaci�n: Asigna los minutos a la fecha.
//Precondici�n: fecha debe haberse creado.
//Postcondici�n: fecha cambia con el nuevo valor de minuto.
//Par�metros:
//  fecha: TDAFecha al que se asignara el nuevo valor de mes
//  minuto: entero representando el nuevo valor de los minutos
//No devuelve nada
void setMinuto(FechaPtr fecha,int minuto);
//Operaci�n: de resta de fechas
//Precondici�n: fecha1 y fecha2 deben haberse creado
///Postcondici�n: se obtiene la diferencia entre ambas fechas (fecha1-fecha2) en d�as, horas y minutos.
//Par�metros:
//  fecha1: TDAFecha al que se restar� fecha2
//  fecha2: TDAFecha que restar� a fecha1
///Devuelve un vector de enteros de 3 posiciones representando la diferencia entre fechas, de esta forma:
///             - Posici�n 0: diferencia en d�as.
///             - Posici�n 1: diferencia en horas.
///             - Posici�n 2: diferencia en minutos.
///     Para cualquiera de sus posiciones, si:
///             - diferencias==0, no hay diferencia en ese campo.
///             - diferencia<0, fecha1 es menor a fecha2 (es decir, fecha1 sucede antes que fecha2)
///             - diferencia>0, fecha1 es mayor a fecha2 (es decir, fecha1 sucede despu�s que fecha2)

///     *** Si diferencia==0 EN TODAS SUS POSICIONES, entonces las fechas son totalmente id�nticas.
///     ADVERTENCIA: manejar con cuidado, chequeando siempre con lo explicado ac�.
int *calcularDiferenciaFechas(FechaPtr fecha1,FechaPtr fecha2); ///Nueva implementaci�n
// Operaci�n de conversi�n a string
// Precondici�n: fecha debe haberse creado
// Postcondici�n: se obtiene la representaci�n "dd/mm/aaaa" de la fecha
// Par�metros:
//  fecha: TDAFecha a convertir
//  Buffer: buffer de memoria con capacidad para 11 char
// No devuelve valor.
void traerFechaCorta(FechaPtr fecha,char *buffer);
// Operaci�n de conversi�n a string
// Precondici�n: fecha debe haberse creado
// Postcondici�n: se obtiene la representaci�n "dd/mm/aaaa" de la fecha en memoria din�mica
// Par�metros:
//  fecha: TDAFecha a convertir
// Devuelve puntero a la representaci�n como srtring en memoria din�mica
// **** Recordar liberar memoria luego de utilizar ****//
char *traerFechaCortaDinamica(FechaPtr fecha);
//Operaci�n para saber si el a�o es bisiesto
//Precondici�n: fecha debe haberse creado
//Postcondici�n: se obtiene true/ false si la fecha es bisiesto
//Par�metros:
// fecha: TDA a verificar
// Devuelve un boleano
bool esBiciesto(FechaPtr fecha);
//Operaci�n para sumar dias a una fecha
//Precondici�n: fecha debe haberse creado
//Postcondici�n: fecha va a tener sumado los dias que le pase
//Par�metros:
// fecha: TDA a sumar
// dias: dias a sumar
//Devuelve un puntero a la estructura
FechaPtr sumarAFecha(FechaPtr fecha,int dias);
//Operaci�n: Indica el numero de semana.
//Precondici�n: fecha debe haberse creado
//Postcondici�n: Se sabe que numero de la semana es.
//Par�metros:
// fecha: estructura a sacar el calculo.
//Devuelve un entero a representar el numero de semana.
int diaSemana(FechaPtr fecha);
//Operaci�n: Da el nombre del dia.
//Precondici�n: fecha debe haberse creado.
//Postcondici�n: El buffer contiene el nombre del dia.
//Par�metros:
// fecha: estructura a sacar el nombre.
// buffer: string que representa el nombre del dia.
//No devuelve nada
void diaSemanaStr(FechaPtr fecha,char *buffer);
//Operaci�n: Pone la fecha en string en el buffer.
//Precondici�n: fecha debe haberse creado
//Postcondici�n: Buffer va a poseer la fecha en formato string.
//Par�metros:
// fecha: estructura a sacar el nombre.
// buffer: string para guardar el nombre de la fecha.
//No devuelve nada
void traerFechaLarga(FechaPtr fecha, char* buffer);
//Operaci�n: Pone la fecha y la hora en string en el buffer.
//Precondici�n: fecha debe haberse creado
//Postcondici�n: Buffer va a poseer la fecha y la hora en formato string.
//Par�metros:
// fecha: estructura a sacar el nombre.
// buffer: string para guardar el nombre  y la hora de la fecha.
//No devuelve nada
void traerFechaYHora(FechaPtr fecha,char *buffer);
//Operaci�n: Pone la fecha y la hora en un string dinamico en el buffer.
//Precondici�n: fecha debe haberse creado
//Postcondici�n: Buffer va a poseer la fecha y la hora en formato string dinamico.
//Par�metros:
// fecha: estructura a sacar el nombre
//Devuelve un string en memoria dinamica.
///****RECORDAR LIBERAR LA MEMORIA LUEGO DE USAR****
char *traerFechaYHoraDinamica(FechaPtr fecha);

//Operaci�n: Validacion de fecha
//Precondici�n: fecha debe haberse creado
//Postcondici�n: Se determina si la fecha es v�lida.
//Par�metros:
// fecha: puntero a la fecha a v�lidar.
//Devuelve true si es v�lida, false si no es valida.
bool esFechaValida(FechaPtr fecha); ///NUEVA

#endif //TDAFECHAYHORA_H_INCLUDED

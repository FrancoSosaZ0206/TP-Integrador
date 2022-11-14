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
    int hora;
    int minuto;
}   Fecha;
typedef Fecha * FechaPtr;



/** OPERACIONES


///creacion y destruccion
/** OPERACI�N: Crea fecha.
PRECONDICI�N: Fecha no debe estar creada.
POSTCONDICI�N: Se crea fecha con dia, mes, anio, minuto y hora.
PAR�METROS:
    - dia: entero representando el dia.
    - mes: entero representando el mes.
    - anio: entero representando el a�o.
    - hora: entero representando la hora.
    - minuto: entero representando los minutos.
DEVUELVE: un puntero a la estructura.
FechaPtr crearFecha(int dia,int mes,int anio,int hora,int minuto);
///NUEVA: Orientada a crear fecha a partir de otra fecha (o si se parte de d. julianos) (utilizada en Files).
/** OPERACI�N: Crea fecha a partir de dia juliano en lugar de dia, mes y anio.
PRECONDICI�N: Fecha no debe estar creada.
POSTCONDICI�N: Se crea fecha con dia, mes, anio, minuto y hora.
PAR�METROS:
    - diaJuliano: entero representando el dia juliano (dia, mes y anio en 1 sola variable)
    - hora: entero representando la hora.
    - minuto: entero representando los minutos.
DEVUELVE: un puntero a la estructura.
FechaPtr crearFechaDirect(int diaJuliano,int hora,int minuto);
/** OPERACI�N: Destruir fecha.
PRECONDICI�N: Que fecha este creada.
POSTCONDICI�N: Destruye fecha y libera la memoria.
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
DEVUELVE: un entero representando el d�a juliano.
int getDiaJuliano(FechaPtr fecha); ///NUEVA
/** OPERACI�N: Obtiene el dia.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene el dia de fecha
PAR�METROS:
    - fecha: Fecha del que es obtiene el dia.
DEVUELVE: un entero representando el d�a del mes
int getDia(FechaPtr fecha);
/** OPERACI�N: Obtiene el dia.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene el mes de fecha
PAR�METROS:
    - fecha: Fecha del que es obtiene el mes.
DEVUELVE: un entero representando el mes del a�o.
int getMes(FechaPtr fecha);
/** OPERACI�N: Obtiene el dia.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene el a�o de fecha
PAR�METROS:
    - fecha: Fecha del que es obtiene el a�o.
DEVUELVE: un entero representando el a�o de la fecha.
int getAnio(FechaPtr fecha);
/** OPERACI�N: Obtiene el dia.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene la hora de fecha
PAR�METROS:
    - fecha: Fecha del que es obtiene la hora.
DEVUELVE: un entero representando la hora de la fecha.
int getHora(FechaPtr fecha);
/** OPERACI�N: Obtiene el dia.
PRECONDICI�N: fecha debe haberse creado.
POSTCONDICI�N: se obtiene el minuto de fecha
PAR�METROS:
    - fecha: Fecha del que es obtiene el minuto.
DEVUELVE: un entero representando el minuto de la fecha.
int getMinuto(FechaPtr fecha);
///setters
/** OPERACI�N: Asigna el dia juliano a la fecha.
PRECONDICI�N: fecha debe haberse creado.
POSTCONDICI�N: fecha cambia con el nuevo valor de dia juliano.
PAR�METROS:
    - fecha: puntero a estructura fecha al que se asignara el nuevo valor
    - diaJuliano: entero representando el nuevo valor del dia juliano
DEVUELVE: nada. */
void setDiaJuliano(FechaPtr fecha,int diaJuliano); ///NUEVA
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
/** OPERACI�N: de resta de fechas
PRECONDICI�N: fecha1 y fecha2 deben haberse creado
POSTCONDICI�N: se obtiene la diferencia entre ambas fechas (fecha1-fecha2) en d�as, horas y minutos.
PAR�METROS:
    - fecha1: TDAFecha al que se restar� fecha2
    - fecha2: TDAFecha que restar� a fecha1
DEVUELVE: un vector de enteros de 3 posiciones representando la diferencia entre fechas, de esta forma:
             - Posici�n 0: diferencia en d�as.
             - Posici�n 1: diferencia en horas.
             - Posici�n 2: diferencia en minutos.
     Para cualquiera de sus posiciones, si:
             - diferencias==0, no hay diferencia en ese campo.
             - diferencia<0, fecha1 es menor a fecha2 (es decir, fecha1 sucede antes que fecha2)
             - diferencia>0, fecha1 es mayor a fecha2 (es decir, fecha1 sucede despu�s que fecha2)

     *** Si diferencia==0 EN TODAS SUS POSICIONES, entonces las fechas son totalmente id�nticas.
///     ADVERTENCIA: manejar con cuidado, chequeando siempre con lo explicado ac�.
int *calcularDiferenciaFechas(FechaPtr fecha1,FechaPtr fecha2); ///Nueva implementaci�n
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
POSTCONDICI�N: se obtiene la representaci�n "dd/mm/aaaa" de la fecha en memoria din�mica
PAR�METROS:
    - fecha: TDAFecha a convertir
DEVUELVE: puntero a la representaci�n como srtring en memoria din�mica
// **** Recordar liberar memoria luego de utilizar ****//
char *traerFechaCortaDinamica(FechaPtr fecha);
/** OPERACI�N para saber si el a�o es bisiesto
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: se obtiene true/ false si la fecha es bisiesto
PAR�METROS:
    - fecha: TDA a verificar
DEVUELVE: un boleano
bool esBiciesto(FechaPtr fecha);
/** OPERACI�N para sumar dias a una fecha
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: fecha va a tener sumado los dias que le pase
PAR�METROS:
    - fecha: TDA a sumar
    - dias: dias a sumar
DEVUELVE: un puntero a la estructura
FechaPtr sumarAFecha(FechaPtr fecha,int dias);
/** OPERACI�N: Indica el numero de semana.
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: Se sabe que numero de la semana es.
PAR�METROS:
    - fecha: estructura a sacar el calculo.
DEVUELVE: un entero a representar el numero de semana.
int diaSemana(FechaPtr fecha);
/** OPERACI�N: Da el nombre del dia.
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
DEVUELVE: un string en memoria dinamica.
//****RECORDAR LIBERAR LA MEMORIA LUEGO DE USAR****
char *traerFechaYHoraDinamica(FechaPtr fecha);

/** OPERACI�N: Validacion de fecha
PRECONDICI�N: fecha debe haberse creado
POSTCONDICI�N: Se determina si la fecha es v�lida.
PAR�METROS:
    - fecha: puntero a la fecha a v�lidar.
DEVUELVE: true si es v�lida, false si no es valida.
bool esFechaValida(FechaPtr fecha);

/** OPERACI�N: verifica si dos fechas son iguales.
PRECONDICI�N: Ambas fechas deben haber sido creadas.
POSTCONDICI�N: chequea si las estructuras son id�nticas en d�as, horas y minutos (utiliza la funcion diferenciaFechas)
PAR�METROS:
    - fecha1: puntero a la estructura a verificar.
    - fecha2: puntero a la estructura a verificar.
DEVUELVE: true si son id�nticas, false de lo contrario. */
bool fechasIguales(FechaPtr fecha1,FechaPtr fecha2); ///NUEVA

/** OPERACI�N: MOSTRAR
/PRECONDICI�N: FECHA DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
POSTCONDICI�N: MUESTRA LOS VALORES DE LA FECHA EN FORMATO
 [DD/MM/AAAA - HH:MM]
PAR�METROS:
 PUNTERO A FECHA [A MOSTRAR]
DEVUELVE: nada. */
void mostrarFecha(FechaPtr fecha);


#endif //TDAFECHAYHORA_H_INCLUDED

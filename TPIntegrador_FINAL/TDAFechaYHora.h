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
/** OPERACIÓN: Crea fecha.
PRECONDICIÓN: Fecha no debe estar creada.
POSTCONDICIÓN: Se crea fecha con dia, mes, anio, minuto y hora.
PARÁMETROS:
    - dia: entero representando el dia.
    - mes: entero representando el mes.
    - anio: entero representando el año.
    - hora: entero representando la hora.
    - minuto: entero representando los minutos.
DEVUELVE: un puntero a la estructura.
FechaPtr crearFecha(int dia,int mes,int anio,int hora,int minuto);
///NUEVA: Orientada a crear fecha a partir de otra fecha (o si se parte de d. julianos) (utilizada en Files).
/** OPERACIÓN: Crea fecha a partir de dia juliano en lugar de dia, mes y anio.
PRECONDICIÓN: Fecha no debe estar creada.
POSTCONDICIÓN: Se crea fecha con dia, mes, anio, minuto y hora.
PARÁMETROS:
    - diaJuliano: entero representando el dia juliano (dia, mes y anio en 1 sola variable)
    - hora: entero representando la hora.
    - minuto: entero representando los minutos.
DEVUELVE: un puntero a la estructura.
FechaPtr crearFechaDirect(int diaJuliano,int hora,int minuto);
/** OPERACIÓN: Destruir fecha.
PRECONDICIÓN: Que fecha este creada.
POSTCONDICIÓN: Destruye fecha y libera la memoria.
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
DEVUELVE: un entero representando el día juliano.
int getDiaJuliano(FechaPtr fecha); ///NUEVA
/** OPERACIÓN: Obtiene el dia.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene el dia de fecha
PARÁMETROS:
    - fecha: Fecha del que es obtiene el dia.
DEVUELVE: un entero representando el día del mes
int getDia(FechaPtr fecha);
/** OPERACIÓN: Obtiene el dia.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene el mes de fecha
PARÁMETROS:
    - fecha: Fecha del que es obtiene el mes.
DEVUELVE: un entero representando el mes del año.
int getMes(FechaPtr fecha);
/** OPERACIÓN: Obtiene el dia.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene el año de fecha
PARÁMETROS:
    - fecha: Fecha del que es obtiene el año.
DEVUELVE: un entero representando el año de la fecha.
int getAnio(FechaPtr fecha);
/** OPERACIÓN: Obtiene el dia.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene la hora de fecha
PARÁMETROS:
    - fecha: Fecha del que es obtiene la hora.
DEVUELVE: un entero representando la hora de la fecha.
int getHora(FechaPtr fecha);
/** OPERACIÓN: Obtiene el dia.
PRECONDICIÓN: fecha debe haberse creado.
POSTCONDICIÓN: se obtiene el minuto de fecha
PARÁMETROS:
    - fecha: Fecha del que es obtiene el minuto.
DEVUELVE: un entero representando el minuto de la fecha.
int getMinuto(FechaPtr fecha);
///setters
/** OPERACIÓN: Asigna el dia juliano a la fecha.
PRECONDICIÓN: fecha debe haberse creado.
POSTCONDICIÓN: fecha cambia con el nuevo valor de dia juliano.
PARÁMETROS:
    - fecha: puntero a estructura fecha al que se asignara el nuevo valor
    - diaJuliano: entero representando el nuevo valor del dia juliano
DEVUELVE: nada. */
void setDiaJuliano(FechaPtr fecha,int diaJuliano); ///NUEVA
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
/** OPERACIÓN: de resta de fechas
PRECONDICIÓN: fecha1 y fecha2 deben haberse creado
POSTCONDICIÓN: se obtiene la diferencia entre ambas fechas (fecha1-fecha2) en días, horas y minutos.
PARÁMETROS:
    - fecha1: TDAFecha al que se restará fecha2
    - fecha2: TDAFecha que restará a fecha1
DEVUELVE: un vector de enteros de 3 posiciones representando la diferencia entre fechas, de esta forma:
             - Posición 0: diferencia en días.
             - Posición 1: diferencia en horas.
             - Posición 2: diferencia en minutos.
     Para cualquiera de sus posiciones, si:
             - diferencias==0, no hay diferencia en ese campo.
             - diferencia<0, fecha1 es menor a fecha2 (es decir, fecha1 sucede antes que fecha2)
             - diferencia>0, fecha1 es mayor a fecha2 (es decir, fecha1 sucede después que fecha2)

     *** Si diferencia==0 EN TODAS SUS POSICIONES, entonces las fechas son totalmente idénticas.
///     ADVERTENCIA: manejar con cuidado, chequeando siempre con lo explicado acá.
int *calcularDiferenciaFechas(FechaPtr fecha1,FechaPtr fecha2); ///Nueva implementación
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
POSTCONDICIÓN: se obtiene la representación "dd/mm/aaaa" de la fecha en memoria dinámica
PARÁMETROS:
    - fecha: TDAFecha a convertir
DEVUELVE: puntero a la representación como srtring en memoria dinámica
// **** Recordar liberar memoria luego de utilizar ****//
char *traerFechaCortaDinamica(FechaPtr fecha);
/** OPERACIÓN para saber si el año es bisiesto
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: se obtiene true/ false si la fecha es bisiesto
PARÁMETROS:
    - fecha: TDA a verificar
DEVUELVE: un boleano
bool esBiciesto(FechaPtr fecha);
/** OPERACIÓN para sumar dias a una fecha
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: fecha va a tener sumado los dias que le pase
PARÁMETROS:
    - fecha: TDA a sumar
    - dias: dias a sumar
DEVUELVE: un puntero a la estructura
FechaPtr sumarAFecha(FechaPtr fecha,int dias);
/** OPERACIÓN: Indica el numero de semana.
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: Se sabe que numero de la semana es.
PARÁMETROS:
    - fecha: estructura a sacar el calculo.
DEVUELVE: un entero a representar el numero de semana.
int diaSemana(FechaPtr fecha);
/** OPERACIÓN: Da el nombre del dia.
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
DEVUELVE: un string en memoria dinamica.
//****RECORDAR LIBERAR LA MEMORIA LUEGO DE USAR****
char *traerFechaYHoraDinamica(FechaPtr fecha);

/** OPERACIÓN: Validacion de fecha
PRECONDICIÓN: fecha debe haberse creado
POSTCONDICIÓN: Se determina si la fecha es válida.
PARÁMETROS:
    - fecha: puntero a la fecha a válidar.
DEVUELVE: true si es válida, false si no es valida.
bool esFechaValida(FechaPtr fecha);

/** OPERACIÓN: verifica si dos fechas son iguales.
PRECONDICIÓN: Ambas fechas deben haber sido creadas.
POSTCONDICIÓN: chequea si las estructuras son idénticas en días, horas y minutos (utiliza la funcion diferenciaFechas)
PARÁMETROS:
    - fecha1: puntero a la estructura a verificar.
    - fecha2: puntero a la estructura a verificar.
DEVUELVE: true si son idénticas, false de lo contrario. */
bool fechasIguales(FechaPtr fecha1,FechaPtr fecha2); ///NUEVA

/** OPERACIÓN: MOSTRAR
/PRECONDICIÓN: FECHA DEBE HABER SIDO CREADO EN MEMORIA DINAMICA
POSTCONDICIÓN: MUESTRA LOS VALORES DE LA FECHA EN FORMATO
 [DD/MM/AAAA - HH:MM]
PARÁMETROS:
 PUNTERO A FECHA [A MOSTRAR]
DEVUELVE: nada. */
void mostrarFecha(FechaPtr fecha);


#endif //TDAFECHAYHORA_H_INCLUDED

#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

/**
****************************************************************************************************************
                                                INTERFAZ DE ARCHIVOS
****************************************************************************************************************/

///                                                 OPERACIONES


/// //////////////////////////////////////////////////////////////////////////////////////////////////////// ///
///                                                  ESCRITURA
/// //////////////////////////////////////////////////////////////////////////////////////////////////////// ///


/// Para conjuntos de datos - Para guardar bases de datos de structs por defecto.
//  Dedicadas a las funciones de creación de datos por defecto de test.h.

//OPERACIÓN: Guarda un conjunto de Personas
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//  centroLogistico: puntero al centro logistico donde se encuentran todos los datos por defecto.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarPersonas(CentroLogisticoPtr datosPorDefecto);
//OPERACIÓN: Guarda un conjunto de Paquetes
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//  centroLogistico: puntero al centro logistico donde se encuentran todos los datos por defecto.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarPaquetes(CentroLogisticoPtr datosPorDefecto);
//OPERACIÓN: Guarda un conjunto de Vehiculos
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//  centroLogistico: puntero al centro logistico donde se encuentran todos los datos por defecto.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarVehiculos(CentroLogisticoPtr datosPorDefecto);
//OPERACIÓN: Guarda un conjunto de Repartos
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//  centroLogistico: puntero al centro logistico donde se encuentran todos los datos por defecto.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarRepartos(CentroLogisticoPtr datosPorDefecto);


///---------------------------------------------------------------------------------------------------------------

/// Para listas de datos - Centro Logístico


//OPERACIÓN: guarda una lista de Personas en un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico y cargado con una
//              lista de Personas
//POSTCONDICIÓN: Extrae la lista de Personas y las registra una por una dentro de un archivo de texto
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Personas para guardar
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarListaPersonas(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: guarda una lista de Paquetes en un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico y cargado con una
//              lista de Paquetes
//POSTCONDICIÓN: Extrae la lista de Paquetes y los registra uno por uno dentro de un archivo de texto
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Paquetes para guardar
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarListaPaquetes(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: guarda una lista de Vehiculos en un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico y cargado con una
//              lista de Vehiculos
//POSTCONDICIÓN: Extrae la lista de Vehiculos y los registra uno por uno dentro de un archivo de texto
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Vehiculos para guardar
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarListaVehiculos(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: guarda una lista de Repartos Abiertos en un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico y cargado con una
//              lista de Repartos
//POSTCONDICIÓN: guarda en el archivo correspondiente según la variable esRepartoAbierto
//          si es true (esRepartoAbierto) se guardará en un archivo "Lista de Repartos Abiertos.txt"
//          en caso contrario (!esRepartoAbiero) se guardará en un archivo "Lista de Repartos Cerrados.txt"

//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Repartos para guardar
//  esRepartoAbierto: valor booleano:
//      true = si se quiere guardar un reparto abierto,
//      false = si se quiere guardar un reparto cerrado.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarListaRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);


///---------------------------------------------------------------------------------------------------------------

/// Guardado general

bool guardarTodoPorDefecto(CentroLogisticoPtr centroLogistico); ///PENDIENTE

//OPERACIÓN: guarda un centro logístico en un conjunto de archivos de texto.
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico previamente
//POSTCONDICIÓN: Utiliza a las funciones "guardarLista" para registrar el conjunto de datos procedente del
//               centro logistico en una serie de archivos de texto.
//PARÁMETROS
//      centroLogistico: Puntero a la estructura CentroLogistico a guardar
//DEVUELVE: verdadero si TODO se guardó correctamente,
//  falso si ocurrió un error EN EL GUARDADO DE ALGUNO DE LOS DATOS.
bool guardarTodo(CentroLogisticoPtr centroLogistico); //implementacion: llamará a las otras funciones de guardado





/// //////////////////////////////////////////////////////////////////////////////////////////////////////// ///
///                                                   LECTURA
//                                 Se reutilizan las estructuras creadas en main.c
/// //////////////////////////////////////////////////////////////////////////////////////////////////////// ///

/// Para conjuntos de datos - Para abrir bases de datos de structs por defecto.
//  Dedicadas a las funciones de creación de datos por defecto de test.h.

bool abrirFechas(FechaPtr *fechas);
//OPERACIÓN: Recupera los datos de un conjunto de Personas de un archivo de texto
//PRECONDICIÓN:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva función destructora.
/// - ADEMÁS, DEBEN HABERSE GUARDADO UN CONJUNTO DE PersonaS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Personas por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Copia dentro del conjunto de Personas los datos almacenados en un archivo de texto.
//PARÁMETROS
//  Personas: PUNTERO A PUNTERO A la estructura Persona (Doble puntero). Se puede pensar como un vector de Personas
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirPersonas(PersonaPtr *personas);
//OPERACIÓN: Recupera los datos de un conjunto de Paquetes de un archivo de texto
//PRECONDICIÓN:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva función destructora.
/// - ADEMÁS, DEBEN HABERSE GUARDADO UN CONJUNTO DE CuilS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Paquetes por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Copia dentro del conjunto de Paquetes los datos almacenados en un archivo de texto.
//PARÁMETROS
//  Paquetes: PUNTERO A PUNTERO A la estructura Paquete (Doble puntero). Se puede pensar como un vector de Paquetes
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirPaquetes(PaquetePtr *paquetes);
//OPERACIÓN: Recupera los datos de un conjunto de Vehiculos de un archivo de texto
//PRECONDICIÓN:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva función destructora.
/// - ADEMÁS, DEBEN HABERSE GUARDADO UN CONJUNTO DE VehiculoS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Vehiculos por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Copia dentro del conjunto de Vehiculos los datos almacenados en un archivo de texto.
//PARÁMETROS
//  Vehiculos: PUNTERO A PUNTERO A la estructura Vehiculo (Doble puntero). Se puede pensar como un vector de Vehiculos
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirVehiculos(VehiculoPtr *vehiculos);
//OPERACIÓN: Recupera los datos de un conjunto de Repartos de un archivo de texto
//PRECONDICIÓN:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva función destructora.
/// - ADEMÁS, DEBEN HABERSE GUARDADO UN CONJUNTO DE RepartoS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Reparto por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Copia dentro del conjunto de Repartos los datos almacenados en un archivo de texto.
//PARÁMETROS
//  Repartos: PUNTERO A PUNTERO A la estructura Reparto (Doble puntero). Se puede pensar como un vector de Repartos
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirRepartos(RepartoPtr *repartos);


///---------------------------------------------------------------------------------------------------------------

/// Para listas de datos - Centro Logístico


//OPERACIÓN: Recupera una lista de Personas de un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico,
//              y su lista de Personas debe estar vacía
/// - ADEMÁS, DEBE HABERSE GUARDADO UNA LISTA DE PersonaS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de Personas.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Abre el archivo y copia los datos en la lista de Personas del centro logístico recibido
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Personas para guardar
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirListaPersonas(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: Recupera una lista de Paquete de un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico,
//              y su lista de Paquetes debe estar vacía
/// - ADEMÁS, DEBE HABERSE GUARDADO UNA LISTA DE PaqueteS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de Paquetes.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Abre el archivo y copia los datos en la lista de Paquetes del centro logístico recibido
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Paquetes para guardar
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirListaPaquetes(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: Recupera una lista de Vehiculos de un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico,
//              y su lista de Vehiculos debe estar vacía
/// - ADEMÁS, DEBE HABERSE GUARDADO UNA LISTA DE VehiculoS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de Vehiculos.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Abre el archivo y copia los datos en la lista de Vehiculos del centro logístico recibido
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Vehiculos para guardar
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirListaVehiculos(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: Recupera una lista de Repartos de un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico,
//              y su lista de Repartos debe estar vacía
/// - ADEMÁS, DEBE HABERSE GUARDADO UNA LISTA DE PersonaS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de Repartos.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Abre el archivo y copia los datos en la lista de Repartos correspondiente del centro logístico recibido
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Repartos para abrir
//  esRepartoAbierto: valor booleano:
//      true = si se quiere abrir un reparto abierto,
//      false = si se quiere abrir un reparto cerrado.
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirListaRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);


///---------------------------------------------------------------------------------------------------------------

/// Apertura general

CentroLogisticoPtr abrirTodoPorDefecto(CentroLogisticoPtr centroLogistico); ///PENDIENTE

//OPERACIÓN: Crea un centro logístico a partir de los datos de un conjunto de archivos de texto.
//PRECONDICIÓN: centroLogistico debe haber sido declarado previamente
//POSTCONDICIÓN: Utiliza a las funciones "abrirLista" para registrar en cada lista del centro logístico
//               el conjunto de datos procedente de una serie de archivos de texto.
/// - ADEMÁS, DEBE HABERSE GUARDADO UNA CENTRO LOGÍSTICO PREVIAMENTE CON GUARDAR TODO,
///     O UTILIZADO TODAS LAS FUNCIONES DE GUARDADO DE LISTAS.
///     VERIFICAR QUE CADA ARCHIVO DEL TIPO "Lista de ... .txt" EXISTA Y TENGA CONTENIDO.
//PARÁMETROS
//      Ninguno
//DEVUELVE: puntero al centro logistico creado si TODO se abrió correctamente,
//  NULL si ocurrió un error EN EL GUARDADO DE ALGUNO DE LOS DATOS.
CentroLogisticoPtr abrirTodo();



///*************************************************************************************************************


///                                         Especiales - Ayudantes

//OPERACION: Función para leer líneas de texto terminadas con un caracter especial
//PRECONDICIÓN:
//      - la variable archivo debe haberse definido previamente.
//      - la variable buffer debe haberse definido previamente con un tamaño recomendado de 100 caracteres
//      - debe existir un archivo de texto con una serie de palabras o frases terminadas de una forma específica
//      - se debe conocer la longitud máxima del archivo en caracteres
//POSTCONDICIÓN: se lee el contenido del archivo y se almacena en el buffer
//PARÁMETROS
//  archivo: variable puntero a FILE requerida para abrir y leer del archivo
//  buffer: variabe string en la cual almacenar los datos leídos
//  longitudMax: entero representando la longitud máxima de caracreres que se espera leer
//  terminador: variable char representando el caracter que termina cada palabra o frase
//      (suele ser un punto, coma o un fin de línea, '\n'. Chequear del archivo de texto)
//DEVUELVE: entero representando la cantidad de caracteres leídos,
//          o EOF si se llegó al final del archivo antes de llegar a leer la longitudMax.
int LeerString(FILE *archivo,char *buffer, int longitudMax, char terminador);


#endif // FILES_H_INCLUDED

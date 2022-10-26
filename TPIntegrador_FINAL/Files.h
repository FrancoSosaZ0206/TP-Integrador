#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "TDACentroLogistico.h"

typedef struct fCuil //a este ya lo definimos como nos dijo el profe. Despues cambio el que utilizamos siempre.
{
    char cuil[15]; //un CUIL con espacios entre cada campo ocuparía 13 espacios, pero le damos un poco de
} fCuil; //espacio extra por las dudas.
typedef fCuil* fCuilPtr;

typedef struct fDomicilio
{
    char calle[50];
    int altura;
    char localidad[50];
} fDomicilio;
typedef fDomicilio* fDomicilioPtr;

typedef struct fFecha
{
    int diaJuliano;
    int hora;
    int minuto;
} fFecha;
typedef fFecha* fFechaPtr;

typedef struct fPersona
{
    char nombre[50];
    char apellido[50];
    fDomicilio domicilio; ///Ojo:
    fCuil cuil; ///las estructuras tampoco pueden ser punteros!!!
    bool esChofer;
    bool RepartoDiario;
} fPersona; //Lo único que pasamos como puntero es la estructura dentro del campo de fwrite o fread
typedef fPersona* fPersonaPtr;

typedef struct fPaquete
{
    int ID;
    int ancho;
    int alto;
    int largo;
    int peso;
    fDomicilio dirRetiro;
    fDomicilio dirEntrega;
    fFecha fechaEntrega;
    fPersona cliente;
    int estado; ///0=En depósito,1=En curso,2=Retirado,3=Entregado,4=Demorado,5=Suspendido
} fPaquete;
typedef fPaquete* fPaquetePtr;

typedef struct fVehiculo
{
    int tipo;
    char marca[50];
    char modelo[50];
    char patente[15];
} fVehiculo;
typedef fVehiculo* fVehiculoPtr;

typedef struct fReparto
{
    fPersona chofer;
    fVehiculo vehiculo;
    fFecha fechaSalida;
    fFecha fechaRetorno;
    int tamanioPilaPaq; ///la dimension del array...
    fPaquete paquetes[20]; ///depende de la longitud de la pila que me pasan
} fReparto;
typedef fReparto* fRepartoPtr;

/**
****************************************************************************************************************
                                                INTERFAZ DE ARCHIVOS
****************************************************************************************************************/

///                                                 OPERACIONES


/// //////////////////////////////////////////////////////////////////////////////////////////////////////// ///
///                                                  ESCRITURA
/// //////////////////////////////////////////////////////////////////////////////////////////////////////// ///


//OPERACIÓN: guarda una lista de Personas en un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico y cargado con una
//              lista de Personas
//POSTCONDICIÓN: Extrae la lista de Personas y las registra una por una dentro de un archivo de texto
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Personas para guardar
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarPersonas(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: guarda una lista de Paquetes en un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico y cargado con una
//              lista de Paquetes
//POSTCONDICIÓN: Extrae la lista de Paquetes y los registra uno por uno dentro de un archivo de texto
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Paquetes para guardar
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarPaquetes(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: guarda una lista de Vehiculos en un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico y cargado con una
//              lista de Vehiculos
//POSTCONDICIÓN: Extrae la lista de Vehiculos y los registra uno por uno dentro de un archivo de texto
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Vehiculos para guardar
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarVehiculos(CentroLogisticoPtr centroLogistico);
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
bool guardarRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);


///---------------------------------------------------------------------------------------------------------------

/// Guardado general

//OPERACIÓN: guarda un centro logístico en un conjunto de archivos de texto.
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico previamente
//POSTCONDICIÓN: Utiliza a las funciones "guardar" para registrar el conjunto de datos procedente del
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


//OPERACIÓN: Recupera una lista de Personas de un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico,
//              y su lista de Personas debe estar vacía
/// - ADEMÁS, DEBE HABERSE GUARDADO UNA LISTA DE PersonaS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de Personas.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Abre el archivo y copia los datos en la lista de Personas del centro logístico recibido
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Personas para guardar
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirPersonas(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: Recupera una lista de Paquete de un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico,
//              y su lista de Paquetes debe estar vacía
/// - ADEMÁS, DEBE HABERSE GUARDADO UNA LISTA DE PaqueteS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de Paquetes.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Abre el archivo y copia los datos en la lista de Paquetes del centro logístico recibido
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Paquetes para guardar
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirPaquetes(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: Recupera una lista de Vehiculos de un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico,
//              y su lista de Vehiculos debe estar vacía
/// - ADEMÁS, DEBE HABERSE GUARDADO UNA LISTA DE VehiculoS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de Vehiculos.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Abre el archivo y copia los datos en la lista de Vehiculos del centro logístico recibido
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Vehiculos para guardar
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirVehiculos(CentroLogisticoPtr centroLogistico);
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
bool abrirRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);


///---------------------------------------------------------------------------------------------------------------

/// Apertura general

//OPERACIÓN: Crea un centro logístico a partir de los datos de un conjunto de archivos de texto.
//PRECONDICIÓN: centroLogistico debe haber sido declarado previamente
//POSTCONDICIÓN: Utiliza a las funciones "abrir" para registrar en cada lista del centro logístico
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


///-----------------------------------------------------------------------------------------------------------///
                    ///SECCION DE FUNCIONES ASISTENTES PARA GUARDAR Y LEER ARCHIVOS///
                        ///PASAJES DE MEMORIA ESTATICA A MEMORIA DINAMICA///
                        ///PASAJES DE MEMORIA DINAMICA A MEMORIA ESTATICA///
///-----------------------------------------------------------------------------------------------------------///


///-----------------------------------------------------------------------------------------------------------///
                            ///SECCION DE FUNCIONES DE CREACION///
///-----------------------------------------------------------------------------------------------------------///

///OPERACION: CREACION
///PRECONDICION: FECHA EN MEMORIA ESTATICA DEBE POSEER DATOS DENTRO
///POSTCONDICION: DEVUELVE EN MEMORIA DINAMICA LOS DATOS EXTRAIDOS
/// DE LA MEMORIA ESTATICA DE FECHA
///PARAMETROS: PUNTERO A LA ESTRUCTURA ESTATICA DE FECHA
///DEVUELVE: PUNTERO A LA ESTRUCTURA FECHA CREADA EN MEMORIA DINAMICA
FechaPtr crearFechaDirectNuevo(fFechaPtr FechaEstatico);

///OPERACION: CREACION
///PRECONDICION: DOMICILIO EN MEMORIA ESTATICA DEBE POSEER DATOS DENTRO
///POSTCONDICION: DEVUELVE EN MEMORIA DINAMICA LOS DATOS EXTRAIDOS
/// DE LA MEMORIA ESTATICA DE DOMICILIO
///PARAMETROS: PUNTERO A LA ESTRUCTURA ESTATICA DE DOMICILIO
///DEVUELVE: PUNTERO A LA ESTRUCTURA DOMICILIO CREADA EN MEMORIA DINAMICA
DomicilioPtr crearDomicilioNuevo(fDomicilioPtr DomicilioEstatico);

///OPERACION: CREACION
///PRECONDICION: PAQUETE EN MEMORIA ESTATICA DEBE POSEER DATOS DENTRO
///POSTCONDICION: DEVUELVE EN MEMORIA DINAMICA LOS DATOS EXTRAIDOS
/// DE LA MEMORIA ESTATICA DE PAQUETE
///PARAMETROS: PUNTERO A LA ESTRUCTURA ESTATICA DE PAQUETE
///DEVUELVE: PUNTERO A LA ESTRUCTURA PAQUETE CREADA EN MEMORIA DINAMICA
PaquetePtr crearPaqueteDirectNuevo(fPaquetePtr PaqueteEstatico);

///OPERACION: CREACION
///PRECONDICION: PERSONA EN MEMORIA ESTATICA DEBE POSEER DATOS DENTRO
///POSTCONDICION: DEVUELVE EN MEMORIA DINAMICA LOS DATOS EXTRAIDOS
/// DE LA MEMORIA ESTATICA DE PERSONA
///PARAMETROS: PUNTERO A LA ESTRUCTURA ESTATICA DE PERSONA
///DEVUELVE: PUNTERO A LA ESTRUCTURA PERSONA CREADA EN MEMORIA DINAMICA
PersonaPtr crearPersonaDirectNuevo(fPersonaPtr PersonaEstatico);

///OPERACION: CREACION
///PRECONDICION: VEHICULO EN MEMORIA ESTATICA DEBE POSEER DATOS DENTRO
///POSTCONDICION: DEVUELVE EN MEMORIA DINAMICA LOS DATOS EXTRAIDOS
/// DE LA MEMORIA ESTATICA DE VEHICULO
///PARAMETROS: PUNTERO A LA ESTRUCTURA ESTATICA DE VEHICULO
///DEVUELVE: PUNTERO A LA ESTRUCTURA VEHICULO CREADA EN MEMORIA DINAMICA
VehiculoPtr crearVehiculoDirectNuevo(fVehiculoPtr VehiculoEstatico);

///OPERACION: CREACION
///PRECONDICION: REPARTO EN MEMORIA ESTATICA DEBE POSEER DATOS DENTRO
///POSTCONDICION: DEVUELVE EN MEMORIA DINAMICA LOS DATOS EXTRAIDOS
/// DE LA MEMORIA ESTATICA DE REPARTO
///PARAMETROS: PUNTERO A LA ESTRUCTURA ESTATICA DE REPARTO
///DEVUELVE: PUNTERO A LA ESTRUCTURA REPARTO CREADA EN MEMORIA DINAMICA
RepartoPtr crearRepartoDirectoNuevo(fRepartoPtr RepartoEstatico);


///-----------------------------------------------------------------------------------------------------------///
                        ///SECCION DE FUNCIONES DE COPIA DE DATOS///
///-----------------------------------------------------------------------------------------------------------///

///OPERACION: COPIA DE DATOS
///PRECONDICION: QUE FECHA EN MEMORIA ESTATICA HAYA SIDO DECLARADA
/// QUE FECHA EN MEMORIA DINAMICA HAYA SIDO DECALARADA
///POSTCONDICION:
///1. COPIA LOS DATOS DE MEMORIA ESTATICA DE FECHA A MEMORIA DINAMICA DE FECHA
///2. COPIA LOS DATOS DE MEMORIA DINAMICA DE FECHA A MEMORIA ESTATICA DE FECHA
///PARAMETROS:
///1. PUNTERO A LA ESTRUCTURA ESTATICA DE FECHA
///2. PUNTERO A LA ESTRUCTURA DINAMICA DE FECHA
///3. IDENTIFICADOR SI LA COPIA DE DATOS ES
///                 TRUE = A MEMORIA DINAMICA
///                 FALSE = A MEMORIA ESTATICA
///DEVUELVE: PUNTERO A LA ESTRUCTURA FECHA CREADA EN MEMORIA DINAMICA
FechaPtr PasajeFechaDinamico(fFechaPtr FechaEstatico, FechaPtr FechaDinamica, bool ADinamico);

///OPERACION: COPIA DE DATOS
///PRECONDICION: QUE DOMICILIO EN MEMORIA ESTATICA HAYA SIDO DECLARADA
/// QUE DOMICILIO EN MEMORIA DINAMICA HAYA SIDO DECALARADA
///POSTCONDICION:
///1. COPIA LOS DATOS DE MEMORIA ESTATICA DE DOMICILIO A MEMORIA DINAMICA DE DOMICILIO
///2. COPIA LOS DATOS DE MEMORIA DINAMICA DE DOMICILIO A MEMORIA ESTATICA DE DOMICILIO
///PARAMETROS:
///1. PUNTERO A LA ESTRUCTURA ESTATICA DE DOMICILIO
///2. PUNTERO A LA ESTRUCTURA DINAMICA DE DOMICILIO
///3. IDENTIFICADOR SI LA COPIA DE DATOS ES
///                 TRUE = A MEMORIA DINAMICA
///                 FALSE = A MEMORIA ESTATICA
///DEVUELVE: PUNTERO A LA ESTRUCTURA DOMICILIO CREADA EN MEMORIA DINAMICA
DomicilioPtr PasajeDomicilioDinamico(fDomicilioPtr DomicilioEstatico, DomicilioPtr DomicilioDinamico, bool ADinamico);

///OPERACION: COPIA DE DATOS
///PRECONDICION: QUE CUIL EN MEMORIA ESTATICA HAYA SIDO DECLARADA
/// QUE CUIL EN MEMORIA DINAMICA HAYA SIDO DECALARADA
///POSTCONDICION:
///1. COPIA LOS DATOS DE MEMORIA ESTATICA DE CUIL A MEMORIA DINAMICA DE CUIL
///2. COPIA LOS DATOS DE MEMORIA DINAMICA DE CUIL A MEMORIA ESTATICA DE CUIL
///PARAMETROS:
///1. PUNTERO A LA ESTRUCTURA ESTATICA DE CUIL
///2. PUNTERO A LA ESTRUCTURA DINAMICA DE CUIL
///3. IDENTIFICADOR SI LA COPIA DE DATOS ES
///                 TRUE = A MEMORIA DINAMICA
///                 FALSE = A MEMORIA ESTATICA
///DEVUELVE: PUNTERO A LA ESTRUCTURA CUIL CREADA EN MEMORIA DINAMICA
CuilPtr PasajeCuilDinamico(fCuilPtr CuilEstatico, CuilPtr CuilDinamico, bool ADinamico);

///OPERACION: COPIA DE DATOS
///PRECONDICION: QUE VEHICULO EN MEMORIA ESTATICA HAYA SIDO DECLARADA
/// QUE VEHICULO EN MEMORIA DINAMICA HAYA SIDO DECALARADA
///POSTCONDICION:
///1. COPIA LOS DATOS DE MEMORIA ESTATICA DE VEHICULO A MEMORIA DINAMICA DE VEHICULO
///2. COPIA LOS DATOS DE MEMORIA DINAMICA DE VEHICULO A MEMORIA ESTATICA DE VEHICULO
///PARAMETROS:
///1. PUNTERO A LA ESTRUCTURA ESTATICA DE VEHICULO
///2. PUNTERO A LA ESTRUCTURA DINAMICA DE VEHICULO
///3. IDENTIFICADOR SI LA COPIA DE DATOS ES
///                 TRUE = A MEMORIA DINAMICA
///                 FALSE = A MEMORIA ESTATICA
///DEVUELVE: PUNTERO A LA ESTRUCTURA VEHICULO CREADA EN MEMORIA DINAMICA
VehiculoPtr PasajeVehiculoDinamico(fVehiculoPtr VehiculoEstatico, VehiculoPtr VehiculoDinamico, bool ADinamico);

///OPERACION: COPIA DE DATOS
///PRECONDICION: QUE PERSONA EN MEMORIA ESTATICA HAYA SIDO DECLARADA
/// QUE PERSONA EN MEMORIA DINAMICA HAYA SIDO DECALARADA
///POSTCONDICION:
///1. COPIA LOS DATOS DE MEMORIA ESTATICA DE PERSONA A MEMORIA DINAMICA DE PERSONA
///2. COPIA LOS DATOS DE MEMORIA DINAMICA DE PERSONA A MEMORIA ESTATICA DE PERSONA
///PARAMETROS:
///1. PUNTERO A LA ESTRUCTURA ESTATICA DE PERSONA
///2. PUNTERO A LA ESTRUCTURA DINAMICA DE PERSONA
///3. IDENTIFICADOR SI LA COPIA DE DATOS ES
///                 TRUE = A MEMORIA DINAMICA
///                 FALSE = A MEMORIA ESTATICA
///DEVUELVE: PUNTERO A LA ESTRUCTURA PERSONA CREADA EN MEMORIA DINAMICA
PersonaPtr PasajePersonaDinamico(fPersonaPtr PersonaEstatico, PersonaPtr PersonaDinamico, bool ADinamico);

///OPERACION: COPIA DE DATOS
///PRECONDICION: QUE PAQUETE EN MEMORIA ESTATICA HAYA SIDO DECLARADA
/// QUE PAQUETE EN MEMORIA DINAMICA HAYA SIDO DECALARADA
///POSTCONDICION:
///1. COPIA LOS DATOS DE MEMORIA ESTATICA DE PAQUETE A MEMORIA DINAMICA DE PAQUETE
///2. COPIA LOS DATOS DE MEMORIA DINAMICA DE PAQUETE A MEMORIA ESTATICA DE PAQUETE
///PARAMETROS:
///1. PUNTERO A LA ESTRUCTURA ESTATICA DE PAQUETE
///2. PUNTERO A LA ESTRUCTURA DINAMICA DE PAQUETE
///3. IDENTIFICADOR SI LA COPIA DE DATOS ES
///                 TRUE = A MEMORIA DINAMICA
///                 FALSE = A MEMORIA ESTATICA
///DEVUELVE: PUNTERO A LA ESTRUCTURA PAQUETE CREADA EN MEMORIA DINAMICA
PaquetePtr PasajePaqueteDinamico(fPaquetePtr PaqueteEstatico, PaquetePtr PaqueteDinamico, bool ADinamico);

///OPERACION: COPIA DE DATOS
///PRECONDICION: QUE REPARTO EN MEMORIA ESTATICA HAYA SIDO DECLARADA
/// QUE REPARTO EN MEMORIA DINAMICA HAYA SIDO DECALARADA
///POSTCONDICION:
///1. COPIA LOS DATOS DE MEMORIA ESTATICA DE REPARTO A MEMORIA DINAMICA DE REPARTO
///2. COPIA LOS DATOS DE MEMORIA DINAMICA DE REPARTO A MEMORIA ESTATICA DE REPARTO
///PARAMETROS:
///1. PUNTERO A LA ESTRUCTURA ESTATICA DE REPARTO
///2. PUNTERO A LA ESTRUCTURA DINAMICA DE REPARTO
///3. IDENTIFICADOR SI LA COPIA DE DATOS ES
///                 TRUE = A MEMORIA DINAMICA
///                 FALSE = A MEMORIA ESTATICA
///DEVUELVE: PUNTERO A LA ESTRUCTURA REPARTO CREADA EN MEMORIA DINAMICA
RepartoPtr PasajeRepartoDinamico(fRepartoPtr RepartoEstatico, RepartoPtr RepartoDinamico, bool ADinamico);


#endif // FILES_H_INCLUDED

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

/// Para datos individuales
//  Se pueden pensar como un portapapeles.

//OPERACIÓN: Guarda un AAA en un archivo dedicado
//PRECONDICIÓN: La variable AAAPtr que se pase deberá haber sido creada previamente con crearA.
//POSTCONDICIÓN: se copian los contenidos de la estructura AAAPtr en una estructura estática interna "fAAA",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS
//  Puntero a la estructura AAA dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarCuil(CuilPtr cuil);
//OPERACIÓN: Guarda un BBB en un archivo dedicado
//PRECONDICIÓN: La variable BBBPtr que se pase deberá haber sido creada previamente con crearB.
//POSTCONDICIÓN: se copian los contenidos de la estructura BBBPtr en una estructura estática interna "fBBB",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS
//  Puntero a la estructura BBB dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarDomicilio(DomicilioPtr domicilio);
//OPERACIÓN: Guarda una CCC en un archivo dedicado
//PRECONDICIÓN: La variable CCCPtr que se pase deberá haber sido creada previamente con crearCCC.
//POSTCONDICIÓN: se copian los contenidos de la estructura CCCPtr en una estructura estática interna "fCCC",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS
//  Puntero a la estructura CCC dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarFecha(FechaPtr fecha);
//OPERACIÓN: Guarda una DDD en un archivo dedicado
//PRECONDICIÓN: La variable DDDPtr que se pase deberá haber sido creada previamente con crearDDD.
//POSTCONDICIÓN: se copian los contenidos de la estructura DDDPtr en una estructura estática interna "fDDD",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS
//  Puntero a la estructura DDD dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarPersona(PersonaPtr persona);
//OPERACIÓN: Guarda una EEE en un archivo dedicado
//PRECONDICIÓN: La variable EEEPtr que se pase deberá haber sido creada previamente con crearEEE.
//POSTCONDICIÓN: se copian los contenidos de la estructura EEEPtr en una estructura estática interna "fEEE",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS
//  Puntero a la estructura EEE dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarPaquete(PaquetePtr paquete);
//OPERACIÓN: Guarda una FFF en un archivo dedicado
//PRECONDICIÓN: La variable FFFPtr que se pase deberá haber sido creada previamente con crearFFF.
//POSTCONDICIÓN: se copian los contenidos de la estructura FFFPtr en una estructura estática interna "fFFF",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS
//  Puntero a la estructura FFF dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarVehiculo(VehiculoPtr vehiculo);
//OPERACIÓN: Guarda una GGG en un archivo dedicado
//PRECONDICIÓN: La variable GGGPtr que se pase deberá haber sido creada previamente con crearGGG.
//POSTCONDICIÓN: se copian los contenidos de la estructura GGGPtr en una estructura estática interna "fGGG",
//               la cual se guarda posteriormente en un archivo de texto (.txt).
//PARÁMETROS
//  Puntero a la estructura GGG dinámica
//DEVUELVE: true si se pudo guardar, false de lo contrario (if archivo == NULL)
bool guardarReparto(RepartoPtr reparto);


///---------------------------------------------------------------------------------------------------------------

/// Para conjuntos de datos - Para guardar bases de datos de structs por defecto.
//  Dedicadas a las funciones de creación de datos por defecto de test.h.

//OPERACIÓN: Guarda un conjunto de AAAs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//  cuils: PUNTERO A PUNTERO A la estructura AAA (Doble puntero). Se puede pensar como un vector de AAAs
//  cantidad: entero representando la cantidad de AAAs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarCuils(CuilPtr *cuils,int cantidad);
//OPERACIÓN: Guarda un conjunto de BBBs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//  cuils: PUNTERO A PUNTERO A la estructura BBB (Doble puntero). Se puede pensar como un vector de BBBs
//  cantidad: entero representando la cantidad de BBBs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarDomicilios(DomicilioPtr *domicilios,int cantidad);
//OPERACIÓN: Guarda un conjunto de CCCs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//  cuils: PUNTERO A PUNTERO A la estructura CCC (Doble puntero). Se puede pensar como un vector de CCCs
//  cantidad: entero representando la cantidad de CCCs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarFechas(FechaPtr *fechas,int cantidad);
//OPERACIÓN: Guarda un conjunto de DDDs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//  cuils: PUNTERO A PUNTERO A la estructura DDD (Doble puntero). Se puede pensar como un vector de DDDs
//  cantidad: entero representando la cantidad de DDDs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarPersonas(PersonaPtr *personas,int cantidad);
//OPERACIÓN: Guarda un conjunto de EEEs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//  cuils: PUNTERO A PUNTERO A la estructura EEE (Doble puntero). Se puede pensar como un vector de EEEs
//  cantidad: entero representando la cantidad de EEEs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarPaquetes(PaquetePtr *paquetes,int cantidad);
//OPERACIÓN: Guarda un conjunto de FFFs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//  cuils: PUNTERO A PUNTERO A la estructura FFF (Doble puntero). Se puede pensar como un vector de FFFs
//  cantidad: entero representando la cantidad de FFFs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarVehiculos(VehiculoPtr *vehiculos,int cantidad);
//OPERACIÓN: Guarda un conjunto de GGGs
//PRECONDICIÓN: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICIÓN: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PARÁMETROS
//  cuils: PUNTERO A PUNTERO A la estructura GGG (Doble puntero). Se puede pensar como un vector de GGGs
//  cantidad: entero representando la cantidad de GGGs a guardar.
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarRepartos(RepartoPtr *repartos,int cantidad);


///---------------------------------------------------------------------------------------------------------------

/// Para listas de datos - Centro Logístico


//OPERACIÓN: guarda una lista de DDDs en un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico y cargado con una
//              lista de DDDs
//POSTCONDICIÓN: Extrae la lista de DDDs y las registra una por una dentro de un archivo de texto
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de DDDs para guardar
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarListaPersonas(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: guarda una lista de EEEs en un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico y cargado con una
//              lista de EEEs
//POSTCONDICIÓN: Extrae la lista de EEEs y los registra uno por uno dentro de un archivo de texto
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de EEEs para guardar
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarListaPaquetes(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: guarda una lista de FFFs en un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico y cargado con una
//              lista de FFFs
//POSTCONDICIÓN: Extrae la lista de FFFs y los registra uno por uno dentro de un archivo de texto
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de FFFs para guardar
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarListaVehiculos(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: guarda una lista de GGGs en un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico y cargado con una
//              lista de GGGs
//POSTCONDICIÓN: Extrae la lista de GGGs y los registra uno por uno dentro de un archivo de texto
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de GGGs para guardar
//DEVUELVE: verdadero si se guardó correctamente, falso si ocurrió un error
bool guardarListaRepartos(CentroLogisticoPtr centroLogistico);


///---------------------------------------------------------------------------------------------------------------

/// Guardado general


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


/// Para datos individuales
//  Se pueden pensar como un portapapeles.


//OPERACIÓN: recupera los datos de una estructura AAA desde un archivo de texto
//PRECONDICIÓN: La variable AAA recibida debe haber sido definida previamente,
//              y su contenido vaciado con su función destructora.
/// - ADEMÁS, DEBE HABERSE GUARDADO UN CONJUNTO DE AAA PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "AAA.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: se llena la estructura AAA con los contenidos del archivo de texto
//PARÁMETROS
//  AAA: puntero a la estructura AAA en la que se quiere cargar datos
//DEVUELVE: true si se pudo abrir, false de lo contrario (if archivo == NULL)
bool abrirCuil(CuilPtr cuil);
//OPERACIÓN: recupera los datos de una estructura BBB desde un archivo de texto
//PRECONDICIÓN: La variable BBB recibida debe haber sido definida previamente,
//              y su contenido vaciado con su función destructora.
/// - ADEMÁS, DEBE HABERSE GUARDADO UN CONJUNTO DE BBB PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "BBB.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: se llena la estructura BBB con los contenidos del archivo de texto
//PARÁMETROS
//  BBB: puntero a la estructura BBB en la que se quiere cargar datos
//DEVUELVE: true si se pudo abrir, false de lo contrario (if archivo == NULL)
bool abrirDomicilio(DomicilioPtr domicilio);
//OPERACIÓN: recupera los datos de una estructura CCC desde un archivo de texto
//PRECONDICIÓN: La variable CCC recibida debe haber sido definida previamente,
//              y su contenido vaciado con su función destructora.
/// - ADEMÁS, DEBE HABERSE GUARDADO UN CONJUNTO DE CCC PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "CCC.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: se llena la estructura CCC con los contenidos del archivo de texto
//PARÁMETROS
//  CCC: puntero a la estructura CCC en la que se quiere cargar datos
//DEVUELVE: true si se pudo abrir, false de lo contrario (if archivo == NULL)
bool abrirFecha(FechaPtr fecha);
//OPERACIÓN: recupera los datos de una estructura DDD desde un archivo de texto
//PRECONDICIÓN: La variable DDD recibida debe haber sido definida previamente,
//              y su contenido vaciado con su función destructora.
/// - ADEMÁS, DEBE HABERSE GUARDADO UN CONJUNTO DE DDD PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "DDD.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: se llena la estructura DDD con los contenidos del archivo de texto
//PARÁMETROS
//  DDD: puntero a la estructura DDD en la que se quiere cargar datos
//DEVUELVE: true si se pudo abrir, false de lo contrario (if archivo == NULL)
bool abrirPersona(PersonaPtr persona);
//OPERACIÓN: recupera los datos de una estructura EEE desde un archivo de texto
//PRECONDICIÓN: La variable EEE recibida debe haber sido definida previamente,
//              y su contenido vaciado con su función destructora.
/// - ADEMÁS, DEBE HABERSE GUARDADO UN CONJUNTO DE EEE PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "EEE.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: se llena la estructura EEE con los contenidos del archivo de texto
//PARÁMETROS
//  EEE: puntero a la estructura EEE en la que se quiere cargar datos
//DEVUELVE: true si se pudo abrir, false de lo contrario (if archivo == NULL)
bool abrirPaquete(PaquetePtr paquete);
//OPERACIÓN: recupera los datos de una estructura FFF desde un archivo de texto
//PRECONDICIÓN: La variable FFF recibida debe haber sido definida previamente,
//              y su contenido vaciado con su función destructora.
/// - ADEMÁS, DEBE HABERSE GUARDADO UN CONJUNTO DE FFF PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "FFF.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: se llena la estructura FFF con los contenidos del archivo de texto
//PARÁMETROS
//  FFF: puntero a la estructura FFF en la que se quiere cargar datos
//DEVUELVE: true si se pudo abrir, false de lo contrario (if archivo == NULL)
bool abrirVehiculo(VehiculoPtr vehiculo);
//OPERACIÓN: recupera los datos de una estructura GGG desde un archivo de texto
//PRECONDICIÓN: La variable GGG recibida debe haber sido definida previamente,
//              y su contenido vaciado con su función destructora.
/// - ADEMÁS, DEBE HABERSE GUARDADO UN CONJUNTO DE GGG PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "GGG.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: se llena la estructura GGG con los contenidos del archivo de texto
//PARÁMETROS
//  GGG: puntero a la estructura GGG en la que se quiere cargar datos
//DEVUELVE: true si se pudo abrir, false de lo contrario (if archivo == NULL)
bool abrirReparto(RepartoPtr reparto);


///---------------------------------------------------------------------------------------------------------------

/// Para conjuntos de datos - Para abrir bases de datos de structs por defecto.
//  Dedicadas a las funciones de creación de datos por defecto de test.h.

//OPERACIÓN: Recupera los datos de un conjunto de AAAs de un archivo de texto
//PRECONDICIÓN:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva función destructora.
/// - ADEMÁS, DEBEN HABERSE GUARDADO UN CONJUNTO DE AAAS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "AAAs por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Copia dentro del conjunto de AAAs los datos almacenados en un archivo de texto.
//PARÁMETROS
//  cuils: PUNTERO A PUNTERO A la estructura AAA (Doble puntero). Se puede pensar como un vector de AAAs
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirCuils(CuilPtr *cuils);
//OPERACIÓN: Recupera los datos de un conjunto de BBBs de un archivo de texto
//PRECONDICIÓN:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva función destructora.
/// - ADEMÁS, DEBEN HABERSE GUARDADO UN CONJUNTO DE BBBS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "BBBs por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Copia dentro del conjunto de BBBs los datos almacenados en un archivo de texto.
//PARÁMETROS
//  BBBs: PUNTERO A PUNTERO A la estructura BBB (Doble puntero). Se puede pensar como un vector de BBBs
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirDomicilios(DomicilioPtr *domicilios);
//OPERACIÓN: Recupera los datos de un conjunto de CCCs de un archivo de texto
//PRECONDICIÓN:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva función destructora.
/// - ADEMÁS, DEBEN HABERSE GUARDADO UN CONJUNTO DE CCCS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "CCCs por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Copia dentro del conjunto de CCCs los datos almacenados en un archivo de texto.
//PARÁMETROS
//  CCCs: PUNTERO A PUNTERO A la estructura CCC (Doble puntero). Se puede pensar como un vector de CCCs
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirFechas(FechaPtr *fechas);
//OPERACIÓN: Recupera los datos de un conjunto de DDDs de un archivo de texto
//PRECONDICIÓN:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva función destructora.
/// - ADEMÁS, DEBEN HABERSE GUARDADO UN CONJUNTO DE DDDS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "DDDs por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Copia dentro del conjunto de DDDs los datos almacenados en un archivo de texto.
//PARÁMETROS
//  DDDs: PUNTERO A PUNTERO A la estructura DDD (Doble puntero). Se puede pensar como un vector de DDDs
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirPersonas(PersonaPtr *personas);
//OPERACIÓN: Recupera los datos de un conjunto de EEEs de un archivo de texto
//PRECONDICIÓN:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva función destructora.
/// - ADEMÁS, DEBEN HABERSE GUARDADO UN CONJUNTO DE AAAS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "EEEs por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Copia dentro del conjunto de EEEs los datos almacenados en un archivo de texto.
//PARÁMETROS
//  EEEs: PUNTERO A PUNTERO A la estructura EEE (Doble puntero). Se puede pensar como un vector de EEEs
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirPaquetes(PaquetePtr *paquetes);
//OPERACIÓN: Recupera los datos de un conjunto de FFFs de un archivo de texto
//PRECONDICIÓN:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva función destructora.
/// - ADEMÁS, DEBEN HABERSE GUARDADO UN CONJUNTO DE FFFS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "FFFs por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Copia dentro del conjunto de FFFs los datos almacenados en un archivo de texto.
//PARÁMETROS
//  FFFs: PUNTERO A PUNTERO A la estructura FFF (Doble puntero). Se puede pensar como un vector de FFFs
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirVehiculos(VehiculoPtr *vehiculos);
//OPERACIÓN: Recupera los datos de un conjunto de GGGs de un archivo de texto
//PRECONDICIÓN:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva función destructora.
/// - ADEMÁS, DEBEN HABERSE GUARDADO UN CONJUNTO DE GGGS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "GGG por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Copia dentro del conjunto de GGGs los datos almacenados en un archivo de texto.
//PARÁMETROS
//  GGGs: PUNTERO A PUNTERO A la estructura GGG (Doble puntero). Se puede pensar como un vector de GGGs
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirRepartos(RepartoPtr *repartos);


///---------------------------------------------------------------------------------------------------------------

/// Para listas de datos - Centro Logístico


//OPERACIÓN: Recupera una lista de DDDs de un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico,
//              y su lista de DDDs debe estar vacía
/// - ADEMÁS, DEBE HABERSE GUARDADO UNA LISTA DE DDDS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de DDDs.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Abre el archivo y copia los datos en la lista de DDDs del centro logístico recibido
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de DDDs para guardar
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirListaPersonas(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: Recupera una lista de EEE de un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico,
//              y su lista de EEEs debe estar vacía
/// - ADEMÁS, DEBE HABERSE GUARDADO UNA LISTA DE EEES PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de EEEs.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Abre el archivo y copia los datos en la lista de EEEs del centro logístico recibido
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de EEEs para guardar
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirListaPaquetes(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: Recupera una lista de FFFs de un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico,
//              y su lista de FFFs debe estar vacía
/// - ADEMÁS, DEBE HABERSE GUARDADO UNA LISTA DE FFFS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de FFFs.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Abre el archivo y copia los datos en la lista de FFFs del centro logístico recibido
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de FFFs para guardar
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirListaVehiculos(CentroLogisticoPtr centroLogistico);
//OPERACIÓN: Recupera una lista de GGGs de un archivo de texto
//PRECONDICIÓN: centroLogistico debe haber sido creado con la función crearCentroLogistico,
//              y su lista de GGGs debe estar vacía
/// - ADEMÁS, DEBE HABERSE GUARDADO UNA LISTA DE DDDS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de GGGs.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICIÓN: Abre el archivo y copia los datos en la lista de GGGs del centro logístico recibido
//PARÁMETROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de GGGs para guardar
//DEVUELVE: verdadero si se abrió correctamente, falso si ocurrió un error
bool abrirListaRepartos(CentroLogisticoPtr centroLogistico);


///---------------------------------------------------------------------------------------------------------------

/// Guardado general


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

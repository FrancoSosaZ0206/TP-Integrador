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

//OPERACI�N: Copia un Cuil en un archivo dedicado
//PRECONDICI�N: La variable CuilPtr que se pase deber� haber sido creada previamente con crearA.
//POSTCONDICI�N: se copian los contenidos de la estructura CuilPtr en una estructura est�tica interna "fCuil",
//               la cual se copia posteriormente en un archivo de texto (.txt).
//PAR�METROS
//  Puntero a la estructura Cuil din�mica
//DEVUELVE: true si se pudo copiar, false de lo contrario (if archivo == NULL)
bool copiarCuil(CuilPtr cuil);
//OPERACI�N: Copia un Domicilio en un archivo dedicado
//PRECONDICI�N: La variable DomicilioPtr que se pase deber� haber sido creada previamente con crearB.
//POSTCONDICI�N: se copian los contenidos de la estructura DomicilioPtr en una estructura est�tica interna "fDomicilio",
//               la cual se copia posteriormente en un archivo de texto (.txt).
//PAR�METROS
//  Puntero a la estructura Domicilio din�mica
//DEVUELVE: true si se pudo copiar, false de lo contrario (if archivo == NULL)
bool copiarDomicilio(DomicilioPtr domicilio);
//OPERACI�N: Copia una Fecha en un archivo dedicado
//PRECONDICI�N: La variable FechaPtr que se pase deber� haber sido creada previamente con crearFecha.
//POSTCONDICI�N: se copian los contenidos de la estructura FechaPtr en una estructura est�tica interna "fFecha",
//               la cual se copia posteriormente en un archivo de texto (.txt).
//PAR�METROS
//  Puntero a la estructura Fecha din�mica
//DEVUELVE: true si se pudo copiar, false de lo contrario (if archivo == NULL)
bool copiarFecha(FechaPtr fecha);
//OPERACI�N: Copia una Persona en un archivo dedicado
//PRECONDICI�N: La variable PersonaPtr que se pase deber� haber sido creada previamente con crearPersona.
//POSTCONDICI�N: se copian los contenidos de la estructura PersonaPtr en una estructura est�tica interna "fPersona",
//               la cual se copia posteriormente en un archivo de texto (.txt).
//PAR�METROS
//  Puntero a la estructura Persona din�mica
//DEVUELVE: true si se pudo copiar, false de lo contrario (if archivo == NULL)
bool copiarPersona(PersonaPtr persona);
//OPERACI�N: Copia una Paquete en un archivo dedicado
//PRECONDICI�N: La variable PaquetePtr que se pase deber� haber sido creada previamente con crearPaquete.
//POSTCONDICI�N: se copian los contenidos de la estructura PaquetePtr en una estructura est�tica interna "fPaquete",
//               la cual se copia posteriormente en un archivo de texto (.txt).
//PAR�METROS
//  Puntero a la estructura Paquete din�mica
//DEVUELVE: true si se pudo copiar, false de lo contrario (if archivo == NULL)
bool copiarPaquete(PaquetePtr paquete);
//OPERACI�N: Copia una Vehiculo en un archivo dedicado
//PRECONDICI�N: La variable VehiculoPtr que se pase deber� haber sido creada previamente con crearVehiculo.
//POSTCONDICI�N: se copian los contenidos de la estructura VehiculoPtr en una estructura est�tica interna "fVehiculo",
//               la cual se copia posteriormente en un archivo de texto (.txt).
//PAR�METROS
//  Puntero a la estructura Vehiculo din�mica
//DEVUELVE: true si se pudo copiar, false de lo contrario (if archivo == NULL)
bool copiarVehiculo(VehiculoPtr vehiculo);
//OPERACI�N: Copia una Reparto en un archivo dedicado
//PRECONDICI�N: La variable RepartoPtr que se pase deber� haber sido creada previamente con crearReparto.
//POSTCONDICI�N: se copian los contenidos de la estructura RepartoPtr en una estructura est�tica interna "fReparto",
//               la cual se copia posteriormente en un archivo de texto (.txt).
//PAR�METROS
//  Puntero a la estructura Reparto din�mica
//DEVUELVE: true si se pudo copiar, false de lo contrario (if archivo == NULL)
bool copiarReparto(RepartoPtr reparto);


///---------------------------------------------------------------------------------------------------------------

/// Para conjuntos de datos - Para guardar bases de datos de structs por defecto.
//  Dedicadas a las funciones de creaci�n de datos por defecto de test.h.

//OPERACI�N: Guarda un conjunto de Cuils
//PRECONDICI�N: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICI�N: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PAR�METROS
//  listaCuils: puntero a la lista de cuils por defecto.
//DEVUELVE: verdadero si se guard� correctamente, falso si ocurri� un error
bool guardarCuils(ListaPtr listaCuils);
//OPERACI�N: Guarda un conjunto de Domicilios
//PRECONDICI�N: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICI�N: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PAR�METROS
//  listaDomicilios: puntero a la lista de domicilios por defecto.
//DEVUELVE: verdadero si se guard� correctamente, falso si ocurri� un error
bool guardarDomicilios(ListaPtr listaDomicilios);
//OPERACI�N: Guarda un conjunto de Fechas
//PRECONDICI�N: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICI�N: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PAR�METROS
//  listaFechas: puntero a la lista de fechas por defecto.
//DEVUELVE: verdadero si se guard� correctamente, falso si ocurri� un error
bool guardarFechas(ListaPtr listaFechas);
//OPERACI�N: Guarda un conjunto de Personas
//PRECONDICI�N: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICI�N: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PAR�METROS
//  centroLogistico: puntero al centro logistico donde se encuentran todos los datos por defecto.
//DEVUELVE: verdadero si se guard� correctamente, falso si ocurri� un error
bool guardarPersonas(CentroLogisticoPtr centroLogistico);
//OPERACI�N: Guarda un conjunto de Paquetes
//PRECONDICI�N: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICI�N: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PAR�METROS
//  centroLogistico: puntero al centro logistico donde se encuentran todos los datos por defecto.
//DEVUELVE: verdadero si se guard� correctamente, falso si ocurri� un error
bool guardarPaquetes(CentroLogisticoPtr centroLogistico);
//OPERACI�N: Guarda un conjunto de Vehiculos
//PRECONDICI�N: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICI�N: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PAR�METROS
//  centroLogistico: puntero al centro logistico donde se encuentran todos los datos por defecto.
//DEVUELVE: verdadero si se guard� correctamente, falso si ocurri� un error
bool guardarVehiculos(CentroLogisticoPtr centroLogistico);
//OPERACI�N: Guarda un conjunto de Repartos
//PRECONDICI�N: La estructura debe haber sido creada con su respectiva constructora.
//POSTCONDICI�N: Copia dentro del archivo los datos pasados por medio de un doble puntero y la cantidad enviada
//PAR�METROS
//  centroLogistico: puntero al centro logistico donde se encuentran todos los datos por defecto.
//DEVUELVE: verdadero si se guard� correctamente, falso si ocurri� un error
bool guardarRepartos(CentroLogisticoPtr centroLogistico);


///---------------------------------------------------------------------------------------------------------------

/// Para listas de datos - Centro Log�stico


//OPERACI�N: guarda una lista de Personas en un archivo de texto
//PRECONDICI�N: centroLogistico debe haber sido creado con la funci�n crearCentroLogistico y cargado con una
//              lista de Personas
//POSTCONDICI�N: Extrae la lista de Personas y las registra una por una dentro de un archivo de texto
//PAR�METROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Personas para guardar
//DEVUELVE: verdadero si se guard� correctamente, falso si ocurri� un error
bool guardarListaPersonas(CentroLogisticoPtr centroLogistico);
//OPERACI�N: guarda una lista de Paquetes en un archivo de texto
//PRECONDICI�N: centroLogistico debe haber sido creado con la funci�n crearCentroLogistico y cargado con una
//              lista de Paquetes
//POSTCONDICI�N: Extrae la lista de Paquetes y los registra uno por uno dentro de un archivo de texto
//PAR�METROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Paquetes para guardar
//DEVUELVE: verdadero si se guard� correctamente, falso si ocurri� un error
bool guardarListaPaquetes(CentroLogisticoPtr centroLogistico);
//OPERACI�N: guarda una lista de Vehiculos en un archivo de texto
//PRECONDICI�N: centroLogistico debe haber sido creado con la funci�n crearCentroLogistico y cargado con una
//              lista de Vehiculos
//POSTCONDICI�N: Extrae la lista de Vehiculos y los registra uno por uno dentro de un archivo de texto
//PAR�METROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Vehiculos para guardar
//DEVUELVE: verdadero si se guard� correctamente, falso si ocurri� un error
bool guardarListaVehiculos(CentroLogisticoPtr centroLogistico);
//OPERACI�N: guarda una lista de Repartos Abiertos en un archivo de texto
//PRECONDICI�N: centroLogistico debe haber sido creado con la funci�n crearCentroLogistico y cargado con una
//              lista de Repartos
//POSTCONDICI�N: guarda en el archivo correspondiente seg�n la variable esRepartoAbierto
//          si es true (esRepartoAbierto) se guardar� en un archivo "Lista de Repartos Abiertos.txt"
//          en caso contrario (!esRepartoAbiero) se guardar� en un archivo "Lista de Repartos Cerrados.txt"

//PAR�METROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Repartos para guardar
//  esRepartoAbierto: valor booleano:
//      true = si se quiere guardar un reparto abierto,
//      false = si se quiere guardar un reparto cerrado.
//DEVUELVE: verdadero si se guard� correctamente, falso si ocurri� un error
bool guardarListaRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);


///---------------------------------------------------------------------------------------------------------------

/// Guardado general

bool copiarTodo(CuilPtr cuil,DomicilioPtr domicilio,PaquetePtr paquete,PersonaPtr persona,VehiculoPtr vehiculo,RepartoPtr reparto); ///PENDIENTE
bool guardarTodoPorDefecto(CentroLogisticoPtr centroLogistico); ///PENDIENTE

//OPERACI�N: guarda un centro log�stico en un conjunto de archivos de texto.
//PRECONDICI�N: centroLogistico debe haber sido creado con la funci�n crearCentroLogistico previamente
//POSTCONDICI�N: Utiliza a las funciones "guardarLista" para registrar el conjunto de datos procedente del
//               centro logistico en una serie de archivos de texto.
//PAR�METROS
//      centroLogistico: Puntero a la estructura CentroLogistico a guardar
//DEVUELVE: verdadero si TODO se guard� correctamente,
//  falso si ocurri� un error EN EL GUARDADO DE ALGUNO DE LOS DATOS.
bool guardarTodo(CentroLogisticoPtr centroLogistico); //implementacion: llamar� a las otras funciones de guardado





/// //////////////////////////////////////////////////////////////////////////////////////////////////////// ///
///                                                   LECTURA
//                                 Se reutilizan las estructuras creadas en main.c
/// //////////////////////////////////////////////////////////////////////////////////////////////////////// ///


/// Para datos individuales
//  Se pueden pensar como un portapapeles.


//OPERACI�N: recupera los datos de una estructura Cuil desde un archivo de texto
//PRECONDICI�N: La variable Cuil recibida debe haber sido definida previamente,
//              y su contenido vaciado con su funci�n destructora.
/// - ADEM�S, DEBE HABERSE GUARDADO UN CONJUNTO DE Cuil PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Cuil.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: se llena la estructura Cuil con los contenidos del archivo de texto
//PAR�METROS
//  Cuil: puntero a la estructura Cuil en la que se quiere cargar datos
//DEVUELVE: true si se pudo pegar, false de lo contrario (if archivo == NULL)
bool pegarCuil(CuilPtr cuil);
//OPERACI�N: recupera los datos de una estructura Domicilio desde un archivo de texto
//PRECONDICI�N: La variable Domicilio recibida debe haber sido definida previamente,
//              y su contenido vaciado con su funci�n destructora.
/// - ADEM�S, DEBE HABERSE GUARDADO UN CONJUNTO DE Domicilio PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Domicilio.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: se llena la estructura Domicilio con los contenidos del archivo de texto
//PAR�METROS
//  Domicilio: puntero a la estructura Domicilio en la que se quiere cargar datos
//DEVUELVE: true si se pudo pegar, false de lo contrario (if archivo == NULL)
bool pegarDomicilio(DomicilioPtr domicilio);
//OPERACI�N: recupera los datos de una estructura Fecha desde un archivo de texto
//PRECONDICI�N: La variable Fecha recibida debe haber sido definida previamente,
//              y su contenido vaciado con su funci�n destructora.
/// - ADEM�S, DEBE HABERSE GUARDADO UN CONJUNTO DE Fecha PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Fecha.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: se llena la estructura Fecha con los contenidos del archivo de texto
//PAR�METROS
//  Fecha: puntero a la estructura Fecha en la que se quiere cargar datos
//DEVUELVE: true si se pudo pegar, false de lo contrario (if archivo == NULL)
bool pegarFecha(FechaPtr fecha);
//OPERACI�N: recupera los datos de una estructura Persona desde un archivo de texto
//PRECONDICI�N: La variable Persona recibida debe haber sido definida previamente,
//              y su contenido vaciado con su funci�n destructora.
/// - ADEM�S, DEBE HABERSE GUARDADO UN CONJUNTO DE Persona PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Persona.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: se llena la estructura Persona con los contenidos del archivo de texto
//PAR�METROS
//  Persona: puntero a la estructura Persona en la que se quiere cargar datos
//DEVUELVE: true si se pudo pegar, false de lo contrario (if archivo == NULL)
bool pegarPersona(PersonaPtr persona);
//OPERACI�N: recupera los datos de una estructura Paquete desde un archivo de texto
//PRECONDICI�N: La variable Paquete recibida debe haber sido definida previamente,
//              y su contenido vaciado con su funci�n destructora.
/// - ADEM�S, DEBE HABERSE GUARDADO UN CONJUNTO DE Paquete PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Paquete.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: se llena la estructura Paquete con los contenidos del archivo de texto
//PAR�METROS
//  Paquete: puntero a la estructura Paquete en la que se quiere cargar datos
//DEVUELVE: true si se pudo pegar, false de lo contrario (if archivo == NULL)
bool pegarPaquete(PaquetePtr paquete);
//OPERACI�N: recupera los datos de una estructura Vehiculo desde un archivo de texto
//PRECONDICI�N: La variable Vehiculo recibida debe haber sido definida previamente,
//              y su contenido vaciado con su funci�n destructora.
/// - ADEM�S, DEBE HABERSE GUARDADO UN CONJUNTO DE Vehiculo PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Vehiculo.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: se llena la estructura Vehiculo con los contenidos del archivo de texto
//PAR�METROS
//  Vehiculo: puntero a la estructura Vehiculo en la que se quiere cargar datos
//DEVUELVE: true si se pudo pegar, false de lo contrario (if archivo == NULL)
bool pegarVehiculo(VehiculoPtr vehiculo);
//OPERACI�N: recupera los datos de una estructura Reparto desde un archivo de texto
//PRECONDICI�N: La variable Reparto recibida debe haber sido definida previamente,
//              y su contenido vaciado con su funci�n destructora.
/// - ADEM�S, DEBE HABERSE GUARDADO UN CONJUNTO DE Reparto PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Reparto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: se llena la estructura Reparto con los contenidos del archivo de texto
//PAR�METROS
//  Reparto: puntero a la estructura Reparto en la que se quiere cargar datos
//DEVUELVE: true si se pudo pegar, false de lo contrario (if archivo == NULL)
bool pegarReparto(RepartoPtr reparto);


///---------------------------------------------------------------------------------------------------------------

/// Para conjuntos de datos - Para abrir bases de datos de structs por defecto.
//  Dedicadas a las funciones de creaci�n de datos por defecto de test.h.

//OPERACI�N: Recupera los datos de un conjunto de Cuils de un archivo de texto
//PRECONDICI�N:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva funci�n destructora.
/// - ADEM�S, DEBEN HABERSE GUARDADO UN CONJUNTO DE CuilS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Cuils por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: Copia dentro del conjunto de Cuils los datos almacenados en un archivo de texto.
//PAR�METROS
//  cuils: PUNTERO A PUNTERO A la estructura Cuil (Doble puntero). Se puede pensar como un vector de Cuils
//DEVUELVE: verdadero si se abri� correctamente, falso si ocurri� un error
bool abrirCuils(CuilPtr *cuils);
//OPERACI�N: Recupera los datos de un conjunto de Domicilios de un archivo de texto
//PRECONDICI�N:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva funci�n destructora.
/// - ADEM�S, DEBEN HABERSE GUARDADO UN CONJUNTO DE DomicilioS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Domicilios por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: Copia dentro del conjunto de Domicilios los datos almacenados en un archivo de texto.
//PAR�METROS
//  Domicilios: PUNTERO A PUNTERO A la estructura Domicilio (Doble puntero). Se puede pensar como un vector de Domicilios
//DEVUELVE: verdadero si se abri� correctamente, falso si ocurri� un error
bool abrirDomicilios(DomicilioPtr *domicilios);
//OPERACI�N: Recupera los datos de un conjunto de Fechas de un archivo de texto
//PRECONDICI�N:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva funci�n destructora.
/// - ADEM�S, DEBEN HABERSE GUARDADO UN CONJUNTO DE FechaS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Fechas por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: Copia dentro del conjunto de Fechas los datos almacenados en un archivo de texto.
//PAR�METROS
//  Fechas: PUNTERO A PUNTERO A la estructura Fecha (Doble puntero). Se puede pensar como un vector de Fechas
//DEVUELVE: verdadero si se abri� correctamente, falso si ocurri� un error
bool abrirFechas(FechaPtr *fechas);
//OPERACI�N: Recupera los datos de un conjunto de Personas de un archivo de texto
//PRECONDICI�N:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva funci�n destructora.
/// - ADEM�S, DEBEN HABERSE GUARDADO UN CONJUNTO DE PersonaS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Personas por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: Copia dentro del conjunto de Personas los datos almacenados en un archivo de texto.
//PAR�METROS
//  Personas: PUNTERO A PUNTERO A la estructura Persona (Doble puntero). Se puede pensar como un vector de Personas
//DEVUELVE: verdadero si se abri� correctamente, falso si ocurri� un error
bool abrirPersonas(PersonaPtr *personas);
//OPERACI�N: Recupera los datos de un conjunto de Paquetes de un archivo de texto
//PRECONDICI�N:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva funci�n destructora.
/// - ADEM�S, DEBEN HABERSE GUARDADO UN CONJUNTO DE CuilS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Paquetes por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: Copia dentro del conjunto de Paquetes los datos almacenados en un archivo de texto.
//PAR�METROS
//  Paquetes: PUNTERO A PUNTERO A la estructura Paquete (Doble puntero). Se puede pensar como un vector de Paquetes
//DEVUELVE: verdadero si se abri� correctamente, falso si ocurri� un error
bool abrirPaquetes(PaquetePtr *paquetes);
//OPERACI�N: Recupera los datos de un conjunto de Vehiculos de un archivo de texto
//PRECONDICI�N:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva funci�n destructora.
/// - ADEM�S, DEBEN HABERSE GUARDADO UN CONJUNTO DE VehiculoS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Vehiculos por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: Copia dentro del conjunto de Vehiculos los datos almacenados en un archivo de texto.
//PAR�METROS
//  Vehiculos: PUNTERO A PUNTERO A la estructura Vehiculo (Doble puntero). Se puede pensar como un vector de Vehiculos
//DEVUELVE: verdadero si se abri� correctamente, falso si ocurri� un error
bool abrirVehiculos(VehiculoPtr *vehiculos);
//OPERACI�N: Recupera los datos de un conjunto de Repartos de un archivo de texto
//PRECONDICI�N:
//  - La estructura debe haber sido definida previamente,
//      y su contenido vaciado con su respectiva funci�n destructora.
/// - ADEM�S, DEBEN HABERSE GUARDADO UN CONJUNTO DE RepartoS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Reparto por Defecto.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: Copia dentro del conjunto de Repartos los datos almacenados en un archivo de texto.
//PAR�METROS
//  Repartos: PUNTERO A PUNTERO A la estructura Reparto (Doble puntero). Se puede pensar como un vector de Repartos
//DEVUELVE: verdadero si se abri� correctamente, falso si ocurri� un error
bool abrirRepartos(RepartoPtr *repartos);


///---------------------------------------------------------------------------------------------------------------

/// Para listas de datos - Centro Log�stico


//OPERACI�N: Recupera una lista de Personas de un archivo de texto
//PRECONDICI�N: centroLogistico debe haber sido creado con la funci�n crearCentroLogistico,
//              y su lista de Personas debe estar vac�a
/// - ADEM�S, DEBE HABERSE GUARDADO UNA LISTA DE PersonaS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de Personas.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: Abre el archivo y copia los datos en la lista de Personas del centro log�stico recibido
//PAR�METROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Personas para guardar
//DEVUELVE: verdadero si se abri� correctamente, falso si ocurri� un error
bool abrirListaPersonas(CentroLogisticoPtr centroLogistico);
//OPERACI�N: Recupera una lista de Paquete de un archivo de texto
//PRECONDICI�N: centroLogistico debe haber sido creado con la funci�n crearCentroLogistico,
//              y su lista de Paquetes debe estar vac�a
/// - ADEM�S, DEBE HABERSE GUARDADO UNA LISTA DE PaqueteS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de Paquetes.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: Abre el archivo y copia los datos en la lista de Paquetes del centro log�stico recibido
//PAR�METROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Paquetes para guardar
//DEVUELVE: verdadero si se abri� correctamente, falso si ocurri� un error
bool abrirListaPaquetes(CentroLogisticoPtr centroLogistico);
//OPERACI�N: Recupera una lista de Vehiculos de un archivo de texto
//PRECONDICI�N: centroLogistico debe haber sido creado con la funci�n crearCentroLogistico,
//              y su lista de Vehiculos debe estar vac�a
/// - ADEM�S, DEBE HABERSE GUARDADO UNA LISTA DE VehiculoS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de Vehiculos.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: Abre el archivo y copia los datos en la lista de Vehiculos del centro log�stico recibido
//PAR�METROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Vehiculos para guardar
//DEVUELVE: verdadero si se abri� correctamente, falso si ocurri� un error
bool abrirListaVehiculos(CentroLogisticoPtr centroLogistico);
//OPERACI�N: Recupera una lista de Repartos de un archivo de texto
//PRECONDICI�N: centroLogistico debe haber sido creado con la funci�n crearCentroLogistico,
//              y su lista de Repartos debe estar vac�a
/// - ADEM�S, DEBE HABERSE GUARDADO UNA LISTA DE PersonaS PREVIAMENTE.
///     VERIFICAR QUE EXISTA UN ARCHIVO "Lista de Repartos.txt" Y QUE TENGA CONTENIDO.
//POSTCONDICI�N: Abre el archivo y copia los datos en la lista de Repartos correspondiente del centro log�stico recibido
//PAR�METROS
//  centroLogistico: puntero a la estructura CentroLogistico del que extraer la lista de Repartos para abrir
//  esRepartoAbierto: valor booleano:
//      true = si se quiere abrir un reparto abierto,
//      false = si se quiere abrir un reparto cerrado.
//DEVUELVE: verdadero si se abri� correctamente, falso si ocurri� un error
bool abrirListaRepartos(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto);


///---------------------------------------------------------------------------------------------------------------

/// Apertura general

void pegarTodo(); ///PENDIENTE
CentroLogisticoPtr abrirTodoPorDefecto(CentroLogisticoPtr centroLogistico); ///PENDIENTE

//OPERACI�N: Crea un centro log�stico a partir de los datos de un conjunto de archivos de texto.
//PRECONDICI�N: centroLogistico debe haber sido declarado previamente
//POSTCONDICI�N: Utiliza a las funciones "abrirLista" para registrar en cada lista del centro log�stico
//               el conjunto de datos procedente de una serie de archivos de texto.
/// - ADEM�S, DEBE HABERSE GUARDADO UNA CENTRO LOG�STICO PREVIAMENTE CON GUARDAR TODO,
///     O UTILIZADO TODAS LAS FUNCIONES DE GUARDADO DE LISTAS.
///     VERIFICAR QUE CADA ARCHIVO DEL TIPO "Lista de ... .txt" EXISTA Y TENGA CONTENIDO.
//PAR�METROS
//      Ninguno
//DEVUELVE: puntero al centro logistico creado si TODO se abri� correctamente,
//  NULL si ocurri� un error EN EL GUARDADO DE ALGUNO DE LOS DATOS.
CentroLogisticoPtr abrirTodo();



///*************************************************************************************************************


///                                         Especiales - Ayudantes

//OPERACION: Funci�n para leer l�neas de texto terminadas con un caracter especial
//PRECONDICI�N:
//      - la variable archivo debe haberse definido previamente.
//      - la variable buffer debe haberse definido previamente con un tama�o recomendado de 100 caracteres
//      - debe existir un archivo de texto con una serie de palabras o frases terminadas de una forma espec�fica
//      - se debe conocer la longitud m�xima del archivo en caracteres
//POSTCONDICI�N: se lee el contenido del archivo y se almacena en el buffer
//PAR�METROS
//  archivo: variable puntero a FILE requerida para abrir y leer del archivo
//  buffer: variabe string en la cual almacenar los datos le�dos
//  longitudMax: entero representando la longitud m�xima de caracreres que se espera leer
//  terminador: variable char representando el caracter que termina cada palabra o frase
//      (suele ser un punto, coma o un fin de l�nea, '\n'. Chequear del archivo de texto)
//DEVUELVE: entero representando la cantidad de caracteres le�dos,
//          o EOF si se lleg� al final del archivo antes de llegar a leer la longitudMax.
int LeerString(FILE *archivo,char *buffer, int longitudMax, char terminador);


#endif // FILES_H_INCLUDED

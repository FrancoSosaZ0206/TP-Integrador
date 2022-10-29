#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TDACentroLogistico.h"
#include "TDAFechaYHora.h"
#include "TDADomicilio.h"
#include "TDAPaquetes.h"
#include "util.h"
#include "Pila.h"
#include "Lista.h"
#include "Files.h"
#include "Menus.h"

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE CREACION///
///-----------------------------------------------------------------------------------------------------------///

PaquetePtr crearPaquete(int ID,int ancho,int alto,int largo,int peso,DomicilioPtr dirRetiro,DomicilioPtr dirEntrega,FechaPtr fechaEntrega,PersonaPtr cliente,int estado)
{
    PaquetePtr paquete=(PaquetePtr)obtenerMemoria(sizeof(Paquete));
    paquete->ID=ID;
    paquete->ancho=ancho;
    paquete->alto=alto;
    paquete->largo=largo;
    paquete->peso=peso;
    paquete->dirRetiro=dirRetiro;
    paquete->dirEntrega=dirEntrega;
    paquete->fechaEntrega=fechaEntrega;
    paquete->cliente=cliente;
    paquete->estado=estado;
    return paquete;
}

PaquetePtr crearPaqueteDirect(int ID,int ancho,int alto,int largo,int peso,char *calleRetiro,int alturaRetiro,char *localidadRetiro,char *calleEntrega,int alturaEntrega,char *localidadEntrega,int dia,int mes,int anio,int hora,int minuto,char* nombre,char* apellido, char* calleCliente, int alturaCliente,char* localidadCliente, char* strCuil, int estado)
{
    PaquetePtr paquete = (PaquetePtr) obtenerMemoria(sizeof(Paquete));
    paquete->ID=ID;
    paquete->ancho=ancho;
    paquete->alto=alto;
    paquete->largo=largo;
    paquete->peso=peso;
    paquete->dirRetiro=crearDomicilio(calleRetiro,alturaRetiro,localidadRetiro);
    paquete->dirEntrega=crearDomicilio(calleEntrega,alturaEntrega,localidadEntrega);
    paquete->fechaEntrega=crearFecha(dia,mes,anio,hora,minuto);
    DomicilioPtr domicilio=crearDomicilio(calleCliente,alturaCliente,localidadCliente);
    CuilPtr cuil=crearCuil(strCuil);
    paquete->cliente=crearPersona(nombre,apellido,domicilio,cuil,false);
    paquete->estado=estado;
    return paquete;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE DESTRUCCION///
///-----------------------------------------------------------------------------------------------------------///

PaquetePtr destruirPaquete(PaquetePtr paquete)
{
    paquete->dirRetiro=destruirDomicilio(paquete->dirRetiro);
    paquete->dirEntrega=destruirDomicilio(paquete->dirEntrega);
    paquete->fechaEntrega=destruirFecha(paquete->fechaEntrega);
    paquete->cliente=destruirPersona(paquete->cliente);
    free(paquete);
    return NULL;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE GETTERS///
///-----------------------------------------------------------------------------------------------------------///

int getID(PaquetePtr paquete)
{
    return paquete->ID;
}

int getAncho(PaquetePtr paquete)
{
    return paquete->ancho;
}

int getAlto(PaquetePtr paquete)
{
    return paquete->alto;
}

int getLargo(PaquetePtr paquete)
{
    return paquete->largo;
}

int getPeso(PaquetePtr paquete)
{
    return paquete->peso;
}

DomicilioPtr getDirRetiro(PaquetePtr paquete)
{
    return paquete->dirRetiro;
}

DomicilioPtr getDirEntrega(PaquetePtr paquete)
{
    return paquete->dirEntrega;
}

FechaPtr getFechaEntrega(PaquetePtr paquete)
{
    return paquete->fechaEntrega;
}

PersonaPtr getCliente(PaquetePtr paquete)
{
    return paquete->cliente;
}

int getEstado(PaquetePtr paquete)
{
    return paquete->estado;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE SETTERS///
///-----------------------------------------------------------------------------------------------------------///

void setID(PaquetePtr paquete,int ID)
{
    paquete->ID=ID;
}

void setAncho(PaquetePtr paquete,int ancho)
{
    paquete->ancho=ancho;
}

void setAlto(PaquetePtr paquete,int alto)
{
    paquete->alto=alto;
}

void setLargo(PaquetePtr paquete,int largo)
{
    paquete->largo=largo;
}

void setPeso(PaquetePtr paquete,int peso)
{
    paquete->peso=peso;
}

void setDirRetiro(PaquetePtr paquete,DomicilioPtr dirRetiro)
{
    paquete->dirRetiro=dirRetiro;
}

void setDirEntrega(PaquetePtr paquete,DomicilioPtr dirEntrega)
{
    paquete->dirEntrega=dirEntrega;
}

void setFechaEntrega(PaquetePtr paquete,FechaPtr fechaEntrega)
{
    paquete->fechaEntrega=fechaEntrega;
}

void setCliente(PaquetePtr paquete, PersonaPtr cliente)
{
    paquete->cliente = cliente;
}

void setEstado(PaquetePtr paquete,int estado)
{
    paquete->estado=estado;
}


///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE OPERACIONES CON PAQUETE///
///-----------------------------------------------------------------------------------------------------------///

void mostrarPaquete(PaquetePtr paquete)
{
    printf("\tID: # %d\n",getID(paquete));
    printf("\tAncho: %d\n",getAncho(paquete));
    printf("\tAlto: %d\n",getAlto(paquete));
    printf("\tLargo: %d\n",getLargo(paquete));
    printf("\tPeso: %d\n",getPeso(paquete));
    printf("\tEstado: ");
    mostrarEstadopaquete(paquete);
    printf("\tDireccion de Retiro: ");
    mostrarDomicilio(getDirRetiro(paquete));
    printf("\tDireccion de Entrega: ");
    mostrarDomicilio(getDirEntrega(paquete));
    printf("\tFECHA DE ENTREGA: ");
    mostrarFecha(getFechaEntrega(paquete));
    printf("\n\tDestinatario: \n");
    mostrarPersona(getCliente(paquete));
    printf("\n\n");
}

///muestra que relacion hay entre cada numero y cada estado posible del paquete.
void helpEstadoPaquete()
{
    printf("Codigo de estados: \n");
    printf("\t0 = En Deposito\n");
    printf("\t1 = En Curso\n");
    printf("\t2 = Retirado\n");
    printf("\t3 = Entregado\n");
    printf("\t4 = Demorado\n");
    printf("\t5 = Suspendido\n\n");
}

///muestra solo el estado actual del paquete recibido.
void mostrarEstadopaquete(PaquetePtr paquete)
{
    switch(getEstado(paquete))
    {
    case 0:
        printf("En Deposito.\n");
        break;
    case 1:
        printf("En Curso.\n");
        break;
    case 2:
        printf("Retirado.\n");
        break;
    case 3:
        printf("Entregado.\n");
        break;
    case 4:
        printf("Demorado.\n");
        break;
    case 5:
        printf("Suspendido.\n");
        break;
    default:
        printf("ERROR.\n");
        break;
    }
}

bool paquetesIguales(PaquetePtr paquete1,PaquetePtr paquete2)
{
    bool matchID,matchResto;
    DomicilioPtr dirRetiro1 = getDirRetiro(paquete1);
    DomicilioPtr dirRetiro2 = getDirRetiro(paquete2);
    DomicilioPtr dirEntrega1 = getDirEntrega(paquete1);
    DomicilioPtr dirEntrega2 = getDirEntrega(paquete2);
    FechaPtr fechaEntrega1 = getFechaEntrega(paquete1);
    FechaPtr fechaEntrega2 = getFechaEntrega(paquete2);
    int difFechas[3];
    calcularDiferenciaFechas(fechaEntrega1,fechaEntrega2,difFechas);
    //primero, se verifica si el ID de paquete1 es igual al del paquete2
    matchID = getID(paquete1) == getID(paquete2);
    //luego, se verifica si las dimensiones de paquete1 son iguales
    matchResto = getAncho(paquete1) == getAncho(paquete2);
    matchResto = matchResto && getAlto(paquete1) == getAlto(paquete2);
    matchResto = matchResto && getLargo(paquete1) == getLargo(paquete2);
    matchResto = matchResto && getPeso(paquete1) == getPeso(paquete2);
    //después, se verifica si las direcciones de retiro de paquete1 coinciden con las del paquete2
    matchResto = matchResto && strcmp(getCalle(dirRetiro1),getCalle(dirRetiro2))==0;
    matchResto = matchResto && getAltura(dirRetiro1) == getAltura(dirRetiro2);
    matchResto = matchResto && strcmp(getLocalidad(dirRetiro1),getLocalidad(dirRetiro2))==0;
    //posteriormente, se verifica si las direcciones de entrega de paquete1 coinciden con las del paquete2
    matchResto = matchResto && strcmp(getCalle(dirEntrega1),getCalle(dirEntrega2))==0;
    matchResto = matchResto && getAltura(dirEntrega1) == getAltura(dirEntrega2);
    matchResto = matchResto && strcmp(getLocalidad(dirEntrega1),getLocalidad(dirEntrega2))==0;
    //finalmente, se chequea la fecha de entrega
    matchResto = matchResto && difFechas[0]==0 && difFechas[1]==0 && difFechas[2]==0;
    //la condicion final será: "si coinciden los ID, o bien el resto de parámetros, o bien todo..."
    return matchID || matchResto;
}


bool menuCargarPaquete(CentroLogisticoPtr centroLogistico)
{
    PaquetePtr paquete;
    ///el ID del paquete se genera automáticamente, no lo tiene que ingresar el usuario.
    int ID = 0;
    int ancho = 0;
    int alto = 0;
    int largo = 0;
    int peso = 0;
    int i = 1;
    int resultado = 0;
    FechaPtr fechaEntrega;
    DomicilioPtr dirRetiro;
    DomicilioPtr dirEntrega;
    PersonaPtr persona;
    ///por defecto, los paquetes se cargan con el estado 0: 'en depósito'.
    srand(time(NULL));
    bool cambiosGuardados = false;
    bool continuar = false;
    if(listaVacia(getPersonas(centroLogistico)))
    {
        printf("No hay destinatarios para elegir\n");
        printf("Ingrese clientes para seleccionar\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            system("cls");
            printf("\n\n\t\t PAQUETE %d. \n\n", i+1);
            i++;

            ///esto no se mostrará sino al final de la carga del paquete.
            ID = longitudLista(getPaquetes(centroLogistico))+1;

            printf("\n\t Ancho: ");
            ancho = seleccionarNumero();

            printf("\n\t Alto: ");
            alto = seleccionarNumero();

            printf("\n\t Largo: ");
            largo = seleccionarNumero();

            printf("\n\t Peso: ");
            peso = seleccionarNumero();

            printf("\n\t Direccion de retiro: ");
            dirRetiro = cargarDomicilio(dirRetiro);

            printf("\n\t Direccion de entrega: ");
            dirEntrega = cargarDomicilio(dirEntrega);

            printf("\n\t Fecha de entrega: ");
            fechaEntrega = cargarFecha(fechaEntrega);

            printf("\n\t Elegir destinatario \n\n");
            persona = menuBusquedaCliente(centroLogistico);

            paquete = crearPaquete(ID,ancho,alto,largo,peso,dirRetiro,dirEntrega,fechaEntrega,persona,0);

            agregarPaquete(centroLogistico,paquete);

            continuar = menuContinuar();

        } while(continuar);

        resultado = menuGuardarCambios();

        if(resultado == 1)
        {
            cambiosGuardados = guardarPaquetes(centroLogistico);
        }
    }
    return cambiosGuardados;
}

bool menuEliminarPaquete(CentroLogisticoPtr centroLogistico)
{
    int opcion = 0;
    bool cambiosGuardados = true;
    bool continuar = true;
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int indices[100];
    int cantIndices = 0;
    PaquetePtr paqueteRemovido;
    do
    {
        if( listaVacia( getPaquetes(centroLogistico) ) )
        {
            printf("ERROR: Lista vacia. Debe agregar paquetes para poder eliminarlos.\n\n");
        }
        else
        {
            EleccionMenuModoAccion = menuModoAccion();
            if(EleccionMenuModoAccion != 0)
            {
                mostrarPaquetes(centroLogistico);
            }
            printf("ELIMINAR PAQUETE\n\n");
            switch(EleccionMenuModoAccion)
            {
            case 1:
                EleccionAccion = menuModoAccion1( getPaquetes(centroLogistico) );
                paqueteRemovido = removerPaquete(centroLogistico, EleccionAccion);
                paqueteRemovido = destruirPaquete(paqueteRemovido);
                cambiosGuardados = false;
                break;
            case 2:
                printf("[ACLARACION]Eliga la cantidad de indices...\n");
                cantIndices = menuModoAccion1( getPaquetes(centroLogistico) );
                menuModoAccion2( getPaquetes(centroLogistico), cantIndices, indices );
                for(int i=0;i<cantIndices+1;i++)
                {
                    paqueteRemovido = removerPaquete(centroLogistico,indices[i]-i);
                    paqueteRemovido = destruirPaquete(paqueteRemovido);
                }
                cambiosGuardados = false;
                break;
            case 3:
                menuModoAccion3( getPaquetes(centroLogistico) , indices );
                for(int i=0;i<indices[1]-indices[0]+1;i++)
                {
                    paqueteRemovido = removerPaquete(centroLogistico,indices[0]);
                    paqueteRemovido = destruirPaquete(paqueteRemovido);
                }
                cambiosGuardados = false;
                break;
            case 0:
                break;
            default:
                printf("Eleccion equivocada \n");
                break;
            }
            if(EleccionMenuModoAccion == 0)
            {
                continuar = false;
            }
            else
            {
                continuar = menuContinuar();
            }
        }
    }while(continuar && !listaVacia( getPaquetes(centroLogistico) ) );
    notificacionListaVacia( getPaquetes(centroLogistico) );
    if( !cambiosGuardados )
    {
        opcion = menuGuardarCambios();
        if(opcion == 1)
        {
            cambiosGuardados = guardarPaquetes(centroLogistico);
        }
    }
    return cambiosGuardados;
}

void cambiarPaquete(CentroLogisticoPtr centroLogistico, PaquetePtr paqueteAModificar)
{
    int nAncho = 0;
    int nAlto = 0;
    int nLargo = 0;
    int nPeso = 0;
    int nEstado = 0;
    int seguirMod = 0;
    int op = 0;
    bool EstadoValido = false;
    do
    {
        system("cls");
        printf("Ha elegido el - \n\n");
        mostrarPaquete(paqueteAModificar);
        printf("\n\n Qué desea modificar? \n\n");
        printf("1. Ancho\n");
        printf("2. Alto\n");
        printf("3. Largo\n");
        printf("4. Peso\n");
        printf("5. Direccion de Retiro\n");
        printf("6. Direccion de Entrega\n");
        printf("7. Fecha de Entrega\n");
        printf("8. Estado\n");
        printf("9. Destinatario\n");
        printf("0. Volver \n");
        printf("Seleccione una opcion: ");
        limpiarBufferTeclado();
        scanf("%d",&op);
        limpiarBufferTeclado();
        printf("\n\n");
        switch(op)
        {
        case 1:
            printf("\n\nIngrese el nuevo ancho: ");
            limpiarBufferTeclado();
            scanf("%d",&nAncho);
            setAncho(paqueteAModificar,nAncho);
            break;
        case 2:
            printf("\n\nIngrese el nuevo alto: ");
            limpiarBufferTeclado();
            scanf("%d",&nAlto);
            setAlto(paqueteAModificar,nAlto);
            break;
        case 3:
            printf("\n\nIngrese el nuevo largo: ");
            limpiarBufferTeclado();
            scanf("%d",&nLargo);
            setLargo(paqueteAModificar,nLargo);
            break;
        case 4:
            printf("\n\nIngrese el nuevo peso: ");
            limpiarBufferTeclado();
            scanf("%d",&nPeso);
            setPeso(paqueteAModificar,nPeso);
            break;
        case 5:
            printf("\n\nIngrese la nueva direccion de retiro:");
            actualizarDomicilio(getDirRetiro(paqueteAModificar));
            break;
        case 6:
            printf("\n\nIngrese la nueva direccion de entrega:");
            actualizarDomicilio(getDirEntrega(paqueteAModificar));
            break;
        case 7:
            printf("\n\nIngrese la nueva fecha y horario de entrega: ");
            actualizarFecha(getFechaEntrega(paqueteAModificar));
            break;
        case 8:
            while(!EstadoValido)
            {
                helpEstadoPaquete();
                printf("\n\nIngrese el nuevo estado: ");
                nEstado = seleccionarNumero();
                if(nEstado >= 0 && nEstado <= 5)
                {
                    EstadoValido = true;
                }
                if(!EstadoValido)
                {
                    printf("\n\n\t [Estado invalido...] \n");
                    printf("\n\t [Estados validos: 0,1,2,3,4,5 ] \n\n");
                    presionarEnterYLimpiarPantalla();
                }
            }
            setEstado(paqueteAModificar, nEstado);
            break;
        case 9:
            cambiarPersona(centroLogistico, getCliente(paqueteAModificar),getEsChofer(getCliente(paqueteAModificar)));
            break;
        case 0:
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }
        if(op == 0)
        {
            seguirMod = 0;
        }
        else
        {
            seguirMod = MenuDeseaSeguirModificando();
        }
    }while(seguirMod!=0);
}

ListaPtr OriginalPaquetes(CentroLogisticoPtr centroLogistico)
{
        ///Creamos una lista "original" para ver si hay cambios,
        ///y una "auxiliar" para obtener y recorrer la lista.
        ListaPtr listaOriginal=crearLista();
        ListaPtr listaAux2=crearLista();
        agregarLista(listaAux2,getPaquetes(centroLogistico));
        ///Hacemos lo mismo pero para cada elemento de la lista
        PaquetePtr paqueteOriginal;
        PaquetePtr paqueteAux;
        while(!listaVacia(listaAux2))
        {
            paqueteAux=getCabecera(listaAux2);
            ///Copiamos el contenido de cada elemento
            paqueteOriginal=crearPaquete(getID(paqueteAux),getAncho(paqueteAux),getAlto(paqueteAux),getLargo(paqueteAux),getPeso(paqueteAux),
                                         getDirRetiro(paqueteAux),getDirEntrega(paqueteAux),getFechaEntrega(paqueteAux),getCliente(paqueteAux),getEstado(paqueteAux));
            ///Agregamos el dato original a la lista
            agregarDatoLista(listaOriginal,(PaquetePtr)paqueteOriginal);
            listaAux2=getResto(listaAux2);
        }
        listaAux2=destruirLista(listaAux2,false);
        return listaOriginal;
}

bool CambiosPaquetes(CentroLogisticoPtr centroLogistico, ListaPtr listaOriginal)
{
    bool cambioDetectado=false;
    ListaPtr listaAux2=crearLista();
    PaquetePtr paqueteAux;
    PaquetePtr paqueteOriginal;
    ListaPtr paquetes = getPaquetes(centroLogistico);
    agregarLista(listaAux2,paquetes);
    ///Recorremos la lista: antes y después de hacer el cambio
    while(!listaVacia(listaAux2))
    {
        paqueteAux=getCabecera(listaAux2);
        paqueteOriginal=getCabecera(listaOriginal);
        ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
        if(!paquetesIguales(paqueteOriginal,paqueteAux))
        {
            cambioDetectado=true;
        }
        listaAux2=getResto(listaAux2);
        listaOriginal=getResto(listaOriginal);
    }
    ///Destruimos ambas listas, ya no las necesitamos más
    listaAux2=destruirLista(listaAux2,false);
    ///Como en esta copiamos los contenidos, ponemos true para removerlos.
    listaOriginal=destruirLista(listaOriginal,true);
    return cambioDetectado;
}

bool menuModificarPaquete(CentroLogisticoPtr centroLogistico)
{
    bool cambiosGuardados = true, continuar;
    int modoAccion, Cantidad, Eleccion, resultado;
    int Elecciones[10];
    PaquetePtr paqueteModificar;
    if(listaVacia(getPaquetes(centroLogistico)))
    {
        printf("ERROR: Lista vacía. Debe agregar paquetes para poder modificarlos.\n\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            modoAccion = menuModoAccion();
            if(modoAccion != 0)
            {
                mostrarPaquetes(centroLogistico);
            }
            switch(modoAccion)
            {
            case 1:
                Eleccion=menuModoAccion1(getPaquetes(centroLogistico));
                paqueteModificar=getDatoLista(getPaquetes(centroLogistico),Eleccion);
                cambiarPaquete(centroLogistico, paqueteModificar);
                cambiosGuardados = false;
                break;
            case 2:
                printf("[ACLARACION]Eliga la cantidad de indices...\n");
                Cantidad=menuModoAccion1(getPaquetes(centroLogistico));
                menuModoAccion2(getPaquetes(centroLogistico),Cantidad,Elecciones);
                for(int i=0;i<Cantidad+1;i++)
                {
                    paqueteModificar=getDatoLista(getPaquetes(centroLogistico),Elecciones[i]);
                    cambiarPaquete(centroLogistico, paqueteModificar);
                }
                cambiosGuardados = false;
                break;
            case 3:
                menuModoAccion3(getPaquetes(centroLogistico),Elecciones);
                for(int i=Elecciones[0];i<=Elecciones[1];i++)
                {
                    paqueteModificar=getDatoLista(getPaquetes(centroLogistico),i);
                    cambiarPaquete(centroLogistico, paqueteModificar);
                }
                cambiosGuardados = false;
                break;
            default:
                printf("Eleccion equivocada \n");
                break;
            }
            if(modoAccion == 0)
            {
                continuar = false;
            }
            else
            {
                continuar = menuContinuar();
            }
        } while(continuar);
    }
    if( !cambiosGuardados )
    {
        resultado = menuGuardarCambios();
        if(resultado == 1)
        {
            cambiosGuardados=guardarPaquetes(centroLogistico);
        }
    }
    return cambiosGuardados;
}


void menuBuscarPaquete(CentroLogisticoPtr centroLogistico)
{
    bool continuar;
    if(listaVacia(getPaquetes(centroLogistico)))
    {
        printf("ERROR: Lista vacia. No hay paquetes para buscar\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            system("cls");
            int ID=0;
            printf("BUSCAR PAQUETE\n\n");
            printf("0. Volver\n");
            printf("Ingrese ID del paquete a buscar: ");
            scanf("%d",&ID);
            limpiarBufferTeclado();
            printf("\n\n");
            if(!buscarPaquete(centroLogistico,ID) && ID != 0)
            {
                printf("\n\nNo se pudo encontrar el paquete con ID #%d.\n\n",ID);
            }
            if(ID == 0)
            {
                continuar = false;
            }
            else
            {
                continuar = menuContinuar();
            }
        }while(continuar);
    }
}


bool menuMostrarPaquetes(CentroLogisticoPtr centroLogistico, int* op1)
{
    int op=0;
    bool cambiosGuardados=false;
    if(listaVacia(getPaquetes(centroLogistico)))
    {
        printf("Lista de paquetes vacia, por favor, agregue elementos\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            op = menuTipoOrdenamientoPaquetes();
            switch(op)
            {
            case 1:
                printf("LISTADO DE PAQUETES (ORDENADOS POR ID)");
                ordenarPaquetes(centroLogistico,1);
                break;
            case 2:
                printf("LISTADO DE PAQUETES (ORDENADOS POR FECHA DE SALIDA)");
                ordenarPaquetes(centroLogistico,2);
                break;
            case 3:
                printf("LISTADO DE PAQUETES (ORDENADOS POR ESTADO)");
                ordenarPaquetes(centroLogistico,3);
                break;
            case 4:
                printf("LISTADO DE PAQUETES (SIN ORDENAR)");
                ordenarPaquetes(centroLogistico,4);
                break;
            case 0:
                break;
            case -1:
                op = 0;
                *op1 = 0;
                break;
            default:
                printf("\nOpcion incorrecta.\n\n");
                break;
            }
        } while(op!=0 && op!=-1);
    }
    return cambiosGuardados;
}

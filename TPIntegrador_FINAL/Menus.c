#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "Files.h"
#include "TDACentroLogistico.h"
#include "test.h"
#include "util.h"
#include "Menus.h"


///--------------------------------------------------------------------------------------------------------------------------

///                                                  FUNCIONES AYUDANTES

///--------------------------------------------------------------------------------------------------------------------------

int menuGuardarCambios()
{
    int opGuardar=0;
    printf("Guardar cambios? 1=SI , 0=NO | ");
    limpiarBufferTeclado();
    scanf("%d",&opGuardar);
    limpiarBufferTeclado();
    system("cls");
    return opGuardar;
}

int menuModoAccion(int opMenuAnterior)
{
    system("cls");
    int eleccion = 0;
    do
    {
        printf("Accion:\n");
        printf("1. Sobre un indice unico [Ej: Posicion 1]\n");
        printf("2. Sobre conjunto de indices [Ej: Posiciones 1,18,4,25,7,6] (*)\n");
        printf("3. Sobre rango de indices [Ej: Posiciones 1 - 4 (1,2,3,4)]\n");
        printf("0. Volver\n");
        printf("-1. MENU PRINCIPAL");
        printf("\n-------------------------------------------------------------\n");
        printf("Opcion: ");
        limpiarBufferTeclado();
        scanf("%d", &eleccion);
        limpiarBufferTeclado();
        if(eleccion<-1 || eleccion>3)
        {
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(eleccion<-1 || eleccion>3);
    if(eleccion==-1)
    {
        opMenuAnterior=-1;
    }
    system("cls");
    return eleccion;
}

int menuModoAccion1(ListaPtr lista)
{
    int eleccion = 0;
    int n=longitudLista(lista);
    int i;
    do
    {
        limpiarBufferTeclado();
        printf("\n\nIngrese indice donde tomar accion: ");
        scanf("%d",&i);
        limpiarBufferTeclado();
        if(i<=0 || i>n)
        {
            printf("\n\nERROR: indice inexistente. Vuelva a elegir.\n\n");
            presionarEnterYLimpiarPantalla();
        }
        else
            system("cls");
    } while(i<=0 || i>n);
    eleccion = i-1;
    return eleccion;
}

void menuModoAccion2(ListaPtr lista,int cantIndices,int* indices)
{
    int n=longitudLista(lista);
//Elegimos los indices
    for(int i=0;i<cantIndices;i++)
    {
        do
        {
            printf("\n\nIngrese indice %d: ",i+1);
            scanf("%d",&indices[i]);
            limpiarBufferTeclado();
            if(indices[i]<1 && indices[i]>n)
            {
                printf("\n\nIndice inexistente. Vuelva a ingresar.\n\n");
                presionarEnterYLimpiarPantalla();
            }
        } while(indices[i]<1 && indices[i]>n);
    }
    system("cls");
    for(int i=0;i<cantIndices-1;i++)
    {
        for(int j=i+1;j<cantIndices;j++)
        {
            if(indices[i]>indices[j])
            {
                int aux=0;
                aux=indices[i];
                indices[i]=indices[j];
                indices[j]=aux;
            }
        }
    }
    for(int i=0;i<cantIndices;i++)
    {
        indices[i] = indices[i]-1-i;
    }
}

void menuModoAccion3(ListaPtr lista,int* vec)
{
    int desde = 0;
    int hasta = 0;
    int n=longitudLista(lista);
    do
    {
        printf("Ingrese el indice minimo: ");
        scanf("%d",&desde);
        limpiarBufferTeclado();
        if(desde<1 || desde>n)
        {
            printf("\n\nIndice incorrecto. Vuelva a ingresar.\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(desde<1 || desde>n);
    do
    {
        printf("Ingrese el indice maximo: ");
        scanf("%d",&hasta);
        limpiarBufferTeclado();
        if(hasta<desde || hasta>n)
        {
            printf("\n\nIndice incorrecto. Vuelva a ingresar.\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(hasta<desde || hasta>n);
    vec[0]=desde-1;
    vec[1]=hasta-1;
//El sistema permite que desde y hasta sean iguales si la lista tiene solo 1 elemento.
}

bool menuContinuar()
{
    int eleccion;
    do
    {
        printf("\n\n\tDesea continuar?\n");
        printf("1. SI \n");
        printf("0. NO \n");
        printf("Opcion: ");
        limpiarBufferTeclado();
        scanf("%d", &eleccion);
        limpiarBufferTeclado();
    } while(eleccion<0 || eleccion>1);
    if(eleccion==1)
    {
        system("cls");
        return true;
    }
    else
    {
        return false;
    }
    limpiarBufferTeclado();
}

int calcularCantidad()
{
    int cantIndices=0;
    //Ingresamos la cantidad de indices a seleccionar
    do
    {
        limpiarBufferTeclado();
        printf("Ingrese cantidad de indices a seleccionar: ");
        scanf("%d",&cantIndices);
        limpiarBufferTeclado();
        if(cantIndices<=0)
        {
            printf("\n\nCantidad incorrecta.\n\n");
        }
    } while(cantIndices<=0);
    return cantIndices;
}

void tipoPersona(bool esChofer)
{
    if(esChofer)
    {
        printf("CHOFER");
    }
    else
    {
        printf("CLIENTE");
    }
}


///--------------------------------------------------------------------------------------------------------------------------

///                             FUNCIONES DE CARGA, VALIDACIÓN Y ACTUALIZACIÓN DE SUBESTRUCTURAS

///--------------------------------------------------------------------------------------------------------------------------

CuilPtr cargarCuil(CuilPtr cuil)
{
    cuil=crearCuil("0000000000000");
    char strCuil[100];
    int i=0;
    do
    {
        helpCuil();
        printf("\n\tCUIL:");
        limpiarBufferTeclado();
        scanf("%[^\n]%*c",strCuil);
        limpiarBufferTeclado();
        setCuil(cuil,strCuil);
        system("cls");
        i++;
    } while(!esCuilValido(cuil));
    return cuil;
}

DomicilioPtr cargarDomicilio(DomicilioPtr domicilio)
{
    char calle[100];
    int altura;
    char localidad[100];
    limpiarBufferTeclado();
    printf("\n\t\tCalle: ");
    scanf("%[^\n]%*c",calle);
    limpiarBufferTeclado();
    printf("\n\t\tAltura: ");
    scanf("%d",&altura);
    limpiarBufferTeclado();
    printf("\n\t\tLocalidad: ");
    scanf("%[^\n]%*c",localidad);
    limpiarBufferTeclado();
    domicilio=crearDomicilio(calle,altura,localidad);
    return domicilio;
}

FechaPtr cargarFecha(FechaPtr fecha)
{
    int dia=0,mes=0,anio=0,hora=0,minuto=0;
    fecha=crearFecha(dia,mes,anio,hora,minuto);
    do
    {
        printf("\n\t\tFecha (DD MM AAAA) ---- Horario (HH MM): ");
        limpiarBufferTeclado();
        scanf("%d %d %d %d %d",&dia,&mes,&anio,&hora,&minuto);
        limpiarBufferTeclado();
        setDia(fecha,dia);
        setMes(fecha,mes);
        setAnio(fecha,anio);
        setHora(fecha,hora);
        setMinuto(fecha,minuto);
        system("cls");
    }while(!esFechaValida(fecha));
    return fecha;
}

void actualizarCuil(CuilPtr cuil)
{
    char strCuil[100];
    do
    {
        helpCuil();
        printf("\n\tNuevo CUIL:");
        limpiarBufferTeclado();
        scanf("%[^\n]%*c",strCuil);
        limpiarBufferTeclado();
        setCuil(cuil,strCuil);
        system("cls");
    } while(!esCuilValido(cuil));
}

void actualizarDomicilio(DomicilioPtr domicilio)
{
    char calle[100];
    int altura;
    char localidad[100];
    limpiarBufferTeclado();
    printf("\n\t\t[CALLE]: ");
    scanf("%[^\n]%*c",calle);
    limpiarBufferTeclado();
    printf("\n\t\tAltura: ");
    scanf("%d",&altura);
    limpiarBufferTeclado();
    printf("\n\t\tLocalidad: ");
    scanf("%[^\n]%*c",localidad);
    limpiarBufferTeclado();
    setCalle(domicilio,calle);
    setAltura(domicilio,altura);
    setLocalidad(domicilio,localidad);
}

void actualizarFecha(FechaPtr fecha)
{
    int dia=0,mes=0,anio=0,hora=0,minuto=0,i=0;
    do
    {
        printf("\n\t\tFecha (DD MM AAAA): ");
        scanf("%d %d %d",&dia,&mes,&anio);
        limpiarBufferTeclado();
        printf("\n\t\tHorario (HH MM): ");
        scanf("%d %d",&hora,&minuto);
        limpiarBufferTeclado();
        setDia(fecha,dia);
        setMes(fecha,mes);
        setAnio(fecha,anio);
        setHora(fecha,hora);
        setMinuto(fecha,minuto);
        system("cls");
    }while(!esFechaValida(fecha));
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE CARGADO///
///-----------------------------------------------------------------------------------------------------------///

bool menuCargarPaquete(CentroLogisticoPtr centroLogistico)
{
    PaquetePtr paquete;
    ///el ID del paquete se genera automáticamente, no lo tiene que ingresar el usuario.
    int ID=0,ancho=0,alto=0,largo=0,peso=0,i=1,resultado=0;
    FechaPtr fechaEntrega;
    DomicilioPtr dirRetiro;
    DomicilioPtr dirEntrega;
    ///por defecto, los paquetes se cargan con el estado 0: 'en depósito'.
    srand(time(NULL));
    bool cambiosGuardados=false, continuar;
    do
    {
        system("cls");
        limpiarBufferTeclado();
        printf("PAQUETE %d\n\n",i++);
        ID=rand(); //esto no se mostrará sino al final de la carga del paquete.
        printf("\tAncho: ");
        scanf("%d",&ancho);
        limpiarBufferTeclado();
        printf("\n\tAlto: ");
        scanf("%d",&alto);
        limpiarBufferTeclado();
        printf("\n\tLargo: ");
        scanf("%d",&largo);
        limpiarBufferTeclado();
        printf("\n\tPeso: ");
        scanf("%d",&peso);
        limpiarBufferTeclado();
        printf("\n\tDireccion de retiro:");
        dirRetiro=cargarDomicilio(dirRetiro);
        printf("\n\tDireccion de entrega:");
        dirEntrega=cargarDomicilio(dirEntrega);
        printf("\n\tFecha de entrega:");
        fechaEntrega=cargarFecha(fechaEntrega);
        paquete=crearPaquete(ID,ancho,alto,largo,peso,dirRetiro,dirEntrega,fechaEntrega,0);
        agregarPaquete(centroLogistico,paquete);
        continuar=menuContinuar();
    } while(continuar);
    resultado=menuGuardarCambios();
    if(resultado==1)
    {
        cambiosGuardados=guardarPaquetes(centroLogistico);
    }
    return cambiosGuardados;
}
bool menuCargarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    int i=1,resultado=0;
    char nombre[100];
    char apellido[100];
    PersonaPtr persona;
    DomicilioPtr domicilio;
    CuilPtr cuil;
    bool cambiosGuardados=false, continuar;
    do
    {
        system("cls");
        tipoPersona(esChofer);
        printf(" %d \n\n", i++);
        limpiarBufferTeclado();
        printf("\tNombre: ");
        scanf("%[^\n]%*c",nombre);
        limpiarBufferTeclado();
        printf("\n\tApellido: ");
        scanf("%[^\n]%*c",apellido);
        limpiarBufferTeclado();
        printf("\n\tDomicilio");
        domicilio=cargarDomicilio(domicilio);
        cuil=cargarCuil(cuil);
        persona=crearPersona(nombre,apellido,domicilio,cuil,false);
        agregarPersona(centroLogistico,persona);
        continuar=menuContinuar();
    } while(continuar);
    resultado=menuGuardarCambios();
    if(resultado==1)
    {
        cambiosGuardados=guardarPersonas(centroLogistico);
    }
    return cambiosGuardados;
}
bool menuCargarVehiculo(CentroLogisticoPtr centroLogistico)
{
    int tipoVehiculo=0,i=1,resultado=0;
    char marca[100];
    char modelo[100];
    char patente[100];
    VehiculoPtr vehiculo;
    bool cambiosGuardados=false, continuar;
    do
    {
        system("cls");
        printf("VEHICULO %d\n\n",i++);
        helpTipoVehiculo();
        limpiarBufferTeclado();
        printf("\n\n\tSeleccione un Tipo: ");
        scanf("%d",&tipoVehiculo);
        limpiarBufferTeclado();
        printf("\n\n\tMarca: ");
        scanf("%[^\n]%*c",marca);
        printf("\n\tModelo: ");
        scanf("%[^\n]%*c",modelo);
        limpiarBufferTeclado();
        printf("\n\tPatente (AA 000 AA): ");
        scanf("%[^\n]%*c",patente);
        limpiarBufferTeclado();
        vehiculo=crearVehiculo(tipoVehiculo,marca,modelo,patente);
        agregarVehiculo(centroLogistico,vehiculo);
        continuar=menuContinuar();
    } while(continuar);
    resultado=menuGuardarCambios();
    if(resultado==1)
    {
        cambiosGuardados=guardarVehiculos(centroLogistico);
    }
    return cambiosGuardados;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE BUSQUEDA///
///-----------------------------------------------------------------------------------------------------------///

void menuBuscarPaquete(CentroLogisticoPtr centroLogistico)
{
    bool continuar;

    if(listaVacia(getPaquetes(centroLogistico)))
        printf("ERROR: Lista vacia. No hay paquetes para buscar\n");
    else
    {
        do
        {
            int ID=0;
            printf("BUSCAR PAQUETE\n\n");

            printf("Ingrese ID del paquete a buscar: ");
            scanf("%d",&ID);
            limpiarBufferTeclado();
            printf("\n\n");

            if(!buscarPaquete(centroLogistico,ID))
                printf("\n\nNo se pudo encontrar el paquete con ID #%d.\n\n",ID);

            continuar=menuContinuar();
        } while(continuar);
    }
}
void menuBuscarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    bool continuar;

    if(listaVacia(getPersonas(centroLogistico)))
    {
        if(esChofer)
            printf("ERROR: Lista vacia. No hay choferes para buscar\n");
        else
            printf("ERROR: Lista vacia. No hay clientes para buscar\n");
    }
    else
    {
        do
        {
            CuilPtr cuilABuscar;
            if(esChofer)
            {
                printf("BUSCAR CHOFER\n\n");
                printf("Ingrese el CUIL del chofer a buscar: ");
            }
            else
            {
                printf("BUSCAR CLIENTE\n\n");
                printf("Ingrese el CUIL del cliente a buscar: ");
            }
            cargarCuil(cuilABuscar);
            printf("\n\n");

            if(!buscarPersona(centroLogistico,cuilABuscar,esChofer))
            {
                if(esChofer)
                    printf("\n\nNo se pudo encontrar el chofer con CUIL %s.\n\n",getCuil(cuilABuscar));
                else
                    printf("\n\nNo se pudo encontrar el cliente con CUIL %s.\n\n",getCuil(cuilABuscar));
            }

            continuar=menuContinuar();
        } while(continuar);
    }
}
void menuBuscarVehiculo(CentroLogisticoPtr centroLogistico)
{
    bool continuar;

    if(listaVacia(getVehiculos(centroLogistico)))
        printf("ERROR: Lista vacia. No hay vehiculos para buscar\n");
    else
    {
        do
        {
            char patente[100];
            printf("BUSCAR VEHICULO\n\n");

            printf("Ingrese la patente del vehiculo a buscar (AA 111 AA): ");
            scanf("%[^\n]%*c",patente);

            if(!buscarVehiculo(centroLogistico,patente))
                printf("\n\nNo se pudo encontrar el vehiculo con patente %s.\n\n",patente);

            continuar=menuContinuar();
        } while(continuar);
    }
}


///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE ELIMINACION///
///-----------------------------------------------------------------------------------------------------------///

bool menuEliminarPaquete(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    int opcion=0;
    bool cambiosGuardados=false;
    bool continuar;
    int modoAccion=0;
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int indices[100];
    int cantIndices=0;
    PaquetePtr paqueteRemovido=(PaquetePtr)obtenerMemoria(sizeof(Paquete));
    ListaPtr listaAuxiliar = getPaquetes(centroLogistico);
    if(listaVacia(listaAuxiliar))
        printf("ERROR: Lista vacía. Debe agregar paquetes para poder eliminarlos.\n\n");
    else
    {
        do
        {
            EleccionMenuModoAccion = menuModoAccion(0);
            mostrarPaquetes(centroLogistico);
            printf("ELIMINAR PAQUETE\n\n");
            switch(EleccionMenuModoAccion)
            {
            case 1:
                EleccionAccion = menuModoAccion1(listaAuxiliar);
                paqueteRemovido = removerPaquete(centroLogistico, EleccionAccion);
                paqueteRemovido = destruirPaquete(paqueteRemovido);
                break;
            case 2:
                cantIndices = calcularCantidad();
                menuModoAccion2(listaAuxiliar,cantIndices,&indices);
                for(int i=0;i<cantIndices;i++)
                {
                    paqueteRemovido = removerPaquete(centroLogistico,indices[i]);
                    paqueteRemovido = destruirPaquete(paqueteRemovido);
                }
                break;
            case 3:
                menuModoAccion3(listaAuxiliar,&indices);
                for(int i=0;i<indices[1]-indices[0]+1;i++)
                {
                    paqueteRemovido = removerPaquete(centroLogistico,indices[0]);
                    paqueteRemovido = destruirPaquete(paqueteRemovido);
                }
                break;
            default:
                printf("Eleccion equivocada \n");
                break;
            }
            continuar = menuContinuar();
        }while(continuar==true);
    opcion=menuGuardarCambios();
    if(opcion==1)
        cambiosGuardados=guardarPersonas(centroLogistico);
    }
    return cambiosGuardados;
}
bool menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer,int opMenuAnterior)
{
    bool cambiosGuardados=false, continuar;
    int EleccionMenuModoAccion=0, EleccionAccion=0, cantidadCorrectas=0, cantIndices=0, opcion=0;
    int indices[100];
    PersonaPtr personaRemovida = (PersonaPtr)obtenerMemoria(sizeof(Persona));
    ListaPtr listaAuxiliar = getPersonas(centroLogistico);
    if(listaVacia(listaAuxiliar))
    {
        if(esChofer)
        {
            printf("ERROR: Lista vacía. Debe agregar choferes para poder eliminarlos.\n\n");
        }
        else
        {
            printf("ERROR: Lista vacía. Debe agregar clientes para poder eliminarlos.\n\n");
        }
    }
    else
    {
        do
        {
            printf("ADVERTENCIA: La opcion 3 no funciona en este tipo de lista \n\n");
            EleccionMenuModoAccion = menuModoAccion(0);
            if(esChofer)
            {
                mostrarPersonas(centroLogistico,1);
                printf("ELIMINAR CHOFR \n\n");
            }
            else
            {
                mostrarPersonas(centroLogistico,2);
                printf("ELIMINAR CLIENTE \n\n");
            }
            switch(EleccionMenuModoAccion)
            {
            case 1:
                EleccionAccion = menuModoAccion1(listaAuxiliar);
                if(getEsChofer(getDatoLista(listaAuxiliar,EleccionAccion))==esChofer)
                {
                    personaRemovida = removerPersona(centroLogistico, EleccionAccion);
                    personaRemovida = destruirPersona(personaRemovida);
                }
                break;
            case 2:
                cantidadCorrectas=0;
                cantIndices = calcularCantidad();
                menuModoAccion2(listaAuxiliar,cantIndices,&indices);
                for(int i=0;i<cantIndices;i++)
                {
                    if(getEsChofer(getDatoLista(listaAuxiliar,indices[i]))==esChofer)
                    {
                        cantidadCorrectas++;
                    }
                }
                if(cantidadCorrectas == cantIndices)
                {
                    for(int i=0;i<cantIndices;i++)
                    {
                        personaRemovida = removerPersona(centroLogistico,indices[i]);
                        personaRemovida = destruirPersona(personaRemovida);
                    }
                }
                break;
            case 3:
                cantidadCorrectas=0;
                menuModoAccion3(listaAuxiliar,&indices);
                for(int i=indices[0];i<indices[1]+1;i++)
                {
                    if(getEsChofer(getDatoLista(listaAuxiliar,i))==esChofer)
                    {
                        cantidadCorrectas++;
                    }
                }
                if(cantidadCorrectas==indices[1]-indices[0]+1)
                {
                    for(int i=indices[0];i<indices[1]+1;i++)
                    {
                        personaRemovida = removerPersona(centroLogistico,indices[0]);
                        personaRemovida = destruirPersona(personaRemovida);
                    }
                }
                else
                {
                    printf("ERROR: No ha elegido correctamente \n");
                }
                break;
            default:
                printf("Eleccion equivocada \n");
                break;
            }
            continuar=menuContinuar();
        } while(continuar==true);
    }
    opcion=menuGuardarCambios();
    if(opcion==1)
    {
        cambiosGuardados=guardarPersonas(centroLogistico);
    }
    return cambiosGuardados;
}
bool menuEliminarVehiculo(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    int opcion=0;
    bool cambiosGuardados=false;
    bool continuar;
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int indices[100];
    int cantIndices=0;
    VehiculoPtr vehiculoRemovido = (VehiculoPtr)obtenerMemoria(sizeof(Vehiculo));
    ListaPtr listaAuxiliar = getVehiculos(centroLogistico);
    if(listaVacia(listaAuxiliar))
        printf("ERROR: Lista vacía. Debe agregar vehiculos para poder eliminarlos.\n\n");
    else
    {
        do
        {
        EleccionMenuModoAccion = menuModoAccion(0);
        mostrarVehiculos(centroLogistico);
        printf("ELIMINAR VEHICULO \n\n");
            switch(EleccionMenuModoAccion)
            {
            case 1:
                EleccionAccion = menuModoAccion1(listaAuxiliar);
                vehiculoRemovido = removerVehiculo(centroLogistico, EleccionAccion);
                vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
                break;
            case 2:
                cantIndices = calcularCantidad();
                menuModoAccion2(listaAuxiliar,cantIndices,&indices);
                for(int i=0;i<cantIndices;i++)
                {
                    vehiculoRemovido = removerPaquete(centroLogistico,indices[i]);
                    vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
                }
                break;
            case 3:
                menuModoAccion3(listaAuxiliar,&indices);
                for(int i=0;i<indices[1]-indices[0]+1;i++)
                {
                    vehiculoRemovido = removerPaquete(centroLogistico,indices[0]);
                    vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
                }
                break;
            default:
                printf("Eleccion equivocada \n");
                break;
            }
        continuar=menuContinuar();
    } while(continuar);
    opcion=menuGuardarCambios();
    if(opcion==1)
        cambiosGuardados=guardarPersonas(centroLogistico);
    }
    return cambiosGuardados;
}


///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE MODIFICACION///
///-----------------------------------------------------------------------------------------------------------///

///VEHICULOS

void cambiarVehiculo(VehiculoPtr vehiculoAModificar)
{
    int op=0;
    int nTipo=0;
    char nMarca[100];
    char nModelo[100];
    char nPatente[100];
    int seguirMod=0;
    do
    {
        system("cls");
        printf("Ha elegido - \n");
        mostrarVehiculo(vehiculoAModificar);
        printf("\n\nQué desea modificar?\n\n");
        printf("1. Tipo de vehiculo\n");
        printf("2. Marca\n");
        printf("3. Modelo\n");
        printf("4. Patente\n");
        printf("Seleccione una opcion: ");
        limpiarBufferTeclado();
        scanf("%d",&op);
        limpiarBufferTeclado();
        switch(op)
        {
        case 1:
            printf("\n\n");
            helpTipoVehiculo();
            printf("\n\nSeleccione una opcion: ");
            scanf("%d",&nTipo);
            switch(nTipo)
            {
            case 1:
                setTipoVehiculo(vehiculoAModificar,1);
                break;
            case 2:
                setTipoVehiculo(vehiculoAModificar,2);
                break;
            case 3:
                setTipoVehiculo(vehiculoAModificar,3);
                break;
            default:
                printf("\nERROR: esa opcion no existe.\n\n");
                break;
            }
            break;
        case 2:
            printf("\n\nIngrese la nueva marca:");
            scanf("%[^\n]%*c",nMarca);
            setMarca(vehiculoAModificar,nMarca);
            break;
        case 3:
            printf("\n\nIngrese el nuevo modelo:");
            scanf("%[^\n]%*c",nModelo);
            setModelo(vehiculoAModificar,nModelo);
            break;
        case 4:
            printf("\n\nIngrese la nueva patente (AA 111 AA):\n\t");
            scanf("%[^\n]%*c",nPatente);
            setPatente(vehiculoAModificar,nPatente);
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            break;
        }
        printf("\n\nDatos modificados exitosamente.\n\n");
        printf("Desea seguir modificando este vehiculo?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&seguirMod);
    } while(seguirMod!=0);
}

ListaPtr OriginalVehiculos(CentroLogisticoPtr centroLogistico)
{
    ///Creamos una lista "original" para ver si hay cambios,
    ///y una "auxiliar" para obtener y recorrer la lista.
    ListaPtr listaOriginal=crearLista();
    ListaPtr listaAux2=crearLista();
    agregarLista(listaAux2,getVehiculos(centroLogistico));
    ///Hacemos lo mismo pero para cada elemento de la lista
    VehiculoPtr vehiculoOriginal;
    VehiculoPtr vehiculoAux;
    while(!listaVacia(listaAux2))
    {
        vehiculoAux=getCabecera(listaAux2);
        ///Copiamos el contenido de cada elemento
        vehiculoOriginal=crearVehiculo(getTipoVehiculo(vehiculoAux),getMarca(vehiculoAux),getModelo(vehiculoAux),getPatente(vehiculoAux));
        ///Agregamos el dato original a la lista
        agregarDatoLista(listaOriginal,(VehiculoPtr)vehiculoOriginal);
        listaAux2=getResto(listaAux2);
    }
    listaAux2=destruirLista(listaAux2,false);
    return listaOriginal;
}

bool CambiosVehiculos(CentroLogisticoPtr centroLogistico, ListaPtr listaOriginal)
{
    bool cambioDetectado=false;
    ListaPtr listaAux2=crearLista();
    VehiculoPtr vehiculoAux;
    VehiculoPtr vehiculoOriginal;
    agregarLista(listaAux2,getVehiculos(centroLogistico));
    ///Recorremos la lista: antes y después de hacer el cambio
    while(!listaVacia(listaAux2))
    {
        vehiculoAux=getCabecera(listaAux2);
        vehiculoOriginal=getCabecera(listaOriginal);
        ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
        if(!vehiculosIguales(vehiculoOriginal,vehiculoAux))
            cambioDetectado=true;
        listaAux2=getResto(listaAux2);
        listaOriginal=getResto(listaOriginal);
    }
    ///Destruimos ambas listas, ya no las necesitamos más
    listaAux2=destruirLista(listaAux2,false);
    ///Como en esta copiamos los contenidos, ponemos true para removerlos.
    listaOriginal=destruirLista(listaOriginal,true);
    return cambioDetectado;
}

bool menuModificarVehiculo(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    bool cambioDetectado=false, cambiosGuardados=false, continuar;
    int modoAccion, Cantidad, Eleccion, resultado, op;
    int Elecciones[10];
    VehiculoPtr vehiculoModificar;
    ListaPtr listaAuxiliar=getVehiculos(centroLogistico);
    ListaPtr listaOriginal;
    if(listaVacia(listaAuxiliar))
    {
        printf("ERROR: Lista vacía. Debe agregar vehiculos para poder modificarlos.\n\n");
    }
    else
    {
    ///------------------------------------------------------------------------------------------------------///
        listaOriginal = OriginalVehiculos(centroLogistico);
    ///------------------------------------------------------------------------------------------------------///
        do
        {
            modoAccion = menuModoAccion(opMenuAnterior);
            mostrarVehiculos(centroLogistico);
            switch(modoAccion)
            {
            case 1:
                Eleccion=menuModoAccion1(listaAuxiliar);
                vehiculoModificar=getDatoLista(listaAuxiliar,Eleccion);
                cambiarVehiculo(vehiculoModificar);
                break;
            case 2:
                Cantidad=calcularCantidad();
                menuModoAccion2(listaAuxiliar,Cantidad,&Elecciones);
                for(int i=0;i<Cantidad;i++)
                {
                    vehiculoModificar=getDatoLista(listaAuxiliar,Elecciones[i]);
                    cambiarVehiculo(vehiculoModificar);
                }
                break;
            case 3:
                menuModoAccion3(listaAuxiliar,&Elecciones);
                for(int i=0;i<Elecciones[1]-Elecciones[0]+1;i++)
                {
                    vehiculoModificar=getDatoLista(listaAuxiliar,i);
                    cambiarVehiculo(vehiculoModificar);
                }
                break;
            default:
                printf("Eleccion equivocada \n");
                break;
            }
            continuar=menuContinuar();
        } while(continuar);
    ///------------------------------------------------------------------------------------------------------///
        cambioDetectado = CambiosVehiculos(centroLogistico,listaOriginal);
    ///------------------------------------------------------------------------------------------------------///
    }
    if(cambioDetectado)
    {
        resultado=menuGuardarCambios();
        if(resultado==1)
        {
            cambiosGuardados=guardarVehiculos(centroLogistico);
        }
    }
    return cambiosGuardados;
}

///PERSONAS


void cambiarPersona(PersonaPtr personaAModificar, bool esChofer)
{
    int seguirMod=0,op=0;
    char nNombre[100];
    char nApellido[100];
    DomicilioPtr nuevoDomicilio;
    CuilPtr nuevoCuil;
    do
    {
        system("cls");
        printf("Ha elegido - \n\n");
        mostrarPersona(personaAModificar);
        printf("\n\nQué desea modificar?\n\n");
        printf("1. Nombre y Apellido\n");
        printf("2. Domicilio\n");
        printf("3. CUIL\n");
        if(esChofer)
        {
            printf("4. Cambiar persona a: CLIENTE\n");
        }
        else
        {
            printf("4. Cambiar persona a: CHOFER\n");
        }
        printf("Seleccione una opcion: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("\n\nIngrese el nuevo nombre y apellido de esta manera:");
                printf("\n\t[Nombre]: ");
                limpiarBufferTeclado();
                scanf("%[^\n]%*c",nNombre);
                limpiarBufferTeclado();
                printf("\n\t[Apellido]: ");
                limpiarBufferTeclado();
                scanf("%[^\n]%*c",nApellido);
                limpiarBufferTeclado();
                setNombre(personaAModificar,nNombre);
                setApellido(personaAModificar,nApellido);
            break;
            case 2:
                printf("\n\nIngrese el nuevo domicilio:");
                actualizarDomicilio(nuevoDomicilio);
                setDomicilio(personaAModificar,nuevoDomicilio);
            break;
            case 3:
                actualizarCuil(nuevoCuil);
                setCuilPersona(personaAModificar,nuevoCuil);
            break;
            case 4:
                if(esChofer)
                {
                    setEsChofer(personaAModificar,false);
                }
                else
                {
                    setEsChofer(personaAModificar,true);
                }
            break;
            default:
                printf("\nOpcion incorrecta.\n\n");
                presionarEnterYLimpiarPantalla();
            break;
        }
        printf("\n\nDatos modificados exitosamente.\n\n");
        printf("Desea seguir modificando esta persona?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&seguirMod);
    } while(seguirMod!=0);
}

ListaPtr OriginalPersonas(CentroLogisticoPtr centroLogistico)
{
    ///Creamos una lista "original" para ver si hay cambios,
    ///y una "auxiliar" para obtener y recorrer la lista.
    ListaPtr listaOriginal=crearLista();
    ListaPtr listaAux2=crearLista();
    agregarLista(listaAux2,getPersonas(centroLogistico));
    ///Hacemos lo mismo pero para cada elemento de la lista
    PersonaPtr personaOriginal;
    PersonaPtr personaAux;
    while(!listaVacia(listaAux2))
    {
        personaAux=getCabecera(listaAux2);
        ///Copiamos el contenido de cada elemento
        personaOriginal=crearPersona(getNombre(personaAux),getApellido(personaAux),getDomicilio(personaAux),getCuilPersona(personaAux),getEsChofer(personaAux));
        ///Agregamos el dato original a la lista
        agregarDatoLista(listaOriginal,(PersonaPtr)personaOriginal);
        listaAux2=getResto(listaAux2);
    }
    listaAux2=destruirLista(listaAux2,false);
    return listaOriginal;
}

bool CambiosPersonas(CentroLogisticoPtr centroLogistico, ListaPtr listaOriginal)
{
    bool cambioDetectado=false;
    ListaPtr listaAux2=crearLista();
    PersonaPtr personaAux;
    PersonaPtr personaOriginal;
    agregarLista(listaAux2,getPersonas(centroLogistico));
    ///Recorremos la lista: antes y después de hacer el cambio
    while(!listaVacia(listaAux2))
    {
        personaAux=getCabecera(listaAux2);
        personaOriginal=getCabecera(listaOriginal);
        ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
        if(!personasIguales(personaOriginal,personaAux))
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

bool menuModificarPersona(CentroLogisticoPtr centroLogistico,bool esChofer,int opMenuAnterior)
{
    ListaPtr listaAuxiliar=getPersonas(centroLogistico);
    ListaPtr listaOriginal;
    int resultado=0,modoAccion=0,Eleccion=0,Cantidad=0,cantidadCorrectas=0;
    int Elecciones[10];
    PersonaPtr personaModificar;
    bool cambiosGuardados=false, cambioDetectado=false, continuar;
    if(listaVacia(listaAuxiliar))
    {
        if(esChofer)
        {
            printf("ERROR: Lista vacía. Debe agregar choferes para poder modificarlos.\n\n");
        }
        else
        {
            printf("ERROR: Lista vacía. Debe agregar clientes para poder modificarlos.\n\n");
        }
    }
    else
    {
    ///---------------------------------------------------------------------///
        listaOriginal = OriginalPersonas(centroLogistico);
    ///---------------------------------------------------------------------///
        do
        {
            modoAccion=menuModoAccion(opMenuAnterior);
            if(esChofer)
            {
                mostrarPersonas(centroLogistico,1);
            }
            else
            {
                mostrarPersonas(centroLogistico,2);
            }
            switch(modoAccion)
            {
            case 1:
                Eleccion=menuModoAccion1(listaAuxiliar);
                personaModificar=getDatoLista(listaAuxiliar,Eleccion);
                cambiarPersona(personaModificar,esChofer);
                break;
            case 2:
                Cantidad=calcularCantidad();
                menuModoAccion2(listaAuxiliar,Cantidad,&Elecciones);
                for(int i=0;i<Cantidad;i++)
                {
                    personaModificar=getDatoLista(listaAuxiliar,Elecciones[i]);
                    cambiarPersona(personaModificar,esChofer);
                }
                break;
            case 3:
                cantidadCorrectas=0;
                menuModoAccion3(listaAuxiliar,&Elecciones);
                for(int i=Elecciones[0];i<Elecciones[1]+1;i++)
                {
                    if(getEsChofer(getDatoLista(listaAuxiliar,i))==esChofer)
                    {
                        cantidadCorrectas++;
                    }
                }
                if(cantidadCorrectas==Elecciones[1]-Elecciones[0]+1)
                {
                    for(int i=Elecciones[0];i<Elecciones[1]+1;i++)
                    {
                        personaModificar = getDatoLista(listaAuxiliar,i);
                        cambiarPersona(personaModificar,esChofer);
                    }
                }
                else
                {
                    printf("ERROR: No ha elegido correctamente \n");
                }
                break;
            default:
                printf("Eleccion equivocada \n");
                break;
            }
            continuar=menuContinuar();
        } while(continuar);

    ///---------------------------------------------------------------------///
        cambioDetectado = CambiosPersonas(centroLogistico, listaOriginal);
    ///---------------------------------------------------------------------///
    }
    if(cambioDetectado)
    {
        resultado=menuGuardarCambios();
        if(resultado==1)
        {
            cambiosGuardados=guardarPersonas(centroLogistico);
        }
    }
    return cambiosGuardados;
}

///PAQUETES



///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE MOSTRAR///
///-----------------------------------------------------------------------------------------------------------///


bool menuMostrarPaquetes(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    int op=0;

    bool cambioDetectado=false;
    bool cambiosGuardados=false;

///Creamos una lista "original" para ver si hay cambios,
///y una "auxiliar" para obtener y recorrer la lista.
    ListaPtr listaOriginal=crearLista();

    ListaPtr listaAux2=crearLista();
    agregarLista(listaAux2,getPaquetes(centroLogistico));
//Hacemos lo mismo pero para cada elemento de la lista
    PaquetePtr paqueteOriginal;

    PaquetePtr paqueteAux;
    while(!listaVacia(listaAux2))
    {
        paqueteAux=getCabecera(listaAux2);
    ///Copiamos el contenido de cada elemento
        paqueteOriginal=crearPaquete(getID(paqueteAux),
                                     getAncho(paqueteAux),
                                     getAlto(paqueteAux),
                                     getLargo(paqueteAux),
                                     getPeso(paqueteAux),
                                     getDirRetiro(paqueteAux),
                                     getDirEntrega(paqueteAux),
                                     getFechaEntrega(paqueteAux),
                                     getEstado(paqueteAux));
     ///Agregamos el dato original a la lista
        agregarDatoLista(listaOriginal,(PaquetePtr)paqueteOriginal);
        listaAux2=getResto(listaAux2);
    }
    listaAux2=destruirLista(listaAux2,false);

    do
    {
        printf("EMITIR LISTADO DE PAQUETES\n");
        printf("\n-----------------------------------------\n\n");
        printf("1. Ordenados por ID\n");
        printf("2. Ordenados por Fecha de Entrega\n");
        printf("3. Ordenados por Estado\n");
        printf("4. SIN ORDENAR\n");
        printf("0. Volver\n");
        printf("-1. MENU PRINCIPAL");
        printf("\n-----------------------------------------\n\n");
        printf("Elija una opcion: ");
        scanf("%d",&op);
        limpiarBufferTeclado();
        system("cls");
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
            break;
        case 0:
            break;
        case -1:
            opMenuAnterior=0;
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            break;
        }
        if(op>=1 && op<=3) //Si se ordenó la lista
        {
            listaAux2=crearLista();
            agregarLista(listaAux2,getPaquetes(centroLogistico));
        ///Recorremos la lista: antes y después de hacer el cambio
            while(!listaVacia(listaAux2))
            {
                paqueteAux=getCabecera(listaAux2);
                paqueteOriginal=getCabecera(listaOriginal);
            ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
                if(!paquetesIguales(paqueteOriginal,paqueteAux))
                    cambioDetectado=true;

                listaAux2=getResto(listaAux2);
                listaOriginal=getResto(listaOriginal);
            }
            listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
            listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.
        }
        if(!(op==0 && op==-1))
        {
            printf("\n-----------------------------------------------------\n\n");
            mostrarPaquetes(centroLogistico);
            printf("\n-----------------------------------------------------\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(!(op==0 && op==-1));

    if(cambioDetectado)
    {
        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&op);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1:
                if(guardarPaquetes(centroLogistico))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
                }
                else
                {
                    printf("ERROR AL GUARDAR\n\n");
                    exit(1);
                }
                break;
            case 0:
                break;
            default:
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(op!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }

    return cambiosGuardados;
}
bool menuMostrarPersonas(CentroLogisticoPtr centroLogistico,int tipo,int opMenuAnterior)
{
    int op=0;

    bool cambioDetectado=false;
    bool cambiosGuardados=false;

///Creamos una lista "original" para ver si hay cambios,
///y una "auxiliar" para obtener y recorrer la lista.
    ListaPtr listaOriginal=crearLista();

    ListaPtr listaAux2=crearLista();
    agregarLista(listaAux2,getPersonas(centroLogistico));
//Hacemos lo mismo pero para cada elemento de la lista
    PersonaPtr personaOriginal;

    PersonaPtr personaAux;
    while(!listaVacia(listaAux2))
    {
        personaAux=getCabecera(listaAux2);
    ///Copiamos el contenido de cada elemento
        personaOriginal=crearPersona(getNombre(personaAux),
                                     getApellido(personaAux),
                                     getDomicilio(personaAux),
                                     getCuilPersona(personaAux),
                                     getEsChofer(personaAux));
     ///Agregamos el dato original a la lista
        agregarDatoLista(listaOriginal,(PersonaPtr)personaOriginal);
        listaAux2=getResto(listaAux2);
    }
    listaAux2=destruirLista(listaAux2,false);

    do
    {
        switch(tipo)
        {
        case 1:
            printf("EMITIR LISTADO DE CHOFERES\n");
            break;
        case 2:
            printf("EMITIR LISTADO DE CLIENTES\n");
            break;
        case 3:
            printf("EMITIR LISTADO DE PERSONAS\n");
            break;
        }
        printf("\n-----------------------------------------\n\n");
        printf("1. Ordenados por Nombre\n");
        printf("2. Ordenados por Apellido\n");
        printf("3. Ordenados por Nombre y Apellido\n");
        printf("4. SIN ORDENAR\n");
        printf("0. Volver\n");
        printf("-1. MENU PRINCIPAL");
        printf("\n-----------------------------------------\n\n");
        printf("Elija una opcion: ");
        scanf("%d",&op);
        limpiarBufferTeclado();
        system("cls");

        switch(tipo)
        {
        case 1:
            printf("LISTADO DE CHOFERES ");
            break;
        case 2:
            printf("LISTADO DE CLIENTES ");
            break;
        case 3:
            printf("LISTADO DE PERSONAS ");
            break;
        }

        switch(op)
        {
        case 1:
            printf("(ORDENADO POR NOMBRE)");
            ordenarPersonas(centroLogistico,1);
            break;
        case 2:
            printf("(ORDENADO POR APELLIDO)");
            ordenarPersonas(centroLogistico,2);
            break;
        case 3:
            printf("(ORDENADO POR NOMBRE Y APELLIDO)");
            ordenarPersonas(centroLogistico,3);
            break;
        case 4:
            printf("(SIN ORDENAR)");
            break;
        case 0:
            break;
        case -1:
            opMenuAnterior=0;
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            break;
        }
        if(op>=1 && op<=3) //Si se ordenó la lista
        {
            listaAux2=crearLista();
            agregarLista(listaAux2,getPersonas(centroLogistico));
        ///Recorremos la lista: antes y después de hacer el cambio
            while(!listaVacia(listaAux2))
            {
                personaAux=getCabecera(listaAux2);
                personaOriginal=getCabecera(listaOriginal);
            ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
                if(!personasIguales(personaOriginal,personaAux))
                    cambioDetectado=true;

                listaAux2=getResto(listaAux2);
                listaOriginal=getResto(listaOriginal);
            }
            listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
            listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.
        }
        if(!(op==0 && op==-1))
        {
            printf("\n-----------------------------------------------------\n\n");
            switch(tipo)
            {
            case 1:
                mostrarPersonas(centroLogistico,1);
                break;
            case 2:
                mostrarPersonas(centroLogistico,2);
                break;
            case 3:
                mostrarPersonas(centroLogistico,3);
                break;
            }
            printf("\n-----------------------------------------------------\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(!(op==0 && op==-1));

    if(cambioDetectado)
    {
        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&op);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1:
                if(guardarPersonas(centroLogistico))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
                }
                else
                {
                    printf("ERROR AL GUARDAR\n\n");
                    exit(1);
                }
                break;
            case 0:
                break;
            default:
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(op!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }

    return cambiosGuardados;
}
bool menuMostrarVehiculos(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    int op=0;

    bool cambioDetectado=false;
    bool cambiosGuardados=false;

///Creamos una lista "original" para ver si hay cambios,
///y una "auxiliar" para obtener y recorrer la lista.
    ListaPtr listaOriginal=crearLista();

    ListaPtr listaAux2=crearLista();
    agregarLista(listaAux2,getVehiculos(centroLogistico));
//Hacemos lo mismo pero para cada elemento de la lista
    VehiculoPtr vehiculoOriginal;

    VehiculoPtr vehiculoAux;
    while(!listaVacia(listaAux2))
    {
        vehiculoAux=getCabecera(listaAux2);
    ///Copiamos el contenido de cada elemento
        vehiculoOriginal=crearVehiculo(getTipoVehiculo(vehiculoAux),
                                       getMarca(vehiculoAux),
                                       getModelo(vehiculoAux),
                                       getPatente(vehiculoAux));
     ///Agregamos el dato original a la lista
        agregarDatoLista(listaOriginal,(VehiculoPtr)vehiculoOriginal);
        listaAux2=getResto(listaAux2);
    }
    listaAux2=destruirLista(listaAux2,false);

    do
    {
        printf("EMITIR LISTADO DE VEHICULOS\n");
        printf("\n-----------------------------------------\n\n");
        printf("1. Ordenados por Marca\n");
        printf("2. Ordenados por Marca y Modelo\n");
        printf("3. SIN ORDENAR\n");
        printf("0. Volver\n");
        printf("-1. MENU PRINCIPAL");
        printf("\n-----------------------------------------\n\n");
        printf("Elija una opcion: ");
        scanf("%d",&op);
        limpiarBufferTeclado();
        system("cls");
        switch(op)
        {
        case 1:
            printf("LISTADO DE VEHICULOS (ORDENADOS POR MARCA)");
            ordenarVehiculos(centroLogistico,1);
            break;
        case 2:
            printf("LISTADO DE VEHICULOS (ORDENADOS POR MARCA Y MODELO)");
            ordenarVehiculos(centroLogistico,2);
            break;
        case 3:
            printf("LISTADO DE VEHICULOS (SIN ORDENAR)");
            break;
        case 0:
            break;
        case -1:
            opMenuAnterior=0;
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            break;
        }
        if(op>=1 && op<=2) //Si se ordenó la lista
        {
            listaAux2=crearLista();
            agregarLista(listaAux2,getVehiculos(centroLogistico));
        ///Recorremos la lista: antes y después de hacer el cambio
            while(!listaVacia(listaAux2))
            {
                vehiculoAux=getCabecera(listaAux2);
                vehiculoOriginal=getCabecera(listaOriginal);
            ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
                if(!vehiculosIguales(vehiculoOriginal,vehiculoAux))
                    cambioDetectado=true;

                listaAux2=getResto(listaAux2);
                listaOriginal=getResto(listaOriginal);
            }
            listaAux2=destruirLista(listaAux2,false); //Destruimos ambas listas, ya no las necesitamos más
            listaOriginal=destruirLista(listaOriginal,true); //Como en esta copiamos los contenidos, ponemos true para removerlos.
        }
        if(!(op==0 && op==-1))
        {
            printf("\n-----------------------------------------------------\n\n");
            mostrarVehiculos(centroLogistico);
            printf("\n-----------------------------------------------------\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(!(op==0 && op==-1));

    if(cambioDetectado)
    {
        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&op);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1:
                if(guardarVehiculos(centroLogistico))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
                }
                else
                {
                    printf("ERROR AL GUARDAR\n\n");
                    exit(1);
                }
                break;
            case 0:
                break;
            default:
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(op!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }

    return cambiosGuardados;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE REPARTOS///
///-----------------------------------------------------------------------------------------------------------///

bool menuArmarReparto(CentroLogisticoPtr centroLogistico)
{
    RepartoPtr reparto;
    int n=0;
    int k=0;
    PersonaPtr choferElegido;
    VehiculoPtr vehiculoElegido;

    FechaPtr fechaSalida;
    FechaPtr fechaRetorno;

    PilaPtr pilaPaquetesElegidos=crearPila();
    int cantPaquetesElegidos=0;
    PaquetePtr paqueteElegido;

    bool cambiosGuardados=false;
    bool continuar=true;

    do
    {
        do
        {
            printf("ARMAR REPARTO\n\n");
            printf("Ingrese cantidad de repartos a armar: ");
            scanf("%d",&n);
            limpiarBufferTeclado();

            if(n<1)
                printf("\nCantidad incorrecta.\n");
            presionarEnterYLimpiarPantalla();
        } while(n<1);

        int longLista=0;
        int i=0;
        while(i<n && continuar)
        {
            if(n>1)
                printf("\n\nREPARTO %d\n\n",i+1);
            do
            { //Cargamos el chofer
                longLista = longitudLista(getPersonas(centroLogistico));

                mostrarPersonas(centroLogistico,1);
                printf("\n\nSeleccione un chofer ingresando su indice: ");
                scanf("%d",&k);
                limpiarBufferTeclado();

                choferElegido=(PersonaPtr)getDatoLista(getPersonas(centroLogistico),k-1);

                if(k>0 && k<longLista && !getEsChofer(choferElegido))
                    printf("\n\nERROR: el indice ingresado no corresponde a un chofer. Vuelva a elegir.\n\n");
                else if(k<=0 || k>=longLista)
                    printf("\n\nERROR: indice inexistente. Vuelva a elegir.\n\n");

                system("cls");
            } while(k<=0 || k>=longLista || !getEsChofer(choferElegido));

            presionarEnterYLimpiarPantalla();

            do
            {
                longLista = longitudLista(getVehiculos(centroLogistico));

                mostrarVehiculos(centroLogistico);
                printf("\n\nSeleccione un vehiculo ingresando su indice: ");
                scanf("%d",&k);
                limpiarBufferTeclado();

                if(k<=0 || k>=longLista)
                    printf("\n\nERROR: indice inexistente. Vuelva a elegir.\n\n");

                system("cls");
            } while(k<=0 || k>=longLista);

            vehiculoElegido=getDatoLista(getVehiculos(centroLogistico),k-1);
            presionarEnterYLimpiarPantalla();

            printf("\n\nFecha de salida:");
            cargarFecha(fechaSalida);
            printf("\n\nFecha de retorno:");
            cargarFecha(fechaRetorno);

            presionarEnterYLimpiarPantalla();

            do
            {
                printf("Ingrese cantidad de paquetes a agregar al reparto: ");
                scanf("%d",&cantPaquetesElegidos);
                if(n<1)
                {
                    printf("\n\nERROR: cantidad incorrecta. Vuelva a ingresar.\n\n");
                    presionarEnterYLimpiarPantalla();
                }
            } while(n<1);

            for(int j=0;j<cantPaquetesElegidos;j++)
            {
                do
                {
                    mostrarPaquetes(centroLogistico);
                    if(cantPaquetesElegidos>1)
                        printf("\n\nPaquete N. %d\n",j+1);

                    printf("Seleccione el paquete a cargar ingresando su indice: ");
                    scanf("%d",&k);
                    limpiarBufferTeclado();

                    if(k<=0 || k>=longLista)
                        printf("\n\nERROR: indice inexistente. Vuelva a elegir.\n\n");
                    system("cls");
                } while(k<=0 || k>=longLista);

                paqueteElegido=getDatoLista(getPaquetes(centroLogistico),k-1);
                apilar(pilaPaquetesElegidos,(PaquetePtr)paqueteElegido);
            }


            reparto=armarReparto(choferElegido,vehiculoElegido,fechaSalida,fechaRetorno,pilaPaquetesElegidos);
            agregarReparto(centroLogistico,reparto,true);

            printf("\n\nReparto armado exitosamente.\n\n");
            presionarEnterYLimpiarPantalla();
            i++;

            continuar=menuContinuar();
        }
        if(n>1)
            printf("Repartos cargados exitosamente.\n\n");

        continuar=menuContinuar();
    } while(continuar);

    int opGuardar=0;
    do
    {
        printf("Guardar cambios? 1=SI , 0=NO | ");
        scanf("%d",&opGuardar);
        limpiarBufferTeclado();
        system("cls");
        switch(opGuardar)
        {
        case 1:
            if(guardarRepartos(centroLogistico,true))
            {
                cambiosGuardados=true;
                printf("Cambios guardados exitosamente.\n\n");
            }
            else
            {
                printf("ERROR AL GUARDAR\n\n");
                exit(1);
            }
            break;
        case 0:
            break;
        default:
            printf("Opcion incorrecta.\n\n");
            break;
        }
        if(opGuardar!=0)
            presionarEnterYLimpiarPantalla();
    } while(opGuardar!=0);

    return cambiosGuardados;
}

bool menuCerrarReparto(CentroLogisticoPtr centroLogistico,int opMenuAnterior)
{
    int vec[10];
    bool cambiosGuardados=false;
    bool continuar;

/// ////////////////////////////////////////////////////////////////////////////////// ///
    int modoAccion = menuModoAccion(opMenuAnterior);
    if(!(modoAccion==0 && modoAccion==-1))
    {
    //para el modo de accion 1,
        int indice;
        RepartoPtr repartoCerrar;
    //para el modo de accion 2,
        int nIndices;
        int *indices;
    //para el modo de accion 3,
        int desde=0,hasta=0;
    //para los modos de accion 2 y 3,
        RepartoPtr *repartosCerrar;
/// ////////////////////////////////////////////////////////////////////////////////// ///
        do
        {
            bool existeEnCerrados=false;

            ListaPtr listaAux=getRepartos(centroLogistico,true);
            do
            {
                mostrarRepartos(centroLogistico,true);
                if(modoAccion==1)
                {
                    printf("CERRAR REPARTO\n");
                    printf("\n-----------------------------------------\n\n");
                    printf("Reparto a cerrar:");
                    indice = menuModoAccion1(listaAux);

                    repartoCerrar=(RepartoPtr)getDatoLista(getRepartos(centroLogistico,false),indice);
                    existeEnCerrados = esRepartoExistente(centroLogistico,repartoCerrar,false);
                    if(existeEnCerrados)
                    {
                        printf("\n\nERROR: el reparto seleccionado ya existe en la lista de repartos cerrados.\n\n");
                        presionarEnterYLimpiarPantalla();
                    }
                }
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
                else if(modoAccion==2)
                {
                    printf("CERRAR REPARTOS\n");
                    printf("\n-----------------------------------------\n\n");
                    printf("Repartos a cerrar:");
                    menuModoAccion2(listaAux,nIndices,&vec);
                    int i=0;
                    while(i<nIndices && !existeEnCerrados)
                    {
                        repartosCerrar[i]=(RepartoPtr)getDatoLista(getRepartos(centroLogistico,false),indices[i]);
                        if(esRepartoExistente(centroLogistico,repartoCerrar,false))
                            existeEnCerrados=true;
                        i++;
                    }
                    if(existeEnCerrados)
                    {
                        printf("\n\nERROR: hay repartos seleccionados que ya existen en la lista de repartos cerrados.\n\n");
                        presionarEnterYLimpiarPantalla();
                    }
                }
                else
                {
                    printf("CERRAR REPARTOS\n");
                    printf("\n-----------------------------------------\n\n");
                    printf("Repartos a cerrar:");
                    menuModoAccion3(listaAux,&vec);
                    int i=desde;
                    while(i<=hasta && !existeEnCerrados)
                    {
                        repartosCerrar[i]=(RepartoPtr)getDatoLista(getRepartos(centroLogistico,false),i);
                        if(esRepartoExistente(centroLogistico,repartoCerrar,false))
                            existeEnCerrados=true;
                        i++;
                    }
                    if(existeEnCerrados)
                    {
                        printf("\n\nERROR: hay repartos seleccionados que ya existen en la lista de repartos cerrados.\n\n");
                        presionarEnterYLimpiarPantalla();
                    }
                }
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
            }while(existeEnCerrados);

            if(modoAccion==1)
            {
                cerrarReparto(centroLogistico,indice);
                printf("\n-----------------------------------------\n\n");
                printf("Reparto cerrado exitosamente.\n\n");
            }
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
            else if(modoAccion==2)
            {
                for(int i=0,j=0;i<nIndices;i++,j++)
                    cerrarReparto(centroLogistico,indices[i]-j);
                printf("\n-----------------------------------------\n\n");
                printf("Repartos cerrados exitosamente.\n\n");
            }
            else
            {
                for(int i=desde;i<=hasta;i++)
                    cerrarReparto(centroLogistico,desde);
                printf("\n-----------------------------------------\n\n");
                printf("Repartos cerrados exitosamente.\n\n");
            }
            continuar=menuContinuar();
/// //////////////////////////////////////////////////////////////////////////////////////////// ///
        } while(continuar);
    ///Como sí o sí vamos a hacer un cambio, no se necesita detectarlos en este menú.
        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&opGuardar);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1: //Sobreescribimos los cambios en las 2 listas de repartos
                if(guardarRepartos(centroLogistico,true) && guardarRepartos(centroLogistico,false))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
                }
                else
                {
                    printf("ERROR AL GUARDAR\n\n");
                    exit(1);
                }
                break;
            case 0:
                break;
            default:
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(opGuardar!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }

    return cambiosGuardados;
}

bool menuEliminarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto,int opMenuAnterior)
{
    int vec[10];
    bool cambiosGuardados=false;
    bool continuar;

    ListaPtr listaAux = getRepartos(centroLogistico,esRepartoAbierto);

    if(listaVacia(listaAux))
        printf("ERROR: Lista vacía. Debe agregar repartos para poder eliminarlos.\n\n");
    else
    {
/// ////////////////////////////////////////////////////////////////////////////////// ///
        int modoAccion = menuModoAccion(opMenuAnterior);
        if(!(modoAccion==0 && modoAccion==-1))
        {
        //para el modo de accion 1,
            int indice;
        //para el modo de accion 2,
            int nIndices;
            int *indices;
        //para el modo de accion 3,
            int desde=0,hasta=0;
/// ////////////////////////////////////////////////////////////////////////////////// ///
            if(modoAccion==1)
            {
                if(esRepartoAbierto)
                    printf("ELIMINAR REPARTO ABIERTO\n");
                else
                    printf("ELIMINAR REPARTO CERRADO\n");
                mostrarRepartos(centroLogistico,esRepartoAbierto);
                printf("\n-----------------------------------------\n\n");
                printf("Reparto a remover: ");
                indice=menuModoAccion1(listaAux);
            //Obtenemos y destruimos el elemento seleccionado
                destruirReparto(removerReparto(centroLogistico,indice,esRepartoAbierto));
            }
            else if(modoAccion==2)
            {
                if(esRepartoAbierto)
                    printf("ELIMINAR REPARTOS ABIERTOS\n");
                else
                    printf("ELIMINAR REPARTOS CERRADOS\n");
                mostrarRepartos(centroLogistico,esRepartoAbierto);
                printf("\n-----------------------------------------\n\n");
                printf("Repartos a remover: ");
                menuModoAccion2(listaAux,nIndices,&vec);
            //Obtenemos y destruimos los elementos seleccionados
                /* Funcionamiento
                1 2 5 9 12
                elimino 1
                2 5 9 12 => 1 4 8 11
                elimino 1
                4 8 11 => 3 7 10
                elimino 3
                7 10 => 6 9
                elimino 6
                9 => 8
                elimino 8

                *************************

                llegamos al límite del vector, termino de iterar.
                */

                for(int i=0,j=0;i<nIndices;i++,j++)
                    destruirReparto(removerReparto(centroLogistico,indices[i]-j,esRepartoAbierto));
            }
            else
            {
                if(esRepartoAbierto)
                    printf("ELIMINAR REPARTOS ABIERTOS\n");
                else
                    printf("ELIMINAR REPARTOS CERRADOS\n");
                mostrarRepartos(centroLogistico,esRepartoAbierto);
                printf("\n-----------------------------------------\n\n");
                printf("Repartos a remover: ");
                menuModoAccion3(listaAux,&vec);
            //Obtenemos y destruimos los elementos en el rango de indices
                for(int i=desde;i<=hasta;i++)
                    destruirReparto(removerReparto(centroLogistico,desde,esRepartoAbierto));
            }

            continuar=menuContinuar();
        } while(continuar);

        int opGuardar=0;
        do
        {
            printf("Guardar cambios? 1=SI , 0=NO | ");
            scanf("%d",&opGuardar);
            limpiarBufferTeclado();
            system("cls");
            switch(opGuardar)
            {
            case 1:
                if(guardarRepartos(centroLogistico,esRepartoAbierto))
                {
                    cambiosGuardados=true;
                    printf("Cambios guardados exitosamente.\n\n");
                }
                else
                {
                    printf("ERROR AL GUARDAR\n\n");
                    exit(1);
                }
                break;
            case 0:
                break;
            default:
                printf("Opcion incorrecta.\n\n");
                break;
            }
            if(opGuardar!=0)
                presionarEnterYLimpiarPantalla();
        } while(opGuardar!=0);
    }
    return cambiosGuardados;
}

void menuBuscarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    int i=0;
    int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));
    RepartoPtr repartoBuscar;
    bool continuar;

    if(listaVacia(getRepartos(centroLogistico,esRepartoAbierto)))
        printf("ERROR: Lista vacia. No hay repartos para buscar\n");
    else
    {
        do
        {
            presionarEnterYLimpiarPantalla();
            printf("Seleccione un reparto para buscar mediante su indice: ");
            scanf("%d",&i);
            if(i>=0 && i<n)
            {
                repartoBuscar=getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),i-1);
                mostrarReparto(repartoBuscar);
            }else
                printf("Reparto inexistente\n");

            continuar=menuContinuar();
        } while(continuar);
    }
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE CENTRO LOGISTICO///
///-----------------------------------------------------------------------------------------------------------///

CentroLogisticoPtr menuCrearNuevoCtroLogRapido(CentroLogisticoPtr ctroLog)
{
    char nuevoNombre[100];

    printf("INGRESE EL NOMBRE DEL CENTRO LOGISTICO: ");
    scanf("%[^\n]%*c",nuevoNombre);

    ctroLog=crearCentroLogisticoRapido(nuevoNombre);

    return ctroLog;
}

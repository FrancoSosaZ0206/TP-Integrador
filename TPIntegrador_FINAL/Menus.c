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
#include "TDARepartos.h"

///--------------------------------------------------------------------------------------------------------------------------
                                            ///FUNCIONES DE MENUES AYUDANTES///
///--------------------------------------------------------------------------------------------------------------------------

int menuGuardarCambios()
{
    int opGuardar=0;
    do
    {
        printf("\n\n\t Guardar cambios? \n\n");
        printf("\t     [0 = NO] \n");
        printf("\t     [1 = SI] \n");
        printf("\n\t   Opcion: ");
        limpiarBufferTeclado();
        scanf("%d",&opGuardar);
        limpiarBufferTeclado();
        if(opGuardar != 0 && opGuardar != 1)
        {
            printf("\n\t [Usted ha ingresado una opcion invalida] \n");
            printf("\n\t [Reingrese una opcion valida] \n");
        }
    }while(opGuardar != 0 && opGuardar != 1);
    system("cls");
    return opGuardar;
}

bool menuContinuar()
{
    int eleccion;
    do
    {
        printf("\n\n\t Desea continuar? \n\n");
        printf("\t     [0. NO] \n");
        printf("\t     [1. SI] \n");
        printf("\n\t   Opcion: ");
        eleccion = seleccionarNumero();
        if(eleccion != 0 && eleccion != 1)
        {
            printf("\n\t [Usted ha ingresado una opcion invalida] \n");
            printf("\n\t [Reingrese una opcion valida] \n");
        }
    } while(eleccion < 0 || eleccion > 1);
    if(eleccion == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int menuModoAccion()
{
    system("cls");
    int eleccion = 0;
    do
    {
        printf("Accion:\n");
        printf("1. Sobre un indice unico [Ej: Posicion 1]\n");
        printf("2. Sobre conjunto de indices [Ej: Posiciones 1,18,4,25,7,6] (*)\n");
        printf("3. Sobre rango de indices [Ej: Posiciones 1 - 4 (1,2,3,4)]\n");
        printf("\n-------------------------------------------------------------\n");
        printf("Opcion: ");
        eleccion = seleccionarNumero();
        if(eleccion<1 || eleccion>3)
        {
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
        }
    } while(eleccion<1 || eleccion>3);
    system("cls");
    return eleccion;
}

int menuModoAccion1(ListaPtr lista)
{
    int eleccion = 0;
    int tamanioLista = longitudLista(lista);
    do
    {
        printf("\n\nIngrese indice donde tomar accion: ");
        eleccion = seleccionarNumero();
        if(eleccion < 1 || eleccion > tamanioLista)
        {
            printf("\t(Indice inexistente)\n");
        }
    } while(eleccion <= 0 || eleccion > tamanioLista);
    eleccion--;
    return eleccion;
}

void menuModoAccion2(ListaPtr lista, int cantIndices,int* indices)
{
    int tamanioLista = longitudLista(lista);
    //Elegimos los indices
    for(int i = 0;i < cantIndices+1;i++)
    {
        printf("\nElemento %d", i+1);
        indices[i] = menuModoAccion1(lista);
    }
    int Salto = round(tamanioLista / 2);
    bool cambios = true;
    while(Salto > 0)
    {
        cambios = false;
        for(int i=0; i< (tamanioLista - Salto); i++)
        {
            if(indices[i] > indices[i+1])
            {
                int aux = indices[i];
                indices[i] = indices[i+1];
                indices[i+1] = aux;
                cambios = true;
            }
        }
        if(!cambios)
        {
            Salto = round(Salto / 2);
        }
    }
}

void menuModoAccion3(ListaPtr lista,int* vec)
{
    int desde = 0;
    int hasta = 0;
    int tamanioLista = longitudLista(lista);
    printf("Indice minimo: \n");
    desde = menuModoAccion1(lista);
    printf("Indice maximo: \n");
    hasta = menuModoAccion1(lista);
    if(vec[0] > vec[1])
    {
        int aux = vec[0];
        vec[0] = vec[1];
        vec[1] = aux;
    }
    //El sistema permite que desde y hasta sean iguales si la lista tiene solo 1 elemento.
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

void notificacionListaVacia(ListaPtr ListaAnalizar)
{
    if( listaVacia(ListaAnalizar)  )
    {
        printf("\n\n\t [Se ha salido del menu de eliminacion debido que no existen elementos] \n");
        printf("\t [Para eliminar, debe agregar mas para poder continuar] \n\n");
        presionarEnterYLimpiarPantalla();
    }
}


///--------------------------------------------------------------------------------------------------------------------------
                                ///FUNCIONES DE CARGA DE DATOS BASICOS///
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

        if(!esCuilValido(cuil))
        {
            printf("\n\t [Usted no ha ingresado un cuil en un formato valido] \n");
            printf("\t [Debera reingresar un cuil hasta que ingrese uno valido] \n\n");
            presionarEnterYLimpiarPantalla();
        }

    } while(!esCuilValido(cuil));
    return cuil;
}

DomicilioPtr cargarDomicilio(DomicilioPtr domicilio)
{
    char calle[100];
    int altura;
    char localidad[100];

    limpiarBufferTeclado();
    printf("\n\n\t\t Calle: ");
    scanf("%[^\n]%*c",calle);

    limpiarBufferTeclado();
    printf("\n\t\t Altura: ");
    scanf("%d",&altura);

    limpiarBufferTeclado();
    printf("\n\t\t Localidad: ");
    scanf("%[^\n]%*c",localidad);

    domicilio=crearDomicilio(calle,altura,localidad);

    return domicilio;
}

FechaPtr cargarFecha(FechaPtr fecha)
{
    int dia=0,mes=0,anio=0,hora=0,minuto=0;
    fecha=crearFecha(dia,mes,anio,hora,minuto);
    do
    {
        printf("\n\n\t\t Fecha (DD MM AAAA) ---- Horario (HH MM): ");
        limpiarBufferTeclado();
        scanf("%d %d %d %d %d",&dia,&mes,&anio,&hora,&minuto);
        limpiarBufferTeclado();

        setDia(fecha,dia);
        setMes(fecha,mes);
        setAnio(fecha,anio);
        setHora(fecha,hora);
        setMinuto(fecha,minuto);

        if( !esFechaValida(fecha) )
        {
            printf("\n\t [Usted no ha ingresado una fecha con el formato apropiado] \n");
            printf("\t [Debera reingresar la fecha, hasta que ingrese una fecha en condiciones] \n\n");
            presionarEnterYLimpiarPantalla();
        }

    }while(!esFechaValida(fecha));
    return fecha;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE ACTUALIZACION DE DATOS BASICOS///
///-----------------------------------------------------------------------------------------------------------///

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

    setCalle(domicilio,calle);
    setAltura(domicilio,altura);
    setLocalidad(domicilio,localidad);
}

void actualizarFecha(FechaPtr fecha)
{
    int dia=0,mes=0,anio=0,hora=0,minuto=0;
    do
    {
        limpiarBufferTeclado();
        printf("\n\t\tFecha (DD MM AAAA) --- Horario (HH MM): ");
        scanf("%d %d %d %d %d",&dia,&mes,&anio,&hora,&minuto);
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
                                ///SECCION DE CARGADO DE DATOS COMPLEJOS///
///-----------------------------------------------------------------------------------------------------------///

bool menuCargarPaquete(CentroLogisticoPtr centroLogistico)
{
    PaquetePtr paquete;
    ///el ID del paquete se genera automáticamente, no lo tiene que ingresar el usuario.
    int ID=0,ancho=0,alto=0,largo=0,peso=0,i=1,resultado=0;
    FechaPtr fechaEntrega;
    DomicilioPtr dirRetiro;
    DomicilioPtr dirEntrega;
    PersonaPtr persona;
    ///por defecto, los paquetes se cargan con el estado 0: 'en depósito'.
    srand(time(NULL));
    bool cambiosGuardados=false, continuar;
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
            printf("PAQUETE %d\n\n",i++);

            ///esto no se mostrará sino al final de la carga del paquete.
            ID=rand();

            limpiarBufferTeclado();
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

            printf("\n\tDireccion de retiro:");
            dirRetiro=cargarDomicilio(dirRetiro);

            printf("\n\tDireccion de entrega:");
            dirEntrega=cargarDomicilio(dirEntrega);

            printf("\n\tFecha de entrega:");
            fechaEntrega=cargarFecha(fechaEntrega);

            system("cls");

            printf("Elegir destinatario\n");
            persona = menuBusquedaCliente(centroLogistico);

            paquete=crearPaquete(ID,ancho,alto,largo,peso,dirRetiro,dirEntrega,fechaEntrega,persona,0);
            agregarPaquete(centroLogistico,paquete);

            continuar=menuContinuar();
        } while(continuar);
        resultado=menuGuardarCambios();
        if(resultado==1)
        {
            cambiosGuardados=guardarPaquetes(centroLogistico);
        }
    }
    return cambiosGuardados;
}

bool menuCargarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    char nombre[100];
    char apellido[100];
    PersonaPtr persona=0;
    CuilPtr cuil=0;
    DomicilioPtr domicilio=0;
    int i=1,resultado=0;
    bool cambiosGuardados=false, continuar;
    do
    {
        system("cls");
        if(esChofer){printf("Chofer %d \n", i++);}
        else{printf("Cliente %d \n", i++);}

        limpiarBufferTeclado();
        printf("\n\t Nombre: ");
        scanf("%[^\n]%*c",nombre);

        limpiarBufferTeclado();
        printf("\n\t Apellido: ");
        scanf("%[^\n]%*c",apellido);

        limpiarBufferTeclado();
        printf("\n\t Domicilio ");
        domicilio=cargarDomicilio(domicilio);

        cuil=cargarCuil(cuil);

        persona=crearPersona(nombre,apellido,domicilio,cuil,esChofer);
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
        printf("\n\tMarca: ");
        scanf("%[^\n]%*c",marca);

        limpiarBufferTeclado();
        printf("\n\tModelo: ");
        scanf("%[^\n]%*c",modelo);

        limpiarBufferTeclado();
        printf("\n\tPatente (AA 000 AA): ");
        scanf("%[^\n]%*c",patente);

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
            printf("Ingrese ID del paquete a buscar: ");
            scanf("%d",&ID);
            limpiarBufferTeclado();
            printf("\n\n");
            if(!buscarPaquete(centroLogistico,ID))
            {
                printf("\n\nNo se pudo encontrar el paquete con ID #%d.\n\n",ID);
            }
            continuar=menuContinuar();
        }while(continuar);
    }
}

void menuBuscarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    bool continuar;
    char cuilStr[100];
    if(listaVacia(getPersonas(centroLogistico)))
    {
        if(esChofer)
        {
             printf("ERROR: Lista vacia. No hay choferes para buscar\n");
             presionarEnterYLimpiarPantalla();
        }
        else
        {
            printf("ERROR: Lista vacia. No hay clientes para buscar\n");
            presionarEnterYLimpiarPantalla();
        }
    }
    else
    {
        do
        {
            system("cls");
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
            scanf("%[^\n]%*c",cuilStr);
            printf("\n\n");

            if(!buscarPersona(centroLogistico,cuilStr,esChofer))
            {
                if(esChofer)
                {
                    printf("\n\nNo se pudo encontrar el chofer con CUIL %s.\n\n",cuilStr);
                }
                else
                {
                    printf("\n\nNo se pudo encontrar el cliente con CUIL %s.\n\n",cuilStr);
                }
            }
            continuar=menuContinuar();
        } while(continuar);
    }
}

void menuBuscarVehiculo(CentroLogisticoPtr centroLogistico)
{
    bool continuar;
    if(listaVacia(getVehiculos(centroLogistico)))
    {
        printf("ERROR: Lista vacia. No hay vehiculos para buscar\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            system("cls");
            char patente[100];
            printf("BUSCAR VEHICULO\n\n");
            printf("Ingrese la patente del vehiculo a buscar (AA 111 AA): ");
            scanf("%[^\n]%*c",patente);
            if(!buscarVehiculo(centroLogistico,patente))
            {
                printf("\n\nNo se pudo encontrar el vehiculo con patente %s.\n\n",patente);
            }
            continuar=menuContinuar();
        } while(continuar);
    }
}

int menuTipoBusquedaCliente()
{
   int eleccion = 0;
   system("cls");
   printf("MENU DE SELECCION DE CLIENTE DE PAQUETE \n");
   printf("1. Seleccion mediante INDICE \n");
   printf("2. Seleccion mediante CUIL \n");
   printf("OPCION: ");
   eleccion = seleccionarNumero();
   return eleccion;
}

PersonaPtr menuBusquedaCliente(CentroLogisticoPtr centroLogistico)
{
    int MENU = 0;
    int ELECCION = 0;
    char CuilBuscar[100];
    PersonaPtr PersonaBuscada;
    if(listaVacia(getPersonas(centroLogistico)))
    {
        printf("Lista vacia, no existen clientes para mostrar\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        MENU = menuTipoBusquedaCliente();
        mostrarPersonas(centroLogistico, 2);
        switch(MENU)
        {
        case 1:
            do{
                ELECCION = menuModoAccion1( getPersonas(centroLogistico) );
                PersonaBuscada = getDatoLista( getPersonas(centroLogistico), ELECCION );
                if( getEsChofer(PersonaBuscada) )
                {
                    printf("\t (Debe eligir un cliente, no un chofer, eliga debidamente) \n");
                }
            }while(getEsChofer(PersonaBuscada));
            break;
        case 2:
            do{
                printf("\n Ingrese el cuil a buscar: ");
                seleccionarString(CuilBuscar);
                PersonaBuscada = devolverPersona(centroLogistico, CuilBuscar);
                if( getEsChofer(PersonaBuscada) )
                {
                    printf("\t (Debe eligir un cliente, no un chofer, eliga debidamente) \n");
                }
            }while( PersonaBuscada == NULL || getEsChofer(PersonaBuscada) );
            break;
        default:
            printf("Opcion equivocada... \n");
            break;
        }
    }
    return PersonaBuscada;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE ELIMINACION///
///-----------------------------------------------------------------------------------------------------------///

bool menuEliminarPaquete(CentroLogisticoPtr centroLogistico)
{
    int opcion=0;
    bool cambiosGuardados=false;
    bool continuar = true;
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int indices[100];
    int cantIndices=0;
    PaquetePtr paqueteRemovido=(PaquetePtr)obtenerMemoria(sizeof(Paquete));
    do
    {
        if( listaVacia( getPaquetes(centroLogistico) ) )
        {
            printf("ERROR: Lista vacia. Debe agregar paquetes para poder eliminarlos.\n\n");
            presionarEnterYLimpiarPantalla();
        }
        else
        {
            EleccionMenuModoAccion = menuModoAccion();
            mostrarPaquetes(centroLogistico);
            printf("ELIMINAR PAQUETE\n\n");
            switch(EleccionMenuModoAccion)
            {
            case 1:
                EleccionAccion = menuModoAccion1( getPaquetes(centroLogistico) );
                paqueteRemovido = removerPaquete(centroLogistico, EleccionAccion);
                paqueteRemovido = destruirPaquete(paqueteRemovido);
                cambiosGuardados = true;
                break;
            case 2:
                printf("[ACLARACION]Eliga la cantidad de indices...\n");
                cantIndices = menuModoAccion1( getPaquetes(centroLogistico) );
                menuModoAccion2( getPaquetes(centroLogistico), cantIndices, indices );
                for(int i=0;i<cantIndices;i++)
                {
                    paqueteRemovido = removerPaquete(centroLogistico,indices[i]-i);
                    paqueteRemovido = destruirPaquete(paqueteRemovido);
                }
                cambiosGuardados = true;
                break;
            case 3:
                menuModoAccion3( getPaquetes(centroLogistico) , indices );
                for(int i=0;i<indices[1]-indices[0]+1;i++)
                {
                    paqueteRemovido = removerPaquete(centroLogistico,indices[0]);
                    paqueteRemovido = destruirPaquete(paqueteRemovido);
                }
                cambiosGuardados = true;
                break;
            default:
                printf("Eleccion equivocada \n");
                break;
            }
            continuar = menuContinuar();
        }
    }while(continuar == true && !listaVacia( getPaquetes(centroLogistico) ) );
    notificacionListaVacia( getPaquetes(centroLogistico) );
    if( cambiosGuardados )
    {
        opcion = menuGuardarCambios();
        if(opcion == 1)
        {
            cambiosGuardados = guardarPaquetes(centroLogistico);
        }
    }
    return cambiosGuardados;
}

bool verificarExistenciaPersonas(CentroLogisticoPtr centroLogistico, bool esChofer)
{
    bool Existen = false;
    ListaPtr ListaAuxiliar = crearLista();
    agregarLista(ListaAuxiliar, getPersonas(centroLogistico));
    while(!listaVacia(ListaAuxiliar))
    {
        if(esChofer)
        {
            if(getEsChofer(getCabecera(ListaAuxiliar)))
            {
                Existen = true;
            }
        }
        if(!esChofer)
        {
            if(!getEsChofer(getCabecera(ListaAuxiliar)))
            {
                Existen = true;
            }
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    return Existen;
}

bool eliminarPersona(CentroLogisticoPtr centroLogistico, bool esChofer)
{
    bool cambiosGuardados = false;
    bool continuar;
    int EleccionMenuModoAccion=0;
    int EleccionAccion=0;
    int cantidadCorrectas=0;
    int cantIndices=0;
    int opcion=0;
    int indices[100];
    PersonaPtr personaRemovida;
    EleccionMenuModoAccion = menuModoAccion();
    if(esChofer)
    {
        mostrarPersonas(centroLogistico, 1);
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
        EleccionAccion = menuModoAccion1(getPersonas(centroLogistico));
        if(getEsChofer( getDatoLista(getPersonas(centroLogistico), EleccionAccion) ) == esChofer)
        {
            personaRemovida = removerPersona(centroLogistico, EleccionAccion);
            personaRemovida = destruirPersona(personaRemovida);
            cambiosGuardados = true;
        }
        else
        {
            printf("\n\t [Ha elegido un tipo de persona inadecuado...] \n\n");
        }
        break;
    case 2:
        cantidadCorrectas = 0;
        printf("[ACLARACION]Eliga la cantidad de indices...\n");
        cantIndices = menuModoAccion1( getPersonas(centroLogistico) );
        menuModoAccion2( getPersonas(centroLogistico) , cantIndices, indices);
        for(int i=0;i<cantIndices;i++)
        {
            if(getEsChofer(getDatoLista(getPersonas(centroLogistico),indices[i])) == esChofer)
            {
                cantidadCorrectas++;
            }
        }
        if(cantidadCorrectas == cantIndices)
        {
            for(int i=0;i<cantIndices;i++)
            {
                personaRemovida = removerPersona(centroLogistico,indices[i]-i);
                personaRemovida = destruirPersona(personaRemovida);
            }
            cambiosGuardados = true;
        }
        else
        {
            printf("\n\t [Ha elegido un tipo de persona inadecuado...] \n\n");
        }
        break;
    case 3:
        cantidadCorrectas=0;
        menuModoAccion3(getPersonas(centroLogistico),indices);
        for(int i=indices[0];i<indices[1]+1;i++)
        {
            if(getEsChofer(getDatoLista(getPersonas(centroLogistico),i)) == esChofer)
            {
                cantidadCorrectas++;
            }
            cambiosGuardados = true;
        }
        if(cantidadCorrectas == indices[1]-indices[0]+1)
        {
            for(int i=indices[0];i<indices[1]+1;i++)
            {
                personaRemovida = removerPersona(centroLogistico,indices[0]);
                personaRemovida = destruirPersona(personaRemovida);
            }
        }
        else
        {
            printf("\n\t [Ha elegido un tipo de persona inadecuado...] \n\n");
        }
        break;
    default:
        printf("Eleccion equivocada \n");
        break;
    }
    continuar = menuContinuar();
    return continuar;
}


bool menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    int opcion;
    bool continuar;
    bool cambiosGuardados;
    do
    {
        if(esChofer)
        {
            if( verificarExistenciaPersonas(centroLogistico, true) )
            {
                continuar = eliminarPersona(centroLogistico, esChofer);
            }
            else
            {
                printf("\n\t [No existen choferes para eliminar...] \n");
                presionarEnterYLimpiarPantalla();
            }
        }
        else
        {
            if( verificarExistenciaPersonas(centroLogistico, false)  )
            {
                continuar = eliminarPersona(centroLogistico, esChofer);
            }
            else
            {
                printf("\n\t [No existen clientes para eliminar...] \n");
                presionarEnterYLimpiarPantalla();
            }
        }
    } while(continuar == true && !listaVacia( getPersonas(centroLogistico) ) && verificarExistenciaPersonas(centroLogistico, esChofer) );
    if(esChofer)
    {
        if( !verificarExistenciaPersonas(centroLogistico, true) )
        {
            printf("\n\n\t [Se ha salido del menu de eliminacion debido que no existen elementos (Choferes)] \n");
            printf("\t [Para eliminar, debe agregar mas para poder continuar] \n\n");
            presionarEnterYLimpiarPantalla();
        }
    }
    else
    {
        if( !verificarExistenciaPersonas(centroLogistico, false) )
        {
            printf("\n\n\t [Se ha salido del menu de eliminacion debido que no existen elementos (Clientes)] \n");
            printf("\t [Para eliminar, debe agregar mas para poder continuar] \n\n");
            presionarEnterYLimpiarPantalla();
        }
    }
    if( cambiosGuardados )
    {
        opcion = menuGuardarCambios();
        if(opcion == 1)
        {
            cambiosGuardados = guardarPersonas(centroLogistico);
        }
    }
    return cambiosGuardados;
}

bool menuEliminarVehiculo(CentroLogisticoPtr centroLogistico)
{
    int opcion=0;
    bool cambiosGuardados=false;
    bool continuar;
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int indices[100];
    int cantIndices=0;
    VehiculoPtr vehiculoRemovido = (VehiculoPtr)obtenerMemoria(sizeof(Vehiculo));
    do
    {
        if(listaVacia(getVehiculos(centroLogistico)))
        {
            printf("ERROR: Lista vacía. Debe agregar vehiculos para poder eliminarlos.\n\n");
            presionarEnterYLimpiarPantalla();
        }
        else
        {
            EleccionMenuModoAccion = menuModoAccion(0);
            mostrarVehiculos(centroLogistico);
            printf("ELIMINAR VEHICULO \n\n");
                switch(EleccionMenuModoAccion)
                {
                    case 1:
                        EleccionAccion = menuModoAccion1(getVehiculos(centroLogistico));
                        vehiculoRemovido = removerVehiculo(centroLogistico, EleccionAccion);
                        vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
                        cambiosGuardados = true;
                        break;
                    case 2:
                        printf("[ACLARACION]Eliga la cantidad de indices...\n");
                        cantIndices = menuModoAccion1( getVehiculos(centroLogistico) );
                        menuModoAccion2(getVehiculos(centroLogistico),cantIndices,indices);
                        for(int i=0;i<cantIndices;i++)
                        {
                            vehiculoRemovido = removerVehiculo(centroLogistico,indices[i]-i);
                            vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
                        }
                        cambiosGuardados = true;
                        break;
                    case 3:
                        menuModoAccion3(getVehiculos(centroLogistico),indices);
                        for(int i=0;i<indices[1]-indices[0]+1;i++)
                        {
                            vehiculoRemovido = removerVehiculo(centroLogistico,indices[0]);
                            vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
                        }
                        cambiosGuardados = true;
                        break;
                    default:
                        printf("Eleccion equivocada \n");
                        break;
                }
            continuar=menuContinuar();
        }
    }while(continuar && !listaVacia( getVehiculos(centroLogistico) ) );
    notificacionListaVacia( getVehiculos(centroLogistico) );
    if( cambiosGuardados )
    {
        opcion = menuGuardarCambios();
        if(opcion == 1)
        {
            cambiosGuardados=guardarPersonas(centroLogistico);
        }
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
            if(nTipo > 0 && nTipo < 4)
            {
                setTipoVehiculo(vehiculoAModificar, nTipo);
            }
            else
            {
                printf("Opcion incorrecta...\n");
                presionarEnterYLimpiarPantalla();
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

bool menuModificarVehiculo(CentroLogisticoPtr centroLogistico)
{
    bool cambioDetectado=false, cambiosGuardados=false, continuar;
    int modoAccion, Cantidad, Eleccion, resultado;
    int Elecciones[10];
    VehiculoPtr vehiculoModificar;
    ListaPtr listaOriginal;
    ///------------------------------------------------------------------------------------------------------///
        listaOriginal = OriginalVehiculos(centroLogistico);
    ///------------------------------------------------------------------------------------------------------///
        if(listaVacia(getVehiculos(centroLogistico)))
        {
            printf("ERROR: Lista vacía. Debe agregar vehiculos para poder modificarlos.\n\n");
            presionarEnterYLimpiarPantalla();
        }
        else
        {
            do
            {
                modoAccion = menuModoAccion();
                mostrarVehiculos(centroLogistico);
                switch(modoAccion)
                {
                case 1:
                    Eleccion=menuModoAccion1(getVehiculos(centroLogistico));
                    vehiculoModificar=getDatoLista(getVehiculos(centroLogistico),Eleccion);
                    cambiarVehiculo(vehiculoModificar);
                    break;
                case 2:
                    printf("[ACLARACION]Eliga la cantidad de indices...\n");
                    Cantidad=menuModoAccion1(getVehiculos(centroLogistico));
                    menuModoAccion2(getVehiculos(centroLogistico),Cantidad,Elecciones);
                    for(int i=0;i<Cantidad;i++)
                    {
                        vehiculoModificar=getDatoLista(getVehiculos(centroLogistico),Elecciones[i]);
                        cambiarVehiculo(vehiculoModificar);
                    }
                    break;
                case 3:
                    menuModoAccion3(getVehiculos(centroLogistico),Elecciones);
                    for(int i=0;i<Elecciones[1]-Elecciones[0]+1;i++)
                    {
                        vehiculoModificar=getDatoLista(getVehiculos(centroLogistico),i);
                        cambiarVehiculo(vehiculoModificar);
                    }
                    break;
                default:
                    printf("Eleccion equivocada \n");
                    break;
                }
                continuar=menuContinuar();
        } while(continuar);
    }
    ///------------------------------------------------------------------------------------------------------///
        cambioDetectado = CambiosVehiculos(centroLogistico,listaOriginal);
    ///------------------------------------------------------------------------------------------------------///
    if( cambioDetectado )
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
                actualizarDomicilio(getDomicilio(personaAModificar));
            break;
            case 3:
                actualizarCuil(getCuilPersona(personaAModificar));
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

bool menuModificarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    ListaPtr listaOriginal;
    int resultado=0,modoAccion=0,Eleccion=0,Cantidad=0,cantidadCorrectas=0;
    int Elecciones[10];
    PersonaPtr personaModificar;
    bool cambiosGuardados=false, cambioDetectado=false, continuar;
    if(listaVacia(getPersonas(centroLogistico)))
    {
        if(esChofer)
        {
            printf("ERROR: Lista vacía. Debe agregar choferes para poder modificarlos.\n\n");
            presionarEnterYLimpiarPantalla();
        }
        else
        {
            printf("ERROR: Lista vacía. Debe agregar clientes para poder modificarlos.\n\n");
            presionarEnterYLimpiarPantalla();
        }
    }
    else
    {
    ///---------------------------------------------------------------------///
        listaOriginal = OriginalPersonas(centroLogistico);
    ///---------------------------------------------------------------------///
        do
        {
            modoAccion=menuModoAccion();
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
                Eleccion=menuModoAccion1(getPersonas(centroLogistico));
                if(getEsChofer(getDatoLista(getPersonas(centroLogistico),Eleccion)) == esChofer)
                {
                    personaModificar=getDatoLista(getPersonas(centroLogistico),Eleccion);
                    cambiarPersona(personaModificar,esChofer);
                }
                else
                {
                    printf("ERROR: No ha elegido correctamente \n");
                }
                break;
            case 2:
                cantidadCorrectas=0;
                printf("[ACLARACION]Eliga la cantidad de indices...\n");
                Cantidad=menuModoAccion1(getPersonas(centroLogistico));
                menuModoAccion2(getPersonas(centroLogistico),Cantidad,Elecciones);
                for(int i=0;i<Cantidad;i++)
                {
                    if(getEsChofer(getDatoLista(getPersonas(centroLogistico),Elecciones[i])) == esChofer)
                    {
                        cantidadCorrectas++;
                    }
                }
                if(cantidadCorrectas==Cantidad)
                {
                    for(int i=0;i<Cantidad;i++)
                    {
                        personaModificar=getDatoLista(getPersonas(centroLogistico),Elecciones[i]);
                        cambiarPersona(personaModificar,esChofer);
                    }
                }
                else
                {
                    printf("ERROR: No ha elegido correctamente \n");
                }
                break;
            case 3:
                cantidadCorrectas=0;
                menuModoAccion3(getPersonas(centroLogistico),Elecciones);
                for(int i=Elecciones[0];i<Elecciones[1]+1;i++)
                {
                    if(getEsChofer(getDatoLista(getPersonas(centroLogistico),i)) == esChofer)
                    {
                        cantidadCorrectas++;
                    }
                }
                if(cantidadCorrectas==Elecciones[1]-Elecciones[0]+1)
                {
                    for(int i=Elecciones[0];i<Elecciones[1]+1;i++)
                    {
                        personaModificar = getDatoLista(getPersonas(centroLogistico),i);
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

void cambiarPaquete(PaquetePtr paqueteAModificar)
{
    int nAncho,nAlto,nLargo,nPeso,nEstado,seguirMod,op;
    do
    {
        system("cls");
        printf("Ha elegido el - \n\n");
        mostrarPaquete(paqueteAModificar);
        printf("\n\nQué desea modificar?\n\n");
        printf("1. Ancho\n");
        printf("2. Alto\n");
        printf("3. Largo\n");
        printf("4. Peso\n");
        printf("5. Direccion de Retiro\n");
        printf("6. Direccion de Entrega\n");
        printf("7. Fecha de Entrega\n");
        printf("8. Estado\n");
        printf("9. Destinatario\n");
        printf("Seleccione una opcion: ");
        limpiarBufferTeclado();
        scanf("%d",&op);
        limpiarBufferTeclado();
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
            helpEstadoPaquete();
            printf("\n\nIngrese el nuevo estado: ");
            limpiarBufferTeclado();
            scanf("%d",&nEstado);
            setEstado(paqueteAModificar,nEstado);
            break;
        case 9:
            cambiarPersona(getCliente(paqueteAModificar),getEsChofer(getCliente(paqueteAModificar)));
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }
        printf("\n\nDatos modificados exitosamente.\n\n");
        printf("Desea seguir modificando este paquete?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");
        printf("Seleccione una opcion: ");
        limpiarBufferTeclado();
        scanf("%d",&seguirMod);
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
    bool cambioDetectado=false, cambiosGuardados=false, continuar;
    int modoAccion, Cantidad, Eleccion, resultado;
    int Elecciones[10];
    PaquetePtr paqueteModificar;
    ListaPtr listaOriginal;
    if(listaVacia(getPaquetes(centroLogistico)))
    {
        printf("ERROR: Lista vacía. Debe agregar paquetes para poder modificarlos.\n\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
    ///--------------------------------------------------------------------///
        listaOriginal = OriginalPaquetes(centroLogistico);
    ///--------------------------------------------------------------------///
        do
        {
            modoAccion = menuModoAccion();
            mostrarPaquetes(centroLogistico);
            switch(modoAccion)
            {
            case 1:
                Eleccion=menuModoAccion1(getPaquetes(centroLogistico));
                paqueteModificar=getDatoLista(getPaquetes(centroLogistico),Eleccion);
                cambiarPaquete(paqueteModificar);
                break;
            case 2:
                printf("[ACLARACION]Eliga la cantidad de indices...\n");
                Cantidad=menuModoAccion1(getPaquetes(centroLogistico));
                menuModoAccion2(getPaquetes(centroLogistico),Cantidad,Elecciones);
                for(int i=0;i<Cantidad;i++)
                {
                    paqueteModificar=getDatoLista(getPaquetes(centroLogistico),Elecciones[i]);
                    cambiarPaquete(paqueteModificar);
                }
                break;
            case 3:
                menuModoAccion3(getPaquetes(centroLogistico),Elecciones);
                for(int i=0;i<Elecciones[1]-Elecciones[0]+1;i++)
                {
                    paqueteModificar=getDatoLista(getPaquetes(centroLogistico),i);
                    cambiarPaquete(paqueteModificar);
                }
                break;
            default:
                printf("Eleccion equivocada \n");
                break;
            }
            continuar=menuContinuar();
        } while(continuar);
    }
    ///--------------------------------------------------------------------///
        cambioDetectado = CambiosPaquetes(centroLogistico,listaOriginal);
    ///--------------------------------------------------------------------///
    if(cambioDetectado)
    {
        resultado = menuGuardarCambios();
        if(resultado==1)
        {
            cambiosGuardados=guardarPaquetes(centroLogistico);
        }
    }
    return cambiosGuardados;
}


///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE MOSTRAR///
///-----------------------------------------------------------------------------------------------------------///


int menuTipoOrdenamientoPaquetes()
{
    int op = 0;
    system("cls");
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
    limpiarBufferTeclado();
    scanf("%d",&op);
    limpiarBufferTeclado();
    system("cls");
    return op;
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
                cambiosGuardados = true;
                break;
            case 2:
                printf("LISTADO DE PAQUETES (ORDENADOS POR FECHA DE SALIDA)");
                ordenarPaquetes(centroLogistico,2);
                cambiosGuardados = true;
                break;
            case 3:
                printf("LISTADO DE PAQUETES (ORDENADOS POR ESTADO)");
                ordenarPaquetes(centroLogistico,3);
                cambiosGuardados = true;
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

int menuTipoOrdenamientoPersonas()
{
    int op = 0;
    printf("\n-----------------------------------------\n\n");
    printf("1. Ordenados por Nombre\n");
    printf("2. Ordenados por Apellido\n");
    printf("3. Ordenados por Cuil\n");
    printf("4. SIN ORDENAR\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    scanf("%d",&op);
    limpiarBufferTeclado();
    system("cls");
    return op;
}

bool menuMostrarPersonas(CentroLogisticoPtr centroLogistico, int tipo, int* op1)
{
    int op=0;
    bool cambiosGuardados=false;
    if(listaVacia(getPersonas(centroLogistico)))
    {
        printf("Lista vacia de personas, agregue un elemento por favor\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
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
            op = menuTipoOrdenamientoPersonas();
            switch(op)
            {
            case 1:
                printf("(ORDENADO POR NOMBRE)\n");
                ordenarPersonas(centroLogistico, 1, tipo);
                cambiosGuardados = true;
                break;
            case 2:
                printf("(ORDENADO POR APELLIDO)\n");
                ordenarPersonas(centroLogistico, 2, tipo);
                cambiosGuardados = true;
                break;
            case 3:
                printf("(ORDENADO POR NOMBRE Y APELLIDO)\n");
                ordenarPersonas(centroLogistico, 3, tipo);
                cambiosGuardados = true;
                break;
            case 4:
                printf("(SIN ORDENAR)\n");
                ordenarPersonas(centroLogistico, 4, tipo);
                break;
            case 0:
                break;
            case -1:
                *op1 = 0;
                op = 0;
                break;
            default:
                printf("\nOpcion incorrecta.\n\n");
                break;
            }
        }while(op!=0 && op!=-1);
    }
    return cambiosGuardados;
}

int menuTipoOrdenamientoVehiculos()
{
    int op = 0;
    system("cls");
    printf("EMITIR LISTADO DE VEHICULOS\n");
    printf("\n-----------------------------------------\n\n");
    printf("1. Ordenados por Marca\n");
    printf("2. Ordenados por Modelo\n");
    printf("3. Ordenados por tipo\n");
    printf("4. SIN ORDENAR\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op);
    limpiarBufferTeclado();
    system("cls");
    return op;
}

bool menuMostrarVehiculos(CentroLogisticoPtr centroLogistico, int* op1)
{
    int op=0;
    bool cambiosGuardados=false;
    if(listaVacia(getVehiculos(centroLogistico)))
    {
        printf("Lista vacia de vehiculos, agregue un elemento por favor\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            op = menuTipoOrdenamientoVehiculos();
            switch(op)
            {
            case 1:
                printf("LISTADO DE VEHICULOS (ORDENADOS POR MARCA)");
                ordenarVehiculos(centroLogistico,1);
                cambiosGuardados = true;
                break;
            case 2:
                printf("LISTADO DE VEHICULOS (ORDENADOS POR MODELO)");
                ordenarVehiculos(centroLogistico,2);
                cambiosGuardados = true;
                break;
            case 3:
                printf("LISTADO DE VEHICULOS (ORDENADOS TIPO)");
                ordenarVehiculos(centroLogistico,3);
                cambiosGuardados = true;
                break;
            case 4:
                printf("LISTADO DE VEHICULOS (SIN ORDENAR)");
                ordenarVehiculos(centroLogistico,4);
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
        }while(op!=0 && op!=-1);
    }
    return cambiosGuardados;
}

///-----------------------------------------------------------------------------------------------------------///
///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE REPARTOS///
///-----------------------------------------------------------------------------------------------------------///
///-----------------------------------------------------------------------------------------------------------///

bool existenChoferesDisponibles(CentroLogisticoPtr centroLogistico)
{
    bool existen = false;
    PersonaPtr ChoferAuxiliar;
    ListaPtr ListaAuxiliar = crearLista();
    agregarLista(ListaAuxiliar, getPersonas(centroLogistico));
    while(!listaVacia(ListaAuxiliar))
    {
        ChoferAuxiliar = (PersonaPtr)getCabecera(ListaAuxiliar);
        if(!buscarChoferRepartos(centroLogistico, getCuil(getCuilPersona(ChoferAuxiliar))))
        {
            if(!getRepartoDiario(ChoferAuxiliar))
            {
                existen = true;
            }
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    return existen;
}

bool existenPaquetesDisponibles(CentroLogisticoPtr centroLogistico)
{
    bool existen = false;
    PaquetePtr PaqueteAuxiliar;
    ListaPtr ListaAuxiliar = crearLista();
    agregarLista(ListaAuxiliar, getPaquetes(centroLogistico));
    while(!listaVacia(ListaAuxiliar))
    {
        PaqueteAuxiliar = (PaquetePtr)getCabecera(ListaAuxiliar);
        if(getEstado(PaqueteAuxiliar) == 0)
        {
            existen = true;
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    return existen;
}

bool existenVehiculosDisponibles(CentroLogisticoPtr centroLogistico)
{
    bool existen = false;
    VehiculoPtr VehiculoAuxiliar;
    ListaPtr ListaAuxiliar = crearLista();
    agregarLista(ListaAuxiliar, getVehiculos(centroLogistico));
    while(!listaVacia(ListaAuxiliar))
    {
        VehiculoAuxiliar = (VehiculoPtr)getCabecera(ListaAuxiliar);
        if(!buscarVehiculoRepartos(centroLogistico, getPatente(VehiculoAuxiliar)))
        {
            existen = true;
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    return existen;
}

bool menuArmarReparto(CentroLogisticoPtr centroLogistico)
{
    RepartoPtr reparto;
    int k=0;
    int cantPaquetesElegidos=0;
    int resultado=0;
    PersonaPtr choferElegido;
    VehiculoPtr vehiculoElegido;
    FechaPtr fechaSalida=NULL;
    FechaPtr fechaRetorno=NULL;
    ListaPtr paquetes=crearLista();
    PaquetePtr paqueteElegido;
    bool ExistenDatos=true;
    bool cambiosGuardados=false;
    bool continuar;
    bool valido=false;
    bool HayChofer=false;
    if(!listaVacia(getVehiculos(centroLogistico)))
    {
        if(!existenVehiculosDisponibles(centroLogistico))
        {
            ExistenDatos=false;
            printf("Faltan vehiculos para agregar al reparto...\n");
        }
    }
    else
    {
        ExistenDatos=false;
        printf("Faltan vehiculos para agregar al reparto...\n");
    }
    if(!listaVacia(getPersonas(centroLogistico)))
    {
        if(!existenChoferesDisponibles(centroLogistico))
        {
            ExistenDatos=false;
            printf("Faltan choferes para agregar al reparto...\n");
        }
    }
    else
    {
        ExistenDatos=false;
        printf("Faltan choferes para agregar al reparto...\n");
    }
    if(!listaVacia(getPaquetes(centroLogistico)))
    {
        if(!existenPaquetesDisponibles(centroLogistico))
        {
            ExistenDatos=false;
            printf("Faltan paquetes para agregar al reparto...\n");
        }
    }
    else
    {
        ExistenDatos=false;
        printf("Faltan paquetes para agregar al reparto...\n");
    }
    if(ExistenDatos)
    {
        do
        {
            ///Cargamos el chofer
            mostrarChoferesDisponibles(centroLogistico);
            printf("\n\nSeleccione un chofer ingresando su indice: ");
            k = menuModoAccion1(getPersonas(centroLogistico));
            choferElegido=getDatoLista(getPersonas(centroLogistico),k);
            if(!buscarChoferRepartos(centroLogistico, getCuil(getCuilPersona(choferElegido))))
            {
                if(getEsChofer(choferElegido))
                {
                    valido=true;
                }
                else
                {
                    printf("\n\nEl chofer elegido resulto no ser un chofer\n\n");
                    presionarEnterYLimpiarPantalla();
                }
            }
            else
            {

                printf("\nEl chofer resulto estar en otro reparto o ya cumplio con su trabajo diario\n\n");
                presionarEnterYLimpiarPantalla();
            }
            system("cls");
        }while(!valido);
        system("cls");
        valido=false;
        do
        {
            mostrarVehiculosDisponibles(centroLogistico);
            printf("\n\nSeleccione un vehiculo ingresando su indice: ");
            k = menuModoAccion1(getVehiculos(centroLogistico));
            if(!buscarVehiculoRepartos(centroLogistico,getPatente(getDatoLista(getVehiculos(centroLogistico),k))))
            {
                vehiculoElegido=getDatoLista(getVehiculos(centroLogistico),k);
                valido=true;
            }
            else
            {
                printf("\n\nVehiculo actualmente en un reparto\n\n");
                presionarEnterYLimpiarPantalla();
            }
            system("cls");
        }while(!valido);
        system("cls");
        printf("\n\nFecha de salida:");
        fechaSalida=cargarFecha(fechaSalida);
        printf("\n\nFecha de retorno:");
        fechaRetorno=cargarFecha(fechaRetorno);
        system("cls");
        int j = 0;
        do
        {
            do
            {
                valido=false;
                system("cls");
                mostrarPaquetesDisponibles(centroLogistico);
                printf("\n\nPaquete N. %d\n",j++);
                printf("Seleccione el paquete a cargar ingresando su indice: ");
                k=menuModoAccion1(getPaquetes(centroLogistico));
                if(getEstado(getDatoLista(getPaquetes(centroLogistico),k))==0)
                {
                    valido=true;
                }
                else
                {
                    printf("\n\nPaquete actualmente en curso\n\n");
                    presionarEnterYLimpiarPantalla();
                }
            }while(!valido);
            paqueteElegido=getDatoLista(getPaquetes(centroLogistico),k);
            setEstado(paqueteElegido,1);
            agregarDatoLista(paquetes,(PaquetePtr)paqueteElegido);
            continuar = menuContinuar();
        }while(continuar && existenPaquetesDisponibles(centroLogistico));
        if(!existenPaquetesDisponibles(centroLogistico))
        {
            printf("\n\nSe ha quedado sin paquetes para seleccionar, agregue mas\n\n");
        }
        reparto=crearReparto(choferElegido,vehiculoElegido,fechaSalida,fechaRetorno,paquetes);
        cambiosGuardados = true;
        agregarReparto(centroLogistico,reparto,true);
        printf("\n\nReparto armado exitosamente.\n\n");
    }
    if( cambiosGuardados )
    {
        resultado = menuGuardarCambios();
        if(resultado == 1)
        {
            cambiosGuardados = guardarRepartos(centroLogistico, true);
        }
    }
    return cambiosGuardados;
}

bool menuCerrarReparto(CentroLogisticoPtr centroLogistico)
{
    bool cambiosGuardados=false;
    bool continuar;
    int EleccionMenuModoAccion=0,EleccionAccion=0,cantIndices=0,resultado=0;
    int indices[100];
    RepartoPtr repartoCerrado;
    do
    {
        if(listaVacia(getRepartos(centroLogistico, true)))
        {
            printf("Lista vacia,, no puede cerrar repartos\n");
            presionarEnterYLimpiarPantalla();
        }
        else
        {
            EleccionMenuModoAccion = menuModoAccion();
            mostrarRepartos(centroLogistico,true);
            printf("CERRAR REPARTO \n\n");
            switch(EleccionMenuModoAccion)
            {
                case 1:
                    EleccionAccion = menuModoAccion1(getRepartos(centroLogistico, true));
                    repartoCerrado=removerReparto(centroLogistico,EleccionAccion,true);
                    verificacionPaquetesCurso(getPaquetesReparto(repartoCerrado));
                    setRepartoDiario(getChofer(repartoCerrado),true);
                    agregarReparto(centroLogistico,repartoCerrado,false);
                    cambiosGuardados = true;
                    break;
                case 2:
                    cantIndices = menuModoAccion1(getRepartos(centroLogistico,true));
                    menuModoAccion2(getRepartos(centroLogistico, true),cantIndices,indices);
                    for(int i=0;i<cantIndices;i++)
                    {
                        repartoCerrado = removerReparto(centroLogistico,indices[i]-i,true);
                        agregarLista(getPaquetesReparto(repartoCerrado),getPaquetesReparto(repartoCerrado));
                        verificacionPaquetesCurso(getPaquetesReparto(repartoCerrado));
                        agregarReparto(centroLogistico,repartoCerrado,false);
                    }
                    cambiosGuardados = true;
                    break;
                case 3:
                    menuModoAccion3(getRepartos(centroLogistico, true),indices);
                    for(int i=0;i<indices[1]-indices[0]+1;i++)
                    {
                        repartoCerrado = removerReparto(centroLogistico,indices[i],true);
                        agregarLista(getPaquetesReparto(repartoCerrado),getPaquetesReparto(repartoCerrado));
                        verificacionPaquetesCurso(getPaquetesReparto(repartoCerrado));
                        agregarReparto(centroLogistico,repartoCerrado,false);
                    }
                    cambiosGuardados = true;
                    break;
                default:
                    printf("Eleccion equivocada \n");
                break;
            }
            continuar=menuContinuar();
        }
    } while(continuar && !listaVacia(getRepartos(centroLogistico,true)));
    notificacionListaVacia(getRepartos(centroLogistico, true));
    if( cambiosGuardados )
    {
        resultado = menuGuardarCambios();
        if(resultado == 1)
        {
            cambiosGuardados = guardarRepartos(centroLogistico,true);
            cambiosGuardados = cambiosGuardados && guardarRepartos(centroLogistico,false);
        }
    }
    return cambiosGuardados;
}

bool menuEliminarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    int resultado=0;
    bool cambiosGuardados=false;
    bool continuar;
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int indices[100];
    int cantIndices=0;
    RepartoPtr repartoRemovido;
    do
    {
        if(listaVacia(getRepartos(centroLogistico,esRepartoAbierto)))
        {
            printf("ERROR: Lista vacía. Debe agregar repartos para poder eliminarlos.\n\n");
            presionarEnterYLimpiarPantalla();
        }
        else
        {
            EleccionMenuModoAccion = menuModoAccion();
            mostrarRepartos(centroLogistico,esRepartoAbierto);
            printf("ELIMINAR REPARTO \n\n");
            switch(EleccionMenuModoAccion)
            {
                case 1:
                    EleccionAccion = menuModoAccion1(getRepartos(centroLogistico,esRepartoAbierto));
                    repartoRemovido = removerReparto(centroLogistico, EleccionAccion,esRepartoAbierto);
                    repartoRemovido = destruirReparto(repartoRemovido);
                    cambiosGuardados = true;
                    break;
                case 2:
                    printf("[ACLARACION]Eliga la cantidad de indices...\n");
                    cantIndices = menuModoAccion1( getRepartos(centroLogistico, esRepartoAbierto) );
                    menuModoAccion2(getRepartos(centroLogistico,esRepartoAbierto),cantIndices,indices);
                    for(int i=0;i<cantIndices;i++)
                    {
                        repartoRemovido = removerReparto(centroLogistico,indices[i]-i,esRepartoAbierto);
                        repartoRemovido = destruirReparto(repartoRemovido);
                    }
                    cambiosGuardados = true;
                    break;
                case 3:
                    menuModoAccion3(getRepartos(centroLogistico,esRepartoAbierto),indices);
                    for(int i=0;i<indices[1]-indices[0]+1;i++)
                    {
                        repartoRemovido = removerReparto(centroLogistico,indices[0],esRepartoAbierto);
                        repartoRemovido = destruirReparto(repartoRemovido);
                    }
                    cambiosGuardados = true;
                    break;
                default:
                    printf("Eleccion equivocada \n");
                    break;
            }
        continuar=menuContinuar();
        }
    } while(continuar && !listaVacia(getRepartos(centroLogistico,esRepartoAbierto)));
    notificacionListaVacia(getRepartos(centroLogistico,esRepartoAbierto));
    if( cambiosGuardados )
    {
        resultado = menuGuardarCambios();
        if(resultado == 1)
        {
            cambiosGuardados = guardarRepartos(centroLogistico,esRepartoAbierto);
        }
    }
    return cambiosGuardados;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE BUSQUEDA DE REPARTOS///
///-----------------------------------------------------------------------------------------------------------///

int menuTipoRepartos()
{
   system("cls");
   int eleccion=0;
   fflush(stdin);
   printf("BUSCAR POR: \n");
   printf("1. Indice \n");
   printf("2. Cuil chofer \n");
   printf("3. Patente vehiculo \n");
   printf("4. Fecha salida \n");
   printf("5. Fecha retorno \n");
   printf("6. ID paquete \n");
   printf("Eleccion: ");
   scanf("%d",&eleccion);
   fflush(stdin);
   return eleccion;
}

void menuBuscarPorIndiceReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    int i=0,n=0;
    RepartoPtr repartoBuscar;
    printf("Seleccione un reparto para buscar mediante su indice: ");
    i=seleccionarNumero();
    if(i>=0 && i<n){
        system("cls");
        repartoBuscar=getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),i-1);
        mostrarReparto(repartoBuscar);
    }else{
        printf("Reparto inexistente\n");
    }
}

void menuBuscarRepartoPorCuilChofer(CentroLogisticoPtr centroLogistico)
{
    char cuilBuscar[100];
    RepartoPtr repartoMostrar;
    printf("Ingrese el cuil a buscar: ");
    seleccionarString(cuilBuscar);
    repartoMostrar=devolverRepartoChofer(centroLogistico, cuilBuscar);
    if(repartoMostrar!=NULL)
    {
        system("cls");
        mostrarReparto(repartoMostrar);
    }
    else
    {
        printf("ERROR: Reparto no localizado... \n");
    }
}

void menuBuscarRepartoPorPatenteVehiculo(CentroLogisticoPtr centroLogistico)
{
    RepartoPtr repartoMostrar;
    char patenteBuscar[100];
    printf("Ingrese la patente a buscar: ");
    seleccionarString(patenteBuscar);
    repartoMostrar=devolverRepartoVehiculo(centroLogistico,patenteBuscar);
    if(repartoMostrar != NULL)
    {
        system("cls");
        mostrarReparto(repartoMostrar);
    }
    else
    {
        printf("ERROR: Reparto no localizado... \n");
    }
}

void menuBuscarRepartoPorFechaSalida(CentroLogisticoPtr centroLogistico)
{
    int dia,mes,anio,hora,minutos;
    FechaPtr fechaBuscar;
    RepartoPtr repartoMostrar;
    fflush(stdin);
    printf("Ingrese la fecha salida [DD/MM/AA - HH:MM]: ");
    scanf("%d %d %d %d %d", &dia,&mes,&anio,&hora,&minutos);
    fflush(stdin);
    fechaBuscar=crearFecha(dia,mes,anio,hora,minutos);
    repartoMostrar=devolverRepartoFechaSalida(centroLogistico,fechaBuscar);
    if(repartoMostrar != NULL)
    {
        system("cls");
        mostrarReparto(repartoMostrar);
    }
    else
    {
        printf("ERROR: Reparto no localizado... \n");
    }
    fechaBuscar=destruirFecha(fechaBuscar);
}

void menuBuscarRepartoPorFechaRetorno(CentroLogisticoPtr centroLogistico)
{
    int dia,mes,anio,hora,minutos;
    FechaPtr fechaBuscar;
    RepartoPtr repartoMostrar;
    fflush(stdin);
    printf("Ingrese la fecha salida [DD/MM/AA - HH:MM]: ");
    scanf("%d %d %d %d %d", &dia,&mes,&anio,&hora,&minutos);
    fflush(stdin);
    fechaBuscar=crearFecha(dia,mes,anio,hora,minutos);
    repartoMostrar=devolverRepartoFechaRetorno(centroLogistico,fechaBuscar);
    if(repartoMostrar != NULL)
    {
        system("cls");
        mostrarReparto(repartoMostrar);
    }
    else
    {
        printf("ERROR: Reparto no localizado... \n");
    }
    fechaBuscar=destruirFecha(fechaBuscar);
}

void menuBuscarRepartoPorIDPaquete(CentroLogisticoPtr centroLogistico)
{
    int ID;
    RepartoPtr repartoMostrar;
    printf("Ingrese ID para buscar: ");
    ID = seleccionarNumero();
    repartoMostrar = devolverRepartoPaquete(centroLogistico, ID);
    if(repartoMostrar != NULL)
    {
        mostrarReparto(repartoMostrar);
    }
    else
    {
        printf("ERROR: Reparto no localizado... \n");
    }
}

void menuBuscarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    int eleccion=0;
    bool continuar=false;
    if(listaVacia(getRepartos(centroLogistico,esRepartoAbierto)))
    {
        printf("ERROR: Lista vacia. No hay repartos para buscar\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            system("cls");
            eleccion=menuTipoRepartos();
            mostrarRepartos(centroLogistico,true);
            switch(eleccion)
            {
                case 1:
                    menuBuscarPorIndiceReparto(centroLogistico, esRepartoAbierto);
                    break;
                case 2:
                    menuBuscarRepartoPorCuilChofer(centroLogistico);
                    break;
                case 3:
                    menuBuscarRepartoPorPatenteVehiculo(centroLogistico);
                    break;
                case 4:
                    menuBuscarRepartoPorFechaSalida(centroLogistico);
                    break;
                case 5:
                    menuBuscarRepartoPorFechaRetorno(centroLogistico);
                    break;
                case 6:
                    menuBuscarRepartoPorIDPaquete(centroLogistico);
                    break;
                default:
                    break;
            }
            continuar=menuContinuar();
        }while(continuar);
    }
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE MODIFICACION DE REPARTOS///
///-----------------------------------------------------------------------------------------------------------///

int MenuSeleccionAtributoReparto()
{
    int eleccion;
    printf("Seleccione un atributo de [ REPARTO ] para modificar \n");
    printf("1. Chofer \n");
    printf("2. Vehiculo \n");
    printf("3. Fecha de salida \n");
    printf("4. Fecha de retorno \n");
    printf("5. Paquete \n");
    printf("Opcion: ");
    limpiarBufferTeclado();
    scanf("%d", &eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

void cambiarAtributoReparto(RepartoPtr repartoModificar)
{
    int SubMenu,iMod,seguirMod;
    PersonaPtr choferModificar;
    VehiculoPtr vehiculoModificar;
    FechaPtr fechaModificar;
    PaquetePtr paqueteModificar;
    do
    {
        system("cls");
        mostrarReparto(repartoModificar);
        SubMenu = MenuSeleccionAtributoReparto();
        switch(SubMenu)
        {
            case 1:
                printf("MODIFICAR CHOFER \n");
                choferModificar = getChofer(repartoModificar);
                cambiarPersona(choferModificar, true);
            break;
            case 2:
                printf("MODIFICAR VEHICULO \n");
                vehiculoModificar = getVehiculo(repartoModificar);
                cambiarVehiculo(vehiculoModificar);
            break;
            case 3:
                printf("MODIFICAR FECHA DE SALIDA \n");
                fechaModificar = getFechaSalida(repartoModificar);
                actualizarFecha(fechaModificar);
            break;
            case 4:
                printf("MODIFICAR FECHA DE RETORNO \n");
                fechaModificar = getFechaRetorno(repartoModificar);
                actualizarFecha(fechaModificar);
            break;
            case 5:
                system("cls");
                printf("MODIFICAR PAQUETE \n");
                mostrarPaquetesReparto(repartoModificar);
                printf("Seleccione un paquete ");
                iMod = menuModoAccion1(getPaquetesReparto(repartoModificar));
                paqueteModificar = getDatoLista(getPaquetesReparto(repartoModificar), iMod);
                cambiarPaquete(paqueteModificar);
            break;
            default:
                printf("Eleccion ewuivocada\n");
            break;
        }
        printf("\n\nDatos modificados exitosamente.\n\n");
        printf("Desea seguir modificando este REPARTO?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&seguirMod);
    }while(seguirMod!=0);
}

RepartoPtr SeleccionRepartoPorAtributo(CentroLogisticoPtr centroLogistico)
{
    char CuilBuscar[100];
    char PatenteBuscar[100];
    int ID_Buscar;
    int diaBuscar,mesBuscar,anioBuscar,horaBuscar,minutosBuscar;
    FechaPtr FechaBuscar;
    int Menu;
    int Indice;
    RepartoPtr RepartoElegido=NULL;
    ListaPtr ListaRepartos = crearLista();
    agregarLista(ListaRepartos, getRepartos(centroLogistico, true));
    if(listaVacia(ListaRepartos))
    {
        printf("Lista de repartos vacia, agregue elementos para seleccionar...\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            system("cls");
            Menu = menuTipoRepartos();
            switch(Menu)
            {
                case 1:
                    mostrarRepartos(centroLogistico, true);
                    Indice = menuModoAccion1( ListaRepartos );
                    RepartoElegido = (RepartoPtr)getDatoLista( ListaRepartos , Indice );
                    break;
                case 2:
                    printf("Ingrese el cuil: ");
                    seleccionarString(CuilBuscar);
                    RepartoElegido = devolverRepartoChofer(centroLogistico, CuilBuscar);
                    break;
                case 3:
                    printf("Ingrese la patente: ");
                    seleccionarString(PatenteBuscar);
                    RepartoElegido = devolverRepartoVehiculo(centroLogistico, PatenteBuscar);
                    break;
                case 4:
                    printf("Ingrese la fecha de salida [DD/MM/AA HH:MM]: ");
                    fflush(stdin);
                    scanf("%d %d %d %d %d", &diaBuscar,&mesBuscar,&anioBuscar,&horaBuscar,&minutosBuscar);
                    fflush(stdin);
                    FechaBuscar = crearFecha(diaBuscar,mesBuscar,anioBuscar,horaBuscar,minutosBuscar);
                    RepartoElegido = devolverRepartoFechaSalida(centroLogistico, FechaBuscar);
                    FechaBuscar = destruirFecha(FechaBuscar);
                    break;
                case 5:
                    printf("Ingrese la fecha de retorno [DD/MM/AA HH:MM]: ");
                    fflush(stdin);
                    scanf("%d %d %d %d %d", &diaBuscar,&mesBuscar,&anioBuscar,&horaBuscar,&minutosBuscar);
                    fflush(stdin);
                    FechaBuscar = crearFecha(diaBuscar,mesBuscar,anioBuscar,horaBuscar,minutosBuscar);
                    RepartoElegido = devolverRepartoFechaRetorno(centroLogistico, FechaBuscar);
                    FechaBuscar = destruirFecha(FechaBuscar);
                    break;
                case 6:
                    printf("Ingrese el ID: ");
                    ID_Buscar = seleccionarNumero();
                    RepartoElegido = devolverRepartoPaquete(centroLogistico, ID_Buscar);
                    break;
                default:
                    printf("Opcion equivocada... \n");
                    presionarEnterYLimpiarPantalla();
                    break;
            }
        }while(RepartoElegido == NULL);
    }
    ListaRepartos = destruirLista(ListaRepartos, false);
    return RepartoElegido;
}

void menuActualizarReparto(CentroLogisticoPtr centroLogistico)
{
    int eleccion = 0;
    int EstadoPaquete = 0;
    PaquetePtr paqueteActual;
    PaquetePtr PaqueteModificar;
    RepartoPtr RepartoActualizar;
    if(listaVacia(getRepartos(centroLogistico,true)))
    {
        printf("No existen repartos para actualizar...\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        RepartoActualizar = SeleccionRepartoPorAtributo(centroLogistico);
        ListaPtr paquetes = getPaquetesReparto(RepartoActualizar);
        ListaPtr listaRespaldo=crearLista();
        agregarLista(listaRespaldo,paquetes);
        bool encontrado = false;
        while(!encontrado && !listaVacia(listaRespaldo))
        {
            paqueteActual=getCabecera(listaRespaldo);
            EstadoPaquete = getEstado(paqueteActual);
            ///SI ES DISTINTO DE ENTREGADO Y SUSPENDIDO
            if(EstadoPaquete != 3 && EstadoPaquete != 5 && encontrado == false)
            {
                encontrado=true;
                PaqueteModificar = paqueteActual;
                ///break;
            }
            ListaPtr ListaDestruir = listaRespaldo;
            listaRespaldo = getResto(listaRespaldo);
            ListaDestruir = destruirLista(ListaDestruir, false);
        }
        listaRespaldo = destruirLista(listaRespaldo,false);
        helpEstadoPaquete();
        do
        {
            printf("El paquete que esta modificando es: \n");
            mostrarPaquete(PaqueteModificar);
            printf("SELECCIONE EL ESTADO: ");
            eleccion=seleccionarNumero();
            if(eleccion == 0)
            {
                printf("Que haces seleccionando un paquete en estado 'DEPOSITO'?\n");
                presionarEnterYLimpiarPantalla();
            }
            if(eleccion < 1 && eleccion > 6)
            {
                printf("\n\n\t [Eliga bien por favor]... \n\n");
                presionarEnterYLimpiarPantalla();
            }
        }while(eleccion < 1 && eleccion > 6);
        setEstado(PaqueteModificar,eleccion);
    }
}

ListaPtr OriginalRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
        ///Creamos una lista "original" para ver si hay cambios,
        ///y una "auxiliar" para obtener y recorrer la lista.
        ListaPtr listaOriginal=crearLista();
        ListaPtr listaAux2=crearLista();
        agregarLista(listaAux2,getRepartos(centroLogistico,esRepartoAbierto));
        ///Hacemos lo mismo pero para cada elemento de la lista
        RepartoPtr repartoOriginal;
        RepartoPtr repartoAux;
        while(!listaVacia(listaAux2))
        {
            repartoAux=getCabecera(listaAux2);
            ///Copiamos el contenido de cada elemento
            repartoOriginal=armarReparto(getChofer(repartoAux),getVehiculo(repartoAux),getFechaSalida(repartoAux),getFechaRetorno(repartoAux),getPaquetesReparto(repartoAux));
            ///Agregamos el dato original a la lista
            agregarDatoLista(listaOriginal,(RepartoPtr)repartoOriginal);
            listaAux2=getResto(listaAux2);
        }
        listaAux2=destruirLista(listaAux2,false);
        return listaOriginal;
}

bool CambiosRepartos(CentroLogisticoPtr centroLogistico, ListaPtr listaOriginal,bool esRepartoAbierto)
{
    bool cambioDetectado=false;
    ListaPtr listaAux2=crearLista();
    RepartoPtr repartoAux;
    RepartoPtr repartoOriginal;
    agregarLista(listaAux2,getRepartos(centroLogistico,esRepartoAbierto));
    ///Recorremos la lista: antes y después de hacer el cambio
    while(!listaVacia(listaAux2))
    {
        repartoAux=getCabecera(listaAux2);
        repartoOriginal=getCabecera(listaOriginal);
        ///Revisamos, elemento por elemento, si son iguales o cambiaron (puede ser que se haya ordenado de la misma forma que estaba)
        if(!repartosIguales(repartoOriginal,repartoAux))
            cambioDetectado=true;
        listaAux2=getResto(listaAux2);
        listaOriginal=getResto(listaOriginal);
    }
    ///Destruimos ambas listas, ya no las necesitamos más
    listaAux2=destruirLista(listaAux2,false);
    ///Como en esta copiamos los contenidos, ponemos true para remover
    listaOriginal=destruirLista(listaOriginal,true);
    return cambioDetectado;
}

bool menuModificarReparto(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
    ListaPtr listaOriginal=crearLista();
    bool cambioDetectado=false,cambiosGuardados=false,continuar;
    int resultado=0;
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int indices[100];
    int cantIndices=0;
    RepartoPtr repartoModificar = (RepartoPtr)obtenerMemoria(sizeof(Reparto));
    if(listaVacia(getRepartos(centroLogistico,esRepartoAbierto)))
    {
        printf("ERROR: Lista vacía. Debe agregar repartos para poder modificarlos.\n\n");
    }
    else
    {
        ///----------------------------------------------------///
            listaOriginal=OriginalRepartos(centroLogistico,esRepartoAbierto);
        ///----------------------------------------------------///
        do
        {
            EleccionMenuModoAccion = menuModoAccion(0);
            mostrarRepartos(centroLogistico,esRepartoAbierto);
            printf("MODIFICAR REPARTO\n\n");
            switch(EleccionMenuModoAccion)
            {
            case 1:
                EleccionAccion = menuModoAccion1(getRepartos(centroLogistico,esRepartoAbierto));
                repartoModificar = getDatoLista(getRepartos(centroLogistico,esRepartoAbierto), EleccionAccion);
                cambiarAtributoReparto(repartoModificar);
                break;
            case 2:
                printf("[ACLARACION]Eliga la cantidad de indices...\n");
                cantIndices = menuModoAccion1(getRepartos(centroLogistico,esRepartoAbierto));
                menuModoAccion2(getRepartos(centroLogistico,esRepartoAbierto),cantIndices,indices);
                for(int i=0;i<cantIndices;i++)
                {
                    repartoModificar = getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),indices[i]-i);
                    cambiarAtributoReparto(repartoModificar);
                }
                break;
            case 3:
                menuModoAccion3(getRepartos(centroLogistico,esRepartoAbierto),indices);
                for(int i=indices[0];i<indices[1]-indices[0]+1;i++)
                {
                    repartoModificar = getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),i);
                    cambiarAtributoReparto(repartoModificar);
                }
                break;
            default:
                printf("Eleccion equivocada \n");
                break;
            }
            continuar=menuContinuar();
        }while(continuar);
    }
    ///----------------------------------------------------///
        cambioDetectado=CambiosRepartos(centroLogistico,listaOriginal,esRepartoAbierto);
    ///----------------------------------------------------///

    if(cambioDetectado)
    {
        resultado = menuGuardarCambios();
        if(resultado==1)
        {
            cambiosGuardados = guardarRepartos(centroLogistico,esRepartoAbierto);
        }
    }
    return cambiosGuardados;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE MOSTRADO DE REPARTOS///
///-----------------------------------------------------------------------------------------------------------///

int menuListadoReparto()
{
    int op2=0;
    system("cls");
    printf("\n-----------------------------------------\n\n");
    printf("1. Mostrar un reparto\n");
    printf("2. Ordenar lista y mostrar...\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion:");
    limpiarBufferTeclado();
    scanf("%d",&op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuOrdenarRepartos()
{
    int op3=0;
    system("cls");
    printf("ORDENAR Y MOSTRAR POR:\n");
    printf("1. Fecha de salida\n");
    printf("2. Fecha de retorno\n");
    printf("3. Fecha de salida y retorno\n");
    printf("4. Nombre del chofer\n");
    printf("5. Apellido del chofer\n");
    printf("6. Nombre y apellido del chofer\n");
    printf("7. Sin ordenar\n");
    printf("0. Volver\n\n");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op3);
    limpiarBufferTeclado();
    system("cls");
    return op3;
}

bool menuMostrarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto, int* op1)
{
	int Main_1=0,Main_2=0,i=0;
    bool cambiosGuardados=false;
	int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));
    if(listaVacia(getRepartos(centroLogistico,esRepartoAbierto)))
    {
        printf("Lista de repartos vacia, por favor, agregue elementos para mostrar\n");
        presionarEnterYLimpiarPantalla();
    }
    else
    {
        do
        {
            system("cls");
            if(esRepartoAbierto)
                printf("EMITIR LISTADO DE REPARTOS ABIERTOS\n");
            else
                printf("EMITIR LISTADO DE REPARTOS CERRADOS\n");
            Main_1=menuListadoReparto();
            switch(Main_1)
            {
            case 1:
                do
                {
                    mostrarRepartos(centroLogistico,esRepartoAbierto);
                    printf("\nSeleccione un reparto para mostrar:");
                    printf("ACLARACION: [-1] para salir...\n");
                    i=seleccionarNumero();
                    if(i<=0 || i>n)
                    {
                        printf("\n\nIndice inexistente. Vuelva a ingresarlo.\n\n");
                        presionarEnterYLimpiarPantalla();
                    }
                } while((i<=0 || i>n) && i==-1);
                system("cls");
                mostrarReparto(getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),i-1));
                system("pause");
                break;
            case 2:
                do
                {
                    Main_2=menuOrdenarRepartos();
                    switch(Main_2)
                    {
                    case 1:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,1);
                        cambiosGuardados = true;
                        break;
                    case 2:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,2);
                        cambiosGuardados = true;
                        break;
                    case 3:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,3);
                        cambiosGuardados = true;
                        break;
                    case 4:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,4);
                        cambiosGuardados = true;
                        break;
                    case 5:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,5);
                        cambiosGuardados = true;
                        break;
                    case 6:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,6);
                        cambiosGuardados = true;
                        break;
                    case 7:
                        ordenarRepartos(centroLogistico,esRepartoAbierto,7);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opcion incorrecta.\n\n");
                        break;
                    }
                    system("cls");
                } while(Main_2!=0);
                break;
            case 0:
                break;
           case -1:
                *op1 = 0;
                Main_1 = 0;
                Main_2 = 0;
                break;
            default:
                printf("Opcion incorrecta\n\n");
                break;
            }
        } while(Main_1!=0);
    }
    return cambiosGuardados;
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

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE MENUES DEL MAIN///
///-----------------------------------------------------------------------------------------------------------///

int menuMainMenu()
{
    int START_OP=0;
    system("cls");
    printf("MENU DE INICIO - BIENVENIDO\n\n");
    printf("\t1. REGISTRARSE\n");
    printf("\t2. INICIAR SESION\n");
    printf("\t0. SALIR\n\n");
    printf("Seleccione una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&START_OP);
    limpiarBufferTeclado();
    system("cls");
    return START_OP;
}

int menuPrincipal(CentroLogisticoPtr centroLogistico)
{
    int MAIN_OP=0;
    system("cls");
    printf("CENTRO LOGISTICO '%s' - MENU PRINCIPAL\n\n",getNombreCentroLogistico(centroLogistico));
    printf("1. BASE DE DATOS\n");
    printf("2. REPARTOS\n");
    printf("3. INDICAR RESULTADOS DE ENTREGAS\n");
    printf("4. EMITIR LISTADOS\n");
    printf("5. GUARDAR CAMBIOS\n"); ///NUEVO
    printf("0. SALIR\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d", &MAIN_OP);
    limpiarBufferTeclado();
    system("cls");
    return MAIN_OP;
}

int menuBaseDeDatos()
{
    int op1=0;
    system("cls");
    printf("BASE DE DATOS\n\n");
    printf("1. Cargar Datos\n");
    printf("2. Eliminar Datos\n");
    printf("3. Modificar Datos\n");
    printf("4. Buscar Datos\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d", &op1);
    limpiarBufferTeclado();
    system("cls");
    return op1;
}

int menuCargaDeDatos()
{
    int op2=0;
    system("cls");
    printf("CARGAR DATOS\n\n");
    printf("1. Cargar paquete\n");
    printf("2. Cargar cliente\n");
    printf("3. Cargar chofer\n");
    printf("4. Cargar vehiculo\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d", &op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuEliminarDatos()
{
    int op2=0;
    system("cls");
    printf("ELIMINAR DATOS\n\n");
    printf("1. Eliminar Paquete\n");
    printf("2. Eliminar Cliente\n");
    printf("3. Eliminar Chofer\n");
    printf("4. Eliminar Vehiculo\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuModificacionDatos()
{
    int op2=0;
    system("cls");
    printf("MODIFICAR DATOS\n\n");
    printf("1. Modificar Paquete\n");
    printf("2. Modificar Cliente\n");
    printf("3. Modificar Chofer\n");
    printf("4. Modificar Vehiculo\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuBusquedaDatos()
{
    int op2=0;
    system("cls");
    printf("BUSCAR DATOS\n\n");
    printf("1. Buscar paquete\n"); //buscamos por ID
    printf("2. Buscar cliente\n"); //buscamos por
    printf("3. Buscar chofer\n"); //cuil
    printf("4. Buscar vehiculo\n"); //buscamos por patente
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d", &op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuOperacionesReparto()
{
    int op1=0;
    system("cls");
    printf("MENU DE REPARTOS\n\n");
    ///Son solo para repartos abiertos:
    printf("1. Armar reparto\n"); //Este
    printf("2. Cerrar reparto\n"); //Y este
    printf("3. Eliminar reparto\n");
    printf("4. Modificar reparto\n");
    printf("5. Buscar reparto\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op1);
    limpiarBufferTeclado();
    system("cls");
    return op1;
}

int menuEliminarRepartoCompleto()
{
    int op2=0;
    system("cls");
    printf("ELIMINAR REPARTO:\n\n");
    printf("1. Abierto\n");
    printf("2. Cerrado\n");
    printf("0. Volver");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Seleccione una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuModificarRepartoCompleto()
{
    int op2=0;
    system("cls");
    printf("MODIFICAR REPARTO:\n\n");
    printf("1. Abierto\n");
    printf("2. Cerrado\n");
    printf("0. Volver");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Seleccione una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuBuscadoReparto()
{
    int op2=0;
    system("cls");
    printf("BUSCAR REPARTO:\n\n");
    printf("1. Abierto\n");
    printf("2. Cerrado\n");
    printf("0. Volver\n");
    printf("-1. MENU PRINCIPAL");
    printf("\n-----------------------------------------\n\n");
    printf("Seleccione una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op2);
    limpiarBufferTeclado();
    system("cls");
    return op2;
}

int menuActualizarRepartoCompleto()
{
    int op1=0;
    system("cls");
    printf("VER RESULTADOS DE ENTREGAS");
    printf("\n-----------------------------------------\n\n");
    printf("1. Ver en Lista de Paquetes\n");
    printf("2. Ver en Repartos ABIERTOS\n");
    printf("3. Ver en Repartos CERRADOS\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op1);
    limpiarBufferTeclado();
    system("cls");
    return op1;
}

int menuListados()
{
    int op1=0;
    system("cls");
    printf("EMITIR LISTADOS DE:\n\n");
    printf("1. Paquetes\n");
    printf("2. Choferes\n");
    printf("3. Clientes\n");
    printf("4. Clientes y Choferes\n");
    printf("5. Vehiculos\n");
    printf("6. Repartos - ABIERTOS\n");
    printf("7. Repartos - CERRADOS\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op1);
    limpiarBufferTeclado();
    system("cls");
    return op1;
}

int menuGuardarCambiosMain()
{
    int op1=0;
    system("cls");
    printf("GUARDAR CAMBIOS\n\n");
    printf("\n-----------------------------------------\n\n");
    printf("1. Lista de Paquetes\n");
    printf("2. Lista de Personas\n");
    printf("3. Lista de Vehiculos\n");
    printf("4. Lista de Repartos Abiertos\n");
    printf("5. Lista de Repartos Cerrados\n");
    printf("6. TODAS LAS LISTAS\n");
    printf("0. Volver\n");
    printf("\n-----------------------------------------\n\n");
    printf("Elija una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op1);
    limpiarBufferTeclado();
    system("cls");
    return op1;
}

int menuGuardadoRespaldo()
{
    int op1=0;
    system("cls");
    printf("Tiene cambios sin guardar. Seguro que quiere salir?\n");
    printf("\n----------------------------------------------------\n\n");
    printf("1. Guardar y salir\n");
    printf("2. Salir sin guardar\n");
    printf("0. Volver\n\n");
    printf("\n----------------------------------------------------\n\n");
    printf("Seleccione una opcion: ");
    limpiarBufferTeclado();
    scanf("%d",&op1);
    limpiarBufferTeclado();
    system("cls");
    return op1;
}


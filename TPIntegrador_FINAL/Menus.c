#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "TDACentroLogistico.h"
#include "test.h"
#include "util.h"
#include "Menus.h"

int MenuTipoSeleccion()
{
    int eleccion = 0;
    system("cls");
    limpiarBufferTeclado();
    printf("Menu de seleccion \n");
    printf("1. Mediante indice unico [Posicion 1] \n");
    printf("2. Mediante conjunto de indices [Posicion 1,4,5,7,6] \n");
    printf("3. Mediante seleccion de 2 indices [Posicion 1 - 4 (1,2,3,4)] \n");
    printf("Opcion: ");
    scanf("%d", &eleccion);
    limpiarBufferTeclado();

    return eleccion;
}

int MenuDeseaContinuar()
{
    int eleccion = 0;
    system("cls");
    limpiarBufferTeclado();
    printf(" Menu desea continuar ? \n");
    printf("0. NO \n");
    printf("1. SI \n");
    printf("Opcion: ");
    scanf("%d", &eleccion);
    limpiarBufferTeclado();
    return eleccion;
}


void cargarCuil(CuilPtr cuil)
{
    char strCuil[100];

    int i=0;

    do
    {
        helpCuil();
        printf("\n\tCUIL:");
        scanf("%[^\n]%*c",strCuil);
        limpiarBufferTeclado();
        if(i==0)
            cuil=crearCuil(strCuil); ///IMPLEMENTACION CAMBIADA
        else if(i>0 && i<4)
            setCuil(cuil,strCuil);
        else    //if(i==4)
            printf("\n\nIntentos agotados.\n\n");

        i++;
        if(i>1)
            system("cls");
    } while(!esCuilValido(cuil));
}
void cargarDomicilio(DomicilioPtr domicilio)
{
    char calle[100];
    int altura;
    char localidad[100];

    printf("\n\t\tCalle y Altura [CALLE, ALTURA]: ");
    scanf("%[^,]%*c, %d",calle,&altura);
    limpiarBufferTeclado();
    printf("\n\t\tLocalidad: ");
    scanf("%[^\n]%*c",localidad);
    limpiarBufferTeclado();

    domicilio=crearDomicilio(calle,altura,localidad);
}
void cargarFecha(FechaPtr fecha)
{
    int dia=0;
    int mes=0;
    int anio=0;
    int hora=0;
    int minuto=0;

    bool primeraVez=true;

    do
    {
        printf("\n\t\tFecha (DD MM AAAA): ");
        scanf("%d %d %d",&dia,&mes,&anio);
        limpiarBufferTeclado();
        printf("\n\t\tHorario (HH MM): ");
        scanf("%d %d",&hora,&minuto);
        limpiarBufferTeclado();


        if(primeraVez)
            fecha=crearFecha(dia,mes,anio,hora,minuto);
        else
        {
            setDia(fecha,dia);
            setMes(fecha,mes);
            setAnio(fecha,anio);
            setHora(fecha,hora);
            setMinuto(fecha,minuto);
            if(!esFechaValida(fecha))
                printf("\n\nFecha invalida. Reingrese la fecha.\n\n");
        }
        primeraVez=false;
        if(primeraVez==false)
            system("cls");
    } while (!esFechaValida(fecha));
}

void actualizarCuil(CuilPtr cuil)
{
    char strCuil[100];
    int i=0;
    do
    {
        helpCuil();
        printf("\n\tNuevo CUIL:");
        scanf("%[^\n]%*c",strCuil);
        limpiarBufferTeclado();
        if(i<4)
            setCuil(cuil,strCuil);
        else    //if(i==4)
            printf("\n\nIntentos agotados.\n\n");
        i++;
        if(i>1)
            system("cls");
    } while(!esCuilValido(cuil));
}
void actualizarDomicilio(DomicilioPtr domicilio)
{
    char calle[100];
    int altura;
    char localidad[100];

    printf("\n\t\tCalle y Altura [CALLE, ALTURA]: ");
    scanf("%[^,]%*c, %d",calle,&altura);
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
    int dia=0;
    int mes=0;
    int anio=0;
    int hora=0;
    int minuto=0;

    int i=0;

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
        if(!esFechaValida(fecha) && i<4)
        {
            printf("\n\nFecha invalida. Reingrese la fecha.\n\n");
            presionarEnterYLimpiarPantalla();
        }
        else if(i==4)
        {
            printf("\n\nSe agotaron los intentos.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }
    } while (!esFechaValida(fecha));
}

void menuCargarPaquete(CentroLogisticoPtr centroLogistico)
{
    ///Variables para funciones
    int n=0;
    ///Paquete
    PaquetePtr paquete;
    int ID=0;   //el ID del paquete se genera automáticamente, no lo tiene que ingresar el usuario.
    int ancho=0;//el mismo se genera aleatoriamente.
    int alto=0;
    int largo=0;
    int peso=0;
    int DeseaContinuar;
        //Fecha
    FechaPtr fechaEntrega;
        //Domicilios
    DomicilioPtr dirRetiro;
    DomicilioPtr dirEntrega;
//por defecto, los paquetes se cargan con el estado 0: 'en depósito'.
    srand(time(NULL));
    do
    {
        system("cls");
        printf("\n\n PAQUETE \n\n");
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
        cargarDomicilio(dirRetiro);
        printf("\n\tDireccion de entrega:");
        cargarDomicilio(dirEntrega);

        printf("\n\tFecha de entrega:");
        cargarFecha(fechaEntrega);

        paquete=crearPaquete(ID,ancho,alto,largo,peso,dirRetiro,dirEntrega,fechaEntrega,0);
        agregarPaquete(centroLogistico,paquete);

        printf("\n\nPaquete #%d cargado exitosamente.\n\n",ID);
        DeseaContinuar = MenuDeseaContinuar();
    }while(DeseaContinuar!=0);
}
void menuCargarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    ///Variables para funciones
    int n=0;
    int DeseaContinuar;
    ///Cliente
    char nombre[100];
    char apellido[100];
    PersonaPtr persona;
        //Domicilio
    DomicilioPtr domicilio;
        //Cuil
    CuilPtr cuil;
    do
    {
    if(esChofer)
    {
        printf("CARGAR CHOFER\n\n");
    }
    else
    {
        printf("CARGAR CLIENTE\n\n");
    }
    if(esChofer)
        printf("CHOFER %d\n\n",i+1);
    else
        printf("CLIENTE %d\n\n",i+1);
        printf("\n\n\tNombre: ");
        scanf("%[^\n]%*c",nombre);
        limpiarBufferTeclado();
        printf("\n\tApellido: ");
        scanf("%[^\n]%*c",apellido);
        limpiarBufferTeclado();
        printf("\n\tDomicilio");
        cargarDomicilio(domicilio);
        cargarCuil(cuil);
        persona=crearPersona(nombre,apellido,domicilio,cuil,false);
        agregarPersona(centroLogistico,persona);
        if(esChofer)
        {
            printf("Cliente cargado exitosamente.\n\n");
        }
        else
        {
            printf("Cliente cargado exitosamente.\n\n");
        }
        DeseaContinuar = MenuDeseaContinuar();
    }while(DeseaContinuar!=0);
    if(esChofer)
        printf("Choferes cargados exitosamente.\n\n");
    else
        printf("Clientes cargados exitosamente.\n\n");
}
void menuCargarVehiculo(CentroLogisticoPtr centroLogistico)
{
    ///Variables para funciones
    int n=0;
    ///Vehiculo
    int tipoVehiculo=0;
    char marca[100];
    char modelo[100];
    char patente[100];
    VehiculoPtr vehiculo;
    int DeseaContinuar;
    do
    {
        system("cls");
        printf("CARGAR VEHICULO\n\n");
        helpTipoVehiculo();
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
        agregarDatoLista(centroLogistico->listaVehiculos,(VehiculoPtr)vehiculo);
        printf("\n\nVehiculo cargado exitosamente.\n\n");
        DeseaContinuar = MenuDeseaContinuar();
    }while(DeseaContinuar!=0);
    printf("\n\nVehiculos cargados exitosamente.\n\n");
}

void menuBuscarPaquete(CentroLogisticoPtr centroLogistico)
{
    int op=0;
    do
    {
        int ID=0;
        printf("BUSCAR PAQUETE\n\n");

        printf("Ingrese ID del paquete a buscar: ");
        scanf("%d",&ID);
        limpiarBufferTeclado();
        printf("\n\n");

        if(buscarPaquete(centroLogistico,ID)==false)
            printf("\n\nNo se pudo encontrar el paquete con ID #%d.\n\n",ID);

        printf("Volver? 0=Si, 1=No");
        scanf("%d",&op);
        limpiarBufferTeclado();
    } while(op!=0);
}
void menuBuscarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    int op=0;
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

        if(buscarPersona(centroLogistico,cuilABuscar,esChofer)==false)
        {
            if(esChofer)
                printf("\n\nNo se pudo encontrar el chofer con CUIL %s.\n\n",getCuil(cuilABuscar));
            else
                printf("\n\nNo se pudo encontrar el cliente con CUIL %s.\n\n",getCuil(cuilABuscar));
        }
        printf("Volver? 0=Si, 1=No");
        scanf("%d",&op);
        limpiarBufferTeclado();
    } while(op!=0);
}
void menuBuscarVehiculo(CentroLogisticoPtr centroLogistico)
{
    int op=0;
    do
    {
        char patente[100];
        printf("BUSCAR VEHICULO\n\n");

        printf("Ingrese la patente del vehiculo a buscar (AA 111 AA): ");
        scanf("%[^\n]%*c",patente);

        if(buscarVehiculo(centroLogistico,patente)==false)
            printf("\n\nNo se pudo encontrar el vehiculo con patente %s.\n\n",patente);
    } while(op!=0);
}

void menuEliminarPaqueteNuevo(CentroLogisticoPtr centroLogistico)
{
    int MainMenu = 0;
    int iElim = 0;
    int cantidadRemover;
    int PosicionInicial,PosicionFinal;
    int DeseaContinuar = 0;
    int eleccionesRemover[100];
    int verificacionElecciones;
    PaquetePtr paqueteRemovido;
    ListaPtr listaAuxiliar = getPaquetes(centroLogistico);
    int cantidadTotalLista = longitudLista(listaAuxiliar);
    do
    {
        system("cls");
        printf("ELIMINAR PAQUETE\n\n");
        MainMenu = MenuTipoSeleccion();
        switch(MainMenu)
        {
            case 1:
                ///mostrarPaquetes(centroLogistico);
                printf("Seleccione un indice para remover: ");
                iElim = seleccionarNumero();
                if(verificarLimiteLista(listaAuxiliar,iElim))
                {
                    paqueteRemovido=removerPaquete(centroLogistico,iElim);
                    paqueteRemovido=destruirPaquete(paqueteRemovido);
                }
            break;
            case 2:
                ///mostrarPaquetes(centroLogistico);
                printf("A modo de ayuda [Cantidad total de paquetes] : %d \n", cantidadTotalLista);
                printf("Seleccione la cantidad de indices a remover \n");
                cantidadRemover = seleccionarNumero();
                for(int i=0;i<cantidadRemover;i++)
                {
                    printf("Indice numero %d: ", i+1);
                    eleccionesRemover[i] = seleccionarNumero();
                }
                for(int i=0;i<cantidadRemover;i++)
                {
                    if(verificarLimiteLista(listaAuxiliar,eleccionesRemover[i]))
                    {
                         verificacionElecciones++;
                    }
                }
                if(eleccionesRemover==cantidadRemover)
                {
                    for(int i=0;i<cantidadRemover;i++)
                    {
                        paqueteRemovido = removerPaquete(centroLogistico, eleccionesRemover[i]-i);
                        paqueteRemovido = destruirPaquete(paqueteRemovido);
                    }
                }
            break;
            case 3:
                ///mostrarPaquetes(centroLogistico);
                printf("Seleccione de indice a indice para remover \n");
                printf("Primer indice: ");
                PosicionInicial = seleccionarNumero();
                printf("Segundo indice: ");
                PosicionFinal = seleccionarNumero();
                if(verificarLimiteLista(listaAuxiliar,PosicionFinal))
                {
                    for(int i=0;i<PosicionFinal-PosicionInicial+1;i++)
                    {
                        paqueteRemovido = removerPaquete(centroLogistico, PosicionInicial);
                        paqueteRemovido = destruirPaquete(paqueteRemovido);
                    }
                }
            break;
            default:
                mensajeError();
            break;
        }
        DeseaContinuar = MenuDeseaContinuar();
    }while(DeseaContinuar!=0);
}

void menuEliminarPersonaNuevo(CentroLogisticoPtr centroLogistico, bool esChofer)
{
    int MainMenu = 0;
    int iElim = 0;
    int cantidadRemover;
    int PosicionInicial,PosicionFinal;
    int DeseaContinuar = 0;
    int eleccionesRemover[100];
    int verificacionElecciones;
    PersonaPtr personaRemovida;
    ListaPtr listaAuxiliar = getPersonas(centroLogistico);
    int cantidadTotalLista = longitudLista(listaAuxiliar);
    do
    {
        system("cls");
        if(esChofer)
        {
            printf("ELIMINAR CHOFER \n")
        }
        else
        {
            printf("ELIMINAR CLIENTE \n");
        }
        MainMenu = MenuTipoSeleccion();
        switch(MainMenu)
        {
            case 1:
                /*if(esChofer)
                {
                    mostrarChoferes(centroLogistico);
                }
                else
                {
                    mostrarClientes(centroLogistico);
                }*/
                printf("Seleccione un indice para remover: ");
                iElim = seleccionarNumero();
                if(verificarLimiteLista(listaAuxiliar,iElim))
                {
                    personaRemovida = removerPersona(centroLogistico,iElim);
                    personaRemovida = destruirPersona(personaRemovida);
                }
            break;
            case 2:
                /*if(esChofer)
                {
                    mostrarChoferes(centroLogistico);
                }
                else
                {
                    mostrarClientes(centroLogistico);
                }*/
                printf("A modo de ayuda [Cantidad total de paquetes] : %d \n", cantidadTotalLista);
                printf("Seleccione la cantidad de indices a remover \n");
                cantidadRemover = seleccionarNumero();
                for(int i=0;i<cantidadRemover;i++)
                {
                    printf("Indice numero %d: ", i+1);
                    eleccionesRemover[i] = seleccionarNumero();
                }
                for(int i=0;i<cantidadRemover;i++)
                {
                    if(verificarLimiteLista(listaAuxiliar,eleccionesRemover[i]))
                    {
                         verificacionElecciones++;
                    }
                }
                if(eleccionesRemover==cantidadRemover)
                {
                    for(int i=0;i<cantidadRemover;i++)
                    {
                        personaRemovida = removerPersona(centroLogistico, eleccionesRemover[i]-i);
                        personaRemovida = destruirPersona(personaRemovida);
                    }
                }
            break;
            case 3:
                /*if(esChofer)
                {
                    mostrarChoferes(centroLogistico);
                }
                else
                {
                    mostrarClientes(centroLogistico);
                }*/
                printf("Seleccione de indice a indice para remover \n");
                printf("Primer indice: ");
                PosicionInicial = seleccionarNumero();
                printf("Segundo indice: ");
                PosicionFinal = seleccionarNumero();
                if(verificarLimiteLista(listaAuxiliar,PosicionFinal))
                {
                    for(int i=0;i<PosicionFinal-PosicionInicial+1;i++)
                    {
                        personaRemovida = removerPersona(centroLogistico, PosicionInicial);
                        personaRemovida = destruirPersona(personaRemovida);
                    }
                }
            break;
            default:
                mensajeError();
            break;
        }
        DeseaContinuar = MenuDeseaContinuar();
    }while(DeseaContinuar!=0);
}


void menuEliminarVehiculoNuevo(CentroLogisticoPtr centroLogistico)
{
    int MainMenu = 0;
    int iElim = 0;
    int cantidadRemover;
    int PosicionInicial,PosicionFinal;
    int DeseaContinuar = 0;
    int eleccionesRemover[100];
    int verificacionElecciones;
    VehiculoPtr vehiculoRemovido;
    ListaPtr listaAuxiliar = getVehiculos(centroLogistico);
    int cantidadTotalLista = longitudLista(listaAuxiliar);
    do
    {
        system("cls");
        printf("ELIMINAR VEHICULO \n");
        MainMenu = MenuTipoSeleccion();
        switch(MainMenu)
        {
            case 1:
                ///mostrarVehiculos(centroLogistico);
                printf("Seleccione un indice para remover: ");
                iElim = seleccionarNumero();
                if(verificarLimiteLista(listaAuxiliar,iElim))
                {
                    vehiculoRemovido = removerVehiculo(centroLogistico,iElim);
                    vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
                }
            break;
            case 2:
                ///mostrarVehiculos(centroLogistico);
                printf("A modo de ayuda [Cantidad total de paquetes] : %d \n", cantidadTotalLista);
                printf("Seleccione la cantidad de indices a remover \n");
                cantidadRemover = seleccionarNumero();
                for(int i=0;i<cantidadRemover;i++)
                {
                    printf("Indice numero %d: ", i+1);
                    eleccionesRemover[i] = seleccionarNumero();
                }
                for(int i=0;i<cantidadRemover;i++)
                {
                    if(verificarLimiteLista(listaAuxiliar,eleccionesRemover[i]))
                    {
                         verificacionElecciones++;
                    }
                }
                if(eleccionesRemover==cantidadRemover)
                {
                    for(int i=0;i<cantidadRemover;i++)
                    {
                        vehiculoRemovido = removerVehiculo(centroLogistico, eleccionesRemover[i]-i);
                        vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
                    }
                }
            break;
            case 3:
                ///mostrarVehiculos(centroLogistico);
                printf("Seleccione de indice a indice para remover \n");
                printf("Primer indice: ");
                PosicionInicial = seleccionarNumero();
                printf("Segundo indice: ");
                PosicionFinal = seleccionarNumero();
                if(verificarLimiteLista(listaAuxiliar,PosicionFinal))
                {
                    for(int i=0;i<PosicionFinal-PosicionInicial+1;i++)
                    {
                        vehiculoRemovido = removerVehiculo(centroLogistico, PosicionInicial);
                        vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
                    }
                }
            break;
            default:
                mensajeError();
            break;
        }
        DeseaContinuar = MenuDeseaContinuar();
    }while(DeseaContinuar!=0);
}

void menuEliminarRepartoNuevo(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    int MainMenu = 0;
    int iElim = 0;
    int cantidadRemover;
    int PosicionInicial,PosicionFinal;
    int DeseaContinuar = 0;
    int eleccionesRemover[100];
    int verificacionElecciones;
    RepartoPtr repartoRemovido;
    ListaPtr listaAuxiliar = getRepartos(centroLogistico,esRepartoAbierto);
    int cantidadTotalLista = longitudLista(listaAuxiliar);
    do
    {
        system("cls");
        /*if(esRepartoAbierto)
        {
            printf("ELIMINAR REPARTO ABIERTO \n");
        }
        else
        {
            printf("ELIMINAR REPARTO CERRADO \n");
        }*/
        MainMenu = MenuTipoSeleccion();
        switch(MainMenu)
        {
            case 1:
                ///mostrarRepartos(centroLogistico,esRepartoAbierto);
                printf("Seleccione un indice para remover: ");
                iElim = seleccionarNumero();
                if(verificarLimiteLista(listaAuxiliar,iElim))
                {
                    repartoRemovido = removerReparto(centroLogistico,iElim);
                    repartoRemovido = destruirReparto(repartoRemovido);
                }
            break;
            case 2:
                ///mostrarRepartos(centroLogistico,esRepartoAbierto);
                printf("A modo de ayuda [Cantidad total de paquetes] : %d \n", cantidadTotalLista);
                printf("Seleccione la cantidad de indices a remover \n");
                cantidadRemover = seleccionarNumero();
                for(int i=0;i<cantidadRemover;i++)
                {
                    printf("Indice numero %d: ", i+1);
                    eleccionesRemover[i] = seleccionarNumero();
                }
                for(int i=0;i<cantidadRemover;i++)
                {
                    if(verificarLimiteLista(listaAuxiliar,eleccionesRemover[i]))
                    {
                         verificacionElecciones++;
                    }
                }
                if(eleccionesRemover==cantidadRemover)
                {
                    for(int i=0;i<cantidadRemover;i++)
                    {
                        repartoRemovido = removerReparto(centroLogistico, eleccionesRemover[i]-i,esRepartoAbierto);
                        repartoRemovido = destruirReparto(repartoRemovido);
                    }
                }
            break;
            case 3:
                ///mostrarRepartos(centroLogistico,esRepartoAbierto);
                printf("Seleccione de indice a indice para remover \n");
                printf("Primer indice: ");
                PosicionInicial = seleccionarNumero();
                printf("Segundo indice: ");
                PosicionFinal = seleccionarNumero();
                if(verificarLimiteLista(listaAuxiliar,PosicionFinal))
                {
                    for(int i=0;i<PosicionFinal-PosicionInicial+1;i++)
                    {
                        repartoRemovido = removerReparto(centroLogistico, PosicionInicial, esRepartoAbierto);
                        repartoRemovido = destruirReparto(repartoRemovido);
                    }
                }
            break;
            default:
                mensajeError();
            break;
        }
        DeseaContinuar = MenuDeseaContinuar();
    }while(DeseaContinuar!=0);
}


void cambiarPaquete(PaquetePtr paqueteAModificar)
{
    int nAncho,nAlto,nLargo,nPeso,nEstado,seguirMod;
    DomicilioPtr nuevaDirRetiro;
    DomicilioPtr nuevaDirEntrega;
    FechaPtr nuevaFechaEntrega;
    do
    {
        system("cls");
        ///printf("Ha elegido el ");
        ///mostrarPaquete(paqueteAModificar);
        printf("\n\nQué desea modificar?\n\n");
        printf("1. Ancho\n");
        printf("2. Alto\n");
        printf("3. Largo\n");
        printf("4. Peso\n");
        printf("5. Direccion de Retiro\n");
        printf("6. Direccion de Entrega\n");
        printf("7. Fecha de Entrega\n");
        printf("8. Estado\n");
        printf("Seleccione una opcion: ");
        limpiarBufferTeclado();
        scanf("%d",&op);
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
            actualizarDomicilio(nuevaDirRetiro);
            setDirRetiro(paqueteAModificar,nuevaDirRetiro);
            break;
        case 6:
            printf("\n\nIngrese la nueva direccion de entrega:");
            actualizarDomicilio(nuevaDirEntrega);
            setDirEntrega(paqueteAModificar,nuevaDirEntrega);
            break;
        case 7:
            printf("\n\nIngrese la nueva fecha y horario de entrega: ");
            actualizarFecha(nuevaFechaEntrega);
            setFechaEntrega(paqueteAModificar,nuevaFechaEntrega);
            break;
        case 8:
            helpEstadoPaquete();
            printf("\n\nIngrese el nuevo estado: ");
            limpiarBufferTeclado();
            scanf("%d",&nEstado);
            setEstado(paqueteAModificar,nEstado);
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

void menuModificarPaquete(CentroLogisticoPtr centroLogistico)
{
    int iMod=0;
    int op=0;
    int DeseaContinuar = 0;
    int MainMenu = 0;
    int cantidadModificar;
    int verificacionElecciones;
    int PosicionInicial, PosicionFinal;
    int eleccionesModificar[100];
    PaquetePtr paqueteModificar;
    ListaPtr listaAuxiliar = getPaquetes(centroLogistico);
    do
    {
        system("cls");
        printf("MODIFICAR PAQUETE \n");
        MainMenu = MenuTipoSeleccion();
        switch(MainMenu)
        {
        case 1:
            printf("Seleccione un indice para modificar \n");
            iMod = seleccionarNumero();
            paqueteModificar = getDatoLista(listaAuxiliar,iMod-1);
            cambiarPaquete(paqueteModificar);
        break;
        case 2:
            printf("Seleccione una cantidad de indices para modificar \n");
            cantidadModificar = seleccionarNumero();
            for(int i=0;i<cantidadModificar;i++)
            {
                printf("Indice numero %d: ");
                eleccionesModificar[i] = seleccionarNumero();
            }
            for(int i=0;i<cantidadModificar;i++)
            {
                if(verificarLimiteLista(listaAuxiliar,eleccionesModificar[i]))
                {
                    verificacionElecciones++;
                }
            }
            if(verificacionElecciones==5)
            {
                for(int i=0;i<cantidadModificar;i++)
                {
                    paqueteModificar = getDatoLista(listaAuxiliar, eleccionesModificar[i]);
                    cambiarPaquete(paqueteModificar);
                }
            }
        break;
        case 3:
            printf("Seleccione los 2 indices en los cuales modificar \n");
            printf("Primer indice: ");
            PosicionInicial = seleccionarNumero();
            printf("Segundo indice: ");
            PosicionFinal = seleccionarNumero();
            if(verificarLimiteLista(PosicionFinal))
            {
                for(int i=0;i<PosicionFinal-PosicionInicial+1;i++)
                {
                    paqueteModificar = getDatoLista(listaAuxiliar, i);
                    cambiarPaquete(paqueteModificar);
                }
            }
        break;
        default:
            mensajeError();
        break;
        }
        DeseaContinuar = MenuDeseaContinuar();
    }while(DeseaContinuar!=0);
}


void cambiarPersona(PersonaPtr personaAModificar, bool esChofer)
{
    int seguirMod=0;
    char nNombre[100];
    char nApellido[100];
    DomicilioPtr nuevoDomicilio;
    CuilPtr nuevoCuil;
    do
    {
        system("cls");
        printf("Ha elegido - ");
        ///mostrarPersona(personaAModificar);
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
                printf("\n\t[Nombre];[Apellido]\n\t");
                scanf("%[^;]%*c;%[^\n]%*c",nNombre,nApellido);
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


void menuModificarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    int iMod=0;
    int op=0;
    int MainMenu;
    int iMod=0;
    int op=0;
    int DeseaContinuar = 0;
    int MainMenu = 0;
    int cantidadModificar;
    int verificacionElecciones;
    int PosicionInicial, PosicionFinal;
    int eleccionesModificar[100];
    PersonaPtr personaModificar;
    ListaPtr listaAuxiliar = getPersonas(centroLogistico);
    //esChofer se puede modificar sin crear una variable
    do
    {
        if(esChofer)
        {
            printf("MODIFICAR CHOFER\n\n");
            ///mostrarChoferes(centroLogistico);
            printf("\n\nIngrese indice del chofer a modificar: ");
        }
        else
        {
            printf("MODIFICAR CLIENTE\n\n");
            ///mostrarClientes(centroLogistico);
            printf("\n\nIngrese indice del cliente a modificar: ");
        }
            MainMenu = MenuTipoSeleccion();
            switch(MainMenu)
            {
            case 1:
                printf("Seleccione un indice para modificar \n");
                iMod = seleccionarNumero();
                personaModificar = getDatoLista(listaAuxiliar,iMod-1);
                cambiarPersona(personaModificar);
            break;
            case 2:
                printf("Seleccione una cantidad de indices para modificar \n");
                cantidadModificar = seleccionarNumero();
                for(int i=0;i<cantidadModificar;i++)
                {
                    printf("Indice numero %d: ");
                    eleccionesModificar[i] = seleccionarNumero();
                }
                for(int i=0;i<cantidadModificar;i++)
                {
                    if(verificarLimiteLista(listaAuxiliar,eleccionesModificar[i]))
                    {
                        verificacionElecciones++;
                    }
                }
                if(verificacionElecciones==5)
                {
                    for(int i=0;i<cantidadModificar;i++)
                    {
                        personaModificar = getDatoLista(listaAuxiliar, eleccionesModificar[i]);
                        cambiarPersona(personaModificar);
                    }
                }
            break;
            case 3:
                printf("Seleccione los 2 indices en los cuales modificar \n");
                printf("Primer indice: ");
                PosicionInicial = seleccionarNumero();
                printf("Segundo indice: ");
                PosicionFinal = seleccionarNumero();
                if(verificarLimiteLista(PosicionFinal))
                {
                    for(int i=0;i<PosicionFinal-PosicionInicial+1;i++)
                    {
                        personaModificar = getDatoLista(listaAuxiliar, i);
                        cambiarPersona(personaModificar);
                    }
                }
            break;
            default:
                mensajeError();
            break;
            }
        DeseaContinuar = MenuDeseaContinuar();
    }while(DeseaContinuar!=0);
}


void cambiarVehiculo(VehiculoPtr vehiculoAModificar)
{
    int nTipo=0;
    char nMarca[100];
    char nModelo[100];
    char nPatente[100];
    int seguirMod=0;
    do
    {
        system("cls");
        printf("Ha elegido - ");
        mostrarVehiculo(vehiculoAModificar);
        printf("\n\nQué desea modificar?\n\n");
        printf("1. Tipo de vehiculo\n");
        printf("2. Marca\n");
        printf("3. Modelo\n");
        printf("4. Patente\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&op);
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
                presionarEnterYLimpiarPantalla();
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
        case 5:
            printf("\n\nIngrese la nueva patente (AA 111 AA):\n\t");
            scanf("%[^\n]%*c",nPatente);
            setPatente(vehiculoAModificar,nPatente);
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
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


void menuModificarVehiculo(CentroLogisticoPtr centroLogistico)
{
    int iMod=0;
    int op=0;
    int MainMenu;
    int iMod=0;
    int op=0;
    int DeseaContinuar = 0;
    int MainMenu = 0;
    int cantidadModificar;
    int verificacionElecciones;
    int PosicionInicial, PosicionFinal;
    int eleccionesModificar[100];
    VehiculoPtr vehiculoModificar;
    ListaPtr listaAuxiliar = getVehiculos(centroLogistico);
    do
    {
        system("cls");
        printf("MODIFICAR VEHICULO \n");
        ///mostrarVehiculos(centroLogistico);
        MainMenu = MenuTipoSeleccion();
        switch(MainMenu)
        {
            case 1:
                printf("Seleccione un indice para modificar \n");
                iMod = seleccionarNumero();
                vehiculoModificar = getDatoLista(listaAuxiliar,iMod-1);
                cambiarVehiculo(vehiculoModificar);
            break;
            case 2:
                printf("Seleccione una cantidad de indices para modificar \n");
                cantidadModificar = seleccionarNumero();
                for(int i=0;i<cantidadModificar;i++)
                {
                    printf("Indice numero %d: ");
                    eleccionesModificar[i] = seleccionarNumero();
                }
                for(int i=0;i<cantidadModificar;i++)
                {
                    if(verificarLimiteLista(listaAuxiliar,eleccionesModificar[i]))
                    {
                        verificacionElecciones++;
                    }
                }
                if(verificacionElecciones==5)
                {
                    for(int i=0;i<cantidadModificar;i++)
                    {
                        vehiculoModificar = getDatoLista(listaAuxiliar, eleccionesModificar[i]);
                        cambiarVehiculo(vehiculoModificar);
                    }
                }
            break;
            case 3:
                printf("Seleccione los 2 indices en los cuales modificar \n");
                printf("Primer indice: ");
                PosicionInicial = seleccionarNumero();
                printf("Segundo indice: ");
                PosicionFinal = seleccionarNumero();
                if(verificarLimiteLista(PosicionFinal))
                {
                    for(int i=0;i<PosicionFinal-PosicionInicial+1;i++)
                    {
                        vehiculoModificar = getDatoLista(listaAuxiliar, i);
                        cambiarVehiculo(vehiculoModificar);
                    }
                }
            break;
            default:
                mensajeError();
            break;
        }
        DeseaContinuar = MenuDeseaContinuar();
    }while(DeseaContinuar!=0);
}


void menuArmarReparto(CentroLogisticoPtr centroLogistico)
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

    for(int i=0;i<n;i++)
    {
        if(n>1)
            printf("\n\nREPARTO %d\n\n",i+1);


        do
        {
            mostrarChoferes(centroLogistico);
            printf("\n\nSeleccione un chofer ingresando su indice: ");
            scanf("%d",&k);
            limpiarBufferTeclado();

            choferElegido=(PersonaPtr)getDatoLista(getPersonas(centroLogistico),k-1);
            if(getEsChofer(choferElegido)==false)
            {
                printf("\n\nERROR: el indice ingresado no corresponde a un chofer. Vuelva a elegir.\n\n");
                system("cls");
            }
        } while(getEsChofer(choferElegido)==false);

        presionarEnterYLimpiarPantalla();

        mostrarVehiculos(centroLogistico);
        printf("\n\nSeleccione un vehiculo ingresando su indice: ");
        scanf("%d",&k);
        limpiarBufferTeclado();
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
            mostrarPaquetes(centroLogistico);
            if(cantPaquetesElegidos>1)
                printf("\n\nPaquete N. %d\n",j+1);
            printf("Seleccione el paquete a cargar ingresando su indice: ");
            scanf("%d",&k);
            limpiarBufferTeclado();
            paqueteElegido=getDatoLista(getPaquetes(centroLogistico),k-1);
            apilar(pilaPaquetesElegidos,(PaquetePtr)paqueteElegido);
            system("cls");
        }


        reparto=armarReparto(choferElegido,vehiculoElegido,fechaSalida,fechaRetorno,pilaPaquetesElegidos);
        agregarReparto(centroLogistico,reparto,true);

        printf("\n\nReparto armado exitosamente.\n\n");
        presionarEnterYLimpiarPantalla();
    }
    if(n>1)
        printf("Repartos cargados exitosamente.\n\n");
}


int MenuSeleccionAtributoReparto()
{
    system("cls");
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
    int SubMenu;
    PersonaPtr choferModificar;
    VehiculoPtr vehiculoModificar;
    FechaPtr fechaModificar;
    PaquetePtr paqueteModificar;
    SubMenu = MenuSeleccionAtributoReparto();
    do
    {
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
                printf("MODIFICAR PAQUETE \n");
                ///mostrarPaquetesReparto(repartoModificar);
                printf("Seleccione un paquete ")
                cantidadPaquetesTotales = longitudPila(pilaPaquetes);
                for(int i=0;i<cantidadPaquetesTotales;i++)
                {
                    paquetes[i] = descargarPaquete(repartoModificar);
                }
                paqueteModificar = paquetes[iMod];
                cambiarPaquete(paqueteModificar);
                for(int i=cantidadPaquetesTotales;i>0;i--)
                {
                    cargarPaquete(repartoModificar,paquetes[i]);
                }
            break;
            default:
                mensajeError();
            break;
        }
        printf("\n\nDatos modificados exitosamente.\n\n");
        printf("Desea seguir modificando este vehiculo?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&seguirMod);
    }while(seguirMod!=0);
}



void menuModificarReparto(CentroLogisticoPtr centroLogistico)
{
    int iMod=0;
    int op=0;
    int MainMenu;
    int SubMenu;
    int DeseaContinuar = 0;
    int cantidadModificar;
    int verificacionElecciones;
    int PosicionInicial, PosicionFinal;
    int eleccionesModificar[100];
    RepartoPtr repartoModificar;
    ListaPtr listaAuxiliar = getRepartos(centroLogistico);
    PilaPtr pilaPaquetes = crearPila();
    int cantidadPaquetesTotales;
    PaquetePtr paquetes[100];
    do
    {
        system("cls");
        printf("MODIFICAR REPARTO \n");
        MainMenu = MenuTipoSeleccion();
        switch(MainMenu)
        {
            case 1:
                printf("Seleccione un indice de repartos: ");
                iMod = seleccionarNumero();
                repartoModificar = getDatoLista(listaAuxiliar,iMod);
                cambiarAtributoReparto(repartoModificar);
            break;
            case 2:
                printf("Seleccione una cantidad de indices de repartos: ");
                cantidadModificar = seleccionarNumero();
                for(int i=0;i<cantidadModificar;i++)
                {
                    printf("Indice numero %d: ");
                    eleccionesModificar[i] = seleccionarNumero();
                }
                for(int i=0;i<cantidadModificar;i++)
                {
                    if(verificarLimiteLista(listaAuxiliar, eleccionesModificar[i]))
                    {
                        verificacionElecciones++;
                    }
                }
                if(verificacionElecciones==5)
                {
                    for(int i=0;i<cantidadModificar;i++)
                    {
                        repartoModificar = getDatoLista(listaAuxiliar, eleccionesModificar[i]);
                        cambiarAtributoReparto(repartoModificar);
                    }
                }

            break;
            case 3:
                printf("Seleccione de indice a indice \n");
                printf("Primer indice: ");
                PosicionInicial = seleccionarNumero();
                printf("Segundo indice: ");
                PosicionFinal = seleccionarNumero();
                if(verificarLimiteLista(listaAuxiliar, PosicionFinal))
                {
                    for(int i=0;i<PosicionFinal-PosicionInicial+1;i++)
                    {
                        repartoModificar = getDatoLista(listaAuxiliar, i);
                        cambiarAtributoReparto(repartoModificar);
                    }
                }
            break;
        }

        DeseaContinuar = MenuDeseaContinuar();
    }while(DeseaContinuar!=0);
}



void menuBuscarReparto(CentroLogisticoPtr centroLogistico);
void menuCerrarReparto(CentroLogisticoPtr centroLogistico);
void menuMostrarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
	int op=0;
	int op1=0;

	int i=0;
	int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));

    do
    {
        if(esRepartoAbierto)
            printf("REPARTOS ABIERTOS\n\n");
        else
            printf("REPARTOS CERRADOS\n\n");

        printf("1. Mostrar reparto individual\n");
        printf("2. Mostrar listado completo\n");
        printf("3. Ordenar y mostrar...\n");
        printf("0. Volver\n\n");
        printf("Elija una opcion:");
        scanf("%d",&op);
        limpiarBufferTeclado();

        system("cls");
        switch(op)
        {
        case 1:
            do
            {
                mostrarRepartos(centroLogistico,esRepartoAbierto);

                printf("\nSeleccione un reparto para mostrar:");
                scanf("%d",&i);
                limpiarBufferTeclado();
                if(i<=0 || i>=n)
                    printf("\n\nERROR: indice inexistente. Vuelva a ingresarlo.\n\n");
                presionarEnterYLimpiarPantalla();
            } while(i>0 && i<n);

            mostrarReparto(getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),i-1));

            presionarEnterYLimpiarPantalla();
            break;
        case 2:
            mostrarRepartos(centroLogistico, esRepartoAbierto);
            presionarEnterYLimpiarPantalla();
            break;
        case 3:
            do
            {
                printf("ORDENAR Y MOSTRAR POR...");

                printf("1. Fecha de salida\n");
                printf("2. Fecha de retorno\n");
                printf("3. Fecha de salida y retorno\n");
                printf("4. Nombre del chofer\n");
                printf("5. Apellido del chofer\n");
                printf("6. Nombre y apellido del chofer\n");
                printf("0. Volver\n\n");

                printf("Elija una opcion: ");
                scanf("%d",&op1);

                system("cls");
                switch(op1)
                {
                case 1:
                    ordenarPorFechaSalida(centroLogistico,esRepartoAbierto);
                    break;
                case 2:
                    ordenarPorFechaRetorno(centroLogistico,esRepartoAbierto);
                    break;
                case 3:
                    ordenarPorFechaRepartos(centroLogistico,esRepartoAbierto);
                    break;
                case 4:
                    ordenarPorNombreChofer(centroLogistico,esRepartoAbierto);
                    break;
                case 5:
                    ordenarPorApellidoChofer(centroLogistico,esRepartoAbierto);
                    break;
                case 6:
                    ordenarPorChoferRepartos(centroLogistico,esRepartoAbierto);
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion incorrecta.\n\n");
                    break;
                }

                if(op1>=1 && op1<=6) //si se eligio volver o una opcion invalida,
                    mostrarRepartos(centroLogistico, esRepartoAbierto); //no mostramos nada.
                presionarEnterYLimpiarPantalla();
                system("cls");
            } while(op1!=0);
            break;
        case 0:
            break;
        default:
            printf("Opcion incorrecta\n\n");
            break;
        }
    } while(op!=0);
}


CentroLogisticoPtr menuCrearNuevoCtroLogRapido(CentroLogisticoPtr ctroLog)
{
    char nuevoNombre[100];

    printf("INGRESE EL NOMBRE DEL CENTRO LOGISTICO: ");
    scanf("%[^\n]%*c",nuevoNombre);

    ctroLog=crearCentroLogisticoRapido(nuevoNombre);

    return ctroLog;
}

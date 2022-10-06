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
        printf("CARGAR PAQUETE\n\n");
        printf("Ingrese cantidad de paquetes a cargar: ");
        scanf("%d",&n);
        limpiarBufferTeclado();

        if(n<1)
            printf("\nCantidad incorrecta.\n");
        presionarEnterYLimpiarPantalla();
    } while(n<1);

    for(int i=0;i<n;i++)
    {
        if(n>1)
            printf("\n\nPAQUETE %d\n\n",i+1);
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
        presionarEnterYLimpiarPantalla();
    }
    if(n>1)
        printf("Paquetes cargados exitosamente.\n\n");
}
void menuCargarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    ///Variables para funciones
    int n=0;
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
        system("cls");

        if(esChofer)
        {
            printf("CARGAR CHOFER\n\n");
            printf("Ingrese cantidad de choferes a cargar: ");
        }
        else
        {
            printf("CARGAR CLIENTE\n\n");
            printf("Ingrese cantidad de clientes a cargar: ");
        }
        scanf("%d",&n);
        limpiarBufferTeclado();
        if(n<1)
            printf("\nCantidad incorrecta.\n");
        presionarEnterYLimpiarPantalla();

    } while(n<1);


    for(int i=0;i<n;i++)
    {
        if(n>1)
        {
            if(esChofer)
                printf("CHOFER %d\n\n",i+1);
            else
                printf("CLIENTE %d\n\n",i+1);
        }
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
            printf("Cliente cargado exitosamente.\n\n");
        else
            printf("Cliente cargado exitosamente.\n\n");
        presionarEnterYLimpiarPantalla();
        system("pause");
    }
    if(esChofer && n>1)
        printf("Choferes cargados exitosamente.\n\n");
    else if(n>1)
        printf("Clientes cargados exitosamente.\n\n");

    presionarEnterYLimpiarPantalla();
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

    do
    {
        system("cls");
        printf("CARGAR VEHICULO\n\n");
        printf("Ingrese cantidad de vehiculos a cargar: ");
        scanf("%d",&n);
        limpiarBufferTeclado();

        if(n<1)
            printf("\nCantidad incorrecta.\n");
        presionarEnterYLimpiarPantalla();
    } while(n<1);

    for(int i=0;i<n;i++)
    {
        if(n>1)
            printf("\n\nVEHICULO %d\n\n",i+1);
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
        presionarEnterYLimpiarPantalla();
    }
    if(n>1)
    {
        printf("\n\nVehiculos cargados exitosamente.\n\n");
        presionarEnterYLimpiarPantalla();
    }
}

void menuBuscarPaquete(CentroLogisticoPtr centroLogistico)
{
    int op=0;

    do
    {
        int ID=0;

        system("cls");
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

        system("cls");
        printf("BUSCAR VEHICULO\n\n");

        printf("Ingrese la patente del vehiculo a buscar (AA 111 AA): ");
        scanf("%[^\n]%*c",patente);

        if(buscarVehiculo(centroLogistico,patente)==false)
            printf("\n\nNo se pudo encontrar el vehiculo con patente %s.\n\n",patente);
    } while(op!=0);
}

void menuEliminarPaquete(CentroLogisticoPtr centroLogistico)
{
    int iElim=0;

    system("cls");
    printf("ELIMINAR PAQUETE\n\n");

    mostrarPaquetes(centroLogistico);

    printf("\n\nSeleccione indice del paquete a eliminar: ");
    scanf("%d",&iElim);

    PaquetePtr paqueteRemovido=removerPaquete(centroLogistico,iElim);
    if(paqueteRemovido!=NULL)
        printf("\n\nPaquete #%d eliminado exitosamente.\n\n",getID(paqueteRemovido));
    else
        printf("\n\nEl paquete %d no se pudo eliminar.\n\n",iElim);

    paqueteRemovido=destruirPaquete(paqueteRemovido);
}
void menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    int iElim=0;

    system("cls");
    if(esChofer)
    {
        printf("ELIMINAR CHOFER\n\n");

        mostrarChoferes(centroLogistico);

        printf("\n\nSeleccione indice del chofer a eliminar: ");
        scanf("%d",&iElim);
    }
    else
    {
        printf("ELIMINAR CLIENTE\n\n");

        mostrarClientes(centroLogistico);

        printf("\n\nSeleccione indice del cliente a eliminar: ");
        scanf("%d",&iElim);
    }

    PersonaPtr personaRemovida=removerPersona(centroLogistico,iElim);
    if(personaRemovida!=NULL)
        printf("\n\nCliente %d eliminado exitosamente.\n\n",iElim);
    else
        printf("\n\nEl cliente %d no se pudo eliminar.\n\n",iElim);

    personaRemovida=destruirPersona(personaRemovida);
}
void menuEliminarVehiculo(CentroLogisticoPtr centroLogistico)
{
    int iElim=0;

    system("cls");
    printf("ELIMINAR VEHICULO\n\n");

    mostrarVehiculos(centroLogistico);

    printf("\n\nSeleccione indice del vehiculo a eliminar: ");
    scanf("%d",&iElim);

    VehiculoPtr vehiculoRemovido=removerVehiculo(centroLogistico,iElim);
    if(vehiculoRemovido!=NULL)
        printf("\n\nVehiculo %d eliminado exitosamente.\n\n",iElim);
    else
        printf("\n\nEl vehiculo %d no se pudo eliminar.\n\n",iElim);

    vehiculoRemovido=destruirVehiculo(vehiculoRemovido);
}

void menuModificarPaquete(CentroLogisticoPtr centroLogistico)
{
    int iMod=0;
    int op=0;
    int seguirMod=0; //para no volver a entrar al menu si queremos cambiar varios parámetros de un dato.

    int nAncho=0;
    int nAlto=0;
    int nLargo=0;
    int nPeso=0;

    DomicilioPtr nuevaDirRetiro;
    DomicilioPtr nuevaDirEntrega;
    FechaPtr nuevaFechaEntrega;

    int nEstado=0;

    system("cls");
    printf("MODIFICAR PAQUETE\n\n");

    mostrarPaquetes(centroLogistico);

    printf("\n\nIngrese indice del paquete a modificar: ");
    scanf("%d",&iMod);

    PaquetePtr paqueteAModificar=(PaquetePtr)getDatoLista(getPaquetes(centroLogistico),iMod-1); //-1 porque muestra con i+1 dentro de la funcion.

    do
    {
        system("cls");
        printf("Ha elegido el ");
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

        printf("Seleccione una opcion: ");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            printf("\n\nIngrese el nuevo ancho: ");
            scanf("%d",&nAncho);

            setAncho(paqueteAModificar,nAncho);
            break;
        case 2:
            printf("\n\nIngrese el nuevo alto: ");
            scanf("%d",&nAlto);

            setAlto(paqueteAModificar,nAlto);
            break;
        case 3:
            printf("\n\nIngrese el nuevo largo: ");
            scanf("%d",&nLargo);

            setLargo(paqueteAModificar,nLargo);
            break;
        case 4:
            printf("\n\nIngrese el nuevo peso: ");
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
        scanf("%d",&seguirMod);
    } while(seguirMod!=0);
}
void menuModificarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    int iMod=0;
    int op=0;
    int seguirMod=0;

    char nNombre[100];
    char nApellido[100];

    DomicilioPtr nuevoDomicilio;
    CuilPtr nuevoCuil;

//esChofer se puede modificar sin crear una variable

    system("cls");

    if(esChofer)
    {
        printf("MODIFICAR CHOFER\n\n");
        mostrarChoferes(centroLogistico);
        printf("\n\nIngrese indice del chofer a modificar: ");
    }
    else
    {
        printf("MODIFICAR CLIENTE\n\n");
        mostrarClientes(centroLogistico);
        printf("\n\nIngrese indice del cliente a modificar: ");
    }

    scanf("%d",&iMod);
//Obtenemos la persona del índice de la lista de personas que se eligió (-1 porque la funcion siempre obtiene el siguiente al pedido. CORROBORAR)
    PersonaPtr personaAModificar=(PersonaPtr)getDatoLista(getPersonas(centroLogistico),iMod-1);

    do
    {
        system("cls");
        printf("Ha elegido - ");
        mostrarPersona(personaAModificar);

        printf("\n\nQué desea modificar?\n\n");

        printf("1. Nombre y Apellido\n");
        printf("2. Domicilio\n");
        printf("3. CUIL\n");

        if(esChofer)
            printf("4. Cambiar persona a: CLIENTE\n");
        else
            printf("4. Cambiar persona a: CHOFER\n");

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
                setEsChofer(personaAModificar,false);
            else
                setEsChofer(personaAModificar,true);
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
void menuModificarVehiculo(CentroLogisticoPtr centroLogistico)
{
    int iMod=0;
    int op=0;
    int seguirMod=0;

    int nTipo=0;
    char nMarca[100];
    char nModelo[100];
    char nPatente[100];

    system("cls");
    printf("MODIFICAR VEHICULO\n\n");

    mostrarVehiculos(centroLogistico);

    printf("\n\nIngrese indice del vehiculo a modificar: ");
    scanf("%d",&iMod);

    VehiculoPtr vehiculoAModificar=(VehiculoPtr)getDatoLista(getVehiculos(centroLogistico),iMod-1);

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
        system("cls");
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

void menuMostrarEntregasReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    int eleccion;
    ListaPtr listaRepartos = crearLista();
    PilaPtr pilaPaquetes = crearPila();
    ListaPtr listaPaquetes = crearLista();
    RepartoPtr repartoAux;
    PaquetePtr paqueteAux;
    listaRepartos = getRepartos(centroLogistico, esRepartoAbierto);
    mostrarRepartos(centroLogistico, esRepartoAbierto);
    do
    {
        limpiarBufferTeclado();
        printf("Seleccione un reparto mediante su indice: ");
        printf("Eleccion: ");
        scanf("%d",&eleccion);
        limpiarBufferTeclado();
    }while(eleccion < 0);
    system("cls");
    repartoAux = getDatoLista(listaRepartos, eleccion-1);
    pilaPaquetes = getPaquetesReparto(repartoAux);
    while(!pilaVacia(pilaPaquetes))
    {
        paqueteAux = desapilar(pilaPaquetes);
        agregarDatoLista(listaPaquetes, (PaquetePtr)paqueteAux);
    }
    int i=0;
    while(i != longitudLista(listaPaquetes))
    {
        printf("Indice %d\n", i);
        mostrarPaquete(getDatoLista(listaAux, i));
        i++;
    }
    while(i != 0)
    {
        paqueteAux = getDatoLista(listaPaquetes, i);
        apilar(pilaPaquetes, (PaquetePtr)paqueteAux);
        i--;
    }
    listaRepartos = destruirLista(listaRepartos, false);
    listaPaquetes = destruirLista(listaRepartos, false);
}



void menuBuscarReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    int eleccion;
    ListaPtr listaRepartos = crearLista();
    RepartoPtr repartoAux;
    listaRepartos = getRepartos(centroLogistico, esRepartoAbierto);
    mostrarRepartos(centroLogistico, esRepartoAbierto);
    do
    {
        limpiarBufferTeclado();
        //Para devolver el reparto o para mostrarlo
        printf("Selecciona un reparto por su indice: ");
        scanf("%d",&eleccion);
        limpiarBufferTeclado();
    }while(eleccion < 0);
    repartoAux = getDatoLista(listaRepartos, eleccion-1);
    //return repartoAux; Por si se quiere el reparto
    //mostrarReparto(repartoAux); // por si se quiere mostrar simplemente
    listaRepartos = destruirLista(listaRepartos, false);
}


void menuEliminarReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    int eleccion;
    ListaPtr listaRepartos = crearLista();
    RepartoPtr repartoAux;
    listaRepartos = getRepartos(centroLogistico, esRepartoAbierto);
    mostrarRepartos(centroLogistico, esRepartoAbierto);
    do
    {
        limpiarBufferTeclado();
        //Para remvoerlo de la lista
        printf("Selecciona un reparto por su indice: ");
        scanf("%d",&eleccion);
        limpiarBufferTeclado();
    }while(eleccion < 0);
    repartoAux = removerDeLista(listaRepartos, eleccion-1);
    //return repartoAux; Por si se quiere el reparto
    //mostrarReparto(repartoAux); // por si se quiere mostrar simplemente
    listaRepartos = destruirLista(listaRepartos, false);
}


void menuCerrarReparto(CentroLogisticoPtr centroLogistico)
{
    int eleccion, totalPaquetes, i;
    bool resultadoBusqueda;
    ListaPtr listaAbiertos = crearLista();
    ListaPtr listaCerrados = crearLista();
    ListaPtr listaPaquetes = crearLista();
    PilaPtr pilaPaquetes = crearPila();
    RepartoPtr repartoAux;
    PaquetePtr paqueteAux;
    listaAbiertos = getRepartos(centroLogistico, true);
    mostrarRepartos(centroLogistico, true);
    do
    {
        limpiarBufferTeclado();
        //Para seleccionar el reparto
        printf("Selecciona un reparto por su indice: ");
        scanf("%d",&eleccion);
        limpiarBufferTeclado();
    }while(eleccion < 0 && eleccion > longitudLista(listaAbiertos));
    pilaPaquetes = getPaquetesReparto(repartoAux);
    while(!pilaVacia(pilaPaquetes))
    {
        paqueteAux = desapilar(pilaPaquetes);
        agregarDatoLista(listaPaquetes, (PaquetePtr)paqueteAux)
    }
    totalPaquetes = longitudLista(listaPaquetes);
    i = 0;
    while(i <= totalPaquetes)
    {
        paqueteAux = getDatoLista(listaPaquetes, i);
        if(getEstado(paqueteAux) != 0 && getEstado(paqueteAux) != 3)
        {
            paqueteAux = getDatoLista(listaPaquetes,i);
            resultadoBusqueda = buscarPaquete(centroLogistico, getID(paqueteAux));
            if(resultadoBusqueda)
                setEstado(paqueteAux, 0);
        }
        i++;
    }
    i = totalPaquetes;
    while(i > -1)
    {
        paqueteAux = getDatoLista(listaPaquetes, i);
        apilar(pilaPaquetes, (PaquetePtr)paqueteAux);
        i--;
    }
    repartoAux = removerDeLista(listaAbiertos, eleccion-1);
    agregarDatoLista(listaCerrados,(RepartoPtr)repartoAux);

    listaAbiertos = destruirLista(listaAbiertos, false);
    listaCerrados = destruirLista(listaCerrados, false);
    listaPaquetes = destruirLista(listaPaquetes, false);
    pilaPaquetes = destruirPila(pilaPaquetes);
}


void menuActualizarReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto)
{
    int eleccion, i;
    ListaPtr listaRepartos = crearLista();
    ListaPtr listaPaquetes = crearLista();
    PilaPtr pilaPaquetes = crearPila();
    PaquetePtr paqueteAux;
    RepartoPtr repartoAux;
    listaRepartos = getRepartos(centroLogistico, esRepartoAbierto);
    mostrarRepartos(centroLogistico, esRepartoAbierto);
    do
    {
        limpiarBufferTeclado();
        //Para modificar el reparto
        printf("Selecciona un reparto por su indice: ");
        scanf("%d",&eleccion);
        limpiarBufferTeclado();
    }while(eleccion < 0 && eleccion > longitudLista(listaRepartos));
    repartoAux = getDatoLista(listaRepartos, eleccion-1);
    pilaPaquetes = getPaquetesReparto(repartoAux);
    while(!pilaVacia)
    {
        paqueteAux = desapilar(pilaPaquetes);
        mostrarPaquete(paqueteAux);
        agregarDatoLista(listaPaquetes, paqueteAux);
    }
    do
    {
        limpiarBufferTeclado();
        //Para modificar el paquete
        printf("Selecciona un paquete por su indice: ");
        scanf("%d",&eleccion);
        limpiarBufferTeclado();
    }while(eleccion < 0 && eleccion > longitudLista(listaPaquetes));
    system("cls");
    paqueteAux = getDatoLista(listaPaquetes, eleccion-1);
    helpEstadoPaquete();
    do
    {
        limpiarBufferTeclado();
        printf("Seleccione un estado mediante su indice: ");
        printf("Eleccion: ");
        scanf("%d",&eleccion);
        limpiarBufferTeclado();
    }while(eleccion < 0 && eleccion < 4);
    system("cls");
    limpiarBufferTeclado();
    setEstado(paqueteAux, eleccion);
    i=longitudLista(listaPaquetes);
    while(i != -1)
    {
        paqueteAux = getDatoLista(listaPaquetes, i);
        apilar(pilaPaquetes, paqueteAux);
        i--;
    }
    listaRepartos = destruirLista(listaRepartos, false);
}


void menuMostrarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto)
{
	int op=0;
	int op1=0;

	int i=0;
	int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));

    do
    {
        system("cls");
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

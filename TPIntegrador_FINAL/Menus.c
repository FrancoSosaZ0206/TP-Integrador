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

CuilPtr cargarCuil(CuilPtr cuil){
    char strCuil[100];
    int i=0;
    do{
        helpCuil();
        printf("\n\tIngresar el cuil de esta forma ");
        printf("[TIPO DE PERSONA - DOCUMENTO DE IDENTIDAD - NUMERO DE VERIFICACION]\n");
        printf("CUIL: ");
        SeleccionarStringEstatico(strCuil);
        if(i==0)
            cuil=crearCuil(strCuil); ///IMPLEMENTACION CAMBIADA
        if(i>0 && i<4)
            cuil=setCuil(cuil,strCuil);
        if(i==4)
            printf("\n\nIntentos agotados.\n\n");
        i++;
        if(i>1)
            system("cls");
    }while(!esCuilValido(cuil));
    return cuil;
}

DomicilioPtr cargarDomicilio(DomicilioPtr domicilio){
    char calle[100];
    int altura;
    char localidad[100];
    printf("\n\t\t [CALLE] : ");
    SeleccionarStringEstatico(calle);
    printf("\n\t\t [ALTURA] : ");
    altura =  SeleccionarNumero();
    printf("\n\t\t [LOCALIDAD] : ");
    SeleccionarStringEstatico(localidad);
    domicilio = crearDomicilio(calle, altura, localidad);
    return domicilio;
}

FechaPtr cargarFecha(FechaPtr fecha){
    int dia = 0, mes = 0, anio = 0, hora = 0, minuto = 0;
    bool primeraVez = true;
    fecha = crearFecha(dia, mes, anio, hora, minuto);
    do{
        limpiarBufferTeclado();
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
        if(!esFechaValida(fecha)){
            printf("\n\nFecha invalida. Reingrese la fecha.\n\n");
            primeraVez=false;
        }
        if(primeraVez==false)
            system("cls");
    }while(!esFechaValida(fecha));
    return fecha;
}



void actualizarCuil(CuilPtr cuil){
    char strCuil[100];
    int i=0;
    do{
        helpCuil();
        printf("\n\tNuevo CUIL:");
        scanf("%[^\n]%*c",strCuil);
        limpiarBufferTeclado();
        if(i<4)
            setCuil(cuil,strCuil);
        if(i==4)
            printf("\n\nIntentos agotados.\n\n");
        if(i>1)
            system("cls");
        i++;
    }while(!esCuilValido(cuil));
}

void actualizarDomicilio(DomicilioPtr domicilio){
    char calle[100];
    int altura;
    char localidad[100];
    limpiarBufferTeclado();
    printf("\n\t\t Calle: ");
    scanf("%[^,]%*c",calle);
    limpiarBufferTeclado();
    printf("\n\t\t Altura: ");
    scanf("%d",&altura);
    limpiarBufferTeclado();
    printf("\n\t\t Localidad: ");
    scanf("%[^\n]%*c",localidad);
    limpiarBufferTeclado();
    setCalle(domicilio,calle);
    setAltura(domicilio,altura);
    setLocalidad(domicilio,localidad);
}

void actualizarFecha(FechaPtr fecha){
    int dia=0,mes=0,anio=0,hora=0,minuto=0,i=0;
    do{
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
        if(!esFechaValida(fecha) && i<4){
            printf("\n\nFecha invalida. Reingrese la fecha.\n\n");
            system("cls");
        }
        if(i==4){
            system("cls");
            printf("\n\nSe agotaron los intentos.\n\n");
            system("pause");
            break;
        }
    }while(!esFechaValida(fecha));
}

PersonaPtr actualizarCliente(PersonaPtr cliente){
    int eleccion;
    char nombre[100];
    char apellido[100];
    DomicilioPtr domicilio = getDomicilio(cliente);
    CuilPtr Cuil = getCuilPersona(cliente);
    char cuil[100];
    system("cls");
    limpiarBufferTeclado();
    printf("1. Modificar nombre y apellido\n");
    printf("2. Modificar domicilio\n");
    printf("3. Modificar cuil\n");
    scanf("%d",&eleccion);
    limpiarBufferTeclado();
    switch(eleccion){
    case 1:
        limpiarBufferTeclado();
        printf("Nombre:");
        scanf("%[^\n]%*c",nombre);
        limpiarBufferTeclado();
        printf("Apellido:");
        scanf("%[^\n]%*c",apellido);
        limpiarBufferTeclado();
        setNombre(cliente,nombre);
        setApellido(cliente,apellido);
        break;
    case 2:
        actualizarDomicilio(domicilio);
        break;
    case 3:
        limpiarBufferTeclado();
        printf("Cuil:");
        scanf("%[^\n]%*c", cuil);
        limpiarBufferTeclado();
        Cuil = setCuil(Cuil,cuil);
        break;
    }
    return cliente;
}


int MenuSeleccion()
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


void menuCargarPaquete(CentroLogisticoPtr centroLogistico){
    int n=0,ID=0,ancho=0,alto=0,largo=0,peso=0;
    int DeseaContinuar = 0;
    PaquetePtr paquete;
    FechaPtr fechaEntrega;
    DomicilioPtr dirRetiro;
    DomicilioPtr dirEntrega;
    do{
        system("cls");
        printf("\n\nPAQUETE %d\n\n",i+1);
        limpiarBufferTeclado();
        ID=rand(); //esto no se mostrar� sino al final de la carga del paquete.
        limpiarBufferTeclado();
        printf("\n\tAncho: ");
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
        limpiarBufferTeclado();
        printf("\n\tDireccion de entrega:");
        dirEntrega=cargarDomicilio(dirEntrega);
        printf("\n\tFecha de entrega:");
        limpiarBufferTeclado();
        fechaEntrega=cargarFecha(fechaEntrega);
        limpiarBufferTeclado();
        system("cls");
        PersonaPtr cliente=menuCargarCliente(centroLogistico);
        paquete=crearPaquete(ID,ancho,alto,largo,peso,dirRetiro,dirEntrega,fechaEntrega,cliente,0);
        agregarPaquete(centroLogistico,paquete);
        printf("\n\nPaquete #%d cargado exitosamente.\n\n",ID);
        DeseaContinuar = MenuDeseaContinuar();
    }while(DeseaContinuar!=0);
}

void menuCargarCliente(CentroLogisticoPtr centroLogistico){
    int n=0,posicionEncontrado=0;
    int DeseaContinuar = 0;
    char nombre[100];
    char apellido[100];
    PersonaPtr cliente;
    DomicilioPtr domicilio;
    CuilPtr cuil;
    do{
        system("cls");
        printf("CLIENTE %d\n\n",i+1);
        limpiarBufferTeclado();
        printf("\n\n\tNombre: ");
        scanf("%[^\n]%*c",nombre);
        limpiarBufferTeclado();
        printf("\n\tApellido: ");
        scanf("%[^\n]%*c",apellido);
        limpiarBufferTeclado();
        printf("\n\tDomicilio");
        domicilio=cargarDomicilio(domicilio);
        limpiarBufferTeclado();
        cuil=cargarCuil(cuil);
        limpiarBufferTeclado();
        posicionEncontrado=buscarCliente(centroLogistico,getCuil(cuil));
        if(posicionEncontrado==-1){
            cliente=crearPersona(nombre,apellido,domicilio,cuil,false);
            agregarDatoLista(getClientes(centroLogistico),(PersonaPtr)cliente);
        }else{
            printf("No se pudo agregar debido a que ya existe\n");
            system("pause");
        }
    }while(DeseaContinuar!=0);
}

void menuCargarChofer(CentroLogisticoPtr centroLogistico){
    int n=0,posicionEncontrado=0;
    char nombre[100];
    char apellido[100];
    PersonaPtr chofer;
    DomicilioPtr domicilio;
    CuilPtr cuil;
    do{
        system("cls");
        limpiarBufferTeclado();
        printf("CARGAR CHOFER\n\n");
        printf("Ingrese cantidad de clientes a cargar: ");
        scanf("%d",&n);
        if(n<1)
            printf("\nCantidad incorrecta.\n");
        system("cls");
    }while(n<1);
    for(int i=0;i<n;i++){
        printf("CLIENTE %d\n\n",i+1);
        limpiarBufferTeclado();
        printf("\n\n\tNombre: ");
        scanf("%[^\n]%*c",nombre);
        limpiarBufferTeclado();
        printf("\n\tApellido: ");
        scanf("%[^\n]%*c",apellido);
        limpiarBufferTeclado();
        printf("\n\tDomicilio");
        domicilio=cargarDomicilio(domicilio);
        limpiarBufferTeclado();
        cuil=cargarCuil(cuil);
        limpiarBufferTeclado();
        posicionEncontrado=buscarChofer(centroLogistico,getCuil(cuil));
        if(posicionEncontrado==-1){
            chofer=crearPersona(nombre,apellido,domicilio,cuil,true);
            agregarDatoLista(getChoferes(centroLogistico),(PersonaPtr)chofer);
        }else{
            printf("No se pudo agregar debido a que ya existe\n");
            system("pause");
        }
    }
}

void menuCargarVehiculo(CentroLogisticoPtr centroLogistico){
    int n=0,tipoVehiculo=0,posicionEncontrado=0;
    char marca[100];
    char modelo[100];
    char patente[100];
    VehiculoPtr vehiculo;
    do{
        limpiarBufferTeclado();
        system("cls");
        printf("CARGAR VEHICULO\n\n");
        printf("Ingrese cantidad de vehiculos a cargar: ");
        scanf("%d",&n);
        limpiarBufferTeclado();
        if(n<1)
            printf("\nCantidad incorrecta.\n");
        system("cls");
    }while(n<1);
    for(int i=0;i<n;i++){
        if(n>1)
            printf("\n\nVEHICULO %d\n\n",i+1);
        limpiarBufferTeclado();
        helpTipoVehiculo();
        printf("\n\n\tSeleccione un Tipo: ");
        scanf("%d",&tipoVehiculo);
        limpiarBufferTeclado();
        printf("\n\n\tMarca: ");
        scanf("%[^\n]%*c",marca);
        limpiarBufferTeclado();
        printf("\n\tModelo: ");
        scanf("%[^\n]%*c",modelo);
        limpiarBufferTeclado();
        printf("\n\tPatente (AA 000 AA): ");
        scanf("%[^\n]%*c",patente);
        limpiarBufferTeclado();
        posicionEncontrado=buscarVehiculo(centroLogistico,patente);
        if(posicionEncontrado==-1){
            vehiculo=crearVehiculo(tipoVehiculo,marca,modelo,patente);
            agregarDatoLista(getVehiculos(centroLogistico),vehiculo);
        }else{
            printf("Ya existe este vehiculo\n");
            system("pause");
        }
    }
}






void menuBuscarPaquete(CentroLogisticoPtr centroLogistico){
    int op=0;
    do{
        int ID=0,posicionEncontrada=0;
        system("cls");
        limpiarBufferTeclado();
        printf("BUSCAR PAQUETE\n\n");
        printf("Ingrese ID del paquete a buscar: ");
        scanf("%d",&ID);
        limpiarBufferTeclado();
        printf("\n\n");
        posicionEncontrada=buscarPaquete(centroLogistico,ID);
        if(posicionEncontrada!=-1)
            mostrarPaquete(getDatoLista(getPaquetes(centroLogistico),posicionEncontrada));
        else
            printf("No existe ese ID\n");
        printf("Volver? 1=Si, 0=No");
        scanf("%d",&op);
        limpiarBufferTeclado();
    }while(op!=0);
}

void menuBuscarCliente(CentroLogisticoPtr centroLogistico){
    int op=0,posicionEncontrado=0;
    char cuilABuscar[100];
    do{
        system("cls"); limpiarBufferTeclado();
        printf("BUSCAR CLIENTE\n\n");
        printf("Ingrese el CUIL del cliente a buscar: ");
        scanf("%[^\n]%*c", cuilABuscar);
        posicionEncontrado=buscarCliente(centroLogistico,cuilABuscar);
        if(posicionEncontrado!=-1)
            mostrarPersona(getDatoLista(getClientes(centroLogistico),posicionEncontrado));
        printf("Volver? 0=Si, 1=No");
        scanf("%d",&op);
    }while(op!=0);
}

void menuBuscarChofer(CentroLogisticoPtr centroLogistico){
    int op=0,posicionEncontrado=0;
    char cuilABuscar[100];
    do{
        system("cls"); limpiarBufferTeclado();
        printf("BUSCAR CHOFER\n\n");
        printf("Ingrese el CUIL del CHOFER a buscar: ");
        scanf("%[^\n]%*c", cuilABuscar);
        posicionEncontrado=buscarChofer(centroLogistico,cuilABuscar);
        if(posicionEncontrado!=-1)
            mostrarPersona(getDatoLista(getChoferes(centroLogistico),posicionEncontrado));
        printf("Volver? 0=Si, 1=No");
        scanf("%d",&op);
    }while(op!=0);
}

void menuBuscarVehiculo(CentroLogisticoPtr centroLogistico){
    int op=0,posicionEncontrado=0;
    do{
        char patente[100];
        system("cls"); limpiarBufferTeclado();
        printf("BUSCAR VEHICULO\n\n");
        printf("Ingrese la patente del vehiculo a buscar (AA 111 AA): ");
        scanf("%[^\n]%*c",patente);
        posicionEncontrado=buscarVehiculo(centroLogistico,patente);
        if(posicionEncontrado!=-1)
            mostrarVehiculo(getDatoLista(getVehiculos(centroLogistico),posicionEncontrado));
    }while(op!=0);
}


int menuSeleccionEliminar(){
    int eleccion;
    limpiarBufferTeclado();
    printf("1. Seleccionar indice unico\n");
    printf("2. Seleccionar indice a indice (4 - 7)\n");
    printf("Opcion: ");
    scanf("%d",&eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

void menuEliminarPaqueteNuevo(CentroLogisticoPtr centroLogistico){
    int iElim,cantidad,Main,posicionInicial,posicionFinal;
    ListaPtr listaPaquetes=getPaquetes(centroLogistico);
    Main=menuSeleccionEliminar();
    switch(Main){
    case 1:
        cantidad=seleccionarCantidad();
        for(int i=0;i<cantidad;i++){
            system("cls");
            mostrarPaquetes(centroLogistico);
            iElim=seleccionarNumero();
            if(verificarLimiteLista(getPaquetes(centroLogistico),iElim)){
                removerPaquete(centroLogistico,iElim);
            }
        }
        break;
    case 2:
        cantidad=seleccionarCantidad();
        for(int i=0;i<cantidad;i++){
            system("cls");
            mostrarPaquetes(centroLogistico);
            printf("Seleccionar primer y segundo indice {1 - 3}\n");
            posicionInicial=seleccionarNumero();
            posicionFinal=seleccionarNumero();
            if(verificarLimiteLista(listaPaquetes,posicionInicial)){
                if(verificarLimiteLista(listaPaquetes,posicionFinal)){
                    for(int i=0;i<posicionFinal-posicionInicial+1;i++){
                        removerPaquete(centroLogistico,posicionInicial);
                    }
                }
            }
        }
        break;
    default:
        mensajeError();
        break;
    }
}

void menuEliminarCliente(CentroLogisticoPtr centroLogistico){
    int iElim=0;
    system("cls");
    if(longitudLista(getClientes(centroLogistico))!=0){
        printf("ELIMINAR CLIENTE\n\n");
        mostrarClientes(centroLogistico);
        printf("\n\nSeleccione indice del cliente a eliminar: ");
        scanf("%d",&iElim);
        if(iElim>=0 && iElim<longitudLista(getClientes(centroLogistico)))
            removerDeLista(getClientes(centroLogistico),iElim);
    }else{
        printf("No existen clientes para remover\n");
    }
}

void menuEliminarClienteNuevo(CentroLogisticoPtr centroLogistico){
    int posicionEliminar,cantidad,Main,posicionInicial,posicionFinal;
    ListaPtr listaClientes=getClientes(centroLogistico);
    Main=menuSeleccionEliminar();
    switch(Main){
    case 1:
        cantidad=seleccionarCantidad();
        for(int i=0;i<cantidad;i++){
            system("cls");
            mostrarClientes(centroLogistico);
            posicionEliminar=seleccionarNumero();
            if(verificarLimiteLista(listaClientes,posicionEliminar)){
                removerCliente(centroLogistico,posicionEliminar);
            }
        }
        break;
    case 2:
        cantidad=seleccionarCantidad();
        for(int i=0;i<cantidad;i++){
            system("cls");
            mostrarClientes(centroLogistico);
            printf("Seleccionar indice a indice [1 - 3]\n");
            posicionInicial=seleccionarNumero();
            posicionFinal=seleccionarNumero();
            if(verificarLimiteLista(listaClientes,posicionInicial)){
                if(verificarLimiteLista(listaClientes,posicionFinal)){
                    for(int i=0;i<posicionFinal-posicionInicial+1;i++){
                        removerCliente(centroLogistico,posicionInicial);
                    }
                }
            }
        }
        break;
    default:
        mensajeError();
        break;
    }
}

void menuEliminarPaquete(CentroLogisticoPtr centroLogistico){
    int iElim=0;
    system("cls");
    if(longitudLista(getPaquetes(centroLogistico))!=0){
        printf("ELIMINAR CLIENTE\n\n");
        mostrarPaquetes(centroLogistico);
        printf("\n\nSeleccione indice del paquete a eliminar: ");
        scanf("%d",&iElim);
        if(iElim>=0 && iElim<longitudLista(getClientes(centroLogistico)))
            removerDeLista(getPaquetes(centroLogistico),iElim);
    }else{
        printf("No existen paquetes para remover\n");
    }
}

void menuEliminarChofer(CentroLogisticoPtr centroLogistico){
    int iElim=0;
    system("cls");
    if(longitudLista(getChoferes(centroLogistico))!=0){
        printf("ELIMINAR CHOFER\n\n");
        mostrarChoferes(centroLogistico);
        printf("\n\nSeleccione indice del chofer a eliminar: ");
        scanf("%d",&iElim);
        if(iElim>=0 && iElim<longitudLista(getChoferes(centroLogistico)))
            removerDeLista(getChoferes(centroLogistico),iElim);
    }else{
        printf("No existen choferes para remover\n");
    }
}

void menuEliminarChoferNuevo(CentroLogisticoPtr centroLogistico){
    int posicionEliminar,posicionInicial,posicionFinal,cantidad,Main;
    ListaPtr listaChoferes=getChoferes(centroLogistico);
    Main=menuSeleccionEliminar();
    switch(Main){
    case 1:
        cantidad=seleccionarCantidad();
        for(int i=0;i<cantidad;i++){
            posicionEliminar=seleccionarNumero();
            if(verificarLimiteLista(listaChoferes,posicionEliminar)){
                removerChofer(centroLogistico,posicionEliminar);
            }
        }
        break;
    case 2:
        cantidad=seleccionarCantidad();
        for(int i=0;i<cantidad;i++){
            printf("Seleccionar de indice a indice [1 - 3]\n");
            posicionInicial=seleccionarNumero();
            posicionFinal=seleccionarNumero();
            if(verificarLimiteLista(listaChoferes,posicionInicial)){
                if(verificarLimiteLista(listaChoferes,posicionFinal)){
                    for(int i=0;i<posicionFinal-posicionInicial+1;i++){
                        removerChofer(centroLogistico,posicionInicial);
                    }
                }
            }
        }
        break;
    default:
        mensajeError();
        break;
    }
}

void menuEliminarVehiculo(CentroLogisticoPtr centroLogistico){
    int iElim=0;
    system("cls");
    if(longitudLista(getVehiculos(centroLogistico))!=0){
        printf("ELIMINAR VEHICULO\n\n");
        mostrarVehiculos(centroLogistico);
        printf("\n\nSeleccione indice del vehiculo a eliminar: ");
        scanf("%d",&iElim);
        if(iElim>=0 && iElim<longitudLista(getVehiculos(centroLogistico)))
            removerVehiculo(centroLogistico,iElim);
    }else{
        printf("No existen vehiculos para remover\n");
    }
}

void menuEliminarVehiculoNuevo(CentroLogisticoPtr centroLogistico){
    int posicionEliminar,posicionInicial,posicionFinal,cantidad,Main;
    ListaPtr listaVehiculos=getVehiculos(centroLogistico);
    Main=menuSeleccionEliminar();
    switch(Main){
        case 1:
            cantidad=seleccionarCantidad();
            for(int i=0;i<cantidad;i++){
                posicionEliminar=seleccionarNumero();
                if(verificarLimiteLista(listaVehiculos,posicionEliminar)){
                    removerVehiculo(centroLogistico,posicionEliminar);
                }
            }
            break;
        case 2:
            cantidad=seleccionarCantidad();
            for(int i=0;i<cantidad;i++){
                printf("Selecione el primer y segundo indice [1 - 3]\n");
                posicionInicial=seleccionarNumero();
                posicionFinal=seleccionarNumero();
                if(verificarLimiteLista(listaVehiculos,posicionInicial)){
                    if(verificarLimiteLista(listaVehiculos,posicionFinal)){
                        for(int i=0;i<posicionFinal-posicionInicial+1;i++){
                            removerVehiculo(centroLogistico,posicionInicial);
                        }
                    }
                }
            }
            break;
        default:
            mensajeError();
            break;
    }
}


void menuModificarPaquete(CentroLogisticoPtr centroLogistico){
    int iMod=0,op=0,seguirMod=0,nAncho=0,nAlto=0,nLargo=0,nPeso=0,nEstado=0;
    DomicilioPtr nuevaDirRetiro=NULL;
    DomicilioPtr nuevaDirEntrega=NULL;
    FechaPtr nuevaFechaEntrega=NULL;
    PersonaPtr cliente;
    system("cls");
    printf("MODIFICAR PAQUETE\n\n");
    mostrarPaquetes(centroLogistico);
    printf("\n\nIngrese indice del paquete a modificar: ");
    scanf("%d",&iMod);
    //-1 porque muestra con i+1 dentro de la funcion.
    PaquetePtr paqueteAModificar=(PaquetePtr)getDatoLista(getPaquetes(centroLogistico),iMod);
    cliente = getClientePaquete(paqueteAModificar);
    do{
        system("cls");
        limpiarBufferTeclado();
        printf("Ha elegido el ");
        mostrarPaquete(paqueteAModificar);
        printf("\n\nQu� desea modificar?\n\n");
        printf("1. Ancho\n");
        printf("2. Alto\n");
        printf("3. Largo\n");
        printf("4. Peso\n");
        printf("5. Direccion de Retiro\n");
        printf("6. Direccion de Entrega\n");
        printf("7. Fecha de Entrega\n");
        printf("8. Estado\n");
        printf("9. Modificar al destinatario\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&op);
        limpiarBufferTeclado();
        switch(op){
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
        case 9:
            cliente = actualizarCliente(cliente);
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            system("cls");
            break;
        }
        limpiarBufferTeclado();
        printf("\n\nDatos modificados exitosamente.\n\n");
        printf("Desea seguir modificando este paquete?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&seguirMod);
        limpiarBufferTeclado();
    }while(seguirMod!=0);
}

void menuModificarCliente(CentroLogisticoPtr centroLogistico){
    int iMod=0,op=0,seguirMod=0,cantidadPersonas=0;
    char nNombre[100];
    char nApellido[100];
    DomicilioPtr nuevoDomicilio=NULL;
    CuilPtr nuevoCuil=NULL;
    system("cls");
    printf("MODIFICAR CLIENTE\n\n");
    mostrarChoferes(centroLogistico);
    cantidadPersonas=longitudLista(getChoferes(centroLogistico));
    printf("\n\nIngrese indice del cliente a modificar: ");
    scanf("%d",&iMod);
    if(iMod>0 && iMod<cantidadPersonas){
        PersonaPtr personaAModificar=(PersonaPtr)getDatoLista(getClientes(centroLogistico),iMod);
        do{
            system("cls");
            printf("Ha elegido - ");
            mostrarPersona(personaAModificar);
            printf("\n\nQu� desea modificar?\n\n");
            printf("1. Nombre y Apellido\n");
            printf("2. Domicilio\n");
            printf("3. CUIL\n");
            printf("Seleccione una opcion: ");
            scanf("%d",&op);
            switch(op){
            case 1:
                limpiarBufferTeclado();
                printf("\n\nIngrese el nuevo nombre y apellido de esta manera:");
                printf("\n\t[NOMBRE]\n\t");
                scanf("%[^\n]%*c",nNombre);
                limpiarBufferTeclado();
                printf("\n\t[APELLIDO]\n\t");
                scanf("%[^\n]%*c",nApellido);
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
            default:
                printf("\nOpcion incorrecta.\n\n");
                system("cls");
                break;
            }
            printf("\n\nDatos modificados exitosamente.\n\n");
            printf("Desea seguir modificando esta persona?\n\n");
            printf("\t1. SI\n\t");
            printf("0. NO\n\n");
            printf("Seleccione una opcion: ");
            scanf("%d",&seguirMod);
        }while(seguirMod!=0);
    }else{
        printf("Seleccion inexistente\n");
    }
}

void menuModificarChofer(CentroLogisticoPtr centroLogistico){
    int iMod=0,op=0,seguirMod=0,cantidadPersonas=0;
    char nNombre[100];
    char nApellido[100];
    DomicilioPtr nuevoDomicilio=NULL;
    CuilPtr nuevoCuil=NULL;
    system("cls");
    printf("MODIFICAR CHOFER\n\n");
    mostrarChoferes(centroLogistico);
    cantidadPersonas=longitudLista(getChoferes(centroLogistico));
    printf("\n\nIngrese indice del chofer a modificar: ");
    scanf("%d",&iMod);
    if(iMod>0 && iMod<cantidadPersonas){
        PersonaPtr personaAModificar=(PersonaPtr)getDatoLista(getChoferes(centroLogistico),iMod);
        do{
            system("cls");
            printf("Ha elegido - ");
            mostrarPersona(personaAModificar);
            printf("\n\nQu� desea modificar?\n\n");
            printf("1. Nombre y Apellido\n");
            printf("2. Domicilio\n");
            printf("3. CUIL\n");
            printf("Seleccione una opcion: ");
            scanf("%d",&op);
            switch(op){
            case 1:
                limpiarBufferTeclado();
                printf("\n\nIngrese el nuevo nombre y apellido de esta manera:");
                printf("\n\t[NOMBRE]\n\t");
                scanf("%[^\n]%*c",nNombre);
                limpiarBufferTeclado();
                printf("\n\t[APELLIDO]\n\t");
                scanf("%[^\n]%*c",nApellido);
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
            default:
                printf("\nOpcion incorrecta.\n\n");
                system("cls");
                break;
            }

            printf("\n\nDatos modificados exitosamente.\n\n");
            printf("Desea seguir modificando esta persona?\n\n");
            printf("\t1. SI\n\t");
            printf("0. NO\n\n");
            printf("Seleccione una opcion: ");
            scanf("%d",&seguirMod);
        }while(seguirMod!=0);
    }else{
        printf("Seleccion inexistente\n");
    }
}

void menuModificarVehiculo(CentroLogisticoPtr centroLogistico){
    int iMod=0,op=0,seguirMod=0,nTipo=0;
    char nMarca[100];
    char nModelo[100];
    char nPatente[100];
    system("cls");
    printf("MODIFICAR VEHICULO\n\n");
    mostrarVehiculos(centroLogistico);
    printf("\n\nIngrese indice del vehiculo a modificar: ");
    scanf("%d",&iMod);
    if(iMod>0 && iMod<longitudLista(getVehiculos(centroLogistico))){
         VehiculoPtr vehiculoAModificar=(VehiculoPtr)getDatoLista(getVehiculos(centroLogistico),iMod);
        do{
            system("cls");
            limpiarBufferTeclado();
            printf("Ha elegido - ");
            mostrarVehiculo(vehiculoAModificar);
            printf("\n\nQu� desea modificar?\n\n");
            printf("1. Tipo de vehiculo\n");
            printf("2. Marca\n");
            printf("3. Modelo\n");
            printf("4. Patente\n");
            printf("Seleccione una opcion: ");
            scanf("%d",&op);
            limpiarBufferTeclado();
            switch(op){
            case 1:
                printf("\n\n");
                helpTipoVehiculo();
                printf("\n\nSeleccione una opcion: ");
                scanf("%d",&nTipo);
                switch(nTipo){
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
                    system("cls");
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
                system("cls");
                break;
            }
            limpiarBufferTeclado();
            printf("\n\nDatos modificados exitosamente.\n\n");
            printf("Desea seguir modificando este vehiculo?\n\n");
            printf("\t1. SI\n\t");
            printf("0. NO\n\n");
            printf("Seleccione una opcion: ");
            scanf("%d",&seguirMod);
            limpiarBufferTeclado();
        } while(seguirMod!=0);
    }
}



int menuBuscarPaquetePorAtributo()
{
	int eleccion = 0;
	limpiarBufferTeclado();
	printf("Seleccione una de las siguientes opciones \n");
	printf("Buscar mediante: \n");
	printf("----------------------------------------- \n");
	printf("1. ID \n");
	printf("2. Altura \n");
	printf("3. Ancho \n");
	printf("4. Largo \n");
	printf("5. Peso \n");
	printf("6. Estado de entrega \n");
	printf("7. Direccion de retiro \n");
	printf("8. Direccion de entrega \n");
	printf("9. Fecha de entrega \n");
	printf("10. Cuil del destinatario \n");
	printf("----------------------------------------- \n");
	printf("Eleccion: ");
	scanf("%d", &eleccion);
	printf("----------------------------------------- \n");
	limpiarBufferTeclado();
	return eleccion;
}



void menuBuscarPaqueteNuevo(CentroLogisticoPtr centroLogistico)
{
	int MainMenu = 0;
	int CantidadElegida = 0;
	int DatoBuscarEntero = 0;
	char DatoBuscarString_1[100];
	char DatoBuscarString_2[100];
	bool Encontrado = false;
	///Datos a buscar de fecha
	int dia = 0;
	int mes = 0;
	int anio = 0;
	int hora = 0;
	int minutos = 0;
	FechaPtr FechaBuscar;
	///En caso de que se desee buscar por dia juliano
	int DiaJulianoBuscar = 0;
	FechaPtr FechaBuscarAuxiliar;
	///Para otorgar mayor legibilidad al codigo en la seccion de busqueda por fecha de entrega
	int contador = 0;
	ListaPtr ListaPaquetes = getPaquetes(centroLogistico);
	ListaPtr ListaAuxiliar;
	PaquetePtr PaqueteAuxiliar;
	PersonaPtr ClienteAuxiliar;
	CuilPtr CuilAuxiliar;
	DomicilioPtr DireccionAuxiliar;
	CantidadElegida = seleccionarNumero();
	for( int i = 0 ; i < CantidadElegida ; i++ )
	{
		ListaAuxiliar = ListaPaquetes;
		system("cls");
		MainMenu = menuBuscarPaquetePorAtributo();
		switch(MainMenu)
		{
			case 1:
				system("cls");
				printf("Seleccione el ID para buscar: ");
				DatoBuscarEntero = seleccionarNumero();
				while(!listaVacia(ListaAuxiliar))
				{
					PaqueteAuxiliar = getCabecera(ListaAuxiliar);
					if(DatoBuscarEntero == getID(PaqueteAuxiliar))
					{
						Encontrado = true;
						///return PaqueteAuxiliar;
						///mostrarPaquetes(PaqueteAuxiliar);
					}
					ListaAuxiliar = getResto(ListaAuxiliar);
				}
			break;
			case 2:
				system("cls");
				printf("Seleccione la altura para buscar: ");
				DatoBuscarEntero = seleccionarNumero();
				while(!listaVacia(ListaAuxiliar))
				{
					PaqueteAuxiliar = getCabecera(ListaAuxiliar);
					if(DatoBuscarEntero == getAlto(PaqueteAuxiliar))
					{
						Encontrado = true;
						///return PaqueteAuxiliar;
						///mostrarPaquetes(PaqueteAuxiliar);
					}
					ListaAuxiliar = getResto(ListaAuxiliar);
				}
			break;
			case 3:
			system("cls");
			printf("Seleccione el ancho para buscar: ");
			DatoBuscarEntero = seleccionarNumero();
			while(!listaVacia(ListaAuxiliar))
			{
				PaqueteAuxiliar = getCabecera(ListaAuxiliar);
				if(DatoBuscarEntero == getAncho(PaqueteAuxiliar))
				{
					Encontrado = true;
					///return PaqueteAuxiliar;
					///mostrarPaquetes(PaqueteAuxiliar);
				}
				ListaAuxiliar = getResto(ListaAuxiliar);
			}
			break;
			case 4:
				system("cls");
				printf("Seleccione el largo");
				DatoBuscarEntero = seleccionarNumero();
				while(!listaVacia(ListaAuxiliar))
				{
					PaqueteAuxiliar = getCabecera(ListaAuxiliar);
					if(DatoBuscarEntero == getLargo(PaqueteAuxiliar))
					{
						Encontrado = true;
						///return PaqueteAuxiliar;
						///mostrarPaquetes(PaqueteAuxiliar);
					}
					ListaAuxiliar = getResto(ListaAuxiliar);
				}
			break;
			case 5:
				system("cls");
				printf("Seleccione el peso para buscar: ");
				DatoBuscarEntero = seleccionarNumero();
				while(!listaVacia(ListaAuxiliar))
				{
					PaqueteAuxiliar = getCabecera(ListaAuxiliar);
					if(DatoBuscarEntero == getPeso(PaqueteAuxiliar))
					{
						Encontrado = true;
						///return PaqueteAuxiliar;
						///mostrarPaquetes(PaqueteAuxiliar);
					}
					ListaAuxiliar = getResto(ListaAuxiliar);
				}
			break;
			case 6:
				system("cls");
				printf("Seleccione las identidades de la direccion de retiro \n");
				printf("Seleccione la calle de retiro: ");
				SeleccionarStringEstatico(DatoBuscarString_1);
				printf("Seleccione la altura de retiro: ");
				DatoBuscarEntero = seleccionarNumero();
				printf("Seleccione la localidad de retiro: ");
				SeleccionarStringEstatico(DatoBuscarString_2);
				while(!listaVacia(ListaAuxiliar))
				{
					contador = 0;
					PaqueteAuxiliar = getCabecera(ListaAuxiliar);
					DireccionAuxiliar = getDirRetiro(PaqueteAuxiliar);
					if( strcmp(  DatoBuscarString_1, getCalle(DireccionAuxiliar) ) == 0 )
					{
						contador++;
					}
					if( DatoBuscarEntero == getAltura(DireccionAuxiliar) )
					{
						contador++;
					}
					if( strcmp( DatoBuscarString_2, getLocalidad(DireccionAuxiliar)) == 0 )
					{
						contador++;
					}
					if( contador == 3 )
					{
						Encontrado = true;
						///return PaqueteAuxiliar;
						///mostrarPaquete(PaqueteAuxiliar);
					}
					ListaAuxiliar = getResto(ListaAuxiliar);
				}
			break;
			case 7:
				system("cls");
				printf("Seleccione las identidades de la direccion de entrega \n");
				printf("Seleccione la calle de entrega: ");
				SeleccionarStringEstatico(DatoBuscarString_1);
				printf("Seleccione la altura de entrega: ");
				DatoBuscarEntero = seleccionarNumero();
				printf("Seleccione la localidad de entrega: ");
				SeleccionarStringEstatico(DatoBuscarString_2);
				while(!listaVacia(ListaAuxiliar))
				{
					contador = 0;
					PaqueteAuxiliar = getCabecera(ListaAuxiliar);
					DireccionAuxiliar = getDirEntrega(PaqueteAuxiliar);
					if( strcmp(  DatoBuscarString_1, getCalle(DireccionAuxiliar) ) == 0 )
					{
						contador++;
					}
					if( DatoBuscarEntero == getAltura(DireccionAuxiliar) )
					{
						contador++;
					}
					if( strcmp( DatoBuscarString_2, getLocalidad(DireccionAuxiliar)) == 0 )
					{
						contador++;
					}
					if( contador == 3 )
					{
						Encontrado = true;
						///return PaqueteAuxiliar;
						///mostrarPaquete(PaqueteAuxiliar);
					}
					ListaAuxiliar = getResto(ListaAuxiliar);
				}
			break;
			case 8:
				system("cls");
			break;
			case 9:
				system("cls");
				printf("Seleccione una fecha para buscar \n");
				printf("(FORMATO DE INGRESO) = [ DD / MM / AA  ||  HH : MM] : ");
				limpiarBufferTeclado();
				scanf("%d" "%d" "%d" "%d" "%d", &dia, &mes, &anio, &hora, &minutos);
				///FechaBuscar = crearFecha(dia, mes, anio, hora, minutos);
				limpiarBufferTeclado();
				while(!listaVacia(ListaAuxiliar))
				{
					contador = 0;
					PaqueteAuxiliar = getCabecera(ListaAuxiliar);
					FechaBuscar = getFechaEntrega(PaqueteAuxiliar);
					if( dia == getDia(FechaBuscar) )
					{
						contador++;
					}
					if( mes == getMes(FechaBuscar) )
					{
						contador++;
					}
					if( anio == getAnio(FechaBuscar) )
					{
						contador++;
					}
					/*
					DiaJulianoBuscar = calcularDiaJuliano();
					if( getDiaJuliano(FechaBuscarAuxiliar) == getDiaJuliano(FechaBuscar) )
					{
						contador++;
					}
					*/
					if( hora == getHora(FechaBuscar) )
					{
						contador++;
					}
					if( minutos == getMinuto(FechaBuscar) )
					{
						contador++;
					}
					if( contador == 5 )
					{
						Encontrado = true;
						///return PaqueteAuxiliar;
						///mostrarPaquete(PaqueteAuxiliar);
					}
					ListaAuxiliar = getResto(ListaAuxiliar);
				}
			break;
			case 10:
				system("cls");
				printf("Seleccione un cuil para buscar: ");
				SeleccionarStringEstatico(DatoBuscarString_1);
				while(!listaVacia(ListaAuxiliar))
				{
					PaqueteAuxiliar = getCabecera(ListaAuxiliar);
					ClienteAuxiliar = getClientePaquete(PaqueteAuxiliar);
					CuilAuxiliar = getCuilPersona(ClienteAuxiliar);
					if( strcmp(DatoBuscarString_1, getCuil(ClienteAuxiliar) ) == 0 )
					{
						Encontrado = true;
						///return PaqueteAuxiliar;
						///mostrarPaquetes(PaqueteAuxiliar);
					}
					ListaAuxiliar = getResto(ListaAuxiliar);
				}
			break;
			default:
				printf("Eleccion equivocada \n");
				presionarEnterYLimpiarPantalla();
			break;
		}
	}
}




void menuArmarReparto(CentroLogisticoPtr centroLogistico){
    limpiarBufferTeclado();
    int n=0,j=0,k=0,m=0,posicionEncontrado=0;
    bool paquetesElegidos=false,choferesElegidos=false,vehiculosElegidos=false;
    RepartoPtr reparto;
    PersonaPtr choferElegido;
    VehiculoPtr vehiculoElegido;
    FechaPtr fechaSalida;
    FechaPtr fechaRetorno;
    ListaPtr listaPaquetes = crearLista();
    int cantPaquetesElegidos=0;
    PaquetePtr paqueteElegido;
    if(longitudLista(getPaquetes(centroLogistico))!=0 && longitudLista(getVehiculos(centroLogistico))!=0 && longitudLista(getChoferes(centroLogistico))!=0){
        do{
            system("cls");
            limpiarBufferTeclado();
            printf("ARMAR REPARTO\n\n");
            printf("Ingrese cantidad de repartos a armar: ");
            scanf("%d",&n);
            limpiarBufferTeclado();
            system("cls");
            if(n<1)
                printf("\nCantidad incorrecta.\n");
        }while(n<1);
        for(int i=0;i<n;i++){
            printf("\n\nREPARTO %d\n\n",i+1);
            ///SECCION DE CHOFERES
            while(choferesElegidos==false && longitudLista(getChoferes(centroLogistico))!=0){
                system("cls");
                printf("Cantidad disponible de choferes: %d\n", longitudLista(getChoferes(centroLogistico)));
                if(longitudLista(getChoferes(centroLogistico))!=0){
                    mostrarChoferes(centroLogistico);
                    limpiarBufferTeclado();
                    printf("\n\nSeleccione un chofer ingresando su indice: ");
                    scanf("%d",&k);
                    limpiarBufferTeclado();
                    if(k>=0 && k<longitudLista(getChoferes(centroLogistico))){
                        choferElegido=getDatoLista(getChoferes(centroLogistico),k);
                        posicionEncontrado=buscarChoferRepartos(centroLogistico,getCuil(getCuilPersona(choferElegido)));
                        if(posicionEncontrado==-1)
                            choferesElegidos=true;
                    }
                }
                if(k<0 || k>longitudLista(getChoferes(centroLogistico)))
                    printf("No existe el chofer seleccionado\n");
            }
            system("cls");
            ///SECCION VEHICULOS
            while(vehiculosElegidos==false && longitudLista(getVehiculos(centroLogistico))!=0){
                system("cls");
                printf("Vehiculos totales disponibles: %d\n", longitudLista(getVehiculos(centroLogistico)));
                if(longitudLista(getVehiculos(centroLogistico))!=0){
                    mostrarVehiculos(centroLogistico);
                    printf("\n\nSeleccione un vehiculo ingresando su indice: ");
                    scanf("%d",&k);
                    limpiarBufferTeclado();
                    if(k >= 0 && k < longitudLista(getVehiculos(centroLogistico))){
                        vehiculoElegido = getDatoLista(getVehiculos(centroLogistico), k);
                        posicionEncontrado = buscarVehiculoRepartos(centroLogistico, getPatente(vehiculoElegido));
                        if(posicionEncontrado == -1)
                            vehiculosElegidos = true;
                        else
                            printf("Seleccione un vehiculo valido\n");
                    }
                }
            }
            system("cls");
            ///SECCION DE FECHAS
            printf("\n\nFecha de salida:");
            fechaSalida=cargarFecha(fechaSalida);
            printf("\n\nFecha de retorno:");
            fechaRetorno=cargarFecha(fechaRetorno);
            system("cls");
            ///SECCION DE PAQUETES
            if(longitudLista(getPaquetes(centroLogistico))!=0){
                do{
                    system("cls");
                    limpiarBufferTeclado();
                    printf("Cantidad disponible de paquetes: %d\n", longitudLista(getPaquetes(centroLogistico)));
                    printf("Ingrese cantidad de paquetes a agregar al reparto: ");
                    scanf("%d",&cantPaquetesElegidos);
                    limpiarBufferTeclado();
                    if(n<1 || n>longitudLista(getPaquetes(centroLogistico))){
                        printf("\n\nERROR: cantidad incorrecta. Vuelva a ingresar.\n\n");
                    }
                }while(n<1);
            }
            j = 0;
            while(j < cantPaquetesElegidos && (longitudLista(getPaquetes(centroLogistico))-j) != 0){
                if(longitudLista(getPaquetes(centroLogistico)) != 0){
                    system("cls");
                    filtrarPaquetes(centroLogistico,0);
                    limpiarBufferTeclado();
                    printf("\n\nPaquete N. %d\n",j);
                    printf("Seleccione el paquete a cargar ingresando su indice: ");
                    scanf("%d",&k);
                    limpiarBufferTeclado();
                    if(k >= 0 && k < longitudLista(getPaquetes(centroLogistico)) && getEstado(getDatoLista(getPaquetes(centroLogistico),k)) == 0){
                        paqueteElegido=getDatoLista(getPaquetes(centroLogistico),k);
                        setEstado(paqueteElegido,1);
                        insertarDatoLista(listaPaquetes,(PaquetePtr)paqueteElegido,m++);
                        j++;
                    }else
                        printf("ELIJA CORRECTAMENTE\n");
                    if(j == cantPaquetesElegidos)
                        paquetesElegidos=true;
                }
            }
        }
    }
    if(choferesElegidos==true && paquetesElegidos==true && vehiculosElegidos==true){
        reparto=armarReparto(choferElegido,vehiculoElegido,fechaSalida,fechaRetorno,listaPaquetes);
        agregarDatoLista(getRepartos(centroLogistico,true),reparto);
        printf("\n\nReparto armado exitosamente.\n\n");
    }
    if(vehiculosElegidos==false){
        printf("Vehiculo no seleccionado\n");
    }
    if(choferesElegidos==false){
        printf("Chofer no seleccionado\n");
    }
    if(paquetesElegidos==false){
        printf("Paquetes no seleccionados\n");
    }
     system("pause");
}

void menuMostrarEntregasReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto){
    int eleccion=0;
    int tamanioLista=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));
    if(tamanioLista!=0){
        mostrarRepartos(centroLogistico, esRepartoAbierto);
        limpiarBufferTeclado();
        printf("Seleccione un reparto mediante su indice: ");
        scanf("%d",&eleccion);
        system("cls");
        if(eleccion>=0 && eleccion<tamanioLista)
            mostrarPaquetesListaReparto(getDatoLista(getRepartos(centroLogistico,esRepartoAbierto), eleccion));
        else
            printf("Ese reparto es inexistente\n");
    }else
        printf("No hay repartos para mostrar\n");
}

RepartoPtr menuBuscarReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto){
    int eleccion=0;
    int tamanioLista=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));
    RepartoPtr repartoBuscar;
    if(tamanioLista!=0){
        limpiarBufferTeclado();
        printf("Seleccione un reparto para buscar mediante su indice: ");
        scanf("%d",&eleccion);
        if(eleccion>=0 && eleccion<tamanioLista){
            repartoBuscar=getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),eleccion);
            mostrarReparto(repartoBuscar);
        }else
            printf("Reparto inexistente\n");
    }else
        printf("No hay repartos para buscar\n");
    return repartoBuscar;
}

RepartoPtr menuEliminarReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto){
    int eleccion=0;
    if(longitudLista(getRepartos(centroLogistico,true))!=0){
        mostrarRepartos(centroLogistico,esRepartoAbierto);
        limpiarBufferTeclado();
        printf("Seleccione un reparto para remover segun su indice: ");
        scanf("%d",&eleccion);
        limpiarBufferTeclado();
    }
    if(eleccion>=0 && eleccion<longitudLista(getRepartos(centroLogistico,true))){
        RepartoPtr repartoRemover=removerDeLista(getRepartos(centroLogistico,esRepartoAbierto),eleccion);
        return repartoRemover;
    }else{
        printf("Agregue repartos para remover\n");
        return 0;
    }
}

void menuEliminarRepartoNuevo(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto){
    int Main,posicionEliminar,posicionInicial,posicionFinal,cantidad;
    ListaPtr listaRepartos=getRepartos(centroLogistico,esRepartoAbierto);
    Main=menuSeleccionEliminar();
    switch(Main){
    case 1:
        cantidad=seleccionarCantidad();
        for(int i=0;i<cantidad;i++){
            posicionEliminar=seleccionarNumero();
            if(verificarLimiteLista(listaRepartos,posicionEliminar)){
                removerReparto(centroLogistico,posicionEliminar,esRepartoAbierto);
            }
        }
        break;
    case 2:
        cantidad=seleccionarCantidad();
        for(int i=0;i<cantidad;i++){
            printf("Seleccione en formato indice a indice [1 - 3]\n");
            posicionInicial=seleccionarNumero();
            posicionFinal=seleccionarNumero();
            if(verificarLimiteLista(listaRepartos,posicionInicial)){
                if(verificarLimiteLista(listaRepartos,posicionFinal)){
                    for(int i=0;i<posicionFinal-posicionInicial+1;i++){
                        removerReparto(centroLogistico,posicionInicial,esRepartoAbierto);
                    }
                }
            }
        }
        break;
    default:
        mensajeError();
        break;
    }
}

void menuCerrarReparto(CentroLogisticoPtr centroLogistico){
    int eleccion=0;
    mostrarRepartos(centroLogistico,true);
    do{
        limpiarBufferTeclado();
        printf("Seleccione un reparto mediante su indice: ");
        scanf("%d",&eleccion);
    }while(eleccion<0 && eleccion>longitudLista(getRepartos(centroLogistico,true)));
    RepartoPtr repartoCerrado=removerDeLista(getRepartos(centroLogistico,true),eleccion);
    agregarDatoLista(getRepartos(centroLogistico,false),(RepartoPtr)repartoCerrado);
}

void menuCerrarRepartoNuevo(CentroLogisticoPtr centroLogistico){
    int cantidad,Main,posicionInicial,posicionFinal,posicionEliminar;
    ListaPtr listaRepartos=getRepartos(centroLogistico,true);
    RepartoPtr repartoAuxiliar;
    Main=menuSeleccionEliminar();
    switch(Main){
    case 1:
        cantidad=seleccionarNumero();
        for(int i=0;i<cantidad;i++){
            posicionEliminar=seleccionarNumero();
            if(verificarLimiteLista(listaRepartos,posicionEliminar)){
                repartoAuxiliar=removerReparto(centroLogistico,posicionEliminar,true);
                agregarReparto(centroLogistico,repartoAuxiliar,false);
            }
        }
        break;
    case 2:
        cantidad=seleccionarCantidad();
        for(int i=0;i<cantidad;i++){
            printf("Selecciona indice a indice [1 - 3]\n");
            posicionInicial=seleccionarNumero();
            posicionFinal=seleccionarNumero();
            if(verificarLimiteLista(listaRepartos,posicionInicial)){
                if(verificarLimiteLista(listaRepartos,posicionFinal)){
                    for(int i=0;i<posicionFinal-posicionInicial+1;i++){
                        repartoAuxiliar=removerReparto(centroLogistico,posicionInicial,true);
                        agregarReparto(centroLogistico,repartoAuxiliar,false);
                    }
                }
            }
        }
        break;
    default:
        mensajeError();
        break;
    }
}

int menuBuscadoReparto(){
    int eleccion;
    limpiarBufferTeclado();
    printf("Buscar reparto mediante\n");
    printf("1. El indice\n");
    printf("2. Cuil del chofer\n");
    printf("3. Patente del vehiculo\n");
    printf("0. Volver\n");
    printf("Opcion: ");
    scanf("%d",&eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int seleccionarEstadoReparto(){
    int eleccion;
    limpiarBufferTeclado();
    helpEstadoPaquete();
    printf("Eleccion: ");
    scanf("%d",&eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

void modificarEstadoPaquete(CentroLogisticoPtr centroLogistico, int posicionEncontrado){
    int eleccion;
    system("cls");
    RepartoPtr repartoActualizar=getDatoLista(getRepartos(centroLogistico,true),posicionEncontrado);
    ///mostrarPaquetesListaReparto(repartoActualizar);
    posicionEncontrado=menuBuscarPaqueteReparto(centroLogistico,repartoActualizar);
    if(posicionEncontrado!=-1){
        system("cls");
        PaquetePtr paqueteActualizar=getDatoLista(getListaPaquetesReparto(repartoActualizar),posicionEncontrado);
        eleccion=seleccionarEstadoReparto();
        setEstado(paqueteActualizar,eleccion);
    }else{
        printf("No existe tal paquete\n");
        system("pause");
    }
}

void menuActualizarReparto(CentroLogisticoPtr centroLogistico){
    int MAIN=0,posicionEncontrado=0,eleccion=0;
    char cuilBuscar[100];
    char patenteBuscar[100];
    do{
        system("cls");
        ///mostrarRepartos(centroLogistico,true);
        MAIN=menuBuscadoReparto();
        switch(MAIN){
        case 1:
            printf("Seleccione un reparto para actualizar mediante su indice: ");
            scanf("%d",&eleccion);
            posicionEncontrado=buscarReparto(centroLogistico,eleccion);
            if(posicionEncontrado!=-1)
                modificarEstadoPaquete(centroLogistico,posicionEncontrado);
            else{
                printf("Reparto inexistente\n");
                system("pause");
            }
            break;
        case 2:
            system("cls");
            limpiarBufferTeclado();
            printf("Seleccione un reparto para actualizar mediante el cuil del chofer: ");
            scanf("%[^\n]%*c",cuilBuscar);
            limpiarBufferTeclado();
            posicionEncontrado=buscarChoferRepartos(centroLogistico,cuilBuscar);
            if(posicionEncontrado!=-1)
                modificarEstadoPaquete(centroLogistico,posicionEncontrado);
            else{
                printf("No existe este reparto con este chofer\n");
                system("pause");
            }
            break;
        case 3:
            system("cls");
            limpiarBufferTeclado();
            printf("Seleccione un reparto para actualizar mediante la patente del vehiculo: ");
            scanf("%[^\n]%*c",patenteBuscar);
            limpiarBufferTeclado();
            posicionEncontrado=buscarVehiculoRepartos(centroLogistico,patenteBuscar);
            if(posicionEncontrado!=-1)
                modificarEstadoPaquete(centroLogistico,posicionEncontrado);
            else{
                printf("No existe este reparto con este vehiculo\n");
                system("pause");
            }
            break;
        }
    }while(MAIN!=0);
}

void menuMostrarRepartos(CentroLogisticoPtr centroLogistico,bool esRepartoAbierto){
	int op=0,op1,i=0;
	int n=longitudLista(getRepartos(centroLogistico,esRepartoAbierto));
    do{
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
        switch(op){
        case 1:
            do{
                mostrarRepartos(centroLogistico,esRepartoAbierto);
                printf("\nSeleccione un reparto para mostrar:");
                scanf("%d",&i);
                limpiarBufferTeclado();
                if(i<=0 || i>=n)
                    printf("\n\nERROR: indice inexistente. Vuelva a ingresarlo.\n\n");
                system("cls");
            } while(i>0 && i<n);
            mostrarReparto(getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),i));
            system("cls");
            break;
        case 2:
            mostrarRepartos(centroLogistico, esRepartoAbierto);
            system("cls");
            break;
        case 3:
            do{
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
                switch(op1){
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
                system("cls");
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


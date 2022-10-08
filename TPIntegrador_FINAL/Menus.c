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
        fflush(stdin);
        helpCuil();
        printf("\n\tCUIL:");
        scanf("%[^\n]%*c",strCuil);
        fflush(stdin);
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
    fflush(stdin);
    printf("\n\t\t[CALLE]");
    scanf("%[^\n]%*c",calle);
    fflush(stdin);
    printf("\n\t\t[ALTURA]");
    scanf("%d",&altura);
    fflush(stdin);
    printf("\n\t\t[LOCALIDAD]: ");
    scanf("%[^\n]%*c",localidad);
    fflush(stdin);
    domicilio=crearDomicilio(calle,altura,localidad);
    return domicilio;
}

FechaPtr cargarFecha(FechaPtr fecha){
    int dia=0,mes=0,anio=0,hora=0,minuto=0;
    bool primeraVez=true;
    fecha=crearFecha(dia,mes,anio,hora,minuto);
    do{
        fflush(stdin);
        printf("\n\t\tFecha (DD MM AAAA): ");
        scanf("%d %d %d",&dia,&mes,&anio);
        fflush(stdin);
        printf("\n\t\tHorario (HH MM): ");
        scanf("%d %d",&hora,&minuto);
        fflush(stdin);
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
        fflush(stdin);
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
    fflush(stdin);
    printf("\n\t\tCalle: ");
    scanf("%[^,]%*c",calle);
    fflush(stdin);
    printf("\n\t\Altura: ");
    scanf("%d",&altura);
    fflush(stdin);
    printf("\n\t\tLocalidad: ");
    scanf("%[^\n]%*c",localidad);
    fflush(stdin);
    setCalle(domicilio,calle);
    setAltura(domicilio,altura);
    setLocalidad(domicilio,localidad);
}

void actualizarFecha(FechaPtr fecha){
    int dia=0,mes=0,anio=0,hora=0,minuto=0,i=0;
    do{
        printf("\n\t\tFecha (DD MM AAAA): ");
        scanf("%d %d %d",&dia,&mes,&anio);
        fflush(stdin);
        printf("\n\t\tHorario (HH MM): ");
        scanf("%d %d",&hora,&minuto);
        fflush(stdin);
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
    fflush(stdin);
    printf("1. Modificar nombre y apellido\n");
    printf("2. Modificar domicilio\n");
    printf("3. Modificar cuil\n");
    scanf("%d",&eleccion);
    fflush(stdin);
    switch(eleccion){
    case 1:
        fflush(stdin);
        printf("Nombre:");
        scanf("%[^\n]%*c",nombre);
        fflush(stdin);
        printf("Apellido:");
        scanf("%[^\n]%*c",apellido);
        fflush(stdin);
        setNombre(cliente,nombre);
        setApellido(cliente,apellido);
        break;
    case 2:
        actualizarDomicilio(domicilio);
        break;
    case 3:
        fflush(stdin);
        printf("Cuil:");
        scanf("%[^\n]%*c", cuil);
        fflush(stdin);
        Cuil = setCuil(Cuil,cuil);
        break;
    }
    return cliente;
}



void menuCargarPaquete(CentroLogisticoPtr centroLogistico){
    int n=0,ID=0,ancho=0,alto=0,largo=0,peso=0;
    PaquetePtr paquete;
    FechaPtr fechaEntrega;
    DomicilioPtr dirRetiro;
    DomicilioPtr dirEntrega;
    do{
        fflush(stdin);
        system("cls");
        printf("CARGAR PAQUETE\n\n");
        printf("Ingrese cantidad de paquetes a cargar: ");
        scanf("%d",&n);
        fflush(stdin);
        if(n<1)
            printf("\nCantidad incorrecta.\n");
    }while(n<1);
    for(int i=0;i<n;i++){
        system("cls");
        printf("\n\nPAQUETE %d\n\n",i+1);
        fflush(stdin);
        ID=rand(); //esto no se mostrará sino al final de la carga del paquete.
        fflush(stdin);
        printf("\n\tAncho: ");
        scanf("%d",&ancho);
        fflush(stdin);
        printf("\n\tAlto: ");
        scanf("%d",&alto);
        fflush(stdin);
        printf("\n\tLargo: ");
        scanf("%d",&largo);
        fflush(stdin);
        printf("\n\tPeso: ");
        scanf("%d",&peso);
        fflush(stdin);
        printf("\n\tDireccion de retiro:");
        dirRetiro=cargarDomicilio(dirRetiro);
        fflush(stdin);
        printf("\n\tDireccion de entrega:");
        dirEntrega=cargarDomicilio(dirEntrega);
        printf("\n\tFecha de entrega:");
        fflush(stdin);
        fechaEntrega=cargarFecha(fechaEntrega);
        fflush(stdin);
        system("cls");
        PersonaPtr cliente=menuCargarCliente(centroLogistico);
        paquete=crearPaquete(ID,ancho,alto,largo,peso,dirRetiro,dirEntrega,fechaEntrega,cliente,0);
        agregarPaquete(centroLogistico,paquete);
        printf("\n\nPaquete #%d cargado exitosamente.\n\n",ID);
    }
}

PersonaPtr menuCargarCliente(CentroLogisticoPtr centroLogistico){
    int n=0,posicionEncontrado=0;
    char nombre[100];
    char apellido[100];
    PersonaPtr cliente;
    DomicilioPtr domicilio;
    CuilPtr cuil;
    do{
        system("cls");
        fflush(stdin);
        printf("CARGAR CLIENTE\n\n");
        printf("Ingrese cantidad de clientes a cargar: ");
        scanf("%d",&n);
        if(n<1)
            printf("\nCantidad incorrecta.\n");
        system("cls");
    }while(n<1);
    for(int i=0;i<n;i++){
        printf("CLIENTE %d\n\n",i+1);
        fflush(stdin);
        printf("\n\n\tNombre: ");
        scanf("%[^\n]%*c",nombre);
        fflush(stdin);
        printf("\n\tApellido: ");
        scanf("%[^\n]%*c",apellido);
        fflush(stdin);
        printf("\n\tDomicilio");
        domicilio=cargarDomicilio(domicilio);
        fflush(stdin);
        cuil=cargarCuil(cuil);
        fflush(stdin);
        posicionEncontrado=buscarCliente(centroLogistico,getCuil(cuil));
        if(posicionEncontrado==-1){
            cliente=crearPersona(nombre,apellido,domicilio,cuil,false);
            insertarDatoLista(getClientes(centroLogistico),(PersonaPtr)cliente,longitudLista(getClientes(centroLogistico)));
        }else{
            printf("No se pudo agregar debido a que ya existe\n");
            system("pause");
        }
    }
    return cliente;
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
        fflush(stdin);
        printf("CARGAR CHOFER\n\n");
        printf("Ingrese cantidad de clientes a cargar: ");
        scanf("%d",&n);
        if(n<1)
            printf("\nCantidad incorrecta.\n");
        system("cls");
    }while(n<1);
    for(int i=0;i<n;i++){
        printf("CLIENTE %d\n\n",i+1);
        fflush(stdin);
        printf("\n\n\tNombre: ");
        scanf("%[^\n]%*c",nombre);
        fflush(stdin);
        printf("\n\tApellido: ");
        scanf("%[^\n]%*c",apellido);
        fflush(stdin);
        printf("\n\tDomicilio");
        domicilio=cargarDomicilio(domicilio);
        fflush(stdin);
        cuil=cargarCuil(cuil);
        fflush(stdin);
        posicionEncontrado=buscarChofer(centroLogistico,getCuil(cuil));
        if(posicionEncontrado==-1){
            chofer=crearPersona(nombre,apellido,domicilio,cuil,true);
            insertarDatoLista(getChoferes(centroLogistico),(PersonaPtr)chofer,longitudLista(getChoferes(centroLogistico)));
        }else{
            printf("No se pudo agregar debido a que ya existe\n");
            system("pause");
        }
    }
}

void menuCargarVehiculo(CentroLogisticoPtr centroLogistico){
    int n=0,tipoVehiculo=0,posicionEncontrado=0;
    bool valido=false;
    char marca[100];
    char modelo[100];
    char patente[100];
    VehiculoPtr vehiculo;
    do{
        fflush(stdin);
        system("cls");
        printf("CARGAR VEHICULO\n\n");
        printf("Ingrese cantidad de vehiculos a cargar: ");
        scanf("%d",&n);
        fflush(stdin);
        if(n<1)
            printf("\nCantidad incorrecta.\n");
        system("cls");
    }while(n<1);
    for(int i=0;i<n;i++){
        if(n>1)
            printf("\n\nVEHICULO %d\n\n",i+1);
        fflush(stdin);
        helpTipoVehiculo();
        printf("\n\n\tSeleccione un Tipo: ");
        scanf("%d",&tipoVehiculo);
        fflush(stdin);
        printf("\n\n\tMarca: ");
        scanf("%[^\n]%*c",marca);
        fflush(stdin);
        printf("\n\tModelo: ");
        scanf("%[^\n]%*c",modelo);
        fflush(stdin);
        printf("\n\tPatente (AA 000 AA): ");
        scanf("%[^\n]%*c",patente);
        fflush(stdin);
        posicionEncontrado=buscarVehiculo(centroLogistico,patente);
        if(posicionEncontrado==-1){
            vehiculo=crearVehiculo(tipoVehiculo,marca,modelo,patente);
            insertarDatoLista(getVehiculos(centroLogistico),vehiculo,longitudLista(getVehiculos(centroLogistico)));
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
        fflush(stdin);
        printf("BUSCAR PAQUETE\n\n");
        printf("Ingrese ID del paquete a buscar: ");
        scanf("%d",&ID);
        fflush(stdin);
        printf("\n\n");
        posicionEncontrada=buscarPaquete(centroLogistico,ID);
        if(posicionEncontrada!=-1)
            mostrarPaquete(getDatoLista(getPaquetes(centroLogistico),posicionEncontrada));
        else
            printf("No existe ese ID\n");
        printf("Volver? 1=Si, 0=No");
        scanf("%d",&op);
        fflush(stdin);
    }while(op!=0);
}

void menuBuscarCliente(CentroLogisticoPtr centroLogistico){
    int op=0,posicionEncontrado=0;
    char cuilABuscar[100];
    do{
        system("cls"); fflush(stdin);
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
        system("cls"); fflush(stdin);
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
        system("cls"); fflush(stdin);
        printf("BUSCAR VEHICULO\n\n");
        printf("Ingrese la patente del vehiculo a buscar (AA 111 AA): ");
        scanf("%[^\n]%*c",patente);
        posicionEncontrado=buscarVehiculo(centroLogistico,patente);
        if(posicionEncontrado!=-1)
            mostrarVehiculo(getDatoLista(getVehiculos(centroLogistico),posicionEncontrado));
    }while(op!=0);
}



void menuEliminarPaquete(CentroLogisticoPtr centroLogistico){
    int iElim=0;
    system("cls");
    fflush(stdin);
    if(longitudLista(getPaquetes(centroLogistico))!=0){
        printf("ELIMINAR PAQUETE\n\n");
        mostrarPaquetes(centroLogistico);
        printf("\n\nSeleccione indice del paquete a eliminar: ");
        scanf("%d",&iElim);
        if(iElim>0 && iElim<longitudLista(getPaquetes(centroLogistico)))
            removerPaquete(centroLogistico,iElim);
    }else{
        printf("Agregue paquetes para poder eliminarlos\n");
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
        if(iElim>0 && iElim<longitudLista(getClientes(centroLogistico)))
            removerDeLista(getClientes(centroLogistico),iElim);
    }else{
        printf("No existen clientes para remover\n");
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
        if(iElim>0 && iElim<longitudLista(getChoferes(centroLogistico)))
            removerDeLista(getChoferes(centroLogistico),iElim);
    }else{
        printf("No existen choferes para remover\n");
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
        if(iElim>0 && iElim<longitudLista(getVehiculos(centroLogistico)))
            removerVehiculo(centroLogistico,iElim);
    }else{
        printf("No existen vehiculos para remover\n");
    }
}



void menuModificarPaquete(CentroLogisticoPtr centroLogistico){
    int iMod=0,op=0,seguirMod=0,nAncho=0,nAlto=0,nLargo=0,nPeso=0,nEstado=0;
    DomicilioPtr nuevaDirRetiro;
    DomicilioPtr nuevaDirEntrega;
    FechaPtr nuevaFechaEntrega;
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
        fflush(stdin);
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
        printf("9. Modificar al destinatario\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&op);
        fflush(stdin);
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
        fflush(stdin);
        printf("\n\nDatos modificados exitosamente.\n\n");
        printf("Desea seguir modificando este paquete?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&seguirMod);
        fflush(stdin);
    }while(seguirMod!=0);
}

void menuModificarCliente(CentroLogisticoPtr centroLogistico){
    int iMod=0,op=0,seguirMod=0,cantidadPersonas=0;
    char nNombre[100];
    char nApellido[100];
    DomicilioPtr nuevoDomicilio;
    CuilPtr nuevoCuil;
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
            printf("\n\nQué desea modificar?\n\n");
            printf("1. Nombre y Apellido\n");
            printf("2. Domicilio\n");
            printf("3. CUIL\n");
            printf("Seleccione una opcion: ");
            scanf("%d",&op);
            switch(op){
            case 1:
                fflush(stdin);
                printf("\n\nIngrese el nuevo nombre y apellido de esta manera:");
                printf("\n\t[NOMBRE]\n\t");
                scanf("%[^\n]%*c",nNombre);
                fflush(stdin);
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
    DomicilioPtr nuevoDomicilio;
    CuilPtr nuevoCuil;
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
            printf("\n\nQué desea modificar?\n\n");
            printf("1. Nombre y Apellido\n");
            printf("2. Domicilio\n");
            printf("3. CUIL\n");
            printf("Seleccione una opcion: ");
            scanf("%d",&op);
            switch(op){
            case 1:
                fflush(stdin);
                printf("\n\nIngrese el nuevo nombre y apellido de esta manera:");
                printf("\n\t[NOMBRE]\n\t");
                scanf("%[^\n]%*c",nNombre);
                fflush(stdin);
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
            fflush(stdin);
            printf("Ha elegido - ");
            mostrarVehiculo(vehiculoAModificar);
            printf("\n\nQué desea modificar?\n\n");
            printf("1. Tipo de vehiculo\n");
            printf("2. Marca\n");
            printf("3. Modelo\n");
            printf("4. Patente\n");
            printf("Seleccione una opcion: ");
            scanf("%d",&op);
            fflush(stdin);
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
            fflush(stdin);
            printf("\n\nDatos modificados exitosamente.\n\n");
            printf("Desea seguir modificando este vehiculo?\n\n");
            printf("\t1. SI\n\t");
            printf("0. NO\n\n");
            printf("Seleccione una opcion: ");
            scanf("%d",&seguirMod);
            fflush(stdin);
        } while(seguirMod!=0);
    }
}



void menuArmarReparto(CentroLogisticoPtr centroLogistico){
    fflush(stdin);
    bool valido=false;
    int n=0,j=0,k=0,m=0,posicionEncontrado=0;
    bool elegidoCorrectamente=false,paquetesElegidos=false,choferesElegidos=false,vehiculosElegidos=false,choferElegidoBool=false;
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
            fflush(stdin);
            printf("ARMAR REPARTO\n\n");
            printf("Ingrese cantidad de repartos a armar: ");
            scanf("%d",&n);
            fflush(stdin);
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
                    fflush(stdin);
                    printf("\n\nSeleccione un chofer ingresando su indice: ");
                    scanf("%d",&k);
                    fflush(stdin);
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
                    fflush(stdin);
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
                    fflush(stdin);
                    printf("Cantidad disponible de paquetes: %d\n", longitudLista(getPaquetes(centroLogistico)));
                    printf("Ingrese cantidad de paquetes a agregar al reparto: ");
                    scanf("%d",&cantPaquetesElegidos);
                    fflush(stdin);
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
                    fflush(stdin);
                    printf("\n\nPaquete N. %d\n",j);
                    printf("Seleccione el paquete a cargar ingresando su indice: ");
                    scanf("%d",&k);
                    fflush(stdin);
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
        insertarDatoLista(getRepartos(centroLogistico,true),reparto,longitudLista(getRepartos(centroLogistico,true)));
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
    mostrarRepartos(centroLogistico, esRepartoAbierto);
    do{
        fflush(stdin);
        printf("Seleccione un reparto mediante su indice: ");
        scanf("%d",&eleccion);
    }while(eleccion<0 && eleccion>longitudLista(getRepartos(centroLogistico,esRepartoAbierto)));
    system("cls");;
    mostrarPaquetesListaReparto(getDatoLista(getRepartos(centroLogistico,esRepartoAbierto), eleccion-1));
}

void menuBuscarReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto){
    int eleccion=0;
    RepartoPtr repartoBuscar;
    do{
        fflush(stdin);
        printf("Seleccione un reparto para buscar mediante su indice: ");
        scanf("%d",&eleccion);
    }while(eleccion<0 && eleccion>longitudLista(getRepartos(centroLogistico,esRepartoAbierto)));
    repartoBuscar=getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),eleccion);
    mostrarReparto(repartoBuscar);
    return repartoBuscar;
}

void menuEliminarReparto(CentroLogisticoPtr centroLogistico, bool esRepartoAbierto){
    int eleccion=0;
    mostrarRepartos(centroLogistico,esRepartoAbierto);
    do{
        fflush(stdin);
        printf("Seleccione un reparto para remover segun su indice: ");
        scanf("%d",&eleccion);
    }while(eleccion<0 && eleccion>longitudLista(getRepartos(centroLogistico,esRepartoAbierto)));
    RepartoPtr repartoRemover=removerDeLista(getRepartos(centroLogistico,esRepartoAbierto),eleccion);
    return repartoRemover;
}

void menuCerrarReparto(CentroLogisticoPtr centroLogistico){
    int eleccion=0;
    mostrarRepartos(centroLogistico,true);
    do{
        fflush(stdin);
        printf("Seleccione un reparto mediante su indice: ");
        scanf("%d",&eleccion);
    }while(eleccion<0 && eleccion>longitudLista(getRepartos(centroLogistico,true)));
    RepartoPtr repartoCerrado=removerDeLista(getRepartos(centroLogistico,true),eleccion);
    agregarDatoLista(getRepartos(centroLogistico,false),(RepartoPtr)repartoCerrado);
}

void menuActualizarReparto(CentroLogisticoPtr centroLogistico){
    int eleccion=0;
    mostrarRepartos(centroLogistico,true);
    do{
        fflush(stdin);
        printf("Seleccione un reparto para actualizar mediante su indice: ");
        scanf("%d",&eleccion);
    }while(eleccion<0 && eleccion>longitudLista(getRepartos(centroLogistico,true)));
    RepartoPtr repartoActualizar=getDatoLista(getRepartos(centroLogistico,true),eleccion);
    mostrarPaquetesListaReparto(repartoActualizar);
    do{
        fflush(stdin);
        printf("Seleccione una entrega para actualizar mediante su indice: ");
        scanf("%d",&eleccion);
    }while(eleccion<0 && eleccion>longitudLista(getListaPaquetesReparto(repartoActualizar)));
    PaquetePtr paqueteActualizar=getDatoLista(getListaPaquetesReparto(repartoActualizar),eleccion);
    do{
        fflush(stdin);
        helpEstadoPaquete();
        printf("Eleccion: ");
        scanf("%d",&eleccion);
        setEstado(paqueteActualizar,eleccion);
    }while(eleccion<0 && eleccion>3);
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
        fflush(stdin);
        system("cls");
        switch(op){
        case 1:
            do{
                mostrarRepartos(centroLogistico,esRepartoAbierto);
                printf("\nSeleccione un reparto para mostrar:");
                scanf("%d",&i);
                fflush(stdin);
                if(i<=0 || i>=n)
                    printf("\n\nERROR: indice inexistente. Vuelva a ingresarlo.\n\n");
                system("cls");
            } while(i>0 && i<n);
            mostrarReparto(getDatoLista(getRepartos(centroLogistico,esRepartoAbierto),i-1));
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


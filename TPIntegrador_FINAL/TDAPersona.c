#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "TDADomicilio.h"
#include "TDACuil.h"
#include "TDAPersona.h"
#include "TDACentroLogistico.h"
#include "Files.h"
#include "Menus.h"
#include "Lista.h"
#include "util.h"

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE CREACION///
///-----------------------------------------------------------------------------------------------------------///

PersonaPtr crearPersona(char *nombre,char *apellido,DomicilioPtr domicilio,CuilPtr cuil,bool esChofer)
{
    //Precondición: domicilio y cuil debieron haber sido creados con sus respectivas funciones de creacion.
    PersonaPtr persona=(PersonaPtr)obtenerMemoria(sizeof(Persona));
    persona->nombre=crearStringDinamico(nombre);
    persona->apellido=crearStringDinamico(apellido);
    persona->domicilio=domicilio;
    persona->cuil=cuil;
    persona->esChofer=esChofer;
    persona->RepartoDiario = false;
    //en VSCode vimos que se puede asignar valores entre variables de tipo bool.
    //esChofer valdría NULL por defecto, pero ahora vale o bien true, o bien false.
    return persona;
}

///Creador especial que solo recibe datos primitivos.
PersonaPtr crearPersonaDirect(char *nombre,char *apellido,char *calle,int altura,char *localidad,char *cuilStr,bool esChofer)
{
    DomicilioPtr domicilio = crearDomicilio(calle,altura,localidad);
    CuilPtr cuil = crearCuil(cuilStr);
    return crearPersona(nombre,apellido,domicilio,cuil,esChofer);
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE DESTRUCCION///
///-----------------------------------------------------------------------------------------------------------///

PersonaPtr destruirPersona(PersonaPtr persona)
{
    ///destruimos TODOS los campos, incluyendo los que no reservamos dinámicamente en crearPersona
    destruirStringDinamico(persona->nombre);
    destruirStringDinamico(persona->apellido);
    persona->domicilio=destruirDomicilio(persona->domicilio);
    persona->cuil=destruirCuil(persona->cuil);
    free(persona);
    return NULL;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE SETTERS///
///-----------------------------------------------------------------------------------------------------------///

void setNombre(PersonaPtr persona,char *nombre)
{
    destruirStringDinamico(persona->nombre);
    char* NombreNuevo = crearStringDinamico(nombre);
    persona->nombre = NombreNuevo;
}

void setApellido(PersonaPtr persona,char *apellido)
{
    destruirStringDinamico(persona->apellido);
    char* ApellidoNuevo = crearStringDinamico(apellido);
    persona->apellido = ApellidoNuevo;
}

void setDomicilio(PersonaPtr persona,DomicilioPtr domicilio)
{
    persona->domicilio=domicilio;
}

void setCuilPersona(PersonaPtr persona, CuilPtr cuil) ///NUEVO NOMBRE PARA NO CONFUNDIR CON SETCUIL DEL TDA CUIL
{
    persona->cuil=cuil;
}

void setEsChofer(PersonaPtr persona,bool esChofer)
{
    persona->esChofer=esChofer; //de nuevo, esto se puede hacer sin drama.
}

void setRepartoDiario(PersonaPtr persona, bool RepartoDiario)
{
    persona->RepartoDiario = RepartoDiario;
}

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE GETTERS///
///-----------------------------------------------------------------------------------------------------------///

char *getNombre(PersonaPtr persona)
{
    return persona->nombre;
}

char *getApellido(PersonaPtr persona)
{
    return persona->apellido;
}

DomicilioPtr getDomicilio(PersonaPtr persona)
{
    return persona->domicilio;
}

CuilPtr getCuilPersona(PersonaPtr persona) ///NUEVO NOMBRE PARA NO CONFUNDIR CON GETCUIL DEL TDA CUIL
{
    return persona->cuil;
}

bool getEsChofer(PersonaPtr persona)
{
    return persona->esChofer;
}

bool getRepartoDiario(PersonaPtr persona)
{
    return persona->RepartoDiario;
}

///-----------------------------------------------------------------------------------------------------------///
                            ///SECCION DE FUNCIONES DE OPERACIONES CON PERSONA///
///-----------------------------------------------------------------------------------------------------------///

void mostrarPersona(PersonaPtr persona)
{
    printf("\tTipo: ");
    if(getEsChofer(persona))
    {
        printf("Chofer\n");
    }
    else
    {
        printf("Cliente\n");
    }
    printf("\tNombre: %s\n",getNombre(persona));
    printf("\tApellido: %s\n",getApellido(persona));
    printf("\tDomicilio: ");
    mostrarDomicilio(getDomicilio(persona));
    mostrarCuil(getCuilPersona(persona));
    printf("\n\n");
}

bool personasIguales(PersonaPtr persona1,PersonaPtr persona2)
{
    return cuilsIguales(getCuilPersona(persona1),getCuilPersona(persona2));
}

bool VerificarCuilUnico(CentroLogisticoPtr centroLogistico, char* CuilComprobar)
{
    PersonaPtr PersonaTemporal;
    CuilPtr CuilTemporal;
    bool CuilUnico = true;
    ListaPtr ListaAuxiliar = crearLista();
    agregarLista(ListaAuxiliar, getPersonas(centroLogistico) );
    while(!listaVacia(ListaAuxiliar))
    {
        PersonaTemporal = (PersonaPtr)getCabecera(ListaAuxiliar);
        CuilTemporal = getCuilPersona(PersonaTemporal);
        if( strcmp(getCuil(CuilTemporal), CuilComprobar) == 0 )
        {
            CuilUnico = false;
        }
        ListaPtr ListaDestruir = ListaAuxiliar;
        ListaAuxiliar = getResto(ListaAuxiliar);
        ListaDestruir = destruirLista(ListaDestruir, false);
    }
    ListaAuxiliar = destruirLista(ListaAuxiliar, false);
    return CuilUnico;
}


bool menuCargarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    char nombre[100];
    char apellido[100];
    PersonaPtr persona=0;
    CuilPtr cuil=0;
    DomicilioPtr domicilio=0;
    bool CuilValido = false;
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

        do
        {
            cuil=cargarCuil(cuil);
            CuilValido = VerificarCuilUnico(centroLogistico, getCuil(cuil));
            if(!CuilValido)
            {
                printf("\n\n\t [Usted ha ingresado un cuil ya existente...] \n\n");
                presionarEnterYLimpiarPantalla();
            }
        }while(!CuilValido);

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
    bool cambiosGuardados = true;
    int EleccionMenuModoAccion=0;
    int EleccionAccion=0;
    int cantidadCorrectas=0;
    int cantIndices=0;
    int indices[100];
    PersonaPtr personaRemovida;
    EleccionMenuModoAccion = menuModoAccion();
    if(esChofer && EleccionMenuModoAccion != 0)
    {
        mostrarPersonas(centroLogistico, 1);
        printf("ELIMINAR CHOFR \n\n");
    }
    if(!esChofer && EleccionMenuModoAccion != 0)
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
            cambiosGuardados = false;
        }
        else
        {
            printf("\n\t [Ha elegido un tipo de persona inadecuado...] \n\n");
            printf("\n\n\t [Se procedera a retirarlo del menu...] \n\n");
            printf("\n\t [Se deshara todas las elecciones realizadas...] \n\n");
            presionarEnterYLimpiarPantalla();
        }
        break;
    case 2:
        cantidadCorrectas = 0;
        printf("[ACLARACION]Eliga la cantidad de indices...\n");
        cantIndices = menuModoAccion1( getPersonas(centroLogistico) );
        menuModoAccion2( getPersonas(centroLogistico) , cantIndices, indices);
        for(int i=0;i<cantIndices+1;i++)
        {
            if(getEsChofer(getDatoLista(getPersonas(centroLogistico),indices[i])) == esChofer)
            {
                cantidadCorrectas++;
            }
        }
        if(cantidadCorrectas == cantIndices+1)
        {
            for(int i=0;i<cantIndices+1;i++)
            {
                personaRemovida = removerPersona(centroLogistico,indices[i]-i);
                personaRemovida = destruirPersona(personaRemovida);
            }
            cambiosGuardados = false;
        }
        else
        {
            printf("\n\t [Ha elegido un tipo de persona inadecuado...] \n\n");
            printf("\n\n\t [Se procedera a retirarlo del menu...] \n\n");
            printf("\n\t [Se deshara todas las elecciones realizadas...] \n\n");
            presionarEnterYLimpiarPantalla();
        }
        break;
    case 3:
        cantidadCorrectas=0;
        menuModoAccion3(getPersonas(centroLogistico),indices);
        for(int i=indices[0];i<=indices[1];i++)
        {
            if(getEsChofer(getDatoLista(getPersonas(centroLogistico),i)) == esChofer)
            {
                cantidadCorrectas++;
            }
        }
        if(cantidadCorrectas == indices[1]-indices[0]+1)
        {
            for(int i=indices[0];i<=indices[1];i++)
            {
                personaRemovida = removerPersona(centroLogistico,indices[0]);
                personaRemovida = destruirPersona(personaRemovida);
            }
            cambiosGuardados = false;
        }
        else
        {
            printf("\n\t [Ha elegido un tipo de persona inadecuado...] \n\n");
            printf("\n\t [Se procedera a retirarlo del menu...] \n");
            printf("\n\t [Se deshara todas las elecciones realizadas...] \n\n");
            presionarEnterYLimpiarPantalla();
        }
        break;
    case 0:
        break;
    default:
        printf("Eleccion equivocada \n");
        break;
    }
    return cambiosGuardados;
}



bool menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    int opcion = 0;
    bool continuar = false;
    bool cambiosGuardados = true;
    do
    {
        if(esChofer)
        {
            if( verificarExistenciaPersonas(centroLogistico, true) )
            {
                cambiosGuardados = eliminarPersona(centroLogistico, esChofer);
            }
            else
            {
                printf("\n\t [No existen choferes para eliminar...] \n");
            }
        }
        else
        {
            if( verificarExistenciaPersonas(centroLogistico, false)  )
            {
                cambiosGuardados = eliminarPersona(centroLogistico, esChofer);
            }
            else
            {
                printf("\n\t [No existen clientes para eliminar...] \n");
            }
        }
        if( !cambiosGuardados )
        {
            continuar = menuContinuar();
        }
        else
        {
            continuar = false;
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
    if( !cambiosGuardados )
    {
        opcion = menuGuardarCambios();
        if(opcion == 1)
        {
            cambiosGuardados = guardarPersonas(centroLogistico);
        }
    }
    return cambiosGuardados;
}

void cambiarPersona(CentroLogisticoPtr centroLogistico, PersonaPtr personaAModificar, bool esChofer)
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
        printf("0. Volver\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("\n\t [Nombre]: ");
                seleccionarString(nNombre);
                printf("\n\t [Apellido]: ");
                seleccionarString(nApellido);
                setNombre(personaAModificar,nNombre);
                setApellido(personaAModificar,nApellido);
            break;
            case 2:
                printf("\n\n Ingrese el nuevo domicilio: ");
                actualizarDomicilio(getDomicilio(personaAModificar));
            break;
            case 3:
                do
                {
                    actualizarCuil(getCuilPersona(personaAModificar));
                    if(!VerificarCuilUnico(centroLogistico, getCuil(getCuilPersona(personaAModificar))))
                    {
                        mostrarPersonas(centroLogistico, 3);
                        printf("\n\n\t [No ha ingresado un cuil unico...] \n\n");
                        printf("\n\t [Verifique que el cuil que ingresa sea unico...] \n");
                        printf("\n\t [Compruebe usted mismo los cuils existentes...] \n\n");
                        presionarEnterYLimpiarPantalla();
                    }
                }while(!VerificarCuilUnico(centroLogistico, getCuil(getCuilPersona(personaAModificar))));
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
            case 0:
                break;
            default:
                printf("\nOpcion incorrecta.\n\n");
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
    int resultado=0;
    int modoAccion=0,Eleccion=0,Cantidad=0,cantidadCorrectas=0;
    int Elecciones[10];
    PersonaPtr personaModificar;
    bool cambiosGuardados = true;
    bool continuar;
    if(listaVacia(getPersonas(centroLogistico)))
    {
        if(esChofer)
        {
            printf("\n\n\t ERROR: Lista vacía. Debe agregar choferes para poder modificarlos. \n\n");
            presionarEnterYLimpiarPantalla();
        }
        else
        {
            printf("\n\n\t ERROR: Lista vacía. Debe agregar clientes para poder modificarlos.\n\n");
            presionarEnterYLimpiarPantalla();
        }
    }
    else
    {
        do
        {
            modoAccion = menuModoAccion();
            if(esChofer && modoAccion != 0)
            {
                mostrarPersonas(centroLogistico,1);
            }
            if(!esChofer && modoAccion != 0)
            {
                mostrarPersonas(centroLogistico,2);
            }
            switch(modoAccion)
            {
            case 1:
                Eleccion = menuModoAccion1(getPersonas(centroLogistico));
                if(getEsChofer(getDatoLista(getPersonas(centroLogistico),Eleccion)) == esChofer)
                {
                    personaModificar=getDatoLista(getPersonas(centroLogistico),Eleccion);
                    cambiarPersona(centroLogistico, personaModificar,esChofer);
                    cambiosGuardados = false;
                }
                else
                {
                    printf("\n\n\t ERROR: No ha elegido correctamente \n\n");
                    presionarEnterYLimpiarPantalla();
                }
                break;
            case 2:
                cantidadCorrectas=0;
                printf("\n\n\t [ACLARACION]Eliga la cantidad de indices...\n\n");
                Cantidad = menuModoAccion1(getPersonas(centroLogistico));
                menuModoAccion2(getPersonas(centroLogistico),Cantidad,Elecciones);
                for(int i=0;i<Cantidad+1;i++)
                {
                    if(getEsChofer(getDatoLista(getPersonas(centroLogistico),Elecciones[i])) == esChofer)
                    {
                        cantidadCorrectas++;
                    }
                }
                if(cantidadCorrectas == Cantidad+1)
                {
                    for(int i=0;i<Cantidad+1;i++)
                    {
                        personaModificar=getDatoLista(getPersonas(centroLogistico),Elecciones[i]);
                        cambiarPersona(centroLogistico, personaModificar,esChofer);
                        cambiosGuardados = false;
                    }
                }
                else
                {
                    printf("\n\n\t ERROR: No ha elegido correctamente \n\n");
                    presionarEnterYLimpiarPantalla();
                }
                break;
            case 3:
                cantidadCorrectas=0;
                menuModoAccion3(getPersonas(centroLogistico),Elecciones);
                for(int i=Elecciones[0];i<=Elecciones[1];i++)
                {
                    if(getEsChofer(getDatoLista(getPersonas(centroLogistico),i)) == esChofer)
                    {
                        cantidadCorrectas++;
                    }
                }
                if(cantidadCorrectas == Elecciones[1]-Elecciones[0]+1)
                {
                    for(int i=Elecciones[0];i<=Elecciones[1];i++)
                    {
                        personaModificar = getDatoLista(getPersonas(centroLogistico),i);
                        cambiarPersona(centroLogistico, personaModificar,esChofer);
                        cambiosGuardados = false;
                    }
                }
                else
                {
                    printf("\n\n\t ERROR: No ha elegido correctamente \n\n");
                    presionarEnterYLimpiarPantalla();
                }
                break;
            case 0:
                break;
            default:
                printf("\n\n\t Eleccion equivocada \n\n");
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
            cambiosGuardados = guardarPersonas(centroLogistico);
        }
    }
    return cambiosGuardados;
}


void menuBuscarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    bool continuar;
    char cuilStr[100];
    if(listaVacia(getPersonas(centroLogistico)))
    {
        if(esChofer)
        {
             printf("\n\n\t ERROR: Lista vacia. No hay choferes para buscar \n\n");
             presionarEnterYLimpiarPantalla();
        }
        else
        {
            printf("\n\n\t ERROR: Lista vacia. No hay clientes para buscar \n\n");
            presionarEnterYLimpiarPantalla();
        }
    }
    else
    {
        do
        {
            system("cls");
            printf("0. Volver\n");
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

            if(!buscarPersona(centroLogistico,cuilStr,esChofer) && strlen(cuilStr) != 1)
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
            if(strlen(cuilStr) == 1)
            {
                continuar = false;
            }
            else
            {
                continuar = menuContinuar();
            }
        } while(continuar);
    }
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
        switch(MENU)
        {
        case 1:
            do
            {
                mostrarPersonas(centroLogistico, 2);
                ELECCION = menuModoAccion1( getPersonas(centroLogistico) );
                PersonaBuscada = getDatoLista( getPersonas(centroLogistico), ELECCION );
                if( getEsChofer(PersonaBuscada) )
                {
                    printf("\n\n\t [No ha elegido correctamente...] \n\n");
                    presionarEnterYLimpiarPantalla();
                }
            }while(getEsChofer(PersonaBuscada));
            break;
        case 2:
            do
            {
                mostrarPersonas(centroLogistico, 2);
                printf("\n Ingrese el cuil a buscar: ");
                seleccionarString(CuilBuscar);
                PersonaBuscada = devolverPersona(centroLogistico, CuilBuscar);
                if(PersonaBuscada == NULL)
                {
                    printf("\n\n\t [No ha elegido correctamente...] \n\n");
                    presionarEnterYLimpiarPantalla();
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
            system("cls");
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
                break;
            case 2:
                printf("(ORDENADO POR APELLIDO)\n");
                ordenarPersonas(centroLogistico, 2, tipo);
                break;
            case 3:
                printf("(ORDENADO POR NOMBRE Y APELLIDO)\n");
                ordenarPersonas(centroLogistico, 3, tipo);
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






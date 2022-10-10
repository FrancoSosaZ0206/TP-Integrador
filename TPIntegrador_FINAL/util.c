#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "Lista.h"

const bool ShowHelp=false;

void *obtenerMemoria(size_t tamanio)
{
    void *p=malloc(tamanio);
    if(p==NULL)
    {
        printf("\n\nERROR AL OBTENER MEMORIA.\n\n");
        exit(1);
    }
    return p;
}

char* crearStringDinamico(char* literal)
{
    char* buffer=(char*)obtenerMemoria(sizeof(char)*strlen(literal)+1);
    strcpy(buffer,literal);
    return buffer;
}

void destruirStringDinamico(char *buffer)
{
    buffer=NULL;
    free(buffer);
}

void limpiarBufferTeclado()
{
    //char c;
    //while((c=getchar())!='\n' && c!=EOF){};
    fflush(stdin);
    fflush(stdin);
}

void p(){
    limpiarBufferTeclado();
    system("pause");
    limpiarBufferTeclado();
    system("cls");
    limpiarBufferTeclado();
}

bool numeroValido(int numero){
    if(numero>0){
        return true;
    }else{
        system("cls");
        printf("Numero incorrecto \n");
        printf("No existe la posibilidad de contar negativamente \n");
        printf("Vuelva a ingresar al menu nuevamente \n");
        printf("Presione [ ENTER ] para continuar... ");
        limpiarBufferTeclado();
        getchar();
        limpiarBufferTeclado();
        system("cls");
        return false;
    }
}

int solicitarEnteroPorConsola()
{
    int eleccion = 0;
    if(ShowHelp)
    {
        printf("Seleccione un numero\n");
        printf("Formato adecuado [ Numero elegido > 0 ] : ");
    }
    limpiarBufferTeclado();
    scanf("%d", &eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

int seleccionarNumero()
{
    int eleccion = 0;
    bool valido = false;
    while(!valido)
    {
        eleccion = solicitarEnteroPorConsola();
        valido = numeroValido(eleccion);
    }
    return eleccion;
}

bool verificarLimiteLista(ListaPtr lista, int eleccion){
    limpiarBufferTeclado();
    system("cls");
    bool valido;
    int tamanioLista=longitudLista(lista);
    if(tamanioLista!=0){
        if(eleccion>=0 && eleccion<tamanioLista){
            valido=true;
        }else{
            printf("Eleccion invalida\n");
            printf("La lista que ha seleccionado no posee ese indice\n");
            valido=false;
        }
    }else{
        printf("La lista que desea visualizar no posee elementos\n");
        valido=false;
    }
    limpiarBufferTeclado();
    return valido;
}

void mensajeError(){
    system("cls");
    limpiarBufferTeclado();
    printf("No ha seguido las instrucciones indicadas\n");
    printf("El servicio procedera a realizar la ejecucion de salida\n");
    printf("Volviendo al menu seleccionado\n");
    limpiarBufferTeclado();
    system("pause");
    system("cls");
}

char* SeleccionarStringDinamico(){
    char StringEstatico[100];
    char* StringDinamico;
    limpiarBufferTeclado();
    printf("Ingrese el string: ");
    scanf("%[^\n]%*c",StringEstatico);
    limpiarBufferTeclado();
    StringDinamico=crearStringDinamico(StringEstatico);
    return StringDinamico;
}

void SeleccionarStringEstatico(char* String){
    limpiarBufferTeclado();
    if(ShowHelp)
    {
        printf("Ingrese una cadena de caracteres correspondiente \n");
        printf("Ejemplo: Gaston Romero [ ENTER ] \n");
        printf(" [ Ingrese el String ] : ");
    }
    scanf("%[^\n]%*c",String);
    limpiarBufferTeclado();
}


void presionarEnterYLimpiarPantalla()
{
    printf("\n\n Presione [ ENTER ] para continuar ...");
    limpiarBufferTeclado();
    getchar();
    limpiarBufferTeclado();
    system("cls");
}

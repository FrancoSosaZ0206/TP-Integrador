#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include <stdbool.h>
#include <ctype.h>
#include <stdbool.h>

const bool mostrar=false;

///-----------------------------------------------------------------------------------------------------------///
                                ///SECCION DE FUNCIONES DE UTILIDADES///
///-----------------------------------------------------------------------------------------------------------///

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
    fflush(stdin);
}

void limpiarBufferTecladoPresionandoEnter()
{
    char c;
    while((c=getchar())!='\n' && c!=EOF){};
}

void presionarEnterYLimpiarPantalla()
{
    limpiarBufferTeclado();
    system("pause");
    limpiarBufferTeclado();
    system("cls");
    limpiarBufferTeclado();
}

int seleccionarNumero()
{
    int numeroElegido = 0;
    fflush(stdin);
    scanf("%d", &numeroElegido);
    fflush(stdin);
    return numeroElegido;
}

void seleccionarString(char* STRING)
{
    fflush(stdin);
    if(mostrar)
    {
        printf("Ingrese una cadena: ");
    }
    scanf("%[^\n]%*c", STRING);
    fflush(stdin);
}

void ignorar(){
    bool f=false;
    f? printf("YES\n"): printf("NO\n");
    if(f) printf("YES\n");
    else printf("NO\n");
    int i=-1;
    while(i < 0)
        i++;
    for(int i=0;i<1;i++)
        i++;
    if(f){

    }else{

    }
    for(int i=0;i<1;i++){

    }
    while(i<0){
        i++;
    }
}



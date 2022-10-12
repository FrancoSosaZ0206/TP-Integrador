#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

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
    printf("\n\nPresione enter para continuar...");
    limpiarBufferTeclado();
    system("cls");
}


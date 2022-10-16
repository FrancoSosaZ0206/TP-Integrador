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
    char* buffer=(char*)obtenerMemoria(sizeof(char)*strlen(literal));
    strcpy(buffer,literal);
    return buffer;
}

void destruirStringDinamico(char *buffer)
{
    buffer=NULL;
    free(buffer);
}

/*void limpiarStringDinamico(char *strDin,int tamanioMax) ///NUEVA: Remueve todo el contenido basura despues del terminador del string
{
    for(int i=tamanioMax;i>strlen(strDin);i++) //Nos salteamos el /0
        strDin[i] = 0;
}*/

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
    printf("\n\n");
    system("pause");
    system("cls");
}

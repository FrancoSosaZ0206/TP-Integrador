#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

char *destruirStringDinamico(char *buffer)
{
    free(buffer);
    return NULL;
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
    printf("\n\n");
    system("pause");
    system("cls");
}


int extraerDigitosString(char *source,int buffer[])
{
    int n=strlen(source)+1;

    int i=0; //este cuenta la cantidad de caracteres analizados
    int k=0; //este cuenta la cantidad de dígitos extraídos
    int x=0; //y este cuenta la cantidad de caracteres que no son números (los consideramos basura)

    for(i=0;i<n;i=k+x) //Mientras haya más caracteres por ver...
    {
        if(isdigit(source[i])) //Si el caracter actual del string es un numero
            for(k=i-x;isdigit(source[i]);k++,i++)
                buffer[k] = (int)source[i] - 48;
        else
            x++;
    }
    return k-1;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
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
}

int seleccionarNumero()
{
    int numeroElegido=-1;
    while(numeroElegido < 0)
    {
        fflush(stdin);
        if(mostrar)
        {
            printf("Seleccione un numero natural: ");
        }
        scanf("%d", &numeroElegido);
        fflush(stdin);
        if(numeroElegido < 0)
        {
            printf("Numero equivocado, eliga un numero");
            printf(" comprendido entre 0 y +infinito \n");
            presionarEnterYLimpiarPantalla();
        }
    }
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

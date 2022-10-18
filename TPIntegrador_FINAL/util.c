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
    char* buffer=(char*)obtenerMemoria(sizeof(char)*strlen(literal));
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
    printf("\n\n");
    system("pause");
    system("cls");
}


void extraerDigitosString(char *source,int buffer[])
{
    int *temp;
    int aux=0;

    int n=strlen(source);

    int k=0;
    int garbage=1;

    for(int i=0;i<n;i=k+garbage) //Mientras haya más caracteres por ver...
    {
        if(isdigit(source[i])) //Si el caracter actual del string es un numero
        {
            printf("i=%d\tk = %d\tsource[i]=%s\n\n",i,k,source+i);

            sscanf(source+i,"%d",&temp[i]); //lo metemos en el vector
            aux = temp[i];

            printf("temp[i] = %d\taux = %d\n\n",temp[i],aux);

            presionarEnterYLimpiarPantalla();

            while(aux > 0) //hasta que el numero insertado no sea divisible por 10 (y de cociente entero)
            {
                printf("aux = %d\n",aux);
                printf("resto = %d\n\n",aux % 10);

                buffer[k] = aux % 10; //obtenemos el resto entre el numero insertado y 10 (resto(num / 10))
                aux /= 10;            //dividimos el numero por 10

                k++;

                presionarEnterYLimpiarPantalla();
            } //repetimos el proceso hasta que no queden más dígitos por separar del numero
            for(int j=0;j<=(k/2);j++)
            { //ordenamos el vector para que mantenga el orden original de los dígitos
                aux = buffer[j];
                buffer[j] = buffer[k-j];
                buffer[k-j] = aux;
            }
        }

        garbage++;

        printf("NEXT NUMBER!");
        presionarEnterYLimpiarPantalla();
    }

    int i=0;
    printf("\n\n");
    while(temp[i])
    {
        printf("temp[%d] = %d\n",i,*(temp+i));
        i++;
    }
    i=0;
    printf("\n\n");
    while(buffer[i])
    {
        printf("buffer[%d] = %d\n",i,*(buffer+i));
        i++;
    }
}

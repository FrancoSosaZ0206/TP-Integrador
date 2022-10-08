#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDACuil.h"
#include "util.h"


CuilPtr crearCuil(char *cuilStr)
{
    CuilPtr cuil=(CuilPtr)obtenerMemoria(sizeof(Cuil));
    cuil->cuil=crearStringDinamico(cuilStr);
    return cuil;
}

CuilPtr crearCuilNumeros(int tipoPersona,int dni,int nVerificador)
{
    char *temp;
    sprintf(temp,"%d %d %d",tipoPersona,dni,nVerificador);
    int longitudString=strlen(temp)+1;
    temp[longitudString]=0;

    char sCuil=crearStringDinamico(temp);

    CuilPtr cuil=(CuilPtr)obtenerMemoria(sizeof(Cuil));

    cuil->cuil=sCuil;

    return cuil;
}

CuilPtr destruirCuil(CuilPtr cuil)
{
    destruirStringDinamico(cuil->cuil);

    free(cuil);

    return NULL;
}


CuilPtr setCuil(CuilPtr cuil,char *cuilStr) ///NUEVA
{
    cuil->cuil = cuilStr;
}

void setTipo(CuilPtr cuil,int tipo)
{
    int oldTipo=0;
    int oldDni=0;
    int oldNVerif=0;

    //Dividimos el string en 3 variables int
    sscanf(cuil->cuil,"%d %d %d",&oldTipo,&oldDni,&oldNVerif);
    //Vaciamos el contenido del string
    cuil->cuil="";
    //Insertamos el nuevo numero junto con los otros 2 antiguos
    sprintf(cuil->cuil,"%d %d %d",tipo,oldDni,oldNVerif);
}

void setDni(CuilPtr cuil,int dni)
{
    int oldTipo=0;
    int oldDni=0;
    int oldNVerif=0;

    sscanf(cuil->cuil,"%d %d %d",&oldTipo,&oldDni,&oldNVerif);

    cuil->cuil="";

    sprintf(cuil->cuil,"%d %d %d",oldTipo,dni,oldNVerif);
}

void setNVerificador(CuilPtr cuil,int nVerificador)
{
    int oldTipo=0;
    int oldDni=0;
    int oldNVerif=0;

    //Obtenemos los primeros 2 numeros y los almacenamos en un entero;
    sscanf(cuil->cuil,"%d %d %d",&oldTipo,&oldDni,&oldNVerif);

    cuil->cuil="";

    sprintf(cuil->cuil,"%d %d %d",oldTipo,oldDni,nVerificador);
}


char* getCuil(CuilPtr cuil) ///NUEVA
{
    return cuil->cuil;
}

int getTipo(CuilPtr cuil)
{
    int tipo=0;
    int dni=0;
    int nVerif=0;

    //Dividimos el string en 3 variables int
    sscanf(cuil->cuil,"%d %d %d",&tipo,&dni,&nVerif);
    //retornamos el que queríamos
    return tipo;
}

int getDni(CuilPtr cuil)
{
    int tipo=0;
    int dni=0;
    int nVerif=0;

    //Dividimos el string en 3 variables int
    sscanf(cuil->cuil,"%d %d %d",&tipo,&dni,&nVerif);
    //retornamos el que queríamos
    return dni;
}

int getNVerificador(CuilPtr cuil)
{
    int tipo=0;
    int dni=0;
    int nVerif=0;

    //Dividimos el string en 3 variables int
    sscanf(cuil->cuil,"%d %d %d",&tipo,&dni,&nVerif);
    //retornamos el que queríamos
    return nVerif;
}


///NO APTA PARA TIPO EMPRESA
bool esCuilValido(CuilPtr cuil) ///NUEVA
{
/** COMO CALCULAR EL CUIL / CUIT ***

"XY 12345678 Z"

CUIL/T: Son 11 números en total:
XY – 12345678 – Z

XY: Indican el tipo (Masculino, Femenino o una empresa)
12345678: Número de DNI
Z: Código Verificador

---------------------------------------------------------------------

Se determina XY con las siguientes reglas
Masculino:20
Femenio:27
Empresa:30

1. Se multiplica XY 12345678 por un número de forma separada:

X * 5
Y * 4
1 * 3
2 * 2
3 * 7
4 * 6
5 * 5
6 * 4
7 * 3
8 * 2

2. Se suman dichos resultados.

3. El resultado obtenido se divide por 11.

4. De esa división se obtiene un Resto que determina Z:

    a) Si el resto es 0, entoces Z=0.

    b) Si el resto es 1, entonces se aplica la siguiente regla:
        I - Si es hombre: Z=9 y XY pasa a ser 23.
       II - Si es mujer: Z=4 y XY pasa a ser 23.

    c) Caso contrario, XY pasa a ser (11 - Resto).
*/

    char *cuilStr = getCuil(cuil);

//1. Obtenemos cada numero y hacemos las multiplicaciones
    int x=(int)cuilStr[0] * 5;
    int y=(int)cuilStr[1] * 4;
//cuilStr[2] = " " <<< un espacio
    int n1=(int)cuilStr[3] * 3;
    int n2=(int)cuilStr[4] * 2;
    int n3=(int)cuilStr[5] * 7;
    int n4=(int)cuilStr[6] * 6;
    int n5=(int)cuilStr[7] * 5;
    int n6=(int)cuilStr[8] * 4;
    int n7=(int)cuilStr[9] * 3;
    int n8=(int)cuilStr[10] * 2;
//obtenemos el Z actual
    int z=getNVerificador(cuil);

    int sumatoria = x+y+n1+n2+n3+n4+n5+n6+n7+n8;
    int division = sumatoria / 11;
    int resto = sumatoria % 11;

    int tipo=getTipo(cuil);

    int zRes = 0;

    switch(resto)
    {
    case 0:
//Se deja como está.
        break;
    case 1:

        switch(tipo)
        {
        case 20:
            zRes = 9;
            break;
        case 27:
            zRes = 4;
            break;
        default: ///Posiblemente salga este mensaje aunque el tipo sea empresa.
            printf("\n\nERROR: TIPO DE CUIL INEXISTENTE.\n\n");
            exit(1);
        }

    default:
//zRes se deja como está.
        break;
    }
//Si son iguales, es un cuil valido (retornará true), caso contrario es invalido (false).
    return (z==zRes);
}



void helpCuil()
{
    printf("\n\n----------------------------------------\n");
    printf("AYUDA CUIL\n\n");
    printf("CUIL = XY 12345678 Z\n");

    printf("\tXY = Tipo de persona\n");
    printf("\t\t20 = Hombre\n");
    printf("\t\t27 = Mujer\n");
    printf("\t\t30 = Empresa\n\n");

    printf("\t12345678 = DNI\n");
    printf("\tZ = Numero Verificador");
    printf("\n\n----------------------------------------\n");
}

void mostrarCuil(CuilPtr cuil)
{
    printf("\tCuil: %s\n",getCuil(cuil));
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDACuil.h"
#include <math.h>
#include "util.h"


CuilPtr crearCuil(char *cuilStr)
{
    CuilPtr cuil=(CuilPtr)obtenerMemoria(sizeof(Cuil));

    cuil->cuil=crearStringDinamico(cuilStr);

    return cuil;
}

CuilPtr crearCuilNumeros(int tipoPersona,int dni,int nVerificador)
{
    char temp[14];
    sprintf(temp,"%d %d %d",tipoPersona,dni,nVerificador);
    int longitudString=strlen(temp)+1;
    temp[longitudString]=0;

    char *sCuil=crearStringDinamico(temp);

    CuilPtr cuil=(CuilPtr)obtenerMemoria(sizeof(Cuil));

    cuil->cuil=sCuil;

    return cuil;
}

CuilPtr destruirCuil(CuilPtr cuil)
{
    cuil->cuil=destruirStringDinamico(cuil->cuil);

    free(cuil);

    return NULL;
}


void setCuil(CuilPtr cuil,char *cuilStr) ///NUEVA
{
    cuil->cuil = destruirStringDinamico(cuil->cuil);
    cuil->cuil = crearStringDinamico(cuilStr);
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


char *getCuil(CuilPtr cuil) ///NUEVA
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
    //retornamos el que quer�amos
    return tipo;
}

int getDni(CuilPtr cuil)
{
    int tipo=0;
    int dni=0;
    int nVerif=0;

    //Dividimos el string en 3 variables int
    sscanf(cuil->cuil,"%d %d %d",&tipo,&dni,&nVerif);
    //retornamos el que quer�amos
    return dni;
}

int getNVerificador(CuilPtr cuil)
{
    int tipo=0;
    int dni=0;
    int nVerif=0;

    //Dividimos el string en 3 variables int
    sscanf(cuil->cuil,"%d %d %d",&tipo,&dni,&nVerif);
    //retornamos el que quer�amos
    return nVerif;
}


///NO APTA PARA TIPO EMPRESA
bool esCuilValido(CuilPtr cuil)
{
/** COMO CALCULAR EL CUIL / CUIT ***

"XY 12345678 Z"

CUIL/T: Son 11 n�meros en total:
XY � 12345678 � Z

XY: Indican el tipo (Masculino, Femenino o una empresa)
12345678: N�mero de DNI
Z: C�digo Verificador

---------------------------------------------------------------------

Se determina XY con las siguientes reglas
Masculino:20
Femenio:27
Empresa:30

1. Se multiplica XY 12345678 por un n�mero de forma separada:

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

4. De esa divisi�n se obtiene un Resto que determina Z:

    a) Si el resto es 0, entoces Z=0.

    b) Si el resto es 1, entonces se aplica la siguiente regla:
        I - Si es hombre: Z=9 y XY pasa a ser 23.
       II - Si es mujer: Z=4 y XY pasa a ser 23.

    c) Caso contrario, XY pasa a ser (11 - Resto).
*/

    ///1. Obtenemos cada numero y hacemos las multiplicaciones
    char digitosCuil[100];
    strcpy(digitosCuil,getCuil(cuil));

    int sumatoria = 0;
    int multiplicador[10] = {5,4,3,2,7,6,5,4,3,2};

    sumatoria += (((int)digitosCuil[0])-48)*multiplicador[0];
    sumatoria += (((int)digitosCuil[1])-48)*multiplicador[1];

    sumatoria += (((int)digitosCuil[3])-48)*multiplicador[2];
    sumatoria += (((int)digitosCuil[4])-48)*multiplicador[3];
    sumatoria += (((int)digitosCuil[5])-48)*multiplicador[4];
    sumatoria += (((int)digitosCuil[6])-48)*multiplicador[5];

    sumatoria += (((int)digitosCuil[7])-48)*multiplicador[6];
    sumatoria += (((int)digitosCuil[8])-48)*multiplicador[7];
    sumatoria += (((int)digitosCuil[9])-48)*multiplicador[8];
    sumatoria += (((int)digitosCuil[10])-48)*multiplicador[9];

    int zOriginal = ((int)digitosCuil[12])-48;
    int division = ceil(sumatoria / 11);
    int resto = sumatoria - (division * 11);
    int zRes = 11 - resto;
    int tipo = getTipo(cuil);

    switch(resto)
    {
    case 0: ///Se deja como est�. break;
    case 1:
        switch(tipo){
            case 20:
                zRes = 9;
                setTipo(cuil,23);
                break;
            case 27:
                zRes = 4;
                setTipo(cuil,23);
                break;
            default:
                ///Posiblemente salga este mensaje aunque el tipo sea empresa.
                printf("\n\nERROR: TIPO DE CUIL INEXISTENTE.\n\n");
        }
        break;
    }
    ///Si son iguales, es un cuil valido (retornar� true), caso contrario es invalido (false).
    return (zOriginal == zRes);
}



void helpCuil(){
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

void mostrarCuil(CuilPtr cuil){
    printf("\tCuil: %s\n",getCuil(cuil));
}

bool cuilsIguales(CuilPtr cuil1,CuilPtr cuil2){
    return strcmp(getCuil(cuil1),getCuil(cuil2)) == 0;
}

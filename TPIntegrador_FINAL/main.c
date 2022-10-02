#include <stdio.h>
#include <stdlib.h>
#include "Files.h"
#include "Lista.h"
#include "Menus.h"
#include "test.h"
#include "util.h"

///HOLA COMO ESTÁS GASTON

//Todo bien, y tu?

///Que hiciste este fin de semana
/*
Yo jugué al basquet
Estuvo muy divertido jajaj
el equipo contrario hico 50 puntos y el nuestro solo 3
Pero no importa, la pase bien lol

Que bueno, seguro que dejaste todo en la cancha
Yo estuve visitando a mis abuelos, comi hasta reventar
Y disfrute mucho con ellos

La verdad que este fin de semana estuvo interesante

Probando con modificacion con codeblocks

No entiendo por que no funciona

*/

=======
//AAAAAAAAAAAAAAAAA
//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

/**
DIRECTORIOS (FRANCO S.)

Para crear y linkear archivos
E:\Franco\0. UNIVERSIDAD Y APRENDIZAJE\INFORMÁTICA\¡LIC. EN SISTEMAS - UNLa\CARRERA\1ER AÑO\PROGRAMACIÓN\TP INTEGRADOR\Código - FINAL - ACTUALIZAR PEN DRIVE\V1.7\TPIntegrador_FINAL\

Para abrir/guardar files = CARPETA "Archivos"
E:\Franco\0. UNIVERSIDAD Y APRENDIZAJE\INFORMÁTICA\¡LIC. EN SISTEMAS - UNLa\CARRERA\1ER AÑO\PROGRAMACIÓN\TP INTEGRADOR\Código - FINAL - ACTUALIZAR PEN DRIVE\V1.7\Archivos\
*/

int MAIN_MENU(CentroLogisticoPtr centroLogistico);

int main()
{
    CentroLogisticoPtr centroLogistico;

    int MAIN_OP=0;

    char *nombreCtroLog; //para una de las opciones.

    do
    {
        printf("START MENU - BIENVENIDO\n\n");
        printf("\t1. Soy nuevo - INICIAR DE CERO.\n");
        printf("\t2. Ya he ingresado antes - ABRIR ARCHIVOS.\n");
        printf("\t0. SALIR\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&MAIN_OP);

        system("cls");

        switch(MAIN_OP)
        {
        case 1:
            printf("\t\tINGRESE EL NOMBRE DEL CENTRO LOGISTICO\n\n\t\t");
            scanf("%[^\n]%*c",nombreCtroLog);
            centroLogistico = crearCentroLogisticoRapido(nombreCtroLog);
            MAIN_OP = MAIN_MENU(centroLogistico);
            break;
        case 2:
            centroLogistico = abrirTodo();
            if(centroLogistico==NULL)
            {
                printf("ERROR AL ABRIR.\n\n");
                exit(1);
            }
            else
                MAIN_OP = MAIN_MENU(centroLogistico);
            break;
        case 0:
            printf("Hasta pronto!\n\n");
            break;
        default:
            printf("Opcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }
    } while(MAIN_OP!=0);

    return 0;
}


int MAIN_MENU(CentroLogisticoPtr centroLogistico)
{
    ///Menúes
    int MAIN_OP = 0;
    int op1=0;  //usamos otras para los loops internos, para evitar que,
    int op2=0;  //si queremos volver atrás, se vuelva todo atrás o cosas así.

    do
    {
        system("cls");
        printf("CENTRO LOGISTICO '%s' - MENU PRINCIPAL\n\n",getNombreCentroLogistico(centroLogistico));

        printf("1. BASE DE DATOS\n");
        printf("2. REPARTOS\n");
        printf("3. VER RESULTADOS DE ENTREGAS\n");
        printf("4. EMITIR LISTADOS\n");
        printf("5. GUARDAR CAMBIOS\n"); ///NUEVO
        printf("0. SALIR\n");
        printf("\n-----------------------------------------\n\n");
        printf("Elija una opcion: ");
        scanf("%d", &MAIN_OP);
        limpiarBufferTeclado();


        switch(MAIN_OP)
        {
        case 1:
            do
            {
                system("cls");
                printf("BASE DE DATOS\n\n");

                printf("1. Cargar Datos\n");
                printf("2. Eliminar Datos\n");
                printf("3. Modificar Datos\n");
                printf("4. Buscar Datos\n");
                printf("0. Volver\n");
                printf("\n-----------------------------------------\n\n");
                printf("Elija una opcion: ");
                scanf("%d", &op1);
                limpiarBufferTeclado();


                switch(op1)
                {
                case 1:
                    do
                    {
                        system("cls");
                        printf("CARGAR DATOS\n\n");

                        printf("1. Cargar paquete\n");
                        printf("2. Cargar cliente\n");
                        printf("3. Cargar chofer\n");
                        printf("4. Cargar vehiculo\n");
                        printf("0. Volver\n");
                        printf("\n-----------------------------------------\n\n");
                        printf("Elija una opcion: ");
                        scanf("%d", &op2);
                        limpiarBufferTeclado();


                        switch(op2)
                        {
                        case 1:
                            menuCargarPaquete(centroLogistico);
                            break;
                        case 2:
                            menuCargarPersona(centroLogistico,false);
                            break;
                        case 3:
                            menuCargarPersona(centroLogistico,true);
                            break;
                        case 4:
                            menuCargarVehiculo(centroLogistico);
                            break;
                        case 0:
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(op2!=0);
                    break;
                case 2:
                    do
                    {
                        system("cls");
                        printf("ELIMINAR DATOS\n\n");

                        printf("1. Eliminar Paquete\n");
                        printf("2. Eliminar Cliente\n");
                        printf("3. Eliminar Chofer\n");
                        printf("4. Eliminar Vehiculo\n");
                        printf("0. Volver\n\n");

                        printf("Elija una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();


                        switch(op2)
                        {
                        case 1:
                            menuEliminarPaquete(centroLogistico);

                            presionarEnterYLimpiarPantalla();
                            break;
                        case 2:
                            menuEliminarPersona(centroLogistico,false);

                            presionarEnterYLimpiarPantalla();
                            break;
                        case 3:
                            menuEliminarPersona(centroLogistico,true);

                            presionarEnterYLimpiarPantalla();
                            break;
                        case 4:
                            menuEliminarVehiculo(centroLogistico);

                            presionarEnterYLimpiarPantalla();
                            break;
                        case 0:
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(op2!=0);
                    break;
                case 3:
                    do
                    {
                        system("cls");
                        printf("MODIFICAR DATOS\n\n");

                        printf("1. Modificar Paquete\n");
                        printf("2. Modificar Cliente\n");
                        printf("3. Modificar Chofer\n");
                        printf("4. Modificar Vehiculo\n");
                        printf("0. Volver\n\n");

                        printf("Elija una opcion: ");
                        scanf("%d",&op2);
                        limpiarBufferTeclado();


                        switch(op2)
                        {
                        case 1:
                            menuModificarPaquete(centroLogistico);

                            presionarEnterYLimpiarPantalla();
                            break;
                        case 2:
                            menuModificarPersona(centroLogistico,false);

                            presionarEnterYLimpiarPantalla();
                            break;
                        case 3:
                            menuModificarPersona(centroLogistico,true);

                            presionarEnterYLimpiarPantalla();
                            break;
                        case 4:
                            menuModificarVehiculo(centroLogistico);

                            presionarEnterYLimpiarPantalla();
                            break;
                        case 0:
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(op2!=0);
                    break;
                case 4:
                    do
                    {
                        system("cls");
                        printf("BUSCAR DATOS\n\n");

                        printf("1. Buscar paquete\n"); //buscamos por ID
                        printf("2. Buscar cliente\n"); //buscamos por
                        printf("3. Buscar chofer\n"); //cuil
                        printf("4. Buscar vehiculo\n"); //buscamos por patente
                        printf("0. Volver\n");
                        printf("\n-----------------------------------------\n\n");
                        printf("Elija una opcion: ");
                        scanf("%d", &op2);
                        limpiarBufferTeclado();


                        switch(op2)
                        {
                        case 1:
                            menuBuscarPaquete(centroLogistico);

                            presionarEnterYLimpiarPantalla();
                            break;
                        case 2:
                            menuBuscarPersona(centroLogistico,false);

                            presionarEnterYLimpiarPantalla();
                            break;
                        case 3:
                            menuBuscarPersona(centroLogistico,true);

                            presionarEnterYLimpiarPantalla();
                            break;
                        case 4:
                            menuBuscarVehiculo(centroLogistico);

                            presionarEnterYLimpiarPantalla();
                            break;
                        case 0:
                            break;
                        default:
                            printf("\nOpcion incorrecta.\n\n");
                            presionarEnterYLimpiarPantalla();
                            break;
                        }
                    } while(op2!=0);
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    presionarEnterYLimpiarPantalla();
                    break;
                }
            } while(op1!=0);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            do
            {
                system("cls");
                printf("EMITIR LISTADOS\n\n");

                printf("1. Emitir listado de Paquetes\n");
                printf("2. Emitir listado de Clientes\n");
                printf("3. Emitir listado de Choferes\n");
                printf("4. Emitir listado de Vehiculos\n");
                printf("5. Emitir listado de Repartos\n");
                printf("0. Volver\n\n");

                printf("Elija una opcion: ");
                scanf("%d",&op1);
                limpiarBufferTeclado();


                switch(op1)
                {
                case 1:
                    system("cls");
                    printf("EMITIENDO LISTADO DE PAQUETES\n\n");

                    mostrarPaquetes(centroLogistico);

                    presionarEnterYLimpiarPantalla();
                    break;
                case 2:
                    system("cls");
                    printf("EMITIENDO LISTADO DE CLIENTES\n\n");

                    mostrarClientes(centroLogistico);

                    presionarEnterYLimpiarPantalla();
                    break;
                case 3:
                    system("cls");
                    printf("EMITIENDO LISTADO DE CHOFERES\n\n");

                    mostrarChoferes(centroLogistico);

                    presionarEnterYLimpiarPantalla();
                    break;
                case 4:
                    system("cls");
                    printf("EMITIENDO LISTADO DE VEHICULOS\n\n");

                    mostrarVehiculos(centroLogistico);

                    presionarEnterYLimpiarPantalla();
                    break;
                case 5:
                    system("cls");
                    printf("EMITIENDO LISTADO DE REPARTOS\n\n");

                    mostrarRepartos(centroLogistico);

                    presionarEnterYLimpiarPantalla();
                    break;
                case 0:
                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    presionarEnterYLimpiarPantalla();
                    break;
                }
            } while(op1!=0);
            break;
        case 5:
            break;
        case 0:
            do
            {
                system("cls");
                printf("Tiene cambios sin guardar. Seguro que quiere salir?\n\n");

                printf("1. Guardar cambios y salir\n");
                printf("2. Salir sin guardar\n");
                printf("0. Volver\n\n");

                printf("Seleccione una opcion: ");
                scanf("%d",&op1);

                switch(op1)
                {
                case 1:
                    guardarTodo(centroLogistico);
                    break;
                case 2:
                    break;
                case 0:
                    MAIN_OP=1; //Cambiamos el valor para evitar que salga el programa. No pasa nada, luego se espera a que el usuario ingrese una opcion.
                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    presionarEnterYLimpiarPantalla();
                    break;
                }
            } while(op1!=0 && op1!=1 && op1!=2);
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }
    } while(MAIN_OP!=0);

    centroLogistico=destruirCentroLogistico(centroLogistico);

    return MAIN_OP;
}

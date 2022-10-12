///PASAJE DE ARCHIVOS


bool esCuilValido(CuilPtr cuil) ///NUEVA
{
    char cuilStr[100];
    strcpy(cuilStr,getCuil(cuil));
//1. Obtenemos cada numero y hacemos las multiplicaciones
    int x=((int)cuilStr[0]-48) * 5;
    int y=((int)cuilStr[1]-48) * 4;
//cuilStr[2] = " " <<< un espacio
    int n1=((int)cuilStr[3]-48) * 3;
    int n2=((int)cuilStr[4]-48) * 2;
    int n3=((int)cuilStr[5]-48) * 7;
    int n4=((int)cuilStr[6]-48) * 6;
    int n5=((int)cuilStr[7]-48) * 5;
    int n6=((int)cuilStr[8]-48) * 4;
    int n7=((int)cuilStr[9]-48) * 3;
    int n8=((int)cuilStr[10]-48) * 2;
//obtenemos el Z actual
    int z=getNVerificador(cuil);
    int zRes = 0;
    int sumatoria = x+y+n1+n2+n3+n4+n5+n6+n7+n8;
    int division = round(sumatoria / 11);
    int resto = sumatoria - (division*11);
    zRes = 11 - resto;
    int tipo=getTipo(cuil);
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

void mostrarFecha(FechaPtr fecha)
{
    printf("%d / %d / %d \n", getDia(fecha),getMes(fecha),getAnio(fecha));
    printf("%d : %d \n", getHora(fecha),getMinuto(fecha));
}

void mostrarPersona(PersonaPtr persona)
{
    printf("\tTipo: ");
    if(getEsChofer(persona))
        printf("Chofer\n");
    else
        printf("Cliente\n");
    printf("Nombre: %s\n",getNombre(persona));
    printf("Apellido: %s\n",getApellido(persona));
    printf("\tDomicilio: ");
    mostrarDomicilio(getDomicilio(persona));
    mostrarCuil(getCuilPersona(persona));
}

char* crearStringDinamico(char* literal)
{
    char* buffer=(char*)obtenerMemoria(sizeof(char)*strlen(literal)+1);
    strcpy(buffer,literal);
    return buffer;
}

void cargarDomicilio(DomicilioPtr domicilio)
{
    char calle[100];
    int altura;
    char localidad[100];

    limpiarBufferTeclado();
    printf("\n\t\tCalle: ");
    scanf("%[^\n]%*c",calle);
    limpiarBufferTeclado();
    printf("\n\t\tAltura: ");
    scanf("%d",&altura);
    limpiarBufferTeclado();
    printf("\n\t\tLocalidad: ");
    scanf("%[^\n]%*c",localidad);
    limpiarBufferTeclado();

    domicilio=crearDomicilio(calle,altura,localidad);
}

void tipoPersona(bool esChofer)
{
    if(esChofer)
    {
        printf("CHOFER");
    }
    else
    {
        printf("CLIENTE");
    }
}

void cambiarPersona(PersonaPtr personaAModificar, bool esChofer)
{
    int seguirMod=0;
    char nNombre[100];
    char nApellido[100];
    DomicilioPtr nuevoDomicilio;
    CuilPtr nuevoCuil;
    do
    {
        system("cls");
        printf("Ha elegido - ");
        ///mostrarPersona(personaAModificar);
        printf("\n\nQué desea modificar?\n\n");
        printf("1. Nombre y Apellido\n");
        printf("2. Domicilio\n");
        printf("3. CUIL\n");
        if(esChofer)
        {
            printf("4. Cambiar persona a: CLIENTE\n");
        }
        else
        {
            printf("4. Cambiar persona a: CHOFER\n");
        }
        printf("Seleccione una opcion: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("\n\nIngrese el nuevo nombre y apellido de esta manera:");
                printf("\n\t[Nombre];[Apellido]\n\t");
                scanf("%[^;]%*c;%[^\n]%*c",nNombre,nApellido);
                setNombre(personaAModificar,nNombre);
                setApellido(personaAModificar,nApellido);
            break;
            case 2:
                printf("\n\nIngrese el nuevo domicilio:");
                actualizarDomicilio(nuevoDomicilio);
                setDomicilio(personaAModificar,nuevoDomicilio);
            break;
            case 3:
                actualizarCuil(nuevoCuil);
                setCuilPersona(personaAModificar,nuevoCuil);
            break;
            case 4:
                if(esChofer)
                {
                    setEsChofer(personaAModificar,false);
                }
                else
                {
                    setEsChofer(personaAModificar,true);
                }
            break;
            default:
                printf("\nOpcion incorrecta.\n\n");
                presionarEnterYLimpiarPantalla();
            break;
        }
        printf("\n\nDatos modificados exitosamente.\n\n");
        printf("Desea seguir modificando esta persona?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&seguirMod);
    } while(seguirMod!=0);
}

void cambiarPaquete(PaquetePtr paqueteAModificar)
{
    int nAncho,nAlto,nLargo,nPeso,nEstado,seguirMod;
    DomicilioPtr nuevaDirRetiro;
    DomicilioPtr nuevaDirEntrega;
    FechaPtr nuevaFechaEntrega;
    do
    {
        system("cls");
        ///printf("Ha elegido el ");
        ///mostrarPaquete(paqueteAModificar);
        printf("\n\nQué desea modificar?\n\n");
        printf("1. Ancho\n");
        printf("2. Alto\n");
        printf("3. Largo\n");
        printf("4. Peso\n");
        printf("5. Direccion de Retiro\n");
        printf("6. Direccion de Entrega\n");
        printf("7. Fecha de Entrega\n");
        printf("8. Estado\n");
        printf("Seleccione una opcion: ");
        limpiarBufferTeclado();
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("\n\nIngrese el nuevo ancho: ");
            limpiarBufferTeclado();
            scanf("%d",&nAncho);
            setAncho(paqueteAModificar,nAncho);
            break;
        case 2:
            printf("\n\nIngrese el nuevo alto: ");
            limpiarBufferTeclado();
            scanf("%d",&nAlto);
            setAlto(paqueteAModificar,nAlto);
            break;
        case 3:
            printf("\n\nIngrese el nuevo largo: ");
            limpiarBufferTeclado();
            scanf("%d",&nLargo);
            setLargo(paqueteAModificar,nLargo);
            break;
        case 4:
            printf("\n\nIngrese el nuevo peso: ");
            limpiarBufferTeclado();
            scanf("%d",&nPeso);
            setPeso(paqueteAModificar,nPeso);
            break;
        case 5:
            printf("\n\nIngrese la nueva direccion de retiro:");
            actualizarDomicilio(nuevaDirRetiro);
            setDirRetiro(paqueteAModificar,nuevaDirRetiro);
            break;
        case 6:
            printf("\n\nIngrese la nueva direccion de entrega:");
            actualizarDomicilio(nuevaDirEntrega);
            setDirEntrega(paqueteAModificar,nuevaDirEntrega);
            break;
        case 7:
            printf("\n\nIngrese la nueva fecha y horario de entrega: ");
            actualizarFecha(nuevaFechaEntrega);
            setFechaEntrega(paqueteAModificar,nuevaFechaEntrega);
            break;
        case 8:
            helpEstadoPaquete();
            printf("\n\nIngrese el nuevo estado: ");
            limpiarBufferTeclado();
            scanf("%d",&nEstado);
            setEstado(paqueteAModificar,nEstado);
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }
        printf("\n\nDatos modificados exitosamente.\n\n");
        printf("Desea seguir modificando este paquete?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");
        printf("Seleccione una opcion: ");
        limpiarBufferTeclado();
        scanf("%d",&seguirMod);
    }while(seguirMod!=0);
}

void cambiarVehiculo(VehiculoPtr vehiculoAModificar)
{
    int nTipo=0;
    char nMarca[100];
    char nModelo[100];
    char nPatente[100];
    int seguirMod=0;
    do
    {
        system("cls");
        printf("Ha elegido - ");
        mostrarVehiculo(vehiculoAModificar);
        printf("\n\nQué desea modificar?\n\n");
        printf("1. Tipo de vehiculo\n");
        printf("2. Marca\n");
        printf("3. Modelo\n");
        printf("4. Patente\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("\n\n");
            helpTipoVehiculo();
            printf("\n\nSeleccione una opcion: ");
            scanf("%d",&nTipo);
            switch(nTipo)
            {
            case 1:
                setTipoVehiculo(vehiculoAModificar,1);
                break;
            case 2:
                setTipoVehiculo(vehiculoAModificar,2);
                break;
            case 3:
                setTipoVehiculo(vehiculoAModificar,3);
                break;
            default:
                printf("\nERROR: esa opcion no existe.\n\n");
                presionarEnterYLimpiarPantalla();
                break;
            }
            break;
        case 2:
            printf("\n\nIngrese la nueva marca:");
            scanf("%[^\n]%*c",nMarca);
            setMarca(vehiculoAModificar,nMarca);
            break;
        case 3:
            printf("\n\nIngrese el nuevo modelo:");
            scanf("%[^\n]%*c",nModelo);
            setModelo(vehiculoAModificar,nModelo);
            break;
        case 5:
            printf("\n\nIngrese la nueva patente (AA 111 AA):\n\t");
            scanf("%[^\n]%*c",nPatente);
            setPatente(vehiculoAModificar,nPatente);
            break;
        default:
            printf("\nOpcion incorrecta.\n\n");
            presionarEnterYLimpiarPantalla();
            break;
        }
        printf("\n\nDatos modificados exitosamente.\n\n");
        printf("Desea seguir modificando este vehiculo?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&seguirMod);
    } while(seguirMod!=0);
}

void cambiarAtributoReparto(RepartoPtr repartoModificar)
{
    int SubMenu;
    PersonaPtr choferModificar;
    VehiculoPtr vehiculoModificar;
    FechaPtr fechaModificar;
    PaquetePtr paqueteModificar;
    SubMenu = MenuSeleccionAtributoReparto();
    do
    {
        switch(SubMenu)
        {
            case 1:
                printf("MODIFICAR CHOFER \n");
                choferModificar = getChofer(repartoModificar);
                cambiarPersona(choferModificar, true);
            break;
            case 2:
                printf("MODIFICAR VEHICULO \n");
                vehiculoModificar = getVehiculo(repartoModificar);
                cambiarVehiculo(vehiculoModificar);
            break;
            case 3:
                printf("MODIFICAR FECHA DE SALIDA \n");
                fechaModificar = getFechaSalida(repartoModificar);
                actualizarFecha(fechaModificar);
            break;
            case 4:
                printf("MODIFICAR FECHA DE RETORNO \n");
                fechaModificar = getFechaRetorno(repartoModificar);
                actualizarFecha(fechaModificar);
            break;
            case 5:
                printf("MODIFICAR PAQUETE \n");
                ///mostrarPaquetesReparto(repartoModificar);
                printf("Seleccione un paquete ")
                cantidadPaquetesTotales = longitudPila(pilaPaquetes);
                for(int i=0;i<cantidadPaquetesTotales;i++)
                {
                    paquetes[i] = descargarPaquete(repartoModificar);
                }
                paqueteModificar = paquetes[iMod];
                cambiarPaquete(paqueteModificar);
                for(int i=cantidadPaquetesTotales;i>0;i--)
                {
                    cargarPaquete(repartoModificar,paquetes[i]);
                }
            break;
            default:
                mensajeError();
            break;
        }
        printf("\n\nDatos modificados exitosamente.\n\n");
        printf("Desea seguir modificando este vehiculo?\n\n");
        printf("\t1. SI\n\t");
        printf("0. NO\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&seguirMod);
    }while(seguirMod!=0);
}

int MenuSeleccionAtributoReparto()
{
    system("cls");
    int eleccion;
    printf("Seleccione un atributo de [ REPARTO ] para modificar \n");
    printf("1. Chofer \n");
    printf("2. Vehiculo \n");
    printf("3. Fecha de salida \n");
    printf("4. Fecha de retorno \n");
    printf("5. Paquete \n");
    printf("Opcion: ");
    limpiarBufferTeclado();
    scanf("%d", &eleccion);
    limpiarBufferTeclado();
    return eleccion;
}

bool menuEliminarPaquete(CentroLogisticoPtr centroLogistico)
{
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int indices[100];
    int cantIndices=0;
    ListaPtr listaAuxiliar = getPaquetes(centroLogistico);
    PaquetePtr paqueteRemovido=(PaquetePtr)obtenerMemoria(sizeof(Paquete));
    EleccionMenuModoAccion = menuModoAccion(0);
    mostrarPaquetes(centroLogistico);
    printf("ELIMINAR PAQUETE\n\n");
    switch(EleccionMenuModoAccion)
    {
    case 1:
        EleccionAccion = menuModoAccion1Nuevo(listaAuxiliar);
        paqueteRemovido = removerPaquete(centroLogistico, EleccionAccion);
        paqueteRemovido = destruirPaquete(paqueteRemovido);
        break;
    case 2:
        cantIndices = calcularCantidad();
        menuModoAccion2Nuevo(listaAuxiliar,cantIndices,&indices);
        for(int i=0;i<cantIndices;i++)
        {
            paqueteRemovido = removerPaquete(centroLogistico,indices[i]);
            paqueteRemovido = destruirPaquete(paqueteRemovido);
        }
        break;
    case 3:
        menuModoAccion3Nuevo(listaAuxiliar,&indices);
        for(int i=0;i<indices[1]-indices[0]+1;i++)
        {
            paqueteRemovido = removerPaquete(centroLogistico,indices[0]);
            paqueteRemovido = destruirPaquete(paqueteRemovido);
        }
        break;
    default:
        printf("Eleccion equivocada \n");
        break;
    }
}

bool menuEliminarPersona(CentroLogisticoPtr centroLogistico,bool esChofer)
{
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int cantidadCorrectas = 0;
    int indices[100];
    int cantIndices=0;
    ListaPtr listaAuxiliar = getPersonas(centroLogistico);
    PersonaPtr personaRemovida = (PersonaPtr)obtenerMemoria(sizeof(Persona));
    printf("ADVERTENCIA: La opcion 3 no funciona en este tipo de lista \n\n");
    EleccionMenuModoAccion = menuModoAccion(0);
    if(esChofer)
    {
        mostrarPersonas(centroLogistico,1);
        printf("ELIMINAR CHOFR \n\n");
    }
    else
    {
        mostrarPersonas(centroLogistico,2);
        printf("ELIMINAR CLIENTE \n\n");
    }
    printf("ELIMINAR ");
    switch(EleccionMenuModoAccion)
    {
    case 1:
        EleccionAccion = menuModoAccion1Nuevo(listaAuxiliar);
        if(getEsChofer(getDatoLista(listaAuxiliar,EleccionAccion))==esChofer)
        {
            personaRemovida = removerPersona(centroLogistico, EleccionAccion);
            personaRemovida = destruirPersona(personaRemovida);
        }
        else
        {
            printf("Indice erroneo, usted intenta eliminar un ");
            tipoPersona(esChofer);
            printf("\n\n");
        }
        break;
    case 2:
        cantIndices = calcularCantidad();
        menuModoAccion2Nuevo(listaAuxiliar,cantIndices,&indices);
        for(int i=0;i<cantIndices;i++)
        {
            if(getEsChofer(getDatoLista(listaAuxiliar,indices[i]))==esChofer)
            {
                cantidadCorrectas++;
            }
            else
            {
                printf("Indice erroneo, usted intenta eliminar un ");
                tipoPersona(esChofer);
                printf("\n\n");
            }
        }
        if(cantidadCorrectas == cantIndices)
        {
            for(int i=0;i<cantIndices;i++)
            {
                personaRemovida = removerPersona(centroLogistico,indices[i]);
                personaRemovida = destruirPersona(personaRemovida);
            }
        }
        break;
    case 3:
        ///INHABILITADA PARA PERSONAS, PROBLEMA DE LOGICA
        ///NO SE PUEDE SELECCIONAR UN CONJUNTO DE INDICES TENIENDO EN CUENTA
        ///QUE LOS CLIENTES Y LOS CHOFERES ESTAN EN UNA MISMA LISTA
        /*menuModoAccion3Nuevo(listaAuxiliar,&indices);
        for(int i=0;i<indices[1]-indices[0]+1;i++)
        {
            personaRemovida = removerPersona(centroLogistico,indices[0]);
            personaRemovida = destruirPersona(personaRemovida);
        }*/
        break;
    default:
        printf("Eleccion equivocada \n");
        break;
    }
}

bool menuEliminarVehiculo(CentroLogisticoPtr centroLogistico)
{
    int EleccionMenuModoAccion = 0;
    int EleccionAccion = 0;
    int indices[100];
    int cantIndices=0;
    ListaPtr listaAuxiliar = getVehiculos(centroLogistico);
    VehiculoPtr vehiculoRemovido = (VehiculoPtr)obtenerMemoria(sizeof(Vehiculo));
    EleccionMenuModoAccion = menuModoAccion(0);
    mostrarVehiculos(centroLogistico);
    printf("ELIMINAR VEHICULO \n\n");
    switch(EleccionMenuModoAccion)
    {
    case 1:
        EleccionAccion = menuModoAccion1Nuevo(listaAuxiliar);
        vehiculoRemovido = removerVehiculo(centroLogistico, EleccionAccion);
        vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
        break;
    case 2:
        cantIndices = calcularCantidad();
        menuModoAccion2Nuevo(listaAuxiliar,cantIndices,&indices);
        for(int i=0;i<cantIndices;i++)
        {
            vehiculoRemovido = removerPaquete(centroLogistico,indices[i]);
            vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
        }
        break;
    case 3:
        menuModoAccion3Nuevo(listaAuxiliar,&indices);
        for(int i=0;i<indices[1]-indices[0]+1;i++)
        {
            vehiculoRemovido = removerPaquete(centroLogistico,indices[0]);
            vehiculoRemovido = destruirVehiculo(vehiculoRemovido);
        }
        break;
    default:
        printf("Eleccion equivocada \n");
        break;
    }
}































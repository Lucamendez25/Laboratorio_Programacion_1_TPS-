/*
 * calculos.c
 *
 *  Created on: 13 may. 2022
 *      Author: Luca
 */

#include "calculos.h"
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////INICIAR/////////////////////////////////////////////////////
int iniciarPasajeros (ePassenger listado[], int tam)
{
    int i;
    for (i=0; i<tam; i++)
    {
        listado[i].isEmpty=0;
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////MENU/////////////////////////////////////////////////////
void menuPasajeros(ePassenger listado[] , int tam)
{
	char opcion;
	    char carga='N';
	    do
	    {
	        printf("\n         #############################################################");
	        printf("\n         *                                                           *");
	        printf("\n         *                 - Trabajo Practico Nro. 2 -               *");
	        printf("\n         *                                                           *");
	        printf("\n         *                 >>      Pasajeros      <<                 *");
	        printf("\n         *                                                           *");
	        printf("\n         *                  x     Mendez Luca	     x                 *");
	        printf("\n         *                                                           *");
	        printf("\n         #############################################################");
	        printf("\n         |                                                           |");
	        printf("\n             A - Altas");
	        printf("\n         |                                                           |");
	        printf("\n             M - Modificaciones");
	        printf("\n         |                                                           |");
	        printf("\n             B - Bajas");
	        printf("\n         |                                                           |");
	        printf("\n             I - Informes");
	        printf("\n         |                                                           |");
	        printf("\n             S - Salir");
	        printf("\n         |                                                           |");
	        printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	        printf("\n");
	        printf("\n          Ingrese una opcion: ");

	        fflush(stdin);
	        scanf("%c",&opcion);
	        opcion=toupper(opcion);
	        switch(opcion)
	        {
	        case 'A':
	            cargarLibre(listado,tam);
	            carga='S';
	            break;
	        case 'M':
	            carga='S';

	            if (carga=='S')
	            {
	                modificarValor(listado, tam);
	                break;
	            }
	            else
	            {
	                printf("No se han ingresado datos de empleados. \n ");
	                system("pause");
	                break;
	            }
	        case 'B':

	            carga='S';
	            if (carga=='S')
	            {
	                darBaja(listado, tam);
	                break;
	            }
	            else
	            {
	                printf("No se han ingresado datos de empleados. \n ");
	                system("pause");
	                break;
	            }
	        case 'I':
	        	 carga='S';
	            if (carga=='S')
	            {
	                subMenuInformes(listado, tam);
	                break;
	            }
	            else
	            {
	                printf("No se han ingresado datos de empleados. \n ");
	                system("pause");
	                break;
	            }
	        case 'S':
	            break;
	        default:
	            printf("No es una opcion valida");
	        }
	    }
	    while(opcion!='S');
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////SUBMENU/////////////////////////////////////////////////////

void subMenuInformes(ePassenger listado[], int tam)
{
    char opcion;
    do
    {
        system("cls");
        printf("\n         #############################################################");
        printf("\n         *                                                           *");
        printf("\n         *                                                           *");
        printf("\n         *                      >> Informes <<                       *");
        printf("\n         *                                                           *");
        printf("\n         *                                                           *");
        printf("\n         #############################################################");
        printf("\n         |                                                           |");
        printf("\n             		O - Ordenar por apellido");
        printf("\n         |                                                           |");
        printf("\n             		C - Costo del Vuelo");
        printf("\n         |                                                           |");
        printf("\n             	    R - Regresar");
        printf("\n         |                                                           |");
        printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        printf("\n");
        printf("\n          Ingrese una opcion: ");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion=toupper(opcion);
        switch(opcion)
        {
        case 'O':
            system("cls");
            ordenarApellidos(listado, tam);
            break;
        case 'C':
            system("cls");
            compararPrecios(listado, tam);
            break;
        case 'R':
            break;
        default:
            printf("No es una opcion valida");
        }
    }
    while(opcion!='R');
}


///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////AGREGAR/////////////////////////////////////////////////////
ePassenger agregarPasajero()
{
	ePassenger unPasajero;

	printf("Ingrese su nombre:\n");
	fflush(stdin);
	scanf("%[^\n]",unPasajero.name);

	printf("Ingrese su apellido:\n");
	fflush(stdin);
	scanf("%[^\n]",unPasajero.lastName);

	printf("Ingrese precio:\n");
	scanf("%f",&unPasajero.price);

	printf("Ingrese codigo de vuelo:\n");
	fflush(stdin);
	scanf("%s",unPasajero.flycode);

	printf("Tipo de pasajero:\n");
	scanf("%d",&unPasajero.typePassenger);

	printf("Ingrese estado de vuelo [1=Activo 2=No Activo]");
	scanf("%d",&unPasajero.statusFlight);

	unPasajero.id = cargarIDs();
	unPasajero.isEmpty=1;

	return unPasajero;
}
///////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////ID/////////////////////////////////////////////////////
int cargarIDs (void)
{
    static int IDEmpleado=5;
    IDEmpleado++;
return IDEmpleado;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////BUSCAR//////////////////////////////////////////////////////

int buscarLibre(ePassenger listado[],int tam)
{
    int index=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty==0)
        {
            index = i;
            break;
        }
    }
    return index;
}
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////CARGAR/////////////////////////////////////////////////////////
void cargarLibre (ePassenger listado[],int tam)
{
    int indice;
    char seguir='s';
    do
    {
        indice = buscarLibre(listado,tam);
        if(indice>-1)
        {
            listado[indice]=agregarPasajero();
        }
        else
        {
            printf("Todos los IDs se encuentran actualmente en uso, no es posible cargar mas datos. ");
            system("pause");
            break;
        }

        printf("Desea ingresar otro? s / n \n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    while(seguir=='s');
    correccionNombres(listado,tam);
    correccionApellidos(listado,tam);
}


///////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////CORRECCIONES///////////////////////////////////////////

void correccionNombres(ePassenger listado[], int tam)
{
    int i;
    int j;
    for(i=0; i<tam; i++)
    {
        strlwr(listado[i].name);
    }
    for(i=0; i<tam; i++)
    {
        listado[i].name[0]=toupper(listado[i].name[0]);
        for(j=0; j<strlen(listado[i].name); j++)
        {
            if(listado[i].name[j]==' ')
            {
                listado[i].name[j+1]=toupper(listado[i].name[j+1]);
            }
        }
    }
}
void correccionApellidos(ePassenger listado[], int tam)
{
    int i;
    int j;
    for(i=0; i<tam; i++)
    {
        strlwr(listado[i].lastName);
    }
    for(i=0; i<tam; i++)
    {
        listado[i].lastName[0]=toupper(listado[i].lastName[0]);
        for(j=0; j<strlen(listado[i].lastName); j++)
        {
            if(listado[i].lastName[j]==' ')
            {
                listado[i].lastName[j+1]=toupper(listado[i].lastName[j+1]);
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////MOSTRAR/////////////////////////////////////////////////////
void mostrarPasajeros(ePassenger listado[], int tam)
{


    int i;
    printf("Lista: \n");
    for (i=0; i<tam; i++)
    {
        if(listado[i].isEmpty==1)
        {
        	mostrarPasajero(listado[i]);
        }
    }
    system("pause");
}
void mostrarPasajero(ePassenger unPasajero)
{
    if(unPasajero.isEmpty==1)
    {
		printf( "ID: %d\n"
				"Nombre: %s\n"
				"Apellido: %s\n"
				"Precio:%.2f\n"
				"Codigo de Vuelo: %s\n"
				"Tipo de pasajero: %d\n"
				"Estado de vuelo: %d\n\n",
				unPasajero.id, unPasajero.name, unPasajero.lastName, unPasajero.price,
				unPasajero.flycode, unPasajero.typePassenger, unPasajero.statusFlight);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////MODIFICAR/////////////////////////////////////////

void modificarValor (ePassenger listado[], int tam)
{
    mostrarPasajeros(listado,tam);
    int idaux;
    int i;
    char posicion;
    char validar;
    char numero[10];
    int n;
    printf("ingrese el ID a buscar: ");
    scanf("%d", &idaux);
    for (i=0; i<tam; i++)
    {
        if(idaux == listado[i].id)
        {
            mostrarPasajero(listado[i]);
            printf("¿Desea modificar alguno de los parametros?  \n  s / n ");
            fflush(stdin);
            scanf("%c",&validar);
            validar=tolower(validar);

            if(validar=='s')
            {
                printf("¿Que parametro desea modificar?  \n  1 - Nombre \n 2 - Apellido \n 3 - Salario \n 4 - Codigo de vuelo \n ");
                fflush(stdin);
                scanf("%c",&posicion);
                switch(posicion)
                {
                case '1':
                    fflush(stdin);
                    printf("Ingrese el nombre: ");
                    gets(listado[i].name);
                    validarNombre(listado[i]);
                    correccionNombres(listado,tam);

                    system("pause");
                    break;
                case '2':
                    fflush(stdin);
                    printf("Ingrese el apellido: ");
                    gets(listado[i].lastName);
                    validarApellido(listado[i]);
                    correccionApellidos(listado,tam);
                    system("pause");
                    break;
                case '3':
                    fflush(stdin);
                    printf("Ingrese el salario: ");
                    scanf("%f",&listado[i].price);
                    fflush(stdin);
                    system("pause");
                    break;
                case '4':
                    do
                    {
                        fflush(stdin);
                        printf("Ingrese el codigo de vuelo: ");
                        scanf("%s",numero);
                        fflush(stdin);
                        n=validarNumero(numero);
                    }
                    while(n==0);

                    system("pause");
                    break;
                default:
                    printf("No existe esa opción. \n");
                    break;
                }
            }
            else
            {
                break;
            }

        }
    }
    correccionNombres(listado,tam);
    correccionApellidos(listado,tam);
}

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////BAJA/////////////////////////////////////////////////
void darBaja (ePassenger listado[], int tam)
{
    mostrarPasajeros(listado, tam);
    int idaux;
    int i;
    char validar;
    int flag=0;
    printf("ingrese el ID a dar de baja: ");
    scanf("%d", &idaux);
    for (i=0; i<tam; i++)
    {
        if(listado[i].isEmpty==1 && idaux == listado[i].id)
        {
            mostrarPasajero(listado[i]);
            printf("¿Desea dar de baja este empleado?  \n  s / n ");
            fflush(stdin);
            scanf("%c",&validar);
            validar=tolower(validar);
            if(validar=='s')
            {
                flag=1;
                listado[i].isEmpty=-1;
                printf("Se bajo correctamente\n\n");
            }
        }
    }
    if(flag==0)
    {
        printf("No se encontro el ID");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////VALIDACIONES/////////////////////////////////////////////////////

void validarNombre (ePassenger pasajero)
{
    int i;
    for (i=0; i<strlen(pasajero.name); i++)
    {
        if (pasajero.name[i]==' ')
        {
            break;
        }
        while (!(isalpha(pasajero.name[i])))
        {
            printf("Reingrese un nombre valido \n");
            gets(pasajero.name);
            fflush(stdin);
        }
    }
}


void validarApellido (ePassenger pasajero)
{
    int i;
    for (i=0; i<strlen(pasajero.name); i++)
    {
        if (pasajero.lastName[i]==' ')
        {
            break;
        }
        while (!(isalpha(pasajero.lastName[i])))
        {
            printf("Reingrese un apellido valido \n");
            gets(pasajero.lastName);
            fflush(stdin);
        }
    }
}



int validarNumero (char valores[])
{
    int i;
    for(i=0; i<strlen(valores); i++)
    {
        if(!(isdigit(valores[i])))
        {
            printf("Reingrese un valor valido \n");
            getchar();
            return 0;
        }
    }
    return 1;
}


void harcodearPasajeros(ePassenger listado[],int tam)
 {

	int id[5]={1,2,3,4,5};
	char nombre[5][51]={"Luca","Alex","Fabio","Martin","Pamela"};
	char apellido[5][51]={"Mendez","Lukasch","Toro","Arenas","Arenas"};
	int precio[5] = {1000,2999,3999,4289,529};
	char codigoVuelo[5][10]={"2HGDFD","9ASQW","99LLFD","DSDS44","KKKJL52"};
	int tipoPasajero[5]={1,1,2,3,3};
	int vueloEstado[5]={1,1,1,2,2};
	int estado[5]={1,1,1,1,1};

	int i;

	for(i=0;i<5;i++)
	{
	 listado[i].id = id[i];
	 strcpy(listado[i].name, nombre[i]);
	 strcpy(listado[i].lastName, apellido[i]);
	 listado[i].price=precio[i];
	 strcpy(listado[i].flycode, codigoVuelo[i]);
	 listado[i].typePassenger=tipoPasajero[i];
	 listado[i].statusFlight=vueloEstado[i];
	 listado[i].isEmpty=estado[i];


	}

 }


void ordenarApellidos(ePassenger listado[],int tam)
{
	int i;
	    int j;
	    ePassenger auxEmpleado;
	    printf("\n Valores ordenados alfabeticamente: \n");
	    printf("%5s\t %5s\t %5s\t %5s\t %5s\t","ID","Nombre","Apellido","Salario", "Sector \n");
	    for (i=0; i<tam-1; i++)
	    {
	        for(j=i+1; j<tam; j++)
	        {
	            if (strcmp(listado[i].lastName, listado[j].lastName)==0)
	            {
	                if(listado[i].statusFlight>listado[j].statusFlight)
	                {
	                    auxEmpleado=listado[i];
	                    listado[i]=listado[j];
	                    listado[j]=auxEmpleado;
	                }
	            }
	            else if (strcmp(listado[i].lastName, listado[j].lastName)>0)
	            {
	                auxEmpleado=listado[i];
	                listado[i]=listado[j];
	                listado[j]=auxEmpleado;
	            }
	        }
	    }
	    for (i=0; i<tam; i++)
	    {
	        mostrarPasajero(listado[i]);
	    }
	    system("pause");
}



float calcularPromedio(ePassenger listado [], int tam)
{
    int i;
    int contPrecioPasajes=0;
    float sumaPrecioPasajes=0;
    float promedioPasajes;
    for (i=0; i<tam; i++)
    {
        if(listado[i].isEmpty==1)
        {
        	sumaPrecioPasajes=sumaPrecioPasajes+listado[i].price;
            contPrecioPasajes++;
        }
    }
    promedioPasajes=sumaPrecioPasajes/contPrecioPasajes;
    printf("La suma de los precios de los pasajes es de: %f \n el promedio total seria: %f \n", sumaPrecioPasajes, promedioPasajes);
    return promedioPasajes;
}

void compararPrecios (ePassenger listado[], int tam)
{
    int i;
    int contPasajePrecioPromedio=0;
    float promedio;
    promedio=calcularPromedio(listado,tam);
    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty==1 && listado[i].price>promedio)
        {
            mostrarPasajero(listado[i]);
            contPasajePrecioPromedio++;
        }
    }
    printf("La cantidad de pasajeros que superan el precio promedio es de: %d \n ", contPasajePrecioPromedio);

    system("pause");
}



#include "Empleado.h"
#define LIBRE 0
#define OCUPADO 1


void cargarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    int j;
    int valor;
    int indice;
    float valorHoraSector;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &valor);

        indice=buscarLibrePorValor(lista, tam, valor);

        if(indice!=-1)
        {
            lista[i].legajo=valor;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(lista[i].nombre);
            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &lista[i].sexo);

            //en funcion
            for(j=0; j<ts; j++)
            {
                printf("%d\t %s\n",sectores[j].idSector, sectores[j].descripcion);
            }
            printf("Elija sector:\n");
            scanf("%d", &lista[i].idSector);


            printf("Ingrese cantidad de horas: ");
            scanf("%d", &lista[i].cantidadHoras);

            for(j=0; j<ts; j++)
            {
                if(lista[i].idSector == sectores[j].idSector)
                {
                    valorHoraSector=sectores[j].valor;
                }
            }

            lista[i].sueldoBruto=valorHoraSector*lista[i].cantidadHoras;

            lista[i].sueldoNeto =lista[i].sueldoBruto*0.85;

            lista[i].estado = OCUPADO;
        }
        else
        {
            printf("El legajo esta OCUPADO\n");
        }
    }
    else
    {
        printf("No hay espacio\n");
    }
}

//_______________________________________________________________________
void mostrarListaEmpleados(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarEmpleado(lista[i], sectores, ts);
        }

    }
}

//_______________________________________________________________________
void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int ts)
{
    char descripcionSector[20];
    int i;

    for(i=0; i<ts; i++)
    {
        if(unEmpleado.idSector==sectores[i].idSector)
        {
            strcpy(descripcionSector, sectores[i].descripcion);
            break;
        }
    }
    printf("%d\t%s\t\t%c\t%.2f\t\t%.2f\t\t%s\n", unEmpleado.legajo,unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto,unEmpleado.sueldoNeto,descripcionSector);

}

//_______________________________________________________________________
int buscarLibre(eEmpleado lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            return index;
        }
    }
    return index;
}


//_______________________________________________________________________
int buscarLibrePorValor(eEmpleado lista[], int tam, int valor)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].legajo==valor && lista[i].estado==OCUPADO)
        {
            return index;
        }
    }
    index=i;
    return index;
}


//_______________________________________________________________________
void inicializarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
        lista[i].legajo = -2;
    }
}

//_______________________________________________________________________
void hardcodearDatosEmpleados(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    int j;
    float valorHoraSector;
    int legajos[]= {1,8,9,7,2,4};
    char nombres[][50]= {"Carlos","Maria","Carlos","Pedro","Carlos","Mateo"};
    char sexo[]= {'M','F','M','M','M','M'};
    int sector[]= {1,2,3,1,2,2};
    int horas[]= {10, 12, 13, 10, 13, 11};




    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].idSector = sector[i];
        for(j=0; j<ts; j++)
        {
            if(lista[i].idSector == sectores[j].idSector)
            {
                valorHoraSector=sectores[j].valor;
            }
        }
        lista[i].sueldoBruto=valorHoraSector*horas[i];
        lista[i].sueldoNeto = lista[i].sueldoBruto * 0.85;
        lista[i].estado = OCUPADO;


    }
}

//_______________________________________________________________________
int pedirEntero(char texto[])

{
    int numero;

    printf(texto);
    scanf("%d",&numero);
    return numero;
}


//_______________________________________________________________________
char pedirChar(char texto[])
{
    char caracter;

    printf(texto);
    fflush(stdin);
    scanf("%c",&caracter);
    return caracter;
}


//_______________________________________________________________________
void modificarEmpleado(eEmpleado lista[], int tam, int legajo, eSector sectores[], int ts)
{
    int i;
    int j;
    int flag=0;
    int opcion;
    float valor;

    legajo=pedirEntero("Ingrese el legajo del empleado a modificar: ");

    for(i=0; i<tam; i++)
    {
        if (legajo==lista[i].legajo && lista[i].estado==OCUPADO)
        {
            mostrarEmpleado(lista[i], sectores, ts);
            opcion=menuDeOpciones("Escoja el campo a modificar:\n1.Nombre\n2.Sexo\n3.Cantidad de horas\n4.Sector\n5.Salir\nElija una opcion: ");
            switch(opcion)
            {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                gets(lista[i].nombre);
                flag=1;
                break;
            case 2:
                printf("Ingrese el nuevo sexo: ");
                fflush(stdin);
                scanf("%c", &lista[i].sexo);
                flag=1;
                break;
            case 3:
                printf("Ingrese la nueva cantidad de horas: ");
                scanf("%d", &lista[i].cantidadHoras);
                for(j=0; j<ts; j++)
                {
                    if(lista[i].idSector == sectores[j].idSector)
                    {
                        valor=sectores[j].valor;
                    }
                }

                lista[i].sueldoBruto=valor*lista[i].cantidadHoras;
                lista[i].sueldoNeto = lista[i].sueldoBruto * 0.85;
                flag=1;
                break;
            case 4:
                for(j=0; j<ts; j++)
                {
                    printf("%d\t %s\n",sectores[j].idSector, sectores[j].descripcion);
                }
                printf("Ingrese el nuevo sector: ");
                scanf("%d", &lista[i].idSector);
                flag=1;
                break;
            case 5:
                flag=1;
                break;
            }

        }
    }
    if(flag==0)
    {
        printf("No ingreso un legajo valido\n");
    }
}


//_______________________________________________________________________
void bajarEmpleado(eEmpleado lista[], int tam, int legajo, eSector sectores[], int ts)
{
    int i;
    int flag=0;

    legajo=pedirEntero("Ingrese el legajo del empleado a dar de baja: ");

    for(i=0; i<tam; i++)
    {
        if (legajo==lista[i].legajo)
        {
            printf("Se ha dado de baja al siguiente empleado:\n");
            mostrarEmpleado(lista[i], sectores, ts);
            lista[i].estado = LIBRE;
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No ingreso un legajo valido\n");
    }
}


//_______________________________________________________________________
int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


//_______________________________________________________________________
float importeMaximo(eEmpleado lista[], int tam)
{
    int i;
    float sueldo=0;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(lista[i].sueldoBruto>sueldo || flag==0)
            {
                sueldo=lista[i].sueldoBruto;
                flag=1;
            }
        }
    }

    return sueldo;
}


//_______________________________________________________________________
void mostrarSueldoMaximo(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    float sueldo;
    int i;

    sueldo=importeMaximo(lista, tam);

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(sueldo==lista[i].sueldoBruto)
            {
                mostrarEmpleado(lista[i], sectores, ts);
            }
        }
    }

}


//_______________________________________________________________________
int contarCarlos(eEmpleado lista[], int tam)
{
    int contadorCarlos = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(stricmp(lista[i].nombre,"Carlos")==0 && lista[i].sueldoBruto>1500)
            {
                contadorCarlos++;
            }
        }
    }

    return contadorCarlos;
}

//_______________________________________________________________________
void mostrarSector(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    int j;


    for(i=0; i<ts; i++)
    {
        printf("Lista de empleados de %s\n",sectores[i].descripcion);
        for(j=0; j<tam; j++)
        {
            if(sectores[i].idSector==lista[j].idSector && lista[j].estado==OCUPADO)
            {
                mostrarEmpleado(lista[j],sectores, ts);
            }
        }
    }


}

//_______________________________________________________________________
void calcularSueldosSector(eEmpleado lista[],int tam, eSector sectores[], int ts)
{
    eAuxiliar auxiliar[ts];
    int i;
    int j;

    for(i=0; i<ts; i++)
    {
        auxiliar[i].idSector=sectores[i].idSector;
        strcpy(auxiliar[i].descripcion,sectores[i].descripcion);
        auxiliar[i].sueldos=0;
    }

    for(i=0; i<ts; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(auxiliar[i].idSector==lista[j].idSector && lista[j].estado==OCUPADO)
            {
                auxiliar[i].sueldos+=lista[j].sueldoNeto;
            }
        }
    }

    for(i=0; i<ts; i++)
    {
        printf("Sector: %s\t\t%.2f\n",auxiliar[i].descripcion,auxiliar[i].sueldos);
    }
}


//_______________________________________________________________________
void mostrarSectorConMasEmpleados(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    eAuxiliar auxiliar[ts];
    int i;
    int j;
    int maximo;
    int flag=0;

    for(i=0; i<ts; i++)
    {
        auxiliar[i].idSector=sectores[i].idSector;
        strcpy(auxiliar[i].descripcion,sectores[i].descripcion);
        auxiliar[i].cantidadEmpleados=0;
    }

    for(i=0; i<ts; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(auxiliar[i].idSector==lista[j].idSector && lista[j].estado==OCUPADO)
            {
                auxiliar[i].cantidadEmpleados++;
            }
        }
    }

    for(i=0; i<ts; i++)
    {
        if(flag==0 || auxiliar[i].cantidadEmpleados>maximo)
        {
            maximo=auxiliar[i].cantidadEmpleados;
            flag=1;
        }
    }

    for(i=0; i<ts; i++)
    {
        if(auxiliar[i].cantidadEmpleados==maximo)
        {
            printf("Sector: %s\t%d\n",sectores[i].descripcion,auxiliar[i].cantidadEmpleados);
        }
    }
}

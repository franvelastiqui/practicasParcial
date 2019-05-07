#include "funciones.h"

#define LIBRE 0
#define ACTIVA 1
#define PAUSADA 2

int pedirInt(char mensaje[])
{
    int entero;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d",&entero);

    return entero;
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

float pedirFloat(char mensaje[])
{
    float flotante;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f",&flotante);

    return flotante;
}

//_______________________________________________________________________

long pedirLong(char mensaje[])
{
    long largo;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%ld",&largo);

    return largo;
}

//_______________________________________________________________________

void inicializar(eClientes listado[],int tc,ePublicaciones publicaciones[],int tp)
{
    int i;
    int j;

    for(i=0; i<tc; i++)
    {
        listado[i].estado= LIBRE;
        listado[i].id= 0;
    }

    for(j=0; j<tp; j++)
    {
        publicaciones[j].estado=LIBRE;
    }
}

//_______________________________________________________________________

int buscarLibre(eClientes listado[],int tc)
{
    int i;

    for(i=0; i<tc; i++)
    {
        if(listado[i].estado == LIBRE)
        {
            return i;
        }
    }

    return -1;
}

//_______________________________________________________________________

int buscarPublicacionLibre(ePublicaciones publicaciones[], int tp)
{
    int i;

    for(i=0; i<tp; i++)
    {
        if(publicaciones[i].estado == LIBRE)
        {
            return i;
        }
    }

    return -1;
}

//_______________________________________________________________________

int buscarPorId(eClientes listado[],int tc)
{
    int i;
    int id;

    id=pedirInt("Ingrese el id del cliente: ");

    for(i=0; i<tc; i++)
    {
        if(listado[i].id==id && listado[i].estado == ACTIVA)
        {
            return id;
        }
    }

    return -1;
}

//_______________________________________________________________________

int buscarPublicacionPorId(ePublicaciones publicaciones[],int tp)
{
    int i;
    int id;

    id=pedirInt("Ingrese el id de la publicacion: ");

    for(i=0; i<tp; i++)
    {
        if(publicaciones[i].idAviso==id && publicaciones[i].estado == ACTIVA)
        {
            return id;
        }
    }

    return -1;
}

//_______________________________________________________________________

void agregarCliente(eClientes listado[],int tc)
{
    int i;

    i=buscarLibre(listado,tc);

    if(i!=-1)
    {
        listado[i].id=i+1;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(listado[i].nombre);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(listado[i].apellido);

        printf("Ingrese cuit: ");
        scanf("%ld", &listado[i].cuit);

        listado[i].estado=ACTIVA;
    }
    else
    {
        printf("No hay lugar disponible\n");
    }
}

//_______________________________________________________________________

void mostrarCliente(eClientes unCliente)
{
    printf("%d\t\t%s\t\t%s\t\t%ld\t\t%d\n", unCliente.id, unCliente.nombre, unCliente.apellido, unCliente.cuit, unCliente.cantidad);
}

//_______________________________________________________________________

void modificarCliente(eClientes listado[],int tc)
{
    int i;
    int id;
    int opcion;
    char confirmacion;
    int flag=0;
    eClientes auxiliar;

    id=pedirInt("Ingrese el id del cliente a modificar: ");

    for(i=0; i<tc; i++)
    {
        if(listado[i].id==id && listado[i].estado==ACTIVA)
        {
            printf("Se modificara al siguente cliente:\n");
            mostrarCliente(listado[i]);

            opcion=pedirInt("1.Nombre\n2.Apellido\n3.Cuit\n4.Salir\nElija una opcion: ");

            switch(opcion)
            {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                gets(auxiliar.nombre);
                confirmacion=pedirChar("Ingrese s para confirmar la operacion u otra tecla para salir\n");
                if(confirmacion=='s')
                {
                    strcpy(listado[i].nombre, auxiliar.nombre);
                }
                flag=1;
                break;
            case 2:
                printf("Ingrese el nuevo apellido: ");
                fflush(stdin);
                gets(auxiliar.apellido);
                confirmacion=pedirChar("Ingrese s para confirmar la operacion u otra tecla para salir\n");
                if(confirmacion=='s')
                {
                    strcpy(listado[i].apellido, auxiliar.apellido);
                }
                flag=1;
                break;
            case 3:
                printf("Ingrese el nuevo cuit: ");
                scanf("%ld",&auxiliar.cuit);
                confirmacion=pedirChar("Ingrese s para confirmar la operacion u otra tecla para salir\n");
                if(confirmacion=='s')
                {
                    listado[i].cuit=auxiliar.cuit;
                }
                flag=1;
                break;
            case 4:
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

void bajarCliente(eClientes listado[],int tc)
{
    int i;
    int id;
    char confirmacion;
    int flag=0;

    id=pedirInt("Ingrese el id del cliente a dar de baja");

    for(i=0; i<tc; i++)
    {
        if(listado[i].id==id && listado[i].estado==ACTIVA)
        {
            printf("Se dara de baja al siguiente cliente:\n");
            mostrarCliente(listado[i]);

            confirmacion=pedirChar("Ingrese s para confirmar la operacion u otra tecla para salir\n");
            if(confirmacion=='s')
            {
                listado[i].estado=LIBRE;
            }
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("No ingreso un legajo valido\n");
    }
}

//_______________________________________________________________________

void crearPublicacion(eClientes listado[], int tc, ePublicaciones publicaciones[], int tp)
{
    int i;
    int j;
    int id;

    id=buscarPorId(listado,tc);

    if(id!=-1)
    {

        j=buscarPublicacionLibre(publicaciones,tp);

        if(j!=-1)
        {
            publicaciones[j].idCliente=id;

            publicaciones[j].idAviso=j+1;

            publicaciones[j].numeroRubro=pedirInt("Ingrese el numero de rubro: ");

            printf("Redacte el aviso:\n");
            fflush(stdin);
            gets(publicaciones[j].textoAviso);

            printf("El id de este aviso es %d\n", publicaciones[j].idAviso);

            publicaciones[j].estado=ACTIVA;

            for(i=0;i<tc;i++)
            {
                if(listado[i].id==publicaciones[j].idCliente)
                {
                    listado[i].cantidad++;
                }
            }
        }
    }
    else
    {
        printf("No ingreso un legajo valido\n");
    }
}

//_______________________________________________________________________

void pausarPublicacion(eClientes listado[],int tc,ePublicaciones publicaciones[],int tp)
{
    int i;
    int id;
    int j;
    char confirmacion;

    id=buscarPublicacionPorId(publicaciones,tp);

    if(id!=-1)
    {
        for(j=0;j<tp;j++)
        {
            if(publicaciones[j].idAviso==id && publicaciones[j].estado==ACTIVA)
            {
                for(i=0;i<tc;i++)
                {
                    if(listado[i].id == publicaciones[j].idCliente)
                    {
                        mostrarCliente(listado[i]);
                        confirmacion=pedirChar("Ingrese s para confirmar la operacion u otra tecla para salir\n");

                        if(confirmacion=='s')
                        {
                            publicaciones[j].estado=PAUSADA;
                            listado[i].cantidad--;
                        }
                    }
                }
            }
        }
    }
}

//_______________________________________________________________________

void reanudarPublicacion(eClientes listado[],int tc,ePublicaciones publicaciones[],int tp)
{
    int i;
    int id;
    int j;
    char confirmacion;

    id=buscarPublicacionPorId(publicaciones,tp);

    if(id!=-1)
    {
        for(j=0;j<tp;j++)
        {
            if(publicaciones[j].idAviso==id && publicaciones[j].estado==PAUSADA)
            {
                for(i=0;i<tc;i++)
                {
                    if(listado[i].id == publicaciones[j].idCliente)
                    {
                        mostrarCliente(listado[i]);
                        confirmacion=pedirChar("Ingrese s para confirmar la operacion u otra tecla para salir\n");

                        if(confirmacion=='s')
                        {
                            publicaciones[j].estado=ACTIVA;
                            listado[i].cantidad++;
                        }
                    }
                }
            }
        }
    }
}

//_______________________________________________________________________

void mostrarListaClientes(eClientes listado[],int tc)
{
    int i;

    for(i=0;i<tc;i++)
    {
        if(listado[i].estado!=LIBRE)
        {
           mostrarCliente(listado[i]);
        }
    }
}

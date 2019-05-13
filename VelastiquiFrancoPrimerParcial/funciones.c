#include "funciones.h"

#define LIBRE 0
#define OCUPADO 1

void inicializarPeliculasyActores(ePeliculas peliculas[],int tp,eActores actores[],int ta)
{
    int i;

    for(i=0; i<tp; i++)
    {
        peliculas[i].estado= LIBRE;
    }

    for(i=0; i<ta; i++)
    {
        actores[i].estadoActor= LIBRE;
    }
}

//_____________________________________________________

int buscarLibre(ePeliculas peliculas[],int tp)
{
    int i;

    for(i=0; i<tp; i++)
    {
        if(peliculas[i].estado == LIBRE)
        {
            return i;
        }
    }

    return -1;
}

//_____________________________________________________

void agregarPelicula(ePeliculas peliculas[],int tp,eGeneros generos[],int tg,eActores actores[],int ta,eFechas fechas[])
{
    int i;
    int j;
    int flag=0;

    i=buscarLibre(peliculas,tp);

    if(i!=-1)
    {
        peliculas[i].idPelicula=i+1000;

        printf("Ingrese titulo: ");
        fflush(stdin);
        gets(peliculas[i].titulo);

        peliculas[i].idFecha=i;

        fechas[i].idFecha = i;

        fechas[i].anio=validarDato("Ingrese el año de estreno: ", 1900, 2019);

        fechas[i].mes=validarDato("Ingrese el mes de estreno: ", 1, 12);
        if(fechas[i].mes==2)
        {
            if(fechas[i].anio%100==0)
            {
                if(fechas[i].anio%400==0)
                {
                    fechas[i].dia=validarDato("Ingrese el dia de estreno: ", 1, 29);
                    flag=1;
                }
            }
            else
            {
                if(fechas[i].anio%4==0)
                {
                    fechas[i].dia=validarDato("Ingrese el dia de estreno: ", 1, 29);
                    flag=1;
                }
            }
            if(flag==0)
            {
                fechas[i].dia=validarDato("Ingrese el dia de estreno: ", 1, 28);
            }
        }
        else if(fechas[i].mes==4 || fechas[i].mes==6 || fechas[i].mes==9 || fechas[i].mes==11)
        {
            fechas[i].dia=validarDato("Ingrese el dia de estreno: ", 1, 30);
        }
        else
        {
            fechas[i].dia=validarDato("Ingrese el dia de estreno: ", 1, 31);
        }

        for(j=0; j<tg; j++)
        {
            printf("%d\t %s\n",generos[j].idGenero, generos[j].genero);
        }

        peliculas[i].idGenero=validarDato("Elija genero: ",1,5);

        for(j=0; j<ta; j++)
        {
            if(actores[j].estadoActor!=LIBRE)
            {
                printf("%d\t\t%s\t\t%s\n",actores[j].idActor, actores[j].nombre, actores[j].paisOrigen);
            }
        }
        peliculas[i].idActor=validarDato("Elija genero: ",1,10);

        peliculas[i].estado=OCUPADO;
    }
    else
    {
        printf("No hay lugar disponible\n");
    }
}

//_____________________________________________________

void hardcodearDatos(ePeliculas peliculas[],int tp,eFechas fechas[],eActores actores[],int ta)
{
    int i;
    int idPeliculas[]= {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,1019,1020};
    char titulos[][31]= {"Avengers EndGame","Thor","Cellular","Men in Black 4","IronMan","13 Going on 32","Lucy","Nace una estrella","¿Dime con cuantos?","Guardianes de la galaxia","A perfect murder","La isla Que paso ayer","Home Alone 3","Deadpool","Sherlock Holmes","Men in Black 3","Avengers infinity war","Grandes esperanzas","SWAT","XxX"};
    int idGenero[]= {1,1,1,1,1,4,1,4,4,1,3,3,2,2,1,1,1,1,4,1,1};
    int idActor[]= {2,5,4,5,2,3,1,9,4,9,7,1,9,1,10,2,10,10,7,6,6};
    int dia[]= {20,10,2,10,5,7,9,8,4,20,6,3,5,6,7,5,2,6,8,20,11};
    int mes[]= {4,6,5,7,9,5,2,3,4,5,8,10,2,10,12,6,5,4,12,2,5};
    int anio[]= {2019,2013,2004,2019,2012,2004,2014,2018,2010,2014,1995,2005,2013,1997,2015,2011,2010,2017,1995,1998,1992};
    int idFechas[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    for(i=0; i<tp; i++)
    {
        peliculas[i].idPelicula = idPeliculas[i];
        strcpy(peliculas[i].titulo, titulos[i]);
        peliculas[i].idGenero = idGenero[i];
        peliculas[i].idActor = idActor[i];
        fechas[i].dia=dia[i];
        fechas[i].mes = mes[i];
        fechas[i].anio = anio[i];
        peliculas[i].idFecha = idFechas[i];
        fechas[i].idFecha = idFechas[i];
        peliculas[i].estado = OCUPADO;

    }

    for(i=0; i<ta; i++)
    {
        actores[i].estadoActor=OCUPADO;
    }

}

//_____________________________________________________

int pedirInt(char mensaje[])
{
    int entero;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d",&entero);

    return entero;
}

//_____________________________________________________

int validarDato(char mensaje[], int minimo, int maximo)
{
    int numero;

    printf(mensaje);
    scanf("%d",&numero);
    while(numero>maximo || numero<minimo)
    {
        printf("Error. Por favor, reingrese: ");
        scanf("%d",&numero);
    }
    return numero;
}

//_____________________________________________________

char pedirChar(char texto[])
{
    char caracter;
    printf(texto);
    fflush(stdin);
    scanf("%c",&caracter);

    return caracter;
}

//_____________________________________________________

void modificarPelicula(ePeliculas peliculas[],int tp,eActores actores[],int ta,eFechas fechas[],eGeneros generos[], int tg)
{
    int i;
    int j;
    int flag=0;
    int flagFecha=0;
    int opcion;
    int idP;
    char confirmacion;
    ePeliculas auxiliar;
    eFechas auxiliarF;

    idP=pedirInt("Ingrese el id de la pelicula a modificar: ");

    for(i=0; i<tp; i++)
    {
        if (idP==peliculas[i].idPelicula && peliculas[i].estado==OCUPADO)
        {
            printf("Se modificara la siguiente pelicula:\n");
            mostrarPelicula(peliculas[i],fechas[i],generos, tg, actores,ta);
            opcion=pedirInt("Escoja el campo a modificar:\n1.Titulo\n2.Actor\n3.Fecha de estreno\n4.Salir\nElija una opcion: ");
            switch(opcion)
            {
            case 1:
                printf("Ingrese el nuevo titulo: ");
                fflush(stdin);
                gets(auxiliar.titulo);
                confirmacion=pedirChar("Ingrese s para confirmar la operacion u otra tecla para salir: ");
                if(confirmacion=='s')
                {
                    strcpy(peliculas[i].titulo, auxiliar.titulo);
                }
                flag=1;
                break;
            case 2:
                for(j=0; j<ta; j++)
                {
                    if(actores[j].estadoActor!=LIBRE)
                    {
                        printf("%d\t\t%s\t\t%s\n",actores[j].idActor, actores[j].nombre, actores[j].paisOrigen);
                    }
                }
                peliculas[i].idActor=validarDato("Elija actor: ",1,10);
                confirmacion=pedirChar("Ingrese s para confirmar la operacion u otra tecla para salir: ");
                if(confirmacion=='s')
                {
                    peliculas[i].idActor= auxiliar.idActor;
                }
                flag=1;
                break;
            case 3:
                auxiliar.idFecha=i;

                auxiliarF.idFecha = i;


                auxiliarF.anio=validarDato("Ingrese el año de estreno: ", 1900, 2019);

                auxiliarF.mes=validarDato("Ingrese el mes de estreno: ", 1, 12);
                if(auxiliarF.mes==2)
                {
                    if(auxiliarF.anio%100==0)
                    {
                        if(auxiliarF.anio%400==0)
                        {
                            auxiliarF.dia=validarDato("Ingrese el dia de estreno: ", 1, 29);
                            flagFecha=1;
                        }
                    }
                    else
                    {
                        if(auxiliarF.anio%4==0)
                        {
                            auxiliarF.dia=validarDato("Ingrese el dia de estreno: ", 1, 29);
                            flagFecha=1;
                        }
                    }
                    if(flagFecha==0)
                    {
                        auxiliarF.dia=validarDato("Ingrese el dia de estreno: ", 1, 28);
                    }
                }
                else if(auxiliarF.mes==4 || auxiliarF.mes==6 || auxiliarF.mes==9 || auxiliarF.mes==11)
                {
                    auxiliarF.dia=validarDato("Ingrese el dia de estreno: ", 1, 30);
                }
                else
                {
                    auxiliarF.dia=validarDato("Ingrese el dia de estreno: ", 1, 31);
                }


                confirmacion=pedirChar("Ingrese s para confirmar la operacion u otra tecla para salir: ");
                if(confirmacion=='s')
                {
                    peliculas[i].idFecha=auxiliar.idFecha;

                    fechas[i].idFecha =auxiliarF.idFecha;

                    fechas[i].dia=auxiliarF.dia;
                    fechas[i].mes=auxiliarF.mes;
                    fechas[i].anio=auxiliarF.anio;
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
        printf("No ingreso un id valido\n");
    }
}

//_____________________________________________________

void bajarPelicula(ePeliculas peliculas[], int tp, eActores actores[], int ta, eFechas fechas[], eGeneros generos[],int tg)
{
    int i;
    int idP;
    int flag=0;
    char confirmacion;

    idP=pedirInt("Ingrese el id de la pelicula a dar de baja: ");

    for(i=0; i<tp; i++)
    {
        if (idP==peliculas[i].idPelicula)
        {
            printf("Se dara de baja la siguiente pelicula:\n");
            mostrarPelicula(peliculas[i],fechas[i],generos, tg, actores,ta);

            confirmacion=pedirChar("Ingrese s para confirmar la operacion u otra tecla para salir: ");
            if(confirmacion=='s')
            {
                peliculas[i].estado=LIBRE;
            }
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("No ingreso un id valido\n");
    }
}

//_____________________________________________________

void mostrarPelicula(ePeliculas unaPelicula, eFechas Fecha, eGeneros generos[], int tg, eActores actores[], int ta)
{
    int i;
    char genero[21];
    char actor[31];

    for(i=0; i<tg; i++)
    {
        if(unaPelicula.idGenero==generos[i].idGenero)
        {
            strcpy(genero, generos[i].genero);
            break;
        }
    }

    for(i=0; i<ta; i++)
    {
        if(unaPelicula.idActor==actores[i].idActor && actores[i].estadoActor!=LIBRE)
        {
            strcpy(actor, actores[i].nombre);
            break;
        }
    }

    printf("%d\t%s\t\t%d/%d/%d\t\t%s\t\t%s\n", unaPelicula.idPelicula, unaPelicula.titulo, Fecha.dia, Fecha.mes, Fecha.anio, genero, actor);

}

//_____________________________________________________

void ordenarPorAnio(ePeliculas peliculas[],int tp,eFechas fechas[],int tf)
{
    int i;
    int j;
    ePeliculas auxiliar;
    eFechas auxiliarF;

    for(i=0; i<tp-1; i++)
    {
        for(j=i+1; j<tf; j++)
        {
            if(fechas[i].anio>fechas[j].anio)
            {
                auxiliar=peliculas[i];
                peliculas[i]=peliculas[j];
                peliculas[j]=auxiliar;

                auxiliarF=fechas[i];
                fechas[i]=fechas[j];
                fechas[j]=auxiliarF;
            }
        }
    }
}

//_____________________________________________________

void mostrarListaPeliculasPorAnio(ePeliculas peliculas[], int tp, eGeneros generos[], int tg, eActores actores[], int ta, eFechas fechas[])
{
    int i;
    ordenarPorAnio(peliculas,tp,fechas,tp);
    for(i=0; i<tp; i++)
    {
        if(peliculas[i].estado!=LIBRE)
        {
            mostrarPelicula(peliculas[i],fechas[i],generos, tg, actores,ta);
        }

    }
}

//_____________________________________________________

void ordenarPorPais(eActores actores[],int ta)
{
    int i;
    int j;
    eActores auxiliar;

    for(i=0; i<ta-1; i++)
    {
        for(j=i+1; j<ta; j++)
        {
            if(stricmp(actores[i].paisOrigen,actores[j].paisOrigen)>0 && actores[i].estadoActor!=LIBRE && actores[j].estadoActor!=LIBRE)
            {
                auxiliar=actores[i];
                actores[i]=actores[j];
                actores[j]=auxiliar;

            }
        }
    }
}

//_____________________________________________________

void mostrarActor(eActores unActor)
{
    printf("%s\t\t%s\n",unActor.paisOrigen, unActor.nombre);
}

//_____________________________________________________

void mostrarListaActores(eActores actores[], int ta)
{
    int i;
    ordenarPorPais(actores,ta);
    for(i=0; i<ta; i++)
    {
        if(actores[i].estadoActor!=LIBRE)
        {
            mostrarActor(actores[i]);
        }
    }
}

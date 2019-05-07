#include <stdlib.h>
#include "funciones.h"

#define TA 50
#define TAM 1000


int main()
{
    int opcion;

    ePeliculas peliculas[TAM];
    eFechas fechas[TAM];
    eGeneros generos[5] = {{1,"Accion"},{2,"Comedia"},{3,"Drama"},{4,"Romance"},{5,"Terror"}};
    eActores actores[TA]={{1,"Scarlett Johansson","Argentina"},{2,"Robert Downey Jr","EEUU"},{3,"Mark Ruffalo","Camada"},{4,"Chris Evans","EEUU"},{5,"Chris Hemsworth","Argentina"},{6,"Samuel Jackson","EEUU"},{7,"Gwyneth Paltrow","Canada"},{8,"Paul Rudd","Argentina"},{9,"Bradley Cooper","EEUU"},{10,"Josh Brolin","Canada"}};

    inicializarPeliculas(peliculas,TAM);

    hardcodearDatos(peliculas,20,fechas);

    do
    {
        opcion=pedirInt("1.Alta\n2.Modificar\n3.Bajar\n4.Listar peliculas\n5.Lista actores\n6.Salir\nElija una opcion: ");

        switch(opcion)
        {
        case 1:
            agregarPelicula(peliculas,TAM,generos,5,actores,10,fechas);
            break;
        case 2:
            modificarPelicula(peliculas,TAM,actores,10,fechas,generos,TAM);
            break;
        case 3:
            bajarPelicula(peliculas,TAM,actores,10,fechas,generos,TAM);
            break;
        case 4:
            mostrarListaPeliculasPorAnio(peliculas,TAM,generos,TAM,actores,20,fechas);
            break;
        case 5:
            mostrarListaActores(actores,20);
            break;

        }
        system("pause");
        system("cls");

    }
    while(opcion!=6);
    return 0;
}

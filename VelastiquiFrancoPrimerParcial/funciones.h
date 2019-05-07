#include <stdio.h>
#include "string.h"

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int idActor;
    char nombre[31];
    char paisOrigen[21];
} eActores;

typedef struct
{
    int idGenero;
    char genero[21];
} eGeneros;

typedef struct
{
    int anio;
    int mes;
    int dia;
    int idFecha;
} eFechas;

typedef struct
{
    char titulo[31];
    int idPelicula;
    int idGenero;
    int idActor;
    int idFecha;
    int estado;
} ePeliculas;

void inicializarPeliculas(ePeliculas[],int);

int buscarLibre(ePeliculas[],int);

void agregarPelicula(ePeliculas[],int,eGeneros[],int,eActores[],int,eFechas[]);

void hardcodearDatos(ePeliculas[], int, eFechas[]);

int pedirInt(char[]);

void modificarPelicula(ePeliculas[],int,eActores[],int,eFechas[],eGeneros[],int);

void bajarPelicula(ePeliculas[], int, eActores[], int, eFechas[], eGeneros[],int);

void mostrarPelicula(ePeliculas,eFechas,eGeneros[],int,eActores[],int);

void ordenarPorAnio(ePeliculas[],int,eFechas[],int);

void mostrarListaPeliculasPorAnio(ePeliculas[], int, eGeneros[], int, eActores[], int, eFechas[]);

void ordenarPorPais(eActores[],int);

void mostrarActor(eActores);

void mostrarListaActores(eActores[], int);

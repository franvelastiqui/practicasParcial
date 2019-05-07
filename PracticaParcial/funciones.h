#include <stdio.h>
#include "string.h"

#define LIBRE 0
#define ACTIVA 1

#define PAUSADA 2

typedef struct
{
    int idAviso;
    int idCliente;
    int numeroRubro;
    char textoAviso[64];
    int estado;
} ePublicaciones;

typedef struct
{
    int id;
    char nombre[21];
    char apellido[21];
    long cuit;
    int estado;
    int cantidad;
} eClientes;

int pedirInt(char[]);

char pedirChar(char[]);

float pedirFloat(char[]);

long pedirLong(char[]);

void inicializar(eClientes[],int,ePublicaciones[],int);

int buscarLibre(eClientes[],int);

int buscarPublicacionLibre(ePublicaciones[],int);

int buscarPorId(eClientes[],int);

int buscarPublicacionPorId(ePublicaciones[],int);

void agregarCliente(eClientes[],int);

void mostrarCliente(eClientes);

void modificarCliente(eClientes[],int);

void bajarCliente(eClientes[],int);

void crearPublicacion(eClientes[],int,ePublicaciones[],int);

void pausarPublicacion(eClientes[],int,ePublicaciones[],int);

void reanudarPublicacion(eClientes[],int,ePublicaciones[],int);

void mostrarListaClientes(eClientes[],int);

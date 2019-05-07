
#include <stdlib.h>
#include "Empleado.h"

#define T 10
#define TS 3


int main()
{

    int opcion;

    eEmpleado lista[T];
    inicializarEmpleados(lista,T);

    eSector sectores[3] = {{1,"Contabilidad",100},{2,"Sistemas",200},{3, "RRHH", 150}};

    hardcodearDatosEmpleados(lista,6, sectores, TS);
    do
    {
        opcion = menuDeOpciones("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Informar Sectores\n6.Total Sueldos por Sector\n7.Sector con mas Empleados\n10.Salir\nElija una opcion: ");
        switch(opcion)
        {
        case 1:
            cargarEmpleado(lista,  T, sectores, TS);
            break;
        case 2:
            bajarEmpleado(lista, T, 3, sectores, TS);
            break;
        case 3:
            modificarEmpleado(lista, T, 3, sectores, TS);
            break;
        case 4:
            mostrarListaEmpleados(lista, T, sectores, TS);
            break;
        case 5:
            mostrarSector(lista, T, sectores, TS);
            break;
        case 6:
            calcularSueldosSector(lista,T,sectores,TS);
            break;
        case 7:
            mostrarSectorConMasEmpleados(lista,T,sectores,TS);
            break;

        }
        system("pause");
        system("cls");
    }
    while(opcion!=10);


    return 0;
}

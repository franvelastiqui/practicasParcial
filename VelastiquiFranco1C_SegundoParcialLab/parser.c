#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"

int parserEmpleado(FILE* pFile , LinkedList* listadoE)
{
    eEmpleado* empleado;
    int verificacion=-1;

    char id[500], nombre[500], empleo[500], edad[500], horasTrabajadas[500];

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, empleo, edad, horasTrabajadas);

            empleado=eEmpleado_newParametros(id, nombre, empleo, edad, horasTrabajadas);

            ll_add(listadoE, empleado);
        }
        verificacion=0;
    }

    return verificacion;
}

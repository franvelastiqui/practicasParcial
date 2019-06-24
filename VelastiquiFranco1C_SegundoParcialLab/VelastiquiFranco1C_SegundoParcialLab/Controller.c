#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int cargarDeTexto(char* path, LinkedList* listadoE)
{
    int verificacion=-1;

    FILE* miArchivo;

    miArchivo=fopen(path, "r");

    if(miArchivo!=NULL);
    {
        verificacion=parserEmpleado(miArchivo, listadoE);
    }

    fclose(miArchivo);

    return verificacion;
}


int ordenarEmpleado(LinkedList* listadoE)
{
    int verificacion= -1;

    if(listadoE != NULL)
    {
        ll_sort(listadoE, *(Empleado_compareByName), 1);
        verificacion=0;
    }
    return verificacion;
}


int listarEmpleado(LinkedList* listadoE, int flag)
{
    eEmpleado* empleado;
    int verificacion=-1;
    int i;

    if(listadoE != NULL)
    {
        for(i=0; i<ll_len(listadoE); i++)
        {
            if(i%200==0)
            {
                system("pause");
            }

            empleado=(eEmpleado*)ll_get(listadoE, i);
            if(flag==0)
            {
               Empleado_printEmpleado(empleado);
            }
            else
            {
                Empleado_printEmpleadoConSueldo(empleado);
            }

        }
        verificacion=0;
    }

    return verificacion;
}

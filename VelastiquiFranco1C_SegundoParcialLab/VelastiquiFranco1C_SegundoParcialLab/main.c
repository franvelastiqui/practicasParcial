#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    int option;
    int flag;
    int verificacion;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        printf("1.Cargar los datos desde archivo\n2.Listar por nombre\n3.Calcular sueldo\n4.Listar con sueldo\n5.Salir\nElija una opcion: ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            verificacion=cargarDeTexto("datos.csv",listaEmpleados);
            verificar(&verificacion, "Se han cargado con exito\n");
            break;
        case 2:
            flag=0;
            verificacion=ordenarEmpleado(listaEmpleados);
            verificar(&verificacion, "Se han ordenado con exito\n");
            listarEmpleado(listaEmpleados, flag);
            break;
        case 3:
            verificacion=ll_map(listaEmpleados, *(laQueMapea));
            verificar(&verificacion, "Se ha realizado con exito la operacion\n");
            break;
        case 4:
            flag=1;
            verificacion=ordenarEmpleado(listaEmpleados);
            verificar(&verificacion, "Se han ordenado con exito\n");
            listarEmpleado(listaEmpleados, flag);

        }

        system("pause");
        system("cls");

    } while(option!=5);

    return 0;
}

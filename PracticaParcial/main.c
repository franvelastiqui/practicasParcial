#include <stdlib.h>
#include "funciones.h"

#define TC 100
#define TS 1000

int main()
{
    int opcion;

    eClientes listado[TC];
    ePublicaciones publicaciones[TS];
    inicializar(listado,TC,publicaciones,TS);

    do
    {
        opcion=pedirInt("1.Alta\n2.Modificar\n3.Bajar\n4.Publicar\n5.Pausar publicacion\n6.Reanudar publicacion\n7.Imprimir clientes\n8.Imprimir publicaciones\n9.Informar clientes\n10.Informar publicaciones\n11.Salir\nElija una opcion: ");

        switch(opcion)
        {
        case 1:
            agregarCliente(listado,TC);
            break;
        case 2:
            modificarCliente(listado,TC);
            break;
        case 3:
            bajarCliente(listado,TC);
            break;
        case 4:
            crearPublicacion(listado,TC,publicaciones,TS);
            break;
        case 5:
            pausarPublicacion(listado,TC,publicaciones,TS);
            break;
        case 6:
            reanudarPublicacion(listado,TC,publicaciones,TS);
            break;
        case 7:
            mostrarListaClientes(listado,TC);
            break;
        }
        system("pause");
        system("cls");

    }
    while(opcion!=11);

    return 0;
}

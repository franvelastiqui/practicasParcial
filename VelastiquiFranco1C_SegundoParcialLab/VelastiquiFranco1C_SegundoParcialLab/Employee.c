#include "Employee.h"
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

eEmpleado* eEmpleado_new()
{
    eEmpleado* empleado;

    empleado = (eEmpleado*)malloc(sizeof(eEmpleado));

    return empleado;
}

//_______________________________________________________________

eEmpleado* eEmpleado_newParametros(char* idStr,char* nombreStr,char* empleoStr,char* edadStr,char* horasTrabajadasStr)
{
    eEmpleado* empleado=eEmpleado_new();

    Empleado_setId(empleado, atoi(idStr));
    Empleado_setNombre(empleado, nombreStr);
    Empleado_setEmpleo(empleado, empleoStr);
    Empleado_setEdad(empleado, atoi(edadStr));
    Empleado_setHorasTrabajadas(empleado, atoi (horasTrabajadasStr));

    return empleado;
}

//_______________________________________________________________

void Empleado_delete(eEmpleado* this)
{
    free(this);
}

//_______________________________________________________________

int Empleado_setId(eEmpleado* this, int id)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        this->id=id;
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int Empleado_getId(eEmpleado* this,int* id)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        *id=this->id;
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int Empleado_setNombre(eEmpleado* this, char nombre[])
{
    int verificacion=-1;
    if(this!=NULL)
    {
        strcpy(this->nombre, nombre);
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int Empleado_getNombre(eEmpleado* this,char* nombre)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        strcpy(nombre, this->nombre);
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int Empleado_setEmpleo(eEmpleado* this, char empleo[])
{
    int verificacion=-1;
    if(this!=NULL)
    {
        strcpy(this->empleo, empleo);
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int Empleado_getEmpleo(eEmpleado* this,char* empleo)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        strcpy(empleo, this->empleo);
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int Empleado_setEdad(eEmpleado* this, int edad)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        this->edad=edad;
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int Empleado_getEdad(eEmpleado* this,int* edad)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        *edad=this->edad;
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int Empleado_setHorasTrabajadas(eEmpleado* this, int horasTrabajadas)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

int Empleado_getHorasTrabajadas(eEmpleado* this,int* horasTrabajadas)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        verificacion=0;
    }

    return verificacion;
}

//_______________________________________________________________

void Empleado_printEmpleado(eEmpleado* this)
{
    int id;
    char nombre[50];
    char empleo[50];
    int edad;
    int horasTrabajadas;

    Empleado_getId(this, &id);
    Empleado_getHorasTrabajadas(this, &horasTrabajadas);
    Empleado_getEdad(this, &edad);
    Empleado_getNombre(this, nombre);
    Empleado_getEmpleo(this, empleo);

    printf("%d%15s%10d%10d%15s\n", id, nombre, horasTrabajadas, edad, empleo);
}

//_______________________________________________________________

int Empleado_compareByName(void* empleadoUno, void* empleadoDos)
{
    int estado;
    char nombre1[50];
    char nombre2[50];

    eEmpleado* emp1=(eEmpleado*)empleadoUno;
    eEmpleado* emp2=(eEmpleado*)empleadoDos;

    Empleado_getNombre(emp1,nombre1);
    Empleado_getNombre(emp2,nombre2);

    estado=stricmp(nombre1,nombre2);

    return estado;
}

//_______________________________________________________________

int verificar(int* ver, char mensaje[])
{
    if(*ver==0)
    {
        printf(mensaje);
    }
    else
    {
        printf("Hubo un error\n");
    }

    return 0;
}

int Empleado_getSueldo(eEmpleado* this, float* sueldo)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        verificacion=0;
    }

    return verificacion;
}

int Empleado_setSueldo(eEmpleado* this, int sueldo)
{
    int verificacion=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        verificacion=0;
    }

    return verificacion;
}


int laQueMapea(void* item)
{
    int horas;
    float sueldo;
    int auxiliar=-1;

    if(item!=NULL)
    {
        eEmpleado* emp1=(eEmpleado*)item;

        Empleado_getHorasTrabajadas(emp1, &horas);

        sueldo=horas*300;

        Empleado_setSueldo(emp1, sueldo);

        auxiliar=0;
    }

    return auxiliar;
}

//_______________________________________________________________

void Empleado_printEmpleadoConSueldo(eEmpleado* this)
{
    int id;
    char nombre[50];
    char empleo[50];
    int edad;
    int horasTrabajadas;
    float sueldo;

    Empleado_getId(this, &id);
    Empleado_getHorasTrabajadas(this, &horasTrabajadas);
    Empleado_getEdad(this, &edad);
    Empleado_getNombre(this, nombre);
    Empleado_getEmpleo(this, empleo);
    Empleado_getSueldo(this, &sueldo);

    printf("%d%15s%10d%10d%15s%15f\n", id, nombre, horasTrabajadas, edad, empleo, sueldo);
}

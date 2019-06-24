typedef struct
{
    int id;
    char nombre[100];
    char empleo[100];
    int edad;
    int horasTrabajadas;
    float sueldo;
} eEmpleado;

eEmpleado* eEmpleado_new();
eEmpleado* eEmpleado_newParametros(char* idStr,char* nombreStr,char* empleoStr,char* edadStr,char* horasTrabajadasStr);
void Empleado_delete(eEmpleado* this);

int Empleado_setId(eEmpleado* this,int id);
int Empleado_getId(eEmpleado* this,int* id);

int Empleado_setNombre(eEmpleado* this,char nombre[]);
int Empleado_getNombre(eEmpleado* this,char* nombre);

int Empleado_setEmpleo(eEmpleado* this,char empleo[]);
int Empleado_getEmpleo(eEmpleado* this,char* empleo);

int Empleado_setEdad(eEmpleado* this,int edad);
int Empleado_getEdad(eEmpleado* this,int* edad);

int Empleado_setHorasTrabajadas(eEmpleado* this,int horasTrabajadas);
int Empleado_getHorasTrabajadas(eEmpleado* this,int* horasTrabajadas);

void Empleado_printEmpleado(eEmpleado* this);

int Empleado_compareByName(void* empleadoUno, void* empleadoDos);

int verificar(int* ver, char mensaje[]);

int laQueMapea(void* item);

int Empleado_getSueldo(eEmpleado* this,float* sueldo);
int Empleado_setSueldo(eEmpleado* this, int sueldo);

void Empleado_printEmpleadoConSueldo(eEmpleado* this);

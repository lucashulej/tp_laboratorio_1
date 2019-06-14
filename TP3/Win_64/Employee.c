#include "Employee.h"
/** \brief crea espacio en memoria para un empleado
 *
 * \return Employee* el puntero al empleado creado
 *
 */
Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

/** \brief verficia si los datos son validos y se los asgina al puntero de empleado
 *
 * \param idStr char* el id del empleado en formato string
 * \param nombreStr char* el nombre del empleado
 * \param horasTrabajadasStr char* las horas del empleado en formato string
 * \param sueldoStr char* el sueldo del empleado en formato string
 * \return Employee* si todo esta bien delvuelve el puntero al empleado, sino NULL
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee *empleado;
    if(idStr!=NULL && nombreStr!=NULL && sueldoStr!=NULL && horasTrabajadasStr!=NULL)
    {
        if(isValidPositiveInter(idStr)&&isValidName(nombreStr)&&isValidPositiveInter(sueldoStr)&&isValidPositiveInter(horasTrabajadasStr))
        {
            empleado=employee_new();
            if(empleado!=NULL)
            {
                if(!employee_setId(empleado,atoi(idStr)))
                {
                    return NULL;
                }
                if(!employee_setNombre(empleado,nombreStr))
                {
                    return NULL;
                }
                if(!employee_setSueldo(empleado,atoi(sueldoStr)))
                {
                    return NULL;
                }
                if(!employee_setHorasTrabajadas(empleado,atoi(horasTrabajadasStr)))
                {
                    return NULL;
                }
                return empleado;
            }
        }
    }
    return NULL;
}

/** \brief elimina al empleado en memoria
 *
 * \param this Employee* puntero al empleado que se desea eliminar
 * \return int 1 si se pudo eliminar, sino 0
 *
 */
int employee_delete(Employee* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        free(this);
        retorno=1;
    }
    return retorno;
}

/** \brief setea el id de un empleado
 *
 * \param this Employee* puntero al empleado
 * \param id int el id que se desea setear
 * \return int 1 si se logro, sino 0
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno=0;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        retorno=1;
    }
    return retorno;
}

/** \brief obtiene el id de un empleado
 *
 * \param this Employee* puntero al empleado
 * \param id int* puntero al id
 * \return int 1 si se logra, sino 0
 *
 */
int employee_getId(Employee* this,int* id)
{
    int retorno=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=1;
    }
    return retorno;
}

/** \brief setea el nombre de un empleado
 *
 * \param this Employee* puntero al empleado
 * \param nombre char* el nombre que se desea setear
 * \return int 1 si se logra, sino 0
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }
    return retorno;
}

/** \brief obtiene el nombre de un empleado
 *
 * \param this Employee* puntero al empleado
 * \param nombre char* el nombre que se va a obtener
 * \return int 1 se se logra, sino 0
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }
    return retorno;
}

/** \brief setea las horas trabajadas trabajadas de un empleado
 *
 * \param this Employee* puntero al empleado
 * \param horasTrabajadas int las horas trabajadas que se van a setear
 * \return int 1 si se logra, sino 0
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

/** \brief obtiene las horas trabajadas trabajadas de un empleado
 *
 * \param this Employee* puntero al empleado
 * \param horasTrabajadas int* las horas trabajadas que se van a obtener
 * \return int 1 si se logra, sino 0
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

/** \brief setea el sueldo de un empleado
 *
 * \param this Employee* puntero al empleado
 * \param sueldo int el sueldo que se va a setear
 * \return int 1 si se logra, sino 0
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=1;
    }
    return retorno;
}

/** \brief obtiene el sueldo de un empleado
 *
 * \param this Employee* puntero al empleado
 * \param sueldo int* el sueldo que se va a obtener
 * \return int 1 si se logra, sino 0
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=1;
    }
    return retorno;
}

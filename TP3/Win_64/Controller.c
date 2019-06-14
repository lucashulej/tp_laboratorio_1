#include <stdio.h>
#include <stdlib.h>
#include "utn.h" //

#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h" //
#include "parser.h" //


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int TRUE si se pudo, sino FALSE
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=FALSE;
    FILE *pFile=NULL;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            if(parser_EmployeeFromText(pFile,pArrayListEmployee))
            {
                retorno=TRUE;
            }
        }
        fclose(pFile);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int TRUE si se pudo, sino FALSE
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=FALSE;
    FILE *pFile=NULL;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen(path,"rb");
        if(pFile!=NULL)
        {
            if(parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                retorno=TRUE;
            }
        }
        fclose(pFile);
    }
    return retorno;
}


/** \brief
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param id int* id del empleado
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* id)
{
    int retorno=0;
    int auxId;
    char auxName[128];
    char auxString1[10];
    char auxString2[10];
    Employee* empleado;
    if(pArrayListEmployee!=NULL)
    {
        empleado=employee_new();
        if(empleado!=NULL)
        {
            if(!utn_getName("Ingrese el nombre del empleado\n","ERROR en cantidad de caracteres\n",3,128,3,auxName))
            {
                if(!utn_getPositiveInter("Ingrese el sueldo del empleado\n","ERROR en cantidad de caracteres\n",3,10,3,auxString1))
                {
                    if(!utn_getPositiveInter("Ingrese las horas trabajdas del empleado\n","ERROR en cantidad de caracteres\n",3,10,3,auxString2))
                    {
                        if(!controller_usedNames(pArrayListEmployee,auxName))
                        {
                            *id= *id + 1;
                            auxId=*id;
                            if(employee_setId(empleado,auxId)&&employee_setNombre(empleado,auxName)&&employee_setSueldo(empleado,atoi(auxString1))&&employee_setHorasTrabajadas(empleado,atoi(auxString2)))
                            {
                                ll_add(pArrayListEmployee,empleado);
                                retorno=1;
                            }
                            else
                            {
                                *id = *id - 1;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            printf("No hay mas memoria. ");
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    char auxOpcion[3];
    char auxString[10];
    int x;
    int id;
    int index;
    Employee* empleado;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        x=utn_getPositiveInter("Ingrese el id del empleado que desea modificar\n","ERROR en cantidad de caracteres\n",1,10,3,auxString);
        if(x==0)
        {
            id=atoi(auxString);
            index=controller_getEmployeeById(pArrayListEmployee,id);
            if(index>=0)
            {
                empleado=ll_get(pArrayListEmployee,index);
                if(empleado!=NULL)
                {
                    utn_clean();
                        utn_getPositiveInter("MODIFICAR\n1)NOMBRE\n2)SALARIO\n3)HORAS TRABAJADAS\n","ERROR en cantidad de caracteres\n",1,3,3,auxOpcion);
                        utn_clean();
                        switch(atoi(auxOpcion))
                        {
                            case 1:
                                if(controller_modifyName(pArrayListEmployee,empleado))
                                {
                                    retorno=1;
                                }
                                break;
                            case 2:
                                if(controller_modifySalary(pArrayListEmployee,empleado))
                                {
                                    retorno=1;
                                }
                                break;
                            case 3:
                                if(controller_modifyWorkHours(pArrayListEmployee,empleado))
                                {
                                    retorno=1;
                                }
                                break;
                            default:
                                printf("El valor ingresado es valido. ");
                        }
                }
            }

        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int i,x;
    int len;
    int id;
    char auxString[100];
    Employee* empleado;
    int idEmpleado;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        x=utn_getPositiveInter("Ingrese el id del empleado que desea dar de baja\n","ERROR\n",1,10,3,auxString);
        if(x==0)
        {
            id=atoi(auxString);
            len=ll_len(pArrayListEmployee);
            if(len>0)
            {
                for(i=0;i<len;i++)
                {
                    empleado=ll_get(pArrayListEmployee,i);
                    employee_getId(empleado,&idEmpleado);
                    if(id==idEmpleado)
                    {
                        employee_delete(empleado);
                        ll_remove(pArrayListEmployee,i);
                        retorno=1;
                        break;
                    }
                }
            }
        }
        else
        {
            printf("El valor ingresado es valido. ");
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
     int retorno=0;
    int i;
    int len;
    int auxId;
    char auxNombre[128];
    int auxSueldo;
    int auxHorasTrabajadas;
    Employee* empleado;
    char opcion;
    int contador=0;
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        if(len>0)
        {
            for(i=0;i<len;i++)
            {
                if(contador==0)
                {
                    printf("Id     Nombre        Salario      HorasTrabajadas\n");
                }
                empleado=ll_get(pArrayListEmployee,i);
                if(empleado!=NULL)
                {
                    if( employee_getId(empleado,&auxId) &&
                        employee_getNombre(empleado,auxNombre) &&
                        employee_getSueldo(empleado,&auxSueldo) &&
                        employee_getHorasTrabajadas(empleado,&auxHorasTrabajadas))
                    printf("%-3d    %-10s    %-10d   %-5d\n",auxId,auxNombre,auxSueldo,auxHorasTrabajadas);
                    contador++;
                }

                if(i==len-1)
                {
                    utn_getChar("\n\n\na = anterior\ne = salir\n","ERROR\n",10,&opcion);
                    switch(opcion)
                    {
                        case 'a':
                            i=i-contador-10;
                            contador=0;
                            if(i<0)
                            {
                                i=0;
                            }
                            break;
                        case 'e':
                            i=len-1;
                            break;
                        default:
                            i=len-1;
                            break;

                    }
                    utn_clean();

                }

                if(contador==10)
                {
                    utn_getChar("\n\n\ns = siguiente\na = anterior\ne = salir\n","ERROR\n",10,&opcion);
                    switch(opcion)
                    {
                        case 's':
                            break;
                        case 'a':
                            i=i-contador-10;
                            if(i<0)
                            {
                                i=-1;
                            }
                            break;
                        case 'e':
                            i=len-1;
                            break;
                    }
                    contador=0;
                    utn_clean();
                }
            }
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    char auxString[3];
    if(pArrayListEmployee!=NULL)
    {
        if(!utn_getPositiveInter("ORDENAMEINTO\n1)NOMBRE\n2)NOMBRE INVERSO\n3)SALARIO\n4)SALARIO INVERSO\n5)HORAS TRABAJADAS\n6)HORAS TRABAJADAS INVERSO\n","ERROR caracteres no validos\n",1,3,3,auxString))
        {
            switch(atoi(auxString))
            {
                case 1:
                    ll_sort(pArrayListEmployee,controller_sortName,1);
                    retorno=1;
                    break;

                case 2:
                    ll_sort(pArrayListEmployee,controller_sortName,0);
                    retorno=1;
                    break;

                case 3:
                    ll_sort(pArrayListEmployee,controller_sortSalary,1);
                    retorno=1;
                    break;

                case 4:
                    ll_sort(pArrayListEmployee,controller_sortSalary,0);
                    retorno=1;
                    break;

                case 5:
                    ll_sort(pArrayListEmployee,controller_sortWorkHours,1);
                    retorno=1;
                    break;

                 case 6:
                    ll_sort(pArrayListEmployee,controller_sortWorkHours,0);
                    retorno=1;
                    break;

                default:
                    printf("El valor ingresado no es valido");
                    break;
            }
        }
        else
        {
            printf("El valor ingresado no es valido");
        }

    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE* pFile;
    char nombre[128];
    int id;
    int horasTrabajadas;
    int sueldo;
    int len;
    int i;
    Employee* empleado=NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        if(len>0)
        {

            pFile=fopen(path,"w");
            if(pFile!=NULL)
            {
                for(i=0;i<len;i++)
                {
                    empleado=ll_get(pArrayListEmployee,i);
                    if(empleado!=NULL)
                    {
                        if(employee_getId(empleado,&id)&&
                           employee_getNombre(empleado,nombre)&&
                           employee_getHorasTrabajadas(empleado,&horasTrabajadas)&&
                           employee_getSueldo(empleado,&sueldo))
                        {
                            fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
                        }
                    }
                }
            }
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE* pFile;
    int len;
    int i;
    Employee* empleado=NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        if(len>0)
        {
            pFile=fopen(path,"wb");
            if(pFile!=NULL)
            {
                for(i=0;i<len;i++)
                {
                    empleado=ll_get(pArrayListEmployee,i);
                    if(empleado!=NULL)
                    {
                        fwrite(empleado,sizeof(Employee),1,pFile);
                    }
                }
            }
            fclose(pFile);
        }
    }
    return retorno;

}

/** \brief busca el id mas grande de la lista
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param id int* id del empleado
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_getBiggestId(LinkedList* pArrayListEmployee,int* id)
{
    int retorno=0;
    int i;
    int len;
    int auxId;
    Employee* empleado;
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        if(len>0)
        {
            for(i=0;i<len;i++)
            {
                empleado=ll_get(pArrayListEmployee,i);
                if(empleado!=NULL)
                {
                    employee_getId(empleado,&auxId);
                    if(i==0)
                    {
                        *id=auxId;
                        continue;
                    }
                    if(auxId>*id)
                    {
                        *id=auxId;
                    }
                }
            }
        }
        else
        {
            id=NULL;
        }
    }
    return retorno;
}

/** \brief verifica si el nombre ya esta siendo utilizado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param name char* nombre del empleado
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_usedNames(LinkedList* pArrayListEmployee,char* name)
{
    int retorno=0;
    int i;
    int len;
    char auxNombre[128];
    Employee* empleado;
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        if(len>0)
        {
            for(i=0;i<len;i++)
            {
                empleado=ll_get(pArrayListEmployee,i);
                if(empleado!=NULL)
                {
                    employee_getNombre(empleado,auxNombre);
                    if(strcmp(auxNombre,name)==0)
                    {
                        retorno=1;
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief busca un empleado en la lista por su id
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param id int id del empleado
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_getEmployeeById(LinkedList* pArrayListEmployee,int id)
{
    int retorno=-1;
    int i;
    int auxId;
    int len;
    Employee* empleado;
    if(pArrayListEmployee!=NULL )
    {
        len=ll_len(pArrayListEmployee);
        if(len>0)
        {
            for(i=0;i<len;i++)
            {
                empleado=ll_get(pArrayListEmployee,i);
                if(empleado!=NULL)
                {
                    employee_getId(empleado,&auxId);
                    if(id==auxId)
                    {
                        retorno=i;
                        break;
                    }
                }
            }
        }

    }
    return retorno;
}

/** \brief modifica el nombre de un empleado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param this Employee* puntero al empleado
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_modifyName(LinkedList* pArrayListEmployee,Employee* this)
{
    int retorno=0;
    char auxName[128];
    if(pArrayListEmployee!=NULL)
    {
        if(!utn_getName("Ingrese el nuevo nombre del empleado\n","ERROR en cantidad de caracteres\n",3,128,3,auxName))
        {
            if(!controller_usedNames(pArrayListEmployee,auxName))
            {
                if(employee_setNombre(this,auxName))
                {
                    retorno=1;
                }
            }
            else
            {
                printf("El nombre ingresado ya esta siendo utilizado. ");
            }

        }
        else
        {
            printf("El nombre ingresado no es valido. ");
        }
    }
    return retorno;
}

/** \brief modifica el salario de un empleado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param this Employee* puntero al empleado
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_modifySalary(LinkedList* pArrayListEmployee,Employee* this)
{
    int retorno=0;
    char auxSalary[10];
    if(pArrayListEmployee!=NULL)
    {
        if(!utn_getPositiveInter("Ingrese el nuevo salario del empleado\n","ERROR en cantidad de caracteres\n",3,10,3,auxSalary))
        {
            if(employee_setSueldo(this,atoi(auxSalary)))
            {
                retorno=1;
            }
        }
        else
        {
            printf("El salario ingresado no es valido. ");
        }
    }
    return retorno;
}

/** \brief modifica las horas trabajdas de un empleado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param this Employee* puntero al empleado
 * \return int 1 si se pudo, sino 0
 *
 */
int controller_modifyWorkHours(LinkedList* pArrayListEmployee,Employee* this)
{
    int retorno=0;
    char auxWorkHours[10];
    if(pArrayListEmployee!=NULL)
    {
        if(!utn_getPositiveInter("Ingrese la nueva cantidad de horas de trabajo del empleado\n","ERROR en cantidad de caracteres\n",3,10,3,auxWorkHours))
        {
            if(employee_setHorasTrabajadas(this,atoi(auxWorkHours)))
            {
                retorno=1;
            }
        }
        else
        {
            printf("La cantidad de horas trabajadas no son validas. ");
        }
    }
    return retorno;
}

/** \brief compara las horas trabajadas del elemento a con el elemento b
 *
 * \param elementoA void* elemento a
 * \param elementoB void* elemento b
 * \return  int -1 , 0 o 1 dependiendo el tamanio
 *
 */
int controller_sortName(void* elementoA,void* elementoB)
{
    int retorno=NULL;
    Employee* empleadoA;
    Employee* empleadoB;
    char nombreA[100];
    char nombreB[100];
    if(elementoA!=NULL && elementoB!=NULL)
    {
        empleadoA = (Employee*) elementoA;
        empleadoB = (Employee*) elementoB;
        employee_getNombre(empleadoA,nombreA);
        employee_getNombre(empleadoB,nombreB);

       retorno=strcmp(nombreA,nombreB);
    }
    return retorno;
}

/** \brief compara el salario del elemento a con el elemento b
 *
 * \param elementoA void* elemento a
 * \param elementoB void* elemento b
 * \return  -1 , 0 o 1 dependiendo el tamanio
 *
 */
int controller_sortSalary(void* elementoA,void* elementoB)
{
    int retorno=NULL;
    Employee* empleadoA;
    Employee* empleadoB;
    int salaryA;
    int salaryB;
    if(elementoA!=NULL && elementoB!=NULL)
    {
        empleadoA = (Employee*) elementoA;
        empleadoB = (Employee*) elementoB;
        employee_getSueldo(empleadoA,&salaryA);
        employee_getSueldo(empleadoB,&salaryB);
        if(salaryA>salaryB)
        {
            retorno=1;
        }
        else if(salaryB>salaryA)
        {
            retorno=-1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}

/** \brief compara las horas trabajadas del elemento a con el elemento b
 *
 * \param elementoA void* elemento a
 * \param elementoB void* elemento b
 * \return int -1 , 0 o 1 dependiendo el tamanio
 *
 */
int controller_sortWorkHours(void* elementoA,void* elementoB)
{
    int retorno=NULL;
    Employee* empleadoA;
    Employee* empleadoB;
    int workHoursA;
    int workHoursB;
    if(elementoA!=NULL && elementoB!=NULL)
    {
        empleadoA = (Employee*) elementoA;
        empleadoB = (Employee*) elementoB;
        employee_getHorasTrabajadas(empleadoA,&workHoursA);
        employee_getHorasTrabajadas(empleadoB,&workHoursB);
        if(workHoursA>workHoursB)
        {
            retorno=1;
        }
        else if(workHoursB>workHoursA)
        {
            retorno=-1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}

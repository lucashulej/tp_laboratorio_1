#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h" //

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* lista de empleado
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    char auxId[10];
    char auxNombre[128];
    char auxHorasTrabajadas[10];
    char auxSueldo[10];
    int flag=0;
    Employee* empleado;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            empleado=employee_new();
            if(empleado!=NULL)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
                if(flag==0)
                {
                    flag=1;
                    continue;
                }

                empleado=employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
                if(empleado!=NULL)
                {
                    ll_add(pArrayListEmployee,empleado);
                    retorno=1;
                }
                else
                {
                    employee_delete(empleado);
                }
            }
            else
            {
                printf("No hay mas espacio para un nuevo empleado. ");
            }

        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    Employee auxEmpleado;
    Employee* empleado=NULL;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            fread(&auxEmpleado,sizeof(Employee),1,pFile);
            if(feof(pFile))
            {
               continue;
            }
            empleado=employee_new();
            if(employee_setId(empleado,auxEmpleado.id)
               &&employee_setNombre(empleado,auxEmpleado.nombre)
               &&employee_setSueldo(empleado,auxEmpleado.sueldo)
               &&employee_setHorasTrabajadas(empleado,auxEmpleado.horasTrabajadas))
            {
                ll_add(pArrayListEmployee,empleado);
                retorno=1;
            }
            else
            {
                employee_delete(empleado);
            }
        }
    }
    return retorno;
}

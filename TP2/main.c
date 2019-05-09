#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empleados.h"
#define ELEMENTOS 10

int main()
{
    Empleado arrayEmpleados[ELEMENTOS];
    int opcion;
    int index;
    emp_initArray(arrayEmpleados,ELEMENTOS);
    do
    {
        getInter("Ingrese una opcion:\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-IMPRIMIR\n5-SALIR\n","ERROR\n",1,5,&opcion);
        clean();
        switch(opcion)
        {
            case 1:
                if(emp_buscarLibre(arrayEmpleados,ELEMENTOS,&index))
                {
                    if(emp_alta(arrayEmpleados,ELEMENTOS,index))
                    {
                        printf("El empleado fue ingresado de manera exitosa\n");
                    }
                    else
                    {
                        printf("ERROR.El empleado no pudo ser ingresado\n");
                    }
                }
                else
                {
                    printf("No hay mas espacio libre\n");
                }
                break;
            case 2:
                if(emp_comprobarLista(arrayEmpleados,ELEMENTOS))
                {
                    if(emp_modificar(arrayEmpleados,ELEMENTOS))
                    {
                        printf("El empleado fue modificado de manera exitosa\n");
                    }
                    else
                    {
                        printf("ERROR. El empleado no fue modificado\n");
                    }
                }
                else
                {
                    printf("La opcion ingresada no es valida\n");
                }
                break;
            case 3:
                if(emp_comprobarLista(arrayEmpleados,ELEMENTOS))
                {
                    if(emp_baja(arrayEmpleados,ELEMENTOS))
                    {
                        printf("El empleado fue dado de baja\n");
                    }
                    else
                    {
                        printf("ERROR. El empleado no fue dado de baja\n");
                    }
                }
                else
                {
                    printf("La opcion ingresada no es valida\n");
                }
                break;
            case 4:
                if(emp_comprobarLista(arrayEmpleados,ELEMENTOS))
                {
                    getInter("Ingrese una opcion:\n1-IMPRIMIR LISTA ORDENADA\n2-SALARIOS\n3-SALIR\n","ERROR\n",1,3,&opcion);
                    {
                        switch(opcion)
                        {
                            case 1:
                                emp_ordenar(arrayEmpleados,ELEMENTOS);
                                emp_imprimirArray(arrayEmpleados,ELEMENTOS);
                                break;
                            case 2:
                                emp_informeSalarios(arrayEmpleados,ELEMENTOS);
                                break;
                            case 3:
                                break;
                        }
                    }
                }
                else
                {
                    printf("La opcion ingresada no es valida\n");
                }
                break;
            case 5:
                break;
        }
        pauseClean();
    }while(opcion!=5);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flag=0;
    int id=0;
    do{
        menu();
        printf("Ingrese opcion\n");
        scanf("%d",&option);
        utn_clean();
        switch(option)
        {
            case 1:
                if(flag==0)
                {
                    flag=1;
                    if(controller_loadFromText("data.csv",listaEmpleados))
                    {
                        printf("La lista fue cargada de manera correcta\n");
                        controller_getBiggestId(listaEmpleados,&id);
                    }
                    else
                    {
                        printf("No se pudo cargar la lista\n");
                    }
                }
                else
                {
                    printf("La lista ya fue cargada\n");
                }
                break;
            case 2:
                if(flag==0)
                {
                    flag=1;
                    if(controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        controller_getBiggestId(listaEmpleados,&id);
                        printf("La lista fue cargada de manera correcta\n");
                    }
                    else
                    {
                        printf("No se pudo cargar la lista\n");
                    }
                }
                else
                {
                    printf("La lista ya fue cargada\n");
                }

                break;
            case 3:
                if(flag==1)
                {
                    if(controller_addEmployee(listaEmpleados,&id))
                    {
                        printf("El empleado fue dado de alta");
                    }
                    else
                    {
                        printf("El empleado NO fue dado de alta");
                    }
                }
                else
                {
                    printf("Primero debe cargar la lista\n");
                }
                break;
            case 4:
                if(flag==1)
                {
                    if(controller_editEmployee(listaEmpleados))
                    {
                        printf("El empleado a sido modificado\n");
                    }
                    else
                    {
                        printf("El empleado NO a sido modificado\n");
                    }
                }
                else
                {
                    printf("Primero debe cargar la lista\n");
                }
                break;
            case 5:
                if(flag==1)
                {
                    if(controller_removeEmployee(listaEmpleados))
                    {
                        printf("El empleado se a dado de baja\n");
                    }
                    else
                    {
                        printf("El empleado NO se a dado de baja\n");
                    }
                }
                else
                {
                    printf("Primero debe cargar la lista\n");
                }

                break;
            case 6:
                if(flag==1)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero debe cargar la lista\n");
                }
                break;
            case 7:
                if(flag==1)
                {
                    if(controller_sortEmployee(listaEmpleados))
                    {
                        printf("La lista ha sido ordenada\n");
                    }
                    else
                    {
                        printf("La lista NO ha sido ordenada\n");
                    }
                }
                else
                {
                    printf("Primero debe cargar la lista\n");
                }
                break;
            case 8:
                if(flag==1)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                    printf("Lista cargada\n");
                }
                else
                {
                    printf("Primero debe cargar la lista\n");
                }
                break;
            case 9:
                if(flag==1)
                {
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    printf("Lista cargada\n");
                }
                else
                {
                    printf("Primero debe cargar la lista\n");
                }
                break;
            case 10:
                ll_deleteLinkedList(listaEmpleados);
                break;
        }
    utn_pauseClean();
    }while(option != 10);
    return 0;
}

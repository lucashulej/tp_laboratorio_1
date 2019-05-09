#include "Empleados.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int emp_comprobarLista(Empleado lista[],int len)
{
    int retorno=FALSE;
    int i;
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==0)
        {
            retorno=TRUE;
            break;
        }
    }
    return retorno;
}

int emp_initArray(Empleado lista[],int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        lista[i].isEmpty=1;
    }
    return 1;
}

int emp_buscarLibre(Empleado lista[],int len,int *index)
{
    int i;
    int retorno=0;
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==1)
        {
            *index=i;
            retorno=1;
            break;
        }
    }
    return retorno;
}

int emp_alta(Empleado lista[],int len,int id)
{
    Empleado auxEmpleado;
    int retorno=0;
    int i;
    int x=0;

    printf("ALTA\n");
    i=getName("Ingrese un nombre : ","ERROR\n",2,50,3,auxEmpleado.nombre);
    x = x + i;
    i=getName("Ingrese un apellido : ","ERROR\n",2,50,3,auxEmpleado.apellido);
    x = x + i;
    getFloat("Ingrese el salario : ","ERROR\n",1,100000,&auxEmpleado.salary);
    getInter("Ingrese un sector entre 1 y 100: ","ERROR\n",1,100,&auxEmpleado.sector);
    i=emp_comprobarNombreApellido(lista,len,auxEmpleado);
    x = x + i;

    if(x==0)
    {
        lista[id]=auxEmpleado;
        lista[id].idEmpleado=id;
        lista[id].isEmpty=0;
        retorno=1;
    }
    return retorno;
}

int emp_baja(Empleado lista[],int len)
{
    Empleado auxEmpleado;
    int retorno=0;
    int i;
    int x=0;
    int id;
    emp_imprimirArray(lista,len);
    printf("BAJA\n");
    i=getName("Ingrese el nombre : ","ERROR\n",2,50,3,auxEmpleado.nombre);
    x = x + i;
    i=getName("Ingrese un apellido : ","ERROR\n",2,50,3,auxEmpleado.apellido);
    x = x + i;
    if(x==0)
    {
        id=emp_buscarIdPorNombreApellido(lista,len,auxEmpleado);
        if(id>=0)
        {
            lista[id].isEmpty=1;
            retorno=1;
        }
        else
        {
            printf("El empleado no existe\n");
        }
    }
    return retorno;
}

int emp_comprobarNombreApellido(Empleado lista[],int len,Empleado auxEmpleado)
{
    int retorno=0;
    int i;
    for(i=0;i<len;i++)
    {
        if( strcmp(lista[i].nombre,auxEmpleado.nombre)==0 && strcmp(lista[i].apellido,auxEmpleado.apellido)==0 && lista[i].isEmpty==0)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}

int emp_buscarIdPorNombreApellido(Empleado lista[],int len,Empleado auxEmpleado)
{
    int retorno=-1;
    int i;
    for(i=0;i<len;i++)
    {
        if( strcmp(lista[i].nombre,auxEmpleado.nombre)==0 &&strcmp(lista[i].apellido,auxEmpleado.apellido)==0 && lista[i].isEmpty==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int emp_imprimirArray(Empleado lista[],int len)
{
    int retorno=TRUE;
    int i;
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==0)
        {
            printf("%6s %6s %3.2f %3d\n",lista[i].nombre,lista[i].apellido,lista[i].salary,lista[i].sector);
        }
    }
    return retorno;
}

int emp_modificar(Empleado lista[],int len)
{
    Empleado auxEmpleado;
    int retorno = FALSE;
    int i,opcion,index;
    int x=0;
    emp_imprimirArray(lista,len);

    i=getName("Ingrese nombre del empleado: ","ERROR\n",2,50,3,auxEmpleado.nombre);
    x = x + i;
    i=getName("Ingrese apellido del empleado: ","ERROR\n",2,50,3,auxEmpleado.apellido);
    x = x + i;
    if(x==0)
    {
        index=emp_buscarIdPorNombreApellido(lista,len,auxEmpleado);
        if(index!=-1)
        {
            emp_menu();
            getInter(" ","ERROR\n",0,5,&opcion);
            switch(opcion)
            {
                case 1:
                    if(emp_modificarNombre(lista,len,index,auxEmpleado))
                    {
                        retorno = TRUE;
                    }
                    break;
                case 2:
                    if(emp_modificarApellido(lista,len,index,auxEmpleado))
                    {
                        retorno = TRUE;
                    }
                    break;
                case 3:
                    if(emp_modificarSalario(lista,len,index,auxEmpleado))
                    {
                        retorno = TRUE;
                    }
                    break;
                case 4:
                    if(emp_modificarSector(lista,len,index,auxEmpleado))
                    {
                        retorno = TRUE;
                    }
                    break;
                case 5:
                    break;
            }
        }
    }
    return retorno;
}

int emp_modificarNombre(Empleado lista[],int len, int index, Empleado auxEmpleado)
{
    int retorno=FALSE;
    int i;
    int j;
    i=getName("Ingrese el nuevo nombre del empleado: ","ERROR\n",2,50,3,auxEmpleado.nombre);
    if(i==0)
    {
        j=emp_comprobarNombreApellido(lista,len,auxEmpleado);
        if(j==0)
        {
            strcpy(lista[index].nombre,auxEmpleado.nombre);
            retorno=TRUE;
        }
    }
    return retorno;
}

int emp_modificarApellido(Empleado lista[],int len, int index, Empleado auxEmpleado)
{
    int retorno=FALSE;
    int i;
    int j;
    i=getName("Ingrese el nuevo apellido del empleado: ","ERROR\n",2,50,3,auxEmpleado.apellido);
    if(i==0)
    {
        j=emp_comprobarNombreApellido(lista,len,auxEmpleado);
        if(j==0)
        {
            strcpy(lista[index].apellido,auxEmpleado.apellido);
            retorno = TRUE;
        }
    }
    return retorno;
}

int emp_modificarSalario(Empleado lista[],int len, int index, Empleado auxEmpleado)
{
    int retorno=FALSE;
    getFloat("Ingrese el nuevo salario del empleado: ","ERROR\n",1,100000,&auxEmpleado.salary);
    lista[index].salary=auxEmpleado.salary;
    retorno=TRUE;
    return retorno;
}

int emp_modificarSector(Empleado lista[],int len, int index, Empleado auxEmpleado)
{
    int retorno=FALSE;
    getInter("Ingrese el nuevo sector (1 - 100) del empleado: ","ERROR\n",1,100,&auxEmpleado.sector);
    lista[index].salary=auxEmpleado.salary;
    retorno=TRUE;
    return retorno;
}

void emp_menu()
{
    printf("INGRESE UNA OPCION PARA MODIFICAR:\n");
    printf("1-NOMBRE\n");
    printf("2-APELLIDO\n");
    printf("3-SALARIO\n");
    printf("4-SECTOR\n");
    printf("5-SALIR\n");
}

int emp_ordenar(Empleado lista[],int len)
{
    int retorno=TRUE;
    Empleado auxEmpleado;
    int i,j;
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(lista[j].isEmpty==1)
            {
                continue;
            }
            if(strcmp(lista[i].apellido,lista[j].apellido)>0)
            {
                auxEmpleado=lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmpleado;
            }
        }
    }
    return retorno;
}

int emp_informeSalarios(Empleado lista[],int len)
{
    int retorno=TRUE;
    double promedio=0;
    double total=0;
    int contador=0;
    int superanPromedio=0;
    int i;
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==0)
        {
            total = total + lista[i].salary;
            contador++;
        }
    }
    promedio = total/contador;
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty==0 && lista[i].salary>promedio)
        {
            superanPromedio++;
        }
    }
    printf("El total de los sueldos es de %.2f , el promedio es de %.2f y la cantidad de personas que superan el promedio es de %d\n",total,promedio,superanPromedio);
    return retorno;
}



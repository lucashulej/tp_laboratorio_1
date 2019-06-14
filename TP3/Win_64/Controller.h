#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee,int* id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_getBiggestId(LinkedList* pArrayListEmployee,int* id);
int controller_usedNames(LinkedList* pArrayListEmployee,char* name);
int controller_getEmployeeById(LinkedList* pArrayListEmployee,int id);
int controller_modifyName(LinkedList* pArrayListEmployee,Employee* this);
int controller_modifySalary(LinkedList* pArrayListEmployee,Employee* this);
int controller_modifyWorkHours(LinkedList* pArrayListEmployee,Employee* this);
int controller_sortName(void* elementoA,void* elementoB);
int controller_sortSalary(void* elementoA,void* elementoB);
int controller_sortWorkHours(void* elementoA,void* elementoB);

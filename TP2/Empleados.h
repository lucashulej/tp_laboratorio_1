#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int idEmpleado;
    int isEmpty;
//-------------------------------
    char nombre[50];
    char apellido[50];
    float salary;
    int sector;
}Empleado;

#endif // EMPLEADOS_H_INCLUDED

/** \brief comprueba si en la lista hay un empleado activo
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \return int 1 si hay un empleado activo o 0 si no hay un empleado activo
 *
 */
int emp_comprobarLista(Empleado lista[],int len);

/** \brief pone el valor isEmpty de la estructura empleados en 1
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \return int 1 cuando finaliza
 *
 */
int emp_initArray(Empleado lista[],int len);

/** \brief recorre la lista buscando un espacio libre
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \param index int* pocision donde se encuentra el espacio libre
 * \return int 1 si encuentra lugar libre o 0 si no encuentra lugar libre
 *
 */
int emp_buscarLibre(Empleado lista[],int len,int *index);

/** \brief da de alta a un empleado
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \param id int el id que tendra el empleado
 * \return int 1 si se pudo dar de alta o 0 si no se pudo dar la alta
 *
 */
int emp_alta(Empleado lista[],int len,int id);

/** \brief se da de baja a un empleado
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \return int 1 si se pudo dar de baja o 0 si no se pudo dar de baja
 *
 */
int emp_baja(Empleado lista[],int len);

/** \brief verifica que no exista un empleado activo con el mismo nombre y apellido
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \param auxEmpleado Empleado el empleado con el que se comparara el nombre y el apellido
 * \return int 1 si el nombre y apellido ya fue utilizado o 0 si el nombre y el apellido no han sido utilizados
 *
 */
int emp_comprobarNombreApellido(Empleado lista[],int len,Empleado auxEmpleado);

/** \brief busca el id de un empleado por su nombre y apellido
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \param auxEmpleado Empleado el nombre y apellido con el que buscaran el id
 * \return int -1 si no se encuentra una coincidencia o el ID si se encuentra una coincidencia
 *
 */
int emp_buscarIdPorNombreApellido(Empleado lista[],int len,Empleado auxEmpleado);

/** \brief imprime la lista de empleados
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \return int 1 cuando finaliza
 *
 */
int emp_imprimirArray(Empleado lista[],int len);

/** \brief modifica los diferentes campos de la estructura empleado
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \return int 1 si se logra modificar al empleado o 0 si no se logra modificar al empleado
 *
 */
int emp_modificar(Empleado lista[],int len);

/** \brief modifica el nombre del empleado
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \param index int id del empleado que se va a modificar
 * \param auxEmpleado Empleado empleado que se va a modificar
 * \return int 1 si se modifico o 0 si no se modifico
 *
 */
int emp_modificarNombre(Empleado lista[],int len, int index,Empleado auxEmpleado);

/** \brief modifica el apellido del empleado
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \param index int id del empleado que se va a modificar
 * \param auxEmpleado Empleado empleado que se va a modificar
 * \return int 1 si se modifico o 0 si no se modifico
 *
 */
int emp_modificarApellido(Empleado lista[],int len, int index,Empleado auxEmpleado);

/** \brief modifica el salario del empleado
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \param index int id del empleado que se va a modificar
 * \param auxEmpleado Empleado empleado que se va a modificar
 * \return int 1 cuando finaliza
 *
 */
int emp_modificarSalario(Empleado lista[],int len, int index,Empleado auxEmpleado);

/** \brief modifica el sector del empleado
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \param index int id del empleado que se va a modificar
 * \param auxEmpleado Empleado empleado que se va a modificar
 * \return int 1 cuando finaliza
 *
 */
int emp_modificarSector(Empleado lista[],int len, int index,Empleado auxEmpleado);

/** \brief imprime un menu
 *
 * \param void
 * \return void
 *
 */
void emp_menu(void);

/** \brief ordena la lista alfabeticamente
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \return int 1 cuando finaliza
 *
 */
int emp_ordenar(Empleado lista[],int len);

/** \brief calcula el total, promedio y cuatas personas superan el promedio y lo imprime por pantalla
 *
 * \param lista[] Empleado lista de empleados
 * \param len int tamaño de la lista
 * \return int 1 cuando finaliza
 *
 */
int emp_informeSalarios(Empleado lista[],int len);

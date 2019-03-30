#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief limpia la pantalla
 *
 * \param void
 * \return void
 *
 */
void clean(void);

/** \brief pausa el programa y luego limpia la pantalla
 *
 * \param void
 * \return void
 *
 */
void pauseClean(void);

/** \brief imprime el menu de la calculadora
 *
 * \param int primera bandera
 * \param int segunda bandera
 * \param float numero a
 * \param float numero b
 * \return void
 *
 */
void menu(int,int,float,float);

/** \brief pregunta al usuario que opcion desea
 *
 * \param void
 * \return int la opcion elegida
 *
 */
int askOption(void);

/** \brief pregunta al usuario cual es el numero a
 *
 * \param void
 * \return float el numero a
 *
 */
float askNumA(void);

/** \brief pregunta al usuario cual es el numero b
 *
 * \param void
 * \return float el numero b
 *
 */
float askNumB(void);

/** \brief suma el numero a con el numero b
 *
 * \param float numero a
 * \param float numero b
 * \return float resultado de la suma
 *
 */
float addFunction(float,float);

/** \brief resta el numero a con el numero b
 *
 * \param float numero a
 * \param float numero b
 * \return float resultado de la resta
 *
 */
float subtractFunction(float,float);

/** \brief multiplica el numero a con el numero b
 *
 * \param float numero a
 * \param float numero b
 * \return float resultado de la multiplicacion
 *
 */
float multiplyFunction(float,float);

/** \brief divide el numero a con el numero b
 *
 * \param float numero a
 * \param float numero b
 * \return float resultado de la division
 *
 */
float divideFunction(float,float);

/** \brief calcula el escalar de un numero
 *
 * \param float numero
 * \return double escalar del numero
 *
 */
double scaleFunction(float);

/** \brief imprime el resultado de la suma del numero a con el numero b
 *
 * \param float numero a
 * \param float numero b
 * \param float resultado de la suma
 * \return void
 *
 */
void printAddResult(float,float,float);

/** \brief imprime el resultado de la resta del numero a con el numero b
 *
 * \param float numero a
 * \param float numero b
 * \param float resultado de la resta
 * \return void
 *
 */
void printSubtractResult(float,float,float);

/** \brief imprime el resultado de la division del numero a con el numero b
 *
 * \param float numero a
 * \param float numero b
 * \param float resultado de la division
 * \return void
 *
 */
void printDivideResult(float,float,float);

/** \brief imprime el resultado de la multiplicacion dek numero a con el numero b
 *
 * \param float numero a
 * \param float numero b
 * \param float resultado de la multiplicacion
 * \return void
 *
 */
void printMultiplyResult(float,float,float);

/** \brief imprime el escalar de un numero
 *
 * \param float numero
 * \param double escalar del numero
 * \return void
 *
 */
void printScaleResult(float,double);

/** \brief compara el valor de los numeros para verificar si se debe volver a realizar los calculos antes de mostralos por pantalla
 *
 * \param float numero a
 * \param float numero b
 * \param float numero anterior a
 * \param float numero anterior b
 * \return int 1 si coinciden o 0 si no coinciden
 *
 */
int checkNumbers(float,float,float,float);

#endif // FUNCIONES_H_INCLUDED

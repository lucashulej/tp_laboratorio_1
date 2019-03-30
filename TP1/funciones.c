#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void clean(void)
{
    system("cls");
}

void pauseClean(void)
{
    system("pause");
    system("cls");
}

void menu( int flagA , int flagB , float numA , float numB )
{
    printf("Ingrese una opcion porfavor:\n");
    if(flagA!=0)
    {
        printf("1-Ingresar 1er operando (A=%.2f)\n",numA);
    }
    else
    {
        printf("1-Ingresar 1er operando (A=x)\n");
    }
    if(flagB!=0)
    {
     printf("2-Ingresar 2do operando (B=%.2f)\n",numB);
    }
    else
    {
        printf("2-Ingresar 2do operando (B=x)\n");
    }
    printf("3-Calcular todas las operaciones\n");
    printf("4-Informar resultados\n");
    printf("5-Salir\n");
}

int askOption(void)
{
    int option;
    scanf("%d",&option);
    return option;
}

float askNumA(void)
{
    float numA;
    printf("Ingrese el valor de A:\n");
    scanf("%f",&numA);
    return numA;
}

float askNumB(void)
{
    float numB;
    printf("Ingrese el valor de B:\n");
    scanf("%f",&numB);
    return numB;
}

float addFunction( float numA ,float numB )
{
    float add;
    add = numA + numB;
    return add;
}

float subtractFunction( float numA , float numB )
{
    float subtract;
    subtract = numA -numB;
    return subtract;
}

float multiplyFunction( float numA , float numB)
{
    float multiply;
    multiply = numA * numB;
    return multiply;
}

float divideFunction( float numA , float numB)
{
    float divide;
    divide = numA / numB;
    return divide;
}

double scaleFunction( float num )
{
    int i;
    double scale = 1;
    for(i=num;i>=1;i--)
    {
        scale = scale * i;
    }
    return scale;
}

void printAddResult( float numA , float numB , float addResult)
{
     printf("El resultado de %.2f + %.2f es = %.2f\n",numA,numB,addResult);
}

void printSubtractResult( float numA , float numB , float subtractResult )
{
    printf("El resultado de %.2f - %.2f es = %.2f\n",numA,numB,subtractResult);
}

void printDivideResult( float numA , float numB , float divideResult )
{
    if(numB!=0)
    {
        printf("El resultado de %.2f / %.2f es = %.2f\n",numA,numB,divideResult);
    }
    else
    {
        printf("La division no a podido realizarse ya que no se puede dividir un numero por 0\n");
    }
}
void printMultiplyResult(  float numA , float numB , float multiplyResult )
{
    printf("El resultado de %.2f * %.2f es = %.2f\n",numA,numB,multiplyResult);
}

void printScaleResult( float num , double scale )
{
    if(num==0)
    {
        printf("El escalar de 0 es 1\n");
    }
    else if(num<0)
    {
        printf("No se puede realizar el escalar de un numero negativo\n");
    }
    else
    {
        printf("El escalar de %.2f es %.2f\n",num,scale);
    }
}

int checkNumbers( float numA , float numB , float prevNumA , float prevNumB )
{
    int verified = 0;
    if(prevNumA==numA&&prevNumB==numB)
    {
        verified = 1;
    }
    return verified;
}



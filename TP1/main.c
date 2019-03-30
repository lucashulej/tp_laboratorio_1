#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    //VARIABLES
    int option;
    float numA;
    float numB;
    float prevNumA;
    float prevNumB;
    int flagA = 0;
    int flagB = 0;
    int flagC = 0;
    float addResult;
    float subtractResult;
    float divideResult;
    float multiplyResult;
    double scaleA;
    double scaleB;

    do{
        clean();
        menu(flagA,flagB,numA,numB);
        option = askOption();
        switch(option)
        {
            //OPCION 1
            case 1:
                clean();
                flagA = 1;
                numA = askNumA();
                break;
            //OPCION 2
            case 2:
                clean();
                flagB = 1;
                numB = askNumB();
                break;
            //OPCION 3
            case 3:
                clean();
                if(flagA==1&&flagB==1)
                {
                    flagC=1;
                    prevNumA = numA;
                    prevNumB = numB;
                    addResult = addFunction(numA,numB);
                    subtractResult = subtractFunction(numA,numB);
                    divideResult = divideFunction(numA,numB);
                    multiplyResult = multiplyFunction(numA,numB);
                    scaleA = scaleFunction(numA);
                    scaleB = scaleFunction(numB);
                    printf("Todas las operaciones fueron calculadas\n");
                }
                else
                {
                    printf("Debe ingresar ambos operadores, para realizar los calculos\n");
                }
                pauseClean();
                break;
            //OPCION 4
            case 4:
                clean();
                flagC = checkNumbers(numA,numB,prevNumA,prevNumB);
                if(flagA==1&&flagB==1&&flagC==1)
                {
                    printAddResult(numA,numB,addResult);
                    printSubtractResult(numA,numB,subtractResult);
                    printDivideResult(numA,numB,divideResult);
                    printMultiplyResult(numA,numB,multiplyResult);
                    printScaleResult(numA,scaleA);
                    printScaleResult(numB,scaleB);
                }
                else if(flagA==1&&flagB==1&&flagC==0)
                {
                    printf("Debe ingresar primero la opcion 3\n");
                }
                else
                {
                    printf("Debe ingresar ambos operadores, para mostrar los resultados\n");
                }
                pauseClean();
                break;
            //OPCION 5
            case 5:
                clean();
                break;

            default:
                clean();
                printf("La opcion ingresada no es valida\n");
                pauseClean();
                break;
        }
    }while(option!=5);
    return 0;
}

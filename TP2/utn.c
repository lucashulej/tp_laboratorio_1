#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int getString ( char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int getName (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}


int isValidName (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------
int getInter(char* msg,char* msgError,int minimo,int maximo,int* resultado)
{
    int retorno = -1;
    int contador=0;
    char auxString[50];
    if(msg != NULL && msgError != NULL && minimo < maximo && resultado !=NULL )
    {
        do
        {
            if(contador==1)
            {
                printf("%s",msgError);
            }

            printf("%s",msg);
            scanf("%s",auxString);
            if(isValidInter(auxString))
            {
                *resultado=atoi(auxString);
                if(*resultado>=minimo && *resultado<=maximo)
                {
                    retorno=0;
                }
            }
            contador=1;
        }while(retorno==-1);
    }
    return retorno;
}

int isValidInter (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0; cadena[i] != '\0'; i++)
    {
        if((cadena[i] < '0' || cadena[i] > '9'))
        {
            if(i==0 && cadena[i]=='-')
            {
                continue;
            }
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------
int getFloat(char* msg,char* msgError,int minimo,int maximo,float* resultado)
{
    int retorno = -1;
    char auxString[50];
    if(msg != NULL && msgError != NULL && minimo < maximo && resultado !=NULL )
    {
        do
        {
            printf("%s",msg);
            scanf("%s",auxString);
            if(isValidFloat(auxString))
            {
                *resultado=atof(auxString);
                if(*resultado>=minimo && *resultado<=maximo)
                {
                    retorno=0;
                }
            }
        }while(retorno==-1);
    }
    return retorno;
}

int isValidFloat (char* cadena)
{
    int retorno = TRUE;
    int i;
    int contador=0;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] < '0' || cadena[i] > '9'))
        {
            if(i==0 && cadena[i]=='-')
            {
                continue;
            }
            if(contador==0 && cadena[i]=='.')
            {
                contador++;
                continue;
            }
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

void clean(void)
{
    system("cls");
}

void pauseClean(void)
{
    system("pause");
    system("cls");
}

//--------------------------------------------------------------------------------------------------

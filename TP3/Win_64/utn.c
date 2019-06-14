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

int getChar ( char* msg,char* msgError,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)<2)
            {
                strncpy(resultado,bufferStr,2);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}

int getFecha ( char* msg,char* msgError,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr) > 7 && strlen(bufferStr) < 9)
            {
                strncpy(resultado,bufferStr,9);
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

int utn_getName (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
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
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            if(cadena[i] == ' ')
            {
                retorno = FALSE;
            }
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getChar (char* msg,char* msgError,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && reintentos>=0 && resultado != NULL)
    {
        if(!getChar(msg,msgError,reintentos,bufferStr))
        {
            if(isValidChar(bufferStr))
            {
                strncpy(resultado, bufferStr,2);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidChar (char* cadena)
{
    int retorno = TRUE;
    if((*cadena > 'Z' || *cadena < 'A') && (*cadena > 'z' || *cadena < 'a')  )
    {
        retorno = FALSE;
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getSexo (char* msg,char* msgError,int reintentos,char* resultado) //CADENA= &VARIABLE
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && reintentos>=0 && resultado != NULL)
    {
        if(!getChar(msg,msgError,reintentos,bufferStr))
        {
            if(isValidSexo(bufferStr))
            {
                strncpy(resultado, bufferStr,2);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidSexo (char* cadena)
{
    int retorno = TRUE;
    if(*cadena != 'M' && *cadena != 'm' && *cadena != 'F' && *cadena != 'f')
    {
        retorno = FALSE;
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getInter(char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidInter(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidInter (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] < '0' || cadena[i] > '9'))
        {
            if( (i==0 && cadena[i]=='-') )
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

int utn_getPositiveInter(char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidPositiveInter(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidPositiveInter (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] < '0' || cadena[i] > '9'))
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getFloat(char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidFloat(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

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
        if(contador<1&&cadena[i]=='.')
        {
            contador++;
            continue;
        }
        if((cadena[i] < '0' || cadena[i] > '9'))
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getEmail(char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidEmail(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidEmail (char* cadena)
{
    int retorno = TRUE;
    int contador1=0;
    int contador2=0;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if(contador1<1&&cadena[i]=='@')
        {
            contador1++;
            continue;
        }
        if(contador2<2&&cadena[i]=='.')
        {
            contador2++;
            continue;
        }
        if( (cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a') )
        {
            retorno = FALSE;
            break;
        }
    }
    if(contador1==0 || contador2==0)
    {
        retorno=FALSE;
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getTelephone(char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidTelephone(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidTelephone (char* cadena)
{
    int retorno = TRUE;
    int contador=0;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if(contador<2&&cadena[i]=='-')
        {
            contador++;
            continue;
        }
        if((cadena[i] < '0' || cadena[i] > '9'))
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getFecha (char* msg,char* msgError,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && reintentos>=0 && resultado != NULL)
    {
        if(!getFecha(msg,msgError,reintentos,bufferStr))
        {
            if(isValidFecha(bufferStr))
            {
                strncpy(resultado, bufferStr,9);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidFecha (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if(i==2&&cadena[i]=='/')
        {
            continue;
        }
        if(i==5&&cadena[i]=='/')
        {
            continue;
        }
        if((cadena[i] < '0' || cadena[i] > '9'))
        {
            retorno = FALSE;
            break;
        }
    }
    if(cadena[0]=='3'&&cadena[1]>'1')
    {
        retorno=FALSE;
    }
    if(cadena[3]>'1')
    {
        retorno=FALSE;
    }
    if(cadena[3]=='1'&&cadena[4]>'2')
    {
        retorno=FALSE;
    }
    if( (cadena[0]=='0'&&cadena[1]=='0') || (cadena[3]=='0'&& cadena[4]=='0') )
    {
        retorno=FALSE;
    }
    return retorno;
}


//--------------------------------------------------------------------------------------------------

int utn_getAlphaNumerico (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidAlphaNumerico(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int isValidAlphaNumerico (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if(cadena[i]==' ')
        {
            continue;
        }
        if( (cadena[i] < '0' || cadena[i] > '9') && (cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a') )
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------

int utn_getDni (char* msg,char* msgError,int minimo,int maximo,int reintentos,char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidTelephone(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}
int isValidDni (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if( (cadena[i] < '0' || cadena[i] > '9') )
        {
            if(cadena[i]=='.')
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

void utn_clean(void)
{
    system("cls");
}

void utn_pauseClean(void)
{
    system("pause");
    system("cls");
}

//--------------------------------------------------------------------------------------------------

void menu()
{
    printf("**Menu**\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf(" 3. Alta de empleado\n");
    printf(" 4. Modificar datos de empleado\n");
    printf(" 5. Baja de empleado\n");
    printf(" 6. Listar empleados\n");
    printf(" 7. Ordenar empleados\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");











}

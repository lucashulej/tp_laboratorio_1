#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#define TRUE 1
#define FALSE 0

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);

//-------------------------------------

int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);

int isValidName (char* cadena);

//-------------------------------------

int getInter(char* msg,char* msgError,int minimo,int maximo,int* resultado);

int isValidInter (char* cadena);

//-------------------------------------

int getFloat(char* msg,char* msgError,int minimo,int maximo,float* resultado);

int isValidFloat (char* cadena);

//-------------------------------------

void clean(void);

void pauseClean(void);

//-------------------------------------

#endif // UTN_H_INCLUDED

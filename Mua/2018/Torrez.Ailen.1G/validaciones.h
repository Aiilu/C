#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "clientes.h"

int function_ValidaSexo(char msj[],char input[]);
int function_getStringLetras(char msj[],char input[]);
void function_getString (char msj[],char input[]);
int function_esSoloLetras(char str[]);
int function_esTelefono(char msj[],char str[]);
float getFloat(char msj[]);
int function_getInt(char msj[] );
char function_getChar(char msj[]);
int function_esNum(char str[]);
int function_getStringNumeros(char msj[],char input[]);
char function_getCharSexo(char msj[]);

#endif // VALIDACIONES_H_INCLUDED

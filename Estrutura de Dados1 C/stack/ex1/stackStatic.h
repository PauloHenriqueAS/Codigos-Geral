#ifndef stackStatich
#define stackStatich

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define EMPTY -3
#define FULL 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"

typedef struct TStackS Stack;

Stack *stack_create();//OK
int stack_free(Stack *st);//OK
int stack_push(Stack *st, struct aluno al);//OK
int stack_pop(Stack *st);//OK
int stack_top(Stack *st, struct aluno *al);//OK
int stack_size(Stack *st);//OK

#endif
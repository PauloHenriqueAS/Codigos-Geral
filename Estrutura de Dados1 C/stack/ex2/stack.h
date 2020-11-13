#ifndef stackh
#define stackh

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define NOT_EMPTY -3

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"

typedef struct TStack TStack;

TStack *stack_create();//OK
int stack_free(TStack *st);
int stack_push(TStack *st, struct aluno al);//OK
int stack_pop(TStack *st);//OK
int stack_top(TStack *st, struct aluno *al);
int stack_size(TStack *st);//OK
int stack_empty(TStack *st);//OK

#endif 
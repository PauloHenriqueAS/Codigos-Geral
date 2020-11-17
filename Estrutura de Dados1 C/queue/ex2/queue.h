#ifndef queueh
#define queueh

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "aluno.h"
#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define EMPTY -3

typedef struct queue Queue;

Queue *create_queue();//OK
int free_queue(Queue *dq);//OK
int push_queue(Queue *dq, struct aluno al);//OK
int pop_queue(Queue *dq);//OK
int size_queue(Queue *dq);//OK
int first_queue(Queue *dq, struct aluno *al);//OK

#endif
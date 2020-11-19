#ifndef circListh
#define circListh

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "aluno.h"

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define ELEMENT_NOT_FOUND -2
#define OUT_OF_RANGE -3
#define OUT_OF_MEMORY -4

typedef struct circList List;

List* create_circ();//OK
int free_circ(List *li);//OK
int push_front_circ(List *li, struct aluno al);//OK
int push_back_circ(List *li, struct aluno al);//OK
int pop_front_circ(List *li);//OK
int pop_back_circ(List *li);//OK
int size_circ(List *li);//OK
int front_circ(List *li, struct aluno *al);//OK
int back_circ(List *li, struct aluno *al);//OK
int print_circ(List *li);//OK
int get_pos_circ(List *li, int pos, struct aluno *al);//OK
int get_mat_circ(List *li, int nmat, struct aluno *al);//OK
int next_circ(List *li, struct aluno *al);//OK
int insert_circ(List *li, int pos, struct aluno al);//OK
int erase_circ(List *li, int pos);//OK

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4


struct aluno{
  int matricula;
  char nome[50];
  float n1,n2,n3;
};

typedef struct list List;

List* list_create();//OK
int list_free(List *li);//OK
int list_push_front(List *li, struct aluno al);//OK
int list_push_back(List *li, struct aluno al);//OK
int list_insert(List *li, int pos, struct aluno al);//OK
int list_insert_sorted(List *li, struct aluno al);//OK
int list_size(List *li);//OK
int list_pop_front(List *li);//OK
int list_pop_back(List *li);//OK
int list_erase(List *li, int pos);//OK
int list_find_pos(List *li, int pos, struct aluno *al);//OK
int list_find_mat(List *li, int nmat, struct aluno *al);//OK
int list_front(List *li, struct aluno *al);//OK
int list_back(List *li, struct aluno *al);//OK
int list_get_pos(List *li, int nmat, int *pos);//OK
int list_print(List *li);//OK
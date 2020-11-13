#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FULL 1
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define EMPTY -3
#define MAX 100

typedef struct stackChar Stack;

//------Funcoes----
Stack *create_stack(int size);//OK
int free_stack(Stack *st);
int push_stack(Stack *st, char caracter);//OK
int pop_stack(Stack *st);//OK
int top_stack(Stack *st, char *caracter);//OK //consultar quem esta no top da pilha 
int size_stack(Stack *st);//OK


void print(Stack *st);

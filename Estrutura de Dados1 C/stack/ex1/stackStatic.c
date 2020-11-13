#include "stackStatic.h"
#include "listaSequenciada.h"

struct TStackS{
    Lista *data;
};


//---------------CREATE--------------
Stack *stack_create(){

  Stack *st;
  st = malloc(sizeof(Stack));

  if(st != NULL){
    st->data = cria_lista();
    if(st->data == NULL){
      free(st);
      st = NULL;
    }
  }
  return st;
}

//--------------FREE------------------
int stack_free(Stack *st){
  if(st == NULL){
    return INVALID_NULL_POINTER;
  }else{
    int aux = libera_lista(st->data);
    free(st);
    return SUCCESS;
  }
}

//--------------PUSH-----------------
int stack_push(Stack *st, struct aluno al){
  if(st == NULL){
    return INVALID_NULL_POINTER;
  }else{
     return insere_lista_inicio(st->data,  al);
  }
}

//--------------POP------------------
int stack_pop(Stack *st){
  if(st == NULL){
    return INVALID_NULL_POINTER;
  }else{
    return remove_lista_inicio(st->data);
  }
}

//--------------TOP------------------
int stack_top(Stack *st, struct aluno *al){
  if(st == NULL){
    return INVALID_NULL_POINTER;
  }else{
    return consulta_lista_pos(st->data, 1, al);
  }
}

//--------------SIZE------------------
int stack_size(Stack *st){
  if(st == NULL){
    return INVALID_NULL_POINTER;
  }else{
    int aux = tamanho_lista(st->data);
    if(aux == 0){
      return EMPTY;
    }else{
      if(aux == MAX){
        return FULL;
      }else{
        return aux;
      }
    }
  }
}
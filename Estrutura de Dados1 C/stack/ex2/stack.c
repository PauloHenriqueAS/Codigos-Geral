#include "stack.h"
#include "linkedList.h"

struct TStack{
    List *data;
};

//-----------------CREATE-------------------OK
TStack *stack_create(){

    TStack *st;
    st = malloc(sizeof(TStack));

    if(st != NULL){
        st->data = list_create();
        if(st->data == NULL){
            free(st);
            st = NULL;
        }
    }
    return st;
}

//-----------------PUSH-------------------OK
int stack_push(TStack *st, struct aluno al){
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }else{
       return list_push_back(st->data,al);
    }
}

//-----------------POP-------------------OK
int stack_pop(TStack *st){
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }else{
        int aux = list_pop_back(st->data);
        return aux;
    }
}


//-----------------TOP-------------------OK
int stack_top(TStack *st, struct aluno *al){
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }else{
        int aux;
        aux = list_back(st->data, al);
        if(aux == 0){
            return SUCCESS;
        }else{
            return OUT_OF_MEMORY;
        }
    }
}

//-----------------SIZE-------------------OK
int stack_size(TStack *st){
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }else{
        int aux;
        aux = list_size(st->data);
        return aux;
    }
}

//-----------------EMPTY-------------------OK
int stack_empty(TStack *st){
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }else{
        /*
        if(st->data == 0){
            return SUCCESS;
        }else{
            return NOT_EMPTY;
        }*/
        int aux = list_size(st->data);
        if(aux == 0){
            return SUCCESS;
        }else{
            return NOT_EMPTY;
        }
    }
}

//-----------------FREE-------------------OK
int stack_free(TStack *st){
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }else{
        int aux;
        aux = list_free(st->data);
        if(aux == 0){
            free(st);
        }
        return SUCCESS;
    }
}
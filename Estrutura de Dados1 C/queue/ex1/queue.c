#include "queue.h"
#include "linkedList.h"

typedef struct dqnode DQnode;

struct queue{
    List *data;
};


//-------------------CREATE---------------------------
Queue *create_queue(){

    Queue *dq;
    dq = malloc(sizeof(Queue));

    if(dq != NULL){
        dq->data = list_create();
        if(dq->data == NULL){
            free(dq);
            dq = NULL;
        }
    }
    return dq;
}

//-------------------FREE---------------------------
int free_queue(Queue *dq){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        int aux;
        aux = list_free(dq->data);
        if(aux == 0){
            free(dq);
        }
        return SUCCESS;
    }
}

//-------------------PUSH---------------------------
int push_queue(Queue *dq, struct aluno al){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        return list_push_back(dq->data, al);
    }
}

//-------------------POP---------------------------
int pop_queue(Queue *dq){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        return list_pop_front(dq->data);
    }
}

//-------------------SIZE---------------------------
int size_queue(Queue *dq){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        int aux = list_size(dq->data);
        if(aux == 0){
            return EMPTY;
        }else{
            return aux;
        }
    }
}

//-------------------POP---------------------------
int first_queue(Queue *dq, struct aluno *al){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        return list_front(dq->data, al);
    }
}
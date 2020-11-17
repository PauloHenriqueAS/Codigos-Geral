#include "queue.h"

typedef struct dqnode DQnode;

struct queue{
    DQnode *first;
    DQnode *last;
    int size;
};

struct dqnode{
    struct aluno data;
    DQnode *next;
};

//-------------------CREATE---------------------------
Queue *create_queue(){
    
    Queue *dq;
    dq = malloc(sizeof(Queue));
    if(dq != NULL){
        dq->size = 0;
        dq->first = NULL;
        dq->last = NULL;
    }

    return dq;
}

//-------------------FREE---------------------------
int free_queue(Queue *dq){
    if(dq == NULL){
        //verifica se a fila não esta null
        return INVALID_NULL_POINTER;
    }else{
        if(dq->size == 0){
            free(dq);
            return SUCCESS;
        }else{
            int auxI=1;
            DQnode *aux = dq->first, *auxF;

            while(auxI != dq->size && aux != NULL){
                auxF = aux;
                aux = aux->next;
                free(auxF);
                auxI++;
            }//while

            free(dq);
            return SUCCESS;
        }
    }
}

//Insere no final
//-------------------PUSH---------------------------
int push_queue(Queue *dq, struct aluno al){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        DQnode *node;
        node = malloc(sizeof(DQnode));

        if(node == NULL){
            return OUT_OF_MEMORY;
        }//if verificação node
        
        node->data = al;

        if(dq->first == NULL){
            //Primeira posição
            dq->first = node;
            dq->last = node;
            node->next = NULL;
            dq->size = dq->size + 1;
            return SUCCESS;
        }else{
            //Inserir no final
            DQnode *aux = dq->last;
            aux->next = node;
            dq->last = node;
            node->next = NULL;
            dq->size++;
            return SUCCESS;
        }
    }
}

//Retira do inicio
//-------------------POP---------------------------
int pop_queue(Queue *dq){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(dq->size == 1){
            //Se existir somente 1 elemento na fila
            DQnode *aux = dq->first;
            free(aux);
            dq->first = NULL;
            dq->last = NULL;
            dq->size = 0;

            return SUCCESS;
        }

        //Outros casos
        DQnode *aux = dq->first, *auxF;
        aux = aux->next;
        auxF = dq->first;

        free(auxF);
        dq->first = aux;
        dq->size--;

        return SUCCESS;
    }
}

//-------------------SIZE---------------------------
int size_queue(Queue *dq){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(dq->size == 0){
            return EMPTY;
        }else{
            return dq->size;
        }
    }
}

//-------------------First-on-Queue---------------------------
int first_queue(Queue *dq, struct aluno *al){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(dq->first == NULL){
            //Se não tiver ninguém na fila
            return EMPTY;
        }

        DQnode *aux = dq->first;
        *al = aux->data;
        return SUCCESS;
    }
}
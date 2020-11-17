#include "queue.h"

typedef struct dqnode DQnode;

struct queue{
    int front;
    int rear;
    int size;
    struct aluno data[MAX];
    int size_vet;
};

//-------------------CREATE---------------------------
Queue *create_queue(int size){

    Queue *dq;
    dq = malloc(size*sizeof(Queue));
    if(dq != NULL){
        dq->size = 0;
        dq->front = 0;
        dq->rear = 0;
        dq->size_vet = size;
    }
    return dq;
}

//-------------------FREE---------------------------
int free_queue(Queue *dq){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        free(dq);
        return SUCCESS;
    }
}

//-------------------PUSH---------------------------
int push_queue(Queue *dq, struct aluno al){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(dq->front == 0){
            dq->data[0] = al;
            dq->rear++;
            dq->size++;
            return SUCCESS;
        }else{
            if(dq->size == dq->size_vet ){
                int aux;
                aux = realloc_queue(dq);
            }

            int aux = dq->rear;
            //rear esta na posição final onde podemos inserir o al
            dq->data[aux] = al;
            dq->size++;
            dq->rear++;
            return SUCCESS;
        }
    }
}

//-------------------POP---------------------------
int pop_queue(Queue *dq){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(dq->size == 1){
            //primeira posição
            dq->front++;
            dq->rear++;
            dq->size = 0;
            return SUCCESS;
        }else{
            if(dq->rear == dq->size_vet){
                //se rear igual ao size inserido pelo usuario
                dq->rear = (dq->rear+1)%dq->size_vet;
            }

            if(dq->front == dq->size_vet){
                //se front igual ao size inserido pelo usuario
                    dq->front = (dq->front+1)%dq->size_vet;
            }

            dq->size--;
            dq->front++;
            
            return SUCCESS;
        }
    }
}

//-------------------SIZE---------------------------
int size_queue(Queue *dq){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        int aux = dq->size;
        if(aux == 0){
            return EMPTY;
        }else{
            return aux;
        }
    }
}


//-------------------FIRST---------------------------
int first_queue(Queue *dq, struct aluno *al){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        int aux = dq->front;
        *al = dq->data[aux];
        return SUCCESS;
    }
}

//-------------------REALLOC---------------------------
int realloc_queue(Queue *dq){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        int auxSize = dq->size_vet*2;
        dq = realloc(dq, auxSize*sizeof(Queue));

        dq->size_vet = auxSize;
        
    //jogar todo mundo pro inincio e o rear pro inicio
        int i, j = dq->front;
        for(i=0; i<dq->size; i++){
            dq->data[i] = dq->data[j];
            j++;
        }
        dq->front = 0;  
        dq->rear = i;
    
        return SUCCESS;
    }
}

//-------------------COMPACT---------------------------
int compact_queue(Queue *dq){
    if(dq == NULL){
        return INVALID_NULL_POINTER;
    }else{
        int auxSize = dq->size, aux=2;
        aux = ceil(auxSize*100)/100;
        
        //parte para realocar 
        dq = realloc(dq, aux*sizeof(Queue));

        dq->size_vet = aux;

        int i, j = dq->front;
        for(i=0; i<dq->size; i++){
            dq->data[i] = dq->data[j];
            j++;
        }
        dq->front = 0;
        dq->rear = i;
        
        return SUCCESS;
    }
}

//-------------------PRINT------------------------
void print_queue(Queue *dq){
   if(dq == NULL)
     return;
   int i = dq->front;
   for(; i<=dq->size; i++){
       printf("Matricula: %d", dq->data[i].matricula);
       printf("\nNome: %s", dq->data[i].nome);
       printf("\nNotas: %f, %f, %f", dq->data[i].n1,
                               dq->data[i].n2,
                               dq->data[i].n3);
  printf("\n---------------------------------------------\n");
   }
}
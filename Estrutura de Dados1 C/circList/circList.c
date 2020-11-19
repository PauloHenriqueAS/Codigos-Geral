#include "circList.h"

typedef struct cListNode CircNode;

struct circList{
    CircNode *end;
    CircNode *next;
    int size;
};

struct cListNode{
    struct aluno data; 
    CircNode *next;
};

//--------------------CREATE----------------------------------
List* create_circ(){

    List *li;
    li = malloc(sizeof(List));

    if(li != NULL){
        li->next = NULL;
        li->end = NULL;
        li->size = 0;
    }

    return li;
}

//--------------------FREE----------------------------------
int free_circ(List *li){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{
        CircNode *aux, *aux2;
        aux = li->end->next;//vai comecar no inicio/head

        while(aux != li->end){//comeca no inicio e vai ate aparar no end
            aux2 = aux;
            aux = aux->next;
            free(aux2);     
        }        
        free(aux);
        li->next = NULL;
        li->size = 0;
        return SUCCESS;
    }
}

//--------------------PUSH-FRONT----------------------------------
int push_front_circ(List *li, struct aluno al){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{

        CircNode *node;
        node = malloc(sizeof(CircNode));
        if(node == NULL){
            return OUT_OF_MEMORY;
        }
        node->data = al;

        if(li->size == 0){
            li->end = node;
            node->next = NULL;
            li->size = 1;
            li->next = node;
            return SUCCESS;
        }

        if(li->size == 1){
            li->end->next = node;
            node->next = li->end; 
            li->size = li->size + 1;
            //li->next = li->end->next;
            return SUCCESS;
        }


        node->next = li->end->next;//node->next passa a apontar o antigo head
        li->end->next = node;
        li->size++;
        //li->next = li->end->next;

        return SUCCESS;
    }
}

//--------------------PUSH-BACK----------------------------------
int push_back_circ(List *li, struct aluno al){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{

        CircNode *node;
        node = malloc(sizeof(CircNode));
        if(node == NULL){
            return OUT_OF_MEMORY;
        }
        node->data = al;

        if(li->size == 0){//primeira inserção
            li->end = node;
            node->next = NULL;
            li->size++;
            li->next = node;
            return SUCCESS;
        }

        if(li->size == 1){//segunda inserção
            node->next = li->end->next;
            li->end->next = node;
            li->end = node;
            li->size++;
            return SUCCESS;
        }
        node->next = li->end->next;
        li->end->next = node;
        li->end = node;
        li->size++;
        
        return SUCCESS;
    }
}

//--------------------POP-FRONT----------------------------------
int pop_front_circ(List *li){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{

        if(li->size == 0){
            return ELEMENT_NOT_FOUND;
        }

        if(li->size == 1){
            free(li->end);
            li->end= NULL;
            li->size = 0;
            return SUCCESS;
        }

        CircNode *aux;
        
        aux = li->end->next;//aponta pro inicio
        li->end->next = aux->next;//aponta para o novo inicio

        if(li->next == aux){
            li->next = aux->next;
        }

        free(aux);
        li->size--;

        return SUCCESS;
    }
}

//--------------------POP-BACK----------------------------------
int pop_back_circ(List *li){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(li->size == 0){
            return ELEMENT_NOT_FOUND;
        }

        if(li->size == 1){
            free(li->end);
            li->end = NULL;
            li->size = 0;
            return SUCCESS;
        }

        CircNode *aux, *aux2;
        aux = li->end->next;

        if(li->next == li->end){
            li->next = li->end->next;
        }

        while(aux->next != li->end){ //aux para um no antes do li->end
            aux = aux->next;
        }

        aux2 = aux;
        aux = li->end;
        aux2->next = li->end->next;
        li->end = aux2;
        free(aux);
        li->size--;
        return SUCCESS;
    }
}

//--------------------SIZE----------------------------------
int size_circ(List *li){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{
        return li->size;
    }
}

//--------------------FRONT----------------------------------
int front_circ(List *li, struct aluno *al){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(li->size == 0){
            return ELEMENT_NOT_FOUND;
        }
        if(li->size == 1){
            CircNode *aux = li->end;
            *al = aux->data;
            return SUCCESS;
        }

        CircNode *aux;
        aux = li->end->next;//equivalente a head

        *al = aux->data;

        return SUCCESS;
    }
}

//--------------------BACK----------------------------------
int back_circ(List *li, struct aluno *al){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(li->size == 0){
            return ELEMENT_NOT_FOUND;
        }
 
        *al = li->end->data;

        return SUCCESS;
    }
}

//--------------------PRINT----------------------------------
int print_circ(List *li){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{
        CircNode *aux;
        aux = li->end->next;

        while(aux != li->end){
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Nota1 = %f, Nota2 = %f, Nota3 = %f\n", aux->data.n1, aux->data.n2, aux->data.n3);
            aux = aux->next;
        }

        return SUCCESS;
    }
}

//--------------------GET-POS----------------------------------
int get_pos_circ(List *li, int pos, struct aluno *al){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(li->size == 0 || pos <= 0 || pos > li->size){
            return OUT_OF_RANGE;
        }       

        if(pos == 1){
            *al = li->end->next->data;
            return SUCCESS;
        }

        if(pos == li->size){
            *al = li->end->data;
        }

        int aux = 0;
        CircNode *node_aux = li->end->next;

        while(aux != pos){
            node_aux = node_aux->next;
            aux++;
        }

        *al = node_aux->data;

        return SUCCESS;
    }
}

//--------------------GET-MAT----------------------------------
int get_mat_circ(List *li, int nmat, struct aluno *al){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{
        
        if(li->end == NULL ){
            return OUT_OF_RANGE;
        }

        CircNode *aux_node;
        aux_node = li->end->next;//inicio

        int aux=0;
        while( nmat != aux_node->data.matricula &&  aux_node != li->end){
            aux_node = aux_node->next;
        }

        if(nmat == aux_node->data.matricula){
            *al = aux_node->data;
            return SUCCESS;
        }else{
            return ELEMENT_NOT_FOUND;
        }
        
    }
}

//--------------------NEXT----------------------------------
//retorna data do li->next e dps aponta para o proximo
int next_circ(List *li, struct aluno *al){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{
        *al = li->next->data;
        li->next = li->next->next;
        return SUCCESS;
    }
}

//--------------------INSERT----------------------------------
//inserir em uma posição
int insert_circ(List *li, int pos, struct aluno al){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(pos > li->size || pos <= 0){
            return OUT_OF_RANGE;
        }

        CircNode *node, *node_aux;
        node = malloc(sizeof(CircNode));
        if(node == NULL){
            return OUT_OF_MEMORY;
        }

        node->data = al;
        node_aux = li->end->next;

        int aux = 0;
        while(aux != pos-1 && node_aux != li->end){
            node_aux = node_aux->next;
            aux++;
        }

        //para uma posição antes 
        node->next = node_aux->next;
        node_aux->next = node;
        li->size++;
        return SUCCESS;
    }
}

//--------------------ERASE----------------------------------
//remove de uma posição
int erase_circ(List *li, int pos){
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }else{

        if(pos <=0 || pos > li->size || li->size == 0){
            return OUT_OF_RANGE;
        }

        CircNode *node_aux, *aux2;
        node_aux = li->end->next;

        int aux = 0;
        while(aux != pos-1 && node_aux != li->end){
            node_aux = node_aux->next;
            aux++;
        }

        //para um antes
        aux2 = node_aux->next;//node que deseja retirar 
        node_aux = aux2->next;//o anterior->next aponta para o next do no que sera retirado

        if(li->next == aux2){//se li->next for igual ao no a ser retirado
            li->next = node_aux;
        }
        free(aux2);
        li->size--;

        return SUCCESS;
    }
}
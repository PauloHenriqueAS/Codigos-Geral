#include "stackChar.h"

//tamanho da pilha e os dados
struct stackChar{
    char data[MAX];
    int size;
};

//------------------CREATE--------------------------------
Stack *create_stack(int size){

    Stack *st;
    st = malloc(size*sizeof(Stack));

    if(st != NULL){
        st->size = 0;
    }
    
    return st;
}

//------------------PUSH---------------------------------
int push_stack(Stack *st, char caracter){
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(st->size == MAX){
            return OUT_OF_MEMORY;
        }else{
            //inserino no inicio da pilha
            //precisa passar todos para prox posicao
            int i= st->size;

            while(i>0){
                st->data[i] = st->data[i-1];
                i--;
            }

            st->data[0] = caracter;//inseri na primeira posicao
            st->size = st->size + 1;
            return SUCCESS;
        }
    }
}

//------------------POP---------------------------------
int pop_stack(Stack *st){
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(st->size == 0){
            return EMPTY;
        }else{
          if(st->size == 1){
            st->size = 0;
          }
          //st->size == 1
            //retira do inicio
            int i=0;
            while(i <= st->size){
                st->data[i] = st->data[i+1];//ex vet[0] recebe valor de vet[1]
                i++;
            }

            st->size--;
            return SUCCESS;
        }
    }
}

//------------------TOP---------------------------------
int top_stack(Stack *st, char *caracter){
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(st->size == 0){
            return EMPTY;
        }else{
            //topo = ultimo primeiro elemento na pilha
            *caracter = st->data[0];
            return SUCCESS;
        }
    }
}

//------------------SIZE--------------------------------
int size_stack(Stack *st){
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }else{
        if(st->size == 0){
            return EMPTY;
        }else{
            if(st->size == MAX){
                return FULL;
            }else{
                return st->size;
            }
        }
    }
}

//------------------FREE-------------------------------
int free_stack(Stack *st){
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }else{
        free(st);
        return SUCCESS;
    }
}

//--------------------print------------------------
void print(Stack *st){
  int i=0;
  while(i <= st->size){
  printf("%c", st->data[i]);
  i++;
  }
  return ;
}

//------------------------------------------------
int insere_bem_formada(Stack *st, char string[]){
  if(st == NULL){
    return INVALID_NULL_POINTER;
  }else{
    char caracter;
    int i = 0, aux;

    for(; string[i] != '\0'; i++){
      switch(string[i]){
        case ')':
          if(size_stack(st) == 0){
            return EMPTY;
          }
          aux = top_stack(st, &caracter);
          if(caracter == '('){
            aux = pop_stack(st);
          }else{
            return -1;
          }
        break;

        case ']':
          if(size_stack(st) == 0){
            return EMPTY;
          }
          aux = top_stack(st, &caracter);
          if(caracter == '['){
           aux = pop_stack(st);
          }else{
            return -1;
          }
        break;

        default: push_stack(st, string[i]);
      }//switch
    }//for
    return st->size;
  }
}
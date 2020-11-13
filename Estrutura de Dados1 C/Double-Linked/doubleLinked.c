#include "doubleLinked.h"

typedef struct dlnode Dlnode;

//Estrutura da lista
struct doublelinked{
  Dlnode *begin;
  Dlnode *end;
  int size;
};


//Estrutura do no
struct dlnode{
  struct aluno data;
  Dlnode *next;
  Dlnode *prev;
};

//-----------------CREATE-------------------
List* list_create(){
  
  List *li;
  li = malloc(sizeof(List));
  
  if(li != NULL){
    li->begin = NULL;
    li->end = NULL;
    li->size = 0;
  }
  return li;
}

//-----------------FREE-------------------
int list_free(List *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }

  if(li->begin == NULL && li->end == NULL){
    free(li);
  }else{
  
  Dlnode *aux, *prev;
  aux = li->begin;

  while(aux->next != NULL){
    prev = aux;
    aux = aux->next;
    free(prev);
  }
  /*while(aux != NULL){

  }*/

  free(aux);
  free(li);
  li->size = 0;
  }
  return SUCCESS;
}

//-----------------Push-Front(insere)-------------------
// olhar inicio, meio, fim
int list_push_front(List *li, struct aluno al){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }else{
    Dlnode *node;
    node = malloc(sizeof(Dlnode));
    
  if(node == NULL){
    return OUT_OF_MEMORY;
  }
//se for a primeira insercao
  if(li->begin ==  NULL){
    node->prev = NULL;
    node->next = NULL;

    li->begin = node;
    li->end = node;   
  }else{
    Dlnode *aux;
    
    aux = li->begin;
    li->begin = node;
    node->prev = NULL;
    node->next = aux;
    aux->prev = node;
  }
  node->data = al;
  li->size = li->size +1;
  return SUCCESS;
  }
}

//-----------------Push-Back(insere)-------------------
// olhar inicio, meio, fim
int list_push_back(List *li, struct aluno al){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  
  Dlnode *node;
  node = malloc(sizeof(Dlnode));
  
  if(node == NULL){
    return OUT_OF_MEMORY;
  }
  if(li->end == NULL){
    node->prev = NULL;
    node->next = NULL;
    
    li->begin = node;
    li->end = node;
  }else{
    Dlnode *aux;

    aux = li->end;
    li->end = node;
    node->next = NULL;
    node->prev = aux;
    aux->next = node;
  }
  node->data = al;
  li->size = li->size +1;
  return SUCCESS;
}

//-----------------Insert(insere-posicao)-------------------
// olhar inicio, meio, fim
int list_insert(List *li, int pos, struct aluno al){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }

  if( (pos > li->size + 1) || pos <= 0){
      return OUT_OF_RANGE;
  }

  Dlnode *node;
  node = malloc(sizeof(Dlnode));

  if(node == NULL){
    return OUT_OF_MEMORY;
  }else{
     node->data = al;

     if(li->size == 0){
       //vazio
       li->size = 1;
       li->begin = node;
       li->end = node;

       node->next = NULL;
       node->prev = NULL;
     }else{
       if(pos == 1){
         //inicio
         node->next = li->begin;
         li->begin->prev = node;
         li->begin = node;
         node->prev = NULL;
         li->size = li->size + 1;
       }else{
         if(pos > li->size + 1){
           //final
           node->next = NULL;
           node->prev = li->end;
           li->end->next = node;
           li->end = node;
           li->size++;
         }else{
           //meio da lista
          //aux = 1 pois ao inserir um elemento na lista o size passa a ser 1
           int aux = 1, aux2 = 1;
            Dlnode *node_aux;
            node_aux = li->begin;

            while(aux != (pos-1) && aux2 <= li->size ){
              node_aux = node_aux->next;
              aux++;
              aux2++;
            }
          //insere em uma posicao ai pega o que estava ali e passa pra frente
            node->next = node_aux->next;
            node->prev = node_aux;
            node_aux->next = node;
            li->size++;
         }
       }
     }//primeiro else
  return SUCCESS;
  }
}

//-----------------List-Size-------------------
// olhar inicio, meio, fim
int list_size(List *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }else{
  
  int aux = 0;
  aux = li->size;
  return aux;
  }
}

//-----------------Pop-Front(retirar-do-inicio)-------------------
// olhar inicio, meio, fim
int list_pop_front(List *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  
  if(li->size == 0){
    return OUT_OF_RANGE;
  }else{
    if(li->size == 1){
      free(li->begin);
      li->end = NULL;
      li->begin = NULL;
      li->size = 0;
    }else{
  
    Dlnode *aux, *aux2;
    aux = li->begin;
    aux2 = aux->next;

    li->begin = aux2;
    aux2->prev = NULL;
    li->size = li->size - 1;
    free(aux);
    }
  }
  return SUCCESS;
}


//-----------------Pop-Back(retirar-do-fim)-------------------
// olhar inicio, meio, fim
int list_pop_back(List *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }

  if(li->size == 0){
    return OUT_OF_RANGE;
  }else{
    if(li->size == 1){
      free(li->end);
      li->end = NULL;
      li->begin = NULL;
      li->size = 0;
    }else{
    Dlnode *aux, *aux2;
    aux = li->end;
    aux2 = aux->prev;

    aux2->next = NULL;
    li->end = aux2;
    li->size = li->size - 1;
    free(aux);
    }
  }
  return SUCCESS;
}

//-----------------list_erase(retirar-posicao)-------------------
//--------->>>> olhar inicio, meio, fim
int list_erase(List *li, int pos){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  
  if(pos <= 0 || pos == li->size+1){
    return OUT_OF_RANGE;
  }

  if(li->size == 0){
    return OUT_OF_MEMORY;
    }else{
    if(pos == 1){
      //inicio
      Dlnode *aux;
      aux = li->begin;
      li->begin = aux->next;
      free(aux);
      li->begin->prev = NULL;
      li->size--;
      return SUCCESS;
    }else{
      if(pos == li->size){
        //fim
        Dlnode *aux = li->end;
        li->end = aux->prev;
        free(aux);
        li->end->next = NULL;
        li->size--;
        return SUCCESS;
      }else{
        //meio
        Dlnode *aux = li->begin,*aux2;
        int i=1;

        while(i != pos && aux != NULL){
          i++;
          aux = aux->next;
        }

        aux2 = aux->prev;
        aux2->next = aux->next;
        free(aux);
        li->size--;

        return SUCCESS;
      }
    }
  }
}


//-----------------Find-Pos(achar-posicao)-------------------
int list_find_pos(List *li, int pos, struct aluno *al){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }else{
    if(pos == 1){ 
      *al = li->begin->data;
      return SUCCESS;
    }else{
      if(pos == li->size){
        *al = li->end->data;
        return SUCCESS;
      }else{
        if(pos == 1 || pos == li->size+1){
          return OUT_OF_RANGE;
        }else{
          Dlnode *aux = li->begin;
          int i = 1;

          while(i != pos && aux != NULL){
            i++;
            aux = aux->next;
          }

          *al = aux->data;

          return SUCCESS;
        }
      }
    }
  }

  if(li->size == 0){
    return OUT_OF_MEMORY;
  }else{
    
  }
}

//-----------------Find-Mat-------------------
int list_find_mat(List *li, int nmat, struct aluno *al){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }else{
    if(nmat == li->begin->data.matricula){
      //inicio
      *al = li->begin->data;
      return SUCCESS;
    }else{
      if(nmat == li->end->data.matricula){
        //fim
        *al = li->end->data;
        return SUCCESS;
      }else{
        Dlnode *aux = li->begin;
        int aux_mat=1;

        while(aux != NULL && nmat != aux->data.matricula){
          aux_mat++;
          aux = aux->next;
        }

        if(aux_mat != nmat){
          return ELEM_NOT_FOUND;
        }else{

          *al = aux->data;
          return SUCCESS;
        }
      }
    }
  }
}

//-----------------Front-------------------
int list_front(List *li, struct aluno *al){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }else{
    if(li->begin == NULL){
      return ELEM_NOT_FOUND;
    }else{
      /*Dlnode *node_aux;
      node_aux = li->begin;*/

      al->matricula = li->begin->data.matricula;
      strcpy(al->nome, li->begin->data.nome);
      al->n1 = li->begin->data.n1;
      al->n2 = li->begin->data.n2;
      al->n3 = li->begin->data.n3;
      
      return SUCCESS;
      /*----OU ---
      al->matricula = node_aux->data.matricula;
      */
    }
  }
}

//-----------------Back-------------------
int list_back(List *li, struct aluno *al){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }else{
    if(li->end == NULL){
      return ELEM_NOT_FOUND;
    }else{
      al->matricula = li->end->data.matricula;
      //strcpy(destino, origem)
      strcpy(al->nome, li->end->data.nome);
      al->n1 = li->end->data.n1;
      al->n2 = li->end->data.n2;
      al->n3 = li->end->data.n3;

      return SUCCESS;
    }
  }
}

//-----------------Get-Pos-------------------
int list_get_pos(List *li, int nmat, int *pos){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }else{
    if(nmat == li->begin->data.matricula){
      //inicio
      *pos = 1;
      return SUCCESS;
    }else{
      if(nmat == li->end->data.matricula){
        //fim
        *pos = li->size;
        return SUCCESS;
      }else{
        int aux=1;
        Dlnode *node_aux = li->begin;

        while(nmat != node_aux->data.matricula && node_aux != NULL){
          aux++;
          node_aux = node_aux->next;
        }
        
        if(aux != nmat){
          return ELEM_NOT_FOUND;
        }

        *pos = aux;
        return SUCCESS;
      }
    }
  }
}//func

//-----------------Print-Forward-------------------
int list_print_forward(List *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }else{

    Dlnode *node_print;
    node_print = li->begin;

    while(node_print != NULL){
      printf("\nMatricula: %d", node_print->data.matricula);
      printf("\nNome: %s", node_print->data.nome);
      printf("\nNota1: %f, Nota2: %f, Nota3: %f\n", node_print->data.n1, node_print->data.n2, node_print->data.n3);
      node_print = node_print->next;
    }
    return SUCCESS;
  }//else
}

//-----------------Print-Reverse-------------------
int list_print_reverse(List *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }else{

    Dlnode *node_print;
    node_print = li->end;

    while(node_print != NULL){
      printf("\nMatricula: %d", node_print->data.matricula);
      printf("\nNome: %s", node_print->data.nome);
      printf("\nNota1: %f, Nota2: %f, Nota3: %f\n", node_print->data.n1, node_print->data.n2, node_print->data.n3);
      node_print = node_print->prev;
    }
    return SUCCESS;
  }//else
}

/*
ifndef serve para um arquivo chamar outro arquivo 2 vezes na primeiraa ele 'levanta a bandeira' ai na seguinda vez hr que ele chega no ifdef ele percebe que 'a bandeira ja estava levantada' entao ele pula/ignora*/
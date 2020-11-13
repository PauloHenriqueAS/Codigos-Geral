#include "linkedList.h"

typedef struct list_node list_node;

struct list_node{
  struct aluno data;
  struct list_node *next;
};

struct list {
  list_node *head;
  int size; // quantidade de elementos na lista
  int sorted; // indica se a lista é ordenada
};


//-----------------CREATE-------------------
List* list_create(){

  List *li;
  li = malloc(sizeof(List));

   if(li != NULL){
     li->head = NULL;
     li->size = 0;
      return li;
   }else{
     return NULL;
   }
}

//-----------------PUSH-FRONT(insere)-------------------
int list_push_front(List *li, struct aluno al){
  
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }

  list_node  *node;
  node = malloc(sizeof(list_node));

  if(node == NULL){
    return  OUT_OF_MEMORY;
  }else{

    if(li->head == NULL){
      li->head = node;
      node->data = al;
      node->next = NULL;
      li->size +=1;
      return  SUCCESS;
    }else{

      list_node *aux;
      aux = li->head;
      li->head = node;
      node->next = aux;
      li->size +=1;
      return SUCCESS;
    }
  }
}

//-----------------PUSH-BACK(insere)-------------------
int list_push_back(List *li, struct aluno al){
  if(li == NULL){
      return INVALID_NULL_POINTER;
    }

    list_node  *node;
    node = malloc(sizeof(list_node));

    if(node == NULL){
    return  OUT_OF_MEMORY;
  }else{

    if(li->head == NULL){
      li->head = node;
      node->data = al;
      node->next = NULL;
      li->size +=1;
      return  SUCCESS;

    }else{

      list_node *aux = li->head;
      while(aux->next != NULL){
          aux = aux->next;
      }
      aux->next = node;
      node->data = al;
      li->size +=1;

      return SUCCESS;
    }
  }
}


//-----------------INSERT-POS(insere)-------------------
int list_insert(List *li, int pos, struct aluno al){
  if(li == NULL){
      return INVALID_NULL_POINTER;
    }

    if(pos == 0){
      return OUT_OF_RANGE;
    }

    list_node  *node, *aux, *auxNext;
    node = malloc(sizeof(list_node));

    if(node == NULL){
      return OUT_OF_MEMORY;
    }
    node->data = al;
    
    if(pos == 1){
      node->next = li->head;
      li->head = node;
      return SUCCESS;
    }

    int aux2 = 1;
    aux = li->head;
   
    while(aux2 != (pos-1) && aux->next != NULL){
      aux = aux->next;
      aux2 += 1;
    }
    auxNext = aux->next;

    if(auxNext == NULL){
     aux->next = node;
     node->next = NULL;
     return SUCCESS;
    }
    
    aux->next = node;
    node->next = auxNext;

    return SUCCESS;
}

//-----------------INSERT-SORTED(insere-ordenado)-------------------
int list_insert_sorted(List *li, struct aluno al){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  
  list_node *node;
  node = malloc(sizeof(list_node));

  if(node == NULL){
   return OUT_OF_MEMORY;
  }else{
    node->data = al;

    if(li->head == NULL){
      li->head = node;
      node->next = NULL;
    }else{
      list_node *aux, *prev;
      aux = li->head;

      while(aux->next != NULL && aux->data.matricula < al.matricula){
        prev = aux;
        aux = aux->next;
      }
      if(aux == li->head){
        node->next = li->head;
        li->head = node;
      }
      prev->next = node;
      node->next =aux;
      li->size +=1;
      li->sorted +=1;
      
    }
    return SUCCESS;
  }
}


//-----------------SIZE-------------------
int list_size(List *li){
 if(li == NULL){
   return INVALID_NULL_POINTER;
 }

  int aux2 = 0;  
  
  while(aux2 != li->size){
    aux2 += 1;
  }
 
 return aux2;
}

//-----------------POP-FRONT(retira)-------------------
int list_pop_front(List *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }

  if(li->head == NULL){
    return ELEM_NOT_FOUND;
  }else{
    list_node *aux, *aux2;
    aux = li->head;
    aux2 = li->head;
    //aux = li->head->next;
    aux = aux->next;
  
    li->head = aux;

    free(aux2);
    li->size -=1;
    return SUCCESS;
  }
}

//-----------------POP-BACK(retira)-------------------
int list_pop_back(List *li){
 if(li == NULL){
    return INVALID_NULL_POINTER;
  }

  if(li->head == NULL){
    return ELEM_NOT_FOUND;
  }else{

    list_node *aux, *prev;
    aux = li->head;

    while(aux->next != NULL){
      prev = aux;
      aux = aux->next;
    }
    
    prev->next = NULL;
    free(aux);
    li->size -=1;
  }
  return SUCCESS;
}

//-----------------ERASE(retira-pos)-------------------
int list_erase(List *li, int pos){
  if(li == NULL){
   return INVALID_NULL_POINTER;
  }

  if(li->head == NULL){
    return OUT_OF_RANGE;
  }else{
  
  int aux2=1;
  list_node *aux, *prev, *next_node;
  aux = li->head;
  
  while(aux->next != NULL && aux2 != pos){
    prev = aux;
    aux = aux->next;
    aux2++;
   }
   next_node = aux->next;
   prev->next = next_node;
   free(aux);
   li->size -=1;
  }
  return SUCCESS;
}

//-----------------FIND-POS---------------------------
int list_find_pos(List *li, int pos, struct aluno *al){
  
  if( li == NULL){
    return  INVALID_NULL_POINTER;
  }
  
  if(li->head == NULL){
    return OUT_OF_RANGE;
  }else{
  
  int aux2=1;
  list_node *aux;
  aux = li->head;

   while(aux->next != NULL && aux2 != pos){
    aux = aux->next;
    aux2++;
   }
   if(aux2 != pos){
      return ELEM_NOT_FOUND;
    }
   
   *al = aux->data;
  }
  return  SUCCESS;
}

//-----------------FIND-MAT---------------------------
int list_find_mat(List *li, int nmat, struct aluno *al){
  if( li == NULL){
    return  INVALID_NULL_POINTER;
  }
  
  if(li->head == NULL){
    return OUT_OF_RANGE;
  }else{

    list_node *aux;
    aux = li->head;

    while(aux->next != NULL && nmat != aux->data.matricula){
      aux = aux->next;
    }

    if(nmat != aux->data.matricula){
      return ELEM_NOT_FOUND;
    }

    *al = aux->data;
  }
  return SUCCESS;
}

//-----------------FRONT---------------------------
int list_front(List *li, struct aluno *al){
  if( li == NULL){
    return  INVALID_NULL_POINTER;
  }
  
  if(li->head == NULL){
    return OUT_OF_RANGE;
  }else{
    
    list_node *aux;
    aux = li->head;
    
    *al = aux->data;
  }
  return SUCCESS;
}

//-----------------BACK---------------------------
int list_back(List *li, struct aluno *al){
  if( li == NULL){
    return  INVALID_NULL_POINTER;
  }
  
  if(li->head == NULL){
    return OUT_OF_RANGE;
  }else{

    list_node *aux;
    aux = li->head;

    while(aux->next != NULL){
      aux = aux->next;
    }

    *al = aux->data;
  }
  return SUCCESS;
}

//-----------------GET-POS---------------------------
int list_get_pos(List *li, int nmat, int *pos){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  
  if(li->head == NULL){
    return OUT_OF_RANGE;
  }else{
    
    list_node *aux;
    aux = li->head;
    int aux2=1;
    
    while(aux->next != NULL && nmat != aux->data.matricula){
      aux = aux->next;
      aux2 += 1;
    }
    if(nmat != aux->data.matricula){
      return ELEM_NOT_FOUND;
    }
    
    *pos = aux2;
  }
  return SUCCESS;
}

//-----------------PRINT---------------------------
int list_print(List *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }

  if(li->head == NULL){
    return OUT_OF_RANGE;
  }else{
    
    list_node *aux;
    aux = li->head;

    while(aux != NULL){
      printf("\nMatricula: %d", aux->data.matricula);
      printf("\nNome: %s", aux->data.nome);
      printf("\n nota1 %f, nota2 %f, nota3 %f", aux->data.n1, aux->data.n2, aux->data.n3);
      printf("\n--------------------------------------------------------\n");
      aux = aux->next;
    }
  }
  return SUCCESS;
}
//-----------------FREE---------------------------
int list_free(List *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  
  if(li->head == NULL){
    free(li);
  }else{

    list_node *aux, *prev;
    aux = li->head;
    
    while(aux->next != NULL){
      prev = aux;
      aux = aux->next;
      free(prev);
    }

    free(aux);
    free(li);
  }
  return SUCCESS;
}

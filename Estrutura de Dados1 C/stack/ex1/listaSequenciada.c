#include "listaSequenciada.h"

struct lista{
  int qtd;
  struct aluno dados[MAX];
};

//-------------------CRIA--------------------------
Lista *cria_lista(){
   Lista *li;
   li = malloc(sizeof(Lista));
     if(li != NULL)
       li->qtd = 0;

  return li;
}

//-------------------LIBERA--------------------------
int libera_lista(Lista* li){
  free(li);
  return 0;
}

//-------------------CONSULTA-POS------------------------
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
   //posicao = qtd-1
   if(li == NULL)
     return -1;

   if(pos <= 0 ||pos >li->qtd)
     return -2;

   int aux= pos-1;
   *al = li->dados[aux]; 

 return 0;
}

//-------------------CONSULTA-MAT------------------------
int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
  if(li == NULL)
    return -1;
  int i=0;
  //i nao pode passar de qtd E repete ate achar mat == dados.matricula
  while(i < li->qtd && li->dados[i].matricula != mat)
   i++;
  
  if(i == li->qtd)
    return -2;

  *al = li->dados[i];
  return 0;
}

//-------------------INSERE-FINAL------------------------
int insere_lista_final(Lista* li, struct aluno al){
  if(li == NULL)
     return -1;
  if(li->qtd == MAX)
     return -2;

  int aux = li->qtd;
  li->dados[aux] = al;
   
  li->qtd++;
  return 0;
}

//-------------------INSERE-INICIO------------------------
//passar cada elemento pra prox posicao e ai inserir
int insere_lista_inicio(Lista* li, struct aluno al){
  if(li == NULL)
    return -1;
  if(li->qtd == MAX)
    return -2;

  int i=li->qtd;
  while(i>0){
    li->dados[i] = li->dados[i-1];
    i--;
  }

  li->dados[0] = al;
  li->qtd++;
  return 0;
}

//-------------------ORDENADA------------------------
int insere_lista_ordenada(Lista* li, struct aluno al){
  if(li == NULL)
    return -1;
  if(li->qtd == MAX)
    return -2;
  
  int i=0, k=0;
  while(i<li->qtd && li->dados[i].matricula < al.matricula)
    i++;
  
  for(k=(li->qtd-1); k>=i; k--)
     li->dados[k+1] = li->dados[k];

  li->dados[i] = al;
  li->qtd++;

  return 0;
}

//-------------------REMOVE------------------------
int remove_lista(Lista* li, int mat){
  if(li == NULL)
    return -1;
  if(li->qtd == 0)//nao tem como retir nada de uma lista vazia
    return -2;

  int i=0;
   while(i<li->qtd && li->dados[i].matricula != mat)
    i++;
  
  if(i == li->qtd)//nao achou a matricula ent ja foi removido
    return 0;
 //achou o que deseja remover, entao colocamos o valor da prox posicao na anterior
 for(int k=i; k <li->qtd-1; i++)//qtd-1 pq qtd esta onde desejamos inserir a proxima informacao
    li->dados[i] = li->dados[i+1];
  
  li->qtd--;
 return 0;
}

//-------------------REMOVE-INICIO------------------------
int remove_lista_inicio(Lista* li){
  if(li == NULL)
    return -1;
  if(li->qtd == 0)//se qtd for 0 quer dizer que nao tem o que remover
    return 0;
  
  for(int i=0; i<li->qtd-1; i++)
   li->dados[i] = li->dados[i+1];

  li->qtd--;
  return 0;
}

//-------------------REMOVE-FINAL------------------------
int remove_lista_final(Lista* li){
  if(li == NULL)
    return -1;
  if(li->qtd == 0)//se qtd for 0 quer dizer que nao tem o que remover
    return -2;

  li->qtd--;
  return  0;
}

//-------------------TAMANHO-LISTA------------------------
int tamanho_lista(Lista* li){
  if(li == NULL)
    return -1;
  else
    return li->qtd;
}

//-------------------TAMANHO-CHEIA------------------------
int lista_cheia(Lista* li){//retorna true se lista cheia ou false lista vazia
  if(li == NULL)
    return -1;
  else
    return (li->qtd == MAX);
}

//-------------------TAMANHO-VAZIA------------------------
int lista_vazia(Lista* li){
  if(li == NULL)
    return -1;
  else 
    return (li->qtd == 0);
}

//-------------------IMPRIME------------------------
void imprime_lista(Lista* li){
   if(li == NULL)
     return;
   int i;
   for(i=0; i<li->qtd-1; i++){
       printf("Matricula: %d", li->dados[i].matricula);
       printf("\nNome: %s", li->dados[i].nome);
       printf("\nNotas: %f, %f, %f", li->dados[i].n1,
                               li->dados[i].n2,
                               li->dados[i].n3);
  printf("---------------------------------------------\n");
   }
}

//-------------------REMOVE-OTIMIZADO------------------------
int remove_lista_otimizado(Lista* li, int mat){
  if(li == NULL)
    return -1;
  if(li->qtd == 0)
    return -2;

  int i=0, aux= li->qtd-1;
  li->qtd--;
  
  while(i<li->qtd && li->dados[i].matricula != mat)//acha o que queremos retirar e pegamos o ultimo elemento e colocamos nele
    i++;
  if(i == li->qtd)//elemento nao encontrado
    return -2;

  li->dados[i] = li->dados[aux];
  
  return 0;
}


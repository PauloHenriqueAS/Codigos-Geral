#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSequenciada.h"
int menu(){
  int opc;
  printf("------------------TAD-Lista------------------\n");
  printf("1- Criar lista\n");
  printf("2- Consulta Lista Posicao\n");
  printf("3- Consulta Lista Matricula\n");
  printf("4- Insere Lista Final\n");
  printf("5- Insere Lista Incio\n");
  printf("6- Insere Lista Ordenada\n");
  printf("7- Remove Lista\n");
  printf("8- Remove Lista Incio\n");
  printf("9- Remove Lista Final\n");
  printf("10- Tamanho Lista\n");
  printf("11- Lista Cheia\n");
  printf("12- Lista Vazia\n");
  printf("13- Imprime Lista\n");
  printf("14- Remove Lista Ordenada\n");
  printf("15- Compactar Lista\n");
  printf("16- Libera Lista\n");
  printf("0- Sair\n");
  printf("Digite uma opcao: ");
  scanf("%d", &opc);
  printf("\n");
  return opc;
}

int main(void) {
  int tam, opc, aux;
  Lista *alunos_li;
  struct aluno aluno;
  int posi, mat, taman;
  taman = MAX;
  do{
    opc = menu();
    switch(opc){
      case 1:
       printf("------------------------------------\n");
        printf("Criar Lista\n");
        printf("Digite o tamanho maximo da lista: ");
          scanf("%d", &taman);
        alunos_li = cria_lista(taman);
        printf("Lista Criada\n");
       printf("------------------------------------\n");
      break;

      case 2:
      printf("------------------------------------\n");
        printf("Consulta Lista Posicao\n");
        printf("Deseja ascessar qual posicao da lista? ");
          scanf("%d", &posi);
        aux = consulta_lista_pos(alunos_li, posi, &aluno);
       //printf("returno = %d\n", aux);
        if(aux == 0){
        printf("Matricula: %d", aluno.matricula);
        printf("\nNome: %s", aluno.nome);
        printf("\nNota1 %.2f, Nota2 %.2f, Nota3: %.2f",aluno.n1, aluno.n2, aluno.n3);
        }else{
          printf("Posicao nao existe\n");
        }
      printf("------------------------------------\n");
      break;

      case 3:
      printf("------------------------------------\n");
        printf("Consulta Lista Matricula\n");
        printf("Deseja ascessar qual matricula da lista? ");
          scanf("%d", &mat);
        aux = consulta_lista_mat(alunos_li, mat, &aluno);
         //printf("returno = %d\n", aux);
        if(aux == 0){
        printf("Matricula: %d", aluno.matricula);
        printf("\nNome: %s", aluno.nome);
        printf("\nnota1 %.2f, Nota2 %.2f, Nota3: %.2f ", aluno.n1,aluno.n2,aluno.n3);
        }else{
          printf("Posicao nao existe\n");
        }
       printf("------------------------------------\n");
      break;

      case 4:
      printf("------------------------------------\n");
      printf("Insere Lista Final\n");
      printf("Digite a matricula: ");
        scanf("%d", &aluno.matricula);
      printf("Digite o nome: ");
        getchar();
        fgets(aluno.nome, sizeof(aluno.nome), stdin);
      printf("Digite a primeira nota: ");
        scanf("%f", &aluno.n1);
      printf("Digite a primeira nota: ");
        scanf("%f", &aluno.n2);
      printf("Digite a primeira nota: ");
        scanf("%f", &aluno.n3);

       aux = insere_lista_final(alunos_li, aluno);
       // printf("returno = %d\n", aux);
       printf("------------------------------------\n");
      break;
      
      case 5:
      printf("------------------------------------\n");
      printf("Insere Lista Incio\n");
      printf("Digite a matricula: ");
        scanf("%d", &aluno.matricula);
      printf("Digite o nome: ");
        getchar();
        fgets(aluno.nome, sizeof(aluno.nome), stdin);
      printf("Digite a primeira nota: ");
        scanf("%f", &aluno.n1);
      printf("Digite a primeira nota: ");
        scanf("%f", &aluno.n2);
      printf("Digite a primeira nota: ");
        scanf("%f", &aluno.n3);

       aux = insere_lista_inicio(alunos_li, aluno);
      
        //printf("returno = %d\n", aux);
       printf("------------------------------------\n");
      break;
      
      case 6:
      printf("------------------------------------\n");
      printf("Insere Lista Ordenada\n");
      printf("Digite a matricula: ");
        scanf("%d", &aluno.matricula);
      printf("Digite o nome: ");
        getchar();
      //fflush(stdin);
        fgets(aluno.nome, sizeof(aluno.nome), stdin);
      printf("Digite a primeira nota: ");
        scanf("%f", &aluno.n1);
      printf("Digite a primeira nota: ");
        scanf("%f", &aluno.n2);
      printf("Digite a primeira nota: ");
        scanf("%f", &aluno.n3);

       aux = insere_lista_ordenada(alunos_li, aluno);
        //printf("returno = %d\n", aux);
       printf("------------------------------------\n");
      break;

      case 7:
      //OLHAR
        printf("------------------------------------\n");
        printf("Remove Lista\n");
        printf("Deseja ascessar qual matricula da lista? ");
          scanf("%d", &mat);

        aux = remove_lista(alunos_li, mat);

       //printf("returno = %d\n", aux);
       printf("------------------------------------\n");
      break;
      
      case 8:
        printf("------------------------------------\n");
        printf("Remove Lista Incio\n");
        aux = remove_lista_inicio(alunos_li);

        //printf("returno = %d\n", aux);
        printf("Primeiro elemento da lista removido\n");
        printf("------------------------------------\n");
      break;

      case 9:
        printf("------------------------------------\n");
        printf("Remove Lista Final\n");
        aux = remove_lista_final(alunos_li);
       // printf("returno = %d\n", aux);
        printf("Ultimo elemento da lista removido\n");
        printf("------------------------------------\n");
      break;
      
      case 10:
      printf("------------------------------------\n");
        printf("Tamanho Lista\n");
        aux = tamanho_lista(alunos_li);
        if(aux == -1){
          printf("Erro!");
          break;
        }
        printf("O tamanho da lista e: %d", aux);
      printf("\n------------------------------------\n");
      break;

      case 11:
      printf("------------------------------------\n");
        printf("Lista Cheia\n");
        aux = lista_cheia(alunos_li);
        if(aux == MAX){
          printf("Lista Cheia");
          break;
        }if(aux == -1){
          printf("Erro!");
        }else{
          printf("Lista nao esta cheia\n");
        }
        //printf("returno %d\n", aux);
      printf("------------------------------------\n");
      break;

      case 12:
      printf("------------------------------------\n");
        printf("Lista Vazia\n");
        aux = lista_vazia(alunos_li);
        if(aux == 0){
          printf("Lista Vazia");
        }if(aux == -1){
          printf("Erro!");
        }else{
          printf("Lista nao esta vazia\n");
        }
       // printf("returno %d\n", aux);
      printf("------------------------------------\n");
      break;
      
      case 13:
      printf("------------------------------------\n");
        printf("Imprime Lista\n");
        imprime_lista(alunos_li);
      break;
      
      case 14:
      printf("------------------------------------\n");
        printf("Remove Lista Ordenada\n");
        printf("Deseja ascessar qual matricula da lista? ");
          scanf("%d", &mat);

        aux = remove_lista_otimizado(alunos_li, mat);
       // printf("returno %d\n", aux);
      printf("------------------------------------\n");
      break;

      case 15:
      printf("------------------------------------\n");
        printf("Compacta Lista\n");
        compactar_lista(alunos_li);
        printf("Lista Compactada\n");
      printf("------------------------------------\n");
      break;

      case 16:
      printf("------------------------------------\n");
        printf("Libera Lista\n");
        libera_lista(alunos_li);
        printf("Lista Liberada\n");
      printf("------------------------------------\n");
      printf("            PROGRAMA ENCERRADO\n");
      opc = 0;
      break;
      //testar dps do realocar_lista(Lista *li)
    }
  }while(opc != 0);

  return 0;
}
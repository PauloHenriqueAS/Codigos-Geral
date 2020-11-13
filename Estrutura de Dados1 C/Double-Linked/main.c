#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinked.h"

int menu(){
  int opc;
  printf("----------------Lista-Encadeada-Alunos-----------------------\n");
  printf("1- Criar Lista\n");
  printf("2- Inserir no inicio\n");
  printf("3- Inserir no final\n");
  printf("4- Inserir em uma posição\n");
  printf("5- Tamanho da lista\n");
  printf("6- Retirar do inicio\n");
  printf("7- Retirar do fim\n");
  printf("8- Apagar elemento de uma posição\n");
  printf("9- Pegar em posição\n");
  printf("10- Pegar em numero matricula\n");
  printf("11- Pegar primeiro elemento\n");
  printf("12- Pegar ultimo elemento\n");
  printf("13- Qual posição apartir da matricula\n");
  printf("14- Imprimir lista(inicio)\n");
  printf("15- Imprimir lista(fim)\n");
  printf("16- Liberar lista/encerrar programa\n");
  printf("Digite uma opcao: ");
  scanf("%d", &opc);
  
  printf("\n");
return opc;
}

int main(void) {
   
  int opc, aux, posicao, tamanho, nmat;
  List *lista_aluno, *lista;
  struct aluno aluno;

  do{
    opc = menu();
    switch(opc){

      case 1:
      
      printf("Criar lista!\n");
      lista_aluno = list_create();
      if(lista_aluno == NULL){
        printf("Lista nao criada!\n");
        opc = 0;
      }else{
        printf("Lista criada!\n");
      }
      break;

      case 2:
      printf("Inserir no inicio!\n");
      printf("Digite a matricula do aluno: ");
        scanf("%d", &aluno.matricula);
      printf("Digite o nome do aluno: ");
        getchar();
        fgets(aluno.nome, sizeof(aluno.nome), stdin);
      printf("Digite a nota1: ");
        scanf("%f", &aluno.n1);
      printf("Digite a nota2: ");
        scanf("%f", &aluno.n2);
      printf("Digite a nota3: ");
        scanf("%f", &aluno.n3);

      aux = list_push_front(lista_aluno, aluno);
      printf("Aux = %d\n", aux);
      break;

      case 3:
      printf("Inserir no final!\n");
      printf("Digite a matricula do aluno: ");
        scanf("%d", &aluno.matricula);
      printf("Digite o nome do aluno: ");
        getchar();
        fgets(aluno.nome, sizeof(aluno.nome), stdin);
      printf("Digite a nota1: ");
        scanf("%f", &aluno.n1);
      printf("Digite a nota2: ");
        scanf("%f", &aluno.n2);
      printf("Digite a nota3: ");
        scanf("%f", &aluno.n3);
      
      aux = list_push_back(lista_aluno, aluno);
      printf("Aux = %d\n", aux);
      break;
      
      case 4:

      printf("Inserir em posição!\n");
      printf("Digite a matricula do aluno: ");
        scanf("%d", &aluno.matricula);
      printf("Digite o nome do aluno: ");
        getchar();
        fgets(aluno.nome, sizeof(aluno.nome), stdin);
      printf("Digite a nota1: ");
        scanf("%f", &aluno.n1);
      printf("Digite a nota2: ");
        scanf("%f", &aluno.n2);
      printf("Digite a nota3: ");
        scanf("%f", &aluno.n3);
      printf("Digite a posição de deseja mexer: ");
        scanf("%d", &posicao);

      aux = list_insert(lista_aluno, posicao , aluno);
      printf("Aux = %d\n", aux);
      break;

      case 5:
      printf("Tamanho Lista!\n");
      tamanho = list_size(lista_aluno);
      printf("Tamanho da lista e: %d", tamanho);
      break;
      
      case 6:
      printf("Retirar do Inicio!\n");
      aux = list_pop_front(lista_aluno);
      printf("Aux = %d\n", aux);
      break;
      
      case 7:
      printf("Retirar do Final!\n");
      aux = list_pop_back(lista_aluno);
      printf("Aux = %d\n", aux);
      break;
      
      case 8:
      printf("Apagar Elemento Posição!\n");
      printf("Digite a posição que deseja retirar: ");
        scanf("%d", &posicao);
      aux = list_erase(lista_aluno, posicao);
      printf("Aux = %d\n", aux);
      break;
      
      case 9:
      printf("Pegar Posição!\n");
      printf("Digite a posição que deseja achar: ");
        scanf("%d", &posicao);
      aux = list_find_pos(lista_aluno, posicao, &aluno);
      printf("Aux = %d\n", aux);
      break;
      
      case 10:
      printf("Pegar Matricula!\n");
      printf("Digite a matricula que deseja achar: ");
        scanf("%d", &nmat);
      aux = list_find_mat(lista_aluno, nmat, &aluno);

      printf("\nMatricula: %d", aluno.matricula);
      printf("\nNome: %s", aluno.nome);
      printf("\n nota1 %f, nota2 %f, nota3 %f\n", aluno.n1, aluno.n2, aluno.n3);
      printf("Aux = %d\n", aux);
      break;
      
      case 11:
      printf("Pegar Primeiro Elemento!\n");
      aux = list_front(lista_aluno, &aluno);

      printf("\nMatricula: %d", aluno.matricula);
      printf("\nNome: %s", aluno.nome);
      printf("\n nota1 %f, nota2 %f, nota3 %f\n", aluno.n1, aluno.n2, aluno.n3);
      printf("Aux = %d\n", aux);
      break;
      
      case 12:
      printf("Pegar Ultimo Elemento!\n");
      aux = list_back(lista_aluno, &aluno);

      printf("\nMatricula: %d", aluno.matricula);
      printf("\nNome: %s", aluno.nome);
      printf("\n nota1 %f, nota2 %f, nota3 %f\n", aluno.n1, aluno.n2, aluno.n3);
      printf("Aux = %d\n", aux);
      break;

      case 13:
      printf("Pegar Posição!\n");
      printf("Digite a matricula que deseja achar: ");
        scanf("%d", &nmat);
      aux = list_get_pos(lista_aluno, nmat, &posicao);

      printf("Posição = %d\n", posicao);
      printf("Aux = %d\n", aux);
      break;

      case 14:
      printf("Imprimir Lista!\n");
      aux = list_print_forward(lista_aluno);
      printf("Aux = %d\n", aux);
      break;

      case 15:
      printf("Imprimir Lista!\n");
      aux = list_print_reverse(lista_aluno);
      printf("Aux = %d\n", aux);
      break;

      case 16:
      printf("Liberar Lista!\n");
      aux = list_free(lista_aluno);
      printf("Aux = %d\n", aux);
      opc = 0;
      break;
    }
  }while(opc != 0);
  return 0;
}
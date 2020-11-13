#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "stackStatic.h"

int menu(){
    int opcMenu;
    printf("\n----------------TAD-Pilha-------------\n");
    printf("1- Criar pilha\n");
    printf("2- Adicionar na pilha\n");
    printf("3- Remover da pilha\n");
    printf("4- Consultar ultimo elemento da pilha(top)\n");
    printf("5- Tamanho da pilha\n");
    printf("6- Liberar pilha/encerrar programa\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcMenu);
    printf("\n");
    return opcMenu;
}

int main(void) {
  printf("Hello World\n");
  return 0;
}
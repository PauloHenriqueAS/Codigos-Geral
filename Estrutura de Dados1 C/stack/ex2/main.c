#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "stack.h"

int menu(){
    int opcMenu;
    printf("\n----------------TAD-Pilha-------------\n");
    printf("1- Criar pilha\n");
    printf("2- Adicionar na pilha\n");
    printf("3- Remover da pilha\n");
    printf("4- Consultar ultimo elemento da pilha(top)\n");
    printf("5- Tamanho da pilha\n");
    printf("6- Pilha vazia\n");
    printf("7- Liberar pilha/encerrar programa\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcMenu);
    printf("\n");
    return opcMenu;
}

int main(){
  //printf("ola");
  
    int opc, aux;
    char caracter, top;
    TStack *pi;
    struct aluno aluno;

    do{
        opc = menu();
        switch (opc){

        case 1:
            printf("Criar Pilha!\n");
            pi = stack_create();
            if(pi != NULL){
                printf("Pilha criada!\n\n");
            }else{
                printf("Pilha não criada!\n");
            }
        break;
        
        case 2:
            printf("Adicionando na pilha!\n");
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

            aux = stack_push(pi, aluno);
            printf("Aux = %d\n", aux);
        break;

        case 3:
            printf("Remover da pilha!\n");
            aux = stack_pop(pi);
            printf("Aux = %d\n", aux);
        break;

        case 4:
            printf("Consultar Top!\n");
            aux = stack_top(pi, &aluno);

            printf("\nMatricula: %d", aluno.matricula);
            printf("\nNome: %s", aluno.nome);
            printf("\n nota1 %f, nota2 %f, nota3 %f\n", aluno.n1, aluno.n2, aluno.n3);
            printf("Aux = %d\n", aux);
        break;

        case 5:
            printf("Tamaho da pilha!\n");
            aux = stack_size(pi);
            printf("O tamanho da pilha e: %d\n", aux);
            printf("Aux = %d\n", aux);
        break;

        case 6:
            printf("Pilha Vazia?\n");
            aux = stack_empty(pi);

            if(aux == 0){
              printf("Pilha está  vazia!\n");
            }else{
              printf("Pilha não esta vazia!\n");
            }
        break;

        case 7:
            printf("Liberar pilha!\n");
            aux = stack_free(pi);
            printf("Aux = %d\n", aux);
            printf("Lista liberada\n");
            opc = 0;
        break;

        default:
            break;
        }
    }while(opc != 0);

    return 0;
}

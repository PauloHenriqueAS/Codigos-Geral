#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackChar.h"

int menu(){
    int opcMenu;
    printf("----------------TAD-Pilha-------------\n");
    printf("1- Criar pilha\n");
    printf("2- Adicionar na pilha\n");
    printf("3- Remover da pilha\n");
    printf("4- Consultar ultimo elemento da pilha(top)\n");
    printf("5- Tamanho da pilha\n");
    printf("6- Liberar pilha/encerrar programa\n");
    printf("7- Inserir-verificar expressão\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcMenu);
    printf("\n");
    return opcMenu;
}

int main(){
    int opc, tam, aux;
    char caracter, top, expre[20];
    Stack *pi;

    do{
        opc = menu();
        switch (opc){

        case 1:
            printf("Criar Pilha!\n");
            printf("Digite o tamanho da pilha: ");
                scanf("%d", &tam);
            pi = create_stack(tam);
            if(pi != NULL){
                printf("Pilha criada!\n\n");
            }else{
                printf("Pilha não criada!\n");
            }
        break;
        
        case 2:
            printf("Adicionando na pilha!\n");
            getchar();
            printf("Digite a expressao: ");
                scanf("%c", &caracter);
            aux = push_stack(pi, caracter);
            printf("Aux = %d\n", aux);
        break;

        case 3:
            printf("Remover da pilha!\n");
            aux = pop_stack(pi);
            printf("Aux = %d\n", aux);
        break;

        case 4:
            printf("Consultar Top!\n");
            aux = top_stack(pi, &top);
            printf("O caracter no topo e: %c\n", top);
            printf("Aux = %d\n", aux);
        break;

        case 5:
            printf("Tamaho da pilha!\n");
            aux = size_stack(pi);
            printf("O tamanho da pilha e: %d\n", aux);
            printf("Aux = %d\n", aux);
        break;

        case 6:
            printf("Liberar pilha!\n");
            aux = free_stack(pi);
            printf("Aux = %d\n", aux);
            opc = 0;
        break;

        case 7:
          printf("Pilh deve estar criada!\n");
          getchar();
          printf("Digite a expressao: ");
            fgets(expre, sizeof(expre), stdin);
          printf("\nExpressão  = %s", expre);
          aux = insere_bem_formada(pi, expre);
          if(aux == 0){
            printf("Expressão Bem Formada!\n\n");
          }else{
            printf("Expressão Mal Formada!\n\n");
          }
        break;

        case 8:
          print(pi);
          break;

        default:
            break;
        }
    }while(opc != 0);

    return 0;
}
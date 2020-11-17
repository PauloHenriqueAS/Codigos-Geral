#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "aluno.h"

int menu(){
    int escolha;
    printf("==================TAD-FILA===============\n");
    printf("1- Criar fila\n");
    printf("2- Inserir na fila\n");
    printf("3- Retirar da fila\n");
    printf("4- Consultar tamanho da fila\n");
    printf("5- Consultar primeiro elemento da fila\n");
    printf("6- liberar fila/Encerrar programa\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);
    printf("\n");
    return escolha;
}

int main(void){
    int opc, aux;
    Queue *fila;
    struct aluno aluno;
    
    do{
        opc = menu();
        switch(opc){
            case 1:
                printf("Criar a fila\n");
                fila = create_queue();
                if(fila != NULL){
                    printf("Fila criada!\n\n");
                }else{
                    printf("ERRO na criação\n\n");
                }
            break;

            case 2:
                printf("Inserir na fila\n");
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

                aux = push_queue(fila, aluno);
                if(aux == 0){
                    printf("Inserido com sucesso!\n");
                }else{
                    printf("ERRO na inserção!\n");
                }
                printf("AUX = %d\n\n", aux);
            break;

            case 3:
                printf("Retirar da fila\n");
                aux = pop_queue(fila);
                if(aux == 0){
                    printf("Retirado com sucesso!\n");
                }else{
                    printf("ERRO na retirada!\n");
                }
                printf("AUX = %d\n\n", aux);
            break;

            case 4:
                printf("Consultar tamanho\n");
                aux = size_queue(fila);
                if(aux == 0){
                    printf("Fila vazia!\n");
                }else{
                    printf("Tamanho da fila = %d\n", aux);
                }
            break;

            case 5:
                printf("Culsultar primeiro da fila\n");
                aux = first_queue(fila, &aluno);
                if(aux == 0){
                    printf("\nMatricula: %d", aluno.matricula);
                    printf("\nNome: %s", aluno.nome);
                    printf("\n nota1 %f, nota2 %f, nota3 %f\n", aluno.n1, aluno.n2, aluno.n3);
                }else{
                    printf("ERRO na consulta\n");
                }
            break;

            case 6:
                printf("Liberar fila\n");
                aux = free_queue(fila);
                if(aux == 0){
                    printf("Fila liberada!\n");
                    printf("OBRIGADO!\n");
                    opc = 0;
                }else{
                    printf("ERRO na liberação\n");
                }
            break;

        }//fim switch
    }while(opc != 0);
    
    return 0;
}
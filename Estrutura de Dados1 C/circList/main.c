#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circList.h"
#include "aluno.h"

int menu(){
    int escolha;
    printf("================Lista-Circular-Alunos===============\n");
    printf("1- Criar lista\n");//ok
    printf("2- Inserir na primeira posição\n");//ok
    printf("3- Inserir na ultima posição\n");//ok
    printf("4- Inserir aluno em uma posição\n");//ok
    printf("5- Retirar da  frente da lista\n");//ok
    printf("6- Retirar do fundo da lista\n");//ok
    printf("7- Retirar aluno de posição\n");//ok
    printf("8- Consultar tamanho da lista\n");//ok
    printf("9- Consultar primeiro aluno da lista\n");//ok
    printf("10- Consultar ultimo aluno da lista\n");//ok
    printf("11- Pegar aluno em uma posição\n");//ok
    printf("12- Pegar aluno em uma matricula\n");//ok
    printf("13- Pegar proximo aluno\n");//ok
    printf("14- Imprimir lista\n");//ok
    printf("15- Calcular media\n");
    printf("16- liberar lista/Encerrar programa\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);
    printf("\n");
    return escolha;
}

int main(void){
    int opc, aux, tamanho, pos, nmat;
    double media;
    List *lista;
    struct aluno aluno;
    
    do{
        opc = menu();
        switch(opc){
            case 1:
                printf("Criar a lista\n");
                lista = create_circ();
                if(lista != NULL){
                    printf("Lista criada!\n\n");
                }else{
                    printf("ERRO na criação\n\n");
                }
            break;

            case 2:
                printf("Inserir na primeira posição\n");
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

                aux = push_front_circ(lista, aluno);
                if(aux == 0){
                    printf("Inserido com sucesso!\n");
                }else{
                    printf("ERRO na inserção!\n");
                }
                printf("AUX = %d\n\n", aux);
            break;

            case 3:
                printf("Inserir na ultima posição\n");
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

                aux = push_back_circ(lista, aluno);
                if(aux == 0){
                    printf("Inserido com sucesso!\n");
                }else{
                    printf("ERRO na inserção!\n");
                }
                printf("AUX = %d\n\n", aux);
            break;

            case 4:
                printf("Inserir aluno em uma posição\n");
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
                printf("Digite a posição que deseja ser inserido: ");
                    scanf("%d", &pos);

                aux = insert_circ(lista, pos, aluno);
                if(aux == 0){
                    printf("Inserido com sucesso!\n");
                }else{
                    printf("ERRO na inserção!\n");
                }
                printf("AUX = %d\n\n", aux);
            break;
            
            case 5:
                printf("Retirar da  frente da lista\n");
                aux = pop_front_circ(lista);
                if(aux == 0){
                    printf("Retirado com sucesso!\n");
                }else{
                    printf("ERRO na retirada!\n");
                }
                printf("AUX = %d\n\n", aux);
            break;

            case 6:
                printf("Retirar do fundo da lista\n");
                aux = pop_back_circ(lista);
                if(aux == 0){
                    printf("Retirado com sucesso!\n");
                }else{
                    printf("ERRO na retirada!\n");
                }
                printf("AUX = %d\n\n", aux);
            break;

            case 7:
                printf("Retirar aluno de posição\n");
                printf("Digite a posição que deseja retirar o aluno: ");
                    scanf("%d", &pos);
                aux = erase_circ(lista, pos);
                if(aux == 0){
                    printf("Retirado com sucesso!\n");
                }else{
                    printf("ERRO na retirada!\n");
                }
                printf("AUX = %d\n\n", aux);
            break;

            case 8:
                printf("Consultar tamanho da lista\n");
                aux = size_circ(lista);
                if(aux == 0){
                    printf("Lista vazia!\n");
                }else{
                    printf("Tamanho da lista = %d\n", aux);
                }
            break;

            case 9:
                printf("Consultar primeiro aluno da lista\n");
                aux = front_circ(lista, &aluno);
                if(aux != 0){
                    printf("ERRO na consulta!\n");
                }else{
                    printf("\nMatricula: %d", aluno.matricula);
                    printf("\nNome: %s", aluno.nome);
                    printf("\n nota1 %f, nota2 %f, nota3 %f\n", aluno.n1, aluno.n2, aluno.n3);
                    printf("Aux = %d\n", aux);
                }
            break;

             case 10:
                printf("Consultar ultimo aluno da lista\n");
                aux = back_circ(lista, &aluno);
                if(aux != 0){
                    printf("ERRO na consulta!\n");
                }else{
                    printf("\nMatricula: %d", aluno.matricula);
                    printf("\nNome: %s", aluno.nome);
                    printf("\n nota1 %f, nota2 %f, nota3 %f\n", aluno.n1, aluno.n2, aluno.n3);
                    printf("Aux = %d\n", aux);
                }
            break;

            case 11:
                printf("Pegar aluno em uma posição\n");
                printf("Digite a posição que deseja retirar o aluno: ");
                    scanf("%d", &pos);

                aux = get_pos_circ(lista, pos, &aluno);
                if(aux != 0){
                    printf("ERRO na consulta!\n");
                }else{
                    printf("\nMatricula: %d", aluno.matricula);
                    printf("\nNome: %s", aluno.nome);
                    printf("\n nota1 %f, nota2 %f, nota3 %f\n", aluno.n1, aluno.n2, aluno.n3);
                    printf("Aux = %d\n", aux);
                }
            break;

            case 12:
                printf("Pegar aluno em uma matricula\n");
                printf("Digite a matricula que deseja retirar o aluno: ");
                    scanf("%d", &nmat);
                    
                aux = get_mat_circ(lista, nmat, &aluno);
                if(aux != 0){
                    printf("ERRO na consulta!\n");
                }else{
                    printf("\nMatricula: %d", aluno.matricula);
                    printf("\nNome: %s", aluno.nome);
                    printf("\n nota1 %f, nota2 %f, nota3 %f\n", aluno.n1, aluno.n2, aluno.n3);
                    printf("Aux = %d\n", aux);
                }
            break;

            case 13:
                printf("Pegar proximo aluno\n");
                    
                aux = next_circ(lista, &aluno);
                if(aux != 0){
                    printf("ERRO na visualização do proximo aluno!\n");
                }else{
                    printf("\nMatricula: %d", aluno.matricula);
                    printf("\nNome: %s", aluno.nome);
                    printf("\n nota1 %f, nota2 %f, nota3 %f\n", aluno.n1, aluno.n2, aluno.n3);
                    printf("Aux = %d\n", aux);
                }
            break;

            case 14:
                printf("Imprimir Lista\n");
                aux = print_circ(lista);
                if(aux != 0){
                    printf("ERRO na impressão!\n");
                }else{
                    printf("Impressão realizada com sucesso\n");
                    printf("Aux = %d\n", aux);
                }
            break;

            case 15:
                printf("Calcular media\n");
                aux = get_pos_circ(lista, pos, &aluno);
                if(aux != 0){
                    printf("ERRO para acessar o aluno!\n");
                }else{
                    media = (aluno.n1 + aluno.n2 + aluno.n3)/3;
                    printf("Media aluno(a) %s com a media = %lf\n", aluno.nome, media);
                    printf("Aux = %d\n", aux);
                }
            break;
            
        }//fim switch
    }while(opc != 0);
    
    return 0;
}
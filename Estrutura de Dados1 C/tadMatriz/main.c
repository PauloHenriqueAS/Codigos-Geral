#include <stdio.h>
#include "tad.h"
int menu(){
  int opc;
  printf("\n");
  printf("1- Alterar uma posicao\n");//ok
  printf("2- Acessar uma posicao\n");//ok
  printf("3- Preencher a matriz com valores aleatorios\n");//ok
  printf("4- Somar duas matrizes\n");//ok
  printf("5- Multiplicar duas matrizes\n");//pedir a segunda matriz ou randomizar
  printf("6- Multiplicar uma matriz por um valor escalar\n");
  printf("7- Calcular o Traço da matriz\n");
  printf("8- Retornar um vetor com a soma das linhas\n");
  printf("9- Retornar um vetor com a soma das coluna\n");
  printf("10- Liberar memória\n");
  printf("0- Sair\n");
  printf("Digite uma opção: ");
  scanf("%d", &opc);
  printf("\n");
  return opc;
}

int main(void) {
  int lin, col, opcMenu, i, j, aux, tamanho, escalar;
  int matriz=1, aux2, nMat;
  int lin2,lin3,col2,col3, auxiliar=0;
  double val, valor;
  TMat2D *pont;
  TMat2D *pont2;
  TMat2D *pont3;
  char c;
  double *somaLinha, *somaColuna, *traco;
  
  tamanho = lin*col;

  printf("Digite o numero de linhas: ");
   scanf("%d", &lin);
  printf("Digite o numero de colunas: ");
   scanf("%d", &col);
   
 pont = mat2D_create(lin, col);
 //pont2 = mat2D_create(lin, col);

 do{
   opcMenu = menu();
 switch(opcMenu){

   //Escrever elemento i,j
   case 1:
      printf("Digite o numero da linha que deseja modificar: ");
      scanf("%d", &i);
      printf("Digite o numero da coluna que deseja modificar: ");
      scanf("%d", &j);
      printf("Digite o numero que deseja inserir: ");
      scanf("%lf", &val);

      printf("Deseja acessar a posicao de qual matriz? (Note que a matriz deve estar criada!)\nMatriz1 = 1, Matriz2 = 2, Matriz3 = 3  ");
       scanf("%d", &nMat);

      if(nMat == 1){
        aux = mat2D_set_value(pont, i, j, val);
        printf("Valor %.2lf foi colocado na posicao (%d,%d)\n", val, i, j);
      }if(nMat == 2){
        aux = mat2D_set_value(pont2, i, j, val);
        printf("Valor %.2lf foi colocado na posicao (%d,%d)\n", val, i, j);
      }if(nMat == 3){
        aux = mat2D_set_value(pont3, i, j, val);
        printf("Valor %.2lf foi colocado na posicao (%d,%d)\n", val, i, j);
      }
   break;
 
 //Acessar elemento i,j
   case 2:
     printf("Digite o numero da linha que deseja acessar: ");
      scanf("%d", &i);
    printf("Digite o numero da coluna que deseja acessar: ");
      scanf("%d", &j);
    printf("Deseja acessar a posicao de qual matriz? (Note que a matriz deve estar criada!)\nMatriz1 = 1, Matriz2 = 2, Matriz3 = 3  ");
      scanf("%d", &nMat);
    if(nMat == 1){
      aux = mat2D_get_value(pont, i, j, &val);
      printf("Valor na posicao (%d,%d) = %.2lf\n", i, j, val);
    }if(nMat == 2){
      aux = mat2D_get_value(pont2, i, j, &val);
      printf("Valor na posicao (%d,%d) = %.2lf\n", i, j, val);
    }if(nMat == 3){
      aux = mat2D_get_value(pont3, i, j, &val);
      printf("Valor na posicao (%d,%d) = %.2lf\n", i, j, val);
    }
   break;

//Preencher com números aleatórios
   case 3:
      printf("Deseja inserir valores aleatorios na matriz? ");
      setbuf(stdin,NULL);
       scanf("%c", &c);
      if(c == 's' || c == 'S'){
       aux = mat2D_randomize_number(pont);
       //printf("Val==%d\n",aux);
        printf("\n");
      }else{
        break;
      }
   break;
   
   //Somar duas matrizes
   case 4:
     printf("Digite o numero de linhas: ");
      scanf("%d", &lin);
     printf("Digite o numero de colunas: ");
      scanf("%d", &col);

     lin2=lin3=lin;
     col2=col3=col;
    aux = mat2D_randomize_number(pont);
    //printf("aux= %d", aux);
   
    pont2 = mat2D_create(lin, col);
    aux = mat2D_randomize_number(pont2);
     //printf("aux=%d\n", aux);
    
    pont3 = mat2D_create(lin, col);
    aux = mat2D_add(pont, pont2, pont3, lin, col);
    //printf("aux=%d\n", aux);
     printf("\n");
   break;

//Multiplicar duas matrizes TERMINAR!!!!!
   case 5:
     printf("Digite o numero de linhas da segunda matriz: ");
      scanf("%d", &lin);
    printf("Digite o numero de colunas da segunda matriz: ");
      scanf("%d", &col);

    pont2 = mat2D_create(lin, col);
    lin2=lin;
    col2=col;
    tamanho = lin*col;

     printf("Deseja inserir os valores da segunda matriz ou randomizar: ");
     printf("Randomizar = R  Inserier = I: ");
      setbuf(stdin,NULL);
      scanf("%c", &c); 

     if(c == 'r' || c == 'R'){
       aux = mat2D_randomize_number(pont2);
       //printf("Val==%d\n",aux);
      }if(c == 'I' || c == 'i'){
        for(int k=0; k<tamanho; k++){
          printf("Digite o valor: ");
           scanf("%lf", &valor);
            aux = mat2D_prenencher(pont2, valor, k);
        }
      }else{
        break;
      }
     aux = mat2D_multiplying(lin, col, pont, pont2, pont3);
   break;

  //Multiplicar uma matriz por um valor escalar
   case 6:
     printf("Digite o valor para escalar a matriz: ");
      scanf("%d", &escalar);
     aux = mat2D_escalar(pont, escalar);
     printf("aux=%d", aux);
     printf("\n");
   break;
   
   case 7:
    printf("Deseja realizar o traco da matriz? ");
      setbuf(stdin,NULL);
       scanf("%c", &c);
      if(c == 's' || c == 'S'){
       printf("Deseja o traco de Matriz1 = 1, Matriz2 = 2, Matriz3 = 3 (Note que a matriz deve estar criada!) ");
        scanf("%d", &nMat);
      if(nMat == 1){
        traco = mat2D_traco(pont, &aux);
        if(aux != 0){
          printf("Tamanho de matriz invalido para realizar o traco!\n");
        break;
        }
      
        for(int l =0; l<lin; l++){
          if(l == lin-1){
            printf("%.2lf.\n", traco[l]);
          }else
            printf("%.2lf, ", traco[l]);
       }
      }if(nMat == 2){
         traco = mat2D_traco(pont2, &aux);
       if(aux != 0){
          printf("Tamanho de matriz invalido para realizar o traco!\n");
        break;
        }
       
        for(int l =0; l<lin2; l++){
          if(l ==lin2-1){
            printf("%.2lf.\n", traco[l]);
          }else
            printf("%.2lf, ", traco[l]);
       }
      }if(nMat == 3){
        traco = mat2D_traco(pont3, &aux);
        if(aux != 0){
          printf("Tamanho de matriz invalido para realizar o traco!\n");
        break;
        }

        for(int l =0; l<lin3; l++){
          if(l == lin3-1){
            printf("%.2lf.\n", traco[l]);
          }else
            printf("%.2lf, ", traco[l]);
       }
      }
    }else{
      break;
    }
   break;

   case 8:
    printf("Somar linhas de Matriz1 = 1, Matriz2 = 2, Matriz3 = 3 (Note que a matriz deve estar criada!) ");
    scanf("%d", &nMat);
    if(nMat == 1){
      somaLinha = mat2D_add_linhas(pont);
      printf("Soma linhas = ");
      for(int l =0; l<lin; l++){
        if(l == lin-1){
         printf("%.2lf.\n", somaLinha[l]);
        }else
         printf("%.2lf, ", somaLinha[l]);
      }
    }if(nMat == 2){
      somaLinha = mat2D_add_linhas(pont2);
      printf("Soma linhas = ");
      for(int l =0; l<lin2; l++){
        if(l == lin2-1){
         printf("%.2lf.\n", somaLinha[l]);
        }else
         printf("%.2lf, ", somaLinha[l]);
      }
    }if(nMat == 3){
      somaLinha = mat2D_add_linhas(pont3);
      printf("Soma linhas = ");
      for(int l =0; l<lin3; l++){
        if(l == lin3-1){
         printf("%.2lf.\n", somaLinha[l]);
        }else
         printf("%.2lf, ", somaLinha[l]);
      }
    }else{
      break;
    }
   break;

   case 9:
    printf("Somar colunas de Matriz1 = 1, Matriz2 = 2, Matriz3 = 3 (Note que a matriz deve estar criada!) ");
    scanf("%d", &nMat);
    if(nMat == 1){
      somaColuna = mat2D_add_colunas(pont);
      printf("Soma Colunas = ");
      for(int l =0; l<col; l++){
        if(l == col-1){
         printf("%.2lf.\n", somaColuna[l]);
        }else
         printf("%.2lf, ", somaColuna[l]);
      }
    }if(nMat == 2){
      somaColuna = mat2D_add_colunas(pont2);
      printf("Soma Colunas = ");
      for(int l =0; l<col2; l++){
        if(l == col2-1){
         printf("%.2lf.\n", somaColuna[l]);
        }else
         printf("%.2lf, ", somaColuna[l]);
      }

    }if(nMat == 3){
      somaColuna = mat2D_add_colunas(pont3);
      printf("Soma Colunas = ");
      for(int l =0; l<col3; l++){
        if(l == col3-1){
         printf("%.2lf.\n", somaColuna[l]);
        }else
         printf("%.2lf, ", somaColuna[l]);
      }
    }else{
      break;
    }
   break;
   
   //liberar memória
   case 10:
      printf("Deseja liberar qual matriz? (Note que a matriz deve estar criada!)\nMatriz1 = 1, Matriz2 = 2, Matriz3 = 3  ");
       scanf("%d", &nMat);

      if(nMat == 1){
        aux = mat2D_free(pont);
        printf("Val==%d\n",aux);
      }if(nMat == 2){
        aux = mat2D_free(pont2);
        printf("Val==%d\n",aux);
      }if(nMat == 3){
        aux = mat2D_free(pont3);
        printf("Val==%d\n",aux);
      }
   break;
 }//switch
 }while(opcMenu != 0);
 /*
int aux;
  printf("Hello World\n");
  aux = mat2D_free(pont);
  printf("%d", aux);*/
  return 0;
}
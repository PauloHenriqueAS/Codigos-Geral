//Exercicio-1
#include <stdio.h>
#include <string.h>

struct telefone{
  int ddd;
  char fone[10];
};

int main(void) {
  struct telefone tele[3];
  int i=1;
  
   do{
     if(i==2){
       getchar();
     }
     printf("Digite o DDD: ");
      scanf("%d", &tele[i].ddd);
      getchar();
     printf("Digite o telefone: ");
      fgets(tele[i].fone,11,stdin);
   i++;
   }while(i<3);
   
   printf("\nTelefones cadastrados: \n");
   for(i=1;i<3;i++){
   printf("%d %s\n", tele[i].ddd, tele[i].fone);
   }
  return 0;
}

//Exercicio-2
#include <stdio.h>
#include <string.h>

struct data{
  int dia;
  char mes[10];
  int ano;
};

int main(void) {
  int aux=0, maior=0;
  struct data dados[3];
  
 for(int i=0; i<3; i++){
  printf("\nDigite o dia: ");
   scanf("%d", &dados[i].dia);
   getchar();
  printf("Digite o mês: ");
   fgets(dados[i].mes, 10, stdin);
  printf("Digite o ano: ");
   scanf("%d", &dados[i].ano);
   getchar();
  
  aux = dados[i].ano;
  if(aux > maior)
     maior = aux;
}

  printf("\n%d foi o maior ano cadastrado.\n", maior);
  return 0;
}

//Exercicio-3
#include <stdio.h>

int main(void) {
  char nome[50];
  char letra;
  int posicao=0;
  
  printf("<< Vetor de char>>\n");
  printf("Digite um nome: ");
  int aux;
  letra = getchar();
  aux = letra;
  
  while(letra != '\n'){
    if(aux > 96 && aux < 123){
      letra -= 32;
      nome[posicao] = letra;
    }else{
       nome[posicao] = letra;
    }
    posicao++;
    letra = getchar();
    aux = letra;
  }
  
  printf("O nome digitado é: ");
  for(int i=0; i<posicao; i++){
    printf("%c", nome[i]);
  }
  return 0;
}

//Exercicio-5
#include <stdio.h>
#include <string.h>

struct aluno{
  char matricula[50];
  char nome[50];
  int nota1;
  int nota2;
  int nota3;
  double media;
  int numFaltas;
  double frequencia;
  char situacao;
  double menor;
};

int main(void) {
  int i, aux,aux2, maior;
  double mediaT=0;
  double aux3, maiorMedia=0, menorMedia=935;
  struct aluno dados[3];
  i=aux=aux2=maior=0;
  
  for(i=0; i<3; i++){
    printf("Entre com os dados do %dº aluno: \n", i+1);
    printf("Matricula: ");
     setbuf(stdin, 0);
     fgets(dados[i].matricula,13,stdin);
    printf("Nome: ");
    setbuf(stdin, 0);
     fgets(dados[i].nome,50,stdin);
    printf("Nota da 1º prova: ");
     scanf("%d", &dados[i].nota1);
    printf("Nota da 2º prova: ");
     scanf("%d", &dados[i].nota2);
    printf("Nota da 3º prova: ");
     scanf("%d", &dados[i].nota3);
    printf("Número de faltas: ");
     scanf("%d", &dados[i].numFaltas);
    printf("\n");
  
    dados[i].media = (dados[i].nota1+dados[i].nota2+dados[i].nota3)/3.0;
    aux = dados[i].nota1;
    if(dados[i].nota1 > maior){
       maior = dados[i].nota1;
    }
    aux2 = dados[i].media;
    if(dados[i].media > maiorMedia){
      maiorMedia = dados[i].media;
    }
    
    aux3 = dados[i].media;
    if(dados[i].media < menorMedia){//menorMedia >dados
      menorMedia = dados[i].media;
      dados[i].menor = menorMedia;
      //printf("%lf", menorMedia);
    }
    
    dados[i].frequencia = (72 - dados[i].numFaltas)*100/72;
    
    if(dados[i].frequencia < 75 && dados[i].media < 60){
      dados[i].situacao = 'F';
    }
    if(dados[i].media >= 60 && dados[i].frequencia >= 75)
      dados[i].situacao = 'A';
      
    if(dados[i].media < 60){
      dados[i].situacao = 'R';
    }
    if(dados[i].frequencia < 75){
      dados[i].situacao = 'F';
    }
    
  }
  int prioridade;
  for(i=0; i<3; i++){
    if(dados[i].nota1 == maior){
      printf("Aluno com maior nota na 1º prova foi %s com %d.0 pontos.\n", dados[i].nome, maior);
    }
     if(dados[i].media == maiorMedia){
      printf("Aluno com maior média geral foi %s com %.1lf pontos.\n", dados[i].nome, maiorMedia); 
     }
  }//for
  
  for(i=0; i<3; i++){
  if(dados[i].media == menorMedia){
       printf("Aluno com menor média geral foi %s com %.1lf pontos. \n", dados[i].nome, menorMedia);
      }
  }
  
  printf("\nSituação dos Alunos: \n");
  for(i=0; i<3; i++){
    if(dados[i].situacao == 'A'){
      printf("%s, %s. Aprovado.\n",dados[i].matricula, dados[i].nome);
    }
    if(dados[i].situacao == 'R'){
      printf("%s, %s. Reprovado por nota.\n",dados[i].matricula, dados[i].nome);
    }
    if(dados[i].situacao == 'F'){
      printf("%s, %s. Reprovado por falta.\n",dados[i].matricula, dados[i].nome);
    }
  }
  return 0;
}

//Exercicio-6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct eletrodomestico{
   char nome[20];
   double potencia;
   double tempoDia;
   double consumo;
};

int main(void) {
  struct eletrodomestico dados[5];
  int numDias;
  double consumoRelativo;
  
  double consumoTotal=0;
  for(int i=0; i<5; i++){
    printf("\nInforme os dados do %dº eletrodoméstico: \n", i+1);
    printf("Nome:  ");
     setbuf(stdin, 0);
     fgets(dados[i].nome, 16, stdin);
    printf("Potência:  "); 
     setbuf(stdin, 0);
     scanf("%lf", &dados[i].potencia);
    printf("Tempo ativo por dia: ");
     setbuf(stdin, 0);
     scanf("%lf", &dados[i].tempoDia);
     
   dados[i].consumo = dados[i].potencia*dados[i].tempoDia;
  }
  printf("\nInforme um valor de tempo (em dia): ");
   scanf("%d", &numDias);
   for(int j=0; j<5; j++){
     consumoTotal = consumoTotal+(dados[j].consumo*numDias);
     dados[j].consumo = dados[j].consumo*numDias;
   }
   printf("Consumo total: %.0lf KW\n", consumoTotal);
  printf("Consumo relativo:\n");
   for(int j=0; j<5; j++){
     //printf("%s ", dados[j].nome);
     consumoRelativo = (dados[j].consumo/consumoTotal)*100;
     printf("%s %.1lf%%\n", dados[j].nome, consumoRelativo);
   }
   
  return 0;
}

//Exercicio-7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct eletrodomestico{
   char nome[20];
   double potencia;
   double tempoDia;
   double consumo;
};

int main(void) {
  struct eletrodomestico dados[5];
  int numDias;
  double consumoRelativo;
  
  double consumoTotal=0;
  for(int i=0; i<5; i++){
    printf("\nInforme os dados do %dº eletrodoméstico: \n", i+1);
    printf("Nome:  ");
     setbuf(stdin, 0);
     fgets(dados[i].nome, 16, stdin);
    printf("Potência:  "); 
     setbuf(stdin, 0);
     scanf("%lf", &dados[i].potencia);
    printf("Tempo ativo por dia: ");
     setbuf(stdin, 0);
     scanf("%lf", &dados[i].tempoDia);
     
   dados[i].consumo = dados[i].potencia*dados[i].tempoDia;
  }
  printf("\nInforme um valor de tempo (em dia): ");
   scanf("%d", &numDias);
   for(int j=0; j<5; j++){
     consumoTotal = consumoTotal+(dados[j].consumo*numDias);
     dados[j].consumo = dados[j].consumo*numDias;
   }
   printf("Consumo total: %.0lf KW\n", consumoTotal);
  printf("Consumo relativo:\n");
   for(int j=0; j<5; j++){
     //printf("%s ", dados[j].nome);
     consumoRelativo = (dados[j].consumo/consumoTotal)*100;
     printf("%s %.1lf%%\n", dados[j].nome, consumoRelativo);
   }
   printf("\nMapa de memória: \n\n");
   for(int i=0; i<5; i++){
     printf("Endereços %dº eletrodoméstico\n", i+1);
     printf("Endereço Nome: %p\n", dados[i].nome); 
     printf("Endereço Potência: %p\n", dados[i].potencia);
     printf("Endereço Tempo ativo: %p\n\n", dados[i].tempoDia);
    }
  return 0;
}

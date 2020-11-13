EXERCICIO-1
#include <stdio.h>
#include <string.h>

int main(void) {
  unsigned char c=128;
  int aux =128;
  
 for(;aux <= 255; aux++, c++){
   if(aux == c+6)
     printf("%d  %c \t", aux, c);
   else
     printf("%d  %c \t", aux, c);
 }
  printf("\n");
  return 0;
}

//EXERCICIO-2
#include <stdio.h>
#include <string.h>

int main(void) {
  unsigned char c=128;
  int aux =128;
  
 for(;aux <= 255; aux++, c++){
   if(aux == c+6)
     printf("%d  %c \t", aux, c);
   else
     printf("%d  %c \t", aux, c);
 }
  printf("\n");
  return 0;
}

//EXERCICiO-3
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void) {
  char nome[50], letra;
  int tamanho, i=0;
  printf("<< Vetor de char>>\nDigite um nome: ");
   fgets(nome, 50, stdin);
   tamanho = strlen(nome);
  printf("O nome digitado é: ");
	do{
		letra = nome[i];
		//para usar o toupper tem q ser letra a letra
		printf("%c", toupper(letra));
		//putchar(toupper(letra)); putchar imprime uma letra na tela
		i++;
	}while(nome[i]);
   
  return 0;
}

//EXERCICIO-4
#include <stdio.h>
#include <string.h>

int main(void) {
  char nome1[50], nome2[50];
  int val;
  printf("<< Compara nomes>>\nDigite o nome 1:");
   fgets(nome1, sizeof(nome1), stdin);
  printf("Digite o nome 2:");
   fgets(nome2, sizeof(nome2), stdin);
   
  val = strcmp(nome1, nome2);
  //printf("%d", val);
  
  if(val == 0){
    printf("Os nomes digitados são iguais");
  }
  if(val != 0){
    printf("Os nomes digitados são diferentes");
  }
  return 0;
}

//EXERCICIO-5
#include <stdio.h>
#include <string.h>

int main(void) {
  char nome1[50], nome2[50];
  int val;
  printf("<< Compara nomes>>\nDigite o nome 1: ");
   fgets(nome1, 50, stdin);
  printf("Digite o nome 2: ");
   fgets(nome2, 50, stdin);
  //verifica se as string sao iguais contendo maiusculo ou nao 
  val = strcasecmp(nome1, nome2);
  
  if(val == 0){
    printf("Os nomes digitados são iguais\n");
  }
  if(val != 0){
    printf("Os nomes digitados são diferentes");
  }
  return 0;
}

//EXERCICIO-6
#include <stdio.h>
#include <string.h>

int main(void) {
  char nome1[20], nome2[20], nomeComp[40];
  
  printf("<<  Nomes  >>\nDigite o primeiro nome e último nome: ");
   fgets(nomeComp, sizeof(nomeComp), stdin);
  
  //s -> ja esta no buffer
  sscanf(nomeComp, "%19s %19s", nome1, nome2);
  printf("Nome: %s\n", nome1);
  printf("sobrenome: %s", nome2);
  return 0;
}

//EXERCICIO-7
#include <stdio.h>
#include <string.h>

int main(void) {
  char letras[50];
  int i=0;
  printf("<< Separa letras >>\nDigite o nome:");
  fgets(letras, sizeof(letras), stdin);
  while(letras[i] != '\n'){
    printf("%da letra: %c\n", i+1, letras[i]);
    i++;
    
  }
  return 0;
}

//EXERCICIO-8
#include <stdio.h>

int main(void) {
  char letra, palavra[50];
  int i=0;
  
  printf("<<Sem vogais>>\nDigite a string: ");
  letra = getchar();
  while(letra!='\n'){
    if(letra!='a'&&letra!='e'&&letra!='i'&&letra!='o'&&letra!='u'&&letra!='A'&&letra!='E'&&letra!='I'&&letra!='O'&&letra!='U'){
      palavra[i]=letra;
    }
    
    i++;
    letra=getchar();
  }
  printf("Saída sem vogais: ");
  for(int aux=0; aux<i; aux++){
    printf("%c", palavra[aux]);
  }
  return 0;
}

//EXERCICIO-9
#include <stdio.h>
#include <string.h>

int main(void) {
  char txtFinal[935];
  char nome[50], cpf[30], rg[30], endereco[50];
  char cidade[50], estado[5],cep[30];
  
  printf("Digite seu nome: ");
   fgets(nome, sizeof(nome), stdin);
  printf("Digite seu CPF: ");
   fgets(cpf, sizeof(cpf), stdin);
  printf("Digite seu RG: ");
   fgets(rg, sizeof(rg), stdin);
  printf("Digite seu endereço: ");
   fgets(endereco, sizeof(endereco), stdin);
  printf("Digite a cidade: ");
   fgets(cidade, sizeof(cidade), stdin);
  printf("Digite o estado: ");
   fgets(estado, sizeof(estado), stdin);
  printf("Digite o CEP: ");
  //scanf("%s", cep);
   fgets(cep, sizeof(cep), stdin);
   strcat(txtFinal, nome);
   strcat(txtFinal, ", RG ");
   strcat(txtFinal, rg);
   strcat(txtFinal, ", CPF ");
   strcat(txtFinal, cpf);
   strcat(txtFinal, ", residente a ");
   strcat(txtFinal, endereco);
   strcat(txtFinal, ", ");
   strcat(txtFinal, cidade);
   strcat(txtFinal, "-");
   strcat(txtFinal, estado);
   strcat(txtFinal, ", CEP ");
   strcat(txtFinal, " ");
   strcat(txtFinal, cep);
   strcat(txtFinal, " venho por meio desta declarar que vou estudar para a prova");
   
  printf("\n\n               D  E  C  L  A  R  A  Ç  Ã  O \n\n");
   printf("Eu, %s", txtFinal);
  return 0;
}

//EXERCICIO-10
#include <stdio.h>
#include <string.h>

int main(void) {
  char string[50], inverso[50];
  int tamanho=0, aux=0;
  
  printf("<< invertendo >>\nDigite a string: ");
   fgets(string, sizeof(string), stdin);
   tamanho = strlen(string);
   aux = tamanho-1;
   //printf("%d", aux);
  for(int i=0; i<=tamanho; i++){
    inverso[aux] = string[i];
    aux--;
  }
  printf("Saída invertida: %s", inverso);
  return 0;
}

//EXERCICIO-11
#include <stdio.h>
#include <string.h>

int main(void) {
  char palavra[20], palindromo[20];
  int aux=0, tamanho=0, eh=0;
  
  printf("<< Palíndromo >>\nDigite uma palavra: ");
   scanf("%s",palavra);
  tamanho = strlen(palavra);
  aux = tamanho-1;
  for(int i=0; i<tamanho; i++){
    //palindromo[aux] = palavra[i];
    if(palavra[i] != palavra[tamanho-i-1]){
      eh=1;
      break;
    }
  }
  
  if(eh == 0){
    printf("%s é palíndromo", palavra);
}
  if(eh == 1){
    printf("%s não é palíndromo", palavra);
  }
  return 0;
}
//Exercicio-1
#include <stdio.h>

int main(void) {
  int aux, i=32;
  unsigned char ascii = 32;
  aux=ascii;
  
  for(aux=32; aux<127; aux++, ascii++){
   if(ascii == aux+6){
     printf("%d %c \t", aux, ascii);
   }else{
     printf("%d %c \t", aux, ascii);
   }
  }
  return 0;
}

//EXERCICIO-2
#include <stdio.h>

int main(void) {
    char nome[50]; //guarda o nome
    char c;
    int i=0, pos=0; // pos - guarda a posição atual no vetor
    
    printf("<< Vetor de char>>\n");
    printf("Digite um nome: ");
    c = getchar(); // busca uma letra no buffer
    
    while (c != '\n') {  // fica no loop enquanto nao encontrar um ENTER
        nome[pos] = c;
        pos++;
        c = getchar(); // consome o próximo caractere do buffer
    }
    
    printf("O nome digitado é: ");
    for (i=0; i < pos; i++){
        printf("%c", nome[i]);
    }
        
    return 0;
}

//EXERCICIO-3
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
  char letra1, letra2;
  int aux, posicao=0;
  
  printf("<< Compara nomes>>\n");
  printf("Digite o nome 1: ");
    scanf("%s", nome1);
  
  printf("Digite o nome 2: ");
   scanf("%s", nome2);
  
  int diferenca=0, i=0;
  while (nome1[i]!='\0' && nome2[i]!='\0') {
    if (nome1[i] != nome2[i]) {
      if((nome1[i]+32) != nome2[i] && (nome1[i]-32) != nome2[i]){
        diferenca = 1;
        break;
      }
    }
    i++;
  }
  
  if(diferenca == 0){
    printf("Os nomes digitados são iguais");
  }
  if(diferenca == 1){
    printf("Os nomes digitados são diferentes");
  }
  return 0;
}

//EXERCICIO-6
#include <stdio.h>

int main(void) {
  char letra, nome[50], primeiroNome[50], ultimoNome[50];
  int i=0, j=0;
  printf("<<  Nomes  >>\nDigite o primeiro nome e último nome: ");
  scanf("%[^\n]", nome);

   int aux=0, aux2=0;
   for(i=0; i<50; i++){
     if(nome[i] == ' '){
       aux++;
     }
     if(aux == 0){
       primeiroNome[j++]= nome[i];
     }
     if(aux == 1){
       ultimoNome[aux2++] = nome[i];
     }
   }
   /*for(int j=0; j<sizeof(primeiroNome); j++){
     printf("%c", primeiroNome[i]);
   }*/
   printf("Nome: %s\n", primeiroNome);
   printf("Sobrenome:%s", ultimoNome);
  return 0; 
}

//EXERCICIO-7
#include <stdio.h>

int main(void) {
  char nome[10] = "0123456789";
  
  nome[0] = 'B';
  nome[1] = 'r';
  nome[2] = 'a';
  nome[3] = 's';
  nome[4] = 'i';
  nome[5] = 'l';
  int i,tamanho = 6;
  printf("Usando %%c: ");
  for (i=0; i < tamanho; i++){
    printf("%c",nome[i]);
  }
  
  printf("\nUsando %%s: %.6s",nome);
  

  return 0;
}
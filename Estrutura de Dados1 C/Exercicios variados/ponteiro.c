//Exercicio-1
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int val[5] = {2,4,5,8,10} ;
   unsigned int endereco_val2;
   
   endereco_val2 = &val[2];
   scanf("%d", endereco_val2);
   
   printf("%d\n", val[2]);
  return 0;
}

//Exercicio-2
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int val[5] = {2,4,5,8,10};
  int *pVal;
  
  int a = 40;
  int *pA;
  
  pA = &a;
  pVal = &val[4];
  
  printf("Endereco de A com ponteiro %d\n", pA);
  printf("Endereco de A com & %d\n", &a);
  printf("Altere o valor de A: ");
   scanf("%d", pA);
   
  printf("Altere o valor de val[4]: ");
   scanf("%d", pVal);
   
  printf("\nValor pVal = %d\n", *pVal);
  printf("Valor A = %d\n", *pA);
   
  return 0;
}

//Exercicio-3
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int val[5] = {2,4,5,8,10};
  int *pVal;
  int a = 40;
  int *p; 
  p = &a; 
  
printf("O valor da variavel a eh: %d\n", *p);
  
  for(int i=0; i<5; i++){
    pVal = &val[i];
   printf("Valor[%d] com ponteiro %d\n", i, *pVal);  
  }
  
  return 0;
}

//Exercicio-4
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int val[5] = {2,4,5,8,10};
  int a = 40; 
  int *p;
  int *pVal;
  p = &a;
  *p = 59;

  printf("\n O valor da variavel a eh: %d", a); 
  printf("\n O valor da variavel a eh: %d", *p);
  
  for(int i=0; i<5; i++){
    pVal = &val[i];
    printf("\nval[%d] = %d", i, *pVal-1);
  }
  
  return 0;
}

//Exercicio-5
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int v1 = 1;
  double v2 = 2;
  char c = 'a';

  int *p_v1;
  double *p_v2;
  char *p_c;

  p_v1 = &v1;
  p_v2 = &v2;
  p_c = &c;
//%p imprime o endereco em hexadecimal
  printf("\nEndereço de v1 %p", p_v1);
  printf("\nEndereço de v2 %p", p_v2);
  printf("\nEndereço de c %p\n", p_c);

  printf("\nEndereço+1 de v1 %p", p_v1+1);//1 --> (int) vai andar 4bytes
  printf("\nEndereço+1 de v2 %p", p_v2+1);//1 --> (double) vai andar 8bytes
  printf("\nEndereço+1 de c %p\n", p_c+1);//1 --> (char) vai andar 1byte

  printf("\nEndereço-1 de v1 %p", p_v1-1);
  printf("\nEndereço-1 de v2 %p", p_v2-1);
  printf("\nEndereço-1 de c %p\n", p_c-1);
  
  printf("\nEndereço+2 de v1 %p", p_v1+2);
  printf("\nEndereço+2 de v2 %p", p_v2+2);
  printf("\nEndereço+2 de c %p\n", p_c+2);

  printf("\nEndereço-2 de v1 %p", p_v1-2);
  printf("\nEndereço-2 de v2 %p", p_v2-2);
  printf("\nEndereço-2 de c %p\n", p_c-2);
  return 0;
}

//Exercicio-6
#include <stdio.h>

int main(void) {
  printf("Ha um comportamento diferente ao subtrair/somar de um ponteiro pois o\n"); 
  printf("ponteiro aponta/guarda o valor da posicao da variavel,\n");
  printf("e ao somarmos/subtrairmos mexemos no valor que representa essa\n"); 
  printf("posicao de memoria, se  for um valor\n"); 
  printf("INT andamos 4Bytes, DOUBLE andamos 8Bytes, CHAR, andamos 1Byte e FLOAT andamos 4Bytes.\n");
  printf("Se usarmos * para desreferenciar o  ponteiro ai sim passaremos a mexer no valor da variavel\n");
  return 0;
}

//Exercicio-7
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char nome[] = "José Augusto";

  char *pNome;
  pNome = nome;
  
  for(int i=0; i<= 12; i++){
    //printf("posicao %d == %c\n", i, pNome[i]);
    printf("%c", *pNome);
    pNome++;
  }
  printf("\n");
  return 0;
}

//Exercicio-8
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  //fazer typeCast
  int val1;
  double val2;
  void *p1;
  
  p1 = &val1;
  
  printf("Digite o valor do Inteiro: ");
   scanf("%d", (int *)p1);
   p1 = &val2;
  printf("Digite o valor do Double: ");
   scanf("%lf", (double *)p1);
   
   p1 = &val1;
  printf("valor de val1(comPonteiro) = %d\n", *(int *)p1);
  p1 = &val2;
  printf("valor de val2(comPonteiro) = %lf\n", *(double *)p1);
  
  return 0;
}

//Exercicio-9
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double vet[10]={0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 ,9.0};
  
  for(int i=0; i<10; i++){
    printf("%.1lf, ", *vet);
    vet[0] = vet[i+1];
  }
  printf("\n");
  return 0;
}

//Exercicio-10
#include <stdio.h>

int main(void) {
  int vet[10]={1,2,3,4,5,6,7,8,9};
  int aux =9;
  
  for(int i=0; i<10; i++){
    printf("%d ", *(vet+aux));
    aux--;
  }
  printf("\n");
  return 0;
}
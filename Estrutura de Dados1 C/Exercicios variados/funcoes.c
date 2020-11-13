//Exercicio-1
#include <stdio.h>
#include <stdlib.h>

void desenhaLinha(int num){
  for(int i=0;i<num;i++){
    printf("========\n");
  }
  return;
}
int main(void) {
  int num=0;
  
  printf("Digite a quantidade de linhas a serem impressas: ");
   scanf("%d", &num);
   
   desenhaLinha(num);
  return 0;
}

//Exercicio-2
#include <stdio.h>
#include <stdlib.h>

void desenhaLinha(int num, int linhas){
  for(int i=0;i<num;i++){
    for(int j=0; j<linhas; j++){
      printf("=");
    }
    printf("\n");
  }
  return;
}
int main(void) {
  int num=0, linhas;
  
  printf("Digite a quantidade de linhas a serem impressas: ");
   scanf("%d", &num);
  printf("Digite o tamanho da linha: ");
   scanf("%d", &linhas);
   
   desenhaLinha(num, linhas);
  return 0;
}

//Exercicio-3
#include <stdio.h>
#include <stdlib.h>

void desenhaLinha(int linhas){
  for(int i=0; i<linhas; i++){
     printf("=");
  }
  return;
}

void fatorial(int num){
  int fat=1;
  for(int i=1; i<=num; i++){
    fat = fat*i;
  }
   printf("\nO fatorial de %d é %d \n", num, fat);
  return;
}
int main(void) {
  //fat = fat*i;
  int linhas=0, num=0, fat=0;
  
  printf("Digite o tamanho da linha: ");
   scanf("%d", &linhas);
  printf("Digite o número que deseja calcular o fatorial: ");
   scanf("%d", &num);
  
  desenhaLinha(linhas);
  fatorial(num);
  desenhaLinha(linhas);
   
  return 0;
}

//Exercicio-4
#include <stdio.h>
#include <stdlib.h>

double elevado(int x, int n){
  double result=1;
  if(n>0){
    for(int i=1; i<n; i++){
      result = x*x;
     }
    }else{
      int aux = n*(-1);
    for(int i=0; i<aux; i++){
     result = x*x;
    }
    result = (1/result);
  }
  return result;
}

int main(void) {
  int x,n;
  double resultado;
  
  printf("Digite o valor de x: ");
   scanf("%d", &x);
  printf("Digite o valor de n: ");
   scanf("%d", &n);
  
  resultado = elevado(x, n);
  if(n < 0)
   printf("O valor de %d elevado a %d é %.4lf\n", x, n, resultado);
  else
   printf("O valor de %d elevado a %d é %.0lf\n", x, n, resultado);
  return 0;
}

//Exercicio-5
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void verifica(int n);

int main(void) {
  int n;
  
  printf("Digite o valor de n: ");
   scanf("%d", &n);
  verifica(n);
   
  return 0;
}

void verifica(int n){
  double raizN, resto;
  int aux;
  
  raizN = sqrt(n);
  aux = raizN;
  resto = raizN - aux;
  
  if(resto == 0)
  printf("O número %d é um quadrado perfeito.", n);
  if(resto != 0)
  printf("O número %d não é um quadrado perfeito.", n);
  
  return;
}#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void verifica(int n);

int main(void) {
  int n;
  
  printf("Digite o valor de n: ");
   scanf("%d", &n);
  verifica(n);
   
  return 0;
}

void verifica(int n){
  double raizN, resto;
  int aux;
  
  raizN = sqrt(n);
  aux = raizN;
  resto = raizN - aux;
  
  if(resto == 0)
  printf("O número %d é um quadrado perfeito.", n);
  if(resto != 0)
  printf("O número %d não é um quadrado perfeito.", n);
  
  return;
}

//Exercicio-6
#include <stdio.h>
#include <stdlib.h>

double neperiano(int num){
  double fat=1, nep=1;
  for(int i=1; i<(num); i++){
    fat = fat*i;
    nep = nep +(1/fat);
  }
  return nep;
}

int main(void) {
  int num;
  double nepe;
  
  printf("Digite o valor de n para aproximar o número neperiano: ");
   scanf("%d", &num);
   
  nepe = neperiano(num);
   printf("O valor do número neperiano é: %.14lf", nepe);
   
  return 0;
}
/*neperiano = neperiano +1/fat;*/

//Exercicio-7
#include <stdio.h>
void trocaAB(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  return;
}

int main(void) {
  int a,b;
  
  printf("Digite o número A: ");
   scanf("%d", &a);
  printf("Digite o número B: ");
   scanf("%d", &b);
   
  trocaAB(&a, &b);
  printf("O número A é: %d\nO número B é: %d", a, b);
  return 0;
}

//Exercicio-8
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double alteracao(double y, double alt);

int main(void) {
  double y,x,z, alt;
  
  printf("Digite o valor de y: ");
   scanf("%lf", &y);
  printf("Digite o percentual de alteração:");
   scanf("%lf", &alt);
   
  x = alteracao(y, alt);
  printf("O valor alterado é: %.0lf\n", x);
  return 0;
}

double alteracao(double y, double alt){
   double aux, aux2,resultado;
   aux = y*alt;
   aux2 = alt*100;
  
   if(aux2 > 0){
     resultado = aux+y;  
   }
   if(aux2 < 0){
     resultado = aux2 + y;
   }
   
   return resultado;
}

//Exercicio-9
#include <stdio.h>

void alteracao(double y, double alt, double *resu);

int main(void) {
  double y,x,z, alt;
  double resu;
  
  printf("Digite o valor de y: ");
   scanf("%lf", &y);
  printf("Digite o percentual de alteração:");
   scanf("%lf", &alt);
   
  alteracao(y, alt, &resu);
  printf("O valor alterado é: %.0lf\n", resu);
  return 0;
}

void alteracao(double y, double alt, double *resu){
   double aux, aux2,resultado;
   aux = y*alt;
   aux2 = alt*100;
  
   if(aux2 > 0){
     *resu = aux+y;  
   }
   if(aux2 < 0){
     *resu = aux2 + y;
   }
   
   return;
}

//Exercicio-10
#include <stdio.h>

struct pontos{
  int x;
  int y;
};

void imprime_ponto(struct pontos ponto){
  printf("O ponto digitado é: (%d,%d)", ponto.x, ponto.y);
  return;
}

int main(void) {
  int x, y;
  struct pontos ponto;
  
  printf("Digite o valor de x: ");
   scanf("%d", &ponto.x);
  printf("Digite o valor de y: ");
   scanf("%d", &ponto.y);

  imprime_ponto(ponto);
  return 0;
}

//Exercicio-11
#include <stdio.h>
#include <stdlib.h>

struct pontos{
  int x;
  int y;
};

int soma_pontoX(struct pontos p1, struct pontos p2){
  int somaX;
  somaX=  p1.x + p2.x;
  //p3.y = p1.y + p2.y;
  return somaX;
}
int soma_pontoY(struct pontos p1, struct pontos p2){
  int somaY;
  //p3.x =  p1.x + p2.x;
  somaY= p1.y + p2.y;
  return somaY;
}
void imprime_ponto(struct pontos p1, struct pontos p2, struct pontos p3){
  printf("A soma de (%d,%d) com (%d,%d) é (%d,%d)\n",
  p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
  return;
}

int main(void) {
  struct pontos p1, p2, p3;
  
  printf("Digite o valor de x1: ");
   scanf("%d", &p1.x);
  printf("Digite o valor de y1: ");
   scanf("%d", &p1.y);
  printf("Digite o valor de x2: ");
   scanf("%d", &p2.x);
  printf("Digite o valor de y2: ");
   scanf("%d", &p2.y);
   
  p3.x = soma_pontoX(p1,p2);
  p3.y = soma_pontoY(p1,p2);
  
  imprime_ponto(p1, p2, p3);
  return 0;
}

//Exercicio-12
#include <stdio.h>
#include <stdlib.h>


void soma_pontos(int x1, int y1, int x2, int y2, int *somaX, int *somaY){
  *somaX = x1 + x2;
  *somaY = y1 + y2;
  return;
}
void imprime_ponto(int x1, int y1, int x2, int y2, int somaX, int somaY){
  printf("\nA soma de (%d, %d) com (%d, %d) é (%d, %d).\n", x1,y1,x2,y2,somaX, somaY);
return;
}
   
int main(void) {
  int x1, x2, y1, y2;
  int part1, part2;
  int somaX, somaY;
  
  printf("1º Ponto\n");
  printf("x: ");
   scanf("%d", &x1);
  printf("y: ");
   scanf("%d", &y1);
    
  printf("\n2º Ponto\n");
  printf("x: ");
   scanf("%d", &x2);
  printf("y: ");
   scanf("%d", &y2);
   
  soma_pontos(x1, y1, x2, y2, &somaX, &somaY);
  imprime_ponto(x1, y1, x2, y2, somaX, somaY);
  return 0;
}

//Exercicio-15
#include <stdio.h>

struct pontos{
  int x;
  int y;
};

void inc_dir(struct pontos p, char direcao){
  int aux;
  if(direcao == 'n' || direcao == 'N'){
    aux = p.y;
    p.y = p.y+1;
    printf("\n(%d,%d) norte ==> (%d,%d)\n", p.x, aux, p.x, p.y);
  }
  
  if(direcao == 's' || direcao == 'S'){
    aux = p.y;
    p.y -= 1;
    printf("\n(%d,%d) sul ==> (%d,%d)\n", p.x, aux, p.x, p.y);
  }
  
  if(direcao == 'l' || direcao == 'L'){
    aux = p.x;
    p.x += 1;
    printf("\n(%d,%d) leste ==> (%d,%d)\n", aux, p.y, p.x, p.y);
  }
  
  if(direcao == 'o' || direcao == 'O'){
    aux = p.x;
    p.x = p.x-1;
    printf("\n(%d,%d) oeste ==> (%d,%d)\n",aux, p.y, p.x, p.y);
  }
  return;
}

int main(void) {
  struct pontos p;
  char direcao;
  int n;
  printf("Digite quantas vezes que deseja mexer em pontos: ");
   scanf("%d", &n);
  for(int i=0; i<n; i++){
  printf("Digite o valor para X: ");
   scanf("%d", &p.x);
  printf("Digite o valor para Y: ");
   scanf("%d", &p.y);
  printf("Norte = n, Sul = s, Leste = l, Oeste = o\nDigite a direcao: ");
  getchar();
   scanf("%c", &direcao);
   
  inc_dir(p, direcao);
  }
  
  return 0;
}

//Exercicio-16
#include <stdio.h>
#include <string.h>

struct pontos{
  int x;
  int y;
};

void inc_diag(struct pontos p, char *direcao){
  int aux, aux2;
  if(strncmp(direcao, "nordeste", 8) == 0){
    aux = p.x;
    aux2 = p.y;
    p.y = p.y+1;
    p.x = p.x+1;
    printf("\n(%d,%d) nordeste ==> (%d,%d)\n\n", aux, aux2, p.x, p.y);
  }
  
  if(strncmp(direcao, "noroeste", 8) == 0){
    aux = p.x;
    aux2 = p.y;
    p.y += 1;
    p.x -= 1;
    printf("\n(%d,%d) noroeste ==> (%d,%d)\n\n", aux, aux2, p.x, p.y);
  }
  
  if(strncmp(direcao, "sudeste", 7) == 0){
    aux = p.x;
    aux2 = p.y;
    p.x += 1;
    p.y -= 1;
    printf("\n(%d,%d) sudeste ==> (%d,%d)\n\n", aux, aux2, p.x, p.y);
  }
  
  if(strncmp(direcao, "sudoeste", 8) == 0){//verifica se o conteudo de direcao e igual a sudoeste e se possui o msm tamanho
    aux = p.x;
    aux2 = p.y;
    p.x = p.x-1;
    p.y =p.y-1;
    printf("\n(%d,%d) sudoeste ==> (%d,%d)\n\n",aux, aux2, p.x, p.y);
  }
  return;
}

int main(void) {
  struct pontos p;
  char direcao[50];
  int n;
  
  printf("Digite o numero de vezes que deseja mexer nos pontos: ");
   scanf("%d", &n);
   
  for(int i=0; i<n; i++){
  printf("Digite o valor para X: ");
   scanf("%d", &p.x);
  printf("Digite o valor para Y: ");
   scanf("%d", &p.y);
  printf("Opções: nordeste, noroeste, sudoeste, sudeste\nDigite a direcao: ");
  setbuf(stdin, NULL);
  fgets(direcao, sizeof(direcao), stdin);
   
  inc_diag(p, direcao);//direcao nao precisa de & pois a primeira posicao do vetor e um ponteiro para ele msm
  }
  return 0;
}

//Exercicio-17
#include <stdio.h>
#include <stdlib.h>

void imprime_vet_int(int *vetInt, int n);
void imprime_vet_double(double *vetDouble, int n);
void imprime_vet_float(float *vetFloat, int n);

int main(void) {
  float vetFloat[10] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  double vetDouble[10] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  int vetInt[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n=10;
  imprime_vet_int(vetInt, n); 
  imprime_vet_double(vetDouble, n); 
  imprime_vet_float(vetFloat, n); 
  
  return 0;
}

void imprime_vet_int(int *vetInt, int n){
  printf("Vetor-Int = ");
  for(int i=0; i<n; i++){
    if(i==n-1)
     printf("%d. ", *(vetInt+i));
    else
     printf("%d, ", *(vetInt+i));
  }
}

void imprime_vet_double(double *vetDouble, int n){
   printf("\nVetor-Double = ");
  for(int i=0; i<n; i++){
    if(i==n-1)
     printf("%.1lf. ", *(vetDouble+i));
    else
     printf("%.1lf, ", vetDouble[i]);
  }
}

void imprime_vet_float(float *vetFloat, int n){
   printf("\nVetor-Float = ");
  for(int i=0; i<n; i++){
    if(i==n-1)
     printf("%.1f. ", vetFloat[i]);
    else
     printf("%.1f, ", vetFloat[i]);
  }
}

//Exercicio-18
#include <stdio.h>

void opcDouble(double *vetDouble, int tamanho, double *maior, double *menor){
  for(int i=0; i<tamanho; i++){
    if(vetDouble[i] < *menor){
      *menor = vetDouble[i];
    }//if menor
    if(*(vetDouble+i) > *maior){
      *maior = *(vetDouble+i);
    }//if maior
  }//for
  
  return;
}

int main(void) {
  double vetDouble[10] = {1.0, 50.0, 15.2, 25.0, 935.0, 68.9, 7.0, 30.5, 115.0};
  double maior=0.0, menor = 935.0;
  int tamanho = 9;
  
  opcDouble(vetDouble, tamanho, &maior, &menor);
  printf("Vetor = ");
  for(int i=0; i<tamanho; i++){
    if(i == tamanho-1)
      printf("%.1lf.\n", vetDouble[i]);
    else
      printf("%.1lf, ", vetDouble[i]);
  }
  
  printf("Maior valor deo vetor: %.1lf\n", maior);
  printf("Menor valor do vetor: %.1lf\n", menor);
  
  return 0;
}

//Exercicio-19
#include <stdio.h>

int negativos(float *vet, int N);

int main(void) {
  float vet[10]={0.0, -1.0, 2.0, -3.0, 4.0, -5.0, 6.0, -7.0, 8.0, -9.0};
  int N = 10, numNegativos; 
  
  numNegativos = negativos(vet, N);
  printf("No vetor de Float  tem %d números negativos\n", numNegativos);
  return 0;
}

int negativos(float *vet, int N){
  int num=0;
  for(int i=0; i<N; i++){
    if(*(vet+i) < 0){
      num +=1;
    }//if
  }
  return num;
}

//Exercicio-20
#include <stdio.h>
#include <string.h>

void copiarvet(int *vetOri, int *vetDes, int tamanho){
  for(int j=0; j<tamanho; j++){
    vetDes[j] = *(vetOri+j);
  }
  return;
}
int main(void) {
  int vetOri[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int vetDes[10], tamanho=10;
  
  copiarvet(vetOri, vetDes, tamanho);
  printf("Vetor de Origem: ");
  for(int i=0; i<tamanho; i++){
    printf("%d ", vetOri[i]);
  }
   printf("\nVetor de Destino : ");
  for(int i=0; i<tamanho; i++){
    printf("%d ", vetDes[i]);
  }
  
  return 0;
}

//Exercicio-21
#include <stdio.h>
void multvet(int *vet, int n, int escalar);

int main(void) {
  int vet[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n=10, escalar=0;
  
  printf("Digite o valor de escalar: ");
   scanf("%d", &escalar);
   
  for(int i=0; i<n; i++){
    if(i == n-1)
       printf("%d.\n", vet[i]);
    else
       printf("%d, ", vet[i]);
  }
  
  multvet(vet, n, escalar);
  
  for(int i=0; i<n; i++){
    if(i == n-1)
       printf("%d.\n", vet[i]);
    else
       printf("%d, ", vet[i]);
  }
  return 0;
}

void multvet(int *vet, int n, int escalar){
  for(int i=0; i<n; i++){
    *(vet+i) *= escalar;
  }
  return;
}

//Exercicio-22
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//abs retorna o valor absoluto ex abs(-10) = 10

void abs_vet(int *vet){
  *vet = abs(*vet);
  return;
}

int main(void) {
  int vet[10] ={0, -1, 2, -3, 4, -5, 6, -7, -8, -9};
  int n =10;
  
  printf("Vetor antes de abs :");
  for(int i=0; i<n; i++){
    if(i == n-1)
      printf("%d.\n", vet[i]);
    else
      printf("%d, ", vet[i]);
  }
  
  printf("Vetor depois de abs :");
   for(int i=0; i<n; i++){
    if(i == n-1){
      abs_vet((vet+i));
      printf("%d.\n", vet[i]);
    }else{
      abs_vet(vet+i);
      printf("%d, ", vet[i]);
    }
  }
  return 0;
}

//Exercicio-23
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int menorLista(int *p, int nVet, int menor);
void imprime_vetor(int *p, int nVet);
void maiorLista(int *p, int nVet, int *maior);
void contador(int *p, int nVet, int *contNegativo);
void abs_vet(int *vet, int nVet);
void copiar_vetor(int *p, int nVet, int *pCopia);
void escalarVetor(int *p, int nVet, int escalar);

int main(void) {
  int nVet, *p, *pCopia;
  int menor=115, maior=0, contNegativo=0, escalar;
  
  printf("Entre com o tamanho do vetor: ");
   scanf("%d", &nVet);
   
  p = (int *)malloc(nVet*sizeof(int));
  pCopia = (int *)malloc(nVet*sizeof(int));
  
  if(p != NULL || pCopia != NULL){
      for(int i=0; i<nVet; i++){
      printf("Entre com o elemento %d: ", i+1);
       scanf("%d", &p[i]);
    }
    printf("\nVetor: ");
    imprime_vetor(p, nVet);
    
    menor = menorLista(p, nVet, menor);
    maiorLista(p, nVet, &maior);
    printf("Maior: %d  Menor: %d\n", maior, menor);
    
    contador(p, nVet, &contNegativo);
    printf("Número de negativos: %d", contNegativo);
    
    if(contNegativo > 0){
      printf("\nVetor absoluto: ");
      abs_vet(p, nVet);
    }//if
    
    printf("\nCopiando para outro vetor (alocado dinamicamente)\n\n");
    printf("Vetor original: ");
    imprime_vetor(p, nVet);
    printf("Vetor copiado: ");
    copiar_vetor(p, nVet, pCopia);
    imprime_vetor(pCopia, nVet);
    
    printf("\nEntre com o valor escalar para multiplicar o vetor original: ");
     scanf("%d", &escalar);
    
    printf("\nVetor original: ");
    escalarVetor(p, nVet, escalar);
    imprime_vetor(p, nVet);
    
    printf("Vetor copiado: ");
    imprime_vetor(pCopia, nVet);
  }else{
    printf("ERRO na alocacao do vetor!\n");
    exit(1);
  }
  
  
  free(p);
  free(pCopia);
  return 0;
}

int menorLista(int *p, int nVet, int menor){
  for(int i=0; i<nVet; i++)
  if(p[i] < menor){
    menor = p[i];
  }
  return menor;
}

void imprime_vetor(int *p, int nVet){
  for(int i=0; i<nVet; i++){
    if(i == nVet-1){
      printf("%d\n", p[i]);
    }else{
      printf("%d; ", p[i]);
   }
 }
return;
}

void maiorLista(int *p, int nVet, int *maior){
  for(int i=0; i<nVet; i++){
    if(p[i] > *maior)
      *maior = p[i];
  }
  return;
}

void contador(int *p, int nVet, int *contNegativo){
  for(int i=0; i<nVet; i++){
    if(*(p+i) < 0){
      *contNegativo = *contNegativo+1;
    }
  }
  return;
}
void abs_vet(int *vet, int nVet){
  for(int i=0; i<nVet; i++){
    if(i != nVet-1){
      printf("%d; ", abs(vet[i]));
    }else
      printf("%d\n", abs(vet[i]));
  }
  //*vet = abs(*vet);
  return;
}

void copiar_vetor(int *p, int nVet, int *pCopia){
    for(int i=0; i<nVet; i++){
      pCopia[i] = p[i];
    }
 return;
}

void escalarVetor(int *p, int nVet, int escalar){
  for(int i=0; i<nVet; i++){
    
    *(p+i) = p[i]*escalar;
  } 
 return;
}

//Exercicio-24
#include <stdio.h>
#include <stdlib.h>
void imprime_vetor(int *p, int nVet);
int *aloca_inteiro(int n); 


int main(void) {
  int *p, nVet;
  /*
  printf("Digite quantos numeros deseja inserir: ");
   scanf("%d", &nVet);*/
   
  p = aloca_inteiro(10); 
  imprime_vetor(p,10);
  
  return 0;
}

void imprime_vetor(int *p, int nVet){
  for(int i=0; i<nVet; i++){
    if(i == nVet-1){
      printf("%d\n", p[i]);
    }else{
      printf("%d; ", p[i]);
   }
 }
return;
}

int *aloca_inteiro(int nVet){
   return (int *)calloc(nVet,sizeof(int));
}

//Exercicio-25
#include <stdio.h>
#include <stdlib.h>

double copiarVet(double *vet_origem, int nVet);
void imprime_vetor(int *p, int nVet);
double *aloca_vetor(int nVet);

int main(void) {
  double vet_origem[5]={0.0, 1.0, 2.0, 3.0, 4.0}, vet_destino;
  int nVet=5;

  vet_destino = copiarVet(vet_origem, nVet);  
  
  printf("Vetor original: ");
   for(int i=0; i<nVet; i++){
     if(i == nVet-1)
        printf("%lf.\n", vet_origem[i]);
    else   
        printf("%lf; ", vet_origem[i]);
   }
   printf("Vetor copiado: ");
   for(int i=0; i<nVet; i++){
     if(i != nVet-1)
       printf("%lf; ", vet_destino+i);
     else 
       printf("%lf.\n", vet_destino+i);
   }
  return 0;
}

double copiarVet(double *vet_origem, int nVet){
   double *destino;
   //destino = aloca_vetor(nVet);
   destino = calloc(nVet, sizeof(double));
   
   for(int i=0; i<nVet; i++){
     destino[i] = vet_origem[i]; 
   }
   return *destino;
}

double *aloca_vetor(int nVet){
   return (double *)calloc(nVet,sizeof(double));
}

//Exercicio-26
#include <stdio.h>
#include <stdlib.h>

double * to_double(int *pInt, int nVet);

int main(void) {
  int *pInt, nVet;
  double *vet_double;
  
  printf("Digite quantos valores deseja digitar: ");
    scanf("%d", &nVet);
  
  pInt = (int *)malloc(nVet*sizeof(double));
  
  if(pInt == NULL){
    printf("ERRO na alocao!\n");
    exit(1);
  }else{
    for(int i=0; i<nVet; i++){
      printf("Digite o valor para a posicao %d: ", i+1);
       scanf("%d", &pInt[i]);
    }
    
    vet_double = to_double(pInt, nVet);
    
  printf("\nVetor int : ");
    for(int i=0; i<nVet; i++){
      if(i != nVet-1){
        printf("%d; ", pInt[i]);
      }else{
        printf("%d\n", pInt[i]);
      }
    }
    
    double aux=0.0;
  printf("Vetor double : ");
    for(int i=0; i<nVet; i++){
      if(i != nVet-1){
        printf("%.2lf; ", vet_double[i]);
        aux= aux+1.0;
      }else{
        printf("%.2lf\n", vet_double[i]);
        aux= aux+1.0;
      }
    }
  }//else
  
  free(pInt);
  free(vet_double);
  return 0;
}

double *to_double(int *pInt, int nVet){
  double *vetDouble;
  vetDouble = (double *)calloc(nVet,sizeof(double));
  
    for(int i=0; i<nVet; i++){
      vetDouble[i] = (double )pInt[i];
    }
    
  return vetDouble;
}

//Exercicio-27
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int x;
  int y;
}Pontos;

Pontos *alocar_vetor(int nVet){
  return (Pontos *)calloc(nVet,sizeof(Pontos));
}

void imprime(Pontos *xy, int nVet){
    for(int i=0; i<nVet; i++){
      if(i == nVet-1)
         printf("(%d,%d)\n", xy->x, xy->y);
      else
         printf("(%d,%d); ", xy->x, xy->y);
    }
  return;
}

int main(void) {
  Pontos *xy;
  int nVet;
  
  printf("Digite quantos pontos deseja: ");
   scanf("%d", &nVet);
  
  xy = alocar_vetor(nVet);
  imprime(xy, nVet);
  
  free(xy);
  return 0;
}

//Exercicio-28
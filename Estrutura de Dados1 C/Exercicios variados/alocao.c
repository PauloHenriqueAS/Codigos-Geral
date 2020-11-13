//Exercicio-1
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double *produtos; 
  int n,i; 

  printf("Informe o número de produtos"); 
    scanf("%d",&n); 
  
  // é necessário usar o comando malloc para alocar a memória 
  produtos = (double *)malloc(n*sizeof(double)); 
/*
N e o valor digitado pelo usuario, significa o numero de produtos que ele deseja inserir
sizeof(double) e o tamanho em bytes de double(8bytes), e no comando malloc ele juntamente 
com n vai alocar (n valores * o tamanho) para que ocorra  uma alocacao correta 
*/
if(produtos == NULL){
  printf("Memória nao alocada!!\n");
  exit(1);
}
else{
  for (i = 0; i < n; i++){ 
    printf("Informe o valor do produto %d R$:",i+1); 
    scanf("%lf", &produtos[i]);
  } 

  printf("\nProdutos cadastrados\n"); 

  for (i = 0; i < n; i++){ 
    printf("Produto %d  - R$: %.2f\n",i+1, produtos[i]); 
  } 
}//else
  // ao terminar de usar o vetor, devemos liberar a memória 
  free(produtos); 
  return 0;
}

//Exercicio-2
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p;
  //Alocacao de memoria
  p = (int *)malloc(5*sizeof(int));

  //Leitura dos valores
  for(int i=0; i<5; i++){
    printf("Digite o %d valor: ", i+1);
     scanf("%d", (p+i));
  }
  
  //Mostrar valores
  for(int j=0; j<5; j++){
    printf("posicao %d, contem o valor %d\n", j+1, p[j]);
  }
  
  //Liberacao  da memoria 
  free(p);
  return 0;
}

//Exercicio-3
#include <stdio.h>
#include <stdlib.h>

void parImpar(int *a, int *b){
  
}
int main(void) {
  int *val,n;
  printf("Quantos inteiros serão lidos: ");
   scanf("%d", &n);
   
  val = (int *)malloc(n*sizeof(int));
  for(int i=0; i<n; i++){
    printf("%dº inteiro: ", i+1);
    scanf("%d", &val[i]);
  }
  int contPar=0, contImpar=0;
  for(int i=0; i<n; i++){
    if((val[i] % 2) == 0 ){
      contPar++;
    }else{
      contImpar++;
    }
  }
  printf("São pares: %d dos %d inteiros lidos.\n", contPar, n);
  printf("São impares: %d dos %d inteiros lidos.", contImpar, n);
  
  free(val);
  return 0;
}

//Exercicio-4
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int x;
  int y;
}pontos;

int main(void) {
  int n;
  pontos *p;
  
  printf("Quantos pontos deseja digitar: ");
   scanf("%d", &n);
  printf("\n");
  
  p = (pontos *)calloc(n,sizeof(sizeof (pontos))); // alocacao de memoria 
  //pontos px[*p], py[*p];
  
  for(int i=0; i<n; i++){
    printf("Entre com a coordenada x do ponto %d: ", i+1);
      scanf("%d", &p[i].x);
    printf("Entre com a coordenada y do ponto %d: ", i+1);
      scanf("%d", &p[i].y);
    printf("\n");
  }
  
  printf("Pontos digitados: ");
  for(int i=0; i<n; i++){
    if(i == n-1)
      printf("(%d,%d)\n", p[i].x, p[i].y);
    else
      printf("(%d,%d); ", p[i].x, p[i].y);
  }
  
  free(p);
  return 0;
}

//Exercicio-5
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int x;
  int y;
}pontos;

int main(void) {
  int n;
  pontos *p, *a, *b, *c, *d;
  int acima=1, baixo=0, direita=1, esquerda=0;
  
  printf("Quantos pontos deseja digitar: ");
   scanf("%d", &n); 
  
  p = (pontos *)calloc(n,sizeof(sizeof(pontos)));
  
  if(p != NULL){
    for(int i=0; i<n; i++){
      printf("\nEntre com a coordenada x do ponto %d: ", i+1);
        scanf("%d", &p[i].x);
      printf("Entre com a coordenada y do ponto %d: ", i+1);
        scanf("%d", &p[i].y);
    }
 
 for(int i=0; i<n; i++){    
  if(p[i].x > direita){
    a = &p[i];
    direita = p[i].x;
  }
  if(p[i].x < esquerda){
    b = &p[i];
    esquerda = p[i].x;
  }
  if(p[i].y > acima){
    c = &p[i];
    acima = p[i].y;
  }
  if(p[i].y < baixo){
    d = &p[i];
    baixo = p[i].y;
  }
}
printf("\nPontos digitados: ");
for(int i=0; i<n; i++){
  if(i == n-1){
    printf("(%d,%d)\n", p[i].x, p[i].y);
  }else{
    printf("(%d,%d); ", p[i].x, p[i].y);
  }
}//for
//-> (somente para struct, desreferencia e indica o lugar na struct)
  printf("Ponto mais a esquerda = (%d,%d)\n", b->x, b->y);
  printf("Ponto mais a direita = (%d,%d)\n",a->x, a->y);
  printf("Ponto mais acima = (%d,%d)\n", c->x, c->y);
  printf("Ponto mais abaixo = (%d,%d)\n", d->x, d->y);

  }else{
    printf("ERRO na alocao\n");
    exit(1);
  }
  
  free(p);
  return 0;
}

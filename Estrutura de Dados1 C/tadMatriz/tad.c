#include "tad.h"
#include <stdio.h>

struct TMat2D{
 int nLinhas; // número de linhas
 int nColunas; // número de colunas
 double *data; // ponteiro para os dados da matriz
};

//-----------CRIAR MATRIZ----------------------------------------
TMat2D *mat2D_create(int nLinhas, int nColunas){
 if(nLinhas <= 0 || nColunas <=0){
    return NULL;
  }

  TMat2D *mat;
  mat = malloc(sizeof(TMat2D));
  if(mat == NULL){
    return NULL;
  }

  TMat2D *dados;
  mat->data = malloc(nLinhas*nColunas*sizeof(double));
  if(mat->data == NULL){
    free(mat);
    return NULL;
  }

  mat->nLinhas = nLinhas;
  mat->nColunas = nColunas; 
  //printf("ok");
  return mat;
}

//------------SETAR VALOR-------------------------------------
int mat2D_set_value(TMat2D *mat, int i, int j, double val){
   int posicao;
    posicao = j*(mat->nLinhas)+i;
   int aux = mat->data[posicao];
    mat->data[posicao] = val;

   if(aux != mat->data[posicao]){
     return 0;
   }else{
     return (-1);
   }
   //printf("ok\n");
}

//---------------PEGAR VALOR------------------------------------
int mat2D_get_value(TMat2D *mat, int i, int j, double *val){
  int posicao, aux;
  posicao = j*mat->nLinhas+i;

  *val = mat->data[posicao]; 
  aux = mat->data[posicao];
   
  if(aux == mat->data[posicao]){
     return 0;
   }else{
     return (-1);
   }
}

//----------------------RANDOMIZAR-------------------------------
/*usar srand(time(NULL)); a semente vai ser diferente, gerando numeros aleatorios sempre em cada execucao*/
int mat2D_randomize_number(TMat2D *mat){
   int i, tamanho;

   tamanho = mat->nLinhas * mat->nColunas;
   srand(time(NULL));

   for(i=0; i<=tamanho; i++){
     mat->data[i] = (double) (rand() % 100);
   } 
  //como verificar se deu certo?
  return 0;
}

//-----------------------SOMAR-----------------------------------
int mat2D_add(TMat2D *pont, TMat2D *pont2, TMat2D *pont3, int lin, int col){
   int tamanho;
   tamanho = (lin*col);

   if(pont->nLinhas != lin || pont->nColunas != col){
    return -1;
   }
   else{
    for(int k=0; k<tamanho; k++){
      pont3->data[k] = pont->data[k] + pont2->data[k];
    }
   return 0;
   }
}
//--------------ESCALAR-------------------------------------------
int mat2D_escalar(TMat2D *mat, int escalar){
   int tamanho, aux, aux2;
   tamanho = mat->nLinhas*mat->nColunas;

   for(int i=0; i<tamanho; i++){
     aux = mat->data[i];
     mat->data[i] = mat->data[i]*escalar;

     if(aux != mat->data[i]){
      aux2 = 0;
     }else{
       aux2 = 1;
     }
   }//for

  if(aux2 == 0){
    return 0;
  }else{
    return (-1);
  }
}
//----------------FREE---------------------------------------------OLHAR!!!
int mat2D_free(TMat2D *mat){
  free(mat->data);
  free(mat);
  if(mat->data == NULL){
    return 0;
  }else{
    return (-1);
  }
}

//-------------------------------------------------------------------------
int mat2D_prenencher(TMat2D *pont, double valor, int k){
     pont->data[k] = valor;
  if(pont->data[k] != valor){
    return  (-1);
  }else{
    return 0;
  }
}

//-------------------------------------------------------------------------
int mat2D_multiplying(int lin, int col, TMat2D *pont, TMat2D *pont2, TMat2D *pont3){
   if(pont->nColunas != lin){
     return (-1);
   }else{
     
     return 0;
   }
}

//--------------------------------------------------------------
double *mat2D_add_colunas(TMat2D *mat){
   int aux=0, aux2=0, i=0;
   double *vet;
   vet =(double *)calloc(mat->nColunas,sizeof(double));  
  if(vet == NULL){
     return  NULL;
   }else{
   
  aux = mat->nColunas;
   for(int k=0; k<(mat->nLinhas); k++){
     for(int l=aux2; l<aux; l++){
       vet[k] += mat->data[i];
       i++;
     }
    aux2 = aux;
    aux += mat->nColunas;
   }

 return vet;
  }
}

double *mat2D_traco(TMat2D *mat, int *aux){
  double *vet;
   vet =(double *)calloc(mat->nLinhas,sizeof(double));  
   if(vet == NULL){
     return  NULL;
   }
   if(mat->nColunas != mat->nLinhas){
    *aux = -1;
   }else{
    int aux2 = 0;
        for(int k=0; k<(mat->nLinhas); k++){
            vet[k] += mat->data[aux2];
            aux2 += mat->nLinhas+1;
        }
        *aux = 0; 
   }
   return vet;
}
//--------------------------------------------------------------
double *mat2D_add_linhas(TMat2D *mat){
   int aux=0, aux2=0, i=0;
   double *vet;
   vet =(double *)calloc(mat->nLinhas,sizeof(double));  
   if(vet == NULL){
     return  NULL;
   }else{
 
  aux = mat->nColunas;
   for(int k=0; k<(mat->nLinhas); k++){
     for(int l=aux2; l<aux; l++){
       vet[k] += mat->data[i];
       i += mat->nLinhas+1;
     }
   aux2 =aux;
   aux += mat->nColunas;
   i = aux;
   }

 return vet;
   }
}


/*--------------------------------------------------------------
void print_value(TMat2D *mat, double *valPosi){
  int tamanho = (mat->nLinhas*mat->nColunas); 
  for(int i=0; i<tamanho; i++){
     *val = mat->data[i];
  }

}*/
//somar linhas++ e coluna estatico


//--------------------------------------------------------------
/*
* @file main.c
 *@brief menu com opcoes relacionadas a turma como:ler arquivo com estudante, modificar, criar, etc.
 *@file main.c
 *@author *Paulo Henrique Alves Santos
          *Maycon Douglas Batista dos Santos
 * @date 18/12/2019
 * @bugs Nenhum conhecido.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
char nome[50];
char matricula[12];
int p1;
int p2; 
int p3;
int trab1; 
int trab2;
int faltas;
int notaFinal;
char situ;
}Aluno;

void menuPrincipal (void){

    printf("=====================================================\n");
    printf("=                 Menu Principal                    =\n");
    printf("=====================================================\n");
    printf("Opcoes:\n");
    printf("1 - Ler turma de estudantes do arquivo\n");
    printf("2 - Imprimir turma de estudantes\n");
    printf("3 - Imprimir estatisticas da turma\n");
    printf("4 - Cadastrar novo estudante\n");
    printf("5 - Editar informacoes de um estudante\n");
    printf("6 - Reler turma de estudantes do arquivo\n");
    printf("7 - Salvar e Sair\n");
    printf("\nDigite uma opcao: ");
return;
}
void menuTurma(void){
  printf("============================================\n");
  printf("=                 Ler Turma                =\n");
  printf("============================================\n");
  printf("Opcoes: \n");
  printf("1 - Ler uma turma existente\n");
  printf("2 - Criar uma nova turma\n");
  printf("3 - Voltar ao menu principal\n");
  printf("Digite uma opcao: ");
return;
}
//====================================================================================
void turmaExistente(Aluno *Aluno1, char *nomeArq, int *numEst){
 
  int i = 0;
  printf("\nDigite o nome do arquivo com a turma: ");
  getchar();
  fgets(nomeArq, 70 ,stdin);
  nomeArq[strcspn(nomeArq,"\n")] = '\0'; //tira o \n da string

  FILE * fp = fopen(nomeArq, "r" );//nome do aquivo+ modo abre+le

    if (fp == NULL){
    fprintf(stderr, "Arquivo %s nao existe!\n", nomeArq);
    exit(1);
   }
   printf("Arquivo %s lido com sucesso!\n", nomeArq);
//src = fopen(*nomeArq,"w");/fgets(string,tamanho, stdin
  while (!(feof(fp))){
//for(*numEst = 0; *numEst < 80 ; (*numEst)++){

   fgets(Aluno1[*numEst].nome, sizeof(Aluno1[*numEst].nome), fp);//arquivo
   Aluno1[*numEst].nome[strcspn(Aluno1[*numEst].nome,"\n")] = '\0';
   fgets(Aluno1[*numEst].matricula, sizeof(Aluno1[*numEst].matricula), fp);
   Aluno1[*numEst].matricula[strcspn(Aluno1[*numEst].matricula,"\n")] = '\0';
   fscanf(fp, "%d", &(Aluno1[*numEst].p1));
   fscanf(fp, "%d", &(Aluno1[*numEst].p2));
   fscanf(fp, "%d", &(Aluno1[*numEst].p3));
   fscanf(fp, "%d", &(Aluno1[*numEst].trab1));
   fscanf(fp, "%d", &(Aluno1[*numEst].trab2));
   fscanf(fp, "%d", &(Aluno1[*numEst].faltas));
   fscanf(fp, "%d", &(Aluno1[*numEst].notaFinal));
   fgetc(fp);  //fgetc vai pegar o caractere
   Aluno1[*numEst].situ = fgetc(fp);
   fgetc(fp);
  ++*numEst;
  ++i;
}
  // printf("numEst = %d", *numEst);
   fclose(fp);

   menuTurma();
   return;
}
//==========================================================================================
void criaTurma(Aluno *Aluno1, char *nomeArq){
  char escolha = 's';
  
  printf("\nDigite o nome do arquivo para a nova turma: ");
  getchar();
  fgets(nomeArq, sizeof(nomeArq),stdin);
  nomeArq[strcspn(nomeArq,"\n")] = '\0'; //tira o \n da string

  FILE * fp = fopen( nomeArq, "r" );
  if (fp != NULL){//a ideia e que se o arquivo for diferente de null quer dizer que ele ja existe entao pergunto se devo subscrever 
  fclose(fp);
  printf("Arquivo %s já existe. Deseja sobrescreve-lo? (S/N)", nomeArq);
  scanf("%c", &escolha);
  printf("\n");
  }

  if(escolha == 's' || escolha == 'S'){
   fp = fopen(nomeArq, "w" );
  printf("Arquivo %s criado com sucesso.\n", nomeArq);
  }else{
  }
  fclose(fp);
  //menuTurma();
return;
}
//======================================================================================
void imprimiTurma (Aluno *Aluno1, char *nomeArq, int numEst){
int i = 0;
    if (nomeArq[0] == '\0')
    {
        printf("Não há turma carregada!\n");
    }

printf("-------------------------------------------------------------------------------------------------------\n");
printf("                                       Turma de Estudantes                                             \n");
printf("-------------------------------------------------------------------------------------------------------\n");
printf("Nome  \t\t  Matricula      N1\t N2\t N3\t T1\t T2\tFal\tFinal\tSit\n");
printf("-------------------------------------------------------------------------------------------------------\n");
  //ERRO NO FOR numEst
for (i = 0; i < numEst; i++){ //Vai printar todas as informacoes presentes no arquivo lido
   printf("%s",Aluno1[i].nome);
   printf("  %s",Aluno1[i].matricula);
   printf("\t%d",Aluno1[i].p1);
   printf("\t%d",Aluno1[i].p2);
   printf("\t%d",Aluno1[i].p3);
   printf("\t%d",Aluno1[i].trab1);
   printf("\t%d",Aluno1[i].trab2);
   printf("\t%d",Aluno1[i].faltas);
   printf(" \t%d",Aluno1[i].notaFinal);
   printf(" \t%c",Aluno1[i].situ);
   printf("\n\n");
}
return;
}
//====================================================================================
void mediana(Aluno *Aluno1, int numEst, double *p1,double *p2,double *p3,double *pT1,double *pT2,double *pF){
   
  int n1[numEst], n2[numEst], n3[numEst], n4[numEst], n5[numEst], n6[numEst];
  int idxMed;
 

for(int i=0; i<numEst; i++){
    n1[i] = Aluno1[i].p1;
    n2[i] = Aluno1[i].p2;
    n3[i] = Aluno1[i].p3;
    n4[i] = Aluno1[i].trab1;
    n5[i] = Aluno1[i].trab2;
    n6[i] = Aluno1[i].notaFinal;
}
   ordenacao(n1, numEst);
   ordenacao(n2, numEst);
   ordenacao(n3, numEst);
   ordenacao(n4, numEst);
   ordenacao(n5, numEst);
   ordenacao(n6, numEst);
    
  idxMed = numEst/2;

  if(numEst %2 != 0){//se o arranjo tiver valor par
    *p1 = (n1[idxMed] + n1[idxMed-1])/(double)2.0;
    *p2 = (n2[idxMed] + n2[idxMed-1])/(double)2.0;
    *p3 = (n3[idxMed] + n3[idxMed-1])/(double)2.0;
    *pT1 = (n4[idxMed] + n4[idxMed-1])/(double)2.0;
    *pT2 = (n5[idxMed] + n5[idxMed-1])/(double)2.0; 
    *pF = (n6[idxMed] + n6[idxMed-1])/(double)2.0;
 }else{
    *p1 = (double)n1[idxMed];
    *p2 = (double)n2[idxMed];
    *p3 = (double)n3[idxMed];
    *pT1 = (double)n4[idxMed];
    *pT2 = (double)n5[idxMed]; 
    *pF = (double)n6[idxMed]; 
 }  
 return;
}

//=============================================================================================
void estatisticas(Aluno *Aluno1, int numEst){
  int i;
  int maiorN1=0, maiorN2=0, maiorN3=0,maiorT1=0, maiorT2=0, maiorFinal=0;
  int menorN1=0, menorN2=0, menorN3=0, menorT1=0, menorT2=0, menorFinal=0;
  double mediaN1, mediaN2, mediaN3, mediaT1, mediaT2, mediaFinal;
  int nAprov=0, nReprov=0, nRevfal=0;
  double porcAprov, porcRepro, porcFalta;
  int totalAlunos = 0;
  double p1, p2, p3, pT1, pT2, pF;

 for (int i = 0; Aluno1[i].nome[0] != 0; i++)
        {
            totalAlunos += 1;
        }

 printf("                             Estatisticas                                  \n");
 printf("---------------------------------------------------------------------------\n");
 printf("                        N1\t  N2\t  N3\t  T1\t  T2\t Final\n");

 //esse for vai pegar os valores na struct e vai armazenar e comparar com o proximo valor
 for(i = 0; i < numEst; i++){
   //usar if para verificar cada um 
    if(maiorN1 < Aluno1[i].p1){
      maiorN1 = Aluno1[i].p1;
    }

    if(maiorN2 < Aluno1[i].p2){
      maiorN2 = Aluno1[i].p2;
    }

    if(maiorN3 < Aluno1[i].p3){
      maiorN3 = Aluno1[i].p3;
    }

    if(maiorT1 < Aluno1[i].trab1){
      maiorT1 = Aluno1[i].trab1;  
    }

    if(maiorT2 < Aluno1[i].trab2){
      maiorT2 = Aluno1[i].trab2;  
    }

    if(maiorFinal < Aluno1[i].notaFinal){
    maiorFinal = Aluno1[i].notaFinal;
    }

   //contador faltas
   if(Aluno1[i].situ == 'A'){
     nAprov += 1;
   }
   if (Aluno1[i].situ == 'R'){
     nReprov += 1;
   }
   if (Aluno1[i].situ == 'F'){
     nRevfal += 1;
   }
 }


for(i = 0; i < numEst; i++){
  if (i == 0){
     menorN1 = Aluno1[i].p1; 
     menorN2 = Aluno1[i].p2; 
     menorN3 = Aluno1[i].p3; 
     menorT1 = Aluno1[i].trab1;
     menorT2 = Aluno1[i].trab2;
     menorFinal = Aluno1[i].notaFinal;  
 }
 
  else if(menorN1 > Aluno1[i].p1){
      menorN1 = Aluno1[i].p1;
  }
   else if(menorN2 > Aluno1[i].p2){
      menorN2 = Aluno1[i].p2;
  }
  else  if(menorN3 > Aluno1[i].p3){
      menorN3 = Aluno1[i].p3;
  } 
  else if(menorT1 > Aluno1[i].trab1){
      menorT1 = Aluno1[i].trab1;
  }
  else if(menorT2 > Aluno1[i].trab2){
      menorT2 = Aluno1[i].trab2;
  }
  else if(menorFinal > Aluno1[i].notaFinal){
    menorFinal = Aluno1[i].notaFinal;
  }
}

 i=0;
int soma=0, soma2=0, soma3=0, somaT1=0, somaT2=0, somaFinal=0;
for(i = 0; i < numEst; i++){ 
  soma += Aluno1[i].p1;
  soma2 += Aluno1[i].p2;
  soma3 += Aluno1[i].p3;
  somaT1 += Aluno1[i].trab1;
  somaT2 += Aluno1[i].trab2;
  somaFinal += Aluno1[i].notaFinal;
} 
 
 mediaN1 = soma/ i;
 mediaN2 = soma2 / i;
 mediaN3 = soma3 / i;
 mediaT1 = somaT1 / i;
 mediaT2 = somaT2 / i;
 mediaFinal = somaFinal / i;

  porcAprov = 25*nAprov;
  porcRepro = 25*nReprov;
  porcFalta = 25*nRevfal;
 
   mediana(Aluno1, numEst, &p1, &p2, &p3, &pT1, &pT2, &pF);
 
  printf("Maiores notas da turma  %d\t %d\t %d\t %d\t %d\t %d\n", maiorN1, maiorN2, maiorN3, maiorT1, maiorT2, maiorFinal);
  printf("Menores notas da turma  %d\t %d\t %d\t %d\t %d\t %d\n", menorN1, menorN2, menorN3, menorT1, menorT2, menorFinal);
  printf("Notas medias da turma  %3.1lf\t %3.1lf\t %3.1lf\t %3.1lf\t %3.1lf\t %3.1lf\n", mediaN1, mediaN2, mediaN3, mediaT1, mediaT2, mediaFinal);
  printf("Notas medianas da turma  %.1lf\t %.1lf\t %.1lf\t %.1lf\t %.1lf\t %.1lf\n", p1, p2, p3, pT1, pT2, pF);
  printf("---------------------------------------------------------------------------\n");

  printf("Numero de estudantes aprovados: %d (%.1lf %%)", nAprov, porcAprov);
  printf("\nNumero de estudantes reprovados: %d (%.1lf %%)", nReprov, porcRepro);
  printf("\nNumero de estudantes reprovados por falta: %d (%.1lf %%)", nRevfal, porcFalta);
  printf("\nHistograma de notas finais em grupos de 10 pontos:\n");
  getHistograma(Aluno1, totalAlunos);
  getchar();
  printf("\n");

return;
}

void getHistograma(Aluno *Aluno1, int totalAlunos){
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, l = 0, j = 0;
    for (int i = 0; i < totalAlunos; i++)
    {
        if (Aluno1[i].notaFinal <= 10)
            a++;
        else if (Aluno1[i].notaFinal > 10 && Aluno1[i].notaFinal <= 20)
            b++;
        else if (Aluno1[i].notaFinal > 20 && Aluno1[i].notaFinal <= 30)
            c++;
        else if (Aluno1[i].notaFinal > 30 && Aluno1[i].notaFinal <= 40)
            d++;
        else if (Aluno1[i].notaFinal > 40 && Aluno1[i].notaFinal <= 50)
            e++;
        else if (Aluno1[i].notaFinal > 50 && Aluno1[i].notaFinal <= 60)
            f++;
        else if (Aluno1[i].notaFinal > 60 && Aluno1[i].notaFinal <= 70)
            g++;
        else if (Aluno1[i].notaFinal > 70 && Aluno1[i].notaFinal <= 80)
            h++;
        else if (Aluno1[i].notaFinal > 80 && Aluno1[i].notaFinal <= 90)
            l++;
        else
            j++;
    }

    printf(" 0 -  10   %d", a);
    hist(a);
    printf("11 -  20   %d", b);
    hist(b);
    printf("21 -  30   %d", c);
    hist(c);
    printf("31 -  40   %d", d);
    hist(d);
    printf("41 -  50   %d", e);
    hist(e);
    printf("51 -  60   %d", f);
    hist(f);
    printf("61 -  70   %d", g);
    hist(g);
    printf("71 -  80   %d", h);
    hist(h);
    printf("81 -  90   %d", l);
    hist(l);
    printf("91 - 100   %d", j);
    hist(j);
}
void hist(int var)
{
    if (var == 0)
        printf("\n");
    else
    {
        for (int i = 0; i < var; i++)
        {
            printf("*");
        }
        printf("\n");
    }
    return;
}

int menorNota(int tipoNota, Aluno *Aluno1){
    double menor;

    switch (tipoNota)
    {
    case 1:
        for (int i = 0; Aluno1[i].nome[0] != 0; i++)
        {
            if (i == 0)
                menor = Aluno1[i].p1;
            else if (menor > Aluno1[i].p1)
                menor = Aluno1[i].p1;
        }
        break;
    case 2:
        for (int i = 0; Aluno1[i].nome[0] != 0; i++)
        {
            if (i == 0)
                menor = Aluno1[i].p2;
            else if (menor > Aluno1[i].p2)
                menor = Aluno1[i].p2;
        }
        break;
    case 3:
        for (int i = 0; Aluno1[i].nome[0] != 0; i++)
        {
            if (i == 0)
                menor = Aluno1[i].p3;
            else if (menor > Aluno1[i].p3)
                menor = Aluno1[i].p3;
        }
        break;
    case 4:
        for (int i = 0; Aluno1[i].nome[0] != 0; i++)
        {
            if (i == 0)
                menor = Aluno1[i].trab1;
            else if (menor > Aluno1[i].trab1)
                menor = Aluno1[i].trab1;
        }
        break;
    case 5:
        for (int i = 0; Aluno1[i].nome[0] != 0; i++)
        {
            if (i == 0)
                menor = Aluno1[i].trab2;
            else if (menor > Aluno1[i].trab2)
                menor = Aluno1[i].trab2;
        }
        break;
    case 6:
        for (int i = 0; Aluno1[i].nome[0] != 0; i++)
        {
            if (i == 0)
                menor = Aluno1[i].notaFinal;
            else if (menor > Aluno1[i].notaFinal)
                menor = Aluno1[i].notaFinal;
        }
        break;
    }

    return menor;
}  
void ordenacao(int a[], int tam){
 int i = 0; // ı́ndice da posicao correta
 int temp = 0; // temporário usado para realizar a permuta

for(int j = 1; j < tam; j++){
temp = a[j];

// Procure ao correta para inserir temp no lado esquerdo,
// movendo os elementos para a direita, se necessário.
   i = j - 1; 
while (i >= 0 && temp < a[i]){
  a[i+1] = a[i]; // move o elemento uma posicao para a direita
 i = i - 1;
} // while

  a[i+1] = temp; // insira temp na posicao correta do lado esquerdo
} // for j

return;
}

//==========================================================================================
void cadastrar (Aluno *Aluno1, int *numEst){
   
    printf("=====================================\n");
    printf("=     Cadastrar novo estudante      =\n");
    printf("=====================================\n");
    printf("Opcoes: \n\n");
   
    //*numEst++;

    setbuf(stdin, NULL);
    printf("Digite nome: ");
    fgets(Aluno1[*numEst].nome, sizeof(Aluno1[*numEst].nome), stdin);
    
    setbuf(stdin, NULL); //seta o buffer para NUll
    printf("Digite a matricula: ");
    fgets(Aluno1[*numEst].matricula, sizeof(Aluno1[*numEst].matricula), stdin);

    printf("Digite as tres notas das provas: ");
    scanf("%d",&Aluno1[*numEst].p1);
    scanf("%d",&Aluno1[*numEst].p2);
    scanf("%d",&Aluno1[*numEst].p3);

    printf("Digite as duas notas dos trabalhos: ");
    scanf("%d",&Aluno1[*numEst].trab1);
    scanf("%d",&Aluno1[*numEst].trab2);

    printf("Digite o numero de faltas: ");
    scanf("%d",&Aluno1[*numEst].faltas);

    Aluno1[*numEst].notaFinal = Aluno1[*numEst].p1 + Aluno1[*numEst].p2 + Aluno1[*numEst].p3 + Aluno1[*numEst].trab1 + Aluno1[*numEst].trab2;

    printf("Nota Final calculada: %d\n" ,Aluno1[*numEst].notaFinal);

    if(Aluno1[*numEst].faltas > 18){
        printf("Situacao final: Reprovado por faltas\n");
      
    }
    else if(Aluno1[*numEst].notaFinal < 60){
        printf("Situacao final: Reprovado\n");
        
    }else{
        printf("Situacao final: Aprovado\n");
        
    }
    ++*numEst;

  return;
}
//=============================================================================================
void relerTurma(Aluno *Aluno1,char *nomeArq, int *numEst){
  
  int i = 0;
  printf("\nDigite o nome do arquivo com a turma: ");
  getchar();
  fgets(nomeArq, 70 ,stdin);
  nomeArq[strcspn(nomeArq,"\n")] = '\0'; //tira o \n da string

  FILE * fp = fopen(nomeArq, "r" );//nome do aquivo+ modo abre+le

    if (fp == NULL){
    fprintf(stderr, "Arquivo %s nao existe!\n", nomeArq);
    exit(1);
   }
   printf("Arquivo %s lido com sucesso!\n", nomeArq);
//src = fopen(*nomeArq,"w");/fgets(string,tamanho, stdin
  
  while (!(feof(fp))){
//for(*numEst = 0; *numEst < 80 ; (*numEst)++){

   fgets(Aluno1[*numEst].nome, sizeof(Aluno1[*numEst].nome), fp);//arquivo
   Aluno1[*numEst].nome[strcspn(Aluno1[*numEst].nome,"\n")] = '\0';
   fgets(Aluno1[*numEst].matricula, sizeof(Aluno1[*numEst].matricula), fp);
   Aluno1[*numEst].matricula[strcspn(Aluno1[*numEst].matricula,"\n")] = '\0';
   fscanf(fp, "%d", &(Aluno1[*numEst].p1));
   fscanf(fp, "%d", &(Aluno1[*numEst].p2));
   fscanf(fp, "%d", &(Aluno1[*numEst].p3));
   fscanf(fp, "%d", &(Aluno1[*numEst].trab1));
   fscanf(fp, "%d", &(Aluno1[*numEst].trab2));
   fscanf(fp, "%d", &(Aluno1[*numEst].faltas));
   fscanf(fp, "%d", &(Aluno1[*numEst].notaFinal));
   fgetc(fp);  //fgetc vai pegar o caractere
   Aluno1[*numEst].situ = fgetc(fp);
   fgetc(fp);
  ++*numEst;
  ++i;
}
   //printf("numEst = %d", *numEst);
   fclose(fp);
   return;
}
//===================================================================================
void zerarStruct(Aluno *Aluno1, int *numEst){

 *numEst =0;

 for(int i =0; i<80; i++){  
  Aluno1[i].p1 = '\0';
  Aluno1[i].p2 = '\0';
  Aluno1[i].p3 = 0;
  Aluno1[i].trab1 = 0;
  Aluno1[i].trab2 = 0;
  Aluno1[i].faltas = 0;
  Aluno1[i].notaFinal = 0;
  Aluno1[i].situ = 'F';
 }
 return;
}
//==================================================================================
void salvarSair(Aluno *Aluno1,char *nomeArq, int numEst){
  
  int i;
  printf("\nDigite o nome do arquivo com a turma: ");
  getchar();
  fgets(nomeArq, 70 ,stdin);
  nomeArq[strcspn(nomeArq,"\n")] = '\0'; //tira o \n da string

  FILE * fp = fopen(nomeArq, "w" );//nome do aquivo+ modo abre+le
if (fp == NULL){
    printf("Arquivo vazio!\n");
   }
 
for(i = 0; i < numEst; i++){
   fprintf(fp,"%s", Aluno1[i].nome);
   fprintf(fp, "\n%s",Aluno1[i].matricula);
   fprintf(fp, "\n%d",Aluno1[i].p1);
   fprintf(fp, "\n%d",Aluno1[i].p2);
   fprintf(fp, "\n%d",Aluno1[i].p3);
   fprintf(fp, "\n%d",Aluno1[i].trab1);
   fprintf(fp, "\n%d",Aluno1[i].trab2);
   fprintf(fp, "\n%d",Aluno1[i].faltas);
   fprintf(fp, "\n%d",Aluno1[i].notaFinal);
   fprintf(fp, "\n%c",Aluno1[i].situ);
   fprintf(fp, "\n");
}

   fclose(fp);
   return;
}
//=================================================================================
int editarInfo(Aluno *Aluno1, char *nomeArq){
    int opcao;

    printf("\nDigite o nome do arquivo com a turma: ");
    getchar();
    fgets(nomeArq, 70 ,stdin);
    nomeArq[strcspn(nomeArq,"\n")] = '\0'; //tira o \n da string

  FILE * fp = fopen(nomeArq, "r" );//nome do aquivo+ modo abre+le

if (fp == NULL){
    printf("Arquivo vazio!\n");
   } 
 system("clear");
        printf("============================================\n");
        printf("=      Editar informações do Estudante     =\n");
        printf("============================================\n");
        printf("Opções:\n\n");
        printf("1 - Selecionar por número de matrícula\n");
        printf("2 - Selecionar por nome\n");
        printf("3 - Voltar para o menu principal\n");
        printf("Digite uma opção: ");

        scanf("%d", &opcao);
        while (opcao < 1 || opcao > 3)
        {
            printf("\nOpção inválida!\nDigite uma eita porra opção: ");
            scanf("%d", &opcao);
        } // Verifica a opção escolhida.
        switch (opcao)
        {
        case 1:
            editarMatricula(Aluno1, nomeArq);
            break;
        case 2:
            editarNome(Aluno1, nomeArq);
            break;
        case 3:
            return  110;
            break;
        }
     return;
    }
//================================================================================
void alterarinformacao(Aluno *Aluno1, char *nomeArq, int indice){
    int opcao;
    printf("\n");
    printf("============================================\n");
    printf("\tEditar informações do Estudante\n");
    printf("============================================\n");
    printf("Opções:\n\n");
    printf("1 - Alterar nome\n");
    printf("2 - Alterar matrícula\n");
    printf("3 - Alterar nota da prova 1\n");
    printf("4 - Alterar nota da prova 2\n");
    printf("5 - Alterar nota da prova 3\n");
    printf("6 - Alterar nota do trabalho 1\n");
    printf("7 - Alterar nota do trabalho 2\n");
    printf("8 - Alterar o número de faltas\n");
    printf("9 - Voltar ao menu anterior\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao);

    while (opcao < 1 || opcao > 9)
    {
        printf("\nOpção inválida.\nDigite uma opção: ");
        scanf("%d", &opcao);
    } // Verifica a opção escolhida.
    
    switch (opcao)
    {
    case 1:
        getchar();
        printf("Digite o nome: ");
        if (fgets(Aluno1[indice].nome, sizeof(Aluno1[indice].nome), stdin) == NULL)
        {
            printf("Erro ao ler string\n");
        }
        else
            Aluno1[indice].nome[strcspn(Aluno1[indice].nome, "\n")] = '\0';
        //printf("\n");
        break;
    case 2:
        getchar();
        printf("Digite a matrícula: ");
        scanf("%s", Aluno1[indice].matricula);
        break;
    case 3:
        printf("Digite a nota da prova 1: ");
        scanf("%d", &Aluno1[indice].p1);
        break;
    case 4:
        printf("Digite a nota da prova 2: ");
        scanf("%d", &Aluno1[indice].p2);
        break;
    case 5:
        printf("Digite a nota da prova 3: ");
        scanf("%d", &Aluno1[indice].p3);
        break;
    case 6:
        printf("Digite a nota do trabalho 1: ");
        scanf("%d", &Aluno1[indice].trab1);
        break;
    case 7:
        printf("Digite a nota do trabalho 2: ");
        scanf("%d", &Aluno1[indice].trab2);
        break;
    case 8:
        printf("Digite o número de faltas: ");
        scanf("%d", &Aluno1[indice].faltas);
        break;
    case 9:
        editarInfo(Aluno1, nomeArq);
    default:
        break;
    }
    Aluno1[indice].notaFinal = Aluno1[indice].p1 + Aluno1[indice].p2 + Aluno1[indice].p3 + Aluno1[indice].trab1 + Aluno1[indice].trab2;

    if (Aluno1[indice].faltas > 18)
    {
        Aluno1[indice].situ = 'F';
    }
    else if (Aluno1[indice].notaFinal < 60)
    {
        Aluno1[indice].situ = 'R';
    }
    else if (Aluno1[indice].notaFinal >= 60 && Aluno1[indice].faltas <= 18)
    {
        Aluno1[indice].situ = 'A';
    }

 
}
//================================================================================
int editarNome(Aluno *Aluno1, char *nomeArq){
    char nome[51] = {'\0'};
    int achou = 0;
    getchar();
    printf("Digite o nome: ");
  
    if (fgets(nome, sizeof(nome), stdin) == NULL)
    {
        fprintf(stderr, "Erro ao ler nome\n");
        exit(1);
    }
    nome[strcspn(nome, "\n")] = '\0';
   
    int i = 0, indice = 0;

    for (i = 0; i < 80; i++){
        if (!(strcmp(nome, Aluno1[i].nome))) {
            achou++;
            indice = i;
            i = 80;
        }
    }
    if (achou == 0)
    {
        printf("Nome inválido!\n");
        return 110;
    }
    else
    {
        alterarinformacao(Aluno1, nomeArq, indice);
    }
}
//==============================================================================
int editarMatricula(Aluno *Aluno1, char *nomeArq){
    char matric[13] = {'\0'};
    int achou = 0;
    getchar();
    printf("Digite o número da matrícula: ");

    if (fgets(matric, sizeof(matric), stdin) == NULL)
    {
        fprintf(stderr, "Erro ao ler matricula\n");
        exit(1);
    }
    matric[strcspn(matric, "\n")] = '\0';

    int i = 0, indice = 0;
    for (i = 0; i < 80; i++){
        if (!(strcmp(matric, Aluno1[i].matricula))){
            achou++;
            indice = i;
            i = 80;
        }
    }
    if (achou == 0)
    {
        printf("Número de matrícula inválido!\n");
        return 110;
    }
    else
    {
        alterarinformacao(Aluno1, nomeArq, indice);
    }
}
//============================================================================
int main(void){
    int numEst = 0;
   unsigned char nomeArq[70];
   int opc, opc2, opc3;
   Aluno Aluno1[80];//arranjo Aluno1 do tipo Aluno

do{
  system("clear");
  menuPrincipal();
  scanf("%d", &opc);

  switch(opc){
 
   case 1:
     do{
      system("clear");

      menuTurma();//chama o menu Turma e escaneia a opc digitada pelo usuario
      scanf("%d", &opc2);
      if(opc2 == 1){
        turmaExistente(Aluno1, nomeArq, &numEst);
          getchar();
      }
      if (opc2 == 2){
         criaTurma(Aluno1, nomeArq);
      }
      else{
        break;
      }//a ideia e como a opc 3 e voltar ao menu principal uso o break e saio do (do,while)
    }while(opc != 110);
  break;

  case 2:
   do{
     getchar();
     imprimiTurma(Aluno1, nomeArq, numEst);

     printf("\nDigite para exibir denovo ou 110 para sair: ");
     scanf("%d", &opc);
    printf("-------------------------------------------------------------\n");
   }while(opc != 110);
 break;
 
 case 3:
  do{
    estatisticas(Aluno1, numEst);

    printf("\nDigite 115 para exibir denovo ou 110 para sair: ");
    scanf("%d", &opc);
    printf("-------------------------------------------------------------\n");
  }while(opc != 110);
 break;

  case 4:
   do{
    system("clear");
    cadastrar(Aluno1, &numEst);

    printf("\nDigite 115 para exibir denovo ou 110 para sair: ");
    scanf("%d", &opc);
    printf("-------------------------------------------------------------\n");
   }while(opc != 110);
 break;

   case 5:
     do{
      //system("clear");
    
     opc = editarInfo(Aluno1, nomeArq);
       
     }while(opc != 110);
 break;

   case 6:
   do{
    zerarStruct(Aluno1, &numEst);
    relerTurma(Aluno1, nomeArq, &numEst);


   printf("\nDigite 115 para exibir denovo ou 110 para sair: ");
   scanf("%d", &opc);
   printf("-------------------------------------------------------------\n");
   }while(opc != 110);
 break;

   case 7:
     do{

        salvarSair(Aluno1, nomeArq, numEst);
        
        printf("\nAte mais!\nDigite 115 para exibir denovo ou 110 para sair: ");
        scanf("%d", &opc);

       printf("-------------------------------------------------------------\n");
     }while(opc != 110);
 break;
  }
 }while(opc != 0);
 
 return 0;
}

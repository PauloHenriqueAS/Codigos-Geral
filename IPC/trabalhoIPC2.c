/*
 *@file main.c
 *@brief menu com processador de imagens no formato .ppm(matriz) e o intuito de utilizar matriz/arranjo e ponteiros
 * @author *Paulo Henrique Alves Santos
           *Maycon Douglas Batista dos Santos
 * @date 02/12/2019
 * @bugs Nenhum conhecido.
*Este arquivo contem o segundo trabalho de IPC(introducao a programacao de computadores)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "pmn.h" //biblioteca disponibilizada por Alexandro Soares para realizacao deste trabalho

void menu(void){

  printf("***********************************************************************\n");
  printf("*         P R O C E S S A D O R   D E    I M A G E N S                *\n");
  printf("***********************************************************************\n\n");
  printf("Opcoes:\n\n");

  printf("1 - carregar uma imagem de fundo\n");//pronto
  printf("2 - recortar parte da imagem de fundo\n");//pronto
  printf("3 - inverter a imagem de fundo\n");//pronto
  printf("4 - imprimir a histograma de brilho medio\n");//pronto
  printf("5 - realizar um chroma key com a imagem de fundo\n");//pronto
  printf("6 - ocultar uma imagem na imagem de fundo\n");//pronto
  printf("7 - revelar a imagem oculta inserida em uma imagem\n");//pronto
  printf("8 - inserir texto na imagem de fundo\n");//pronto
  printf("9 - recuperar texto inserido em uma imagem\n");//pronto
  printf("0 - sair\n");
  printf("\nDigite uma opcao: ");
return;
}
//==================================================1-SALVAR IMAGEM ========================================================================
void salva(char(*nome)[60]){
unsigned int cols = 0;
  unsigned int linhas = 0;
  unsigned int valormax = 0;

  printf("Digite o nome do aquivo que deseja abrir: ");
  scanf("%s", *nome);

  FILE * fp = fopen( *nome, "r" );//nome do aquivo + modo leitura

 // Verifica se o arquivo de fato foi aberto
  if (fp == NULL){
    fprintf(stderr, "Erro de leitura no arquivo de imagem.\n");
    exit(1);
  }

  // Lê as dimensões da imagem
  int formato = leia_cabecalho(fp, &linhas, &cols, &valormax);//abre o arquivo e guarda o valor de linhas, colunas e valor max

  if (formato == PNM_P3) {
  } else {
    printf("O arquivo %s não está no formato PPM P3.\n", *nome);
  }

// Aloca espaço para caber a imagem
  unsigned char img[linhas][cols][3];

  if (leia_imagem(fp, linhas, cols, valormax, img)) //leia imagem recebe os valores da imagem - leia_imagem se encontra no ppm.h
    printf("Imagem %s lida.\n\n", *nome);//
  else
    printf("O arquivo %s está corrompido.\n", *nome);

  fclose(fp); // Fecha o arquivo, pois a imagem foi lida

  char nome_do_arq[] = "nomeAle2";
  printf("Digite o nome do arquivo para salvar: \n");
  scanf("%s", nome_do_arq); //salva a imagem com o nome dado pelo usuario

  if (escreve_imagem( nome_do_arq, linhas, cols, valormax, img) == false)
    printf("A imagem %s não está no formato PPM P3\n", nome_do_arq);
  else
    printf("A imagem %s foi escrita.\n\n", nome_do_arq);
return;
}
//======================================================2-RECORTAR IMAGEM====================================================================================================
void recortar(char(*nome)[60]){
  unsigned int cols = 0;
  unsigned int linhas = 0;
  unsigned int valormax = 0;

  printf("Digite o nome do aquivo que deseja abrir: ");
  scanf("%s", *nome);//salva o caminho digitado pelo usuario

  FILE * fp = fopen( *nome, "r" ); //abre arquivo e copia

  if (fp == NULL){
    fprintf(stderr, "Erro de leitura no arquivo de imagem.\n");
    exit(1);
  }

  // Lê as dimensões da imagem
  int formato = leia_cabecalho(fp, &linhas, &cols, &valormax);

  if (formato == PNM_P3) {
//ok
  } else {
    printf("O arquivo %s não está no formato PPM P3.\n", *nome);
  }

  // Aloca espaço para caber a imagem
  unsigned char img[linhas][cols][3];

  if (leia_imagem(fp, linhas, cols, valormax, img))
    printf("Imagem %s lida.\n", *nome);
  else
    printf("O arquivo %s está corrompido.\n", *nome);

  fclose(fp);// Fecha o arquivo, pois a imagem foi lida

  unsigned int x = 0, y = 0, largura = 0, altura = 0;
        printf("\nDigite a coordenada x do ponto de corte: ");
        scanf("%d", &x);
        printf("Digite a coordenada y do ponto de corte: ");
        scanf("%d", &y);
        printf("Digite a altura do retângulo de corte: ");
        scanf("%d", &altura);
        printf("Digite a largura do retângulo de corte: ");
        scanf("%d", &largura);

    unsigned char recorte[linhas][cols][3];

//Uso um for para percorrer o i ate que ele seja <= x,y,altura,largura
unsigned int  i, j;
 if(altura - x > linhas || largura - y > cols) //teste para ver se o valor para ser cortado esta dentro da matriz
 printf("ERRO\n");

else{
   for(i = 0; i<=altura; i++)
      for(j = 0; j<=largura; j++){
          recorte[i][j][0] = img[i+altura][j+largura][0];
          recorte[i][j][1] = img[i+altura][j+largura][1];
          recorte[i][j][2] = img[i+altura][j+largura][2];
  }

  // Escreva a imagem para um arquivo com outro nome
  char nome_do_arq[] = "nomeAle2";
  printf("Digite o nome do arquivo para salvar: ");
  scanf("%s", nome_do_arq);

  if (escreve_imagem( nome_do_arq, linhas, cols, valormax, recorte) == false)
    printf("A imagem %s não está no formato PPM P3\n", nome_do_arq);
  else
    printf("A imagem %s foi escrita.\n\n", nome_do_arq);
}
  return;
}
//============================================================3-NEGATIVO=====================================================================================
void negativo(char(*nome)[60]){

  unsigned int cols = 0;
  unsigned int linhas = 0;
  unsigned int valormax = 0;

  printf("Digite o nome do aquivo que deseja abrir: ");
  scanf("%s", *nome);

  FILE * fp = fopen( *nome, "r" );//nome do aquivo+ modo leitura

  if (fp == NULL){
    fprintf(stderr, "Erro de leitura no arquivo de imagem.\n");
    exit(1);
  }

  int formato = leia_cabecalho(fp, &linhas, &cols, &valormax);//abre o arquivo e guarda o valor de linhas, colunas e valor max

  if (formato == PNM_P3) {
   /* printf("O arquivo %s está no formato PPM P3, com os seguintes atributos:\n", arqfoto);
    printf("- largura: %d\n", cols);
    printf("- altura:  %d\n", linhas);
    printf("- cor máxima: %d\n\n", valormax);*/
  } else {
    printf("O arquivo %s não está no formato PPM P3.\n", *nome);
  }

// Aloca espaço para caber a imagem
  unsigned char img[linhas][cols][3];
  unsigned char invertida[linhas][cols][3];

  if (leia_imagem(fp, linhas, cols, valormax, img)) //leia imagem recebe os valores da imagem - leia_imagem se encontra no ppm.h
    printf("Imagem %s lida.\n\n", *nome);
  else
    printf("O arquivo %s está corrompido.\n", *nome);

  // Fecha o arquivo, pois a imagem foi lida
  fclose(fp);

 char novo_arq[] = "nomeAle2";
 printf("Digite o arquivo que deseja o negativo: ");
 scanf("%s", novo_arq);

unsigned int linha, coluna,cor;
 for(linha = 0; linha < linhas; ++linha)
   for(coluna = 0; coluna < cols; ++coluna)
     for(cor = 0; cor <= 2; ++cor)
        invertida[linha][coluna][cor] = 255 - img[linha][coluna][cor];

if (escreve_imagem( novo_arq, linhas, cols, valormax, invertida) == false)
    printf("A imagem %s não está no formato PPM P3\n", novo_arq);
  else
    printf("A imagem %s foi escrita.\n\n", novo_arq);

  return;
}
//============================================================================4-HISTOGRAMA===================================================================
void histograma(char(*nome)[60]){
  unsigned int cols = 0;
  unsigned int linhas = 0;
  unsigned int valormax = 0;

  printf("Digite o nome do aquivo que deseja abrir: ");
  scanf("%s", *nome);

  FILE * fp = fopen( *nome, "r" );//nome do aquivo + modo leitura

  if (fp == NULL){
    fprintf(stderr, "Erro de leitura no arquivo de imagem.\n");
    exit(1);
  }

  int formato = leia_cabecalho(fp, &linhas, &cols, &valormax);//abre o arquivo e guarda o valor de linhas, colunas e valor max

  if (formato == PNM_P3) {
  } else {
    printf("O arquivo %s não está no formato PPM P3.\n", *nome);
  }

// Aloca espaço
  unsigned char img[linhas][cols][3];

  if (leia_imagem(fp, linhas, cols, valormax, img))
    printf("Imagem %s lida.\n\n", *nome);
  else
    printf("O arquivo %s está corrompido.\n", *nome);

  fclose(fp); // Fecha o arquivo, pois a imagem foi lida
  //faz o histograma
   unsigned int linha, coluna;
   unsigned int  brilho = 0, frequencia[256]={0};
    printf("    Histograma\n");
    printf("----------------------\n");
        for(linha=0 ; linha<linhas ; linha++){
          for(coluna=0 ; coluna<cols ; coluna++){
        brilho =((img[linha][coluna][0])+ (img[linha][coluna][1]) + (img[linha][coluna][2]))/3;//Faz o brilho medio
        frequencia[brilho]++;//O arranjo frequencia recebe o valor brilho que acabou de ser calculado + 1 para ir para a proxima posicao
       }
     }
       for(int i = 0; i <= 255; i++){
       printf("%d \t %d \n", i, frequencia[i]);//printa a posicao mais quantos valores a dela
    }
printf("----------------------\n");
    return;
}
//============================================================5-CHROMAKEY=========================================================================
void chromakey(char(*nome)[60],char(*nome2)[60]){

  unsigned int cols = 0, cols2 =0;
  unsigned int linhas = 0, linhas2 = 0;
  unsigned int valormax = 0, valormax2 = 0;

/*---------------------Vai ler a primeira foto----------------------------------*/
  printf("Digite o nome do aquivo que deseja abrir: ");
  scanf("%s", *nome);

  FILE * fp = fopen( *nome, "r" );//nome do aquivo + modo leitura

  if (fp == NULL){
    fprintf(stderr, "Erro de leitura no arquivo de imagem.\n");
    exit(1);
  }

  int formato = leia_cabecalho(fp, &linhas, &cols, &valormax);//abre o arquivo e guarda o valor de linhas, colunas e valor max

  if (formato == PNM_P3) {//faz nada pois so verifica se ta tudo ok se nao da mensagem de erro
  } else {
    printf("O arquivo %s não está no formato PPM P3.\n", *nome);
  }

  unsigned char img1[linhas][cols][3];

  if (leia_imagem(fp, linhas, cols, valormax, img1))
    printf("Imagem %s lida.\n\n", *nome);
  else
    printf("O arquivo %s está corrompido.\n", *nome);

  fclose(fp); // Fecha o arquivo, pois a imagem foi lida
//--------------------------Fim arquivo 1----------------------------------------------------

//--------------------------Inicio arquivo 2------------------------------------------------
  printf("Digite o nome do segundo aquivo que deseja abrir: ");
  scanf("%s", *nome2);

  FILE * fp2 = fopen( *nome2, "r" );//nome do aquivo + modo leitura

  if (fp2 == NULL){
    fprintf(stderr, "Erro de leitura no arquivo de imagem.\n");
    exit(1);
  }
  int formato2 = leia_cabecalho(fp2, &linhas2, &cols2, &valormax2);//abre o arquivo e guarda o valor de linhas, colunas e valor max

  if (formato2 == PNM_P3) {//faz nada pois so verifica se ta tudo ok se nao da mensagem de erro
  } else {
    printf("O arquivo %s não está no formato PPM P3.\n", *nome2);
  }
  unsigned char img2[linhas2][cols2][3];
  unsigned char imgJuntas[linhas][cols][3];

  if (leia_imagem(fp2, linhas2, cols2, valormax2, img2)) //leia imagem recebe os valores da imagem - leia_imagem se encontra no ppm.h
    printf("Imagem %s lida.\n\n", *nome2);
  else
    printf("O arquivo %s está corrompido.\n", *nome2);

  fclose(fp2);
//-------------------------------Fim Arquivo 2------------------------------------------------
unsigned char  cor1, cor2, cor3;
unsigned int i, j,cor, brilho2, brilho1;//usados no for para passar por linha coluna e cor
brilho1 =(img1[0][0][0]+ img1[0][0][1] + img1[0][0][2])/3; //faz o brilho de img1
brilho2 = (img2[0][0][0]+ img2[0][0][1] + img2[0][0][2])/3;//faz o brilho de img2

    cor1 = img2[0][0][0]; //vai receber a cor do primeiro pixel
    cor2 = img2[0][0][1]; //vai receber a cor do segundo pixel
    cor3 = img2[0][0][2]; //vai receber a cor do terceiro pixel

   for(i=0; i<linhas2; ++i){
      for(j=0; j<cols2; ++j){
         for(cor=0; cor<3; ++cor){

        if(brilho2 != brilho1){//se o brilho de 2 for diferente de 1

    if (img2[i][j][0] != cor1) //compara com a primeira cor e escreve a imagem 2 em cima da imagem 1
	  img1[i][j][0] = img2[i][j][0];

if (img2[i][j][1] != cor2)//compara com a segunda cor e escreve a imagem 2 em cima da imagem 1
	  img1[i][j][1] = img2[i][j][1];//img1 sendo o fundo(maior) recebe o pixel naquela posicao

 if (img2[i][j][2] != cor3)//compara com a terceira cor escreve a imagem 2 em cima da imagem 1
	  img1[i][j][2] = img2[i][j][2];
           //imgJuntas[linha][coluna][cor] = img2[linha][coluna][cor];
}//if
       else{
        // imgJuntas[linha][coluna][cor] = img1[linha][coluna][cor];
}//elser

     }//for linha
    }//for coluna
  }//for cor

//-------------------------------Salva o ChromaKey--------------------------------------------
  char nome_do_arq[] = "nomeAle3";
  printf("Digite o nome do arquivo para salvar o Chroma Key: \n");
  scanf("%s", nome_do_arq);

  if (escreve_imagem( nome_do_arq, linhas, cols, valormax, img1) == false)
    printf("A imagem %s não está no formato PPM P3\n", nome_do_arq);
  else
    printf("A imagem %s foi escrita.\n\n", nome_do_arq);

  return;
}

//===============================================6-ESCONDE IMAGEM===========================================================================
void escondeImagem(char(*nome)[60], char(*nome2)[60]){

  unsigned int cols = 0, cols2 = 0;
  unsigned int linhas = 0, linhas2 = 0;
  unsigned int valormax = 0, valormax2 = 0;

  printf("Digite o caminho da foto da frente: ");
  scanf("%s", *nome);

  FILE * fp = fopen( *nome, "r" );

  if (fp == NULL){
    fprintf(stderr, "Erro de leitura no arquivo de imagem.\n");
    exit(1);
  }

  // Lê as dimensões da imagem
  int formato = leia_cabecalho(fp, &linhas, &cols, &valormax);

  if (formato == PNM_P3) {
  } else {
    printf("O arquivo %s não está no formato PPM P3.\n", *nome);
  }

  // Aloca espaço para caber a imagem
  unsigned char imgFrente[linhas][cols][3];

  if (leia_imagem(fp, linhas, cols, valormax, imgFrente))
    printf("Imagem %s lida.\n\n", *nome);
  else
    printf("O arquivo %s está corrompido.\n", *nome);

  // Fecha o arquivo, pois a imagem foi lida
  fclose(fp);
//----------------------------ABRE A SEGUNDA IMAGEM--------------------------------
  printf("Digite o caminho da foto da frente: ");
  scanf("%s", *nome2);

  FILE * fp2 = fopen( *nome2, "r" );

  if (fp2 == NULL){
    fprintf(stderr, "Erro de leitura no arquivo de imagem.\n");
    exit(1);
  }

  // Lê as dimensões da imagem
  int formato2 = leia_cabecalho(fp2, &linhas2, &cols2, &valormax2);

  if (formato2 == PNM_P3) {
  } else {
    printf("O arquivo %s não está no formato PPM P3.\n", *nome2);
  }

//verificar se a imgFrente e maior que imfFundo
if(linhas2 > linhas || cols2 > cols){
  printf("A imagem a ser escondida deve ser menor que a primeira imagem\n");
return;
}

  // Aloca espaço para caber a imagem
  unsigned char imgFundo[linhas2][cols2][3];

  if (leia_imagem(fp2, linhas2, cols2, valormax2, imgFundo))
    printf("Imagem %s lida.\n\n", *nome2);
  else
    printf("O arquivo %s está corrompido.\n", *nome2);

  // Fecha o arquivo, pois a imagem foi lida
  fclose(fp2);

unsigned int i, j, cor = 0;

   for(i = 0; i < linhas; i++)
      for(j = 0; j < cols; j++)
        for(cor = 0; cor <3; cor++){

       imgFrente[i][j][cor] = imgFrente[i][j][cor] >> 4; //ou /=16 Passa os 4bits mais significativos para a direita
       imgFrente[i][j][cor] = imgFrente[i][j][cor] << 4;//ou *= 16 Volta os 4bits mais significativos para a esquerda deixando os 4bits menos significativos com 0

}

 for(i = 0; i < linhas2; i++)
      for(j = 0; j < cols2; j++){
        for(cor = 0; cor <3; cor++){
       imgFundo[i][j][cor] = imgFundo[i][j][cor] >> 4;
       imgFrente[i][j][cor] |= imgFundo[i][j][cor]; 

        }//for cor
      }//forr coluna
  // Escreva a imagem para um arquivo com outro nome

  char nome_do_arq[] = "aleatorio";
  printf("Digite o nome do arquivo para ser salvo: ");
  scanf("%s", nome_do_arq);

  if (escreve_imagem( nome_do_arq, linhas, cols, valormax, imgFrente) == false)
    printf("A imagem %s não está no formato PPM P3\n", nome_do_arq);
  else
    printf("A imagem %s foi escrita.\n\n", nome_do_arq);

  return;
}
//=======================================================7-REVELAR IMAGEM===========================================================================
void revelaImg (char(*nome)[60]){

  unsigned int cols = 0;
  unsigned int linhas = 0;
  unsigned int valormax = 0;
  unsigned int i, j, cor=0;

  printf("Digite o caminho da foto para desrevelar: ");
  scanf("%s", *nome);

  FILE * fp = fopen( *nome, "r" );

  /* Verifica se o arquivo de fato foi aberto */
  if (fp == NULL){
    fprintf(stderr, "Erro de leitura no arquivo de imagem.\n");
    exit(1);
  }

  int formato = leia_cabecalho(fp, &linhas, &cols, &valormax);

  if (formato == PNM_P3) {
  } else {
    printf("O arquivo %s não está no formato PPM P3.\n", *nome);
  }

  // Aloca espaço para caber a imagem
  unsigned char img[linhas][cols][3];

  if (leia_imagem(fp, linhas, cols, valormax, img))
    printf("Imagem %s lida.\n\n", *nome);
  else
    printf("O arquivo %s está corrompido.\n", *nome);

  // Fecha o arquivo, pois a imagem foi lida
  fclose(fp);

  for(i = 0; i < linhas; i++)
      for(j = 0; j < cols; j++){
         for(cor = 0; cor < 3; cor++){

       img [i][j][cor] = img [i][j][cor] << 4;//Como os bits com o valor da imagem escondida esta nos 4bits menos significativos, move-se eles para esquerda para revelar a imagem

         }
     }

  char nome_do_arq[] = "aleatorio";
  printf("Digite o nome do arquivo para ser salvo: ");
  scanf("%s", nome_do_arq);

  if (escreve_imagem( nome_do_arq, linhas, cols, valormax, img) == false)
    printf("A imagem %s não está no formato PPM P3\n", nome_do_arq);
  else
    printf("A imagem %s foi escrita.\n\n", nome_do_arq);

  return;
}
//============================================8-ESCONDE MENSAGEM==============================================================
void esconderMsn(char (*nome)[60]){

    unsigned int cols = 0;
    unsigned int linhas = 0;
    unsigned int valormax = 0;

    unsigned char texto[700] = {'\0'};//arranjo texto com 70 posicoes

    printf("Digite a imagem desejada: ");
    scanf("%s", *nome);
    FILE * fp = fopen( *nome, "r" );

    leia_cabecalho(fp, &linhas, &cols, &valormax);

    unsigned char img[linhas][cols][3];
    leia_imagem(fp, linhas, cols, valormax, img);
    fclose(fp);

  //recebe a mensagem a ser escondida
    unsigned char txt;

    unsigned int cont = 0;
    unsigned char v0,v1,v2;
    unsigned int i, j;

   printf("Digite o texto a ser escondido: ");
   scanf("%s", txt);

    while (txt != '\n'){ //enguanto txt for diferente de \n
    txt = getchar(); //txt recebe o que foi digitado pelo teclado
    texto[cont] = txt; //texto na posiçao cont recebe txt
    cont++;
    }


    if ((cols*2 < strlen(texto)/3)){ //vai quardar em colunas e em duas linhas sendo assim preciza verificar se existe espao para guardar
    printf("\no Texto é muito grande para ser escondido!\n digite um texto menor\n");
    return;
    }//fim if

cont = 0;//contador e zerado

    for (i = 0; i < linhas; i++){//linhas (sera usadas linhas;
     for (j = 0; j < cols ; j++){//passa por coluna ate que seja igual ao tamanho do tesxto.


		img [i][j][0] = img [i][j][0] >> 2;//anda dois bits para direita para armazenar a mensagem e depois volta os dois para não  modificar a imagem
		img [i][j][0] = img [i][j][0] << 2;

		img [i][j][1] = img [i][j][1] >> 3;//anda tres bits para direita para armazenar a mensagem e depois volta os tres para não  modificar a imagem
		img [i][j][1] = img [i][j][1] << 3;

		img [i][j][2] = img [i][j][2] >> 3;//anda três bits para direita para armazenar a mensagem e depois volta os treŝ para não  modificar a imagem
		img [i][j][2] = img [i][j][2] << 3;

v0 = texto[j] >> 6;// v0 recebe texto na posiçõ j deslocando ele 6 bits para esquerda
v1 = texto [j] << 2;// v1 recebe texto na posicao j voltando dois bits para esquerda e assim armazenando os outros 4 bits
v1 = v1 >> 5;// v1 recebe deslocando 5 bits para direita
v2 = texto[j] << 5;// v2 recebe texto na posicao j deslocando 5 bits para esqueda
v2 = v2 >> 5;// v2 recebe v2 deslocando 5 bits para direita.

		img [i][j][0] = img [i][j][0] | v0;// imagem na posica i j e cor 0 recebe ela mesma ou o valor de v0( compara bit a bit)
		img [i][j][1] = img [i][j][1] | v1;// imagem na posica i j e cor 0 recebe ela mesma ou o valor de v1( compara bit a bit)
		img [i][j][2] = img [i][j][2] | v2;// imagem na posica i j e cor 0 recebe ela mesma ou o valor de v2( compara bit a bit)


       }//fim for
      }//fim for
    
    char nome_do_arq[50];
    printf("digite o nome para a imagem de saída: ");
    scanf(" %s", nome_do_arq);

    if (escreve_imagem( nome_do_arq, linhas, cols, valormax, img) == false){
    printf("\nA imagem %s não está no formato PPM P3\n", nome_do_arq);
    }else{
    printf("\nO texto foi ocultado com sucesso.\n", nome_do_arq);
    }//fim else

  return;
}
//=================================================9-REVELAR IMAGEM=========================================================
void revelaMsn (char (*nome)[60]){

    unsigned int cols = 0;
    unsigned int linhas = 0;
    unsigned int valormax = 0;

    unsigned char v0, v1, v2, vfinal = '\0';
    unsigned int i, j = 0;


    printf("Digite um caminho para a imagem a ser revelada: ");
    scanf("%s", *nome);

    FILE * fp = fopen( *nome, "r" );

   /* Verifica se o arquivo de fato foi aberto */
    if (fp == NULL){
    fprintf(stderr, "Erro de leitura no arquivo de imagem.\n");
    return;
    }

    leia_cabecalho(fp, &linhas, &cols, &valormax);

    unsigned char img[linhas][cols][3];
    leia_imagem(fp, linhas, cols, valormax, img);

    unsigned char texto[cols];// arranjo texto comeca com  cols

    fclose(fp);// Fecha o arquivo, pois a imagem foi lida


   printf("\nO texto oculto é: ");

    for (i = 0; i < linhas; i++){
	    for (j = 0; j < cols; j++){
              //v0,v1,v2 iniciam com \0
		v0 = '\0';
		v1 = '\0';
		v2 = '\0';
    vfinal= '\0';

//deslocmos os bits pois na funcao esconderMsn deslocamos os bits mas significativos para armazenar a mensagem, agora precizamos voltar os bits(resultado tem que ficar com 8 bits)
		v0 = img [i][j][0] << 6; //v0 recebe imagem na posicao i j cor=0 deslocando 6 bits para esquerda/ Em esconderMsn deslocamos v0 2 bits precizando assim voltar 6
		v1 = img [i][j][1] << 5; //v1 recebe imagem na posicao i j cor=1 deslocando 5 bits para esquerda/ Em esconderMsn deslocamos v1 3 bits precizando assim voltar 5
		v1 = v1 >> 2; //v1 recebe ele mesmo deslocando n bits para direita
		v2 = img [i][j][2] << 5; //v2 recebe imagem na posicao i j cor=2 deslocando 5 bits para esquerda
		v2 = v2 >> 5; //v2 recebe ele msm movendo 5bits para direita

		vfinal = v0 | v1 | v2; //final vai receber v0,v1,v2 comparndo bit a bit

		texto[j] = (unsigned char) vfinal; //texto na posicao recebe vfinal

		if (texto[j] == '\n'){
		return;
		}
		printf("%c", texto[j]); //Imprime a mensagem

         }//fim for
        }//fim for

  return;
}
//========================================================   MAIN   ===================================================================================================

int main(void){
  int opc;
  char nome[60], nome2[60];

do{
  system("clear");//clear em linux/ Limpa a tela
  menu();
  scanf("%d", &opc);

switch (opc) {

 //1 = Carrega/Abre uma imagem ppm
 case 1:
    do{
   printf("-------------------------------------------------------------\n");
       salva(&nome); //manda o endereco do arranjo nome
       getchar(); //Limpa o buffer do teclado

       printf("Digite uma tecla(110) para voltar ao menu principal: ");//Digitando o valor 110 sai do case e retorna ao menu
       scanf("%d", &opc);
       printf("-------------------------------------------------------------\n");
}   while(opc != 110); //executa ate o usuario desejar parar e digitar 110
 break;

 //2 = Pega a imagem aberta e recorta ela
 case 2:
    do{
        printf("-------------------------------------------------------------\n");
        recortar(&nome);
        getchar();

        printf("Digite uma tecla(110) para voltar ao menu principal: ");
        scanf("%d", &opc);
        printf("-------------------------------------------------------------\n");
}   while(opc != 110);
 break;

 //3 = Pega uma imagem indicada pelo usuario e retorna sua versao negativa(comlemento)
 case 3:
    do{
        printf("-------------------------------------------------------------\n");
        negativo(&nome);
        getchar();

        printf("Digite uma tecla(110) para voltar ao menu principal: ");
        scanf("%d", &opc);
        printf("-------------------------------------------------------------\n");
}   while(opc != 110);
 break;

 //4 = Imprime na tela o histograma de brilho medio
 case 4:
    do{
        printf("-------------------------------------------------------------\n");
        histograma(&nome);
        getchar();

        printf("Digite uma tecla(110) para voltar ao menu principal: ");
        scanf("%d", &opc);
        printf("-------------------------------------------------------------\n");
}   while(opc != 110);
 break;

 //5 = Realiza um chroma key  com duas imagens indicadas pelo usuario(cola uma sobre a outra)
 case 5:
    do{
       printf("-------------------------------------------------------------\n");
       chromakey(&nome, &nome2);
       getchar();

       printf("Digite uma tecla(110) para voltar ao menu principal: ");
       scanf("%d", &opc);
       printf("-------------------------------------------------------------\n");
}   while(opc != 110);
 break;

 //6 = Oculta/esconde uma imagem dentro de outra
 case 6:
    do{
        printf("-------------------------------------------------------------\n");
        escondeImagem(&nome, &nome2);
        getchar();

        printf("Digite uma tecla(110) para voltar ao menu principal: ");
        scanf("%d", &opc);
        printf("-------------------------------------------------------------\n");
}   while(opc != 110);
 break;

 //7 = Revela uma imagem oculta/escondida dentro de outra imagem
 case 7:
    do{
       printf("-------------------------------------------------------------\n");
       revelaImg(&nome);
       getchar();

       printf("Digite uma tecla(110) para voltar ao menu principal: ");
       scanf("%d", &opc);
       printf("-------------------------------------------------------------\n");
}   while(opc != 110);
 break;

 //8 = Insere/Esconde um texto digitado pelo usuario dentro de uma imagem
 case 8:
    do{
       printf("-------------------------------------------------------------\n");
       esconderMsn(&nome);

       printf("Digite uma tecla(110) para voltar ao menu principal: ");
       scanf("%d", &opc);
       printf("-------------------------------------------------------------\n");
}   while(opc != 110);
 break;

 //9 = Recupera/Exibe uma mensagem escondida dentro de uma imagem
 case 9:
    do{
       printf("-------------------------------------------------------------\n");
       revelaMsn(&nome);
       getchar();

       printf("\n\nDigite uma tecla(110) para voltar ao menu principal: ");
       scanf("%d", &opc);
       printf("-------------------------------------------------------------\n");
}   while(opc != 110);
 break;

}
}while(opc != 0); //Ao digitar 0 o programa termina
  return 0;
}

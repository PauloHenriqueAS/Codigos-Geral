/*
*Programa feito por:
   * Maycon Douglas Batista dos Santos
   * Paulo Henrique Alves Santos
 Este codigo e sobre o primeiro trabalho de IPC um conversor de Binario/Decimal/Hexadecimal/fracao binaria e decimal 
 (Linux) compilamos usando : 
 gcc -std=c11 -c trabalhoPronto.c
 gcc -std=c11 -o trabalhoPronto.exe trabalhoPronto.c -lm
*/

//Bibliotecas utilizadas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Menu encontra-se todas as opcoes do menu para o usuario selecionar
void menu (void){
printf("**************************************************************************\n");
printf("*                          C o n v e r s o r                             *\n");
printf("**************************************************************************\n\n");
printf("Opcoes: \n\n");
printf("1 - converter de binario para a decimal\n"); //feito
printf("2 - converter de hexadecimal para a decimal\n");// feito
printf("3 - converter de decimal para a binario\n"); //feito
printf("4 - converter de decimal para a hexadecimal\n"); //feito
printf("5 - converter de binario para a hexadecimal\n");//feito
printf("6 - converter de hexadecimal para a binario\n"); //feito
printf("7 - converter de fracao binaria para a decimal\n");
printf("8 - converter de fracao decimal para a binario\n");//feito
printf("9 - somar dois binarios sem sinal\n");
printf("0 - sair\n\n");
printf("Digite uma opcao: ");
return;
}//Menu

//Funcao bin_to_dec recebe um binario digitado pelo usuario e retorna um decimal
int bin_to_dec(int bin) {
    unsigned int total  = 0;  //Total comeca em 0
    unsigned int potenc = 1;  //Potencial comeca em 1 pois na primeira base e 1

 while(bin > 0  && bin <= 11111111) {  //Enquanto o valor digitado pelo usuario for maior que 0 e menor 11111111(representar os 8bits) 
   total += bin % 10 * potenc; //Total recebe total + resto do valor digitado por 10 * potencia
   bin = bin / 10;  //Bin recebe valor digitado dividido por 10 (vai diminuindo casa por casa)
   potenc = potenc * 2; //Comeca com 1 e multiplica por 2, pois na conversao cada casa avanca de 2 em 2
 
 }//While
    return total; //retorna total
}//bin_to_dec

//Funcao dec_to_bin recebe um decimal digitado pelo usuario e converte esse valor para binario
int dec_to_bin(int deci){ 
    int i, temp, bin[32]={0}; //Arranjo bin para guardar o binario
    temp = deci; //Temp recebe deci pois deci vai ser modificado
    for(i =0; deci>=2; i++){ //Contador i para guarda o valor  na posicao i / deci >=2 para parar no ultima posicao das divisoes sucessivas
       bin[i]= deci%2; //Arranjo na posicao i recebe o resto da divisao  de deci por 2
       deci = deci/2; //Valor recebe valor dividido por 2
    } //for

    bin[i]= deci; //Arranjo na ultima posicao recebe deci
    printf("%d_(10) = ", temp); //printa a temp
    for(; i >=0; i--){  //i ja comeca na ultima posicao para imprimir de tras para frente
       printf("%d", bin[i]); //Printa valor na posicao i
    }//for
     printf("_(2)\n"); //imprime a base
    return 0;
} //dec_to_bin

//Main vai conter os casos switch
int main(void){ 
 //inicia as variaveis que serao usadas
   int opcmenu, opc, dec, bin, deci;
   int hexa, temp;
   double num1, num2;

do{ //Faca enquanto
 system("clear"); //Clear em linux e cls windows
 menu(); //Printa o menu/usuario digita o valor no menu
 scanf("%d", &opc); //Escanei/guarda o valor digitado pelo usuario no menu
switch (opc) { 

/*
  Break = Quebra e passa o proximo caso
  printf("\n"); = quebra a linha
*/

case 1:
   do{

     printf("---------------------------------------\n");
     printf("Digite um binario: ");
     scanf("%d", &bin); //Guarda o valor binario digitado
     printf("\n");
     dec = bin_to_dec(bin); //dec recebe o valor que vai ser convertido no bin_to_dec

     printf("%d_(2) = %d_(10) \n", bin, dec);
     printf("\n");
     printf("Deseja converter outro binario (s = 115 /n = 110)?\n"); //Repetir a operacao digita 115 e sair 110
     scanf("%d", &opc); //Guarda a opcao digitada pelo usuario / 115(S na tabela ascii)

   }while(opc != 110);  //Executa enquanto opc for diferente de 110(N na tabela ascii)
break; //Quebra e passa o proximo caso

case 2: 
  do{

    //%X armazena/converte um hexadecimal
    printf("---------------------------------------\n");
    printf("Digite um hexadecimal: ");
    scanf("%X", &hexa); //Guarda o hexadecimal digitado
    printf("\n");
    printf("%X_(16) = %d_(10)\n", hexa, hexa); //printa o valor digitado(hexadecimal) e printa o valor correspondende em decimal
    printf("\n");
    printf("Deseja converter outro hexadecimal (s = 115/n = 110)?\n");//Repetir a operacao digita 115 e sair 110
    scanf("%d", &opc);//Guarda a opcao digitada pelo usuario / 115(S na tabela ascii)

  }while(opc != 110); //Executa enquanto opc for diferente de 110(N na tabela ascii)
break;

case 3:
  do{

     printf("---------------------------------------\n");
     printf("Digite um natural: ");
     scanf("%d", &deci); //Guarda o valor digitado
     printf("\n");
     dec_to_bin(deci); //Imprime o valor convertido em dec_to_bin
     printf("\n");
     printf("Deseja converter outro natural (s = 115/n =110)?\n");//Repetir a operacao digita 115 e sair 110
     scanf("%d", &opc);//Guarda a opcao digitada pelo usuario / 115(S na tabela ascii)
    
  }while (opc != 110); //Executa enquanto opc for diferente de 110(N na tabela ascii)
 break;

case 4: 
    do{

        //%X armazena/converte um hexadecimal
        printf("---------------------------------------\n");
        printf("Digite um natural: ");
        scanf("%d", &deci); //Guarda o valor digitado
        printf("\n");
        printf("%d_(16) = %X_(10)\n", deci, deci); //Imprime o valor digitado e  imprime em seguida o valor corespondente em hexadecimal
        printf("\n");
        printf("Deseja converter outro natural (s = 115/n = 110)?\n");//Repetir a operacao digita 115 e sair 110
        scanf("%d", &opc);//Guarda a opcao digitada pelo usuario / 115(S na tabela ascii)

    }while(opc != 110); //Executa enquanto opc for diferente de 110(N na tabela ascii)
 break;

case 5:
  do{

      printf("---------------------------------------\n");
      printf("Digite um binario: ");
      scanf("%d", &bin); //Guarda o valor digitado
      printf("\n");
      deci = bin_to_dec(bin); //deci recebe o valor que vai ser convertido no bin_to_dec
      printf("%d_(2) = %X_(16) \n", deci, deci); //Imprime o valor convertido e  imprime em seguida o valor corespondente em hexadecimal
      printf("\n");
      printf("Deseja converter outro binario (s = 115/n = 110)?\n");//Repetir a operacao digita 115 e sair 110
      scanf("%d", &opc);//Guarda a opcao digitada pelo usuario / 115(S na tabela ascii)
      
  }while(opc != 110); //Executa enquanto opc for diferente de 110(N na tabela ascii)
 break;

case 6:
  do{
    int hexad, bim[16]={0}, i, tempr; //Arrajo bim vai guarda
    int decim;

    printf("---------------------------------------\n");
    printf("Digite um hexadecimal: ");
    scanf("%X", &hexad); //Guarda o hexadecimal digitado
    printf("\n");

    decim = hexad; //decim recebe o valor digitado
    tempr = decim; // tempr recebe o valor decim

    for(i=0; decim>=2 ;i++){ //Contador i para guarda o valor  na posicao i / decim >=2 para parar no ultima posicao das divisoes sucessivas
        bim[i] = decim % 2; //Arranjo na posicao i recebe o resto do valor digitado por 2
        decim = decim/2; //decim recebe ele mesmo por 2
    } //for

    bim[i]=decim; //Arranjo na ultima posicao recebe deci
    printf("%X_(16) = ", tempr); //Imprime o valor em hexadecimal
    for(; i>=0; i--){ //i ja comeca na ultima posicao para imprimir de tras para frente
        printf("%d",bim[i]); //Printa valor na posicao i
    }//for
    printf("_(2)\n"); //Imprime a base
    printf("\n");

    printf("Deseja converter outro hexadecimal (s = 115/n = 110)?\n");//Repetir a operacao digita 115 e sair 110
    scanf("%d", &opc);//Guarda a opcao digitada pelo usuario / 115(S na tabela ascii)

   }while(opc != 110); //Executa enquanto opc for diferente de 110(N na tabela ascii)
 break;

//Nao conseguimos fazer, entao esse case so pede o valor pro usuario, armazena ele e imprime
case 7: 
   do{
    
    double binFraci;
    printf("---------------------------------------\n");
    printf("Digite um binario fracionario: ");
    scanf("%lf", &binFraci);
    printf("\n");
    printf("%lf_(2) = _(10)\n", binFraci);
    printf("\n");
    printf("Deseja converter outro binario fracionario (s = 115/n = 110)?\n");//Repetir a operacao digita 115 e sair 110
    scanf("%d", &opc);//Guarda a opcao digitada pelo usuario / 115(S na tabela ascii)

   }while(opc != 110);// executa enquanto opc for diferente de 110(N na tabela ascii)
break;

case 8:
  do{
    
    double x, partFrac, deci;
    printf("---------------------------------------\n");
    printf("Digite um real: ");
    scanf("%lf", &x); //Guarda o valor digitado
    printf("\n");

    partFrac = modf(x, &deci); //modf serpara a parte fracionada da parte inteira para trabalharmos com elas separadas

    int j = deci; //j recebe a parte inteira
    int i,bin[32]={0};
    double temp = deci; //temp recebe o parte inteira

    for(i =0; j>=2; i++){ //J maior igual 2 vai ser executado e i e incrementado
       bin[i]= j%2; //Arranjo na posicao i recebe 
       j = j/2; //j recebe ele  dividido por 2
    } //for
    bin[i]= j; //Arranjo na ultima posicao i recebe j
    printf("%lf_(10) = ", x); //Imprime o valor digitado pelo usuario

    for(; i >=0; i--){
       printf("%d", bin[i]);
    }//for
     char output[16] = ""; //Arranjo de char possuindo 16 posições
    
    //vai converte a parte fracionada(Decimal) para binario
    while (partFrac) { //Enquanto parteFrac
        int frac;
        double val = partFrac * 2; // val recebe parte francinada * 2
        if (val < 1) frac = '0'; else frac = '1'; //se o valor for menor que q 1 fracao recebe 0 se nao recebe 1
        sprintf(output, "%s%c", output, frac); //endereco(arranjo), tipo(string e char), variavel(arranjo, e fracao)
        partFrac = val; //Parte fracionada recebe val
        if (partFrac >= 1) partFrac -= 1; //Se parte fracionada maior igual a 1 parte fracionada e decrementada em 1
    }//While

  printf(".%s_(2)\n\n", output); //Imprime . base e o arranjo com a valor
  printf("Deseja converter outro real (s = 115/n = 110)?\n");//Repetir a operacao digita 115 e sair 110
  scanf("%d", &opc);//Guarda a opcao digitada pelo usuario / 115(S na tabela ascii)

 }while(opc != 110);// executa enquanto opc for diferente de 110(N na tabela ascii)
break;

/*
Este caso nao conseguimos concluir pois tivemos dificuldades com o caso 7 que reutilizariamos aqui
porem atendemos a forma de printf desejado e executa com valores sem ser fracionado
*/
case 9:
  do{

    double tempr, temp1, temp2, temp3, temp4; //Variaveis usadas

    printf("---------------------------------------\n");
    printf("Digite o primeiro binario: ");
    scanf("%lf", &num1); //Escaneia o primeiro binario
    printf("\n");
    printf("Digite o segundo binario: "); 
    scanf("%lf", &num2); //Ecaneia  o segundo binario
    printf("\n");

    temp1 = num1; //Temporaria 1 recebe o priemiro binario
    temp2 = num2; //Temporaria 2 recebe o segundo binario
    num1 = bin_to_dec(num1); //Primeiro valor e transformado em decimal
    num2 = bin_to_dec(num2); //Segundo valor e transformado em decimal

    tempr = num1 + num2; //tempr recebe os valores em decimais e os soma
    temp3 = dec_to_bin(tempr); //Temporaria 3 recebe o valor de tempr convertido em binario
    //Neste case esse valor deveria ser convertido para um binario fracionado

    printf("%20lf     %18lf\n", temp1, num1); //Primeiro binario vai ser imprimido com ate 20 casas e seu valor em decimal ate 18 casas
    printf("+ "); //Printa +
    printf("%18lf    +%18lf", temp2, num2); //segundo binario vai ser imprimido com ate 18 casas e seu valor em decimal tambem
    printf("\n---------------------   -------------------\n");
    printf("%20lf   %20lf\n", temp3, tempr); //primeiro imprime sua soma em binario com ate 20 casas e sua soma em decimal em ate 20 casa
    printf("Deseja converter outros binarios (s = 115/n = 110)?\n");//Repetir a operacao digita 115 e sair 110
    scanf("%d", &opc);//Guarda a opcao digitada pelo usuario / 115(S na tabela ascii)

 }while(opc != 110);// executa enquanto opc for diferente de 110(N na tabela ascii)
break;

} //Switch contendo todos os case

}while(opc != 0); //Do antes do switch
//Executa ate que seja prescionado 0 que finaliza o programa

return 0; //avisa que terminou tudo OK
} //Menu
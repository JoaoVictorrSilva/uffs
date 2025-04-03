#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//PROG:
int main(){

//TÍTULO GAME:
printf("\n================================\n");
printf("Bem-vindo ao Jogo de Adivinhação\n");
printf("================================\n");

printf("\n\nINFORMAÇÕES:\n");
printf("Descubra qual é o número secreto do intervalo [0, 100) em um limite de tentativas!\n\n");

//NÚMERO SECRETO:
int segundos = time(0);
srand(segundos);
int numerosecreto = rand() % 100;

double pontos = 1000;
int contador_jogadas = 1;
int chute;

//DIFICULDADE:
int dificuldade;
int n_tentativas;

printf("\n");
printf("DIFICULDADE:\n");
printf("(1) Fácil - 15 tentativas.\n");
printf("(2) Médio - 10 tentativas.\n");
printf("(3) Difícil - 5 tentativas.\n");
printf("Escolha: ");
scanf("%d", &dificuldade);

while(dificuldade < 1 || dificuldade > 3){
    printf("\n\nDIFICULDADE INDISPONIVEL!!!\n\n\n");
    printf("DIFICULDADE:\n");
    printf("(1) Fácil - 15 tentativas.\n");
    printf("(2) Médio - 10 tentativas.\n");
    printf("(3) Difícil - 5 tentativas.\n");
    printf("Escolha: ");
    scanf("%d", &dificuldade);}

if(dificuldade == 1){
    printf("\n\nMODO FÁCIL:\n");
    n_tentativas = 15;}
else if(dificuldade == 2){
    printf("\n\nMODO MÉDIO:\n");
    n_tentativas = 10;}
else if(dificuldade == 3){
    printf("\n\nMODO DIFÍCIL:\n");
    n_tentativas = 5;}

//LOOP JOGADAS:
for(int i = 1; i <= n_tentativas; i++){
    printf("\n%dª tentativa: ", i);
    scanf("%d", &chute);

    if(chute == numerosecreto){
        printf("\nParabéns! Você acertou e ficou com %.2f ponto(s)!", pontos);
        printf("\nObrigado por jogar!\n");
        break;}

    else if(chute < 0){
        printf("\nNúmero negativo não vale!!!");
        printf("\nJogue novamente.\n");
        i--;
        continue;}
        
    else if(chute > numerosecreto){
        printf("\nSeu chute foi maior que o número secreto.\n");}
        
    else if(chute < numerosecreto){
        printf("\nSeu chute foi menor que o número secreto.\n");}

    //CALCULO PONTOS
    pontos = pontos - (abs(chute - numerosecreto) / 2.0);      
    
    //FIM DO LOOP
    }

printf("\n");
return 0;   
}
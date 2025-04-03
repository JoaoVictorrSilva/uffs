//NOME: JOÃO VICTOR DA SILVA.
//MATRÍCULA: 2211100072.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//SOBRE O AVIÃO:
typedef struct elemFila {
 int identificador;
 char nome[31];
 struct elemFila *proximo;
} ElemFila;

//ENCADEAMENTO DA LISTA DE AVIÕES:
typedef struct {
 ElemFila *primeiro;
 ElemFila *ultimo;
} Fila;

//INSERIR NA FILA:
void insereFila(Fila *fila, int identificador, char nome[]){
    ElemFila *aux;
    aux = malloc(sizeof(ElemFila));
    aux->identificador = identificador;
    strcpy(aux->nome, nome);
    aux->proximo = NULL;

    if (fila->primeiro == NULL) { // Se a fila esta vazia
    fila->primeiro = aux;
    fila->ultimo = aux;}

    else { // Se a fila nao esta vazia
    fila->ultimo->proximo = aux;
    fila->ultimo = aux;}
}

//REMOVER DA FILA:
void removeFila(Fila *fila){
    ElemFila *aux;
    aux = fila->primeiro;

    if (fila->primeiro == fila->ultimo){
    fila->primeiro = NULL;
    fila->ultimo = NULL;}

    else{
    fila->primeiro = fila->primeiro->proximo;}

    free(aux);
}

//INICIALIZAR FILA:
void inicializaFila(Fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

//TESTAR SE TEM ELEMENTOS NA FILA:
int filaVazia(Fila *fila){
    if(fila->primeiro == NULL){
        return 0;} 
    else{
        return 1;}
}

//APAGAR FILA:
void liberaFila(Fila *fila){
    ElemFila *aux;
    while (fila->primeiro != NULL) {

    aux = fila->primeiro;
    fila->primeiro = fila->primeiro->proximo;

    free(aux);}
    
    fila->ultimo = NULL;
}

//FUNÇÃO AVIÕES NA FILA:
int qtdItensFila(Fila *fila){
    ElemFila *aux;
    int contador;
    for(aux = fila->primeiro; aux!= NULL; aux = aux->proximo){
        contador++;}
    return contador;
}

//FUNÇÃO LISTAR AVIÕES NA FILA:
void printLista(Fila *fila){
    ElemFila *aux;
    int i = 1;
    for(aux = fila->primeiro; aux!= NULL; aux = aux->proximo){
        printf("\n%d - Aviao na fila: %s, %d.", i, aux->nome, aux->identificador);
        i++;}
}

//FUNÇÃO PRINTAR PRIMEIRO AVIÃO DA FILA:
void printPrimeiro(Fila *fila){
    printf("\nPrimeiro aviao da fila: \n\nNOME: %s. \nIDENTIFICADOR: %d.", fila->primeiro->nome, fila->primeiro->identificador);
}

//FUNÇÃO PRINCIPAL:
int main(void){
    Fila fila;
    inicializaFila(&fila);

    int acao = 1;
    while(acao){

        printf("\n\nCENTRAL DA PISTA AEROPORTO");
        printf("\n\n0 - PARA ENCERRAR\n1 - PARA QUANTIDADE DE AVIOES AGUARDANDO PARA DECOLAGEM\n2 - PARA AUTORIZAR DECOLAGEM DO PRIMEIRO AVIAO\n3 - PARA ADIOCIONAR AVIAO A LISTA DE DECOLAGEM\n4 - LISTAR TODOS OS AVIOES NA FILA DE DECOLAGEM\n5 - LISTAR AS INFORMACOES DO PRIMEIRO AVIAO DA FILA");
        printf("\n\nACAO: ");
        scanf("%d", &acao);

        if(acao == 1){
            int quantidade;
            quantidade = qtdItensFila(&fila);
            printf("\nQUANTIDADE DE AVIOES NA FILA PARA DECOLAGEM: %d",quantidade);}

        if(acao == 2){
            int x;
            x = filaVazia(&fila);
            
            if (x==1) {
            printf("\nAUTORIZADO PARA DECOLAGEM:");
            printPrimeiro(&fila);
            removeFila(&fila);}
            
            else{
                printf("\nNENHUM AVIAO NA FILA PARA DECOLAGEM");}
            }

        if(acao == 3){
            printf("\nNOVO AVIAO NA FILA:");

            char nome[30];
            int identificador;
            
            printf("\n\nNOME AVIAO: ");
            scanf("%s", nome);
            printf("IDENTIFICADOR AVIAO: ");
            scanf("%d", &identificador);

            insereFila(&fila, identificador, nome);}

        if(acao == 4){
            int x;
            x = filaVazia(&fila);
            if(x==1){
                printf("\nLISTA AVIOES:\n");
                printLista(&fila);}
            else{
                printf("\nNENHUM AVIAO NA PISTA");}
            }

        if(acao == 5){
            int x;
            x = filaVazia(&fila);
            if(x==1){
                printPrimeiro(&fila);}
            else{
                printf("\nNENHUM AVIAO NA FILA");}
            }
    }

    return 0;
}
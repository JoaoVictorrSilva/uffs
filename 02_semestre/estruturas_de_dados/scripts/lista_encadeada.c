#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//LISTA FUNCIONARIO:
typedef struct funcionario{
    int id;
    char nome[31];
    double salario;
    struct funcionario *proximo;
}Funcionario;

//FUNCAO INSERIR INICIO:
Funcionario* insereNodoInicio(Funcionario *primeiro, int id, char nome[], double salario){
    Funcionario *novo;
    novo = malloc(sizeof(Funcionario));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->salario = salario;
    novo->proximo = NULL;
    if(primeiro!=NULL){
        novo->proximo = primeiro;}
    primeiro = novo;

    printf("\nFUNCIONARIO ADIOCIONADO");
    return primeiro;
}

//FUNCAO INSERIR FIM:
Funcionario *insereNodoFim(Funcionario *primeiro, int id, char nome[], double salario){
    Funcionario *aux, *novo;

    novo = malloc(sizeof(Funcionario));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->salario = salario;
    novo->proximo = NULL;

    if(primeiro==NULL){
        primeiro = novo;}
    else{
        for(aux = primeiro; aux != NULL; aux = aux->proximo){  
            if(aux->proximo == NULL){    
                aux->proximo = novo;
                break;}}
        }

printf("\nFUNCIONARIO ADIOCIONADO");
return primeiro;
}

//DELETAR NODO:
Funcionario *deletaNodo(Funcionario *primeiro, int idDelete){
    Funcionario *aux, *anterior;
    aux = malloc(sizeof(Funcionario));

    if(primeiro->id == idDelete){
        aux = primeiro;
        primeiro = primeiro->proximo;}
    else{
        for(aux = primeiro; aux != NULL; aux = aux->proximo){
            if(aux->id == idDelete){
                anterior->proximo = aux->proximo;
                break;}
            anterior = aux;}}
    free(aux);
    printf("\nFUNCIONARIO DELETADO");
    return primeiro;
}

//FUNCAO P/ PRINTAR LISTA:
void imprimeLista(Funcionario *primeiro){
    printf("\nLISTA FUNCIONARIOS:\n");
    Funcionario *aux;
    if(primeiro==NULL){
        printf("\nNENHUM FUNCIONARIO NA LISTA");
        return;}
    for(aux = primeiro; aux != NULL; aux = aux->proximo){
        printf("\nFuncionario id: %d, nome: %s, salario: R$ %.2lf\n", aux->id, aux->nome, aux->salario);}
    return;
}

//FUNCAO P/ PRINTAR LISTA AO CONTRARIO:
void imprimeAoContrario(Funcionario *aux){
    if(aux != NULL){
        imprimeAoContrario(aux->proximo);
        printf("Funcionario id: %d, nome: %s, salario: R$ %.2lf\n", aux->id, aux->nome, aux->salario);}
}

//FUNCAO CONTAR NODOS:
int contaNodos(Funcionario *primeiro){
    Funcionario *aux = primeiro;
    int contador;
    while(aux!=NULL){
        contador++;
        aux = aux->proximo;}
    return contador;
}

//FUNCAO DESTRUIR LISTA:
Funcionario* destroiLista(Funcionario *primeiro){
    Funcionario*aux;
    while (primeiro != NULL){
        aux = primeiro;
        primeiro = primeiro->proximo;
        free(aux);}
  return NULL;
}

//FUNCAO PRINCIPAL:
int main(void){

    //CRIANDO PRIMEIRO DA LISTA:
    Funcionario *primeiro = NULL;
    primeiro = malloc(sizeof(Funcionario));
    primeiro->id = 0;
    strcpy(primeiro->nome, "X");
    primeiro->salario = 0;
    primeiro->proximo = NULL;

    //LOOP PROGRAMA:
    int continuar = 1;
    while(continuar){
    
    //AÇÕES:
    int acao;
    printf("\n\nINSTRUCOES: \n");
    for(int i=0; i<50; i++){
        printf("=");}
    printf("\n1 - PARA INSERIR UM FUNCIONARIO NO INICIO DA LISTA\n2 - PARA INSERIR UM FUNCIONARIO NO FINAL DA LISTA\n3 - PARA REMOVER UM FUNCIONARIO\n4 - PARA PRINTAR A LISTA\n5 - PARA PRINTAR A LISTA AO CONTRARIO\n6 - PARA CONTAR NUMERO FUNCIONARIOS\n7 - PARA DESTRUIR A LISTA DE FUNCIONARIOS\n");
    for(int i=0; i<50; i++){
        printf("=");}
    printf("\n\nO QUE DESEJA FAZER: ");
    scanf("%d", &acao);

    //AÇÃO ADD FUNCIONARIO NO INICIO:
    if(acao == 1){
        printf("\nADIOCIONANDO NO INCIO: ");
        int quantidade, id1;
        char nome1[31];
        double salario1;

        printf("\n\nQuantos funcionarios adicionar: ");
        scanf("%d", &quantidade);
        for(int i = 1; i <= quantidade; i++){
            printf("\n\nDigite o ID do funcionario %d: ", i);
            scanf("%d", &id1);
            printf("\nDigite o nome do funcionario %d: ", i);
            scanf("%s", nome1);
            printf("\nDigite o salario do funcionario %d: ", i);
            scanf("%lf", &salario1);
            primeiro = insereNodoInicio(primeiro, id1, nome1, salario1);}
    }

    //AÇÃO ADD FUNCIONARIO NO FIM:
    if(acao == 2){
        printf("\nADICIONANDO NO FINAL DA LISTA: ");
        int quantidade, id1;
        char nome1[31];
        double salario1;
        printf("\n\nQuantos funcionarios add: ");
        scanf("%d", &quantidade);
        for(int i = 1; i <= quantidade; i++){
            printf("\n\nDigite o ID do funcionario %d: ", i);
            scanf("%d", &id1);
            printf("\nDigite o nome do funcionario %d: ", i);
            scanf("%s", nome1);
            printf("\nDigite o salario do funcionario %d: ", i);
            scanf("%lf", &salario1);
            primeiro = insereNodoFim(primeiro, id1, nome1, salario1);}
    }

    //AÇÃO DELETAR FUNCIONARIO: 
    if(acao == 3){
        printf("\nDELETANDO FUNCIONARIO");
        if(primeiro == NULL){
            printf("\nNENHUM FUNCIONARIO PARA DELETAR");}
        else{
            int id_delet;
            printf("\nDigite o id do funcionario para deletado: ");
            scanf("%d", &id_delet);
            primeiro = deletaNodo(primeiro, id_delet);}}

    //AÇÃO PRINTAR LISTA:
    if(acao == 4){
        imprimeLista(primeiro);}
    
    //AÇÃO PRINTAR LISTA AO CONTRARIO:
    if(acao == 5){
        printf("\nLISTA A PARTIR DO ULTIMO: ");
        if(primeiro == NULL){
            printf("\nNENHUM FUNCIONARIO");}
        else{
            imprimeAoContrario(primeiro);}}
    
    //AÇÃO CONTAR Nº ELEMENTOS:
    if(acao == 6){
        int n = contaNodos(primeiro);
        if(primeiro == NULL){
            printf("\n\nNenhum funcionario cadastrado");
        }else{
        printf("\nO numero de funcionarios e: %d", n);}}
    
    //AÇÃO EXCLUIR LISTA:
    if(acao==7){
        destroiLista(primeiro);
        printf("\nLISTA DESTRUIDA");}
    
    //ENCERRAR
    printf("\n\nDIGITE 0 PARA ENCERRAR OU OUTRO VALOR PARA CONTINUAR: ");
    scanf("%d", &continuar);}
    
    printf("\nENCERRADO");
    return 0;
}
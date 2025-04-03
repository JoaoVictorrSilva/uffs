//NOME: JOÃO VICTOR DA SILVA - MATRÍCULA: 2211100072

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EXIT 10  //Valor fixo para a opção que finaliza a aplicação

typedef struct item{ //Struct que representa um item de uma lista de compras armazenada em uma arvore binaria de busca
	char produto[50];
	int quantidade;
     struct item *esquerdo; 
	struct item *direito;
}Item;

typedef struct list{ //Struct lista duplicados
	char produto[50];
     struct list *proximo;
}Lista;

int menu1(){ //Apresenta o primeiro menu da aplicação e retorna a opção selecionada
     int op;
     printf("\n\n\n\n        MENU PRINCIPAL\n");
     printf("\n[1] - Gerenciar lista de compras A");
     printf("\n[2] - Gerenciar lista de compras B");
     printf("\n[3] - Visualizar itens duplicados");
     printf("\n[%d] - Sair do programa\n", EXIT);
     printf("\nDigite a opcao: ");
     scanf("%d", &op);
     return op;
}

int menu2(){ //Apresenta o segundo menu da aplicação e retorna a opção selecionada
     int op;
     printf("\n*SUBMENU* - Gerenciar lista de compras\n");
     printf("\n[1] - Para inserir");
     printf("\n[2] - Para pesquisar");
     printf("\n[3] - Para atualizar");
     printf("\n[4] - Para listar");
     printf("\n[5] - Para deletar");
     printf("\n[%d] - Retornar para o menu principal\n", EXIT);
     printf("\nDigite a opcao: ");
     scanf("%d", &op); 
     return op;
}

Item* create(char produto[], int quantidade){ //ALOCANDO UM ITEM
     Item *novo;
     novo = malloc(sizeof(Item));
     if(novo == NULL){
          printf("\n\nSEM ESPAÇO NA MEMÓRIA\n");
          return novo;}
     else{
          strcpy(novo->produto, produto);
          novo->quantidade = quantidade;
          novo->direito = NULL;
          novo->esquerdo = NULL;}
     return novo;
}

void maisculo(char nome[], char nomeNovo[]){ //Função maiúsculo (recebe dois vetores do tipo char e retorna um em maisculo)
     int i = 0;
     while(nome[i] != '\0'){
          nomeNovo[i] = toupper(nome[i]);
          i++;}
     nomeNovo[i] = '\0';
}

int VerificaQuant(int quantidade){ //Verifica se a quantidade inserida pelo usario é valdida
     if(quantidade <= 0){ 
          while (quantidade <= 0){
               printf("\n\nQUANTIDADE INVALIDA");
               printf("\nQuantidade: ");
               scanf("%d", &quantidade);}}

     return quantidade; 
}

Item* insert(Item *raiz, Item *novo){ //Permite o cadastro de um item (caso o produto ainda não exista) em uma lista de compras
     
     if(raiz == NULL){ //Insere
          raiz = novo;
          printf("\nPRODUTO INSERIDO\n");
          return raiz;}
     
     //Caso raiz nao esteja vazia:
     else if(raiz != NULL){
          int mmi; /*mmi = maior / menor / iguais*/
          mmi = strcmp(raiz->produto, novo->produto);
          
          //Verifica qual lado da arvore produto deve estar: 
          if(mmi > 0){
               raiz->esquerdo = insert(raiz->esquerdo, novo);}

          else if(mmi < 0){
               raiz->direito = insert(raiz->direito, novo);} 
     }

     return raiz;
}

Item* query(Item *raiz, char produto[]){ //Permite consultar se um item está em uma lista de compras
     if(raiz != NULL){                   //Caso esteja, retorna um ponteiro para esse produto
                                         //Caso contrario, retorna NULL
          int mmi;                       
          mmi = strcmp(raiz->produto, produto);
          
          if(mmi == 0){
               return raiz;} //Achou o produto e retorna ele

          else if(mmi > 0){
               query(raiz->esquerdo, produto);}
          
          else if(mmi < 0){
               query(raiz->direito, produto);}} 
     
     else{
          return NULL;} //Produto nao cadastrado
}

void update(Item *raiz){ //Permite a atualização da quantidade de um produto (caso exista) na lista de compras
     printf("\n\nATUALIZANDO PRODUTO");
     
     Item *atualizar;
     char produto[50], Produto[50];

     printf("\nNome produto: ");
     scanf("%s", produto);
     maisculo(produto, Produto);
     
     atualizar = query(raiz, Produto); //Ponteiro para o ponteiro (caso ele exista)
     
     if(atualizar != NULL){
          int quantidade;
          printf("\nQuantidade atual: %d", atualizar->quantidade);
          printf("\nNova quantidade: ");
          scanf("%d", &quantidade);
          quantidade = VerificaQuant(quantidade);
          atualizar->quantidade = quantidade;}
     else{
          printf("\nPRODUTO NAO CADASTRADO");}

     return;
}

void list(Item *raiz){ //Listar todos os itens da lista de compras em ordem alfabética;
     if(raiz == NULL){ //Caso base
          return;}

     list(raiz->esquerdo);
     printf("\nProduto: %s", raiz->produto);
     list(raiz->direito);
     return;
}

Item* delete(Item *raiz, char produto[]){ //Permite excluir um item de uma lista de compras
     if(raiz == NULL){ //Produto nao cadastrado
          printf("\n\nPRODUTO NAO CADASTRADO\n");
          return;}

     int mmi;
     mmi = strcmp(raiz->produto, produto);
     if(mmi == 0){ //Achou o produto

          //DELETAR FOLHA:
          if(raiz->esquerdo == NULL && raiz->direito == NULL){
               free(raiz);
               printf("\nProduto %s removido", produto);
               return NULL;}

          //DELETAR PAI COM DOIS FILHOS:
          else if(raiz->esquerdo != NULL && raiz->direito != NULL){
               
               //Aux recebe o maior valor a esquerda da raiz:
               Item *aux = raiz->esquerdo;
               while(aux->direito != NULL){
                    aux = aux->direito;}  

               //Faz a troca do maior nodo a esquerda da raiz, com a raiz:
               raiz->quantidade = aux->quantidade;
               strcpy(raiz->produto, aux->produto);
               strcpy(aux->produto, produto);

               //Agora o nodo que deve ser deletado, deixa de ser pai com dois filhos (chama novamente a função)
               raiz->esquerdo = delete(raiz->esquerdo, produto);
               return raiz;}

          //DELETAR PAI COM UM FILHO
          else{
               Item *aux; //Aux armazena o filho do noto que sera deletado
               if(raiz->esquerdo != NULL){
                    aux = raiz->esquerdo;} 
               else{
                    aux = raiz->direito;}

               free(raiz);
               printf("\nProduto %s removido", produto);
               return aux;
          }}
     
     //Caminha pela arvore:
     else if(mmi > 0){
          raiz->esquerdo = delete(raiz->esquerdo, produto);} 
     else{
          raiz->direito = delete(raiz->direito, produto);}

     return raiz;
}

Lista* intersect(Item *raiz, Item *novo, Lista *lista){ //Intersecção itens duplicados
    Item *aux;
    aux = query(raiz, novo->produto); //Verifica se o novo produto adiocionado esta na outra raiz
    
    if(aux != NULL){ //Produto em ambas as arvores, pois o aux retornou um ponteiro
        
        Lista *novolista;
        novolista = malloc(sizeof(Lista));
        strcpy(novolista->produto, novo->produto);
        novolista->proximo = NULL;

        //Caso lista nao esteja vazia:
        if(lista != NULL){
            Lista *auxlista;
            auxlista = lista;
            while (auxlista->proximo != NULL){
                auxlista = auxlista->proximo;} //auxLista aponta para o ultimo item da lista dos duplicados
            auxlista->proximo = novolista;}
        
        //Caso contrario:
        else{
            lista = novolista;}
    }

    return lista;
}

Lista* deletalista(Lista *lista, char produto[]){ //Deletar item da lista duplicados
     Lista *atual, *anterior, *aux;
     int mmi;
     mmi = strcmp(lista->produto, produto);
     
     //CASO SEJA O PRIMEIRO A SER REMOVIDO:
     if(mmi == 0){
          aux = lista;
          lista = lista->proximo;
          free(aux);
          return lista;}
     
     //CASO CONTRARIO:
     for(atual = lista->proximo; atual != NULL; atual = atual->proximo){
          mmi = strcmp(atual->produto, produto);

          //Achou o Item que deve ser deletado
          if(mmi == 0){
               anterior->proximo = atual->proximo;
               free(atual);
               break;}
          anterior = atual;}

    return lista;
}

void printList(Lista *lista){ //Imprimir lista
     
     if(lista == NULL){
          printf("\n\nNENHUM PRODUTO DUPLICADO\n");
          return;}
          
     printf("\n\nLISTA PRODUTOS DUPLICADOS:\n");
     Lista *aux;
     for(aux = lista; aux != NULL; aux = aux->proximo){
          printf("\nProduto: %s ", aux->produto);}
     return;
}

int main(void){ //PROGRAMA PRINCIPAL:

     int opcao1, opcao2;
     Item *raizA = NULL;
     Item *raizB = NULL;
     Lista *lista = NULL;

     while (opcao1 != EXIT){
     
          opcao1 = menu1();
          switch(opcao1){

               case 1 : //GERENCIAR LISTA A:
                    opcao2 = 11;
                    
                    while(opcao2 != EXIT){
                         printf("\n\n** Lista de Compras A **\n\n");
                         opcao2 = menu2();
                         
                         switch(opcao2){ //OPERAÇÕES ÁRVORE: A
                              
                              case 1 :;
                                   Item *novo = NULL;
                                   char produto[50], Produto[50];
                                   int quantidade;

                                   printf("\n\nNOVO ITEM:\n");
                                   printf("\nNome novo produto: ");
                                   scanf("%s", produto);
                                   maisculo(produto, Produto);

                                   //Verifica se o produto ja nao esta cadastrado
                                   novo = query(raizA, Produto);
                                   
                                   //Caso nao esteja:
                                   if(novo == NULL){
                                        printf("\nQuantidade: ");
                                        scanf("%d", &quantidade);
                                        quantidade = VerificaQuant(quantidade);
                                        novo = create(Produto, quantidade);     //Reserva memoria
                                        raizA = insert(raizA, novo);            //Insere na arvore
                                        lista = intersect(raizB, novo, lista);} //Insere na lista (caso produto esteja na outra arvore)
                                   else{
                                        printf("\nPRODUTO JA CADASTRADO");}

                                   break;

                              case 2 :;
                                   printf("\n\nPESQUISANDO PRODUTO:\n");
                                   char nomePesquisa[50], NomePesquisa[50];
                                   Item *pesquisa;
                                   
                                   printf("\nNome: ");
                                   scanf("%s", nomePesquisa);

                                   maisculo(nomePesquisa, NomePesquisa);
                                   pesquisa = query(raizA, NomePesquisa); //Aponta para o produto se existir
                                   
                                   if(pesquisa == NULL){
                                        printf("\nPRODUTO NAO CADASTRADO");}
                                   else{
                                        printf("\nPRODUTO CADASTRADO: \nNOME: %s\nQUANTIDADE: %d", pesquisa->produto, pesquisa->quantidade);}
                                   break;
                              
                              case 3 :;
                                   update(raizA);
                                   break;
                              
                              case 4 :;
                                   if(raizA != NULL){ //Verifica se a arvore esta vazia
                                        printf("\n\nLISTA PRODUTOS MERCADO A:\n");
                                        list(raizA);}
                                   else{
                                        printf("\n\n*NENHUM PRODUTO CADASTRADO*\n");}
                                   break;
                              
                              case 5 :;
                                   printf("\n\nDELETANDO PRODUTO:\n");
                                   char deletar[50], Deletar[50];

                                   printf("\nNome: ");
                                   scanf("%s", deletar);
                                   maisculo(deletar, Deletar);
                                   
                                   raizA = delete(raizA, Deletar); //Apaga arvore
                                   lista = deletalista(lista, Deletar); //Apaga lista duplicados (caso esteja)
                                   break;
                         }    
                    }
               break;
               
               case 2 : //GERENCIAR LISTA B:
                    opcao2 = 11;
                    
                    while(opcao2 != EXIT){
                         printf("\n\n** Lista de Compras B **\n\n");
                         opcao2 = menu2();
                         
                         switch(opcao2){ //OPERAÇÕES ÁRVORE: B
                              
                              case 1 :;
                                   Item *novo = NULL;
                                   char produto[50], Produto[50];
                                   int quantidade;

                                   printf("\n\nNOVO ITEM:\n");
                                   printf("\nNome novo produto: ");
                                   scanf("%s", produto);
                                   maisculo(produto, Produto);

                                   //Verifica se o produto ja nao esta cadastrado
                                   novo = query(raizB, Produto);
                                   
                                   //Caso nao esteja:
                                   if(novo == NULL){
                                        printf("\nQuantidade: ");
                                        scanf("%d", &quantidade);
                                        quantidade = VerificaQuant(quantidade);
                                        novo = create(Produto, quantidade);     //Reserva memoria
                                        raizB = insert(raizB, novo);            //Insere na arvore
                                        lista = intersect(raizA, novo, lista);} //Insere na lista (caso produto esteja na outra arvore)
                                   else{
                                        printf("\nPRODUTO JA CADASTRADO");}

                                   break;

                              case 2 :;
                                   printf("\n\nPESQUISANDO PRODUTO:\n");
                                   char nomePesquisa[50], NomePesquisa[50];
                                   Item *pesquisa;
                                   
                                   printf("\nNome: ");
                                   scanf("%s", nomePesquisa);

                                   maisculo(nomePesquisa, NomePesquisa);
                                   pesquisa = query(raizB, NomePesquisa); //Aponta para o produto se existir
                                   
                                   if(pesquisa == NULL){
                                        printf("\nPRODUTO NAO CADASTRADO");}
                                   else{
                                        printf("\nPRODUTO CADASTRADO: \nNOME: %s\nQUANTIDADE: %d", pesquisa->produto, pesquisa->quantidade);}
                                   
                                   break;
                              
                              case 3 :;
                                   update(raizB);
                                   break;
                              
                              case 4 :;
                                   if(raizB != NULL){ //Verifica se a arvore esta vazia
                                        printf("\n\nLISTA PRODUTOS MERCADO A:\n");
                                        list(raizB);}
                                   else{
                                        printf("\n\n*NENHUM PRODUTO CADASTRADO*\n");}
                                   
                                   break;
                              
                              case 5 :;
                                   printf("\n\nDELETANDO PRODUTO:\n");
                                   char deletar[50], Deletar[50];

                                   printf("\nNome: ");
                                   scanf("%s", deletar);
                                   maisculo(deletar, Deletar);
                                   
                                   raizB = delete(raizB, Deletar); //Apaga arvore
                                   lista = deletalista(lista, Deletar); //Apaga lista duplicados (caso esteja)
                                   
                                   break;
                         }    
                    }
               break;

               case 3 : //Visualizar itens duplicados
                    printList(lista);
                    break;
          }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "busca_table.h"

table busca_table(char busca_nome_logico[20]) {
    FILE *arquivo_tabela;
    arquivo_tabela = fopen("table.dic", "r");

    table tabela;
    tabela.id_arquivo = -1;

    if (arquivo_tabela == NULL) {
        printf("Erro ao abrir o arquivo 'table.dic'\n");
        return tabela;
    } else {
        while (fread(&tabela, sizeof(tabela), 1, arquivo_tabela) == 1) {
            tabela.nome_logico[19] = '\0';
            tabela.nome_fisico[19] = '\0';

            if (strcmp(tabela.nome_logico, busca_nome_logico) == 0) {
                fclose(arquivo_tabela);
                return tabela;
            }
        }     
    }

    fclose(arquivo_tabela);
    tabela.id_arquivo = -1;
    return tabela;
}
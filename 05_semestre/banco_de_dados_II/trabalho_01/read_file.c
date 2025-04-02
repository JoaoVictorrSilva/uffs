#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_file.h"
#include "busca_table.h"
#include "busca_schema.h"
#include "cabecalho_table.h"
#include "insert_table.h"

int read_file(char busca_nome_logico[20]) {

    table tabela = busca_table(busca_nome_logico);
    
    if (tabela.id_arquivo == -1) {
        printf("Tabela não encontrada\n");
        return 0; 
    }

    att *schema = busca_schema(tabela);

    if (!schema) {
        printf("Erro ao buscar o esquema\n");
        return 0;
    }

    cabecalho_table(schema);
    insert_table(tabela, schema);
    free(schema);

    return 0;
}
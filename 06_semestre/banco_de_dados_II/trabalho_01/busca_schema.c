#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "busca_schema.h"

att* busca_schema(table tabela){
    if (tabela.id_arquivo == -1){
        printf("Tabela não encontrada\n");
        return NULL;
    }

    FILE *arquivo_schema = fopen("att.dic", "r");
    if (!arquivo_schema){
        printf("Erro ao abrir arquivo de Schemas\n");
        return NULL;
    }

    size_t capacidade = 10;  
    att *schema = (att *)malloc(capacidade * sizeof(att));

    size_t i = 0;
    while (fread(&schema[i], sizeof(att), 1, arquivo_schema) == 1){
        schema[i].atributo[19] = '\0';

        if (schema[i].id_arquivo == tabela.id_arquivo){
            i++;
            if (i >= capacidade){
                capacidade *= 2;
                schema = (att *)realloc(schema, capacidade * sizeof(att));
            }
        }
    }

    fclose(arquivo_schema);
    schema = (att *)realloc(schema, i * sizeof(att));

    return schema; 
}

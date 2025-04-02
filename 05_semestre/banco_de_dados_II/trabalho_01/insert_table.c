#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "insert_table.h"
#include "total_atributos.h"
#include "total_largura_maxima.h"
#include "imprime_linhas.h"

int insert_table(table tabela, att* schema){
    FILE *arquivo = fopen(tabela.nome_fisico, "r");
    
    if (!arquivo){
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    int total_atributos_t = total_atributos(schema);
    int *largura = total_largura_maxima(schema, total_atributos_t);

    int continuar = 1;

    while (continuar){
        int primeiro_col = 1;

        for (int i = 0; i < total_atributos_t; i++){
            
            if (schema[i].tipo[0] == 'S'){
                char *valor = (char*)malloc(schema[i].tamanho_atributo);
                size_t bytes_lidos = fread(valor, sizeof(char), schema[i].tamanho_atributo, arquivo);
                
                if (bytes_lidos < schema[i].tamanho_atributo){
                    continuar = 0;
                    free(valor);
                    break;
                }

                valor[bytes_lidos] = '\0';

                if (primeiro_col){
                    printf("|");
                    primeiro_col = 0;
                }

                printf(" %-*s |", largura[i], valor);
                free(valor);
            } else if (schema[i].tipo[0] == 'I'){
                int valor;
                if (fread(&valor, sizeof(int), 1, arquivo) != 1){
                    continuar = 0;
                    break;
                }

                if (primeiro_col){
                    printf("|");
                    primeiro_col = 0;
                }

                printf(" %-*d |", largura[i], valor);
            } else if (schema[i].tipo[0] == 'D'){
                double valor;
                if (fread(&valor, sizeof(double), 1, arquivo) != 1){
                    continuar = 0;
                    break;
                }

                if (primeiro_col){
                    printf("|");
                    primeiro_col = 0;
                }

                printf(" %-*f |", largura[i], valor);
            }
        }

        if (continuar){
            printf("\n");
        }
    }

    linhas(total_atributos_t, largura);

    fclose(arquivo);
    free(largura);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabecalho_table.h"
#include "total_atributos.h"
#include "total_largura_maxima.h"
#include "imprime_linhas.h"

int cabecalho_table(att* schema) {
    int total_atributos_t = total_atributos(schema);
    int *largura = total_largura_maxima(schema, total_atributos_t);

    linhas(total_atributos_t, largura);

    printf("|");
    for (int i = 0; i < total_atributos_t; i++) {
        printf(" %-*s |", largura[i], schema[i].atributo);
    }
    printf("\n");

    linhas(total_atributos_t, largura);
    free(largura);

    return 0;
}
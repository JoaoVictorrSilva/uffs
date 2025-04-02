#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "total_largura_maxima.h"

int* total_largura_maxima(att* schema, int numero_atributos){
    int *largura = (int*) malloc(numero_atributos * sizeof(int));
    
    for(int i = 0; i < numero_atributos; i++){
        largura[i] = strlen(schema[i].atributo);

        if(largura[i] < schema[i].tamanho_atributo){
            largura[i] = schema[i].tamanho_atributo;
        }
    }

    return largura;
}
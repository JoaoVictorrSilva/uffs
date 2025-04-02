#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imprime_linhas.h"

void linhas(int numero_atributos, int* largura){
    printf("+");

    for(int i = 0; i < numero_atributos; i++){
        for (int j = 0; j < largura[i] + 2; j++){
            printf("-");
        }
        
        printf("+");
    }
    printf("\n");

    return;
}

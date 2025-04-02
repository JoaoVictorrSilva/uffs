#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "read_file.h"

int main() {
    char nome_logico[20];
    printf("Por favor digite o nome da tabela que deseja visualizar:\n");
    scanf("%s", nome_logico);

    int resultado = read_file(nome_logico);
    
    return resultado;
}

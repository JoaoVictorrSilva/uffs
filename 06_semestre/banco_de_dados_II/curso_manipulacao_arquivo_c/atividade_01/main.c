#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // Para usar a função toupper()

int main() {
    FILE *f_in, *f_out;
    char caracter;

    f_in = fopen("arquivo.txt", "r");
    
    if (f_in == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        exit(1);
    }

    // Abrindo outro arquivo para escrita
    f_out = fopen("arquivo_maiusculo.txt", "w");
    if (f_out == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        fclose(f_in);
        system("pause");
        exit(1);
    }

    while ((caracter = fgetc(f_in)) != EOF) {
        fputc(toupper(caracter), f_out);
    }

    fclose(f_in);
    fclose(f_out);

    printf("Conversão concluída. Verifique o arquivo 'arquivo_maiusculo.txt'.\n");

    return 0;
}

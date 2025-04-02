#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f;
    f = fopen("arquivo.txt", "w");

    if (f == NULL) {
        printf("Erro ao abrir arquivo para escrita\n");
        exit(1);
    }

    char frase[500];
    printf("Digite alguma frase: ");
    scanf("%s", frase);
    // fgets(frase, sizeof(frase), stdin);

    // Verifica se fgets capturou o caractere de nova linha e remove
    // frase[strcspn(frase, "\n")] = '\0';

    // Escreve a frase no arquivo
    //for (int i = 0; i < strlen(frase); i++) {
    //    fputc(frase[i], f);
    //}

    int retorno =  fputs(frase, f);

    fclose(f);
    
    printf("Frase gravada no arquivo 'arquivo.txt'.\n");
    return 0;
}

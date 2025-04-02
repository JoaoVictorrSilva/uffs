#ifndef TABLE_H
#define TABLE_H

typedef struct table
{
    int id_arquivo;
    char nome_logico[20]; // nome lógico do arquivo
    char nome_fisico[20]; // nome físico do arquivo (no disco)
} table;

#endif // TABLE_H
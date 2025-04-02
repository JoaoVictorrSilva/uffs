#ifndef ATT_H
#define ATT_H

typedef struct att
{
    int id_arquivo;         // chave estrangeira da table.dic
    char atributo[20];      // nome do atributo
    char tipo[1];           // S string, I inteiro, D double
    char opcionalidade[1];  // 0 obrigatório e 1 opcional
    int tamanho_atributo;
} att;

#endif // ATT_H
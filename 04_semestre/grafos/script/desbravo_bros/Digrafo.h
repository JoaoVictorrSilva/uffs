/*
 * Tarefa 04 - Desbravo Bros.
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      João Victor da Silva
 * Matricula: 2211100072
 */

#ifndef DIGRAFO_H
#define DIGRAFO_H
#include "Aresta.h"
#include <iostream>
#include <vector>

class Digrafo {
private:
    std::vector<std::vector<int>> adj;
    int regioes; // --> número de vértices
    int vida;
public:
    Digrafo(int v);
    void insert_edge(Aresta S, int vida_cano);
    bool max_vidas(int v, int dp[]);
    bool Bellman_Ford(int s, int dp[]);
};

#endif
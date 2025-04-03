/*
 * Tarefa 02 - Potenciais Comparsas
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome:      João Victor da Silva
 * Matricula: 2211100072
 */

#include <iostream>
#include "queue"
#include "Grafo.h"
#include <algorithm>

Grafo::Grafo(int suspects){
    suspects_number_ = suspects;
    calls_number_ = 0;

    adj.resize(suspects);

    for(int i = 0; i < suspects; i++)
        adj[i].resize(suspects, 0); 
}

void Grafo::insert_edge(Aresta L){
    if (adj[L.v1][L.v2] != 0)
        return;
    if (L.v1 >= suspects_number_ || L.v2 >= suspects_number_)
        return;

    adj[L.v1][L.v2] = 1;
    adj[L.v2][L.v1] = 1;

    calls_number_++;
}

std::vector<int> Grafo::busca_larg(int v){

    std::vector<int> marcado(suspects_number_, 0);
    std::vector<int> dist(suspects_number_, 0);
    std::vector<int> suspects;
    std::queue<int> fila;

    marcado[v] = 1;
    dist[v] = 0;
    fila.push(v);

    while (!fila.empty()){
        
        int w = fila.front();
        fila.pop();
        
        for(int u = 0; u < suspects_number_; u++)
            if(adj[w][u] != 0)
                if(marcado[u] == 0){
                    marcado[u] = 1;
                    dist[u] = dist[w] + 1;
                    fila.push(u);

                    if(dist[u] <= 3)
                        suspects.push_back(u);
                }
    }

    sort(suspects.begin(), suspects.end());

    return suspects;
} 
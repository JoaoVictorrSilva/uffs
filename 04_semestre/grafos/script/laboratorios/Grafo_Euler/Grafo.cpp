#include <iostream>
#include "queue"
#include "Grafo.h"
#include <algorithm>

Grafo::Grafo(int v){
    vertices_number_ = v;
    arestas_number_ = 0;

    adj.resize(v);

    for(int i = 0; i < v; i++)
        adj[i].resize(v, 0); 
}

void Grafo::insert_edge(Aresta L){
    if (adj[L.v1][L.v2] != 0)
        return;
    if (L.v1 >= vertices_number_ || L.v2 >= vertices_number_)
        return;

    adj[L.v1][L.v2] = 1;
    adj[L.v2][L.v1] = 1;

    arestas_number_++;
}

bool Grafo::busca_larg(int v){

    std::vector<int> vetor_graus(vertices_number_, 0);
    std::vector<int> vetor_isolados(vertices_number_, 0);

    for(int i = 0; i < vertices_number_; i++){
        for(int j = 0; j < vertices_number_; j++){
            if(adj[i][j] != 0)
                vetor_graus[i] += 1;
        }
    }

    for(int i = 0; i < vertices_number_; i++){
        if(vetor_graus[i] == 0){
            vetor_isolados[i] = 1;
        }
        else if(vetor_graus[i] % 2 != 0){
            return false;
        }
    }

    std::vector<int> marcado(vertices_number_, 0);
    std::queue<int> fila;

    marcado[v] = 1;
    fila.push(v);

    while (!fila.empty()){
        


        int w = fila.front();
        fila.pop();
        
        for(int u = 0; u < vertices_number_; u++)
            if(adj[w][u] != 0)
                if(marcado[u] == 0){
                    marcado[u] = 1;
                    fila.push(u);
                }
    }

    return true;
}
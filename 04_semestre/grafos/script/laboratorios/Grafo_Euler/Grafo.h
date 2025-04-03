#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "Aresta.h"
#include "vector"
#include "queue"

class Grafo{

private:
    std::vector<std::vector<int>> adj;
    int vertices_number_; //vertices
    int arestas_number_; //edges

public:
    Grafo(int v);
    void insert_edge(Aresta e); 
    bool busca_larg(int v);
};

#endif
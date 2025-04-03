#include "Aresta.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    
    Grafo g(10);
    g.insert_edge(Aresta(0, 2));
    g.insert_edge(Aresta(0, 9));
    g.insert_edge(Aresta(1, 3));
    g.insert_edge(Aresta(1, 9));
    g.insert_edge(Aresta(2, 3));
    g.insert_edge(Aresta(2, 4));
    g.insert_edge(Aresta(2, 5));
    g.insert_edge(Aresta(2, 7));
    g.insert_edge(Aresta(3, 4));
    g.insert_edge(Aresta(3, 5));
    g.insert_edge(Aresta(3, 6));
    g.insert_edge(Aresta(3, 7));
    g.insert_edge(Aresta(3, 8));
    g.insert_edge(Aresta(5, 9));
    g.insert_edge(Aresta(7, 8));
    g.insert_edge(Aresta(7, 9));

    if(g.busca_larg(0))
        cout << "E Euleriano";

    else
        cout << "\nNao e Euleriano";
    
    return 0;
}
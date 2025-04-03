/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome: João Victor da Silva
 * Matricula: 2211100072
*/

#include "Aresta.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    
    int numVertices, numOperacoes, v1, v2;
    char Op;

    cin >> numVertices;
    Grafo grafo(numVertices);
    cin >> numOperacoes;

    for(int i = 0; i < numOperacoes; i++){  
        cin >> Op;

        if(Op == 'I'){
            cin >> v1;
            cin >> v2;
            Aresta e(v1, v2);       
            grafo.insere_aresta(e);
        }
        
        else if(Op == 'R'){
            cin >> v1;
            cin >> v2;
            Aresta e(v1, v2); //cria aresta       
            grafo.remove_aresta(e); //remove aresta
        }

        else if(Op == 'E')
            cout << grafo.get_num_arestas() << '\n';
        
        else if(Op == 'Q'){
            int vertice;
            cin >> vertice;           
            grafo.remove_vertice(vertice);       
        }

        else if(Op == 'N')
            cout << grafo.get_num_vertices() << '\n';        

        else if(Op == 'P')
            grafo.imprime();              
    }

    return 0;
}
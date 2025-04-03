/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/2
 *
 * Nome: João Victor da Silva
 * Matricula: 2211100072
*/

#include "Grafo.h"
#include <list>
#include <iostream>

Grafo::Grafo(int num_vertices) { 
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    vetor_listas.resize(num_vertices);
}

int Grafo::get_num_vertices() {
    return num_vertices_;
}

void Grafo::remove_vertice(int vertice){
    for(auto vertex : vetor_listas[vertice]){
        vetor_listas[vertex].remove(vertice);
        num_arestas_--;
    }

    for(int i = vertice + 1; i < vetor_listas.size(); i++)
        vetor_listas[i - 1] = vetor_listas[i];

    vetor_listas.resize(--num_vertices_);

    for(int i = 0; i < vetor_listas.size(); i++)
        for(std::list<int>::iterator j = vetor_listas[i].begin(); j != vetor_listas[i].end(); j++)
            if(*j > vertice)
                *j = *j - 1;
}

int Grafo::get_num_arestas() {
    return num_arestas_;
}

void Grafo::insere_aresta(Aresta e) {
    if(e.v1 == e.v2 || e.v1 < 0 || e.v2 < 0 || e.v1 >= num_vertices_ || e.v2 >= num_vertices_){
        return;
    }

    for(auto j: vetor_listas[e.v1]){
        if(j == e.v2)
            return;           
    }

    vetor_listas[e.v1].push_front(e.v2);
    vetor_listas[e.v2].push_front(e.v1);
    num_arestas_++;   
}

void Grafo::remove_aresta(Aresta e) {

    bool removido = false;
    for(auto i = vetor_listas[e.v1].begin(); i!= vetor_listas[e.v1].end(); ++i){ 
        if(*i == e.v2){
            i = vetor_listas[e.v1].erase(i);
            removido = true;
            break;
        }
    }

    for(auto i = vetor_listas[e.v2].begin(); i!= vetor_listas[e.v2].end(); ++i){ 
        if(*i == e.v1){
            i = vetor_listas[e.v2].erase(i);
            break;
        }
    }

    if(removido)
        num_arestas_--; 
}

void Grafo::imprime() {
    for(int i = 0; i < num_vertices_; i++){
        std::cout << i << ':'; 
        for(auto j: vetor_listas[i])
            std::cout << ' ' << j;       
        std::cout << "\n";
    }    
}